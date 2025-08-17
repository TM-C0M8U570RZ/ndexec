#include "r18veritypasspage.h"
#include "ui_r18veritypasspage.h"

namespace tmc {
namespace suyudo {

R18VerityPassPage::R18VerityPassPage(QWidget *parent)
    : QWizardPage(parent)
    , ui(new Ui::R18VerityPassPage)
{
    ui->setupUi(this);
    tmc::Application* a = tmc::Application::getGlobalInstance();
    if (a->hasArg("honoo-safe") || a->hasArg('s'))
    {
        std::string shiitakePath = a->resolveResource("romfs:/shiitake/honoo_chinpoGaNai/default.png").string();
        ui->label_2->setPixmap(QString::fromStdString(shiitakePath));
    }
    else if (a->hasArg("honoo-mushroom") || a->hasArg('m'))
    {
        std::string shiitakePath = (a->hasArg("soft") || a->hasArg('f')) ?
                                       a->resolveResource("romfs:/shiitake/honoo_hitoNoChinpoGaAru/soft.png").string() :
                                       a->resolveResource("romfs:/shiitake/honoo_hitoNoChinpoGaAru/default.png").string();
        ui->label_2->setPixmap(QString::fromStdString(shiitakePath));
    }
    else if (a->hasArg("honoo-rocket") || a->hasArg('r'))
    {
        std::string shiitakePath = (a->hasArg("soft") || a->hasArg('f')) ?
                                       a->resolveResource("romfs:/shiitake/honoo_inuNoChinpoGaAru/soft.png").string() :
                                       a->resolveResource("romfs:/shiitake/honoo_inuNoChinpoGaAru/default.png").string();
        ui->label_2->setPixmap(QString::fromStdString(shiitakePath));
    }
    else
    {
        std::string shiitakePath = a->resolveResource("romfs:/shiitake/honoo_chinpoGaNai/default.png").string();
        ui->label_2->setPixmap(QString::fromStdString(shiitakePath));
    }
}

R18VerityPassPage::~R18VerityPassPage()
{
    delete ui;
}

} // namespace suyudo
} // namespace tmc
