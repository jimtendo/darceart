#include "EffectDialog.h"
#include "ui_EffectDialog.h"

EffectDialog::EffectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EffectDialog)
{
    ui->setupUi(this);
}

EffectDialog::~EffectDialog()
{
    delete ui;
}
