package src.classes;
import java.util.ArrayList;
import java.util.Collections;

public class Paquet {
    
    public ArrayList<Carte> cartes;

    public Paquet() {
        this.cartes = new ArrayList<Carte>();
        int nombre_occurrence = 11;
        for (int valeur = 1; valeur < 11; valeur++) {
            for (int j = 0; j < nombre_occurrence; j++) {
                this.cartes.add(new Carte(valeur));
            }
            if (valeur == 5) {
                nombre_occurrence = 7;
            }
        }
        this.melangerPaquet();
    }

    public void melangerPaquet() {
        Collections.shuffle(this.cartes);
    }

    public int getNombreCartesPioche () {
        return this.cartes.size();
    }

}
