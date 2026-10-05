# TP 3 DPBO — Musicianz

Tugas Praktikum 3 Mata Kuliah **Desain dan Pemrograman Berorientasi Objek (DPBO)**.

Program ini menampilkan data musisi (singer, guitarist, singer-songwriter) dan gitar beserta senarnya dalam tiga edisi bahasa: C++, Java, dan Python. Seluruh edisi menggunakan konsep diamond inheritance yang sama, tetapi memiliki mekanisme multiple inheritance yang berbeda.

## Janji

Saya Nabila Attaya Putri Cahyadi dengan NIM 2508355 mengerjakan Tugas Praktikum 3 pada Mata Kuliah Desain dan Pemrograman Berorientasi Objek (DPBO) untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

## Ringkasan Proyek

| Edisi | Antarmuka | Penyimpanan data |
|---|---|---|
| C++ | Terminal/CLI | `vector` dinamis selama program berjalan |
| Java | Terminal/CLI | `ArrayList` selama program berjalan |
| Python | Terminal/CLI | List selama program berjalan |

Fitur utama program:

- Menggunakan diamond inheritance melalui `Musician`, `Singer`, `Guitarist`, dan `SingerSongwriter`.
- Menyediakan data awal tiga singer, tiga guitarist, dan tiga singer-songwriter.
- Menyediakan data awal enam gitar dengan enam senar tiap gitar.
- Menghubungkan gitar ke guitarist/singer-songwriter melalui `addGuitar`.
- Menampilkan seluruh gitar melalui `printGuitars` dan seluruh musisi melalui `printMusicians`.
- Menambahkan data baru statis (`Taka Moriuchi` + 2 gitar) lalu menampilkan ulang.

## Struktur Folder
```text
TP3DPBO2526C1/
│
├── README.md
├── diagram_design.png
│
├── cpp/
│   ├── program/
│   │   ├── Musician.cpp
│   │   ├── Singer.cpp
│   │   ├── Guitarist.cpp
│   │   ├── SingerSongwriter.cpp
│   │   ├── Guitar.cpp
│   │   ├── GuitarString.cpp
│   │   └── main.cpp
│   └── dokumentasi/
│       ├── dokumcpp.mp4
│       └── dokumcpp.gif
│
├── java/
│   ├── program/
│   │   ├── Musician.java
│   │   ├── Singer.java
│   │   ├── Guitarist.java
│   │   ├── GuitaristTrait.java
│   │   ├── SingerSongwriter.java
│   │   ├── Guitar.java
│   │   ├── GuitarString.java
│   │   └── Main.java
│   └── dokumentasi/
│       ├── dokumjava.mp4
│       └── dokumjava.gif
│
└── python/
    ├── program/
    │   ├── Musician.py
    │   ├── Singer.py
    │   ├── Guitarist.py
    │   ├── SingerSongwriter.py
    │   ├── Guitar.py
    │   ├── GuitarString.py
    │   └── main.py
    └── dokumentasi/
        ├── dokumpy.mp4
        └── dokumpy.gif
```

## Diagram Desain

![Diagram UML Musician, Singer, Guitarist, SingerSongwriter, Guitar, dan GuitarString](diagram_design.png)

### Hierarki Class

```text
Musician
├── Singer
│   └── SingerSongwriter ──┐
└── Guitarist ─────────────┘
        (diamond)

Guitar ◆── GuitarString (composition)
Guitarist o── Guitar (aggregation)
```

Keenam class menggunakan inheritance dan composition untuk kebutuhan data pada tingkat kekhususan yang berbeda:

1. **`Musician`** menyimpan informasi dasar semua musisi: name, yearsOfExperience, dan performanceType.
2. **`Singer`** mewarisi `Musician`, lalu menambah vocalRange dan tone.
3. **`Guitarist`** mewarisi `Musician`, lalu menambah position, favoriteBrand, dan list guitars.
4. **`SingerSongwriter`** mewarisi `Singer` dan `Guitarist`, lalu menambah songsWritten dan writingGenre.
5. **`Guitar`** menyimpan brand, type, dan list strings; tiap gitar selalu dibuat dengan 6 `GuitarString` via `makeStringData`.
6. **`GuitarString`** menyimpan stringBrand, material, dan stringGauge.

Objek yang ditampilkan program adalah list `Guitar` dan list `Musician` berisi `Singer`, `Guitarist`, dan `SingerSongwriter`. Karena pewarisan, `SingerSongwriter` dapat mengakses seluruh atribut dan method dari `Singer` dan `Guitarist`.

### Prinsip OOP

- **Inheritance:** `Singer` adalah `Musician`, `Guitarist` adalah `Musician`, `SingerSongwriter` adalah `Singer` sekaligus `Guitarist`.
- **Hybrid inheritance:** hierarchical (`Musician` -> `Singer` + `Guitarist`) digabung multiple (`Singer` + `Guitarist` -> `SingerSongwriter`).
- **Multiple inheritance:** C++ (`class SingerSongwriter : public Singer, public Guitarist`) dan Python (`class SingerSongwriter(Singer, Guitarist)`) langsung; Java memakai `extends Singer implements GuitaristTrait` karena single inheritance.
- **Encapsulation:** data disimpan sebagai atribut dan diakses melalui getter/setter.
- **Composition:** `Guitar` memiliki 6 `GuitarString` yang dibuat di dalam constructor.
- **Aggregation:** `Guitarist` memiliki list `Guitar` yang ditambah dari luar via `addGuitar`.
- **Reuse:** atribut dasar musisi tidak diduplikasi pada class anak.

## Method Program

Implementasi C++ menggunakan function, Java menggunakan private static method, Python menggunakan function di `main.py`.

| Method/function | Fungsi |
|---|---|
| `main` / `Main.main` / `main()` | Titik masuk yang menyiapkan data awal, menghubungkan gitar, menampilkan data, menambah data baru, lalu menampilkan ulang. |
| `printMusicians(musicians, delay)` | Menampilkan seluruh musisi per kelompok kelas (`Singer`, `Guitarist`, `SingerSongwriter`). |
| `printGuitars(guitars, delay)` | Menampilkan seluruh gitar beserta 6 senarnya. |
| `addGuitar(guitar)` | Menambah satu gitar ke list guitars milik guitarist/singer-songwriter. |
| `makeStringData(stringBrand, material, gauges)` | Membentuk data 6 senar berdasarkan brand, material, dan gauge. |
| `setStrings(stringData)` / `getStrings()` | Validasi lalu menyimpan/mengambil list `GuitarString`. |
| `sleepDelay(seconds)` | Memberi jeda antar tampilan (Java private static method; C++ function; Python `time.sleep`). |

Gauge default `Electric` dan `Acoustic` disimpan di `Guitar.defaultGauges`; tipe lain wajib diberi gauge custom.

## Alur Program

Alur berikut berlaku untuk C++, Java, dan Python.
1. Program membuat list `singers`, `guitarists`, `singerSongwriters`, dan `guitars` sebagai data awal.
2. `addGuitar()` dipanggil untuk tiap guitarist dan singer-songwriter, lalu semuanya digabung ke list `musicians`.
3. Layar sambutan dan animasi `Fetching data` ditampilkan.
4. `printGuitars()` menampilkan tiap gitar beserta senarnya.
5. `printMusicians()` menampilkan tiap musisi per kelompok kelas; `SingerSongwriter` dicek lebih dulu karena juga merupakan `Singer`.
6. Program menampilkan `New data found!`, menambah `Taka Moriuchi` + 2 gitar secara statis.
7. `printGuitars()` dan `printMusicians()` dipanggil ulang dengan data baru.
8. Program menampilkan `Exiting program.` lalu berhenti.

Data pada ketiga edisi hanya tersimpan selama program berjalan.

## Error Handling

| Bagian | Kondisi tidak valid | Penanganan |
|---|---|---|
| `setStrings` | Jumlah senar bukan 6 | Melempar error `A guitar must have exactly 6 strings`. |
| `setStrings` | Gauge tidak unik (kurang dari 6 gauge berbeda) | Melempar error `Each string must have a different gauge`. |
| `Guitar` constructor | Tipe gitar tanpa gauge default dan tanpa gauge custom | Melempar error `A custom gauge set is required for this guitar type`. |

## Dokumentasi

### C++

![Dokumentasi C++](cpp/dokumentasi/dokumcpp.gif)

### Java

![Dokumentasi Java](java/dokumentasi/dokumjava.gif)

### Python

![Dokumentasi Python](python/dokumentasi/dokumpy.gif)
