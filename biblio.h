#pragma once

#ifndef BIBLIO_H
#define BIBLIO_H 

#include "tools.h"

const int MAX_LIVRE = 512;
const int MAX_AUTEUR = 64;
const int MAX = 128;

struct t_date {
    int jour;
    int mois;
    int annee;
};

struct t_livre {
    string titre;
    int auteur;
    t_date date;
    int page;
};

struct t_auteur {
    string nom;
    string prenom;
    string nationalite;
    t_date nais;
    t_date mort;
    int id_auteur;
    int nblivres;
};

struct t_error {
    int noerr;
    string mesg;
};

struct t_mesg {
    int nomesg;
    string mesg;
};

struct t_choix {
    int nochoix;
    char choix;
};

struct t_menu {
    int nomenu;
    int size;
    string menu[MAX];
};

struct t_lang {
    int nberr;
    t_error erreur[MAX];
    int nbmesg;
    t_mesg mesg[MAX];
    int nbmenu;
    t_menu menu[MAX];
    int nbchoix;
    t_choix choix[MAX];
};

struct t_biblio{
    int nblivre;
    t_livre tablivre[MAX_LIVRE];
    int nbauteur;
    t_auteur tabauteur[MAX_AUTEUR];
    int id;
    t_lang lang;
    int nolang;
};

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant d'afficher un livre de la bibliothèque
//
//  Entrée : la bibliothèque contenant les livres
//           le numero du livre a afficher
//
//  Sortie : affichage du livre numero nolivre
//
///////////////////////////////////////////////////////////////////////////////

void AfficheAuteur(t_biblio& biblio, int& nolivre);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant d'afficher tous les livres de la bibliothèque
//
//  Entrée : la bibliothèque contenant les livres
//
//  Sortie : liste de tous les livres
//
///////////////////////////////////////////////////////////////////////////////

void AfficheAuteurs(t_biblio& biblio);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant d'ajouter un livre a la bibliothèque si il n'en existe pas
//      deja un du meme titre
//
//  Entrée : la bibliothèque contenant les livres
//
//  Sortie : rien
//
///////////////////////////////////////////////////////////////////////////////

void AjoutAuteur(t_biblio& biblio);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant d'afficher un livre de la bibliothèque
//
//  Entrée : la bibliothèque contenant les livres
//           le numero du livre a afficher
//
//  Sortie : affichage du livre numero nolivre
//
///////////////////////////////////////////////////////////////////////////////

void AfficheLivre(t_biblio& biblio, int& nolivre);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant d'afficher tous les livres de la bibliothèque
//
//  Entrée : la bibliothèque contenant les livres
//
//  Sortie : liste de tous les livres
//
///////////////////////////////////////////////////////////////////////////////

void AfficheLivres(t_biblio& biblio);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant d'ajouter un livre a la bibliothèque si il n'en existe pas
//      deja un du meme titre
//
//  Entrée : la bibliothèque contenant les livres
//
//  Sortie : rien
//
///////////////////////////////////////////////////////////////////////////////

void AjoutLivre(t_biblio& biblio);

void CloseFile(t_biblio& biblio);

void Langinit(t_biblio& biblio, int choix);

void Menu(string menu, int& choix, t_biblio& biblio);

void MesgError(int noerr, t_biblio& biblio);

void MesgNonValid(int nomesg, t_biblio& biblio);

void MesgValid(int nomesg, t_biblio& biblio);

void ModifAuteur(t_biblio& biblio, int& nolivre);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant de modifier un livre dans la bibliothèque
//
//  Entrée : la bibliothèque contenant les livres
//
//  Sortie : rien
//
///////////////////////////////////////////////////////////////////////////////

void ModifLivre(t_biblio& biblio, int& nolivre);

void OpenFile(t_biblio& biblio);

void Pause(t_biblio& biblio);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant de saisir une date de type t_date (jj mm aaaa)
//
//  Entrée : une date de type t_date
//
//  Sortie : une date de type t_date controlée
//
///////////////////////////////////////////////////////////////////////////////

void SaisirDate(t_date& date, t_biblio& biblio);

void SupprimeAuteur(t_biblio& biblio);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant de supprimer un livre dans la bibliothèque
//
//  Entrée : la bibliothèque contenant les livres
//
//  Sortie : rien
//
///////////////////////////////////////////////////////////////////////////////

void SupprimeLivre(t_biblio& biblio);

///////////////////////////////////////////////////////////////////////////////
//
//  Fonction permettant de rechercher si un livre existe dans la bibliothèque
//
//  Entrée : la bibliothèque contenant les livres
//           le titre du livre a verifier
//
//  Sortie : booleen contenant true si le livre existe
//                              false si le livre n'existe pas
//
///////////////////////////////////////////////////////////////////////////////

bool LivreExisteDeja(t_biblio& biblio, string titre, int auteur);

int AfficheAuteurRecherche(t_biblio& biblio, int type);

int AfficheLivreRecherche(t_biblio& biblio, int type);

int RechercheAuteur(t_biblio& biblio);

///////////////////////////////////////////////////////////////////////////////
//
//  fonction permettant de rechercher un livre dans la bibliothèque
//
//  Entrée : la bibliothèque contenant les livres
//
//  Sortie : le numero du livre recherché si il existe
//
///////////////////////////////////////////////////////////////////////////////

int RechercheLivre(t_biblio& biblio);

char AffChoix(int nochoix, t_biblio& biblio);

string AffErr(int noerr, t_biblio& biblio);

string AffMenu(int nomenu, t_biblio& biblio);

string AffMesg(int nomesg, t_biblio& biblio);

string MesgSaisie(int nomesg, t_biblio& biblio);

#endif // !BIBLIO_H