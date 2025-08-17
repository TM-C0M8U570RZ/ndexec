#include "debugview.h"
#include "ui_debugview.h"
#include "veritywizard.h"

DebugView::DebugView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DebugView)
{
    ui->setupUi(this);
    vw = dynamic_cast<tmc::suyudo::VerityWizard*>(this->parent());
    setEnabled(true);
    ui->label->setText((vw->isCorrectlyAnswered() ? "correct" : "incorrect"));
}

DebugView::~DebugView()
{
    delete ui;
}

void DebugView::closeEvent(QCloseEvent* evt)
{
    QWidget::closeEvent(evt);
    vw->setEnabled(true);
}
