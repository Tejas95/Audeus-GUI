#ifndef NOISE_5_H
#define NOISE_5_H

#include <QDialog>

namespace Ui {
class Noise_5;
}

class Noise_5 : public QDialog
{
    Q_OBJECT

public:
    explicit Noise_5(QWidget *parent = nullptr);
    ~Noise_5();

private slots:
    void on_PBSkip_clicked();

    void on_PBStart_clicked();

private:
    Ui::Noise_5 *ui;
};

#endif // NOISE_5_H
