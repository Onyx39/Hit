"""
Classe représentant un joueur
"""

import random as rd

from classes.carte import Carte

class Joueur :
    """
    Joueur du jeu Hit!
    """

    def __init__ (self, nom : str, audace : float = None, attention : float = None) -> None :
        self.nom :  str = nom
        self.score : int = 0
        if audace is None :
            self.audace : float = round(rd.random(), 2)
        else :
            self.audace = audace
        if attention is None :
            self.attention : float = round(rd.random(), 2)
        else :
            self.attention = attention
        self.carte_en_cours : list[Carte]= []
        self.cartes_sauvegardees : list[Carte] = []

    def __str__ (self) -> str :
        return f"Joueur {self.nom} (score : {self.score}) [{self.audace}, {self.attention}]"

    def __lt__ (self, autre) -> bool :
        if self.score < autre.score :
            return True
        return False

    def sauvegarder_cartes (self) -> None :
        """
        Permet à un joueur de sauvegarder les cartes qu'iel a conservé pendant un tour
        """
        score_actuel : int = self.score
        nombre_cartes : int = len(self.carte_en_cours)
        for carte in self.carte_en_cours :
            self.score += carte.get_valeur()
            self.cartes_sauvegardees.append(carte)
        self.carte_en_cours = []
        if nombre_cartes == 0 :
            print(f"Le joueur {self.nom} n'a pas de cartes à sauvegarder")
        else :
            print(f"Le joueur {self.nom} a sauvegardé {nombre_cartes} carte(s) \
pour une valeur de {self.score - score_actuel} points.\n\
Son score s'éléve maintenant à {self.score}")
