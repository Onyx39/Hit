package hit;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Joueur J1 = new Joueur("J1");
        Joueur J2 = new Joueur("J2");
        Joueur J3 = new Joueur("J3");
        Joueur J4 = new Joueur("J4");
        
        ArrayList<Joueur> joueurs = new ArrayList<>();

        joueurs.add(J1);
        joueurs.add(J2);
        joueurs.add(J3);
        joueurs.add(J4);

        Partie partie = new Partie(joueurs);
        partie.demarrerPartie();
    }
}