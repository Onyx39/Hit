#include <iostream>
#include <cassert>
#include "../src/classes/Carte.h"

void testCarte() {
    // Test de construction
    Carte carte1(5);
    assert(carte1.getValeur() == 5);
    
    // Test de la méthode toString()
    assert(carte1.toString() == "Carte 5");
    
    // Test de l'opérateur ==
    Carte carte2(5);
    assert(carte1 == carte2);
    
    Carte carte3(10);
    assert(!(carte1 == carte3));
    
    std::cout << "Tous les tests Carte.cpp ont réussi !" << std::endl;
}

// int main() {
//     testCarte();
//     return 0;
// }
