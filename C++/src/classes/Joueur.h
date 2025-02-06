#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <string>
#include "Carte.h"

class Joueur {
public:

    std::vector<Carte> cartesEnCours;
    std::vector<Carte> cartesSauvegardees;


    Joueur(std::string nom);
    Joueur(std::string nom, float audace, float attention);

    std::string toString() const;

    int comparerScore(Joueur joueur2);

    void sauvegarderCartes();

    int getScore() const;

    std::string getNom() const;

    float getAudace() const;

    float getAttention() const;

    // Surcharge de l'opérateur << pour la classe Joueur
    friend std::ostream& operator<<(std::ostream& os, const Joueur& joueur) {
        os << "Joueur " + joueur.nom << " (score : " << std::to_string(joueur.score) << ") ["
           << std::to_string(joueur.audace) << ", " << std::to_string(joueur.attention) << "]";
        return os; // Retourne le flux pour permettre l'enchaînement
    }

    // Surcharge de l'opérateur != pour comparer deux objets Joueur
    bool operator!=(const Joueur& autre) const {
        return nom != autre.nom;
    }

    // Surcharge de l'opérateur ==
    bool operator==(const Joueur& autre) const {
        return nom == autre.nom;
    }

private:
    std::string nom;
    int score = 0;
    float audace;
    float attention;
};

#endif