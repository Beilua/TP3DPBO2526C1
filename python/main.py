import time # library for delay

# import classes
from Guitar import Guitar
from Singer import Singer
from Guitarist import Guitarist
from SingerSongwriter import SingerSongwriter


def main():
    # create an array of objects for singers
    singers = [
        Singer("Hayley Williams", 21, "Band", "Soprano", "Bright"),
        Singer("Gerard Way", 24, "Band", "Tenor", "Warm"),
        Singer("Conor Mason", 13, "Band", "Tenor", "Bright"),
    ]

    # create an array of objects for guitarists
    guitarists = [
        Guitarist("Taylor York", 18, "Band", "Lead", "Fender", []),
        Guitarist("Ray Toro", 24, "Band", "Lead", "Gibson", []),
        Guitarist("Toru Yamashita", 20, "Band", "Rhythm", "PRS", []),
    ]

    # create an array of objects for singer songwriters
    singerSongwriters = [
        SingerSongwriter("Luke Hemmings", 14, "Live", "Tenor", "Warm", "Rhythm", "Gibson", [], 120, "Pop"),
        SingerSongwriter("Michael Clifford", 14, "Studio", "Tenor", "Bright", "Lead", "Fender", [], 90, "Pop"),
        SingerSongwriter("Gaon", 4, "Live", "Tenor", "Bright", "Rhythm", "Ibanez", [], 25, "Rock"),
    ]

    # create an array of objects for guitars
    guitars = [
        Guitar("Fender", "Electric", "D'Addario", "Steel"),
        Guitar("Gibson", "Acoustic", "Ernie Ball", "Steel"),
        Guitar("PRS", "Electric", "Elixir", "Steel"),
        Guitar("Gibson", "Acoustic", "Martin", "Steel"),
        Guitar("Fender", "Electric", "D'Addario", "Steel"),
        Guitar("Ibanez", "Acoustic", "Ernie Ball", "Steel"),
    ]

    # add guitars to the list of guitars in guitarists
    guitarists[0].addGuitar(guitars[0])
    guitarists[1].addGuitar(guitars[1])
    guitarists[2].addGuitar(guitars[2])

    # add guitars to the list of guitars in singer songwriters
    singerSongwriters[0].addGuitar(guitars[3])
    singerSongwriters[1].addGuitar(guitars[4])
    singerSongwriters[2].addGuitar(guitars[5])

    # combine the children and grandchildren to musicians list
    musicians = singers + guitarists + singerSongwriters
    
    # print welcome message
    print("                     _      _                   ")
    print(" _ __ ___  _   _ ___(_) ___(_) __ _ _ __  ____  ")
    print("| '_ ` _ \\| | | |_  / |/ __| |/ _` | '_ \\|_  /  ")
    print("| | | | | | |_| |/ /| | (__| | (_| | | | |/ / _ ")
    print("|_| |_| |_\\__,_ /___|_|\\___|_|\\__,_|_| |_/___(_)")

    delay = 1
    time.sleep(delay)
    print("\nFetching data", end="")
    time.sleep(delay)
    print(" . ", end="")
    time.sleep(delay)
    print(" . ", end="")
    time.sleep(delay)
    print(" . \n")
    time.sleep(delay)

    # print guitars data
    printGuitars(guitars, delay)
    # print musicians data
    printMusicians(musicians, delay)

    print("Loading ", end="")
    time.sleep(delay)
    print(" . ", end="")
    time.sleep(delay)
    print(" . ", end="")
    time.sleep(delay)
    print(" . \n")
    time.sleep(delay)

    print("New data found!")
    time.sleep(delay)
    print("Adding new data", end="")
    time.sleep(delay)
    print(" . ", end="")
    time.sleep(delay)
    print(" . ", end="")
    time.sleep(delay)
    print(" . \n")

    # simulate adding new data statically
    musicians.append(SingerSongwriter("Taka Moriuchi", 20, "Live", "Tenor", "Bright", "Rhythm", "Gibson", [], 80, "Rock"))
    guitars.append(Guitar("Gibson", "Electric", "D'Addario", "Steel"))
    musicians[-1].addGuitar(guitars[-1])
    guitars.append(Guitar("Gibson", "Acoustic", "Elixir", "Steel"))
    musicians[-1].addGuitar(guitars[-1])

    # print guitars data after adding new data
    printGuitars(guitars, delay)
    # print musicians data after adding new data
    printMusicians(musicians, delay)

    print("Exiting program.")
    time.sleep(delay)

# function to print musicians data
def printMusicians(musicians, delay):
    print("============================================")
    print("             __     __               __ ")
    print("  |\\/| |  | /__` | /  ` |  /\\  |\\ | /__`")
    print("  |  | \\__/ .__/ | \\__, | /~~\\ | \\| .__/")
    print("\n============================================")
    time.sleep(delay)
    # variable to keep track of current class
    currentClass = None
    number = 1
    for musician in musicians:
        # get the class of the current musician
        musicianClass = type(musician)
        # if the class of the current musician is different from the previous musician
        # print the class name as a title and reset the number
        if musicianClass is not currentClass:
            currentClass = musicianClass
            number = 1
            print(f"\n{musicianClass.__name__.upper()}:")
            time.sleep(delay)

        # print each data
        print(f"{number}. Name: {musician.getName()}")
        print(f"   Years of Experience: {musician.getYearsOfExperience()}")
        print(f"   Performance Type: {musician.getPerformanceType()}")

        # if musician is singer songwriter, print additional data
        if isinstance(musician, SingerSongwriter):
            print(f"   Vocal Range: {musician.getVocalRange()}")
            print(f"   Tone: {musician.getTone()}")
            print(f"   Position: {musician.getPosition()}")
            print(f"   Favorite Guitar Brand: {musician.getFavoriteBrand()}")
            print(f"   Guitars:")
            # print guitars list
            for guitar in musician.getGuitars():
                print(f"      - {guitar.getBrand()} {guitar.getType()}")
            print(f"   Songs Written: {musician.getSongsWritten()}")
            print(f"   Writing Genre: {musician.getWritingGenre()}")
        # if musician is singer, print additional data
        elif isinstance(musician, Singer):
            print(f"   Vocal Range: {musician.getVocalRange()}")
            print(f"   Tone: {musician.getTone()}")
        # if musician is guitarist, print additional data
        elif isinstance(musician, Guitarist):
            print(f"   Position: {musician.getPosition()}")
            print(f"   Favorite Guitar Brand: {musician.getFavoriteBrand()}")
            print(f"   Guitars:")
            # print guitars list
            for guitar in musician.getGuitars():
                print(f"      - {guitar.getBrand()} {guitar.getType()}")

        print()
        number += 1
        time.sleep(delay)

# function to print guitars data
def printGuitars(guitars, delay):
    print("=====================================")
    print("   __         ___       __   __ ")
    print("  / _` |  | |  |   /\\  |__) /__`")
    print("  \\__> \\__/ |  |  /~~\\ |  \\ .__/")
    print("\n=====================================\n")
    time.sleep(delay)
    number = 1
    # print each data
    for guitar in guitars:
        print(f"{number}. Brand: {guitar.getBrand()}")
        print(f"   Type: {guitar.getType()}")
        print(f"   Strings:")
        # print guitar strings
        for string in guitar.getStrings():
            print(f"      - Brand: {string.getStringBrand()}, Material: {string.getMaterial()}, Gauge: {string.getStringGauge()}")
        print()
        number += 1
        time.sleep(delay)

if __name__ == "__main__":
    main()