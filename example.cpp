#include <iostream>
#include "dilami_calendar.h"

using namespace std;

int main(){
    DilamiCalendar dc(1400, 1, 5);
    cout << "Dilami Day: " << dc.getDilamiDay() << endl;
    cout << "Dilami Month: " << dc.getDilamiMonth() << endl;
    cout << "Dilami Year: " << dc.getDilamiYear() << endl;
    cout << endl;

    cout << "Is " << dc.getDilamiYear() << " leap year? " << endl;
    if (dc.isLeap(false)){
        cout << "Yes!" << endl;
    }
    else{
        cout << "No!" << endl;
    }
    cout << endl;


    cout << "Jalali Day: " << dc.getJalaliDay() << endl;
    cout << "Jalali Month: " << dc.getJalaliMonth() << endl;
    cout << "Jalali Year: " << dc.getJalaliYear() << endl;
    cout << endl;

    cout << "Is " << dc.getJalaliYear() << " leap year? " << endl;
    if (dc.isLeap(true)){
        cout << "Yes!" << endl;
    }
    else{
        cout << "No!" << endl;
    }
    cout << endl;

    return 0;
}
