#include "Window.h"

Window::Window()
{
    setFixedSize(400, 300);
    QSize iconSize(70, 70);
    circle = new QIcon("rond.png");
    cross = new QIcon("croix.png");

    QLine northHorLine(10, 102, 288, 102);
    QLine southHorLine(10, 196, 288, 196);
    QLine westVertLine(102, 10, 102, 288);
    QLine eastVertLine(196, 10, 196, 288);
    scene = new QGraphicsScene();
        QPen pen(Qt::black, 3, Qt::SolidLine);
        scene->addLine(northHorLine, pen);
        scene->addLine(southHorLine, pen);
        scene->addLine(westVertLine, pen);
        scene->addLine(eastVertLine, pen);
    sceneView = new QGraphicsView(scene, this);
    sceneView->move(7, 7);

    a1 = new QPushButton(this);
        a1->move(10, 10);
        a1->setFixedSize(90, 90);
        a1->setFlat(true);
        a1->setIconSize(iconSize);
    a2 = new QPushButton(this);
        a2->move(104,10);
        a2->setFixedSize(90, 90);
        a2->setFlat(true);
        a2->setIconSize(iconSize);
    a3 = new QPushButton(this);
        a3->move(198, 10);
        a3->setFixedSize(90, 90);
        a3->setFlat(true);
        a3->setIconSize(iconSize);
    b1 = new QPushButton(this);
        b1->move(10, 104);
        b1->setFixedSize(90, 90);
        b1->setFlat(true);
        b1->setIconSize(iconSize);
    b2 = new QPushButton(this);
        b2->move(104, 104);
        b2->setFixedSize(90, 90);
        b2->setFlat(true);
        b2->setIconSize(iconSize);
    b3 = new QPushButton(this);
        b3->move(198, 104);
        b3->setFixedSize(90, 90);
        b3->setFlat(true);
        b3->setIconSize(iconSize);
    c1 = new QPushButton(this);
        c1->move(10, 198);
        c1->setFixedSize(90, 90);
        c1->setFlat(true);
        c1->setIconSize(iconSize);
    c2 = new QPushButton(this);
        c2->move(104, 198);
        c2->setFixedSize(90, 90);
        c2->setFlat(true);
        c2->setIconSize(iconSize);
    c3 = new QPushButton(this);
        c3->move(198, 198);
        c3->setFixedSize(90, 90);
        c3->setFlat(true);
        c3->setIconSize(iconSize);
        QObject::connect(a1, SIGNAL(clicked()), this, SLOT(a1Click()));
        QObject::connect(a2, SIGNAL(clicked()), this, SLOT(a2Click()));
        QObject::connect(a3, SIGNAL(clicked()), this, SLOT(a3Click()));
        QObject::connect(b1, SIGNAL(clicked()), this, SLOT(b1Click()));
        QObject::connect(b2, SIGNAL(clicked()), this, SLOT(b2Click()));
        QObject::connect(b3, SIGNAL(clicked()), this, SLOT(b3Click()));
        QObject::connect(c1, SIGNAL(clicked()), this, SLOT(c1Click()));
        QObject::connect(c2, SIGNAL(clicked()), this, SLOT(c2Click()));
        QObject::connect(c3, SIGNAL(clicked()), this, SLOT(c3Click()));




    QPushButton *newGame = new QPushButton("Nouvelle\nPartie", this);
        newGame->move(310, 200);
        newGame->setFixedSize(80, 80);
        QObject::connect(newGame, SIGNAL(clicked()), this, SLOT(newGame()));
    QLabel *playerTitle = new QLabel("Au tour de :", this);
        playerTitle->move(310, 10);
        playerTitle->setFixedSize(80, 40);
    playerOne = new QLabel("Joueur 1", this);
        playerOne->move(310, 60);
        playerOne->setFixedSize(80, 40);
        playerOne->setEnabled(false);
    playerTwo = new QLabel("Joueur 2", this);
        playerTwo->move(310, 110);
        playerTwo->setFixedSize(80, 40);
        playerTwo->setEnabled(false);

    Window::newGame();


}



void Window::a1Click()
{
    if(!a1Played)
    {
        if(mPlayer == 1)
        {
            a1->setIcon(*circle);
            playTab[0][0] = 1;
            mPlayer = 2;
            playerOne->setEnabled(false);
            playerTwo->setEnabled(true);
            a1Played = true;
        }
        else if (mPlayer == 2)
        {
            a1->setIcon(*cross);
            playTab[0][0] = 2;
            mPlayer = 1;
            playerOne->setEnabled(true);
            playerTwo->setEnabled(false);
            a1Played = true;
        }
    }
    else if (a1Played)
        QMessageBox::information(this, "Message d'erreur", "Cette case a déjà été jouée");

    checkVictory();
}

void Window::a2Click()
{
    if(!a2Played)
    {
        if(mPlayer == 1)
        {
            a2->setIcon(*circle);
            playTab[0][1] = 1;
            mPlayer = 2;
            playerOne->setEnabled(false);
            playerTwo->setEnabled(true);
            a2Played = true;
        }
        else if (mPlayer == 2)
        {
            a2->setIcon(*cross);
            playTab[0][1] = 2;
            mPlayer = 1;
            playerOne->setEnabled(true);
            playerTwo->setEnabled(false);
            a2Played = true;
        }
    }
    else if (a2Played)
        QMessageBox::information(this, "Message d'erreur", "Cette case a déjà été jouée");

    checkVictory();
}

void Window::a3Click()
{
    if(!a3Played)
    {
        if(mPlayer == 1)
        {
            a3->setIcon(*circle);
            playTab[0][2] = 1;
            mPlayer = 2;
            playerOne->setEnabled(false);
            playerTwo->setEnabled(true);
            a3Played = true;
        }
        else if (mPlayer == 2)
        {
            a3->setIcon(*cross);
            playTab[0][2] = 2;
            mPlayer = 1;
            playerOne->setEnabled(true);
            playerTwo->setEnabled(false);
            a3Played = true;
        }
    }
    else if (a3Played)
        QMessageBox::information(this, "Message d'erreur", "Cette case a déjà été jouée");

    checkVictory();
}

void Window::b1Click()
{
    if(!b1Played)
    {
        if(mPlayer == 1)
        {
            b1->setIcon(*circle);
            playTab[1][0] = 1;
            mPlayer = 2;
            playerOne->setEnabled(false);
            playerTwo->setEnabled(true);
            b1Played = true;
        }
        else if (mPlayer == 2)
        {
            b1->setIcon(*cross);
            playTab[1][0] = 2;
            mPlayer = 1;
            playerOne->setEnabled(true);
            playerTwo->setEnabled(false);
            b1Played = true;
        }
    }
    else if (b1Played)
        QMessageBox::information(this, "Message d'erreur", "Cette case a déjà été jouée");

    checkVictory();
}

void Window::b2Click()
{
    if(!b2Played)
    {
        if(mPlayer == 1)
        {
            b2->setIcon(*circle);
            playTab[1][1] = 1;
            mPlayer = 2;
            playerOne->setEnabled(false);
            playerTwo->setEnabled(true);
            b2Played = true;
        }
        else if (mPlayer == 2)
        {
            b2->setIcon(*cross);
            playTab[1][1] = 2;
            mPlayer = 1;
            playerOne->setEnabled(true);
            playerTwo->setEnabled(false);
            b2Played = true;
        }
    }
    else if (b2Played)
        QMessageBox::information(this, "Message d'erreur", "Cette case a déjà été jouée");

    checkVictory();
}

void Window::b3Click()
{
    if(!b3Played)
    {
        if(mPlayer == 1)
        {
            b3->setIcon(*circle);
            playTab[1][2] = 1;
            mPlayer = 2;
            playerOne->setEnabled(false);
            playerTwo->setEnabled(true);
            b3Played = true;
        }
        else if (mPlayer == 2)
        {
            b3->setIcon(*cross);
            playTab[1][2] = 2;
            mPlayer = 1;
            playerOne->setEnabled(true);
            playerTwo->setEnabled(false);
            b3Played = true;
        }
    }
    else if (b3Played)
        QMessageBox::information(this, "Message d'erreur", "Cette case a déjà été jouée");

    checkVictory();
}

void Window::c1Click()
{
    if(!c1Played)
    {
        if(mPlayer == 1)
        {
            c1->setIcon(*circle);
            playTab[2][0] = 1;
            mPlayer = 2;
            playerOne->setEnabled(false);
            playerTwo->setEnabled(true);
            c1Played = true;
        }
        else if (mPlayer == 2)
        {
            c1->setIcon(*cross);
            playTab[2][0] = 2;
            mPlayer = 1;
            playerOne->setEnabled(true);
            playerTwo->setEnabled(false);
            c1Played = true;
        }
    }
    else if (c1Played)
        QMessageBox::information(this, "Message d'erreur", "Cette case a déjà été jouée");

    checkVictory();
}

void Window::c2Click()
{
    if(!c2Played)
    {
        if(mPlayer == 1)
        {
            c2->setIcon(*circle);
            playTab[2][1] = 1;
            mPlayer = 2;
            playerOne->setEnabled(false);
            playerTwo->setEnabled(true);
            c2Played = true;
        }
        else if (mPlayer == 2)
        {
            c2->setIcon(*cross);
            playTab[2][1] = 2;
            mPlayer = 1;
            playerOne->setEnabled(true);
            playerTwo->setEnabled(false);
            c2Played = true;
        }
    }
    else if (c2Played)
        QMessageBox::information(this, "Message d'erreur", "Cette case a déjà été jouée");

    checkVictory();
}

void Window::c3Click()
{
    if(!c3Played)
    {
        if(mPlayer == 1)
        {
            c3->setIcon(*circle);
            playTab[2][2] = 1;
            mPlayer = 2;
            playerOne->setEnabled(false);
            playerTwo->setEnabled(true);
            c3Played = true;
        }
        else if (mPlayer == 2)
        {
            c3->setIcon(*cross);
            playTab[2][2] = 2;
            mPlayer = 1;
            playerOne->setEnabled(true);
            playerTwo->setEnabled(false);
            c3Played = true;
        }
    }
    else if (c3Played)
        QMessageBox::information(this, "Message d'erreur", "Cette case a déjà été jouée");

    checkVictory();
}

void Window::newGame()
{
    playerOne->setEnabled(true);
    playerTwo->setEnabled(false);
    mPlayer = 1;
    QIcon vide("");
    a1->setIcon(vide);
    a2->setIcon(vide);
    a3->setIcon(vide);
    b1->setIcon(vide);
    b2->setIcon(vide);
    b3->setIcon(vide);
    c1->setIcon(vide);
    c2->setIcon(vide);
    c3->setIcon(vide);

    a1Played = false;
    a2Played = false;
    a3Played = false;
    b1Played = false;
    b2Played = false;
    b3Played = false;
    c1Played = false;
    c2Played = false;
    c3Played = false;


    for(int i= 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            playTab[i][j] = 0;
        }
    }

    a1->setEnabled(true);
    a2->setEnabled(true);
    a3->setEnabled(true);
    b1->setEnabled(true);
    b2->setEnabled(true);
    b3->setEnabled(true);
    c1->setEnabled(true);
    c2->setEnabled(true);
    c3->setEnabled(true);

}

void Window::checkVictory()
{
    //Première ligne horizontale complétée ([0, 0], [0, 1], [0, 2])
    if(playTab[0][0] == 1 && playTab[0][1] == 1 && playTab[0][2] == 1)
        playerOneVictory();
    else if(playTab[0][0] == 2 && playTab[0][1] == 2 && playTab[0][2] == 2)
        playerTwoVictory();
    //Deuxième ligne horizontale complétée ([1, 0], [1, 1], [1, 2])
    else if(playTab[1][0] == 1 && playTab[1][1] == 1 && playTab[1][2] == 1)
        playerOneVictory();
    else if(playTab[1][0] == 2 && playTab[1][1] == 2 && playTab[1][2] == 2)
        playerTwoVictory();
    //Troisième ligne horizontale complétée ([2, 0], [2, 1], [2, 2])
    else if(playTab[2][0] == 1 && playTab[2][1] == 1 && playTab[2][2] == 1)
        playerOneVictory();
    else if(playTab[2][0] == 2 && playTab[2][1] == 2 && playTab[2][2] == 2)
        playerTwoVictory();
    //Première ligne verticale complétée ([0, 0], [1, 0], [2, 0])
    else if(playTab[0][0] == 1 && playTab[1][0] == 1 && playTab[2][0] == 1)
        playerOneVictory();
    else if(playTab[0][0] == 2 && playTab[1][0] == 2 && playTab[2][0] == 2)
        playerTwoVictory();
    //Deuxième ligne verticale complétée ([0, 1], [1, 1], [2, 1])
    else if(playTab[0][1] == 1 && playTab[1][1] == 1 && playTab[2][1] == 1)
        playerOneVictory();
    else if(playTab[0][1] == 2 && playTab[1][1] == 2 && playTab[2][1] == 2)
        playerTwoVictory();
    //Troisième ligne verticale complétée ([0, 2], [1, 2], [2, 2])
    else if(playTab[0][2] == 1 && playTab[1][2] == 1 && playTab[2][2] == 1)
        playerOneVictory();
    else if(playTab[0][2] == 2 && playTab[1][2] == 2 && playTab[2][2] == 2)
        playerTwoVictory();
    //Première ligne croisée complétée ([0, 0], [1, 1], [2, 2])
    else if(playTab[0][0] == 1 && playTab[1][1] == 1 && playTab[2][2] == 1)
        playerOneVictory();
    else if(playTab[0][0] == 2 && playTab[1][2] == 2 && playTab[2][2] == 2)
        playerTwoVictory();
    //Deuxième ligne croisée complétée ([2, 0], [1, 1], [0, 2])
    else if(playTab[2][0] == 1 && playTab[1][1] == 1 && playTab[0][2] == 1)
        playerOneVictory();
    else if(playTab[2][0] == 2 && playTab[1][1] == 2 && playTab[0][2] == 2)
        playerTwoVictory();

    //Match nul : toute les case sont égales à 1 ou 2 (soit != 0)mais aucune condition de victoire n'est réunie
    else if(playTab[0][0] != 0 && playTab[0][1] != 0 && playTab[0][2] != 0 && playTab[1][0] != 0 && playTab[1][1] != 0 && playTab[1][2] != 0 && playTab[2][0] != 0 && playTab[2][1] != 0 && playTab[2][2] != 0)
        mate();
}

void Window::playerOneVictory()
{
    QMessageBox::information(this, "Résultat du jeu", "Victoire du joueur 1");
    a1->setEnabled(false);
    a2->setEnabled(false);
    a3->setEnabled(false);
    b1->setEnabled(false);
    b2->setEnabled(false);
    b3->setEnabled(false);
    c1->setEnabled(false);
    c2->setEnabled(false);
    c3->setEnabled(false);

}

void Window::playerTwoVictory()
{
    QMessageBox::information(this, "Résultat du jeu", "Victoire du joueur 2");
    a1->setEnabled(false);
    a2->setEnabled(false);
    a3->setEnabled(false);
    b1->setEnabled(false);
    b2->setEnabled(false);
    b3->setEnabled(false);
    c1->setEnabled(false);
    c2->setEnabled(false);
    c3->setEnabled(false);
}

void Window::mate()
{
    QMessageBox::information(this, "Résultat du jeu", "Match nul");
    a1->setEnabled(false);
    a2->setEnabled(false);
    a3->setEnabled(false);
    b1->setEnabled(false);
    b2->setEnabled(false);
    b3->setEnabled(false);
    c1->setEnabled(false);
    c2->setEnabled(false);
    c3->setEnabled(false);
}
