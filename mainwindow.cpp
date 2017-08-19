#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMessage("It was a dark and stormy night");
    setButton("continue");
}

//sets random message & buttons
void MainWindow::getNextPage(){
    //get random number, decide environment screen, battle, or item
    //for battle:
    //get random number for monster
    //create monster from Monster class
    //create instance of fight, passing in Monster
}

void MainWindow::setMessage(std::string message){
    ui->message->setText(QString::fromStdString(message));
}

void MainWindow::setButton(std::string label){
    QPushButton *newButton = new QPushButton;
    newButton->setText(QString::fromStdString(label));
    ui->buttonSpace->addWidget(newButton);
    connect(newButton, &QPushButton::clicked, [=](){ this->getNextPage(); });
}

void MainWindow::clearButtons(){
    if(!ui->buttonSpace){
        return;
    }
    while(auto item = ui->buttonSpace->takeAt(0)){
        delete item->widget();
        //clearWidgets(item->layout());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
