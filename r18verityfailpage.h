#ifndef R18VERITYFAILPAGE_H
#define R18VERITYFAILPAGE_H

#include <QWizardPage>

namespace Ui {
class r18VerityFailPage;
}

class r18VerityFailPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit r18VerityFailPage(QWidget *parent = nullptr);
    ~r18VerityFailPage();
    virtual int nextId() const override;

private:
    Ui::r18VerityFailPage *ui;
};

#endif // R18VERITYFAILPAGE_H
