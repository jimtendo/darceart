#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQmlListProperty>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QString> layers READ layers NOTIFY layersChanged)
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QQmlListProperty<QString> layers();

signals:
    void layersChanged();

private slots:
    void on_actionOpen_triggered();

    void on_actionFullscreen_triggered();

    void on_addLayerButton_clicked();

    void on_removeLayerButton_clicked();

private:
    Ui::MainWindow *ui;

    // For capturing escape key in fullscreen
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
