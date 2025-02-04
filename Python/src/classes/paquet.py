"""
Classe représentant le paquet de carte du jeu
"""

import random as rd

from classes.carte import Carte

class Paquet :
    """
    Paquet de carte du jeu Hit!
    """
    def __init__ (self) -> None :
        self.cartes : list[Carte] = []
        nombre_occurrence = 11
        for valeur in range (1, 11) :
            for _ in range (nombre_occurrence) :
                self.cartes.append(Carte(valeur))
            if valeur == 5 :
                nombre_occurrence = 7
        self.melenger_paquet()

    def melenger_paquet (self) -> None :
        """
        Permet de mélanger les cartes du paquet
        """
        rd.shuffle(self.cartes)

    def get_nombre_cartes_pioche (self) -> int :
        """
        Donne le nombre de cartes restantes dans la pioche
        """
        return len(self.cartes)
