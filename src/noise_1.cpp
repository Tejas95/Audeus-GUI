#include "noise_1.h"
#include "ui_noise_1.h"
#include "noise_2.h"
#include "pawrapper.h"
#include "Audeus.h"
#include "pawrapper.h"

Noise_1::Noise_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Noise_1)
{
    ui->setupUi(this);
}

Noise_1::~Noise_1()
{
    delete ui;
}

void Noise_1::on_PBSkip_clicked()
{
    this->close();

    Noise_2 noise2;
    noise2.setModal(true);
    noise2.exec();
}

void Noise_1::on_PBStart_clicked()
{
    CAudeus AUD;
    paWrapper ap;

    AUD.startChannel = 0;
    AUD.endChannel = 0;

    ui->Status_Label->setText("In Progress");
    ap.startAudioNoise();
    ui->Status_Label->setText("Done");
}
