#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    trans = new QTranslator(this);
    QFile file("D:/Qt/Project/lab2/lab2/eng.txt");
    QByteArray block;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    while (!file.atEnd()){
        block = file.readLine();
        ui->comboBox->addItems(QStringList() << block);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QFile file3("D:/Qt/Project/lab2/lab2/eng.txt");
    QFile file4("D:/Qt/Project/lab2/lab2/rus.txt");
    QMap <QString, QString> map1;
    if (!file3.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    if (!file4.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    while (!file3.atEnd()){
        map1[file3.readLine()] = file4.readLine();
    }
    if (map1.count(ui->lineEdit->text() + '\n') == 0){
        ui->label->setText("Такого слова в словаре нет");
    }
    else {
        ui->label->setText(map1[ui->lineEdit->text() + '\n']);
    }
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QFile file1("D:/Qt/Project/lab2/lab2/eng.txt");
    QFile file2("D:/Qt/Project/lab2/lab2/rus.txt");
    QMap <QString, QString> map2;
    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    while (!file1.atEnd()){
        map2[file1.readLine()] = file2.readLine();
    }
    ui->label->setText(map2[arg1]);

}

