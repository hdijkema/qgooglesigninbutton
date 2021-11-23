#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgooglesigninbutton.h"

#include <QLayout>


class MainWindowData
{
public:
    QGoogleSignInButton *btn;
    int                 _times;
public:
    MainWindowData() : btn(nullptr), _times(0) { }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    D = new MainWindowData();
    D->btn = ui->pbGoogle;
    connect(D->btn, &QGoogleSignInButton::clicked, this, &MainWindow::clicked);
    D->btn->setInitial();

    ui->cbEnable->setChecked(true);
    connect(ui->pbQuit, &QPushButton::clicked, this, &MainWindow::quit);

    ui->lbClicked->setText("-");
    setWindowTitle(tr("Google Sign In Button Test app"));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete D;
}

void MainWindow::quit()
{
    close();
}


void MainWindow::on_cbLight_toggled(bool checked)
{
    D->btn->setLight(checked);
}

void MainWindow::on_cbEnable_toggled(bool checked)
{
    D->btn->setEnabled(checked);
}

void MainWindow::clicked()
{
    ui->lbClicked->setText(tr("Google Sign In button has been clicked %1 times").arg(++D->_times));
    if ((D->_times % 2) == 1) {
        D->btn->setAgain();
    } else {
        D->btn->setInitial();
    }
}

