#include "input_loudness.h"
#include "ui_input_loudness.h"
#include "noise_6.h"
#include "pawrapper.h"
#include "Audeus.h"

Input_Loudness::Input_Loudness(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Loudness)
{
    ui->setupUi(this);
}

Input_Loudness::~Input_Loudness()
{
    delete ui;
}

void Input_Loudness::on_PBNext_clicked(void)
{
    this->close();
}

void Input_Loudness::on_PBStart_clicked()
{
    CAudeus AUD;
    paWrapper ap;

    AUD.startChannel = 0;
    AUD.endChannel = NUM_CHANNELS;

    ap.startAudioInput();
}
