package src.classes;
public class Carte {

    private int valeur;
    
    public Carte(int valeur) {
        this.valeur = valeur;
    }

    public int getValeur() {
        return valeur;
    }

    @Override
    public boolean equals(Object autre) {
        if (this == autre) {
            return true;
        }

        if (autre == null || getClass() != autre.getClass()) {
            return false;
        }

        Carte other = (Carte) autre;

        return this.valeur == other.valeur;
    }

    @Override
    public String toString() {
        return "Carte " + this.valeur;
    }
}
