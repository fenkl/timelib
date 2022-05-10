/**
 * Timelib
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>


/**
 * Funktion überprüft Gültigkeit des Datums, gibt eine Eins bei Gültigkeit zurück
 * eine Null bei Ungültigkeit.
 * @param: tag, monat, jahr
**/
int exists_date(int tag, int monat, int jahr)
{
    int date_exists;
    if (jahr >= 1582 && jahr <= 2400)
    {
        date_exists = 1;
        return date_exists;
    }
    else
    {
        date_exists = 0;
        return date_exists;
    }
}


/**
 * @ param jahr
 * Rückgabewert, Schlatjahr True, False
**/
int is_leap_year(int jahr)
{
    int schalt, rest;
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
 * Funktion gibt die anzahl der Tage innerhalb eines angegebenen Monats zurück
 * Schaltjahre werden berücksichtigt.
 * @param: monat, jahr
**/
int get_days_for_month(int monat, int jahr)
{
    int monatstage[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if (monat == 2)
    {
        if (is_leap_year(jahr))
        {
            return 29;
        }
        else
        {
            return monatstage[1];
        }
    }
    else
    {
        return monatstage[monat-1];
    }



}

/**
 * Der Funktion werden Tag, Monat und Jahr übergeben.
 * Rückgabewert ist der Tag des jahres.
 **/
int day_of_the_year(int day, int month, int year)
{
    int jahr, monat, tag, rest, schalt;
    printf("Dies ist ein Rechner fuer die Zahl des Tages!\n");
    printf("Bitte Jahr angeben:\n");
    scanf("%i",&jahr);

    if (exists_date(tag, monat, jahr) == 0)
    {
        printf("Datum muss zwischen dem 1.1.1582 und dem 31.12.2400 liegen.");
        return 0;
    }

    int anzahl[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    schalt = is_leap_year(jahr);
    if (schalt == 1)
    {
        printf("Hinweis: Angegebenes Jahr ist ein Schaltjahr.\n");
        anzahl[1] =29;
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

    printf("\nDer angegebene Tag ist der %i Tag des Jahres %i\n", ergebnis, jahr);


    return 0;
}


int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
