#include "veritywizard.h"
#include "ui_veritywizard.h"
#include "debugview.h"
#include "suyudorunnerstandard.h"
#include "suyudorunnerhelpers.h"

namespace tmc {
namespace suyudo {

VerityWizard::VerityWizard(QWidget *parent)
    : QWizard(parent)
    , ui(new Ui::VerityWizard), rd(), g(new std::mt19937_64(rd()))
{
    mb = new QMenuBar(this);
    viewMenu = new QMenu("View");
    tegamiAction = new QAction("A letter to the government about copyright law");
    debugAction = new QAction("Debug Window");
    alreadyVisited = {};
    wipKeys = std::vector<u8>(512, 0);
    answers = std::vector<bool>(0);
    connect(tegamiAction, &QAction::triggered, this, [this] {
        setEnabled(false);
        tg = std::make_shared<Tegami>(this);
        tg->show();
    });
    connect(debugAction, &QAction::triggered, this, [this] {
        setEnabled(false);
        dv = std::make_shared<DebugView>(this);
        dv->show();
    });
    connect(this, &QWizard::currentIdChanged, this, [this](int id){
        if (currentId() > currentQuestion && !(hasAlreadyVisited(currentQuestion)))
        {
            if ((currentQuestion >= 2 && currentQuestion <= 17) || (currentQuestion >= 20 && currentQuestion <= 35))
                answers.push_back(correctlyAnswered);
            if (currentId() == 19) answers.clear();
            correctlyAnswered = false;
            alreadyVisited.push_back(currentQuestion);
        }
        if (currentId() == 18)
        {
            std::vector<u8> mspcache = buildMspcache(false, false, this, cpp->getPassword());
            tmc::Application* a = tmc::Application::getGlobalInstance();
            std::string truncatedName = a->getLocalConfigDir().string();
            std::size_t found = truncatedName.find("runner");
            truncatedName.erase(truncatedName.begin() + found, truncatedName.end());
            std::filesystem::path outpath = truncatedName;
            if (a->hasArg('o'))
            {
                outpath = a->getAs<std::filesystem::path>('o');
            }
            else if (a->hasArg("output"))
            {
                outpath = a->getAs<std::filesystem::path>("output");
            }
            if (!std::filesystem::exists(outpath)) std::filesystem::create_directories(outpath);
            std::ofstream out(outpath / "PALLET.mspcache", std::ios::binary);
            out.write(reinterpret_cast<char*>(mspcache.data()), mspcache.size());
            out.close();
        }
        if (currentId() == 36)
        {
            std::vector<u8> mspcache = buildMspcache(true, false, this, cpp->getPassword());
            tmc::Application* a = tmc::Application::getGlobalInstance();
            std::string truncatedName = a->getLocalConfigDir().string();
            std::size_t found = truncatedName.find("runner");
            truncatedName.erase(truncatedName.begin() + found, truncatedName.end());
            std::filesystem::path outpath = truncatedName;
            if (a->hasArg('o'))
            {
                outpath = a->getAs<std::filesystem::path>('o');
            }
            else if (a->hasArg("output"))
            {
                outpath = a->getAs<std::filesystem::path>("output");
            }
            if (!std::filesystem::exists(outpath)) std::filesystem::create_directories(outpath);
            std::ofstream out(outpath / "PALLET.mspcache", std::ios::binary);
            out.write(reinterpret_cast<char*>(mspcache.data()), mspcache.size());
            out.close();
        }
        if (currentId() == 37)
        {
            std::vector<u8> mspcache = buildMspcache(true, true, this, cpp->getPassword());
            tmc::Application* a = tmc::Application::getGlobalInstance();
            std::string truncatedName = a->getLocalConfigDir().string();
            std::size_t found = truncatedName.find("runner");
            truncatedName.erase(truncatedName.begin() + found, truncatedName.end());
            std::filesystem::path outpath = truncatedName;
            if (a->hasArg('o'))
            {
                outpath = a->getAs<std::filesystem::path>('o');
            }
            else if (a->hasArg("output"))
            {
                outpath = a->getAs<std::filesystem::path>("output");
            }
            if (!std::filesystem::exists(outpath)) std::filesystem::create_directories(outpath);
            std::ofstream out(outpath / "PALLET.mspcache", std::ios::binary);
            out.write(reinterpret_cast<char*>(mspcache.data()), mspcache.size());
            out.close();
        }
        currentQuestion = currentId();
    });
    debugAction->setShortcut(QKeySequence(QKeyCombination(Qt::AltModifier | Qt::ShiftModifier, Qt::Key_F8)));
    viewMenu->addAction(tegamiAction);
    // viewMenu->addAction(debugAction);
    mb->addMenu(viewMenu);
    ui->setupUi(this);
    r13PassPage = std::make_shared<R13VerityPassPage>(this);
    r13FailPage = std::make_shared<r13verityfailpage>(this);
    setPage(18, r13FailPage.get());
    setPage(19, r13PassPage.get());
    r18PassPage = std::make_shared<R18VerityPassPage>(this);
    r18FailPage = std::make_shared<r18VerityFailPage>(this);
    r13AuthQuestions = getStandardVerityQuestionsR13(this);
    std::shuffle(r13AuthQuestions.begin(), r13AuthQuestions.end(), *g);
    r18AuthQuestions = getStandardVerityQuestionsR18(this);
    std::shuffle(r18AuthQuestions.begin(), r18AuthQuestions.end(), *g);
    for (u8 i = 0; i < 16; i++)
    {
        std::shared_ptr<tmc::UI::QVerityMultipleChoiceQuestion> vmcq = std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(r13AuthQuestions[i]);
        std::shared_ptr<tmc::UI::QVerityMatchingQuestion> vmq = std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(r13AuthQuestions[i]);
        if (vmcq != nullptr)
        {
            setPage(2 + i, vmcq.get());
            connect(vmcq.get(), &tmc::UI::QVerityMultipleChoiceQuestion::answeredCorrectly, this, [this] {
                correctlyAnswered = true;
            });
            connect(vmcq.get(), &tmc::UI::QVerityMultipleChoiceQuestion::answeredIncorrectly, this, [this] {
                correctlyAnswered = false;
            });
        }
        else if (vmq != nullptr)
        {
            setPage(2 + i, vmq.get());
            connect(vmq.get(), &tmc::UI::QVerityMatchingQuestion::answeredCorrectly, this, [this] {
                correctlyAnswered = true;
            });
            connect(vmq.get(), &tmc::UI::QVerityMatchingQuestion::answeredIncorrectly, this,
                    [this](std::vector<tmc::UI::QVerityMatchingQuestion::DefChoiceId> partialCredit) {
                        correctlyAnswered = false;
                    });
        }
        std::shared_ptr<tmc::UI::QVerityMultipleChoiceQuestion> vmcq2 = std::dynamic_pointer_cast<tmc::UI::QVerityMultipleChoiceQuestion>(r18AuthQuestions[i]);
        std::shared_ptr<tmc::UI::QVerityMatchingQuestion> vmq2 = std::dynamic_pointer_cast<tmc::UI::QVerityMatchingQuestion>(r18AuthQuestions[i]);
        if (vmcq2 != nullptr)
        {
            setPage(20 + i, vmcq2.get());
            connect(vmcq2.get(), &tmc::UI::QVerityMultipleChoiceQuestion::answeredCorrectly, this, [this] {
                correctlyAnswered = true;
            });
            connect(vmcq2.get(), &tmc::UI::QVerityMultipleChoiceQuestion::answeredIncorrectly, this, [this] {
                correctlyAnswered = false;
            });
        }
        else if (vmq2 != nullptr)
        {
            setPage(20 + i, vmq2.get());
            connect(vmq2.get(), &tmc::UI::QVerityMatchingQuestion::answeredCorrectly, this, [this] {
                correctlyAnswered = true;
            });
            connect(vmq2.get(), &tmc::UI::QVerityMatchingQuestion::answeredIncorrectly, this,
                    [this](std::vector<tmc::UI::QVerityMatchingQuestion::DefChoiceId> partialCredit) {
                        correctlyAnswered = false;
            });
        }
    }
    currentQuestion = 0;
    removePage(1);
    cpp = std::make_shared<tmc::UI::QCachePasswordPage>(this);
    setPage(1, cpp.get());
    setPage(36, r18FailPage.get());
    setPage(37, r18PassPage.get());
    setStartId(0);
    correctlyAnswered = false;
}

void VerityWizard::closeEvent(QCloseEvent* evt)
{
    QWizard::closeEvent(evt);
    tmc::Application* a = tmc::Application::getGlobalInstance();
    if (a->getFilePaths().size())
    {
        QStringList args;
        for (u64 i = 1; i < a->getFilePaths().size(); i++)
        {
            args.push_back(QString::fromStdString(a->getFilePaths()[i].string()));
        }
        QProcess::execute(QString::fromStdString(a->getFilePaths()[0].string()), args);
    }
}

std::mt19937_64* VerityWizard::getRngWithGlobalSeed()
{
    return g;
}

std::vector<bool> VerityWizard::getAnswers()
{
    return answers;
}

bool VerityWizard::hasAlreadyVisited(int id)
{
    for (u64 i = 0; i < alreadyVisited.size(); i++)
    {
        if (alreadyVisited[i] == id) return true;
    }
    return false;
}

bool VerityWizard::isCorrectlyAnswered()
{
    return correctlyAnswered;
}

VerityWizard::~VerityWizard()
{
    delete ui;
    delete viewMenu;
    delete mb;
}

} // namespace UI
} // namespace tmc
