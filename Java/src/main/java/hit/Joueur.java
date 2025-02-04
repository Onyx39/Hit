package hit;
import java.util.ArrayList;

public class Joueur implements Comparable<Joueur> {

    private String nom;
    private float audace = Float.NaN;
    private float attention = Float.NaN;
    private int score = 0;
    public ArrayList<Carte> cartesEnCours = new ArrayList<Carte>();
    public ArrayList<Carte> cartesSauvegardees = new ArrayList<Carte>();
    
    public Joueur(String nom) {
        this.nom = nom;
        this.audace = Math.round(Math.random() * 100) / 100;
        this.attention = Math.round(Math.random() * 100) / 100;
    }

    public Joueur(String nom, float audace, float attention) {
        this.nom = nom;
        this.audace = audace;
        this.attention = attention;      
    }

    public void sauvegarderCartes () {
        int score_actuel = this.score;
        int nombre_cartes = this.cartesEnCours.size();
        for (Carte carte : this.cartesEnCours) {
            this.score += carte.getValeur();
            this.cartesSauvegardees.add(carte);
        }
        this.cartesEnCours = new ArrayList<Carte>();
        if (nombre_cartes == 0) {
            System.out.println(String.format("Le joueur %s n'a pas de cartes à sauvegarder", this.nom));
        }
        else {
            System.out.println(String.format("Le joueur %s a sauvegardé %d carte(s) pour une valeur de %d points.\nSon score s'éléve maintenant à %d", this.nom, nombre_cartes, this.score - score_actuel, this.score));
        }
    }

    @Override
    public int compareTo(Joueur autre) {
        if (this.score < autre.score) {
            return -1;
        } else if (this.score > autre.score) {
            return 1;
        } else {
            return 0;
        }
    }

    @Override
    public String toString() {
        return String.format("Joueur %s (score : %d) [%f, %f]", this.nom, this.score, this.audace, this.attention);
    }

    public String getNom () {
        return this.nom;
    }

    public int getScore() {
        return this.score;
    }

    public float getAudace() {
        return this.audace;
    }

    public float getAttention() {
        return this.attention;
    }

}
