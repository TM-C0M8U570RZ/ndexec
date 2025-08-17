#include "r18verityfailpage.h"
#include "ui_r18verityfailpage.h"

r18VerityFailPage::r18VerityFailPage(QWidget *parent)
    : QWizardPage(parent)
    , ui(new Ui::r18VerityFailPage)
{
    ui->setupUi(this);
}

r18VerityFailPage::~r18VerityFailPage()
{
    delete ui;
}

int r18VerityFailPage::nextId() const
{
    return -1;
}
