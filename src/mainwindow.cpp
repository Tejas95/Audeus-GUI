#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gettingstarted.h"
#include "pawrapper.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Wallpaper
    QPixmap bkgnd("C:\\Users\\temanjunath.ADHARMAN\\Desktop\\Audeus\\DarkBlueWallpaper.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    //Channel Label Colors
    ui->Ch1Label->setStyleSheet("QLabel { color : white; }");
    ui->Ch2Label->setStyleSheet("QLabel { color : white; }");
    ui->Ch3Label->setStyleSheet("QLabel { color : white; }");
    ui->Ch4Label->setStyleSheet("QLabel { color : white; }");
    ui->Ch5Label->setStyleSheet("QLabel { color : white; }");
    ui->Ch6Label->setStyleSheet("QLabel { color : white; }");
    ui->MasterLabel->setStyleSheet("QLabel { color : white; }");



    //Added Gain Label Colors
    ui->label_9->setStyleSheet("QLabel { color : grey; }");
    ui->label_12->setStyleSheet("QLabel { color : grey; }");
    ui->label_14->setStyleSheet("QLabel { color : grey; }");
    ui->label_16->setStyleSheet("QLabel { color : grey; }");
    ui->label_18->setStyleSheet("QLabel { color : grey; }");
    ui->label_20->setStyleSheet("QLabel { color : grey; }");

    //Slider Loudness Color
    ui->label_64->setStyleSheet("QLabel { color : grey; }");
    ui->label_65->setStyleSheet("QLabel { color : grey; }");
    //ui->label_66->setStyleSheet("QLabel { color : grey; }");
    ui->label_67->setStyleSheet("QLabel { color : grey; }");
    ui->label_68->setStyleSheet("QLabel { color : grey; }");
    ui->label_69->setStyleSheet("QLabel { color : grey; }");

    ui->label_34->setStyleSheet("QLabel { color : grey; }");
    //ui->label_35->setStyleSheet("QLabel { color : grey; }");
    ui->label_36->setStyleSheet("QLabel { color : grey; }");
    ui->label_37->setStyleSheet("QLabel { color : grey; }");
    ui->label_38->setStyleSheet("QLabel { color : grey; }");
    ui->label_39->setStyleSheet("QLabel { color : grey; }");

    ui->label_40->setStyleSheet("QLabel { color : grey; }");
    ui->label_41->setStyleSheet("QLabel { color : grey; }");
    ui->label_42->setStyleSheet("QLabel { color : grey; }");
    //ui->label_43->setStyleSheet("QLabel { color : grey; }");
    ui->label_44->setStyleSheet("QLabel { color : grey; }");
    ui->label_45->setStyleSheet("QLabel { color : grey; }");

    ui->label_46->setStyleSheet("QLabel { color : grey; }");
    ui->label_47->setStyleSheet("QLabel { color : grey; }");
    ui->label_48->setStyleSheet("QLabel { color : grey; }");
    //ui->label_49->setStyleSheet("QLabel { color : grey; }");
    ui->label_50->setStyleSheet("QLabel { color : grey; }");
    ui->label_51->setStyleSheet("QLabel { color : grey; }");

    ui->label_52->setStyleSheet("QLabel { color : grey; }");
    ui->label_53->setStyleSheet("QLabel { color : grey; }");
    ui->label_54->setStyleSheet("QLabel { color : grey; }");
    //ui->label_55->setStyleSheet("QLabel { color : grey; }");
    ui->label_56->setStyleSheet("QLabel { color : grey; }");
    ui->label_57->setStyleSheet("QLabel { color : grey; }");

    ui->label_58->setStyleSheet("QLabel { color : grey; }");
    ui->label_59->setStyleSheet("QLabel { color : grey; }");
    ui->label_60->setStyleSheet("QLabel { color : grey; }");
    //ui->label_61->setStyleSheet("QLabel { color : grey; }");
    ui->label_62->setStyleSheet("QLabel { color : grey; }");
    ui->label_63->setStyleSheet("QLabel { color : grey; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PBAutoSetGain_clicked()
{
    GettingStarted noiseIntro;
    noiseIntro.setModal(true);
    noiseIntro.exec();
}



