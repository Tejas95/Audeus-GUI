#include "noise_3.h"
#include "ui_noise_3.h"
#include "noise_4.h"
#include "noise_2.h"
#include "Audeus.h"
#include "pawrapper.h"

Noise_3::Noise_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Noise_3)
{
    ui->setupUi(this);
}

Noise_3::~Noise_3()
{
    delete ui;
}

void Noise_3::on_PBSkip_clicked()
{
    this->close();

    Noise_4 noise4;
    noise4.setModal(true);
    noise4.exec();
}

void Noise_3::on_PBStart_clicked()
{
    CAudeus AUD;
    paWrapper ap;

    AUD.startChannel = 2;
    AUD.endChannel = 2;

    ui->Status_Label->setText("In Progress");
    ap.startAudioNoise();
    ui->Status_Label->setText("Done");
}
