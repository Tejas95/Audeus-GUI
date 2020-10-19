#include "noise_6.h"
#include "ui_noise_6.h"
#include "mainwindow.h"
#include "input_loudness.h"
#include "noise_5.h"
#include "Audeus.h"
#include "pawrapper.h"

Noise_6::Noise_6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Noise_6)
{
    ui->setupUi(this);
}

Noise_6::~Noise_6()
{
    delete ui;
}

void Noise_6::on_PBSkip_clicked()
{
    this->close();

    Input_Loudness inputloudness;
    inputloudness.setModal(true);
    inputloudness.exec();
}

void Noise_6::on_PBStart_clicked()
{
    CAudeus AUD;
    paWrapper ap;

    AUD.startChannel = 5;
    AUD.endChannel = 5;

    ui->Status_Label->setText("In Progress");
    ap.startAudioNoise();
    ui->Status_Label->setText("Done");
}
