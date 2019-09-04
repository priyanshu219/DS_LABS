#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dict.read();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_2->setText(QString::fromUtf8(dict.search(ui->lineEdit->text().QString::toUtf8().constData()).c_str()));
    ui->label_2->setCursor(Qt::ArrowCursor);
}
