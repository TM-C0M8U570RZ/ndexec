#ifndef R13VERITYFAILPAGE_H
#define R13VERITYFAILPAGE_H

#include <QWizardPage>

namespace tmc {
namespace suyudo {

namespace Ui {
class r13verityfailpage;
}

class r13verityfailpage : public QWizardPage
{
    Q_OBJECT

public:
    explicit r13verityfailpage(QWidget *parent = nullptr);
    ~r13verityfailpage();
    virtual int nextId() const override;

private:
    Ui::r13verityfailpage *ui;
};

} // namespace suyudo
} // namespace tmc
#endif // R13VERITYFAILPAGE_H
