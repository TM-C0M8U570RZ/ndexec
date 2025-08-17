#ifndef QVERITYMULTIPLECHOICEQUESTION_H
#define QVERITYMULTIPLECHOICEQUESTION_H

#include <QWizardPage>
#include <vector>
#include "questioninterface.h"
#include <QRadioButton>
#include "veritycallback.h"
#include <algorithm>
#include <random>

namespace tmc {
namespace UI {

namespace Ui {
class QVerityMultipleChoiceQuestion;
}

class QVerityMultipleChoiceQuestion : public QWizardPage, QuestionInterface
{
    Q_OBJECT

public:
    explicit QVerityMultipleChoiceQuestion(QWidget *parent = nullptr, tmc::Verity::keygenIndex influence = tmc::Verity::r13);
    ~QVerityMultipleChoiceQuestion();
    void setQuestionText(const std::string& str);
    virtual tmc::suyudo::QuestionType getQuestionType() override;
    virtual tmc::suyudo::UsedIn usedIn() override;
    tmc::Verity::keygenIndex getInfluence();
    std::string getChoice(u64 index);
    virtual bool isComplete() const override;
    virtual int nextId() const override;

public slots:
    void addChoice(const std::string& choice);
    void setChoice(const std::string& choice, u64 index);
    void setCorrectChoiceIndex(u64 index);
    void removeChoice(u64 index);
    void shuffle();

signals:
    void answeredCorrectly();
    void answeredIncorrectly();

private slots:
    void onChoicePicked();

private:
    Ui::QVerityMultipleChoiceQuestion *ui;
    std::vector<QRadioButton*> choices;
    tmc::Verity::keygenIndex influence;
    u64 correctIndex;
    std::mt19937_64* g;

};

} // namespace UI
} // namespace tmc
#endif // QVERITYMULTIPLECHOICEQUESTION_H
