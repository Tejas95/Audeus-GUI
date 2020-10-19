#ifndef NOISE_6_H
#define NOISE_6_H

#include <QDialog>

namespace Ui {
class Noise_6;
}

class Noise_6 : public QDialog
{
    Q_OBJECT

public:
    explicit Noise_6(QWidget *parent = nullptr);
    ~Noise_6();

private slots:
    void on_PBSkip_clicked();

    void on_PBStart_clicked();

private:
    Ui::Noise_6 *ui;
};

#endif // NOISE_6_H
