#include "qcachepasswordpage.h"
#include "ui_qcachepasswordpage.h"

namespace tmc {
namespace UI {

QCachePasswordPage::QCachePasswordPage(QWidget *parent)
    : QWizardPage(parent)
    , ui(new Ui::QCachePasswordPage)
{
    ui->setupUi(this);
    registerField("Password*", ui->lineEdit);
    registerField("Confirm*", ui->lineEdit_2);
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SIGNAL(completeChanged()));
    connect(ui->lineEdit_2, SIGNAL(textChanged(QString)), this, SIGNAL(completeChanged()));
}

QCachePasswordPage::~QCachePasswordPage()
{
    delete ui;
}

std::string QCachePasswordPage::getPassword()
{
    return (isComplete() ? ui->lineEdit->text().toStdString() : "");
}

bool QCachePasswordPage::isComplete() const
{
    return (ui->lineEdit->text() == ui->lineEdit_2->text() &&
            ui->lineEdit->text() != "");
}

} // namespace UI
} // namespace tmc
