#ifndef PARTIE_H
#define PARTIE_H

#include <vector>

#include "Carte.h"
#include "Paquet.h"
#include "Joueur.h"

class Partie {
public:
    Partie(std::vector<Joueur> joueurs);

    void demarrerPartie();

    void tourDeJeu();

    void volDeCarte(Carte nouvelleCarte);

    void testFinDePartie();

    void finDePartie();

private:
    Paquet paquet;
    std::vector<Joueur> joueurs;
    Joueur& joueurCourant;
};

#endif