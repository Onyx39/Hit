#include <vector>

#include "classes/Carte.h"
#include "classes/Paquet.h"
#include "classes/Joueur.h"
#include "classes/Partie.h"

int main() {
    // Carte carte1(5);
    // Carte carte2(5);
    // Carte carte3(10);

    // std::cout << carte1.toString() << std::endl;
    // std::cout << (carte1 == carte2 ? "Elles sont egales" : "Elles sont differentes") << std::endl;
    // std::cout << (carte1 == carte3 ? "Elles sont egales" : "Elles sont differentes") << std::endl;

    // Paquet paquet;
    // std::cout << paquet.getNombreCartePioche() << std::endl; 

    Joueur J1("J1");
    Joueur J2("J2");
    Joueur J3("J3");
    Joueur J4("J4");

    std::vector<Joueur> joueurs = {J1, J2, J3, J4};

    Partie partie(joueurs);
    partie.demarrerPartie();

    return 0;
}
