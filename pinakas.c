#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 118

int screenf1();
int screenf2();
int serialSearch();
void search();
int elementsearch();
int symbolsearch();
void groupsearch();
void kokkinisma();

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


const char* chemical_block[NUM_ELEMENTS] = { //χημικη ομαδα καθε στοιχειου
    "Nonmetal", "Noble Gas", "Alkali Metal", "Alkaline Earth Metal", "Metalloid",
    "Nonmetal", "Nonmetal", "Nonmetal", "Noble Gas", "Alkali Metal",
    "Alkaline Earth Metal", "Metalloid", "Metalloid", "Nonmetal", "Nonmetal",
    "Nonmetal", "Nonmetal", "Noble Gas", "Alkali Metal", "Alkaline Earth Metal", 
    "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal",
    "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal",
    "Post-Transition Metal", "Metalloid", "Metalloid", "Nonmetal", "Nonmetal",
    "Nonmetal", "Nonmetal", "Noble Gas", "Alkali Metal", "Alkaline Earth Metal",
    "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal",
    "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal",
    "Post-Transition Metal", "Metalloid", "Metalloid", "Nonmetal", "Nonmetal",
    "Nonmetal", "Noble Gas", "Alkali Metal", "Alkaline Earth Metal", "Transition Metal", 
    "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal",
    "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal",
    "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide",
    "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide",
    "Actinide", "Actinide", "Actinide", "Actinide", "Actinide",
    "Actinide", "Actinide", "Actinide", "Actinide", "Actinide",
    "Post-Transition Metal", "Metalloid", "Nonmetal", "Nonmetal", "Noble Gas",
    "Post-Transition Metal", "Transition Metal", "Lanthanide", "Lanthanide", "Lanthanide",
    "Lanthanide", "Lanthanide", "Actinide", "Actinide", "Actinide",
    "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", 
    "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal", "Transition Metal",
    "Transition Metal", "Transition Metal", "Transition Metal"
};

const char* element_symbols[NUM_ELEMENTS] = { // συμβολο καθε στοιχειου
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
        
        
        
        check = screenf1(); // καλουμαι την πρωτη οθόνη
        

        if (check == 1) {// στην περιπτωση πουυ θελει να αναζητησει ενα μεμονομενο στοιχειο
            search();
            return 0;;
        } else if (check == 2) {
            groupsearch();
            exit(3);// κανουμε exit οταν επιστρεφει απο απο αναζητηση για να βγει κατεθειαν απο το προγραμμα
        } else if (check == 3) {
            system("clear");
            return 0;
        }

}


int screenf1() {
    int ans1;
    while (1) {  // Συνεχίζει το loop μέχρι να εισαχθεί έγκυρος αριθμός
        system("clear");

        // Εμφανίζει το μενού στην αρχή κάθε loop
        printf("| -------------------------- |\n");
        printf("| Periodic Table of Elements |\n");
        printf("| -------------------------- |\n\n");
        printf("1. Search for individual elements\n");
        printf("2. Search for group of elements\n");
        printf("3. Terminate application\n");
        printf("\nType your selection (1, 2 or 3): ");

        // Ελέγχει αν η είσοδος είναι έγκυρος αριθμός
        if (scanf("%d", &ans1) != 1) {  // Μη έγκυρη είσοδος (όχι αριθμός)
            while (getchar() != '\n');  // Καθαρίζει την μη έγκυρη είσοδο από την μνημη δηλαδη απο το buffer 
            // Επαναλαμβάνει την εμφάνιση του μενού μετά από μη έγκυρη είσοδο (μη αριθμός)
        } else if (ans1 < 1 || ans1 > 3) {  // Η είσοδος είναι εκτός των έγκυρων τιμών
            system("clear");

            // Εμφανίζει το μενού στην αρχή κάθε loop
            printf("| -------------------------- |\n");
            printf("| Periodic Table of Elements |\n");
            printf("| -------------------------- |\n\n");
            printf("1. Search for individual elements\n");
            printf("2. Search for group of elements\n");
            printf("3. Terminate application\n");
            printf("\nType your selection (1, 2 or 3): ");
        } else {
            break;  // Έγκυρη είσοδος, βγαίνει από το loop
        }
    }
    return ans1; //γυρναει την απαντηση 
}

int screenf2(){
    int ans1;
    int valid_input;

    do {
        system("clear");

        printf("| -------------------------- |\n");
        printf("| Periodic Table of Elements |\n");
        printf("| -------------------------- |\n\n");
        printf("1. Atomic number\n");
        printf("2. Name\n");
        printf("3. Symbol\n");
        printf("\nType your selection (1, 2, or 3): ");

        valid_input = scanf("%d", &ans1);

        // Καθαριζει το buffer ετσι ωστε και να εχει πατησει παραπανω abc... κτλ ο χρηστης να τα σβησει
        while (getchar() != '\n');

    } while (valid_input != 1 || ans1 < 1 || ans1 > 3);

    return ans1;
}

void search(){
    int check, flag, atnu, ans, check2, check3;
    const char* group;
    char na[10], sy[4]; //χρησιμοποιουμε πινακες ωστε να αποθηκευονται καπου τα στοιχεια απο την scanf , το μεγεθος ειναι αναλογα τα μεγιστα γραμματα ενος στοιχειου
            
        check = screenf2(); //ρωταει τον χρηστη ως προς τι θελει να αναζητησει
        
            
        if(check == 1){
            

            do {
                system("clear");

                printf("| -------------------------- |\n");
                printf("| Periodic Table of Elements |\n");
                printf("| -------------------------- |\n\n");
                printf("1. Atomic number\n");
                printf("2. Name\n");
                printf("3. Symbol\n");
                printf("\nType your selection (1, 2, or 3): ");
                printf("\n\nProvide element atomic number: ");
                
                flag = scanf("%d", &atnu);

                // Αν η είσοδος δεν είναι έγκυρη  καθαρίζουμε το buffer
                if (flag != 1 || atnu < 0 || atnu > 118) {
                    while(getchar() != '\n');
                }
            } while (flag != 1 || atnu < 0 || atnu > 118); //επαναλαμβανετε μεχρι να δωθει μια εγκυρη είισοδος

            if(flag == 1 && atnu > 0 && atnu < 119){ //περιπτωση αναζητησης ως πρως τον ατομικο αριθμο
                 system("clear");

                printf("| -------------------------- |\n");
                printf("| Periodic Table of Elements |\n");
                printf("| -------------------------- |\n\n");
                printf("Element description \n");
                printf("1. Atomic number: %d \n", atnu);
                printf("2. Name: %s \n", element_names[atnu - 1]); // αφαιρουμε -1 επειδη στον πίνακα ειναι -1 τα στοιχεια τα σωστα
                printf("3. Symbol: %s \n", element_symbols[atnu - 1]);
                printf("4. Chemical group block: %s\n", chemical_block[atnu - 1]);
                printf("5. Atomic mass: %f\n\n", atomic_masses[atnu - 1]);
                printf(" 1 ---> Search individual\n 2---> Search group\n Any key ---> Exit the program\n Your Choice: ");// επειτα απο μια εγκυρη αναζητηση εχει επιλογεσ τι θελει να κανει
                scanf("%d", &ans);
                if(ans == 1){
                    search();
                    exit(1);
                }else if(ans == 2){
                    groupsearch();
                    exit(1);
                }else if(ans != 1 && ans != 2){
                    exit(0);
                }
            }
        }else if(check == 2){ // περιπτωση που θελει να αναζητήσει ως προς όνομα 
            do{
                system("clear");

                printf("| -------------------------- |\n");
                printf("| Periodic Table of Elements |\n");
                printf("| -------------------------- |\n\n");
                printf("1. Atomic number\n");
                printf("2. Name\n");
                printf("3. Symbol\n");
                printf("\nType your selection (1, 2, or 3): ");
                printf("\n\nProvide a name: ");


                flag = scanf("%10s", na); // ξερουμε οτι κανενα ονομα δεν μπορει να ξεπεράσει τα 10 γραμματα οποτε φτιαξαμε string με 10 χωριτικοτιτα

                if(flag != 1){
                    while(getchar() != '\n'); // Καθαριζουμε το buffer
                }   
                check2 = elementsearch(na);
            }while(flag != 1 || check2 == 119); //επαναλαμβανετε μεχρι να δωθεί εγκυρη είσοδος 

            

            
                system("clear");  //αν εγινε σωστη εισοδος τοτε εμφανιζει τις πληροφορίες 

                printf("| -------------------------- |\n");
                printf("| Periodic Table of Elements |\n");
                printf("| -------------------------- |\n\n");
                printf("Element description \n");
                printf("1. Atomic number: %d \n", check2 + 1);
                printf("2. Name: %s \n", element_names[check2]);
                printf("3. Symbol: %s \n", element_symbols[check2]);
                printf("4. Chemical group block: %s\n", chemical_block[check2]);
                printf("5. Atomic mass: %f\n\n", atomic_masses[check2]);
                printf(" 1 ---> Search individual\n 2---> Search group\n Any key ---> Exit the program\n Your Choice: ");
                scanf("%d", &ans);
                if(ans == 1){
                    search();
                    exit(1);
                }else if(ans == 2){
                    groupsearch();
                    exit(1);
                }else if(ans != 1 && ans != 2){
                    exit(0);
                }
                

        }else if(check == 3){ //περίπτωση που θελει να γινει αναζητηση με σύμβολο , ακολουθει το ίδιο μοτύβο με τα απο πάνω 

            do{
                system("clear");

                printf("| -------------------------- |\n");
                printf("| Periodic Table of Elements |\n");
                printf("| -------------------------- |\n\n");
                printf("1. Atomic number\n");
                printf("2. Name\n");
                printf("3. Symbol\n");
                printf("\nType your selection (1, 2, or 3): ");
                printf("\n\nProvide a symbol: ");

                flag = scanf("%10s", sy);

                if(flag != 1){
                    while(getchar() != '\n'); // Καθαριζουμε το buffer
                }
                check3 = symbolsearch(sy);
            }while(flag != 1 || check == 119);


            
                system("clear");

                printf("| -------------------------- |\n");
                printf("| Periodic Table of Elements |\n");
                printf("| -------------------------- |\n\n");
                printf("Element description \n");
                printf("1. Atomic number: %d \n", check3 + 1); // προσθετουμε +1 επειδη εχουμε βαλει κατευθειαν την διευθηνση του στοιχειου που βρισκει και επειδη ειναι σε πινακες στρινγκ ειναι -1 
                printf("2. Name: %s \n", element_names[check3]);
                printf("3. Symbol: %s \n", element_symbols[check3]);
                printf("4. Chemical group block: %s\n", chemical_block[check3]);
                printf("5. Atomic mass: %f\n\n", atomic_masses[check3]);
                printf(" 1 ---> Search individual\n 2---> Search group\n Any key ---> Exit the program\n Your Choice: ");
                scanf("%d", &ans);
                if(ans == 1){
                    search();
                    exit(1);
                }else if(ans == 2){
                    groupsearch();
                    exit(1);
                }else if(ans != 1 && ans != 2){
                    exit(0);
                }
            
        }
}



int elementsearch(char *na){ // η συναρτηση ψαχνει αν το ονομα υπαρχει στον χημικο πίνακα
    for(int i = 0; i < NUM_ELEMENTS; i++){
        if(strcasecmp(element_names[i], na) == 0)
            return i; // επιστρεφει ο αριθμος στον οποιο βρεθηκε το στοιχειο
    }
    return 119;//το προγραμμα γυριζει 119 για να δειξει πως δεν βρηκε κανενα στοιχειο, το 119 ειναι μεγαλυτερος αριθμος απο ολα τα στοιχεια του πινακα για αυτο επιλεχθηκε αυτος

}

int symbolsearch(char *sy){ // η συναρτηση ψαχνει αν το συμβολο υπαρχει στον χημικο πίνακα
    for(int i = 0; i < NUM_ELEMENTS; i++){
        if(strcasecmp(element_symbols[i], sy) == 0)
            return i;
    }
    printf("\nSymbol didnt found...\n");
    return 119; //το προγραμμα γυριζει 119 για να δειξει πως δεν βρηκε κανενα στοιχειο, το 119 ειναι μεγαλυτερος αριθμος απο ολα τα στοιχεια του πινακα για αυτο επιλεχθηκε αυτος
}

void groupsearch(){ // αναζητηση ανα ομάδα 
    const char* yes[NUM_ELEMENTS]; // Πίνακας δεικτών για τα σύμβολα των στοιχείων
    int minat, maxat, ans1, ans2, ans3, ans;
    float minmas, maxmas;
    char bl, term;
    int f1, f2, f3, f4, f5;

    system("clear");

   

        printf("| -------------------------- |\n");
        printf("| Periodic Table of Elements |\n");
        printf("| -------------------------- |\n\n");
        printf("Group of elements search, define, criteria: \n");

        printf("1. Minimum atomic number: ");
        f1 = scanf("%d", &minat);
        while (getchar() != '\n'); // Clear buffer
        if(f1 != 1 || minat < 0 || minat > 118){
            groupsearch();
            exit(1);
        }
        

        printf("\n2. Maximum atomic number: ");
        f2 = scanf("%d", &maxat);
        while (getchar() != '\n'); // Clear buffer
        
        if(f2 != 1 || maxat > 118 || maxat < minat){
            groupsearch(); // αν δεν γίνει σωστη εισοδος όλα απο την αρχη 
            system("clear");
            exit(1);  // επειδη κάλεσμα την ίδιας συναρτησης αφου τελειωσει η αλλη θα επιστρεψει σε αυτην πάλι οποτε πρεπει να γίνετε exit 
        }

        printf("\n3. Chemical group block(1. N.  2. A.M  3. A.E.M.  4.T.M.  5. PT.M  6. L.  7. M   8. N.G.  9. A): ");
        f3 = scanf("%c", &bl);
        if(f3 != 1 || bl != 1 && bl != 2 && bl != 3 && bl != 4 && bl != 0 && bl != 5 && bl != 6 && bl != 7 && bl == 8 && bl != 9){
            groupsearch();
            exit(1);
        }

        printf("\n4. Minimum atomic mass: ");
        f4 = scanf("%f", &minmas);
        if(f4 != 1 || minmas < 1.00794 && minmas !=0){
            groupsearch();
            exit(1);
        }

        printf("\n5. Maximum atomic mass: ");  
        f5 = scanf("%f", &maxmas);
        if(f5 != 1 || maxmas > 294.0 && maxmas != 0){
            groupsearch();
            exit(1);
        }
        
        maxat = (maxat == 0) ? 118 : maxat;  
        maxmas = (maxmas == 0) ? 294.0 : maxmas;
        minmas = (minmas == 0) ? 1.00794 : minmas;
        minat = (minat == 0) ? 1 : minat;



 for (int k = 1; k < 10; k++) {
        int thesi = -1; //για να δειξω πως δεν ειναι σε καμια θεση και να γινονται σωστα τα /t
    for (int i = 1; i < 19; i++) {
        
        // Πρώτη σειρά (k=1)
        if (k == 1) {
            if (i == 1) 
                thesi = 0;  // Υδρογόνο
            else if (i == 18) 
                thesi = 1;  // Ήλιο
            else 
                thesi = -1;
        }
        
        // Δεύτερη σειρα (k=2)

        else if (k == 2) {
            if (i == 1) {
                thesi = 2;
            } else if (i == 2) {
                thesi = 3;
    
            } else if (i >= 13 && i <= 18) {
                thesi = i - 9;
            }else{
                thesi = -1;
            }
        }
    
        else if (k == 3) { // τριτη σειρα 
            if (i == 1) {
                thesi = 10;
            } else if (i == 2) {
                thesi = 11;
            } else if (i >= 13 && i <= 18) {
                thesi = i - 1;
            }else
                thesi = -1;
    }
            
        
        else if (k == 4) { //τεταρτη σειρα 
            if (i >= 1 && i <= 18) {
                thesi = 17 + i;
            }
        }
        else if (k == 5){
            if(i >= 1 && i <= 18){
                thesi = 35 + i;
            }
        }
        
        else if(k == 6){
            if(i == 1){
                thesi = 54;
            }else if(i == 2){
                thesi= 55;
            }else if(i == 3){
                thesi = -1;
            }else
                thesi = 67 + i;
        }
        else if (k == 7){
            if(i == 1){
                thesi = 87;
            }else if(i == 2){
                thesi = 88;
            }else if(i == 3){
                thesi = -1;
            }else
                thesi = 99 + i;
        }

        else if (k == 8) {
            if(i >= 4 && i < 19){
                thesi = 52 + i;
            }
        }
        else if(k == 9){
            if(i >= 4 && i < 19){
                thesi = 84 + i;
            }
        }
        
        // Εκτύπωση στοιχείου ή κενού διαστήματος
        if (thesi >= 0 && thesi <= 117) {  
            if ((thesi + 1) >= minat && (thesi + 1) <= maxat && 
                atomic_masses[thesi] >= minmas && atomic_masses[thesi] <= maxmas) {
                printf("\033[31m%d:%s\033[0m\t", thesi + 1, element_symbols[thesi]);
            } else {
                printf("%d:%s\t", thesi + 1, element_symbols[thesi]);
            }
        } else {
            printf("\t");
        }
    }
    printf("\n");
}






     printf("\n 1 ---> Search individual\n 2---> Search group\n Any key ---> Exit the program\n Your Choice: ");
    scanf("%d", &ans);
    if(ans == 1){
        search();
        exit(1);
    }else if(ans == 2){
        groupsearch();
        exit(1);
    }else{
        exit(0);
    }
}