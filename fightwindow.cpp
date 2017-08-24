#include "fightwindow.h"
#include "ui_fightwindow.h"
#include "fight.h"
#include "monster.h"
#include "player.h"

#include <QPixmap>
#include <string>

#include <iostream>

FightWindow::FightWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightWindow)
{
    ui->setupUi(this);
    ui->messageBox->setText("The fight begins!");

    QPixmap pic("C:\\Users\\emmab\\Documents\\Space-Dragons\\resources\\behir.jpg");
    ui->monsterDisplay->setScaledContents(true);
    ui->monsterDisplay->setPixmap(pic);

    connect(ui->attackButton, &QPushButton::clicked, [=](){ this->fightRound("attack"); });
    connect(ui->specialButton, &QPushButton::clicked, [=](){ this->fightRound("special"); });
    connect(ui->defendButton, &QPushButton::clicked, [=](){ this->fightRound("defend"); });
    connect(ui->waitButton, &QPushButton::clicked, [=](){ this->fightRound("wait"); });
    connect(ui->okButton, &QPushButton::clicked, [=](){ this->continueFight(); });
}

void FightWindow::fightRound(std::string action){
    ui->hpBar->setValue(fight.getHP());

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

    if(fight.monster.hp <= 0){
        ui->okButton->setText("Leave Battle");
        connect(ui->okButton, &QPushButton::clicked, [=](){ this->close(); });
    }
    else{
        ui->attackButton->setEnabled(true);
        ui->specialButton->setEnabled(true);
        ui->defendButton->setEnabled(true);
        ui->waitButton->setEnabled(true);
        ui->okButton->setEnabled(false);
    }
}

FightWindow::~FightWindow()
{
    delete ui;
}
