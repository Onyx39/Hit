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

    def demarrer_partie (self) -> None :
        """
        Démarre la partie
        """
        self.joueur_courant = rd.choices(self.joueurs)[0]
        while True :
            print(f"Tour de jeu de {self.joueur_courant.nom}")
            self.tour_de_jeu()
            index : int = (self.joueurs.index(self.joueur_courant) + 1) % len(self.joueurs)
            self.joueur_courant = self.joueurs[index]

    def tour_de_jeu (self) -> None :
        """
        Simule le tour de jeu d'un joueur
        """
        self.joueur_courant.sauvegarder_cartes()
        while True :
            if rd.random() < self.joueur_courant.audace or \
                len(self.joueur_courant.carte_en_cours) < 3 :
                carte : Carte = self.paquet.cartes.pop()
                self.joueur_courant.carte_en_cours.append(carte)
                print(f"Joueur {self.joueur_courant.nom} pioche une carte : {carte}")
                if len(self.joueur_courant.carte_en_cours) > 3 and \
                    carte in self.joueur_courant.carte_en_cours[:-1] :
                    self.joueur_courant.carte_en_cours = []
                    print(f"Joueur {self.joueur_courant.nom} a perdu ses carte(s) !")
                    return None
                if rd.random() < self.joueur_courant.attention :
                    self.vol_de_carte(carte)
                self.test_fin_de_partie()
            else :
                print(f"Joueur {self.joueur_courant.nom} s'arrete")
                return None

    def vol_de_carte (self, nouvelle_carte : Carte) -> None :
        """
        Permet à un joueur de voler les cartes des autres joueurs
        """
        for joueur in self.joueurs :
            if joueur != self.joueur_courant :
                for carte in joueur.carte_en_cours :
                    if carte == nouvelle_carte :
                            joueur.carte_en_cours.remove(carte)
                            self.joueur_courant.carte_en_cours.append(carte)
                            print(f"Le joueur {self.joueur_courant.nom} vole \
une carte {carte.get_valeur()} au joueur {joueur.nom}")

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
