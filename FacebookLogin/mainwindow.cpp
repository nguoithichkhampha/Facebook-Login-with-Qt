#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _browserLogin = new FacebookGoogleLogin();
    connect(_browserLogin, SIGNAL(dataGot()), this, SLOT(on_GotData()));
    webDialog = new QDialog(this);
    webbrowser.setupUi(webDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QWebPage * page = new QWebPage;
    page->setNetworkAccessManager(_browserLogin);
    page->mainFrame()->load(
        QUrl("https://www.facebook.com/dialog/oauth?client_id=your_app_id&display=popup&redirect_uri=your_link_redirect_to_website&auth_type=rerequest&scope=email"));
    webbrowser.webView->setPage(page);
    webDialog->show();
}

void MainWindow::on_GotData()
{
    webDialog->hide();
}
