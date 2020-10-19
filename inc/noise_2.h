#ifndef NOISE_2_H
#define NOISE_2_H

#include <QDialog>

namespace Ui {
class Noise_2;
}

class Noise_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Noise_2(QWidget *parent = nullptr);
    ~Noise_2();

private slots:
    void on_PBSkip_clicked();

    void on_PBStart_clicked();

private:
    Ui::Noise_2 *ui;
};

#endif // NOISE_2_H
