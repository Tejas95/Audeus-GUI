#ifndef NOISE_4_H
#define NOISE_4_H

#include <QDialog>

namespace Ui {
class Noise_4;
}

class Noise_4 : public QDialog
{
    Q_OBJECT

public:
    explicit Noise_4(QWidget *parent = nullptr);
    ~Noise_4();

private slots:
    void on_PBSkip_clicked();

    void on_PBStart_clicked();

private:
    Ui::Noise_4 *ui;
};

#endif // NOISE_4_H
