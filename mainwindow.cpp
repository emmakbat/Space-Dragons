#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "environments.h"
#include "fightwindow.h"

#include <QPushButton>
#include <cstdlib>
#include <ctime>

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
    clearButtons();

    srand(time(NULL));
    int event = rand() % 11;

    if(event <  9){
        int id = rand() % 22;
        spaceDragons::Environments environment(id);
        setMessage(environment.getMessage());
        setButton("go left");
        setButton("go right");
    }
    else{
        int id = rand() % 17;
        FightWindow* fightWindow = new FightWindow;
        fightWindow->show();
    }
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
