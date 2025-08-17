#ifndef QVERITYMATCHINGQUESTION_H
#define QVERITYMATCHINGQUESTION_H

#include <QWizardPage>
#include <veritycallback.h>
#include "questioninterface.h"
#include <QLabel>
#include <QComboBox>
#include <QFormLayout>
#include <algorithm>
#include <random>

namespace tmc {
namespace UI {

namespace Ui {
class QVerityMatchingQuestion;
}

class QVerityMatchingQuestion : public QWizardPage, QuestionInterface
{
    Q_OBJECT

public:
    using DefChoiceId = struct DefChoiceId {std::string definition; std::string choice; std::string identifier;};
    explicit QVerityMatchingQuestion(QWidget *parent = nullptr, tmc::Verity::keygenIndex influence = tmc::Verity::r13);
    ~QVerityMatchingQuestion();
    virtual tmc::suyudo::QuestionType getQuestionType() override;
    std::string getQuestionText();
    DefChoiceId getMatch(u64 index);
    virtual tmc::suyudo::UsedIn usedIn() override;
    tmc::Verity::keygenIndex getInfluence();
    u64 getMatchCount();
    virtual int nextId() const override;

public slots:
    void setQuestionText(const std::string& questionText);
    void addMatch(const std::string& definition, const std::string& choice, const std::string& identifier);
    void setMatch(const std::string& definition, const std::string& choice, const std::string& identifier, u64 index);
    void removeMatch(u64 index);
    void shuffle();

private slots:
    void onChoicePicked(int index);

signals:
    void answeredCorrectly();
    void answeredIncorrectly(std::vector<tmc::UI::QVerityMatchingQuestion::DefChoiceId> partialCredit);

private:
    void refreshUI();
    Ui::QVerityMatchingQuestion *ui;
    std::vector<DefChoiceId> matches;
    tmc::Verity::keygenIndex influence;
    std::vector<QLabel*> definitions;
    std::vector<QComboBox*> choiceInputs;
    QFormLayout* lyt;
    std::mt19937_64* g;
};

} // namespace UI
} // namespace tmc
#endif // QVERITYMATCHINGQUESTION_H
