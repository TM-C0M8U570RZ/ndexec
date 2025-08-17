#ifndef QCACHEPASSWORDPAGE_H
#define QCACHEPASSWORDPAGE_H

#include <QWizardPage>

namespace tmc {
namespace UI {

namespace Ui {
class QCachePasswordPage;
}

class QCachePasswordPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit QCachePasswordPage(QWidget *parent = nullptr);
    ~QCachePasswordPage();
    virtual bool isComplete() const override;
    std::string getPassword();

private:
    Ui::QCachePasswordPage *ui;
};

} // namespace UI
} // namespace tmc
#endif // QCACHEPASSWORDPAGE_H
