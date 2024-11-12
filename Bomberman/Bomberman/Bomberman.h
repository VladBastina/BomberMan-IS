#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Bomberman.h"

class Bomberman : public QMainWindow
{
    Q_OBJECT

public:
    Bomberman(QWidget *parent = nullptr);
    ~Bomberman();

private:
    Ui::BombermanClass ui;
};
