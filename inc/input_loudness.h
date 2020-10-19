#ifndef INPUT_LOUDNESS_H
#define INPUT_LOUDNESS_H

#include <QDialog>

namespace Ui {
class Input_Loudness;
}

class Input_Loudness : public QDialog
{
    Q_OBJECT

public:
    explicit Input_Loudness(QWidget *parent = nullptr);
    ~Input_Loudness();

private slots:
    void on_PBNext_clicked(void);

    void on_PBStart_clicked();

private:
    Ui::Input_Loudness *ui;
};

#endif // INPUT_LOUDNESS_H
