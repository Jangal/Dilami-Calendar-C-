class DilamiCalendar{
    private:
        int dy, dm, dd;
        int jy, jm, jd;

        bool is_jalali_leap_year(int JalaliYear);
        void jalali_to_dilami(int JalaliYear, int JalaliMonth, int JalaliDay);
        void dilami_to_jalali(int DilamiYear, int DilamiMonth, int DilamiDay);
    public:
        DilamiCalendar(int JalaliYear, int JalaliMonth, int JalaliDay){
            jalali_to_dilami(JalaliYear, JalaliMonth, JalaliDay);
            jy = JalaliYear;
            jm = JalaliMonth;
            jd = JalaliDay;
        }

        int getDilamiYear();
        int getDilamiMonth();
        int getDilamiDay();

        bool isLeap();

        int getJalaliYear();
        int getJalaliMonth();
        int getJalaliDay();

        void setDilamiYear(int Year);
        void setDilamiMonth(int Month);
        void setDilamiDay(int Day);

        void setJalaliYear(int Year);
        void setJalaliMonth(int Month);
        void setJalaliDay(int Day);

        void setDilamiDate(int DilamiYear, int DilamiMonth, int DilamiDay);
        void setJalaliDate(int JalaliYear, int JalaliMonth, int JalaliDay);
};

bool DilamiCalendar::is_jalali_leap_year(int JalaliYear){
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


void DilamiCalendar::jalali_to_dilami(int JalaliYear, int JalaliMonth, int JalaliDay){
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
        if ((k == 0) && (JalaliDay == 15)){
            DilamiMonth = 0;
            DilamiDay = 0;
        }
        else if ((k == 0) && (JalaliDay < 15)){
            DilamiMonth = 8;
            DilamiDay = JalaliDay + 16;
        }
        else if (k == 1 && (JalaliDay < 16)){
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

    dy = DilamiYear;
    dm = DilamiMonth;
    dd = DilamiDay;
}


void DilamiCalendar::dilami_to_jalali(int DilamiYear, int DilamiMonth, int DilamiDay){
    int JalaliYear = 0;
    int JalaliMonth = 0;
    int JalaliDay = 0;
    int k = 0;

    if (DilamiMonth == 0){
        JalaliYear = DilamiYear - 194;
    }
    else if (DilamiMonth < 8 || (DilamiMonth == 8 && DilamiDay <= 15)){
        JalaliYear = DilamiYear - 195;
    }
    else{
        JalaliYear = DilamiYear - 194;
    }

    if (is_jalali_leap_year(JalaliYear)){
        k = 1;
    }

    if (DilamiMonth == 0 && DilamiDay == 0){
        JalaliMonth = 1;
        JalaliDay = 15;

        jy = JalaliYear;
        jm = JalaliMonth;
        jd = JalaliDay;
        return;
    }

    if (DilamiMonth == 0){
        JalaliMonth = 1;
        JalaliDay = DilamiDay + 15;

        jy = JalaliYear;
        jm = JalaliMonth;
        jd = JalaliDay;
        return;
    }

    if (DilamiMonth == 1){
        if (DilamiDay <= 15)
            JalaliMonth = 5;
        else
            JalaliMonth = 6;

        if (DilamiDay <= 15)
            JalaliDay = DilamiDay + 16;
        else
            JalaliDay = DilamiDay - 15;
    }
    else if (DilamiMonth == 2){
        if (DilamiDay <= 16)
            JalaliMonth = 6;
        else
            JalaliMonth = 7;

        if (DilamiDay <= 16)
            JalaliDay = DilamiDay + 15;
        else
            JalaliDay = DilamiDay - 16;
    }
    else if (DilamiMonth == 3){
        if (DilamiDay <= 16)
            JalaliMonth = 7;
        else
            JalaliMonth = 8;

        if (DilamiDay <= 16)
            JalaliDay = DilamiDay + 14;
        else
            JalaliDay = DilamiDay - 16;
    }
    else if (DilamiMonth == 4){
        if (DilamiDay <= 16)
            JalaliMonth = 8;
        else
            JalaliMonth = 9;

        if (DilamiDay <= 16)
            JalaliDay = DilamiDay + 14;
        else
            JalaliDay = DilamiDay - 16;
    }
    else if (DilamiMonth == 5){
        if (DilamiDay <= 16)
            JalaliMonth = 9;
        else
            JalaliMonth = 10;

        if (DilamiDay <= 16)
            JalaliDay = DilamiDay + 14;
        else
            JalaliDay = DilamiDay - 16;
    }
    else if (DilamiMonth == 6){
        if (DilamiDay <= 16)
            JalaliMonth = 10;
        else
            JalaliMonth = 11;

        if (DilamiDay <= 16)
            JalaliDay = DilamiDay + 14;
        else
            JalaliDay = DilamiDay - 16;
    }
    else if (DilamiMonth == 7){
        if (DilamiDay <= 16)
            JalaliMonth = 11;
        else
            JalaliMonth = 12;

        if (DilamiDay <= 16)
            JalaliDay = DilamiDay + 14;
        else
            JalaliDay = DilamiDay - 16;
    }
    else if (DilamiMonth == 8){
        if (k == 0)
            k == 1;
        else
            k == 0;

        if (DilamiDay <= (15 + k))
            JalaliMonth = 12;
        else
            JalaliMonth = 1;

        if (DilamiDay <= (15 + k))
            JalaliDay = DilamiDay + 14;
        else
            JalaliDay = DilamiDay - 15 - k;

        if (k == 1 && DilamiDay == 16){
            JalaliYear = JalaliYear - 1;
        }
    }
    else if (DilamiMonth == 9){
        if (DilamiDay <= 16)
            JalaliMonth = 1;
        else
            JalaliMonth = 2;

        if (DilamiDay <= 16)
            JalaliDay = DilamiDay + 20;
        else
            JalaliDay = DilamiDay - 11;
    }
    else if (DilamiMonth == 10){
        if (DilamiDay <= 16)
            JalaliMonth = 2;
        else
            JalaliMonth = 3;

        if (DilamiDay <= 16)
            JalaliDay = DilamiDay + 19;
        else
            JalaliDay = DilamiDay - 12;
    }
    else if (DilamiMonth == 11){
        if (DilamiDay <= 16)
            JalaliMonth = 3;
        else
            JalaliMonth = 4;

        if (DilamiDay <= 16)
            JalaliDay = DilamiDay + 18;
        else
            JalaliDay = DilamiDay - 13;
    }
    else if (DilamiMonth == 12){
        if (DilamiDay <= 16)
            JalaliMonth = 4;
        else
            JalaliMonth = 5;

        if (DilamiDay <= 16)
            JalaliDay = DilamiDay + 17;
        else
            JalaliDay = DilamiDay - 14;
    }

    jy = JalaliYear;
    jm = JalaliMonth;
    jd = JalaliDay;
    return;
}


int DilamiCalendar::getDilamiYear(){
    jalali_to_dilami(jy, jm, jd);
    return dy;
}


int DilamiCalendar::getDilamiMonth(){
    jalali_to_dilami(jy, jm, jd);
    return dm;
}


int DilamiCalendar::getDilamiDay(){
    jalali_to_dilami(jy, jm, jd);
    return dd;
}


bool DilamiCalendar::isLeap(){
    return is_jalali_leap_year(jy);
}


int DilamiCalendar::getJalaliYear(){
    dilami_to_jalali(dy, dm, dd);
    return jy;
}


int DilamiCalendar::getJalaliMonth(){
    dilami_to_jalali(dy, dm, dd);
    return jm;
}


int DilamiCalendar::getJalaliDay(){
    dilami_to_jalali(dy, dm, dd);
    return jd;
}


void DilamiCalendar::setDilamiYear(int Year){
    dy = Year;
}


void DilamiCalendar::setDilamiMonth(int Month){
    dm = Month;
}


void DilamiCalendar::setDilamiDay(int Day){
    dd = Day;
}


void DilamiCalendar::setJalaliYear(int Year){
    jy = Year;
}


void DilamiCalendar::setJalaliMonth(int Month){
    jm = Month;
}


void DilamiCalendar::setJalaliDay(int Day){
    jd = Day;
}


void DilamiCalendar::setDilamiDate(int DilamiYear, int DilamiMonth, int DilamiDay){
    dy = DilamiYear;
    dm = DilamiMonth;
    dd = DilamiDay;
    dilami_to_jalali(DilamiYear, DilamiMonth, DilamiDay);
};


void DilamiCalendar::setJalaliDate(int JalaliYear, int JalaliMonth, int JalaliDay){
    jy = JalaliYear;
    jm = JalaliMonth;
    jd = JalaliDay;
    jalali_to_dilami(JalaliYear, JalaliMonth, JalaliDay);
};

