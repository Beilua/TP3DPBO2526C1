import java.util.ArrayList;

// class to represent a singer songwriter inheriting from Singer class
// and implementing GuitaristTrait as a workaround for multiple inheritance
public class SingerSongwriter extends Singer implements GuitaristTrait {
    // private attributes
    private String position;
    private String favoriteBrand;
    private ArrayList<Guitar> guitars;
    private int songsWritten;
    private String writingGenre;

    // empty constructor
    public SingerSongwriter() {
        this.guitars = new ArrayList<>();
    }

    // constructor with all attributes
    public SingerSongwriter(String name, int yearsOfExperience, String performanceType,
            String vocalRange, String tone, String position,
            String favoriteBrand, ArrayList<Guitar> guitars,
            int songsWritten, String writingGenre) {
        setName(name);
        setYearsOfExperience(yearsOfExperience);
        setPerformanceType(performanceType);
        setVocalRange(vocalRange);
        setTone(tone);
        this.position = position;
        this.favoriteBrand = favoriteBrand;
        this.guitars = (guitars != null) ? new ArrayList<>(guitars) : new ArrayList<>();
        this.songsWritten = songsWritten;
        this.writingGenre = writingGenre;
    }

    // position getter and setter
    public String getPosition() {
        return position;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    // favoriteBrand getter and setter
    public String getFavoriteBrand() {
        return favoriteBrand;
    }

    public void setFavoriteBrand(String favoriteBrand) {
        this.favoriteBrand = favoriteBrand;
    }

    // guitars getter and setter
    public ArrayList<Guitar> getGuitars() {
        return guitars;
    }

    public void setGuitars(ArrayList<Guitar> guitars) {
        this.guitars = guitars;
    }

    // method to add new guitar to existing list of guitars
    public void addGuitar(Guitar guitar) {
        guitars.add(guitar);
    }

    // songsWritten getter and setter
    public int getSongsWritten() {
        return songsWritten;
    }

    public void setSongsWritten(int songsWritten) {
        this.songsWritten = songsWritten;
    }

    // writingGenre getter and setter
    public String getWritingGenre() {
        return writingGenre;
    }

    public void setWritingGenre(String writingGenre) {
        this.writingGenre = writingGenre;
    }
}
