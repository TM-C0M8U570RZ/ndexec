#ifndef TEGAMI_H
#define TEGAMI_H

#include <QMainWindow>
#include <tmc_application.h>
#include <fstream>

namespace Ui {
class Tegami;
}

class Tegami : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tegami(QWidget *parent = nullptr);
    ~Tegami();

protected:
    void closeEvent(QCloseEvent* evt);

private:
    Ui::Tegami *ui;
    tmc::Application* a;
};

#endif // TEGAMI_H
