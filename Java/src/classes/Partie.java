package src.classes;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class Partie {

    private Paquet paquet = new Paquet();
    private ArrayList<Joueur> joueurs;
    private Joueur joueurCourant;

    public Partie(ArrayList<Joueur> joueurs) {
        this.joueurs = joueurs;
    }

    public void demarrerPartie() {
        Random random = new Random();
        this.joueurCourant = joueurs.get(random.nextInt(joueurs.size()));
        System.out.println("Premier joueur : " + this.joueurCourant);
        while (true) {
            System.out.println(String.format("Tour de jeu de %s", this.joueurCourant.getNom()));
            tourDeJeu();
            int index = (joueurs.indexOf(joueurCourant) + 1) % joueurs.size();
            joueurCourant = joueurs.get(index);
        }
    }

    public int tourDeJeu() {
        this.joueurCourant.sauvegarderCartes();
        while (true) {
            if (Math.random() < this.joueurCourant.getAudace() ||
                this.joueurCourant.cartesEnCours.size() < 3) {
                    Carte carte = this.paquet.cartes.get(0);
                    this.paquet.cartes.remove(0);
                    this.joueurCourant.cartesEnCours.add(carte);
                    System.out.println(String.format("Joueur %s pioche une carte : %s", this.joueurCourant.getNom(), carte));
                    if (this.joueurCourant.cartesEnCours.size() > 3 &&
                        this.joueurCourant.cartesEnCours.subList(0, this.joueurCourant.cartesEnCours.size() - 1).contains(carte)) {
                            this.joueurCourant.cartesEnCours = new ArrayList<Carte>();
                            System.out.println(String.format("Joueur %d a perdu ses carte(s) !", this.joueurCourant.getNom()));
                            return 0;
                    }
                    if (Math.random() < this.joueurCourant.getAttention()) {
                        volDeCarte(carte);
                    }
                    testFinDePartie();
                } 
            else {
                System.out.println(String.format("Joueur %s s'arrete", this.joueurCourant.getNom()));
                return 0;
            }
        }
    }

    public void volDeCarte(Carte nouvelleCarte) {
        for (Joueur joueur : this.joueurs) {
            if (!joueur.equals(this.joueurCourant)) {
                for (Carte carte : joueur.cartesEnCours) {
                    if (carte == nouvelleCarte) {
                        joueur.cartesEnCours.remove(carte);
                        this.joueurCourant.cartesEnCours.add(carte);
                        System.out.println(String.format("Le joueur %s vole une carte %d au joueur %s", this.joueurCourant.getNom(), carte.getValeur(), joueur.getNom()));
                    }
                }
            }
        }
    }

    public void testFinDePartie() {
        if (this.paquet.getNombreCartesPioche() == 0) {
            finDePartie();
        }
    }

    public void finDePartie() {
        this.joueurCourant.sauvegarderCartes();
        Collections.sort(this.joueurs);
        Joueur gagnant = this.joueurs.get(this.joueurs.size() - 1);
        for (Joueur joueur : this.joueurs) {
            System.out.println(joueur);
        }
        System.out.println(String.format("Fin de partie !\nLe joueur %s a gagné avec un score de %d", gagnant.getNom(), gagnant.getScore()));
        System.exit(0);
    }
 
}
