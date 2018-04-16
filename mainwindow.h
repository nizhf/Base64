#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QClipboard>
#include "base64.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnEncode_clicked();

    void on_btnDecode_clicked();

    void on_btnClear_clicked();

    void on_btnCopy_clicked();

private:
    Ui::MainWindow *ui;
    QClipboard *clipboard;
};

#endif // MAINWINDOW_H
