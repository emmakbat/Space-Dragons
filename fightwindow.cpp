#include "fightwindow.h"
#include "ui_fightwindow.h"
#include "fight.h"
#include "monster.h"
#include "player.h"
#include <string>

#include <iostream>

FightWindow::FightWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightWindow)
{
    ui->setupUi(this);
    ui->messageBox->setText("The fight begins!");

    connect(ui->attackButton, &QPushButton::clicked, [=](){ this->fightRound("attack"); });
    connect(ui->specialButton, &QPushButton::clicked, [=](){ this->fightRound("special"); });
    connect(ui->defendButton, &QPushButton::clicked, [=](){ this->fightRound("defend"); });
    connect(ui->waitButton, &QPushButton::clicked, [=](){ this->fightRound("wait"); });
    connect(ui->okButton, &QPushButton::clicked, [=](){ this->continueFight(); });

}

void FightWindow::fightRound(std::string action){
    std::string message = fight.doFight("player", action);
    ui->messageBox->setText(QString::fromStdString(message));
    ui->attackButton->setEnabled(false);
    ui->specialButton->setEnabled(false);
    ui->defendButton->setEnabled(false);
    ui->waitButton->setEnabled(false);
    ui->okButton->setEnabled(true);
}

void FightWindow::continueFight(){
    std::string message = fight.doFight("monster", "");
    ui->messageBox->setText(QString::fromStdString(message));

    ui->attackButton->setEnabled(true);
    ui->specialButton->setEnabled(true);
    ui->defendButton->setEnabled(true);
    ui->waitButton->setEnabled(true);
    ui->okButton->setEnabled(false);
}

FightWindow::~FightWindow()
{
    delete ui;
}
