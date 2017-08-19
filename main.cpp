#include "mainwindow.h"
#include <QApplication>

#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    std::string monsters [] = {"behir", "seawolf", "wereshark", "deadly pudding", "planetar", "cat lord", "cloaker", "basidirond",
                               "carnivorous flying squirrel", "the KARNS beaver", "hippocampus", "demagorgon", "literally a five-headed dragon",

                               "space dragon"};
    std::string encounters [] = {"acorns", "kale smoothie", "minor healing", "mountain dew", "malkshake", "melkshake", "MILKSHAKE",
                                 "medium healing", "major healing",
                                 "gelatinous cube", "faerie dragon", "quadrone", "planetar", "moon dog", "dolphin"};
    std::string weapons [] = {"blaster", "laser bow", "laser sword", "crappy spaceship", "ultra super hyper legendary spaceship of doom"};

    std::string modifiers [] = {"big", "mega", "ultra", "ultra mega", "legendary", "hyperlegendary", "ultra super hyper legendary"};

    return a.exec();
}
