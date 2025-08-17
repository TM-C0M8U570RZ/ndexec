#include "r13verityfailpage.h"
#include "ui_r13verityfailpage.h"

namespace tmc {
namespace suyudo {

r13verityfailpage::r13verityfailpage(QWidget *parent)
    : QWizardPage(parent)
    , ui(new Ui::r13verityfailpage)
{
    ui->setupUi(this);
}

r13verityfailpage::~r13verityfailpage()
{
    delete ui;
}

int r13verityfailpage::nextId() const
{
    return -1;
}

} // namespace suyudo
} // namespace tmc
