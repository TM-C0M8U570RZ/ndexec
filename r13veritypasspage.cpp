#include "r13veritypasspage.h"
#include "ui_r13veritypasspage.h"

namespace tmc {
namespace suyudo {

R13VerityPassPage::R13VerityPassPage(QWidget *parent)
    : QWizardPage(parent)
    , ui(new Ui::R13VerityPassPage)
{
    ui->setupUi(this);
}

R13VerityPassPage::~R13VerityPassPage()
{
    delete ui;
}

} // namespace suyudo
} // namespace tmc
