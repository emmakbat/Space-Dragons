#ifndef FIGHTWINDOW_H
#define FIGHTWINDOW_H

#include <QWidget>

#include "monster.h"
#include "player.h"
#include "fight.h"

namespace Ui {
class FightWindow;
}

class FightWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FightWindow(QWidget *parent = 0);
    //void setMonster(spaceDragons::Monster nmonster){monster = nmonster;}
    //void setPlayer(spaceDragons::Player nplayer){player = nplayer;}
    //void fightInit(){fight = spaceDragons::Fight(monster, player);
    ~FightWindow();

private:
    Ui::FightWindow *ui;

    spaceDragons::Monster monster{0,0};
    spaceDragons::Player player;
    spaceDragons::Fight fight{monster, player};

private Q_SLOTS:
    void fightRound(std::string action);
    void continueFight();
};

#endif // FIGHTWINDOW_H
