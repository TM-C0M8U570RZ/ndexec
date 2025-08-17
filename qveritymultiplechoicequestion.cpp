#include "qveritymultiplechoicequestion.h"
#include "ui_qveritymultiplechoicequestion.h"
#include "veritywizard.h"

namespace tmc {
namespace UI {

QVerityMultipleChoiceQuestion::QVerityMultipleChoiceQuestion(QWidget *parent, tmc::Verity::keygenIndex influence)
    : QWizardPage(parent)
    , ui(new Ui::QVerityMultipleChoiceQuestion)
{
    g = dynamic_cast<tmc::suyudo::VerityWizard*>(parent)->getRngWithGlobalSeed();
    this->influence = influence;
    ui->setupUi(this);
    choices = std::vector<QRadioButton*>();
    choices.push_back(ui->radioButton);
    connect(choices.back(), SIGNAL(clicked()), this, SIGNAL(completeChanged()));
    connect(choices.back(), &QRadioButton::clicked, this, &QVerityMultipleChoiceQuestion::onChoicePicked);
    choices.push_back(ui->radioButton_2);
    connect(choices.back(), SIGNAL(clicked()), this, SIGNAL(completeChanged()));
    connect(choices.back(), &QRadioButton::clicked, this, &QVerityMultipleChoiceQuestion::onChoicePicked);
    this->correctIndex = 0;
}

bool QVerityMultipleChoiceQuestion::isComplete() const
{
    for (u64 i = 0; i < choices.size(); i++)
    {
        if (choices[i]->isChecked()) return true;
    }
    return false;
}

void QVerityMultipleChoiceQuestion::shuffle()
{
    std::string correct = getChoice(correctIndex);
    std::vector<std::string> choiceTexts;
    for (u64 i = 0; i < choices.size(); i++)
    {
        choiceTexts.push_back(choices[i]->text().toStdString());
    }
    std::shuffle(choiceTexts.begin(), choiceTexts.end(), *g);
    for (u64 i = 0; i < choiceTexts.size(); i++)
    {
        choices[i]->setText(QString::fromStdString(choiceTexts[i]));
    }
    for (u64 i = 0; i < choiceTexts.size(); i++)
    {
        if (choiceTexts[i] == correct)
        {
            correctIndex = i;
            return;
        }
    }
}

void QVerityMultipleChoiceQuestion::addChoice(const std::string& choice)
{
    QRadioButton* rb = new QRadioButton(QString::fromStdString(choice), ui->groupBox);
    ui->verticalLayout->addWidget(rb);
    connect(rb, &QRadioButton::clicked, this, &QVerityMultipleChoiceQuestion::onChoicePicked);
    choices.push_back(rb);
    connect(choices.back(), SIGNAL(clicked()), this, SIGNAL(completeChanged()));
}

int QVerityMultipleChoiceQuestion::nextId() const
{
    int current = wizard()->currentId();
    if (current == 17)
    {
        std::vector<bool> answers = dynamic_cast<tmc::suyudo::VerityWizard*>(wizard())->getAnswers();
        u16 score = 0;
        u64 indexOfPicked = std::numeric_limits<u64>::max();
        for (u64 i = 0; i < choices.size(); i++)
        {
            if (choices[i]->isChecked())
            {
                indexOfPicked = i;
                break;
            }
        }
        if (indexOfPicked == correctIndex) score++;
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
        u64 indexOfPicked = std::numeric_limits<u64>::max();
        for (u64 i = 0; i < choices.size(); i++)
        {
            if (choices[i]->isChecked())
            {
                indexOfPicked = i;
                break;
            }
        }
        if (indexOfPicked == correctIndex) score++;
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

void QVerityMultipleChoiceQuestion::setChoice(const std::string& choice, u64 index)
{
    choices.at(index)->setText(QString::fromStdString(choice));
}

void QVerityMultipleChoiceQuestion::setCorrectChoiceIndex(u64 index)
{
    correctIndex = index;
    shuffle();
}

void QVerityMultipleChoiceQuestion::removeChoice(u64 index)
{
    QRadioButton* removed = choices.at(index);
    choices.erase(choices.begin() + index);
    if (correctIndex > index)
    {
        correctIndex--;
    }
    else if (correctIndex == index)
    {
        correctIndex = 0;
    }
    if (removed == ui->radioButton || removed == ui->radioButton_2)
    {
        ui->verticalLayout->removeWidget(removed);
        removed->setVisible(false);
    }
    else
    {
        ui->verticalLayout->removeWidget(removed);
        delete removed;
    }
}

void QVerityMultipleChoiceQuestion::onChoicePicked()
{
    u64 indexOfPicked = std::numeric_limits<u64>::max();
    for (u64 i = 0; i < choices.size(); i++)
    {
        if (choices[i]->isChecked())
        {
            indexOfPicked = i;
            break;
        }
    }
    if (indexOfPicked == correctIndex) emit answeredCorrectly();
    else emit answeredIncorrectly();
}

std::string QVerityMultipleChoiceQuestion::getChoice(u64 index)
{
    return choices.at(index)->text().toStdString();
}

tmc::suyudo::QuestionType QVerityMultipleChoiceQuestion::getQuestionType()
{
    return tmc::suyudo::MULTIPLE_CHOICE;
}

tmc::suyudo::UsedIn QVerityMultipleChoiceQuestion::usedIn()
{
    return tmc::suyudo::VERITY;
}

tmc::Verity::keygenIndex QVerityMultipleChoiceQuestion::getInfluence()
{
    return influence;
}

void QVerityMultipleChoiceQuestion::setQuestionText(const std::string& str)
{
    ui->groupBox->setTitle(QString::fromStdString(str));
}

QVerityMultipleChoiceQuestion::~QVerityMultipleChoiceQuestion()
{
    delete ui;
}

} // namespace UI
} // namespace tmc
