#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct kocsi {
    string marka;
    string modell;
    string szin;
    int evjarat;
    int ar;
    string rendszam;
};

struct filter {
    string marka;
    string modell;
    string szin;
    int evjarat;
    int minar;
    int maxar;
};

bool egyenlo(string a, string b){
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    return a==b;
}

int main() {
    kocsi Autok[30] = {
            {"Toyota", "Corolla", "Piros", 2018, 15000, "XYZ123"},
            {"Honda", "Civic", "Kek", 2019, 18500, "ABC456"},
            {"Ford", "Mustang", "Fekete", 2020, 30000, "DEF789"},
            {"Chevrolet", "Malibu", "Ezust", 2017, 14200, "GHI012"},
            {"Nissan", "Altima", "Feher", 2016, 12500, "JKL345"},
            {"BMW", "X5", "Szurke", 2021, 45000, "MNO678"},
            {"Volkswagen", "Jetta", "Zold", 2019, 17800, "PQR901"},
            {"Audi", "A4", "Piros", 2018, 23000, "STU234"},
            {"Mercedes", "C-Class", "Kek", 2020, 38500, "VWX567"},
            {"Subaru", "Outback", "Ezust", 2017, 20000, "YZA890"},
            {"Toyota", "Camry", "Fekete", 2015, 13000, "BCD123"},
            {"Honda", "Accord", "Feher", 2019, 19500, "EFG456"},
            {"Ford", "Escape", "Szurke", 2016, 16200, "HIJ789"},
            {"Chevrolet", "Cruze", "Piros", 2020, 21800, "KLM012"},
            {"Nissan", "Rogue", "Kek", 2018, 22500, "NOP345"},
            {"BMW", "3 Series", "Ezust", 2019, 35000, "QRS678"},
            {"Volkswagen", "Golf", "Fekete", 2017, 18900, "STU901"},
            {"Audi", "Q5", "Feher", 2021, 42500, "VWX234"},
            {"Mercedes", "E-Class", "Szurke", 2018, 40000, "YZA567"},
            {"Subaru", "Forester", "Zold", 2016, 19000, "BCD890"},
            {"Toyota", "Highlander", "Ezust", 2019, 28500, "EFG123"},
            {"Honda", "CR-V", "Kek", 2017, 24000, "HIJ456"},
            {"Ford", "Explorer", "Piros", 2020, 34200, "KLM789"},
            {"Chevrolet", "Tahoe", "Feher", 2018, 38500, "NOP012"},
            {"Nissan", "Pathfinder", "Fekete", 2019, 31000, "QRS345"},
            {"BMW", "5 Series", "Kek", 2017, 43000, "STU678"},
            {"Volkswagen", "Tiguan", "Szurke", 2020, 27800, "VWX901"},
            {"Audi", "A6", "Ezust", 2018, 39000, "YZA234"},
            {"Mercedes", "GLC-Class", "Piros", 2019, 41500, "BCD567"},
            {"Subaru", "Crosstrek", "Feher", 2016, 23000, "EFG890"},
    };

    filter szuro;
    cout << "Allitsd be a szurodet: (ha nem szeretnel szurot allitani, akkor irj egy -1-et, ekezeteket ne hasznalj)" << endl;
    cout << "Marka: " << endl;
    cin >> szuro.marka;
    cout << "Modell: " << endl;
    cin >> szuro.modell;
    cout << "Szin: " << endl;
    cin >> szuro.szin;
    cout << "Evjarat: " << endl;
    cin >> szuro.evjarat;
    cout << "Ar also korlatja ($): " << endl;
    cin >> szuro.minar;
    cout << "Ar felso korlatja ($): " << endl;
    cin >> szuro.maxar;

    vector<kocsi> szurtkocsik;
    for (int i=0; i<30; i++){
        if ((egyenlo(Autok[i].marka, szuro.marka) || szuro.marka == "-1") &&
                (egyenlo(Autok[i].modell, szuro.modell) || szuro.modell == "-1") &&
                (egyenlo(Autok[i].szin, szuro.szin) || szuro.szin == "-1") &&
                (Autok[i].evjarat == szuro.evjarat || szuro.evjarat == -1) &&
                (Autok[i].ar > szuro.minar && (Autok[i].ar < szuro.maxar || szuro.maxar == -1))){
            szurtkocsik.push_back(Autok[i]);
        }
    }
    if (szurtkocsik.size() == 0){
        cout << "Nincs ilyen auto!";
    }
    else {
        cout << "Marka | Modell | Szin | Evjarat | Ar | Rendszam" << endl;
        for (int i = 0; i < szurtkocsik.size(); i++) {
            cout << szurtkocsik[i].marka << " | " << szurtkocsik[i].modell << " | "
                 << szurtkocsik[i].szin << " | " << szurtkocsik[i].evjarat << " | "
                 << szurtkocsik[i].ar << "$ | " << szurtkocsik[i].rendszam << endl;
        }
    }

    return 0;
}
