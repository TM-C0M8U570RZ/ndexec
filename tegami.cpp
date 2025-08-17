#include "tegami.h"
#include "ui_tegami.h"
#include <QWizard>

Tegami::Tegami(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tegami)
{
    a = tmc::Application::getGlobalInstance();
    std::ifstream in(a->resolveResource("romfs:/copyrewrite/index.html"), std::ios::binary);
    ui->setupUi(this);
    setEnabled(true);
    if (in.is_open())
    {
        in.seekg(0, std::ios::end);
        std::string letter(in.tellg(), 0);
        in.seekg(0, std::ios::beg);
        in.read(letter.data(), letter.size());
        ui->label->setText(QString::fromStdString(letter));
    }
    in.close();
}

Tegami::~Tegami()
{
    delete ui;
}

void Tegami::closeEvent(QCloseEvent* evt)
{
    QWidget::closeEvent(evt);
    dynamic_cast<QWizard*>(parent())->setEnabled(true);
}
