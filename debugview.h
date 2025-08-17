#ifndef DEBUGVIEW_H
#define DEBUGVIEW_H

#include <QMainWindow>

namespace Ui {
class DebugView;
}

namespace tmc {
namespace suyudo {
class VerityWizard;
}
}

class DebugView : public QMainWindow
{
    Q_OBJECT

public:
    explicit DebugView(QWidget *parent = nullptr);
    ~DebugView();

protected:
    void closeEvent(QCloseEvent* evt);

private:
    Ui::DebugView *ui;
    tmc::suyudo::VerityWizard* vw;
};

#endif // DEBUGVIEW_H
