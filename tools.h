#pragma once

#ifndef TOOLS_H
#define TOOLS_H

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <windows.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant de saisir un caract�re
//
//  Entr�e : le caract�res moncarac contient le caract�re a saisir
//           la chaine de caract�re text contient le message accompagnant la saisie
//
//  Sortie : caract�re saisie
// 
///////////////////////////////////////////////////////////////////////////////

void SaisieCarac(char& moncarac, string text);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant de saisir une chaine de caract�res
//
//  Entr�e : la chaine de caract�res machaine contient la chaine a saisir
//           la chaine de caract�re text contient le message accompagnant la saisie
//
//  Sortie : chaine de caract�res saisie
// 
///////////////////////////////////////////////////////////////////////////////

void SaisieChaine(string& machaine, string text);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant de saisir un entier
//
//  Entr�e : l'entier entier contient l'entier a saisir
//           la chaine de caract�re text contient le message accompagnant la saisie
//
//  Sortie : entier saisi
// 
///////////////////////////////////////////////////////////////////////////////

void SaisieEntier(int& entier, string text);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant de netoyer le cache du cin afin d'eviter que la saisie
//      d'un caract�re dans un champ de saisie d'un entier soit un probl�me
//
///////////////////////////////////////////////////////////////////////////////

void Clearcin();

///////////////////////////////////////////////////////////////////////////////
//
//  Fonction permettant de contr�ler un entier de plusieurs facons
//
//  Entr�e : controle_type permet de selectionner le controle
//           l'entier nombre contient le nombre a controler
//           les entier bornmin et bornmax sont les bornes du controle
//
//  Sortie : un bool�en contenant la valeur 'true' si le controle est valide
//                                          'false' si le controle n'est pas valide
// 
///////////////////////////////////////////////////////////////////////////////

bool Controle(char controle_type, int& nombre, int bornemin, int bornemax);

///////////////////////////////////////////////////////////////////////////////
// 
//  Fonction permettant de transformer les entiers jour, mois et annee
//      en chaine de caract�res
//
//  Entr�e : jour est un entier compris entre 1 et 31
//           mois est un entier compris entre 1 et 12
//           annee est un entier strictement positif
//
//  Sortie : une chaine de caract�res contienant une date 
//              sous la forme JJ/MM/AAAA
// 
///////////////////////////////////////////////////////////////////////////////

bool ControleDate(int jour1, int mois1, int annee1, int jour2, int mois2, int annee2);

///////////////////////////////////////////////////////////////////////////////
//
//  Fonction permettant de contr�ler si la date saisie est valide
//      en prennant en compte les ann�es bissextiles en utilisant des bool�ens
//
//  Entr�e : jour est un entier compris entre 1 et 31
//           mois est un entier compris entre 1 et 12
//           annee est un entier strictement positif
//
//  Sortie : un bool�en contenant la valeur 'true' si la date est valide
//                                          'false' si la date n'est pas valide
// 
///////////////////////////////////////////////////////////////////////////////

bool DateValide(int jour, int mois, int annee);

bool RechercheExp(string cible, string motif);

string DateToString(char sep, int jour, int mois, int annee);

string Majuscule(string chaine);

string Minuscule(string chaine);

#endif // !TOOLS_H