#ifndef CARTE_H
#define CARTE_H


#include <iostream>

class Carte {
public:
    Carte(int valeur);  // Constructeur

    std::string toString() const;  // Méthode pour afficher la carte

    bool operator==(const Carte& autre) const;  // Comparaison de cartes

    int getValeur() const;  // Retourne la valeur de la carte

    // Surcharge de l'opérateur << pour afficher l'objet Carte
    friend std::ostream& operator<<(std::ostream& os, const Carte& carte) {
        os << "Carte " << carte.valeur;  // Affiche "Carte [valeur]"
        return os;  // Retourne le flux pour permettre l'enchaînement
    }

private:
    int valeur;
};

#endif
