#include "noise_5.h"
#include "ui_noise_5.h"
#include "noise_6.h"
#include "noise_4.h"
#include "Audeus.h"
#include "pawrapper.h"

Noise_5::Noise_5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Noise_5)
{
    ui->setupUi(this);
}

Noise_5::~Noise_5()
{
    delete ui;
}

void Noise_5::on_PBSkip_clicked()
{
    this->close();

    Noise_6 noise6;
    noise6.setModal(true);
    noise6.exec();
}

void Noise_5::on_PBStart_clicked()
{
    CAudeus AUD;
    paWrapper ap;

    AUD.startChannel = 4;
    AUD.endChannel = 4;

    ui->Status_Label->setText("In Progress");
    ap.startAudioNoise();
    ui->Status_Label->setText("Done");
}
