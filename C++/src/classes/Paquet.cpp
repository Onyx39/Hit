#include <iostream>
#include <algorithm>
#include <random>
#include "Paquet.h"

Paquet::Paquet() {
    int nombreOccurence = 11;
    for (int valeur = 1; valeur < 11; valeur++) {
        for (int i = 0; i < nombreOccurence; i++) {
            cartes.push_back(Carte(valeur));
        }
        if (valeur == 5) {
            nombreOccurence = 7;
        }
    }
    melangerPaquet();
    // for (Carte carte : cartes) {
    //     std::cout << carte << " ";
    // }
}

void Paquet::melangerPaquet() {
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(cartes.begin(), cartes.end(), g);
}

Carte Paquet::piocherCarte() {
    Carte carte = cartes.back();
    cartes.pop_back();
    return carte;
}

int Paquet::getNombreCartePioche() const {
    return Paquet::cartes.size();
}