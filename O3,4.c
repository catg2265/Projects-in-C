#include <stdio.h>
#include <stdlib.h>
/* Konstanter for antal sekunder pr. time eller minut defineres */
#define HOURS 3600
#define MINUTES 60

int main(void){
    /* De forskellige variabler deklareres */
    int sec, min, hr, minmod, hrmod;
    /* Der bedes om input, hvorefter dette bliver scannet ind fra konsollen */
    printf("Input seconds: ");
    scanf(" %d", &sec);
    /* Antal timer, minutter og resterende sekunder beregnes og bliver assignet til ver deres variabel */
    hr = sec / HOURS;
    hrmod = sec % HOURS;
    min = hrmod / MINUTES;
    minmod = hrmod % MINUTES;
    sec = minmod;
    /* Hvis timer, minutter eller sekunder er højere større end 0, så fortsætter den videre til endnu en if sætning
    der determinere om enheden skal skrives i ental eller flertal ved brug af betingede udtryk*/
    if (hr > 0){
        printf(" %d %s", hr, hr > 1 ? "Hours" : hr == 1 ? "Hour" : "");    
    }
    if (min > 0){
        printf(" %d %s", min, min > 1 ? "Minutes" : min == 1 ? "Minute" : "");
    }
    if (sec > 0){
        printf(" %d %s", sec, sec > 1 ? "Seconds" : sec == 1 ? "Second" : "");
    }
    /* Koden afsluttes */
    return EXIT_SUCCESS;
}