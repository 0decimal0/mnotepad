/*
Auteur : mourad
Date de création : ven. juil. 25 2008

Rôle :
c'est la classe qui gere notre bloc note, fichier ".h".
*/


#ifndef DEF_MNOTEPAD
#define DEF_MNOTEPAD
#include <QtGui>

class MNotePad : public QMainWindow
{
    Q_OBJECT

public :
    MNotePad();
    void creerAction();
    void creerMenu();
    void creerToolBar();
    //QTextEdit* creerTab(QString nomFichier);
    QTextEdit *pageActuelle();



public slots:
    void nouveauTab();
    void ouvrirTab();
    void saveTab();
    void precedent();
    void suivant();
    void font();
    void apropos();
    void fermerTab();
    void changerTab(QMdiSubWindow* window);

protected :


private :
    QMdiArea *zoneCentrale;
    //QMdiSubWindow* onglet;

    QAction* a_nouveauTab;
    QAction* a_ouvrirTab;
    QAction* a_saveTab;
    QAction* a_fermerTab;
    QAction* a_quitter;
    QAction* a_precedent;
    QAction* a_suivant;
    QAction* a_font;
    QAction* a_apropos;
    QAction* a_aproposQt;
};
#endif
