#ifndef R18VERITYPASSPAGE_H
#define R18VERITYPASSPAGE_H

#include <QWizardPage>
#include <tmc_application.h>

namespace tmc {
namespace suyudo {

namespace Ui {
class R18VerityPassPage;
}

class R18VerityPassPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit R18VerityPassPage(QWidget *parent = nullptr);
    ~R18VerityPassPage();

private:
    Ui::R18VerityPassPage *ui;
};

} // namespace suyudo
} // namespace tmc
#endif // R18VERITYPASSPAGE_H
