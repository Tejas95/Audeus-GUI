#ifndef NOISE_1_H
#define NOISE_1_H

#include <QDialog>

namespace Ui {
class Noise_1;
}

class Noise_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Noise_1(QWidget *parent = nullptr);
    ~Noise_1();

private slots:
    void on_PBSkip_clicked();

    void on_PBStart_clicked();

private:
    Ui::Noise_1 *ui;
};

#endif // NOISE_1_H
