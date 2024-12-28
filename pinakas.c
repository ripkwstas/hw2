#include <stdio.h>
#include <stdlib.h>

int screenf1();
int screenf2();
int screenf4();
int screenf6();

int main(){
    int ans1, check = 4, check1 = 4, check2 = 4, check3 = 4;

        while(check > 3 || check < 1){
        check = screenf1(); // καλουμαι την πρωτη οθόνη
        }

        switch(check){
            case 1:
                while(check1 > 3 || check1 < 1){
                    check1 = screenf2();
                }
                break;
            case 2: 
                while(check2 > 3 || check2 < 1){
                    check2 = screenf4();
                }
                break;
            case 3:
                while(check3 > 3 || check3 < 1){
                    check3 = screenf6();
                }
                break;
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

