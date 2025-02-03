"""
Classe représentant une carte
"""

class Carte :
    """
    Carte du jeu Hit!
    """

    def __init__ (self, valeur : int) -> None:
        self.valeur  : int = valeur

    def __str__ (self) -> str :
        return f"Carte {self.valeur}"

    def get_valeur (self) -> int :
        """
        Permet de récupérer la valeur d'une carte
        """
        return self.valeur
