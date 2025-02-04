"""
Fichier exécutable, permet de simuler le jeu
"""

from classes.joueur import Joueur
from classes.partie import Partie

J1 : Joueur = Joueur("J1", attention=1)
J2 : Joueur = Joueur("J2", attention=1)
J3 : Joueur = Joueur("J3", attention=1)
J4 : Joueur = Joueur("J4", attention=1)

partie : Partie = Partie([J1, J2, J3, J4])
partie.demarrer_partie()
