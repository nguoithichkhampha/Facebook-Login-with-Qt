#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtWebKit/QWebView>
#include <QtWebKit/QWebFrame>
#include "FacebookGoogleLogin.h"
#include "ui_webviewdialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    FacebookGoogleLogin       *_browserLogin;
    QDialog                   *webDialog;
    Ui::webDialog              webbrowser;
private slots:
    void on_pushButton_clicked();
    void on_GotData();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
