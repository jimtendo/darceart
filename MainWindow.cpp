#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QInputDialog>
#include <QQuickWidget>
#include <QQmlContext>
#include <QQuickItem>
#include <QFileDialog>

#include "EffectDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->quickWidget->setSource(QUrl("qrc:/QML/Main.qml"));

    ui->layersWidget->setHeaderLabel("Layer");
}

MainWindow::~MainWindow()
{
    delete ui;
}

QQmlListProperty<QString> MainWindow::layers()
{
    //ui->layersWidget->items;

    QList<QString> items;

    return QQmlListProperty<QString>();
}

void MainWindow::on_actionOpen_triggered()
{
    // Show dialog and get filename
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Video Files (*.*)"));

    // If no filename was specified, just return
    if (fileName.isEmpty()) {
        return;
    }

    // Set this as the media to play
    QObject *mediaPlayer = ui->quickWidget->rootObject()->findChild<QObject*>("mediaPlayer");
    mediaPlayer->setProperty("source", "file:" + fileName);
}

void MainWindow::on_actionFullscreen_triggered()
{
    // This doesn't seem to work, but Qt 5.5 introduces the quickWidget->quickWindow() function
    // so we might be able to use this object and then showFullscreen() on that
    ui->quickWidget->showFullScreen();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        ui->quickWidget->showNormal();
    }
}

void MainWindow::on_addLayerButton_clicked()
{
    QStringList types;
    types << "Video";
    types << "Effect";

    QString type = QInputDialog::getItem(this, tr("Layer Type"), tr("Select Layer Type:"), types, 0, false);

    if (type == "Effect") {
        EffectDialog effectDialog;
        effectDialog.exec();

        QVariant returnedValue;
        QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "addEffect",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, 1), Q_ARG(QVariant, "hello"));
    }

    else if (type == "Video") {
        QString filename = "file:" + QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Video Files (*.webm)"));

        QVariant returnedValue;
        QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "addVideo",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, 1), Q_ARG(QVariant, filename));
    }

    QTreeWidgetItem *layer = new QTreeWidgetItem(ui->layersWidget);
    layer->setIcon(0, QIcon::fromTheme("layer-visible-on"));
    layer->setText(0, "New Layer");
}

void MainWindow::on_removeLayerButton_clicked()
{

}
