#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

struct datum {
    int tag;
    int monat;
    int jahr;
};

// Funktionsprototypen

int exists_date(datum);

int is_leap_year(datum);

int get_days_for_month(datum);

int day_of_the_year(datum);




#endif // TIMELIB_H_INCLUDED
