#ifndef R13VERITYPASSPAGE_H
#define R13VERITYPASSPAGE_H

#include <QWizardPage>

namespace tmc {
namespace suyudo {

namespace Ui {
class R13VerityPassPage;
}

class R13VerityPassPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit R13VerityPassPage(QWidget *parent = nullptr);
    ~R13VerityPassPage();

private:
    Ui::R13VerityPassPage *ui;
};

} // namespace suyudo
} // namespace tmc
#endif // R13VERITYPASSPAGE_H
