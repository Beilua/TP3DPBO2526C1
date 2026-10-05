import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Map;

// class to represent a guitar
public class Guitar {
    // private attributes
    private String brand;
    private String type;
    private ArrayList<GuitarString> strings;

    // default gauges for electric and acoustic guitars
    private static final Map<String, List<String>> defaultGauges = Map.of(
        "Electric", List.of("0.010", "0.013", "0.017", "0.026", "0.036", "0.046"),
        "Acoustic", List.of("0.012", "0.016", "0.024", "0.032", "0.042", "0.053")
    );

    // empty constructor
    public Guitar() {
        this.strings = new ArrayList<>();
    }

    // constructor with parameters (without custom gauges, uses defaults)
    public Guitar(String brand, String type, String stringBrand, String material) {
        this(brand, type, stringBrand, material, null);
    }

    // constructor with parameters
    public Guitar(String brand, String type, String stringBrand, String material, List<String> gauges) {
        this.brand = brand;
        this.type = type;

        // use default gauges if none are provided
        if (gauges == null || gauges.isEmpty()) {
            gauges = defaultGauges.get(type);
        }
        if (gauges == null || gauges.isEmpty()) {
            throw new IllegalArgumentException("A custom gauge set is required for this guitar type");
        }
        setStrings(makeStringData(stringBrand, material, gauges));
    }

    // method to make string data based on the provided string brand, material, and gauges
    public ArrayList<String[]> makeStringData(String stringBrand, String material, List<String> gauges) {
        ArrayList<String[]> stringData = new ArrayList<>();
        for (int i = 0; i < gauges.size(); i++) {
            stringData.add(new String[]{stringBrand, material, gauges.get(i)});
        }
        return stringData;
    }

    // brand getter and setter
    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    // type getter and setter
    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    // strings getter and setter
    public ArrayList<GuitarString> getStrings() {
        return strings;
    }

    public void setStrings(ArrayList<String[]> stringData) {
        // error handling if string is not 6
        if (stringData.size() != 6) {
            throw new IllegalArgumentException("A guitar must have exactly 6 strings");
        }

        // error handling if string gauge is not unique
        HashSet<String> seenGauges = new HashSet<>();
        for (int i = 0; i < stringData.size(); i++) {
            seenGauges.add(stringData.get(i)[2]);
        }
        if (seenGauges.size() != 6) {
            throw new IllegalArgumentException("Each string must have a different gauge");
        }

        strings = new ArrayList<>();
        for (int i = 0; i < stringData.size(); i++) {
            strings.add(new GuitarString(stringData.get(i)[0], stringData.get(i)[1], stringData.get(i)[2]));
        }
    }
}
