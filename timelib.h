#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

/**
 * Funktion �berpr�ft G�ltigkeit des Datums, gibt eine Eins bei G�ltigkeit zur�ck
 * eine Null bei Ung�ltigkeit.
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
 * R�ckgabewert, Schlatjahr True, False
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
 * Funktion gibt die anzahl der Tage innerhalb eines angegebenen Monats zur�ck
 * Schaltjahre werden ber�cksichtigt.
 * @param: monat, jahr
**/
int get_days_for_month(int monat, int jahr)
{
    int monatstage[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

    if (monat >= 1 && monat <= 12)
    {
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
    else
    {
        return -1;
    }

}

/**
 * Der Funktion werden Tag, Monat und Jahr �bergeben.
 * R�ckgabewert ist der Tag des jahres.
 **/
int day_of_the_year(int day, int month, int year)
{
    int jahr, monat, tag, rest, schalt, gueltige_angabe;

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
        anzahl[1] = 29;
    }

    gueltige_angabe = 0;
    while(gueltige_angabe == 0)
    {
        printf("Bitte Monat angeben:\n");
        scanf("%i",&monat);
        if (get_days_for_month(monat, jahr) != -1)
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
        scanf("%i",&tag);
        if (tag >= 0 && tag <= anzahl[monat -1])
        {
            gueltige_angabe = 1;
        }
        else
        {
            printf("Angabe liegt ausserhalb des gueltigen Bereiches.\n");
        }

    }

    int ergebnis = 0;

    for (int i = 0; i< monat-1; i++)
    {
        ergebnis+=anzahl[i];
    }
    ergebnis+=tag;

    printf("\nDer %i.%i. ist der %i. Tag des Jahres %i\n.", tag, monat, ergebnis, jahr);


    return 0;
}



#endif // TIMELIB_H_INCLUDED
