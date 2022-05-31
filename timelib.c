#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"



/**
 * Funktion überprüft Gültigkeit des Datums, gibt eine Eins bei Gültigkeit zurück
 * eine Null bei Ungültigkeit.
 * @param: tag, monat, jahr
**/
int exists_date(struct datum daten)
{
    int date_exists;
    if (daten.jahr >= 1582 && daten.jahr <= 2400)
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
int is_leap_year(struct datum daten)
{
    int schalt, rest;
    rest = daten.jahr % 4;
    if (rest == 0)
    {
       rest = daten.jahr % 100;
       if (rest == 0)
       {
          rest = daten.jahr % 400;
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
int get_days_for_month(struct datum daten)
{
    int monatstage[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

    if (daten.monat >= 1 && daten.monat <= 12)
    {
        if (daten.monat == 2)
        {
            if (is_leap_year(daten.jahr))
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
            return monatstage[daten.monat-1];
        }
    }
    else
    {
        return -1;
    }
}

/**
 * Der Funktion werden Tag, Monat und Jahr übergeben.
 * Rückgabewert ist der Tag des jahres.
 **/
int day_of_the_year(struct datum daten)
{
    int rest, schalt, gueltige_angabe;

    printf("Dies ist ein Rechner fuer die Zahl des Tages!\n");
    printf("Bitte Jahr angeben:\n");
    scanf("%i",&daten.jahr);

    if (exists_date(daten) == 0)
    {
        printf("Datum muss zwischen dem 1.1.1582 und dem 31.12.2400 liegen.");
        return 0;
    }

    int anzahl[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    schalt = is_leap_year(daten.jahr);
    if (schalt == 1)
    {
        printf("Hinweis: Angegebenes Jahr ist ein Schaltjahr.\n");
        anzahl[1] = 29;
    }

    gueltige_angabe = 0;
    while(gueltige_angabe == 0)
    {
        printf("Bitte Monat angeben:\n");
        scanf("%i",&daten.monat);
        if (get_days_for_month(daten.monat, daten.jahr) != -1)
        {
            gueltige_angabe = 1;
        }
        else
        {
            printf("Monatsangabe muss zwischen 1 und 12 liegen.\n");
        }
    }

    gueltige_angabe = 0;
    while (gueltige_angabe == 0)
    {
        printf("Bitte Tag angeben:\n");
        scanf("%i",&daten.tag);
        if (daten.tag >= 0 && daten.tag <= anzahl[daten.monat -1])
        {
            gueltige_angabe = 1;
        }
        else
        {
            printf("Angabe liegt ausserhalb des gueltigen Bereiches.\n");
        }
    }

    int ergebnis = 0;

    for (int i = 0; i< daten.monat-1; i++)
    {
        ergebnis+=anzahl[i];
    }
    ergebnis+=daten.tag;

    printf("\nDer %i.%i. ist der %i. Tag des Jahres %i\n.", daten.tag, daten.monat, ergebnis, daten.jahr);


    return 0;
}
