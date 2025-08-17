#include "qveritymatchingquestion.h"
#include "ui_qveritymatchingquestion.h"
#include "veritywizard.h"

namespace tmc {
namespace UI {

QVerityMatchingQuestion::QVerityMatchingQuestion(QWidget *parent, tmc::Verity::keygenIndex influence)
    : QWizardPage(parent)
    , ui(new Ui::QVerityMatchingQuestion)
{
    g = dynamic_cast<tmc::suyudo::VerityWizard*>(parent)->getRngWithGlobalSeed();
    this->influence = influence;
    ui->setupUi(this);
    this->lyt = dynamic_cast<QFormLayout*>(ui->scrollAreaWidgetContents->layout());
    this->matches = std::vector<DefChoiceId>();
    DefChoiceId match1;
    match1.choice = "Choice1";
    match1.definition = ui->label_3->text().toStdString();
    match1.identifier = "A";
    DefChoiceId match2;
    match2.choice = "Choice2";
    match2.definition = ui->label_4->text().toStdString();
    match2.identifier = "B";
    matches.push_back(match1);
    matches.push_back(match2);
    this->choiceInputs = {ui->comboBox, ui->comboBox_2};
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &QVerityMatchingQuestion::onChoicePicked);
    connect(ui->comboBox_2, &QComboBox::currentIndexChanged, this, &QVerityMatchingQuestion::onChoicePicked);
    this->definitions = {ui->label_3, ui->label_4};
    shuffle();
}

tmc::Verity::keygenIndex QVerityMatchingQuestion::getInfluence()
{
    return influence;
}

std::string QVerityMatchingQuestion::getQuestionText()
{
    return ui->label->text().toStdString();
}

tmc::suyudo::UsedIn QVerityMatchingQuestion::usedIn()
{
    return tmc::suyudo::VERITY;
}

void QVerityMatchingQuestion::setMatch(const std::string& definition, const std::string& choice, const std::string& identifier, u64 index)
{
    for (u64 i = 0; i < choiceInputs[0]->count(); i++)
    {
        if (choiceInputs[0]->itemText(i).toStdString() == matches.at(index).identifier)
        {
            for (u64 j = 0; j < choiceInputs.size(); j++)
            {
                choiceInputs[j]->setItemText(i, QString::fromStdString(identifier));
            }
            break;
        }
    }
    for (u64 i = 0; i < definitions.size(); i++)
    {
        if (definitions[i]->text().toStdString() == matches.at(index).definition)
        {
            definitions[i]->setText(QString::fromStdString(definition));
            break;
        }
    }
    matches.at(index).choice = choice;
    matches.at(index).identifier = identifier;
    matches.at(index).definition = definition;
    refreshUI();
    shuffle();
}

void QVerityMatchingQuestion::addMatch(const std::string& definition, const std::string& choice, const std::string& identifier)
{
    DefChoiceId match;
    match.definition = definition;
    match.choice = choice;
    match.identifier = identifier;
    matches.push_back(match);
    choiceInputs.push_back(new QComboBox(ui->scrollAreaWidgetContents));
    connect(choiceInputs.back(), &QComboBox::currentIndexChanged, this, &QVerityMatchingQuestion::onChoicePicked);
    for (u64 i = 0; i < choiceInputs.size(); i++)
    {
        if (i == choiceInputs.size() - 1)
        {
            for (u64 j = 0; j < matches.size() - 1; j++)
            {
                choiceInputs.back()->addItem(QString::fromStdString(matches[j].identifier));
            }
        }
        choiceInputs[i]->addItem(QString::fromStdString(matches.back().identifier));
    }
    definitions.push_back(new QLabel(ui->scrollAreaWidgetContents));
    definitions.back()->setText(QString::fromStdString(match.definition));
    refreshUI();
    shuffle();
}

u64 QVerityMatchingQuestion::getMatchCount()
{
    return matches.size();
}

void QVerityMatchingQuestion::removeMatch(u64 index)
{
    if (index >= matches.size()) return;
    if (matches.size() == 2) return;
    DefChoiceId removedMatch = matches.at(index);
    matches.erase(matches.begin() + index);
    QLabel* removedDef = nullptr;
    QComboBox* removedChoice = nullptr;
    for (u64 i = 0; i < definitions.size(); i++)
    {
        if (definitions[i]->text().toStdString() == removedMatch.definition)
        {
            removedChoice = choiceInputs[i];
            removedDef = definitions[i];
            choiceInputs.erase(choiceInputs.begin() + i);
            definitions.erase(definitions.begin() + i);
            break;
        }
    }
    // Have to check if non-null to silence a clang-tidy warning
    if (removedChoice != nullptr && (removedChoice == ui->comboBox || removedChoice == ui->comboBox_2))
    {
        lyt->removeWidget(removedChoice);
        removedChoice->setVisible(false);
    }
    else if (removedChoice != nullptr)
    {
        lyt->removeWidget(removedChoice);
        delete removedChoice;
    }
    if (removedDef != nullptr)
    {
        lyt->removeWidget(removedDef);
        delete removedDef;
    }
    for (u64 i = 0; i < choiceInputs.size(); i++)
    {
        for (u64 j = 0; j < choiceInputs[i]->count(); j++)
        {
            if (choiceInputs[i]->itemText(j).toStdString() == removedMatch.identifier)
            {
                choiceInputs[i]->removeItem(j);
            }
        }
    }
    refreshUI();
    shuffle();
}

void QVerityMatchingQuestion::setQuestionText(const std::string& questionText)
{
    ui->label->setText(QString::fromStdString(questionText));
}

QVerityMatchingQuestion::DefChoiceId QVerityMatchingQuestion::getMatch(u64 index)
{
    return matches.at(index);
}

QVerityMatchingQuestion::~QVerityMatchingQuestion()
{
    delete ui;
}

tmc::suyudo::QuestionType QVerityMatchingQuestion::getQuestionType()
{
    return tmc::suyudo::MATCHING;
}

void QVerityMatchingQuestion::shuffle()
{
    std::vector<std::string> strVect;
    for (u64 i = 0; i < matches.size(); i++)
    {
        strVect.push_back(matches[i].definition);
    }
    std::random_device rd;
    std::shuffle(strVect.begin(), strVect.end(), *g);
    for (u64 i = 0; i < definitions.size(); i++)
    {
        definitions[i]->setText(QString::fromStdString(strVect[i]));
    }
}

int QVerityMatchingQuestion::nextId() const
{
    int current = wizard()->currentId();
    if (current == 17)
    {
        std::vector<bool> answers = dynamic_cast<tmc::suyudo::VerityWizard*>(wizard())->getAnswers();
        u16 score = 0;
        std::vector<DefChoiceId> partialCredit;
        for (u64 i = 0; i < definitions.size(); i++)
        {
            for (u64 j = 0; j < matches.size(); j++)
            {
                if (matches[j].definition == definitions[i]->text().toStdString() &&
                    matches[j].identifier == choiceInputs[i]->currentText().toStdString())
                {
                    partialCredit.push_back(matches[j]);
                    break;
                }
            }
        }
        if (partialCredit.size() == matches.size()) score++;
        for (u64 i = 0; i < answers.size(); i++)
        {
            score += answers[i];
        }
        if (f64(score) / 16.0 >= 0.75)
        {
            return 19;
        }
    }
    else if (current == 35)
    {
        std::vector<bool> answers = dynamic_cast<tmc::suyudo::VerityWizard*>(wizard())->getAnswers();
        u16 score = 0;
        std::vector<DefChoiceId> partialCredit;
        for (u64 i = 0; i < definitions.size(); i++)
        {
            for (u64 j = 0; j < matches.size(); j++)
            {
                if (matches[j].definition == definitions[i]->text().toStdString() &&
                    matches[j].identifier == choiceInputs[i]->currentText().toStdString())
                {
                    partialCredit.push_back(matches[j]);
                    break;
                }
            }
        }
        if (partialCredit.size() == matches.size()) score++;
        for (u64 i = 0; i < answers.size(); i++)
        {
            score += answers[i];
        }
        if (f64(score) / 16.0 >= 0.75)
        {
            return 37;
        }
    }
    QList<int> ids = wizard()->pageIds();
    int next = -1;
    for (u64 i = 0; i < ids.size(); i++)
    {
        if (ids[i] > current && next == -1) next = ids[i];
    }
    if (next != -1)
    {
        for (u64 i = 0; i < ids.size(); i++)
        {
            if (ids[i] > current && ids[i] < next) next = ids[i];
        }
    }
    return next;
}

void QVerityMatchingQuestion::onChoicePicked(int index)
{
    std::vector<DefChoiceId> partialCredit;
    for (u64 i = 0; i < definitions.size(); i++)
    {
        for (u64 j = 0; j < matches.size(); j++)
        {
            if (matches[j].definition == definitions[i]->text().toStdString() &&
                matches[j].identifier == choiceInputs[i]->currentText().toStdString())
            {
                partialCredit.push_back(matches[j]);
                break;
            }
        }
    }
    if (partialCredit.size() == matches.size()) emit answeredCorrectly();
    else emit answeredIncorrectly(partialCredit);
}

void QVerityMatchingQuestion::refreshUI()
{
    std::string choicePool;
    for (u64 i = 0; i < matches.size(); i++)
    {
        if (i == 0)
        {
            choicePool += matches[i].identifier + ": " + matches[i].choice;
        }
        else
        {
            if (!(i & 7)) choicePool += "\n" + matches[i].identifier + ": " + matches[i].choice;
            else choicePool += "    " + matches[i].identifier + ": " + matches[i].choice;
        }
    }
    ui->label_2->setText(QString::fromStdString(choicePool));
    for (u64 i = 0; i < definitions.size(); i++)
    {
        lyt->removeWidget(definitions[i]);
        lyt->removeWidget(choiceInputs[i]);
    }
    for (u64 i = 0; i < definitions.size(); i++)
    {
        lyt->addRow(choiceInputs[i], definitions[i]);
    }
}

} // namespace UI
} // namespace tmc
