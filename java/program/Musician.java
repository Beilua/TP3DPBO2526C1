// class to represent a musician
public class Musician {
    // private attributes
    private String name;
    private int yearsOfExperience;
    private String performanceType;

    // empty constructor
    public Musician() {
    }

    // constructor with parameters
    public Musician(String name, int yearsOfExperience, String performanceType) {
        this.name = name;
        this.yearsOfExperience = yearsOfExperience;
        this.performanceType = performanceType;
    }

    // name getter and setter
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    // yearsOfExperience getter and setter
    public int getYearsOfExperience() {
        return yearsOfExperience;
    }

    public void setYearsOfExperience(int yearsOfExperience) {
        this.yearsOfExperience = yearsOfExperience;
    }

    // performanceType getter and setter
    public String getPerformanceType() {
        return performanceType;
    }

    public void setPerformanceType(String performanceType) {
        this.performanceType = performanceType;
    }
}
