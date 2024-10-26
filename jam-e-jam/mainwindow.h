#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "init.h"

// Define debug mode for conditional debug output
#define debug_module

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

private:
    Ui::MainWindow* ui;

private:
    Init m_init;
};
#endif // MAINWINDOW_H
