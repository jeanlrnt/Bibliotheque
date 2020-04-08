#include "tools.h"

void SaisieEntier(int& entier, string text) {
    cout << text;
    cin >> entier;
    Clearcin();
}

void SaisieChaine(string& machaine, string text) {
    cout << text;
    getline(cin, machaine);
    Clearcin();
}

void SaisieCarac(char& moncarac, string text) {
    cout << text;
    cin >> moncarac;
    Clearcin();
}

bool Controle(char controle_type, int& nombre, int bornemin, int bornemax) {
    bool controle_ok = false;

    switch (controle_type) {
    case '>':
        //entrer une valeur hors de l'intervalle dans la borne non desirée
        if (nombre > bornemin) {
            controle_ok = true;
        }
        break;
    case '<':
        //entrer une valeur hors de l'intervalle dans la borne non desirée
        if (nombre < bornemax) {
            controle_ok = true;
        }
        break;
    case '=':
        //entrer une valeur hors de l'intervalle dans bornemax
        if (nombre == bornemin) {
            controle_ok = true;
        }
        break;
    case '&':
        if (nombre > bornemin && nombre < bornemax) {
            controle_ok = true;
        }
        break;
    case '|':
        if (nombre < bornemin || nombre > bornemax) {
            controle_ok = true;
        }
        break;
    default:
        break;
    }
    return controle_ok;
}

bool DateValide(int jour, int mois, int annee)
{
    bool estBiss, mois_ok, jour_ok, fevrier_ok, date_ok;


    estBiss = (((annee % 4 == 0) && (annee % 100 != 0)) || (annee % 400 == 0));

    fevrier_ok = (((estBiss == true) && jour <= 29) || ((estBiss == false) && jour <= 28));

    jour_ok = (jour >= 1 && (((jour <= 31) && (mois != 4 && mois != 6 && mois != 9 && mois != 11 && mois != 2))
        || ((jour <= 30) && (mois != 2))
        || (jour <= 29 && fevrier_ok)
        || (jour <= 28 && fevrier_ok == false)));

    mois_ok = ((mois <= 12 && mois >= 1));

    date_ok = (jour_ok && mois_ok);

    return date_ok;
}

string DateToString(char separateur,int jour, int mois, int annee) {
    string date;
    string jour_str = to_string(jour);
    string mois_str = to_string(mois);
    string annee_str = to_string(annee);

    date = jour_str + separateur + mois_str + separateur + annee_str;
    return date;
}

string Majuscule(string nom) {
    int i, j = nom.length();

    //passage par une boucle de toutes les lettres du nom
    for (i = 0; i <= j ; i++) {
        //verification du caractere etant une lettre
        if ((nom[i] >= 'a') && (nom[i] <= 'z')) {
            //transformation du nom en majuscule 
            nom[i] = nom[i] - 'a' + 'A';
        }
    }
    return nom;
}

string Minuscule(string nom) {
    int i, j = nom.length();

    //passage par une boucle de toutes les lettres du nom
    for(i = 0; i <= j; i++) {
        //verification du caractere etant une lettre
        if(( nom[i] >= 'A' ) && ( nom[i] <= 'Z' )) {
            //transformation du nom en minuscule 
            nom[i] = nom[i] - 'A' + 'a';
        }
    }
    return nom;
}

bool ControleDate(int jour1, int mois1, int annee1, int jour2, int mois2, int annee2) {
    bool date_ok;

    date_ok = false;
    if (annee2 > annee1) {
        date_ok = true;
    } else {
        if (annee2 == annee1 && mois2 > mois1) {
            date_ok = true;
        } else {
            if (annee2 == annee1 && mois2 == mois1 && jour2 > jour1) {
                date_ok = true;
            } else {
                if (annee2 == annee1 && mois2 == mois1 && jour2 == jour1) {
                    date_ok = true;
                }
            }
        }
    }
    return date_ok;
}

void Clearcin() {
    cin.clear(); // effacer les bits d'erreurs 
    cin.seekg(0, ios::end);
    if (!cin.fail()) {
        ; // Le flux a déjà un état valide donc inutile de faire appel à clear()
    } else {
        cin.clear(); // Le flux est dasn un état invalide donc on le remet en état valide
    }
}

bool RechercheExp(string cible, string motif) {
    regex pattern{motif};
    bool result = regex_search(cible, pattern);
    return result;
}