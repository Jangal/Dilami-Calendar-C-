
# C++ Dilami Calendar

## Install

Just download [dilami_calendar.cpp](https://github.com/LordArma/Dilami-Calendar-C-/blob/master/dilami_calendar.cpp "dilami_calendar.cpp") and copy it near your project.


## Example

```C++
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

```

## Maybe You Like
[Python Dilami Calendar](https://github.com/Jangal/python-dilami-calendar)
[تقویم دیلمی](http://giltime.ir)