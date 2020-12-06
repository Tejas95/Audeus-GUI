#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
#include <qline.h>
#include <qbuttongroup.h>
#include <Audeus.h>
#include <QtConcurrent>
#include <QtGui>
#include <QtCore>
#include <QDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

     PaStream *stream;
     audioWrapper ap;

    //PaStreamParameters inputParameters, outputParameters;
    //PaStream *stream;
    //PaError err;


private slots:

    void on_PBAutoSetGain_clicked();

    void on_PBStartAudio_clicked();

private:
    Ui::MainWindow *ui;

protected:
    void paintEvent(QPaintEvent *e);

};

#endif // MAINWINDOW_H
