#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Green_In = 12;
int Red_In = 7;
int Yellow_In = 13;

int Light_Pins[] = { Green_In, Red_In, Yellow_In };

int chooseRandom(int max);

int main() {

    int Light_Pins[] = { Green_In, Red_In, Yellow_In };

    printf("Turn off the light at pins %d, %d, and %d\n", Light_Pins[0],
        Light_Pins[1], Light_Pins[2]);

    // choose which light to turn on
    int Old_Rand_Num = 1;
    
    // turn on the first choice of light
    printf("Turn on the light at pin %d.\n", Light_Pins[Old_Rand_Num]);

    //choose random number between 0 and 2
    srand(time(0));
    int Number_Of_Options = sizeof(Light_Pins) / sizeof(Light_Pins[0]);

    int new_Rand = chooseRandom(Number_Of_Options);


    while (Old_Rand_Num == new_Rand) {

        printf("Same as before\n");

        // choose a different light
        new_Rand = chooseRandom(Number_Of_Options);
    }

    printf("Turn on the light at pin %d\n", Light_Pins[new_Rand]);
    printf("Turn off the light at pin %d\n", Light_Pins[Old_Rand_Num]);
}


//choose a random number between 0 and 2; 
//take in the size of the array size to be chosen from

int chooseRandom(int max) {

    int lower = 0;

    //choose the number
    int num = (rand() %
        (max - lower + 1)) + lower;
   
    return num;
}







