#include <iostream>
#include "dilami_calendar.cpp"

using namespace std;

int main(){
    DilamiCalendar dc(1398, 12, 2);
    cout << "Dilami Day: " << dc.getDilamiDay() << endl;
    cout << "Dilami Month: " << dc.getDilamiMonth() << endl;
    cout << "Dilami Year: " << dc.getDilamiYear() << endl;
    cout << endl;

    cout << "Is " << dc.getDilamiYear() << " leap year? " << endl;
    if (dc.isLeap()){
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

    dc.setJalaliYear(1399);
    return 0;
}
