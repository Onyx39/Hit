#include <time.h>
#include <string>
#include <iostream>

#include "Joueur.h"

Joueur::Joueur(const std::string nom) : nom(nom) {
    audace = (float)rand() / (float)RAND_MAX;
    attention = (float)rand() / (float)RAND_MAX;
}

Joueur::Joueur(const std::string nom, float audace, float attention) : nom(nom), audace(audace), attention(attention) {}

std::string Joueur::toString() const {
    return "Joueur " + nom + " (score : " + std::to_string(score) + ") [" + std::to_string(audace) + ", " + std::to_string(attention) + "]";
}

int Joueur::comparerScore(Joueur joueur2) {
    if (score < joueur2.getScore()) {
        return -1;
    }
    if (score == joueur2.getScore()) {
        return 0;
    }
    return 1;
}

int Joueur::getScore() const {return score;}

std::string Joueur::getNom() const {return nom;}

float Joueur::getAudace() const {return audace;}

float Joueur::getAttention() const {return attention;}

void Joueur::sauvegarderCartes() {
    int scoreActuel = score;
    int nombreCartes = cartesEnCours.size();
    for (Carte carte : cartesEnCours) {
        score += carte.getValeur();
        cartesSauvegardees.push_back(carte);
    }
    cartesEnCours.empty();
    if (nombreCartes == 0) {
        std::cout << "Le joueur " << nom << " n'a pas de carte à sauvegarder" << std::endl;
    }
    else {
        std::cout << "Le joueur " << nom << " a sauvegardé " << std::to_string(nombreCartes) <<
                     " carte(s) pour une valeur de " << std::to_string(score - scoreActuel) <<
                     " points.\nSon score s'eleve maintenant à " << std::to_string(score) << std::endl; 
    }
}

