#include "Partie.h"
#include "Joueur.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


Partie::Partie(std::vector<Joueur> joueurs) : joueurs(joueurs), joueurCourant(joueurs[0]) {}

void Partie::demarrerPartie() {
        joueurCourant = joueurs[std::rand() % joueurs.size()];
        while (true) {
            std::cout << "Tour de jeu de " << joueurCourant.getNom() << std::endl;
            tourDeJeu();
            size_t index = (std::find(joueurs.begin(), joueurs.end(), joueurCourant) - joueurs.begin() + 1) % joueurs.size();
            joueurCourant = joueurs[index];
    }
}


void Partie::tourDeJeu() {
    joueurCourant.sauvegarderCartes();
    while (true) {

        // Si le joueur a un niveau d'audace supérieur à un nombre aléatoire ou a moins de 3 cartes
        if ((float)rand() / (float)RAND_MAX < joueurCourant.getAudace() || joueurCourant.cartesEnCours.size() < 3) {
                // Piocher une carte du paquet
                Carte carte = paquet.piocherCarte();
                std::cout << "XXYNombre de cartes : " << joueurCourant.cartesEnCours.size() << std::endl;
                joueurCourant.cartesEnCours.push_back(carte);  // Ajouter la carte à la main du joueur
                std::cout << "XXZNombre de cartes : " << joueurCourant.cartesEnCours.size() << std::endl;
                std::cout << "Joueur " << joueurCourant.getNom() << " pioche une carte : " << carte.getValeur() << std::endl;

                // Vérifier si le joueur a plus de 3 cartes et si une carte est doublée
                if (joueurCourant.cartesEnCours.size() > 3 && 
                    std::count(joueurCourant.cartesEnCours.begin(), joueurCourant.cartesEnCours.end(), carte) > 1) {
                    joueurCourant.cartesEnCours.clear();  // Vider la main du joueur
                    std::cout << "Joueur " << joueurCourant.getNom() << " a perdu ses carte(s) !" << std::endl;
                    return;  // Fin de la méthode
                }

            // Si le joueur est assez attentif, il vole une carte
            if ((float)rand() / (float)RAND_MAX < joueurCourant.getAttention()) {
                volDeCarte(carte);  // Appel de la méthode pour voler une carte
            }

            // Vérifier la fin de la partie
            testFinDePartie();
        } else {
            std::cout << "Joueur " << joueurCourant.getNom() << " s'arrete" << std::endl;
            return;
        }
    }
}

void Partie::volDeCarte(Carte nouvelleCarte) {
    std::cout << "FONCTION VOLDECARTE" << std::endl;

    
    std::cout << "Affichage de joueurCourant : " << joueurCourant.getNom() << ", " << std::to_string(joueurCourant.getScore()) << std::endl;

    for (Joueur& joueur : joueurs) {
        std::cout << "Affichage du joueur : " << joueur.getNom() << ", " << std::to_string(joueur.getScore()) << std::endl;
        std::cout << "Affichage du joueur BIS: " << joueur << std::endl;
        std::cout << "Affichage du joueurCourant BIS: " << joueurCourant << std::endl;
        std::cout << "glagla " << joueur << " - " << joueurCourant << " : " << std::to_string(joueur != joueurCourant) << std::endl;
        if (joueur != joueurCourant) {
            std::cout << "Passage du col ! (" << joueur << ")" << std::endl;
            std::cout << "Nombre de cartes : " << joueur.cartesEnCours.size() << std::endl;
            std::cout << "Nouvelle carte : " << nouvelleCarte << std::endl;

            for (Carte carte : joueur.cartesEnCours) {
                std::cout << "volle " << carte << " " << nouvelleCarte << std::endl;
                if (carte == nouvelleCarte) {
                    std::cout << "VOL POSSIBLE !!! (" << carte << " - " << nouvelleCarte << ")" << std::endl;
                    for (auto it = joueur.cartesEnCours.begin(); it != joueur.cartesEnCours.end(); ++it) {
                        if (*it == carte) {
                            joueur.cartesEnCours.erase(it);
                            break;
                        }
                    }
                    joueurCourant.cartesEnCours.push_back(carte);  // Ajouter la carte au joueur courant
                    std::cout << "Le joueur " << joueurCourant.getNom() << " vole une carte "
                                << std::to_string(carte.getValeur()) << " au joueur " << joueur.getNom() << std::endl;
                }
            }
        }
    }
}

void Partie::testFinDePartie() {
    // std::cout << "coucou TEST fin de partie " << paquet.getNombreCartePioche() << std::endl;
    if (paquet.getNombreCartePioche() == 0) {
        std::cout << "IFIFIFIFIFIFIFIFIFIFIFIFIFIFIFIF" << std::endl;
        finDePartie();
    }
}

void Partie::finDePartie() {
    // Manque JOUEURS.SORT()
    std::cout << "DEBUT FIN DE PARTIE" << std::endl;
    joueurCourant.sauvegarderCartes();
    Joueur gagnant = joueurs[-1];
    std::cout << "COUCOU FIN DE PARTIE : " << gagnant << std::endl;
    for (Joueur joueur : joueurs) {
        std::cout << "JOUEUR" << std::endl;
        std::cout << joueur << std::endl;
    }
    std::cout << "Fin de partie !\nLe joueur " + gagnant.getNom() + " a gagné avec un score de " + std::to_string(gagnant.getScore()) + ")";
    exit(0);
}