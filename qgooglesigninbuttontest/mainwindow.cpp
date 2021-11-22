#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgooglesigninbutton.h"

#include <QLayout>


class MainWindowData
{
public:
    QGoogleSignInButton *btn;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    D = new MainWindowData();


    D->btn = new QGoogleSignInButton(this);

    connect(D->btn, &QGoogleSignInButton::clicked, this, &MainWindow::quit);

    QLayout *l = ui->centralwidget->layout();

    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->addWidget(D->btn);
    hbox->addStretch();

    l->addItem(hbox);
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


void MainWindow::on_pbDisableEnable_clicked()
{
    D->btn->setEnabled(!D->btn->isEnabled());
}

