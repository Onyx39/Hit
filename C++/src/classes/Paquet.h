#ifndef PAQUET_H
#define PAQUET_H

#include <vector>
#include "Carte.h"

class Paquet {
public:
    Paquet(); // Constructeur

    void melangerPaquet();

    int getNombreCartePioche() const;

    Carte piocherCarte();

private:
    std::vector<Carte> cartes;
};

#endif