
# C++ Dilami Calendar

## Install

Just download [dilami_calendar.h](https://github.com/LordArma/Dilami-Calendar-C-/blob/master/dilami_calendar.h "dilami_calendar.cpp") and copy it near your project.


## Example

```C++
#include <iostream>
#include "dilami_calendar.h"

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

    return 0;
}

```

## Maybe You Like
[Python Dilami Calendar](https://github.com/Jangal/python-dilami-calendar)
<br/>
[Arduino Dilami Calendar](https://github.com/LordArma/Dilami-Calendar-Arduino)
<br/>
[.Net Dilami Calendar](https://github.com/Jangal/Dilami-Calendar-.Net)
<br/>
[تقویم دیلمی](http://giltime.ir)
