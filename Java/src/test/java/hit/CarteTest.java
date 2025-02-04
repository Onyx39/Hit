package hit;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

public class CarteTest {

    private static Carte carte1;
    private static Carte carte2;
    private static Carte carte3;
    
    @BeforeAll
    public static void init() {
        carte1 = new Carte(3);
        carte2 = new Carte(5);
        carte3 = new Carte(3);
    }

    @Test
    public void toStringTest() {
        assertEquals(carte1.toString(), "Carte 3");
        assertEquals(carte2.toString(), "Carte 5");
    }

    @Test
    public void getValeurTest() {
        assertEquals(carte1.getValeur(), 3);
        assertEquals(carte2.getValeur(), 5);
    } 

    @Test
    public void equalsTest() {
        assertFalse(carte1.equals(carte2));
        assertTrue(carte1.equals(carte3));
    }
}
