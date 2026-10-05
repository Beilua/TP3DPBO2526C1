import java.util.ArrayList;

// interface to represent the guitarist side of the diamond inheritance
// workaround for Java single inheritance: Guitarist and SingerSongwriter implement this
public interface GuitaristTrait {
    String getPosition();
    void setPosition(String position);

    String getFavoriteBrand();
    void setFavoriteBrand(String favoriteBrand);

    ArrayList<Guitar> getGuitars();
    void setGuitars(ArrayList<Guitar> guitars);

    // method to add new guitar to existing list of guitars
    void addGuitar(Guitar guitar);
}
