"""
Classe représentant lune partie de jeu
"""

import random  as rd
import sys

from classes.carte import Carte
from classes.joueur import Joueur
from classes.paquet import Paquet

class Partie :
    """
    Partie de jeu Hit!
    """

    def __init__ (self, joueurs : list[Joueur]) -> None :
        self.joueurs : list[Joueur] = joueurs
        self.paquet : Paquet = Paquet()

    def demarrer_partie (self) :
        """
        Démarre la partie
        """
        joueur_courant : Joueur = rd.choices(self.joueurs)[0]
        print(joueur_courant)
        while True :
            print(f"Tour de jeu de {joueur_courant.nom}")
            self.tour_de_jeu(joueur_courant)
            print(self.joueurs.index(joueur_courant), self.joueurs.index(joueur_courant) + 1)
            joueur_courant = self.joueurs[(self.joueurs.index(joueur_courant) + 1) % 4]


    def tour_de_jeu (self, joueur : Joueur) -> None :
        """
        Simule le tour de jeu d'un joueur
        """
        carte : Carte = self.paquet.cartes.pop()
        joueur.carte_en_cours.append(carte)
        self.test_fin_de_partie()

    def test_fin_de_partie (self) -> None :
        """
        Teste si le paquet est épuisé
        """
        if self.paquet.get_nombre_cartes_pioche() == 0 :
            self.fin_de_partie()

    def fin_de_partie (self) -> None :
        """
        Termine la partie lorsque le paquet est épuisé
        """
        self.joueurs.sort()
        gagnant : Joueur = self.joueurs[-1]
        for joueur in self.joueurs :
            print(joueur)
        print(f"Fin de partie !\nLe joueur {gagnant.nom} a gagné avec un score de {gagnant.score}")
        sys.exit()
