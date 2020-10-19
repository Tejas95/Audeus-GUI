#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
#include <qline.h>
#include <qbuttongroup.h>
#include <Audeus.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    PaStreamParameters inputParameters, outputParameters;
    PaStream *stream;
    PaError err;


private slots:

    void on_PBAutoSetGain_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
