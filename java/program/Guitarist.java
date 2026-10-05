import java.util.ArrayList;

// class to represent a guitarist inheriting from Musician class
public class Guitarist extends Musician implements GuitaristTrait {
    // private attributes
    private String position;
    private String favoriteBrand;
    private ArrayList<Guitar> guitars;

    // empty constructor
    public Guitarist() {
        this.guitars = new ArrayList<>();
    }

    // constructor with all attributes from both parent and child classes
    public Guitarist(String name, int yearsOfExperience, String performanceType,
            String position, String favoriteBrand, ArrayList<Guitar> guitars) {
        setName(name);
        setYearsOfExperience(yearsOfExperience);
        setPerformanceType(performanceType);
        this.position = position;
        this.favoriteBrand = favoriteBrand;
        this.guitars = (guitars != null) ? new ArrayList<>(guitars) : new ArrayList<>();
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
}
