/*
Auteur : mourad
Date de création : ven. juil. 25 2008

Rôle :
c'est la classe qui gere notre bloc note, fichier ".cpp";
*/


#include "MNotePad.h"

MNotePad::MNotePad()
{
    creerAction();
    creerMenu();
    creerToolBar();

    //la zone centrale
    zoneCentrale = new QMdiArea;
    nouveauTab();
    nouveauTab();
    nouveauTab();
    //connect(zoneCentrale,SIGNAL(subWindowActivated(QMdiSubWindow)),this,SLOT(changerTab(QMdiSubWindow)));
    //zoneCentrale->setViewMode(QMdiArea::TabbedView);

    setCentralWidget(zoneCentrale);
}

    //les actions
void MNotePad::creerAction()
{
    a_nouveauTab = new QAction(QIcon("images/nouveau.png"),tr("nouveau"),this);
    a_nouveauTab->setShortcut(tr("Ctrl+N"));
    connect(a_nouveauTab,SIGNAL(triggered()),this,SLOT(nouveauTab()));
    a_ouvrirTab = new QAction(QIcon("images/ouvrir.png"),tr("ouvrir"),this);
    a_ouvrirTab->setShortcut(tr("Ctrl+O"));
    connect(a_ouvrirTab,SIGNAL(triggered()),this,SLOT(ouvrirTab()));
    a_saveTab = new QAction(QIcon("images/save.png"),tr("save"),this);
    a_saveTab->setShortcut(tr("Ctrl+S"));
    connect(a_saveTab,SIGNAL(triggered()),this,SLOT(saveTab()));
    a_fermerTab = new QAction(tr("fermer"),this);
    a_fermerTab->setShortcut(tr("Ctrl+W"));
    connect(a_fermerTab,SIGNAL(triggered()),this,SLOT(fermerTab()));
    a_quitter = new QAction(QIcon("images/quitter.png"),tr("quitter"),this);
    a_quitter->setShortcut(tr("Ctrl+Q"));
    connect(a_quitter,SIGNAL(triggered()),qApp,SLOT(quit()));

    a_precedent = new QAction(QIcon("images/precedent.png"),tr("precedent"),this);
    a_precedent->setShortcut(tr("Ctrl+Z"));
    connect(a_precedent,SIGNAL(triggered()),this,SLOT(precedent()));
    a_suivant = new QAction(QIcon("images/suivant.png"),tr("suivant"),this);
    a_suivant->setShortcut(tr("Ctrl+F"));
    connect(a_suivant,SIGNAL(triggered()),this,SLOT(suivant()));
    a_font = new QAction(QIcon("images/font.png"),tr("font"),this);
    connect(a_font,SIGNAL(triggered()),this,SLOT(font()));

    a_apropos = new QAction(QIcon("images/apropos.png"),tr("A propos"),this);
    connect(a_apropos,SIGNAL(triggered()),this,SLOT(apropos()));
    a_aproposQt = new QAction(QIcon("images/aproposQt.png"),tr("A propos de Qt"),this);
    connect(a_aproposQt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    }

    //le menu
void MNotePad::creerMenu()
{
    QMenu* m_fichier = menuBar()->addMenu(tr("&fichier"));
    m_fichier->addAction(a_nouveauTab);
    m_fichier->addAction(a_ouvrirTab);
    m_fichier->addAction(a_saveTab);
    m_fichier->addAction(a_fermerTab);
    m_fichier->addAction(a_quitter);

    QMenu* m_edit = menuBar()->addMenu(tr("&edit"));
    m_edit->addAction(a_precedent);
    m_edit->addAction(a_suivant);

    QMenu* m_format=menuBar()->addMenu(tr("fo&rmat"));
    m_format->addAction(a_font);

    QMenu* m_aide = menuBar()->addMenu(tr("&?"));
    m_aide->addAction(a_apropos);
    m_aide->addAction(a_aproposQt);
    }
    //la barre d'outil
void MNotePad::creerToolBar()
{
    QToolBar* tb_fichier = addToolBar(tr("barre d'outil"));
    tb_fichier->addAction(a_nouveauTab);
    tb_fichier->addSeparator();
    tb_fichier->addAction(a_ouvrirTab);
    tb_fichier->addSeparator();
    tb_fichier->addAction(a_saveTab);
    tb_fichier->addSeparator();
    tb_fichier->addAction(a_precedent);
    tb_fichier->addAction(a_suivant);
    }

   //les slots
void MNotePad::nouveauTab()
{
    QTextEdit *zoneTexte = new QTextEdit;
    QMdiSubWindow *ssFenetre = zoneCentrale->addSubWindow(zoneTexte);
    zoneCentrale->setActiveSubWindow(ssFenetre);
    }
void MNotePad::ouvrirTab()
{
    QString fichier = QFileDialog::getOpenFileName(this,"ouvir un fichier",QString());
    QFile file(fichier);
    if (!file.open(QIODevice::Text))
         return;
         QTextStream in(&file);
        QString str = in.readAll();
    pageActuelle()->setText(str);
    }
void MNotePad::saveTab()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "texte (*.txt)");

    }
void MNotePad::precedent()
{
    pageActuelle()->undo();
    }
void MNotePad::suivant()
{
    pageActuelle()->redo();
    }
void MNotePad::font()
{
    }
void MNotePad::fermerTab()
{
    zoneCentrale->closeActiveSubWindow();
}
void MNotePad::apropos()
{
    QMessageBox::information(this,tr("a propos"),tr("Ce projet est realiser par <strong>mourad mourafiq</strong> dans le but de bien maitriser la bibliotheque Qt.<br/>pour plus d'information veuillez voir a propos de Qt"));
    }
void MNotePad::changerTab(QMdiSubWindow* window)
{
    window = zoneCentrale->activeSubWindow ();
    zoneCentrale->setActiveSubWindow(window);
    }
    //autres fonctions
QTextEdit *MNotePad::pageActuelle()
{
    return zoneCentrale->activeSubWindow()->findChild<QTextEdit *>();
    }
