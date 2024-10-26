#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    m_init.openBinary();
    BinaryFormat binary_information = m_init.returnBinaryInformation();
    if (binary_information.m_format == "PE")
    {
	qDebug() << "PE binary detected.";
    }
    else if (binary_information.m_format == "ELF")
    {
	qDebug() << "ELF binary detected.";
    }
    else if (binary_information.m_format == "Mach-O")
    {
	qDebug() << "Mach-O binary detected.";
    }
    else
    {
	qDebug() << "Unknown binary detected.";
    }
}
