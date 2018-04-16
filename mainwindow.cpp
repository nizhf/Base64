#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clipboard = QApplication::clipboard();
    ui->textEditEncode->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
    ui->textBrowserDecode->setWordWrapMode(QTextOption::WrapAnywhere);
    ui->textEditEncode->setStyleSheet("QTextEdit{font-size: 15px;}");
    ui->textBrowserDecode->setStyleSheet("QTextBrowser{font-size: 15px;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnEncode_clicked()
{
    auto str = ui->textEditEncode->toPlainText().toStdString();
    auto result = Base64::encode(str);
    ui->textBrowserDecode->setText(result.c_str());
}

void MainWindow::on_btnDecode_clicked()
{
    auto str = ui->textEditEncode->toPlainText().toStdString();
    auto result = Base64::decode(str);
    ui->textBrowserDecode->setText(result.c_str());
}

void MainWindow::on_btnClear_clicked()
{
    ui->textBrowserDecode->clear();
    ui->textEditEncode->clear();
}

void MainWindow::on_btnCopy_clicked()
{
    clipboard->setText(ui->textBrowserDecode->toPlainText());
}
