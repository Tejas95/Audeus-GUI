#include "noise_4.h"
#include "ui_noise_4.h"
#include "noise_5.h"
#include "noise_3.h"
#include "Audeus.h"
#include "pawrapper.h"

Noise_4::Noise_4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Noise_4)
{
    ui->setupUi(this);
}

Noise_4::~Noise_4()
{
    delete ui;
}

void Noise_4::on_PBSkip_clicked()
{
    this->close();

    Noise_5 noise5;
    noise5.setModal(true);
    noise5.exec();
}

void Noise_4::on_PBStart_clicked()
{
    CAudeus AUD;
    paWrapper ap;

    AUD.startChannel = 3;
    AUD.endChannel = 3;

    ui->Status_Label->setText("In Progress");
    ap.startAudioNoise();
    ui->Status_Label->setText("Done");
}
