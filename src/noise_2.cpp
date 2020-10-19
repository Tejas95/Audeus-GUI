#include "noise_2.h"
#include "ui_noise_2.h"
#include "noise_3.h"
#include "noise_1.h"
#include "Audeus.h"
#include "pawrapper.h"

Noise_2::Noise_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Noise_2)
{
    ui->setupUi(this);
}

Noise_2::~Noise_2()
{
    delete ui;
}

void Noise_2::on_PBSkip_clicked()
{
    this ->close();

    Noise_3 noise3;
    noise3.setModal(true);
    noise3.exec();
}

void Noise_2::on_PBStart_clicked()
{
    CAudeus AUD;
    paWrapper ap;

    AUD.startChannel = 1;
    AUD.endChannel = 1;

    ui->Status_Label->setText("In Progress");
    ap.startAudioNoise();
    ui->Status_Label->setText("Done");
}
