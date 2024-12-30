#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEMENTS 118

int screenf1();
int screenf2();
int screenf4();
int screenf6();
int serialSearch();
int search();

// Πίνακας με τα ονόματα των στοιχείων
const char* element_names[NUM_ELEMENTS] = {
    "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon",
    "Sodium", "Magnesium", "Aluminium", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium",
    "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc",
    "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium",
    "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin",
    "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
    "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium",
    "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
    "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium",
    "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium",
    "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium",
    "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"
};

// Πίνακας με τα ονόματα των στοιχείων του s-block
const char* s_block_elements[16] = {
    "Hydrogen", "Helium", "Lithium", "Beryllium", "Sodium", "Magnesium", "Potassium", "Calcium", 
    "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel"
};

// Πίνακας με τα ονόματα των στοιχείων του p-block
const char* p_block_elements[35] = {
    "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Aluminium", "Gallium", "Germanium", "Arsenic",
    "Selenium", "Bromine", "Krypton", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium",
    "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", 
    "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium"
};

// Πίνακας με τα ονόματα των στοιχείων του d-block
const char* d_block_elements[10] = {
    "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc"
};

// Πίνακας με τα ονόματα των στοιχείων του f-block
const char* f_block_elements[14] = {
    "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", 
    "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium"
};


const char* element_symbols[NUM_ELEMENTS] = {
    "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
    "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
    "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
    "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
    "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
    "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
    "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
    "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
    "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
    "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
    "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
};

int main(){
    int ans1, check, check1, check2, check3; //αρχικοποιουμε 4 ωστε να παιξουνε τουλαχιστον μια φορα
    int atnu;

        do{
            check = screenf1(); // καλουμαι την πρωτη οθόνη
        }while(check > 3 || check < 1)

        if (check == 1) {
            search();
        } else if (check == 2) {
            do {
                check2 = screenf4();
            } while (check2 > 3 || check2 < 1)
        } else if (check == 3) {
            exit(1);
        }

}


int screenf1(){
    int ans1, check;

        system("clear");

        printf("| -------------------------- |\n");
        printf("| Periodic Table of Elements |\n");
        printf("| -------------------------- |\n\n");
        printf("1. Search for individual elements\n");
        printf("2. Search for group of elements\n");
        printf("3. Terminate application\n");
        printf("\nType your selection (1, 2 or 3): ");

        check = scanf("%d", &ans1);
        return check;
}

int screenf2(){
        int ans1, check;

        system("clear");

        printf("| -------------------------- |\n");
        printf("| Periodic Table of Elements |\n");
        printf("| -------------------------- |\n\n");
        printf("1. Atomic number\n");
        printf("2. Name\n");
        printf("3. Symbol\n");
        printf("\nType your selection (1, 2 or 3): ");

        check = scanf("%d", &ans1);
        return check;

}

int screenf4(){
        int ans1, check;

        system("clear");

        printf("| -------------------------- |\n");
        printf("| Periodic Table of Elements |\n");
        printf("| -------------------------- |\n\n");
        printf("Group of elements search, define, criteria: \n");
        printf("1. Minimum atomic number: 3\n");
        printf("2. Maximum atomic number: 7\n");
        printf("3. Chemical group block: 0\n");
        printf("4. Minimum atomic mass: 0\n");
        printf("5. Maximum atomic mass: 0\n");

        return check;

}



int serialSearch(int pinakas[], int size, int item) {
    for (int i = 0; i < size; i++) {
        if (pinakas[i] == target) { // Αν βρεθεί το στοιχείο
            return i;           // Επιστρέφει τη θέση
        }
    }
    return -1; // Αν δεν βρεθεί, επιστρέφει -1
}


int search(){
    int check, flag;
    char group;
            
        do{
            check = screenf2();
        }while (check > 3 || check < 1)
            
        if(check == 1){
            printf("\n\nProvide element atomic number: ")
            flag = scanf("%d", &atnu);
            if(flag == 1 && atnu > 0 && atnu < 119){
                 system("clear");

            printf("| -------------------------- |\n");
            printf("| Periodic Table of Elements |\n");
            printf("| -------------------------- |\n\n");
            printf("Element description \n");
            printf("1. Atomic number: %d \n", atnu);
            printf("2. Name: %s \n", element_names[atnu - 1]);
            printf("3. Symbol: %s \n", element_symbols[atnu - 1]);

            const char* item = element_names[atnu -1];
            group = find_block(item);

            printf("4. Chemical group block: ")


            }
        }
}




const char* find_block(const char* item) {
    // Έλεγχος για κάθε μπλοκ
    for (int i = 0; i < 16; i++) {
        if (s_block_elements[i] == item){
            return "s-block";
        }
    }
    for (int i = 0; i < 35; i++) {
        if (p_block_elements[i] == item) {
            return "p-block";
        }
    }
    for (int i = 0; i < 10; i++) {
        if (d_block_elements[i] == item) {
            return "d-block";
        }
    }
    for (int i = 0; i < 14; i++) {
        if (f_block_elements[i] == item) {
            return "f-block";
        }
    }

    return "Block not found";  // Αν το στοιχείο δεν ανήκει σε κανένα από τα μπλοκ
}

