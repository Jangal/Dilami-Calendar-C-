#include <iostream>

using namespace std;

const char * DAY_NAMES[] { "Shambeh", "Yekshambeh", "Doushambeh", "Soushambeh", "Charshambeh", "Panshanbeh", "Joumeh" };
const char * MONTH_NAMES[] { "Panjik", "Norouzma", "Kourchema", "Arema", "Tirma", "Mourdalma", "Sharirma", "Amirma", "Avalma", "Siama", "Diama", "Varfanema", "Esfandarma" };

bool is_jalali_leap_year(int JalaliYear){
    int leaps[47] = { 4, 37, 66, 99, 132, 165, 198, 231, 264, 297, 326
                         , 359, 392, 425, 458, 491, 524, 553, 586, 619, 656, 685, 718, 751, 784, 817
                         , 850, 883, 916, 949, 978, 1011, 1044, 1077, 1110, 1143, 1176, 1209, 1238
                         , 1275, 1308, 1343, 1370, 1401, 1436, 1473, 1502 };

    int z = 0;
    for (int i = 0; i <= JalaliYear; i += 4) {

        if (i > leaps[z]) {
            i++;
            z++;
        }

        if (JalaliYear == i) {
            return true;
        }
    }
    return false;
}

int y = 0;
int m = 0;
int d = 0;

void jalali_to_dilami(int JalaliYear, int JalaliMonth, int JalaliDay)
{
    int DilamiYear = 0;
    int DilamiMonth = 0;
    int DilamiDay = 0;
    int k = 0;

    if ((JalaliMonth < 5) || ((JalaliMonth == 5) && (JalaliDay < 17))){
        DilamiYear = JalaliYear + 194;
    }
    else
    {
        DilamiYear = JalaliYear + 195;
    }

    DilamiDay = 0;
    DilamiMonth = 0;
    k = 0;

    if (is_jalali_leap_year(JalaliYear)){
        DilamiDay = 6;
        DilamiMonth = 0;
        k = 1;
    }

    if (JalaliMonth == 5){
        if (JalaliDay > 16)
            DilamiMonth = 1;
        else
            DilamiMonth = 12;

        if (JalaliDay > 16)
            DilamiDay = JalaliDay - 16;
        else
            DilamiDay = JalaliDay + 14;
    }
    else if (JalaliMonth == 6){
        if (JalaliDay > 15)
            DilamiMonth = 2;
        else
            DilamiMonth = 1;

        if (JalaliDay > 15)
            DilamiDay = JalaliDay - 15;
        else
            DilamiDay = JalaliDay + 15;
    }
    else if (JalaliMonth == 7){
        if (JalaliDay > 14)
            DilamiMonth = 3;
        else
            DilamiMonth = 2;

        if (JalaliDay > 14)
            DilamiDay = JalaliDay - 14;
        else
            DilamiDay = JalaliDay + 16;
    }
    else if (JalaliMonth == 8){
        if (JalaliDay > 14)
            DilamiMonth = 4;
        else
            DilamiMonth = 3;

        if (JalaliDay > 14)
            DilamiDay = JalaliDay - 14;
        else
            DilamiDay = JalaliDay + 16;
    }
    else if (JalaliMonth == 9){
        if (JalaliDay > 14)
            DilamiMonth = 5;
        else
            DilamiMonth = 4;

        if (JalaliDay > 14)
            DilamiDay = JalaliDay - 14;
        else
            DilamiDay = JalaliDay + 16;
    }
    else if (JalaliMonth == 10){
        if (JalaliDay > 14)
            DilamiMonth = 6;
        else
            DilamiMonth = 5;

        if (JalaliDay > 14)
            DilamiDay = JalaliDay - 14;
        else
            DilamiDay = JalaliDay + 16;
    }
    else if (JalaliMonth == 11){
        if (JalaliDay > 14)
            DilamiMonth = 7;
        else
            DilamiMonth = 6;

        if (JalaliDay > 14)
            DilamiDay = JalaliDay - 14;
        else
            DilamiDay = JalaliDay + 16;
    }
    else if (JalaliMonth == 12){
        if (JalaliDay > 14)
            DilamiMonth = 8;
        else
            DilamiMonth = 7;

        if (JalaliDay > 14)
            DilamiDay = JalaliDay - 14;
        else
            DilamiDay = JalaliDay + 16;
    }
    else if (JalaliMonth == 1){
        if ((k == 1) && (JalaliDay == 15)){
            DilamiMonth = 0;
            DilamiDay = 0;
        }
        else if ((k == 1) && (JalaliDay < 15)){
            DilamiMonth = 8;
            DilamiDay = JalaliDay + 16;
        }
        else if (k == 0 && (JalaliDay < 16)){
            DilamiMonth = 8;
            DilamiDay = JalaliDay + 15;
        }
        else if ((JalaliDay > 15) && (JalaliDay < 21)){
            DilamiMonth = 0;
            DilamiDay = JalaliDay - 15;
        }
        else if (JalaliDay > 20){
            DilamiMonth = 9;
            DilamiDay = JalaliDay - 20;
        }
    }
    else if (JalaliMonth == 2){
        if (JalaliDay > 19)
            DilamiMonth = 10;
        else
            DilamiMonth = 9;

        if (JalaliDay > 19)
            DilamiDay = JalaliDay - 19;
        else
            DilamiDay = JalaliDay + 11;
    }
    else if (JalaliMonth == 3){
        if (JalaliDay > 18)
            DilamiMonth = 11;
        else
            DilamiMonth = 10;

        if (JalaliDay > 18)
            DilamiDay = JalaliDay - 18;
        else
            DilamiDay = JalaliDay + 12;
    }
    else if (JalaliMonth == 4){
        if (JalaliDay > 17)
            DilamiMonth = 12;
        else
            DilamiMonth = 11;

        if (JalaliDay > 17)
            DilamiDay = JalaliDay - 17;
        else
            DilamiDay = JalaliDay + 13;
    }

    y = DilamiYear;
    m = DilamiMonth;
    d = DilamiDay;
}

int main(){


    jalali_to_dilami(1398, 9, 30);
    cout << y << " " << MONTH_NAMES[m] << " " << d;

    return 0;
}
