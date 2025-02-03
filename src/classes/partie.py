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
        self.joueur_courant : Joueur = None

    def demarrer_partie (self) :
        """
        Démarre la partie
        """
        self.joueur_courant = rd.choices(self.joueurs)[0]
        while True :
            print(f"Tour de jeu de {self.joueur_courant.nom}")
            self.tour_de_jeu()
            self.joueur_courant = self.joueurs[(self.joueurs.index(self.joueur_courant) + 1) % 4]


    def tour_de_jeu (self) -> None :
        """
        Simule le tour de jeu d'un joueur
        """
        probabilite : float = 0.80
        self.joueur_courant.sauvegarder_cartes()
        while True :
            if rd.random() < probabilite or len(self.joueur_courant.carte_en_cours) < 3 :
                carte : Carte = self.paquet.cartes.pop()
                self.joueur_courant.carte_en_cours.append(carte)
                print(f"Joueur {self.joueur_courant.nom} pioche une carte : {carte}")
                if len(self.joueur_courant.carte_en_cours) > 3 and \
                    carte in self.joueur_courant.carte_en_cours[:-1] :
                    self.joueur_courant.carte_en_cours = []
                    print(f"Joueur {self.joueur_courant.nom} a perdu ses carte(s) !")
                    return None
                self.test_fin_de_partie()
            else :
                print(f"Joueur {self.joueur_courant.nom} s'arrete")
                # for carte in joueur.carte_en_cours :
                #     print(carte)
                # joueur.sauvegarder_cartes()
                return None

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
        self.joueur_courant.sauvegarder_cartes()
        self.joueurs.sort()
        gagnant : Joueur = self.joueurs[-1]
        for joueur in self.joueurs :
            print(joueur)
        print(f"Fin de partie !\nLe joueur {gagnant.nom} a gagné avec un score de {gagnant.score}")
        sys.exit()
