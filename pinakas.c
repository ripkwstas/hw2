#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 118

int screenf1();
int screenf2();
int screenf4();
int screenf6();
int serialSearch();
void search();
const char* find_block();
int elementsearch();

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

// Πίνακας με τις ατομικές μάζες των στοιχείων
float atomic_masses[118] = {
    1.00794, 4.002602, 6.941, 9.012182, 10.811, 12.011, 14.00674, 15.9994, 18.9984032, 20.1797,
    22.989768, 24.305, 26.981539, 28.0855, 30.973762, 32.066, 35.4527, 39.948, 39.0983, 40.078,
    44.95591, 47.867, 50.9415, 52.0, 54.938044, 55.845, 58.933195, 58.6934, 63.546, 65.38,
    69.723, 72.63, 74.921595, 78.971, 79.904, 83.798, 85.4678, 87.62, 88.90585, 91.224,
    92.90638, 95.95, 98.0, 101.07, 102.90550, 106.42, 107.8682, 112.411, 114.818, 118.710,
    121.760, 127.60, 126.90447, 131.293, 132.90545196, 137.327, 138.90547, 140.90766, 144.242,
    145.0, 150.36, 151.964, 157.25, 158.92535, 162.500, 164.93033, 167.259, 168.93422, 173.04,
    174.9668, 178.49, 180.94788, 183.84, 186.2071, 190.23, 192.217, 195.078, 196.966569,
    200.592, 204.38, 207.2, 208.98040, 209.0, 210.0, 222.0, 223.0, 226.0, 227.0,
    232.03805, 231.03588, 238.02891, 237.0, 244.0, 243.0, 247.0, 247.0, 251.0, 252.0,
    257.0, 258.0, 259.0, 262.0, 267.0, 270.0, 271.0, 270.0, 277.0, 276.0,
    281.0, 280.0, 285.0, 284.0, 289.0, 288.0, 293.0, 294.0, 294.0, 289.0
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
    "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium"
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
        }while(check > 3 || check < 1);

        if (check == 1) {
            search();
            exit(2);
        } else if (check == 2) {
            do {
                check2 = screenf4();
            }while (check2 > 3 || check2 < 1);
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

        scanf("%d", &ans1);
        return ans1;
}

int screenf2(){
        int ans1;

        system("clear");

        printf("| -------------------------- |\n");
        printf("| Periodic Table of Elements |\n");
        printf("| -------------------------- |\n\n");
        printf("1. Atomic number\n");
        printf("2. Name\n");
        printf("3. Symbol\n");
        printf("\nType your selection (1, 2 or 3): ");

        scanf("%d", &ans1);
        return ans1;

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

        return 0;

}






void search(){
    int check, flag, atnu, ans, check2;
    const char* group;
    char na[10];
            
        do{
            check = screenf2();
        }while (check > 3 || check < 1);
            
        if(check == 1){
            printf("\n\nProvide element atomic number: ");
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
                printf("4. Chemical group block: %s\n", find_block(element_names[atnu - 1]));
                printf("5. Atomic mass: %f\n\n", atomic_masses[atnu - 1]);
                printf("1 ---> restart\nanything else --->end programm");
                scanf("%d", &ans);
                if(ans == 1){
                    search();
                    exit(1);
                }else if(ans != 1)
                    exit(0);
                }
        }else if(check == 2){
            printf("\n\nProvide a name: ");
            scanf("%10s", na);
            check2 = elementsearch(na);
            if(check2 != 119){
                system("clear");

                printf("| -------------------------- |\n");
                printf("| Periodic Table of Elements |\n");
                printf("| -------------------------- |\n\n");
                printf("Element description \n");
                printf("1. Atomic number: %d \n", check2);
                printf("2. Name: %s \n", element_names[check2]);
                printf("3. Symbol: %s \n", element_symbols[check2]);
                printf("4. Chemical group block: %s\n", find_block(element_names[check2]));
                printf("5. Atomic mass: %f\n\n", atomic_masses[check2]);
                printf("1 ---> restart\nanything else --->end programm: ");
                scanf("%d", &ans);
                if(ans == 1){
                    search();
                    exit(1);
                }else if(ans != 1)
                    exit(0);
                }

        }
}





const char* find_block(const char* item) {
    // Έλεγχος για κάθε μπλοκ
    for (int i = 0; i < 16; i++) {
        if (strcmp(s_block_elements[i], item) == 0) {  //χρησιμοποιω την strcmp για να συγκρίνω τα περιεχομενα των 2 strings
            return "s-block";
        }
    }
    for (int i = 0; i < 35; i++) {
        if (strcmp(p_block_elements[i], item) == 0) {
            return "p-block";
        }
    }
    for (int i = 0; i < 10; i++) {
        if (strcmp(d_block_elements[i], item) == 0) {
            return "d-block";
        }
    }
    for (int i = 0; i < 14; i++) {
        if (strcmp(f_block_elements[i], item) == 0) {
            return "f-block";
        }
    }

    return "Block not found";  // Αν το στοιχείο δεν ανήκει σε κανένα από τα μπλοκ
}



int elementsearch(char *na){
    for(int i = 0; i < NUM_ELEMENTS; i++){
        if(strcmp(element_names[i], na) == 0)
            return i;
    }
    printf("\nName didnt found...\n");
    return 119;

}

