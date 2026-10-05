import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        // create an array of objects for singers
        ArrayList<Singer> singers = new ArrayList<>(Arrays.asList(
            new Singer("Hayley Williams", 21, "Band", "Soprano", "Bright"),
            new Singer("Gerard Way", 24, "Band", "Tenor", "Warm"),
            new Singer("Conor Mason", 13, "Band", "Tenor", "Bright")
        ));

        // create an array of objects for guitarists
        ArrayList<Guitarist> guitarists = new ArrayList<>(Arrays.asList(
            new Guitarist("Taylor York", 18, "Band", "Lead", "Fender", new ArrayList<>()),
            new Guitarist("Ray Toro", 24, "Band", "Lead", "Gibson", new ArrayList<>()),
            new Guitarist("Toru Yamashita", 20, "Band", "Rhythm", "PRS", new ArrayList<>())
        ));

        // create an array of objects for singer songwriters
        ArrayList<SingerSongwriter> singerSongwriters = new ArrayList<>(Arrays.asList(
            new SingerSongwriter("Luke Hemmings", 14, "Live", "Tenor", "Warm", "Rhythm", "Gibson", new ArrayList<>(), 120, "Pop"),
            new SingerSongwriter("Michael Clifford", 14, "Studio", "Tenor", "Bright", "Lead", "Fender", new ArrayList<>(), 90, "Pop"),
            new SingerSongwriter("Gaon", 4, "Live", "Tenor", "Bright", "Rhythm", "Ibanez", new ArrayList<>(), 25, "Rock")
        ));

        // create an array of objects for guitars
        ArrayList<Guitar> guitars = new ArrayList<>(Arrays.asList(
            new Guitar("Fender", "Electric", "D'Addario", "Steel"),
            new Guitar("Gibson", "Acoustic", "Ernie Ball", "Steel"),
            new Guitar("PRS", "Electric", "Elixir", "Steel"),
            new Guitar("Gibson", "Acoustic", "Martin", "Steel"),
            new Guitar("Fender", "Electric", "D'Addario", "Steel"),
            new Guitar("Ibanez", "Acoustic", "Ernie Ball", "Steel")
        ));

        // add guitars to the list of guitars in guitarists
        guitarists.get(0).addGuitar(guitars.get(0));
        guitarists.get(1).addGuitar(guitars.get(1));
        guitarists.get(2).addGuitar(guitars.get(2));

        // add guitars to the list of guitars in singer songwriters
        singerSongwriters.get(0).addGuitar(guitars.get(3));
        singerSongwriters.get(1).addGuitar(guitars.get(4));
        singerSongwriters.get(2).addGuitar(guitars.get(5));

        // combine the children and grandchildren to musicians list
        ArrayList<Musician> musicians = new ArrayList<>();
        for (int i = 0; i < singers.size(); i++) {
            musicians.add(singers.get(i));
        }
        for (int i = 0; i < guitarists.size(); i++) {
            musicians.add(guitarists.get(i));
        }
        for (int i = 0; i < singerSongwriters.size(); i++) {
            musicians.add(singerSongwriters.get(i));
        }

        // print welcome message
        System.out.println("                     _      _                   ");
        System.out.println(" _ __ ___  _   _ ___(_) ___(_) __ _ _ __  ____  ");
        System.out.println("| '_ ` _ \\| | | |_  / |/ __| |/ _` | '_ \\|_  /  ");
        System.out.println("| | | | | | |_| |/ /| | (__| | (_| | | | |/ / _ ");
        System.out.println("|_| |_| |_\\__,_ /___|_|\\___|_|\\__,_|_| |_/___(_)");

        double delay = 1.0;
        sleepDelay(delay);
        System.out.print("\nFetching data");
        sleepDelay(delay);
        System.out.print(" . ");
        sleepDelay(delay);
        System.out.print(" . ");
        sleepDelay(delay);
        System.out.println(" . \n");
        sleepDelay(delay);

        // print guitars data
        printGuitars(guitars, delay);
        // print musicians data
        printMusicians(musicians, delay);

        System.out.print("Loading ");
        sleepDelay(delay);
        System.out.print(" . ");
        sleepDelay(delay);
        System.out.print(" . ");
        sleepDelay(delay);
        System.out.println(" . \n");
        sleepDelay(delay);

        System.out.println("New data found!");
        sleepDelay(delay);
        System.out.print("Adding new data");
        sleepDelay(delay);
        System.out.print(" . ");
        sleepDelay(delay);
        System.out.print(" . ");
        sleepDelay(delay);
        System.out.println(" . \n");

        // simulate adding new data statically
        singerSongwriters.add(new SingerSongwriter("Taka Moriuchi", 20, "Live", "Tenor", "Bright", "Rhythm", "Gibson", new ArrayList<>(), 80, "Rock"));
        guitars.add(new Guitar("Gibson", "Electric", "D'Addario", "Steel"));
        singerSongwriters.get(singerSongwriters.size() - 1).addGuitar(guitars.get(guitars.size() - 1));
        guitars.add(new Guitar("Gibson", "Acoustic", "Elixir", "Steel"));
        singerSongwriters.get(singerSongwriters.size() - 1).addGuitar(guitars.get(guitars.size() - 1));

        // rebuild the musicians list
        musicians.clear();
        for (int i = 0; i < singers.size(); i++) {
            musicians.add(singers.get(i));
        }
        for (int i = 0; i < guitarists.size(); i++) {
            musicians.add(guitarists.get(i));
        }
        for (int i = 0; i < singerSongwriters.size(); i++) {
            musicians.add(singerSongwriters.get(i));
        }

        // print guitars data after adding new data
        printGuitars(guitars, delay);
        // print musicians data after adding new data
        printMusicians(musicians, delay);

        System.out.println("Exiting program.");
        sleepDelay(delay);
    }

    // function to simulate delay
    private static void sleepDelay(double seconds) {
        System.out.flush();
        try {
            Thread.sleep((long) (seconds * 1000));
        }
        catch (InterruptedException exception) {
            Thread.currentThread().interrupt();
        }
    }

    // function to print musicians data
    private static void printMusicians(ArrayList<Musician> musicians, double delay) {
        System.out.println("============================================");
        System.out.println("             __     __               __ ");
        System.out.println("  |\\/| |  | /__` | /  ` |  /\\  |\\ | /__`");
        System.out.println("  |  | \\__/ .__/ | \\__, | /~~\\ | \\| .__/");
        System.out.println("\n============================================");
        sleepDelay(delay);

        // variable to keep track of current class
        String currentClass = "";
        int number = 1;

        for (int i = 0; i < musicians.size(); i++) {
            Musician musician = musicians.get(i);

            // get the class of the current musician
            // SingerSongwriter is checked first since it is also a Singer
            String musicianClass = "Unknown";
            if (musician instanceof SingerSongwriter) {
                musicianClass = "SingerSongwriter";
            } else if (musician instanceof Singer) {
                musicianClass = "Singer";
            } else if (musician instanceof GuitaristTrait) {
                musicianClass = "Guitarist";
            }

            // if the class of the current musician is different from the previous musician
            // print the class name as a title and reset the number
            if (!musicianClass.equals(currentClass)) {
                currentClass = musicianClass;
                number = 1;
                System.out.println("\n" + musicianClass + ":");
            }
            sleepDelay(delay);

            // print each data
            System.out.println(number + ". Name: " + musician.getName());
            System.out.println("   Years of Experience: " + musician.getYearsOfExperience());
            System.out.println("   Performance Type: " + musician.getPerformanceType());

            // if musician is singer songwriter, print additional data
            if (musician instanceof SingerSongwriter) {
                SingerSongwriter ss = (SingerSongwriter) musician;
                System.out.println("   Vocal Range: " + ss.getVocalRange());
                System.out.println("   Tone: " + ss.getTone());
                System.out.println("   Position: " + ss.getPosition());
                System.out.println("   Favorite Guitar Brand: " + ss.getFavoriteBrand());
                System.out.println("   Guitars:");
                // print guitars list
                ArrayList<Guitar> guitars = ss.getGuitars();
                for (int j = 0; j < guitars.size(); j++) {
                    System.out.println("      - " + guitars.get(j).getBrand() + " " + guitars.get(j).getType());
                }
                System.out.println("   Songs Written: " + ss.getSongsWritten());
                System.out.println("   Writing Genre: " + ss.getWritingGenre());
            }
            // if musician is singer, print additional data
            else if (musician instanceof Singer) {
                Singer singer = (Singer) musician;
                System.out.println("   Vocal Range: " + singer.getVocalRange());
                System.out.println("   Tone: " + singer.getTone());
            }
            // if musician is guitarist, print additional data
            else if (musician instanceof GuitaristTrait) {
                GuitaristTrait guitarist = (GuitaristTrait) musician;
                System.out.println("   Position: " + guitarist.getPosition());
                System.out.println("   Favorite Guitar Brand: " + guitarist.getFavoriteBrand());
                System.out.println("   Guitars:");
                // print guitars list
                ArrayList<Guitar> guitars = guitarist.getGuitars();
                for (int j = 0; j < guitars.size(); j++) {
                    System.out.println("      - " + guitars.get(j).getBrand() + " " + guitars.get(j).getType());
                }
            }

            System.out.println();
            number++;
            sleepDelay(delay);
        }
    }

    // function to print guitars data
    private static void printGuitars(ArrayList<Guitar> guitars, double delay) {
        System.out.println("=====================================");
        System.out.println("   __         ___       __   __ ");
        System.out.println("  / _` |  | |  |   /\\  |__) /__`");
        System.out.println("  \\__> \\__/ |  |  /~~\\ |  \\ .__/");
        System.out.println("\n=====================================\n");
        sleepDelay(delay);

        int number = 1;
        // print each data
        for (int i = 0; i < guitars.size(); i++) {
            System.out.println(number + ". Brand: " + guitars.get(i).getBrand());
            System.out.println("   Type: " + guitars.get(i).getType());
            System.out.println("   Strings:");
            // print guitar strings
            ArrayList<GuitarString> strings = guitars.get(i).getStrings();
            for (int j = 0; j < strings.size(); j++) {
                System.out.println("      - Brand: " + strings.get(j).getStringBrand()
                    + ", Material: " + strings.get(j).getMaterial()
                    + ", Gauge: " + strings.get(j).getStringGauge());
            }
            System.out.println();
            number++;
            sleepDelay(delay);
        }
    }
}
