/**
 * Timelib
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>



int is_leap_year(int jahr)
{
    if (jahr < 1582)
    {
        return -1
    } 
    int schalt, rest
    rest = jahr % 4;
    if (rest == 0)
    {
       rest = jahr % 100;
       if (rest == 0)
       {
          rest = jahr % 400;
          if(rest != 0)
          {
             schalt = 0;
          }
          else
          {
             schalt = 1;
          }
       }
       else
       {
          schalt = 1;
       }
    }
    else
    {
       schalt=0;
    }

    return schalt;





}

/**
 * Der Funktion werden Tag, Monat und Jahr übergeben.
 * Rückgabewert ist der Tag des jahres.
 **/
int day_of_the_year(int day, int month, int year)
{
    int jahr, monat, tag, rest, schalt;
    printf("Dies ist ein Rechner f�r die Zahl des Tages!\n");
    printf("Bitte Jahr angeben:\n");
    scanf("%i",&jahr);


    int anzahl[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    schalt = is_leap_year(jahr)
    if (is_leap_year == 1)
    {
       anzahl[1] =29;
    }
    else if (is_leap_year == -1)
    {
        printf("Jahresangabe muss nach 1582 sein.");
    }

    do{
      printf("Bitte Monat angeben:\n");
      scanf("%i",&monat);}
    while(monat<=0 || monat>12 );

    do{
      printf("Bitte Tag angeben:\n");
      scanf("%i",&tag);}
    while(tag> anzahl[monat-1] || tag<=0);

    int ergebnis = 0;

    for (int i = 0; i< monat-1; i++)
    {
    ergebnis+=anzahl[i];
    }
    ergebnis+=tag;

    printf("\n Der angegebene Tag ist der %i Tag des Jahres %i\n", ergebnis, jahr);


    return 0;
}


int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
