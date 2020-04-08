#include "biblio.h"
#include "tools.h"


void AfficheLivres(t_biblio& biblio) {
    int i;

    for(i = 1; i <= biblio.nblivre; i++) {
        cout << AffMesg(01, biblio) << i << " :\n";
        AfficheLivre(biblio, i);
        cout << endl;
    }
}

void AfficheLivre(t_biblio& biblio, int& nolivre) {
    t_livre livre;

    livre = biblio.tablivre[nolivre];
    cout << MesgSaisie(02, biblio) << livre.titre << endl;
    cout << MesgSaisie(03, biblio) << biblio.tabauteur[livre.auteur].prenom << " " << biblio.tabauteur[livre.auteur].nom << endl;
    cout << MesgSaisie(04, biblio) << DateToString('/', livre.date.jour, livre.date.mois, livre.date.annee) << endl;
    cout << MesgSaisie(05, biblio) << livre.page << endl;
}

int RechercheLivre(t_biblio& biblio) {
    int choix, nolivre;
    string recherche;

    nolivre = -1;
    do {
        Menu(AffMenu(1001, biblio), choix, biblio);
        switch(choix) {
        case 1:
            nolivre = AfficheLivreRecherche(biblio, 1);
            break;
        case 2:
            nolivre = AfficheLivreRecherche(biblio, 2);
            break;
        case 3:
            nolivre = AfficheLivreRecherche(biblio, 3);
            break;
        case 4:
            nolivre = AfficheLivreRecherche(biblio, 4);
            break;
        case 5:
            break;
        default:
            if(Controle('|', choix, 1, 5)) {
                MesgError(0002, biblio);
            } else {
                MesgError(0001, biblio);
            }
            Pause(biblio);
            break;
        }
    } while(Controle('|', choix, 1, 5));
    return nolivre;
}

int AfficheLivreRecherche(t_biblio& biblio, int type) {
    int i, j, liste[MAX], choix;
    string recherche;
    char reponse;
    t_date date;

    j = 0;
    switch(type) {
    case 1:
        SaisieChaine(recherche, MesgSaisie(0006, biblio));
        for(i = 0; i <= biblio.nblivre; i++) {
            if(RechercheExp(Majuscule(biblio.tablivre[i].titre), Majuscule(recherche))) {
                j++;
                liste[j] = i;
            }
        }
        break;
    case 2:
        recherche = to_string(AfficheAuteurRecherche(biblio, 8));
        for(i = 0; i <= biblio.nblivre; i++) {
            if(recherche == to_string(biblio.tablivre[i].auteur)) {
                j++;
                liste[j] = i;
            }
        }
        break;
    case 3:
        SaisieChaine(recherche, MesgSaisie(0007, biblio));
        for(i = 0; i <= biblio.nblivre; i++) {
            if(recherche == to_string(biblio.tablivre[i].page)) {
                j++;
                liste[j] = i;
            }
        }
        break;
    case 4:
        cout << MesgSaisie(8, biblio) << endl;
        SaisirDate(date, biblio);
        recherche = DateToString('-', date.jour, date.mois, date.annee);
        for(i = 0; i <= biblio.nblivre; i++) {
            if(recherche == DateToString('-', biblio.tablivre[i].date.jour, biblio.tablivre[i].date.mois, biblio.tablivre[i].date.annee)) {
                j++;
                liste[j] = i;
            }
        }
        break;
    default:
        break;
    }
    if(j == 0) {
        MesgError(1003, biblio);
        choix = 0;
    } else {
        if(j == 1) {
            cout << MesgSaisie(9, biblio)<< endl;
            AfficheLivre(biblio, liste[1]);
            choix = liste[1];
        } else {
            for(i = 1; i <= j; i++) {
                cout << MesgSaisie(0010, biblio)<< i<< " : \n";
                AfficheLivre(biblio, liste[i]);
            }
            SaisieEntier(choix, MesgSaisie(0011, biblio));
            while(!Controle('&', choix, 0, j + 1)) {
                MesgError(0005, biblio);
                SaisieEntier(choix, MesgSaisie(0012, biblio));
            }
            system("clear");
            AfficheLivre(biblio, liste[choix]);
            do {
                SaisieCarac(reponse, MesgSaisie(0013, biblio));
                if(reponse == AffChoix(1, biblio)) {
                    choix = liste[choix];
                } else {
                    if(reponse == AffChoix(2, biblio)) {
                        SaisieEntier(choix, MesgSaisie(0011, biblio));
                        while(!Controle('&', choix, 0, j)) {
                            MesgError(0005, biblio);
                            SaisieEntier(choix, MesgSaisie(0012, biblio));
                        }
                        AfficheLivre(biblio, choix);
                        choix = liste[choix];
                    } else {
                        MesgError(0002, biblio);
                    }
                }
            } while(reponse != AffChoix(1, biblio) && reponse != AffChoix(2, biblio));
        }
    }
    Pause(biblio);
    return choix;
}

void AfficheAuteurs(t_biblio& biblio) {
    int i;

    for(i = 1; i <= biblio.nbauteur; i++) {
        cout << AffMesg(15, biblio) << i << " :\n";
        AfficheAuteur(biblio, i);
        cout << endl;
    }
}

void AfficheAuteur(t_biblio& biblio, int& noauteur) {
    t_auteur auteur;

    auteur = biblio.tabauteur[noauteur];
    cout << MesgSaisie(16, biblio) << auteur.nom << endl;
    cout << MesgSaisie(17, biblio) << auteur.prenom << endl;
    cout << MesgSaisie(18, biblio) << auteur.nationalite << endl;
    cout << MesgSaisie(19, biblio) << DateToString('-', auteur.nais.jour, 
        auteur.nais.mois, auteur.nais.annee) << endl;
    if(auteur.mort.jour != 0) {
        cout << MesgSaisie(20, biblio) << DateToString('-', auteur.mort.jour, 
            auteur.mort.mois, auteur.mort.annee) << endl;
    }
    cout << MesgSaisie(21, biblio) << auteur.nblivres << endl;
}

int RechercheAuteur(t_biblio& biblio) {
    int choix, noauteur;
    string recherche;

    noauteur = -1;
    do {
        Menu(AffMenu(1002, biblio), choix, biblio);
        switch(choix) {
        case 1:
            noauteur = AfficheAuteurRecherche(biblio, 1);
            break;
        case 2:
            noauteur = AfficheAuteurRecherche(biblio, 2);
            break;
        case 3:
            noauteur = AfficheAuteurRecherche(biblio, 3);
            break;
        case 4:
            noauteur = AfficheAuteurRecherche(biblio, 4);
            break;
        case 5:
            noauteur = AfficheAuteurRecherche(biblio, 5);
            break;
        case 6:
            noauteur = AfficheAuteurRecherche(biblio, 6);
            break;
        case 7:
            noauteur = AfficheAuteurRecherche(biblio, 7);
            break;
        case 8:
            break;
        default:
            if(Controle('|', choix, 1, 8)) {
                MesgError(0002, biblio);
            } else {
                MesgError(0001, biblio);
            }
            break;
        }
    } while(Controle('|', choix, 1, 8));
    return noauteur;
}

int AfficheAuteurRecherche(t_biblio& biblio, int type) {
    int i, j, liste[MAX], choix;
    string recherche, recherche1, recherche2;
    char reponse;
    t_date date;

    j = 0;
    switch(type) {
    case 1:
        SaisieChaine(recherche, MesgSaisie(22, biblio));
        for(i = 0; i <= biblio.nbauteur; i++) {
            if(RechercheExp(Majuscule(biblio.tabauteur[i].nom), Majuscule(recherche))) {
                j++;
                liste[j] = i;
            }
        }
        break;
    case 2:
        SaisieChaine(recherche, MesgSaisie(23, biblio));
        for(i = 0; i <= biblio.nbauteur; i++) {
            if(RechercheExp(Majuscule(biblio.tabauteur[i].prenom), Majuscule(recherche))) {
                j++;
                liste[j] = i;
            }
        }
        break;
    case 3:
        SaisieChaine(recherche, MesgSaisie(24, biblio));
        for(i = 0; i <= biblio.nbauteur; i++) {
            if(RechercheExp(Majuscule(biblio.tabauteur[i].nationalite), Majuscule(recherche))) {
                j++;
                liste[j] = i;
            }
        }
        break;
    case 4:
        SaisieChaine(recherche, MesgSaisie(25, biblio));
        for(i = 0; i <= biblio.nbauteur; i++) {
            if(recherche == to_string(biblio.tabauteur[i].nblivres)) {
                j++;
                liste[j] = i;
            }
        }
        break;
    case 5:
        cout <<MesgSaisie(26, biblio)<< endl;
        SaisirDate(date, biblio);
        recherche = DateToString('-', date.jour, date.mois, date.annee);
        for(i = 0; i <= biblio.nbauteur; i++) {
            if(recherche == DateToString('-', biblio.tabauteur[i].nais.jour, biblio.tabauteur[i].nais.mois, biblio.tabauteur[i].nais.annee)) {
                j++;
                liste[j] = i;
            }
        }
        break;
    case 6:
        cout << MesgSaisie(26, biblio)<< endl;
        SaisirDate(date, biblio);
        recherche = DateToString('-', date.jour, date.mois, date.annee);
        for(i = 0; i <= biblio.nbauteur; i++) {
            if(recherche == DateToString('-', biblio.tabauteur[i].mort.jour, biblio.tabauteur[i].mort.mois, biblio.tabauteur[i].mort.annee)) {
                j++;
                liste[j] = i;
            }
        }
        break;
    case 7:
        SaisieChaine(recherche, MesgSaisie(28, biblio));
        for(i = 0; i <= biblio.id; i++) {
            if(recherche == to_string(biblio.tabauteur[i].id_auteur)) {
                j++;
                liste[j] = i;
            }
        }
        break;
    case 8:
        SaisieChaine(recherche1, MesgSaisie(23, biblio));
        SaisieChaine(recherche2, MesgSaisie(22, biblio));
        for(i = 0; i <= biblio.id; i++) {
            if(RechercheExp(Majuscule(biblio.tabauteur[i].nom), Majuscule(recherche2)) && 
                RechercheExp(Majuscule(biblio.tabauteur[i].prenom), Majuscule(recherche1))) {
                j++;
                liste[j] = i;
            }
        }
        break;
    default:
        if(Controle('|', choix, 1, 8)) {
            MesgError(0002, biblio);
        } else {
            MesgError(0001, biblio);
        }
        break;
    }
    if(j == 0) {
        MesgError(1004, biblio);
        choix = 0;
    } else {
        if(j == 1) {
            cout << MesgSaisie(29, biblio)<< endl;
            AfficheAuteur(biblio, liste[1]);
            choix = liste[1];
        } else {
            for(i = 1; i <= j; i++) {
                cout << AffMesg(10, biblio)<< i << " : \n";
                AfficheAuteur(biblio, liste[i]);
            }
            SaisieEntier(choix, MesgSaisie(11, biblio));
            while(!Controle('&', choix, 0, j + 1)) {
                MesgError(0005, biblio);
                SaisieEntier(choix, MesgSaisie(12, biblio));
            }
            system("clear");
            AfficheAuteur(biblio, liste[choix]);
            do {
                SaisieCarac(reponse, MesgSaisie(30, biblio));
                if(reponse == AffChoix(1, biblio)) {
                    choix = liste[choix];
                } else {
                    if(reponse == AffChoix(2, biblio)) {
                        SaisieEntier(choix, MesgSaisie(11, biblio));
                        while(!Controle('&', choix, 0, j + 1)) {
                            MesgError(0005, biblio);
                            SaisieEntier(choix, MesgSaisie(12, biblio));
                        }
                        AfficheAuteur(biblio, choix);
                        choix = liste[choix];
                    } else {
                        if(reponse == AffChoix(3, biblio)) {
                            choix = -1;
                        } else {
                            MesgError(0002, biblio);
                        }
                    }
                }
            } while(reponse != AffChoix(1, biblio) && reponse != AffChoix(2, biblio) && reponse != AffChoix(3, biblio));
        }
    }
    Pause(biblio);
    return choix;
}

void AjoutLivre(t_biblio& biblio) {
    t_livre livre;
    char reponse;
    int i;

    if (biblio.nblivre == MAX_LIVRE-1) {
        MesgError(2001, biblio);
    } else {
        SaisieChaine(livre.titre, MesgSaisie(2, biblio));
        while (livre.titre == "") {
            MesgError(0005, biblio);
            SaisieChaine(livre.titre, MesgSaisie(34, biblio));
        }
        i = AfficheAuteurRecherche(biblio, 8);
        if(i == 0) {
            cout <<MesgSaisie(35, biblio)<< endl;
            AjoutAuteur(biblio);
            livre.auteur = biblio.id;
        } else {
            SaisieCarac(reponse, MesgSaisie(36, biblio));
            if(reponse == AffChoix(1, biblio)) {
                AjoutAuteur(biblio);
                livre.auteur = biblio.id;
            } else {
                if(reponse == AffChoix(2, biblio)) {
                    livre.auteur = i;
                } else {
                    MesgError(0002, biblio);
                }
            }
        }
        if (LivreExisteDeja(biblio, livre.titre, livre.auteur)) {
            MesgError(1007, biblio);
        } else {
            cout <<MesgSaisie(4, biblio)<< endl;
            SaisirDate(livre.date, biblio);
            while (!ControleDate(biblio.tabauteur[biblio.nbauteur].nais.jour, biblio.tabauteur[biblio.nbauteur].nais.mois,
                biblio.tabauteur[biblio.nbauteur].nais.annee, livre.date.jour, livre.date.mois, livre.date.annee)) {
                MesgError(0003, biblio);
                SaisirDate(livre.date, biblio);
            }
            SaisieEntier(livre.page, MesgSaisie(5, biblio));
            while (!Controle('>', livre.page, 0, -1)) {
                MesgError(0006, biblio);
                SaisieEntier(livre.page, MesgSaisie(7,biblio));
            }
            biblio.tablivre[biblio.nblivre + 1] = livre;
            biblio.nblivre++;
            biblio.tabauteur[biblio.tablivre[biblio.nblivre].auteur].nblivres++;
            MesgValid(37, biblio);
        }
    }
}

bool LivreExisteDeja(t_biblio& biblio, string titre, int auteur) {
    string buffer_string;
    bool existe = false;
    int i = 0, j = 0;

    for(i = 0; i < biblio.nblivre; i++) {
        for(j = 0; j < biblio.nbauteur; j++) {
            if(Majuscule(biblio.tablivre[i].titre) == Majuscule(titre) && biblio.tabauteur[j].id_auteur == auteur) {
                existe = true;
            }
        }
    }
    return existe;
}

void ModifLivre(t_biblio& biblio, int& nolivre) {
    int choix, buffer_int;
    char reponse;
    t_date date;
    string buffer_string;

    if(nolivre > 0) {
        do {
            Menu(AffMenu(1003, biblio), choix, biblio);
            switch(choix) {
            case 1:
                SaisieChaine(buffer_string, MesgSaisie(38, biblio));
                if(LivreExisteDeja(biblio, buffer_string, biblio.tablivre[nolivre].auteur)) {
                    MesgError(1007, biblio);
                    MesgNonValid(39, biblio);
                } else {
                    biblio.tablivre[nolivre].titre = buffer_string;
                    MesgValid(40, biblio);
                }
                Pause(biblio);
                break;
            case 2:
                cout << AffMesg(42, biblio) << biblio.tablivre[nolivre].titre << " :\n";
                buffer_int = AfficheAuteurRecherche(biblio, 8);
                if(buffer_int == 0) {
                    cout << MesgSaisie(35, biblio) << endl;
                    AjoutAuteur(biblio);
                    buffer_int = biblio.id;
                } else {
                    do {
                        SaisieCarac(reponse, MesgSaisie(36, biblio));
                        if(reponse == AffChoix(1, biblio)) {
                            AjoutAuteur(biblio);
                            buffer_int = biblio.id;
                        } else {
                            if(reponse == AffChoix(2, biblio)) {
                            } else {
                                MesgError(0003, biblio);
                            }
                        }
                    } while(reponse != AffChoix(1, biblio) && reponse != AffChoix(2, biblio));
                }
                if(LivreExisteDeja(biblio, biblio.tablivre[nolivre].titre, buffer_int)) {
                    MesgError(1007, biblio);
                    MesgNonValid(39, biblio);
                } else {
                    biblio.tablivre[nolivre].auteur = buffer_int;
                    MesgValid(40, biblio);
                }
                Pause(biblio);
                break;
            case 3:
                cout << MesgSaisie(43, biblio) << endl;
                SaisirDate(date, biblio);
                if(ControleDate(biblio.tabauteur[biblio.tablivre[nolivre].auteur].nais.jour, 
                    biblio.tabauteur[biblio.tablivre[nolivre].auteur].nais.mois, 
                    biblio.tabauteur[biblio.tablivre[nolivre].auteur].nais.annee, 
                    date.jour, date.annee, date.annee) == false) {
                    MesgError(0003, biblio);
                    MesgNonValid(39, biblio);
                } else {
                    biblio.tablivre[nolivre].date = date;
                    MesgValid(40, biblio);
                }
                Pause(biblio);
                break;
            case 4:
                SaisieEntier(buffer_int, MesgSaisie(44, biblio));
                if(Controle('>', biblio.tablivre[nolivre].page, 0, -1) == false) {
                    MesgError(0006, biblio);
                    MesgNonValid(39, biblio);
                } else {
                    biblio.tablivre[nolivre].page = buffer_int;
                    MesgValid(40, biblio);
                }
                Pause(biblio);
                break;
            case 5:
                break;
            default:
                if(Controle('|', choix, 1, 5)) {
                    MesgError(0002, biblio);
                } else {
                    MesgError(0001, biblio);
                }
                Pause(biblio);
                break;
            }
        } while(choix != 5);
    }
}

void SupprimeLivre(t_biblio& biblio) {
    char reponse;
    int position;

    position = RechercheLivre(biblio);
    if (position <= 0) {
        if (position == 0) {
            MesgError(1005, biblio);
        }
    } else {
        do {
            SaisieCarac(reponse, MesgSaisie(45, biblio));
            if (reponse == AffChoix(1, biblio)) {
                if(biblio.tabauteur[biblio.tablivre[position].auteur].nblivres == 1) {
                    do {
                        SaisieCarac(reponse, MesgSaisie(46, biblio));
                        if(reponse == AffChoix(1, biblio)) {
                            biblio.tabauteur[biblio.tablivre[position].auteur] = biblio.tabauteur[biblio.nbauteur];
                            biblio.nbauteur--;
                            MesgValid(47, biblio);
                        } else {
                            if(reponse == AffChoix(2, biblio)) {
                            } else {
                                MesgError(0002, biblio);
                            }
                        }
                    } while(reponse != AffChoix(1, biblio) && reponse != AffChoix(2, biblio));
                    biblio.tablivre[position] = biblio.tablivre[biblio.nblivre];
                    biblio.nblivre--;
                    MesgValid(47, biblio);
                } else {
                    biblio.tablivre[position] = biblio.tablivre[biblio.nblivre];
                    biblio.nblivre--;
                    MesgValid(47, biblio);
                }
            } else {
                if (reponse == AffChoix(2, biblio)) {
                    MesgNonValid(48, biblio);
                } else {
                    MesgError(0002, biblio);
                }
            }
        } while (reponse != AffChoix(1, biblio) && reponse != AffChoix(2, biblio));
    }
}

void AjoutAuteur(t_biblio& biblio) {
    string buffer_string;
    t_auteur auteur[2];
    char reponse;

    if (biblio.nbauteur == MAX_AUTEUR - 1) {
        MesgError(2002, biblio);
    } else {
        SaisieChaine(auteur[1].nom, MesgSaisie(16, biblio));
        while (auteur[1].nom == "") {
            MesgError(0005, biblio);
            SaisieChaine(auteur[1].nom, MesgSaisie(49, biblio));
        }
        SaisieChaine(auteur[1].prenom, MesgSaisie(17, biblio));
        while (auteur[1].prenom == "") {
            MesgError(0005, biblio);
            SaisieChaine(auteur[1].prenom, MesgSaisie(50, biblio));
        }
        SaisieChaine(auteur[1].nationalite, MesgSaisie(18, biblio));
        while (auteur[1].nationalite == "") {
            MesgError(0005, biblio);
            SaisieChaine(auteur[1].nationalite, MesgSaisie(51, biblio));
        }
        cout <<MesgSaisie(26, biblio)<< endl;
        SaisirDate(auteur[1].nais, biblio);
        do {
            SaisieCarac(reponse, MesgSaisie(52, biblio));
            if (reponse == AffChoix(1, biblio)) {
                cout << MesgSaisie(14, biblio) << endl;
                SaisirDate(auteur[1].mort, biblio);
                while (!ControleDate(auteur[1].nais.jour, auteur[1].nais.mois, auteur[1].nais.annee, auteur[1].mort.jour, auteur[1].mort.mois, auteur[1].mort.annee)) {
                    MesgError(0003, biblio);
                    cout << MesgSaisie(14, biblio) << endl;
                    SaisirDate(auteur[1].mort, biblio);
                }
            } else {
                if (reponse == AffChoix(2, biblio)) {
                    auteur[1].mort.jour = 0;
                    auteur[1].mort.mois = 0;
                    auteur[1].mort.annee = 0;
                } else {
                    MesgError(0002, biblio);
                }
            }
        } while (reponse != AffChoix(1, biblio) && reponse != AffChoix(2, biblio));
        auteur[1].nblivres = 0;
        auteur[1].id_auteur = biblio.id + 1;
        biblio.id++;
        MesgValid(53, biblio);
        cout << MesgSaisie(54, biblio) << auteur[1].id_auteur << endl;
        biblio.tabauteur[biblio.nbauteur + 1] = auteur[1];
        biblio.nbauteur++;
    }
}

void ModifAuteur(t_biblio& biblio, int& noauteur) {
    int choix, i;
    bool date_ok;
    t_date date;
    string buffer_string;

    if(noauteur > 0) {
        do {
            Menu(AffMenu(1004, biblio), choix, biblio);
            switch(choix) {
            case 1:
                SaisieChaine(buffer_string, MesgSaisie(55, biblio));
                biblio.tabauteur[noauteur].nom = buffer_string;
                MesgValid(40, biblio);
                Pause(biblio);
                break;
            case 2:
                SaisieChaine(buffer_string, MesgSaisie(56, biblio));
                biblio.tabauteur[noauteur].prenom = buffer_string;
                MesgValid(40, biblio);
                Pause(biblio);
                break;
            case 3:
                SaisieChaine(buffer_string, MesgSaisie(57, biblio));
                biblio.tabauteur[noauteur].nationalite = buffer_string;
                MesgValid(40, biblio);
                Pause(biblio);
                break;
            case 4:
                cout << MesgSaisie(58, biblio) << endl;
                SaisirDate(date, biblio);
                date_ok = true;
                for(i = 0; i <= biblio.nblivre; i++) {
                    if(biblio.tablivre[i].auteur == biblio.tabauteur[noauteur].id_auteur) {
                        if(ControleDate(date.jour, date.mois, date.annee, biblio.tablivre[i].date.jour, 
                            biblio.tablivre[i].date.mois, biblio.tablivre[i].date.annee) == false || 
                            (ControleDate(date.jour, date.mois, date.annee, biblio.tabauteur[noauteur].mort.jour, 
                                biblio.tabauteur[noauteur].mort.mois, biblio.tabauteur[noauteur].mort.annee) == false &&
                                biblio.tabauteur[noauteur].mort.jour != 0)) {
                            date_ok = false;
                        }
                    }
                }
                if(date_ok == false) {
                    MesgError(0004, biblio);
                    MesgNonValid(39, biblio);
                } else {
                    biblio.tabauteur[noauteur].nais = date;
                    MesgValid(40, biblio);
                }
                Pause(biblio);
                break;
            case 5:
                cout << MesgSaisie(59, biblio) << endl;
                SaisirDate(date, biblio);
                date_ok = true;
                for(i = 0; i <= biblio.nblivre; i++) {
                    if(biblio.tablivre[i].auteur == biblio.tabauteur[noauteur].id_auteur) {
                        if(ControleDate(biblio.tabauteur[noauteur].nais.jour, biblio.tabauteur[noauteur].nais.mois, 
                            biblio.tabauteur[noauteur].nais.annee, date.jour, date.mois, date.annee) == false) {
                            date_ok = false;
                        }
                    }
                }
                if(date_ok == false) {
                    MesgError(0003, biblio);
                    MesgNonValid(39, biblio);
                } else {
                    biblio.tabauteur[noauteur].mort = date;
                    MesgValid(40, biblio);
                }
                Pause(biblio);
                break;
            case 6:
                break;
            default:
                if(Controle('|', choix, 1, 6)) {
                    MesgError(0002, biblio);
                } else {
                    MesgError(0001, biblio);
                }
                Pause(biblio);
                break;
            }
        } while(choix != 6);
    }
}

void SupprimeAuteur(t_biblio& biblio) {
    char reponse;
    int position, i, j, buffer_int;

    position = RechercheAuteur(biblio);
    if(position <= 0) {
        if(position == 0) {
            MesgError(1006, biblio);
        }
    } else {
        AfficheAuteur(biblio, position);
        do {
            SaisieCarac(reponse, MesgSaisie(60, biblio));
            if(reponse == AffChoix(1, biblio)) {
                if(biblio.tabauteur[position].nblivres != 0) {
                    MesgSaisie(61, biblio);
                    for(j = 0; j <= biblio.tabauteur[position].nblivres; j++) {
                        buffer_int = 0;
                        for(i = 0; i <= biblio.nblivre; i++) {
                            if(biblio.tablivre[i].auteur == biblio.tabauteur[position].id_auteur) {
                                cout << biblio.tablivre[i].titre;
                                MesgValid(63, biblio);
                                biblio.tablivre[i] = biblio.tablivre[biblio.nblivre];
                                buffer_int++;
                            }
                        }
                        biblio.nblivre -= buffer_int;
                    }
                }
                biblio.tabauteur[position] = biblio.tabauteur[biblio.nbauteur];
                biblio.nbauteur--;
                MesgValid(47, biblio);
            } else {
                if(reponse == AffChoix(2, biblio)) {
                    MesgNonValid(48, biblio);
                } else {
                    MesgError(0002, biblio);
                }
            }
        } while(reponse != AffChoix(1, biblio) && reponse != AffChoix(2, biblio));
    }
    Pause(biblio);
}

void OpenFile(t_biblio& biblio) {
    int i;
    string buffer_string;
    ifstream fic("Data/fichier.txt");

    getline(fic, buffer_string);
    if(buffer_string != "") {
        biblio.id = stoi(buffer_string);
        getline(fic, buffer_string);
        biblio.nblivre = stoi(buffer_string);
        for(i = 1; i <= biblio.nblivre; i++) {
            getline(fic, biblio.tablivre[i].titre);
            getline(fic, buffer_string);
            biblio.tablivre[i].auteur = stoi(buffer_string);
            getline(fic, buffer_string);
            biblio.tablivre[i].page = stoi(buffer_string);
            getline(fic, buffer_string);
            biblio.tablivre[i].date.jour = stoi(buffer_string);
            getline(fic, buffer_string);
            biblio.tablivre[i].date.mois = stoi(buffer_string);
            getline(fic, buffer_string);
            biblio.tablivre[i].date.annee = stoi(buffer_string);
        }
        getline(fic, buffer_string);
        biblio.nbauteur = stoi(buffer_string);
        for(i = 1; i <= biblio.nbauteur; i++) {
            getline(fic, biblio.tabauteur[i].prenom);
            getline(fic, biblio.tabauteur[i].nom);
            getline(fic, biblio.tabauteur[i].nationalite);
            getline(fic, buffer_string);
            biblio.tabauteur[i].id_auteur = stoi(buffer_string);
            getline(fic, buffer_string);
            biblio.tabauteur[i].nais.jour = stoi(buffer_string);
            getline(fic, buffer_string);
            biblio.tabauteur[i].nais.mois = stoi(buffer_string);
            getline(fic, buffer_string);
            biblio.tabauteur[i].nais.annee = stoi(buffer_string);
            getline(fic, buffer_string);
            biblio.tabauteur[i].mort.jour = stoi(buffer_string);
            getline(fic, buffer_string);
            biblio.tabauteur[i].mort.mois = stoi(buffer_string);
            getline(fic, buffer_string);
            biblio.tabauteur[i].mort.annee = stoi(buffer_string);
            getline(fic, buffer_string);
            biblio.tabauteur[i].nblivres = stoi(buffer_string);
        }
        getline(fic, buffer_string);
        biblio.nolang = stoi(buffer_string);
    } else {
        biblio.id = 0;
        biblio.nbauteur = 0;
        biblio.nblivre = 0;
    }
}

void CloseFile(t_biblio& biblio) {
    int i;
    ofstream fic("Data/fichier.txt");

    fic << biblio.id << endl;
    fic << biblio.nblivre << endl;
    for (i = 1; i <= biblio.nblivre; i++) {
        fic << (biblio.tablivre[i].titre) << endl;
        fic << biblio.tablivre[i].auteur << endl;
        fic << biblio.tablivre[i].page << endl;
        fic << biblio.tablivre[i].date.jour << endl;
        fic << biblio.tablivre[i].date.mois << endl;
        fic << biblio.tablivre[i].date.annee << endl;
    }
    fic << biblio.nbauteur << endl;
    for (i = 1; i <= biblio.nbauteur; i++) {
        fic << (biblio.tabauteur[i].prenom) << endl;
        fic << (biblio.tabauteur[i].nom) << endl;
        fic << (biblio.tabauteur[i].nationalite) << endl;
        fic << biblio.tabauteur[i].id_auteur << endl;
        fic << biblio.tabauteur[i].nais.jour << endl;
        fic << biblio.tabauteur[i].nais.mois << endl;
        fic << biblio.tabauteur[i].nais.annee << endl;
        fic << biblio.tabauteur[i].mort.jour << endl;
        fic << biblio.tabauteur[i].mort.mois << endl;
        fic << biblio.tabauteur[i].mort.annee << endl;
        fic << biblio.tabauteur[i].nblivres << endl;
    }
    fic << biblio.nolang << endl;
}

void Langinit(t_biblio& biblio, int choix) {
    int i, j;
    string buffer_string;
    ifstream ficfr("Data/Language/fr_lang.txt");
    ifstream ficen("Data/Language/en_lang.txt");

    switch(choix) {
    case 1:
        getline(ficfr, buffer_string);
        biblio.lang.nberr = stoi(buffer_string);
        if(biblio.lang.nberr != 0) {
            for(i = 1; i <= biblio.lang.nberr; i++) {
                getline(ficfr, buffer_string);
                biblio.lang.erreur[i].noerr = stoi(buffer_string);
                getline(ficfr, biblio.lang.erreur[i].mesg);
            }
        }
        getline(ficfr, buffer_string);
        biblio.lang.nbmesg = stoi(buffer_string);
        if(biblio.lang.nbmesg != 0) {
            for(i = 1; i <= biblio.lang.nbmesg; i++) {
                getline(ficfr, buffer_string);
                biblio.lang.mesg[i].nomesg = stoi(buffer_string);
                getline(ficfr, biblio.lang.mesg[i].mesg);
            }
        }
        getline(ficfr, buffer_string);
        biblio.lang.nbmenu = stoi(buffer_string);
        if(biblio.lang.nbmenu != 0) {
            for(i = 1; i <= biblio.lang.nbmenu; i++) {
                getline(ficfr, buffer_string);
                biblio.lang.menu[i].nomenu = stoi(buffer_string);
                getline(ficfr, buffer_string);
                biblio.lang.menu[i].size = stoi(buffer_string);
                for(j = 1; j <= biblio.lang.menu[i].size; j++) {
                    getline(ficfr, biblio.lang.menu[i].menu[j]);
                }
            }
        }
        getline(ficfr, buffer_string);
        biblio.lang.nbchoix = stoi(buffer_string);
        if(biblio.lang.nbchoix != 0) {
            for(i = 1; i <= biblio.lang.nbchoix; i++) {
                getline(ficfr, buffer_string);
                biblio.lang.choix[i].nochoix = stoi(buffer_string);
                getline(ficfr, buffer_string);
                biblio.lang.choix[i].choix = buffer_string[0];
            }
        }
        biblio.nolang = 1;
        break;
    case 2:
        getline(ficen, buffer_string);
        biblio.lang.nberr = stoi(buffer_string);
        if(biblio.lang.nberr != 0) {
            for(i = 0; i < biblio.lang.nberr; i++) {
                getline(ficen, buffer_string);
                biblio.lang.erreur[i].noerr = stoi(buffer_string);
                getline(ficen, biblio.lang.erreur[i].mesg);
            }
        }
        getline(ficen, buffer_string);
        biblio.lang.nbmesg = stoi(buffer_string);
        if(biblio.lang.nbmesg) {
            for(i = 0; i < biblio.lang.nbmesg; i++) {
                getline(ficen, buffer_string);
                biblio.lang.mesg[i].nomesg = stoi(buffer_string);
                getline(ficen, biblio.lang.mesg[i].mesg);
            }
        }
        getline(ficen, buffer_string);
        biblio.lang.nbmenu = stoi(buffer_string);
        if(biblio.lang.nbmenu != 0) {
            for(i = 1; i <= biblio.lang.nbmenu; i++) {
                getline(ficen, buffer_string);
                biblio.lang.menu[i].nomenu = stoi(buffer_string);
                getline(ficen, buffer_string);
                biblio.lang.menu[i].size = stoi(buffer_string);
                for(j = 1; j <= biblio.lang.menu[i].size; j++) {
                    getline(ficen, biblio.lang.menu[i].menu[j]);
                }
            }
        }
        getline(ficen, buffer_string);
        biblio.lang.nbchoix = stoi(buffer_string);
        if(biblio.lang.nbchoix != 0) {
            for(i = 1; i <= biblio.lang.nbchoix; i++) {
                getline(ficen, buffer_string);
                biblio.lang.choix[i].nochoix = stoi(buffer_string);
                getline(ficen, buffer_string);
                biblio.lang.choix[i].choix = buffer_string[0];
            }
        }
        biblio.nolang = 2;
        break;
    default:
        break;
    }
}

void MesgError(int noerr, t_biblio& biblio) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string chaine;

    chaine = "# " + AffErr(0000, biblio) + " # " + to_string(noerr) + " # " + AffErr(noerr, biblio) + "\n";
    SetConsoleTextAttribute(hConsole, 4);
    cout << chaine;
    SetConsoleTextAttribute(hConsole, 7);
}

void MesgValid(int nomesg, t_biblio& biblio) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string chaine;

    chaine = AffMesg(nomesg, biblio) + "\n";
    SetConsoleTextAttribute(hConsole, 2);
    cout << chaine;
    SetConsoleTextAttribute(hConsole, 7);
}

void MesgNonValid(int nomesg, t_biblio& biblio) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string chaine;

    chaine = AffMesg(nomesg, biblio) + "\n";
    SetConsoleTextAttribute(hConsole, 6);
    cout << chaine;
    SetConsoleTextAttribute(hConsole, 7);
}

string AffMenu(int nomenu, t_biblio& biblio) {
    string chaine;
    int i,j;

    i = 0;
    while(nomenu != biblio.lang.menu[i].nomenu) {
        i++;
    }
    chaine = biblio.lang.menu[i].menu[1];
    for(j = 2; j <= biblio.lang.menu[i].size ; j++) {
        chaine += "\n";
        chaine += biblio.lang.menu[i].menu[j];
    }
    return chaine;
}

string MesgSaisie(int nomesg, t_biblio& biblio) {
    string chaine;

    chaine = AffMesg(nomesg, biblio) + " : ";
    return chaine;
}

string AffMesg(int nomesg, t_biblio& biblio) {
    int i;
    string mesg;

    i = 0;
    while(nomesg != biblio.lang.mesg[i].nomesg) {
        i++;
    }
    mesg = biblio.lang.mesg[i].mesg;
    return mesg;
}

string AffErr(int noerr, t_biblio& biblio) {
    int i;
    string mesg;

    i = 0;
    while(noerr != biblio.lang.erreur[i].noerr) {
        i++;
    }
    mesg = biblio.lang.erreur[i].mesg;
    return mesg;
}

char AffChoix(int nochoix, t_biblio& biblio) {
    int i;
    char choix;

    i = 0;
    while(nochoix != biblio.lang.choix[i].nochoix) {
        i++;
    }
    choix = biblio.lang.choix[i].choix;
    return choix;
}

void Menu(string menu, int& choix, t_biblio& biblio) {
    system("CLS");
    cout << menu << endl << endl;
    SaisieEntier(choix, MesgSaisie(62, biblio));
}

void SaisirDate(t_date& date, t_biblio& biblio) {
    SaisieEntier(date.jour, MesgSaisie(74, biblio));
    while(Controle('|', date.jour, 1, 31)) {
        MesgError(5, biblio);
        MesgError(7, biblio);
        SaisieEntier(date.jour, MesgSaisie(72, biblio));
    }
    SaisieEntier(date.mois, MesgSaisie(75, biblio));
    while(Controle('|', date.mois, 1, 12)) {
        MesgError(5, biblio);
        MesgError(8, biblio);
        SaisieEntier(date.mois, MesgSaisie(73, biblio));
    }
    SaisieEntier(date.annee, MesgSaisie(76, biblio));
    while(!DateValide(date.jour, date.mois, date.annee)) {
        MesgError(9, biblio);
        SaisirDate(date, biblio);
    }
}

void Pause(t_biblio& biblio) {
    cout << AffMesg(31, biblio);
    cin.get();
}