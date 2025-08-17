#ifndef VERITYWIZARD_H
#define VERITYWIZARD_H

#include <QWizard>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "tegami.h"
#include <veritycallback.h>
#include <random>
#include <algorithm>
#include "qcachepasswordpage.h"
#include "r13verityfailpage.h"
#include "r13veritypasspage.h"
#include "r18verityfailpage.h"
#include "r18veritypasspage.h"
#include <fstream>
#include <QProcess>
#include <QCloseEvent>

class DebugView;

namespace tmc {
namespace suyudo {

namespace Ui {
class VerityWizard;
}

class VerityWizard : public QWizard
{
    Q_OBJECT

public:
    explicit VerityWizard(QWidget *parent = nullptr);
    ~VerityWizard();
    bool isCorrectlyAnswered();
    std::vector<bool> getAnswers();
    std::mt19937_64* getRngWithGlobalSeed();

protected:
    void closeEvent(QCloseEvent* evt);

private:
    bool hasAlreadyVisited(int id);
    Ui::VerityWizard *ui;
    QMenuBar* mb;
    QMenu* viewMenu;
    QAction* tegamiAction;
    QAction* debugAction;
    std::shared_ptr<Tegami> tg;
    std::vector<u8> wipKeys;
    bool correctlyAnswered;
    std::shared_ptr<DebugView> dv;
    std::vector<int> alreadyVisited;
    std::vector<std::shared_ptr<QWizardPage>> r13AuthQuestions;
    std::vector<std::shared_ptr<QWizardPage>> r18AuthQuestions;
    std::shared_ptr<R13VerityPassPage> r13PassPage;
    std::shared_ptr<r13verityfailpage> r13FailPage;
    std::shared_ptr<R18VerityPassPage> r18PassPage;
    std::shared_ptr<r18VerityFailPage> r18FailPage;
    std::shared_ptr<tmc::UI::QCachePasswordPage> cpp;
    std::random_device rd;
    std::mt19937_64* g;
    u64 currentQuestion;
    std::vector<bool> answers;

};

} // namespace UI
} // namespace tmc
#endif // VERITYWIZARD_H
