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
//  Procedure permettant de saisir un caractère
//
//  Entrée : le caractères moncarac contient le caractère a saisir
//           la chaine de caractère text contient le message accompagnant la saisie
//
//  Sortie : caractère saisie
// 
///////////////////////////////////////////////////////////////////////////////

void SaisieCarac(char& moncarac, string text);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant de saisir une chaine de caractères
//
//  Entrée : la chaine de caractères machaine contient la chaine a saisir
//           la chaine de caractère text contient le message accompagnant la saisie
//
//  Sortie : chaine de caractères saisie
// 
///////////////////////////////////////////////////////////////////////////////

void SaisieChaine(string& machaine, string text);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant de saisir un entier
//
//  Entrée : l'entier entier contient l'entier a saisir
//           la chaine de caractère text contient le message accompagnant la saisie
//
//  Sortie : entier saisi
// 
///////////////////////////////////////////////////////////////////////////////

void SaisieEntier(int& entier, string text);

///////////////////////////////////////////////////////////////////////////////
//
//  Procedure permettant de netoyer le cache du cin afin d'eviter que la saisie
//      d'un caractère dans un champ de saisie d'un entier soit un problème
//
///////////////////////////////////////////////////////////////////////////////

void Clearcin();

///////////////////////////////////////////////////////////////////////////////
//
//  Fonction permettant de contrôler un entier de plusieurs facons
//
//  Entrée : controle_type permet de selectionner le controle
//           l'entier nombre contient le nombre a controler
//           les entier bornmin et bornmax sont les bornes du controle
//
//  Sortie : un booléen contenant la valeur 'true' si le controle est valide
//                                          'false' si le controle n'est pas valide
// 
///////////////////////////////////////////////////////////////////////////////

bool Controle(char controle_type, int& nombre, int bornemin, int bornemax);

///////////////////////////////////////////////////////////////////////////////
// 
//  Fonction permettant de transformer les entiers jour, mois et annee
//      en chaine de caractères
//
//  Entrée : jour est un entier compris entre 1 et 31
//           mois est un entier compris entre 1 et 12
//           annee est un entier strictement positif
//
//  Sortie : une chaine de caractères contienant une date 
//              sous la forme JJ/MM/AAAA
// 
///////////////////////////////////////////////////////////////////////////////

bool ControleDate(int jour1, int mois1, int annee1, int jour2, int mois2, int annee2);

///////////////////////////////////////////////////////////////////////////////
//
//  Fonction permettant de contrôler si la date saisie est valide
//      en prennant en compte les années bissextiles en utilisant des booléens
//
//  Entrée : jour est un entier compris entre 1 et 31
//           mois est un entier compris entre 1 et 12
//           annee est un entier strictement positif
//
//  Sortie : un booléen contenant la valeur 'true' si la date est valide
//                                          'false' si la date n'est pas valide
// 
///////////////////////////////////////////////////////////////////////////////

bool DateValide(int jour, int mois, int annee);

bool RechercheExp(string cible, string motif);

string DateToString(char sep, int jour, int mois, int annee);

string Majuscule(string chaine);

string Minuscule(string chaine);

#endif // !TOOLS_H