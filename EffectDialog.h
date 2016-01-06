#ifndef EFFECTDIALOG_H
#define EFFECTDIALOG_H

#include <QDialog>

namespace Ui {
class EffectDialog;
}

class EffectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EffectDialog(QWidget *parent = 0);
    ~EffectDialog();

private:
    Ui::EffectDialog *ui;
};

#endif // EFFECTDIALOG_H
