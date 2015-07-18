#ifndef WINDOW
#define WINDOW

#include <QApplication>
#include <QtWidgets>
#include <QIcon>
#include <QMap>

class Window: public QWidget
{
    Q_OBJECT

public:
    Window();

    void checkVictory();
    void playerOneVictory();
    void playerTwoVictory();
    void mate();


private slots:
    void a1Click();
    void a2Click();
    void a3Click();
    void b1Click();
    void b2Click();
    void b3Click();
    void c1Click();
    void c2Click();
    void c3Click();
    void newGame();

private:
    int playTab[3][3];
    bool a1Played;
    bool a2Played;
    bool a3Played;
    bool b1Played;
    bool b2Played;
    bool b3Played;
    bool c1Played;
    bool c2Played;
    bool c3Played;
    int mPlayer;
    QGraphicsScene *scene;
    QGraphicsView *sceneView;
    QLabel *playerOne;
    QLabel *playerTwo;
    QPushButton *a1;
    QPushButton *a2;
    QPushButton *a3;
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;
    QPushButton *c1;
    QPushButton *c2;
    QPushButton *c3;
    QIcon *circle;
    QIcon *cross;


};


#endif // WINDOW

