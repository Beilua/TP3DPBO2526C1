// class to represent a singer inheriting from Musician class
public class Singer extends Musician {
    // private attributes
    private String vocalRange;
    private String tone;

    // empty constructor
    public Singer() {
    }

    // constructor with all attributes from both parent and child classes
    public Singer(String name, int yearsOfExperience, String performanceType,
            String vocalRange, String tone) {
        setName(name);
        setYearsOfExperience(yearsOfExperience);
        setPerformanceType(performanceType);
        this.vocalRange = vocalRange;
        this.tone = tone;
    }

    // vocalRange getter and setter
    public String getVocalRange() {
        return vocalRange;
    }

    public void setVocalRange(String vocalRange) {
        this.vocalRange = vocalRange;
    }

    // tone getter and setter
    public String getTone() {
        return tone;
    }

    public void setTone(String tone) {
        this.tone = tone;
    }
}
