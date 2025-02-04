import sys
import os

sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '../src')))

from classes.carte import Carte

import unittest


class CarteTest(unittest.TestCase):

    def setUp(self):
        self.carte1 = Carte(3)
        self.carte2 = Carte(5)
        self.carte3 = Carte(3)

    def test_to_string(self):
        self.assertEqual(str(self.carte1), "Carte 3")
        self.assertEqual(str(self.carte2), "Carte 5")

    def test_get_valeur(self):
        self.assertEqual(self.carte1.get_valeur(), 3)
        self.assertEqual(self.carte2.get_valeur(), 5)

    def test_equals(self):
        self.assertFalse(self.carte1 == self.carte2)  # Compare les objets
        self.assertTrue(self.carte1 == self.carte3)   # Compare les objets

if __name__ == '__main__':
    unittest.main()
