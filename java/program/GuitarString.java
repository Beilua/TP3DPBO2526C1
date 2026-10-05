// class to represent a guitar string
public class GuitarString {
    // private attributes
    private String stringBrand;
    private String material;
    private String stringGauge;

    // empty constructor
    public GuitarString() {
    }

    // constructor with parameters
    public GuitarString(String stringBrand, String material, String stringGauge) {
        this.stringBrand = stringBrand;
        this.material = material;
        this.stringGauge = stringGauge;
    }

    // stringBrand getter and setter
    public String getStringBrand() {
        return stringBrand;
    }

    public void setStringBrand(String stringBrand) {
        this.stringBrand = stringBrand;
    }

    // material getter and setter
    public String getMaterial() {
        return material;
    }

    public void setMaterial(String material) {
        this.material = material;
    }

    // stringGauge getter and setter
    public String getStringGauge() {
        return stringGauge;
    }

    public void setStringGauge(String stringGauge) {
        this.stringGauge = stringGauge;
    }
}
