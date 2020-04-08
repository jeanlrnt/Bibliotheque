#include "biblio.h"
#include "tools.h"

int main() {
    int choix1, choix2, choix3, buffer_int;
    t_biblio bibliotheque;
    char reponse;
    bool quit = false;

    OpenFile(bibliotheque);
    Langinit(bibliotheque, bibliotheque.nolang);
    do {
        Menu(AffMenu(1005, bibliotheque), choix1, bibliotheque);
        switch (choix1) {
        case 1: // menu d'affichage
            do {
                Menu(AffMenu(1006, bibliotheque), choix2, bibliotheque);
                switch (choix2) {
                case 1:
                    do {
                        Menu(AffMenu(1007, bibliotheque), choix3, bibliotheque);
                        switch (choix3) {
                        case 1:
                            if (Controle('>', bibliotheque.nblivre, 0, -1)) {
                                cout << MesgSaisie(64, bibliotheque) << endl << endl;
                                AfficheLivres(bibliotheque);
                            } else {
                                MesgError(1001, bibliotheque);
                            }
                            Pause(bibliotheque);
                            break;
                        case 2:
                            if (Controle('>', bibliotheque.nblivre, 0, -1)) {
                                RechercheLivre(bibliotheque);
                            } else {
                                MesgError(1001, bibliotheque);
                            }
                            Pause(bibliotheque);
                            break;
                        case 3:
                            break;
                        default:
                            if(Controle('|', choix3, 1, 3)) {
                                MesgError(0002, bibliotheque);
                            } else {
                                MesgError(0001, bibliotheque);
                            }
                            Pause(bibliotheque);
                            break;
                        }
                    } while (choix3 != 3);
                    break;
                case 2:
                    do {
                        Menu(AffMenu(1008, bibliotheque), choix3, bibliotheque);
                        switch (choix3) {
                        case 1:
                            if(Controle('>', bibliotheque.nbauteur, 0, -1)) {
                                cout << MesgSaisie(70, bibliotheque) << endl << endl;
                                AfficheAuteurs(bibliotheque);
                            } else {
                                MesgError(1002, bibliotheque);
                            }
                            Pause(bibliotheque);
                            break;
                        case 2:
                            if(Controle('>', bibliotheque.nbauteur, 0, -1)) {
                                RechercheAuteur(bibliotheque);
                            } else {
                                MesgError(1002, bibliotheque);
                            }
                            Pause(bibliotheque);
                            break;
                        case 3:
                            break;
                        default:
                            if (Controle('|', choix3, 1, 3)) {
                                MesgError(0002, bibliotheque);
                            } else {
                                MesgError(0001, bibliotheque);
                            }
                            Pause(bibliotheque);
                            break;
                        }
                    } while (choix3 != 3);
                    break;
                case 3:
                    break;
                default:
                    if (Controle('|', choix2, 1, 3)) {
                        MesgError(0002, bibliotheque);
                    } else {
                        MesgError(0001, bibliotheque);
                    }
                    Pause(bibliotheque);
                    break;
                }
            } while (choix2 != 3);
            break;
        case 2: // menu pour ajouter, modifier, supprimer
            do {
                Menu(AffMenu(1009, bibliotheque), choix2, bibliotheque);
                switch (choix2) {
                case 1:
                    do {
                        Menu(AffMenu(1010, bibliotheque), choix3, bibliotheque);
                        switch (choix3) {
                        case 1:
                            cout << MesgSaisie(65, bibliotheque) << endl << endl;
                            AjoutLivre(bibliotheque);
                            Pause(bibliotheque);
                            break;
                        case 2:
                            if (Controle('>', bibliotheque.nblivre, 0, -1)) {
                                buffer_int = RechercheLivre(bibliotheque);
                                ModifLivre(bibliotheque, buffer_int);
                            } else {
                                MesgError(1001, bibliotheque);
                            }
                            Pause(bibliotheque);
                            break;
                        case 3:
                            if (Controle('>', bibliotheque.nblivre, 0, -1)) {
                                SupprimeLivre(bibliotheque);
                            } else {
                                MesgError(1001, bibliotheque);
                            }
                            Pause(bibliotheque);
                            break;
                        case 4:
                            break;
                        default:
                            if (Controle('|', choix3, 1, 4)) {
                                MesgError(0002, bibliotheque);
                            } else {
                                MesgError(0001, bibliotheque);
                            }
                            Pause(bibliotheque);
                            break;
                        }
                    } while (choix3 != 4);
                    break;
                case 2:
                    do {
                        Menu(AffMenu(1011, bibliotheque), choix3, bibliotheque);
                        switch (choix3) {
                        case 1:
                            cout << MesgSaisie(71, bibliotheque) << endl << endl;
                            AjoutAuteur(bibliotheque);
                            Pause(bibliotheque);
                            break;
                        case 2:
                            if(Controle('>', bibliotheque.nbauteur, 0, -1)) {
                                buffer_int = RechercheAuteur(bibliotheque);
                                ModifAuteur(bibliotheque, buffer_int);
                            } else {
                                MesgError(1002, bibliotheque);
                            }
                            Pause(bibliotheque);
                            break;
                        case 3:
                            if(Controle('>', bibliotheque.nbauteur, 0, -1)) {
                                SupprimeAuteur(bibliotheque);
                            } else {
                                MesgError(1002, bibliotheque);
                            }
                            Pause(bibliotheque);
                            break;
                        case 4:
                            break;
                        default:
                            if (Controle('|', choix3, 1, 4)) {
                                MesgError(0002, bibliotheque);
                            } else {
                                MesgError(0001, bibliotheque);
                            }
                            Pause(bibliotheque);
                            break;
                        }
                    } while (choix3 != 4);
                    break;
                case 3:
                    break;
                default:
                    if (Controle('|', choix2, 1, 3)) {
                        MesgError(0002, bibliotheque);
                    } else {
                        MesgError(0001, bibliotheque);
                    }
                    Pause(bibliotheque);
                    break;
                }
            } while (choix2 != 3);
            break;
        case 3:
            do {
                Menu(AffMenu(1012, bibliotheque), choix2, bibliotheque);
                switch(choix2) {
                case 1:
                    bibliotheque.nblivre = 0;
                    bibliotheque.nbauteur = 0;
                    bibliotheque.id = 0;
                    MesgValid(66, bibliotheque);
                    Pause(bibliotheque);
                    break;
                case 2:
                    CloseFile(bibliotheque);
                    MesgValid(67, bibliotheque);
                    Pause(bibliotheque);
                    break;
                case 3:
                    do {
                        Menu(AffMenu(1013, bibliotheque), choix3, bibliotheque);
                        switch(choix3) {
                        case 1:
                            Langinit(bibliotheque, 1);
                            MesgValid(69, bibliotheque);
                            Pause(bibliotheque);
                            break;
                        case 2:
                            Langinit(bibliotheque, 2);
                            MesgValid(69, bibliotheque);
                            Pause(bibliotheque);
                            break;
                        case 3:
                            break;
                        default:
                            if(Controle('|', choix3, 1, 3)) {
                                MesgError(0002, bibliotheque);
                            } else {
                                MesgError(0001, bibliotheque);
                            }
                            Pause(bibliotheque);
                            break;
                        }
                    } while(choix3 != 3);
                    break;
                case 4:
                    break;
                default:
                    if(Controle('|', choix2, 1, 4)) {
                        MesgError(0002, bibliotheque);
                    } else {
                        MesgError(0001, bibliotheque);
                    }
                    Pause(bibliotheque);
                    break;
                }
            } while(choix2 != 4);
            break;
        case 4:
            do {
                SaisieCarac(reponse, MesgSaisie(68, bibliotheque));
                if(reponse == AffChoix(1, bibliotheque)) {
                    CloseFile(bibliotheque);
                    MesgValid(67, bibliotheque);
                } else {
                    if(reponse == AffChoix(2, bibliotheque)) {
                    } else {
                        MesgError(0002, bibliotheque);
                    }
                }
            } while(reponse != AffChoix(1, bibliotheque) && reponse != AffChoix(2, bibliotheque));
            quit = true;
            Pause(bibliotheque);
            break;
        default:
            if (Controle('|', choix1, 1, 4)) {
                MesgError(0002, bibliotheque);
            } else {
                MesgError(0001, bibliotheque);
            }
            Pause(bibliotheque);
            break;
        }
    } while (quit == false);
    return 0;
}