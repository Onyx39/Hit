"""
Fichier exécutable, permet de simuler le jeu
"""

from classes.paquet import Paquet
from classes.joueur import Joueur
from classes.partie import Partie

paquet : Paquet = Paquet()
J1 : Joueur = Joueur("J1")
J2 : Joueur = Joueur("J2")
J3 : Joueur = Joueur("J3")
J4 : Joueur = Joueur("J4")

# J1.score = 10
# J2.score = 0
# J3.score = 25
# J4.score = 18

partie : Partie = Partie([J1, J2, J3, J4])
partie.demarrer_partie()
