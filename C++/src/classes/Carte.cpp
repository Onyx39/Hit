#include "Carte.h"
#include <string>

Carte::Carte(int valeur) : valeur(valeur) {}

std::string Carte::toString() const {
    return "Carte " + std::to_string(valeur);
}

bool Carte::operator==(const Carte& autre) const {
    return this->valeur == autre.valeur;
}

int Carte::getValeur() const {
    return valeur;
}
