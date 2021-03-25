class DilamiCalendar{
    private:
        int dy, dm, dd;
        int jy, jm, jd;

        bool is_jalali_leap_year(int JalaliYear);
        bool is_dilami_leap_year(int DilamiYear);
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

        bool isLeap(bool isJalali = false);

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
    int leaps[769] = {4, 8, 12, 16, 20, 25, 29, 33, 37, 41, 45, 49, 53, 58, 62, 66, 70, 74, 78, 82, 86, 91, 95, 99, 103, 107, 111, 115, 120, 124, 128, 132, 136, 140, 144, 148, 153, 157, 161, 165, 169, 173, 177, 181, 186, 190, 194, 198, 202, 206, 210, 214, 219, 223, 227, 231, 235, 239, 243, 248, 252, 256, 260, 264, 268, 272, 276, 281, 285, 289, 293, 297, 301, 305, 309, 314, 318, 322, 326, 330, 334, 338, 342, 347, 351, 355, 359, 363, 367, 371, 376, 380, 384, 388, 392, 396, 400, 404, 409, 413, 417, 421, 425, 429, 433, 437, 442, 446, 450, 454, 458, 462, 466, 470, 474, 479, 483, 487, 491, 495, 499, 503, 508, 512, 516, 520, 524, 528, 532, 536, 541, 545, 549, 553, 557, 561, 565, 569, 574, 578, 582, 586, 590, 594, 598, 602, 607, 611, 615, 619, 623, 627, 631, 636, 640, 644, 648, 652, 656, 660, 664, 669, 673, 677, 681, 685, 689, 693, 697, 702, 706, 710, 714, 718, 722, 726, 730, 735, 739, 743, 747, 751, 755, 759, 764, 768, 772, 776, 780, 784, 788, 792, 797, 801, 805, 809, 813, 817, 821, 825, 830, 834, 838, 842, 846, 850, 854, 858, 863, 867, 871, 875, 879, 883, 887, 892, 896, 900, 904, 908, 912, 916, 920, 925, 929, 933, 937, 941, 945, 949, 953, 958, 962, 966, 970, 974, 978, 982, 986, 991, 995, 999, 1003, 1007, 1011, 1015, 1020, 1024, 1028, 1032, 1036, 1040, 1044, 1048, 1053, 1057, 1061, 1065, 1069, 1073, 1077, 1081, 1086, 1090, 1094, 1098, 1102, 1106, 1110, 1114, 1119, 1123, 1127, 1131, 1135, 1139, 1143, 1148, 1152, 1156, 1160, 1164, 1168, 1172, 1176, 1181, 1185, 1189, 1193, 1197, 1201, 1205, 1209, 1214, 1218, 1222, 1226, 1230, 1234, 1238, 1242, 1247, 1251, 1255, 1259, 1263, 1267, 1271, 1276, 1280, 1284, 1288, 1292, 1296, 1300, 1304, 1309, 1313, 1317, 1321, 1325, 1329, 1333, 1337, 1342, 1346, 1350, 1354, 1358, 1362, 1366, 1370, 1375, 1379, 1383, 1387, 1391, 1395, 1399, 1404, 1408, 1412, 1416, 1420, 1424, 1428, 1432, 1437, 1441, 1445, 1449, 1453, 1457, 1461, 1465, 1470, 1474, 1478, 1482, 1486, 1490, 1494, 1498, 1503, 1507, 1511, 1515, 1519, 1523, 1527, 1532, 1536, 1540, 1544, 1548, 1552, 1556, 1560, 1565, 1569, 1573, 1577, 1581, 1585, 1589, 1593, 1598, 1602, 1606, 1610, 1614, 1618, 1622, 1626, 1631, 1635, 1639, 1643, 1647, 1651, 1655, 1660, 1664, 1668, 1672, 1676, 1680, 1684, 1688, 1693, 1697, 1701, 1705, 1709, 1713, 1717, 1721, 1726, 1730, 1734, 1738, 1742, 1746, 1750, 1754, 1759, 1763, 1767, 1771, 1775, 1779, 1783, 1788, 1792, 1796, 1800, 1804, 1808, 1812, 1816, 1821, 1825, 1829, 1833, 1837, 1841, 1845, 1849, 1854, 1858, 1862, 1866, 1870, 1874, 1878, 1882, 1887, 1891, 1895, 1899, 1903, 1907, 1911, 1916, 1920, 1924, 1928, 1932, 1936, 1940, 1944, 1949, 1953, 1957, 1961, 1965, 1969, 1973, 1977, 1982, 1986, 1990, 1994, 1998, 2002, 2006, 2010, 2015, 2019, 2023, 2027, 2031, 2035, 2039, 2044, 2048, 2052, 2056, 2060, 2064, 2068, 2072, 2077, 2081, 2085, 2089, 2093, 2097, 2101, 2105, 2110, 2114, 2118, 2122, 2126, 2130, 2134, 2138, 2143, 2147, 2151, 2155, 2159, 2163, 2167, 2172, 2176, 2180, 2184, 2188, 2192, 2196, 2200, 2205, 2209, 2213, 2217, 2221, 2225, 2229, 2233, 2238, 2242, 2246, 2250, 2254, 2258, 2262, 2266, 2271, 2275, 2279, 2283, 2287, 2291, 2295, 2300, 2304, 2308, 2312, 2316, 2320, 2324, 2328, 2333, 2337, 2341, 2345, 2349, 2353, 2357, 2361, 2366, 2370, 2374, 2378, 2382, 2386, 2390, 2394, 2399, 2403, 2407, 2411, 2415, 2419, 2423, 2428, 2432, 2436, 2440, 2444, 2448, 2452, 2456, 2461, 2465, 2469, 2473, 2477, 2481, 2485, 2489, 2494, 2498, 2502, 2506, 2510, 2514, 2518, 2522, 2527, 2531, 2535, 2539, 2543, 2547, 2551, 2556, 2560, 2564, 2568, 2572, 2576, 2580, 2584, 2589, 2593, 2597, 2601, 2605, 2609, 2613, 2617, 2622, 2626, 2630, 2634, 2638, 2642, 2646, 2650, 2655, 2659, 2663, 2667, 2671, 2675, 2679, 2684, 2688, 2692, 2696, 2700, 2704, 2708, 2712, 2717, 2721, 2725, 2729, 2733, 2737, 2741, 2745, 2750, 2754, 2758, 2762, 2766, 2770, 2774, 2778, 2783, 2787, 2791, 2795, 2799, 2803, 2807, 2812, 2816, 2820, 2824, 2828, 2832, 2836, 2840, 2845, 2849, 2853, 2857, 2861, 2865, 2869, 2873, 2878, 2882, 2886, 2890, 2894, 2898, 2902, 2906, 2911, 2915, 2919, 2923, 2927, 2931, 2935, 2940, 2944, 2948, 2952, 2956, 2960, 2964, 2968, 2973, 2977, 2981, 2985, 2989, 2993, 2997, 3001, 3006, 3010, 3014, 3018, 3022, 3026, 3030, 3034, 3039, 3043, 3047, 3051, 3055, 3059, 3063, 3068, 3072, 3076, 3080, 3084, 3088, 3092, 3096, 3101, 3105, 3109, 3113, 3117, 3121, 3125, 3129, 3134, 3138, 3142, 3146, 3150, 3154, 3158, 3162, 3167, 3171, 3175};
    for (int i=1; i<769; ++i)
        if (JalaliYear == leaps[i])
            return true;
    return false;
}

bool DilamiCalendar::is_dilami_leap_year(int DilamiYear){
    int leaps[678] = {203, 207, 211, 215, 220, 224, 228, 232, 236, 240, 244, 248, 253, 257, 261, 265, 269, 273, 277, 281, 286, 290, 294, 298, 302, 306, 310, 315, 319, 323, 327, 331, 335, 339, 343, 348, 352, 356, 360, 364, 368, 372, 376, 381, 385, 389, 393, 397, 401, 405, 409, 414, 418, 422, 426, 430, 434, 438, 443, 447, 451, 455, 459, 463, 467, 471, 476, 480, 484, 488, 492, 496, 500, 504, 509, 513, 517, 521, 525, 529, 533, 537, 542, 546, 550, 554, 558, 562, 566, 571, 575, 579, 583, 587, 591, 595, 599, 604, 608, 612, 616, 620, 624, 628, 632, 637, 641, 645, 649, 653, 657, 661, 665, 669, 674, 678, 682, 686, 690, 694, 698, 703, 707, 711, 715, 719, 723, 727, 731, 736, 740, 744, 748, 752, 756, 760, 764, 769, 773, 777, 781, 785, 789, 793, 797, 802, 806, 810, 814, 818, 822, 826, 831, 835, 839, 843, 847, 851, 855, 859, 864, 868, 872, 876, 880, 884, 888, 892, 897, 901, 905, 909, 913, 917, 921, 925, 930, 934, 938, 942, 946, 950, 954, 959, 963, 967, 971, 975, 979, 983, 987, 992, 996, 1000, 1004, 1008, 1012, 1016, 1020, 1025, 1029, 1033, 1037, 1041, 1045, 1049, 1053, 1058, 1062, 1066, 1070, 1074, 1078, 1082, 1087, 1091, 1095, 1099, 1103, 1107, 1111, 1115, 1120, 1124, 1128, 1132, 1136, 1140, 1144, 1148, 1153, 1157, 1161, 1165, 1169, 1173, 1177, 1181, 1186, 1190, 1194, 1198, 1202, 1206, 1210, 1215, 1219, 1223, 1227, 1231, 1235, 1239, 1243, 1248, 1252, 1256, 1260, 1264, 1268, 1272, 1276, 1281, 1285, 1289, 1293, 1297, 1301, 1305, 1309, 1314, 1318, 1322, 1326, 1330, 1334, 1338, 1343, 1347, 1351, 1355, 1359, 1363, 1367, 1371, 1376, 1380, 1384, 1388, 1392, 1396, 1400, 1404, 1409, 1413, 1417, 1421, 1425, 1429, 1433, 1437, 1442, 1446, 1450, 1454, 1458, 1462, 1466, 1471, 1475, 1479, 1483, 1487, 1491, 1495, 1499, 1504, 1508, 1512, 1516, 1520, 1524, 1528, 1532, 1537, 1541, 1545, 1549, 1553, 1557, 1561, 1565, 1570, 1574, 1578, 1582, 1586, 1590, 1594, 1599, 1603, 1607, 1611, 1615, 1619, 1623, 1627, 1632, 1636, 1640, 1644, 1648, 1652, 1656, 1660, 1665, 1669, 1673, 1677, 1681, 1685, 1689, 1693, 1698, 1702, 1706, 1710, 1714, 1718, 1722, 1727, 1731, 1735, 1739, 1743, 1747, 1751, 1755, 1760, 1764, 1768, 1772, 1776, 1780, 1784, 1788, 1793, 1797, 1801, 1805, 1809, 1813, 1817, 1821, 1826, 1830, 1834, 1838, 1842, 1846, 1850, 1855, 1859, 1863, 1867, 1871, 1875, 1879, 1883, 1888, 1892, 1896, 1900, 1904, 1908, 1912, 1916, 1921, 1925, 1929, 1933, 1937, 1941, 1945, 1949, 1954, 1958, 1962, 1966, 1970, 1974, 1978, 1983, 1987, 1991, 1995, 1999, 2003, 2007, 2011, 2016, 2020, 2024, 2028, 2032, 2036, 2040, 2044, 2049, 2053, 2057, 2061, 2065, 2069, 2073, 2077, 2082, 2086, 2090, 2094, 2098, 2102, 2106, 2111, 2115, 2119, 2123, 2127, 2131, 2135, 2139, 2144, 2148, 2152, 2156, 2160, 2164, 2168, 2172, 2177, 2181, 2185, 2189, 2193, 2197, 2201, 2205, 2210, 2214, 2218, 2222, 2226, 2230, 2234, 2239, 2243, 2247, 2251, 2255, 2259, 2263, 2267, 2272, 2276, 2280, 2284, 2288, 2292, 2296, 2300, 2305, 2309, 2313, 2317, 2321, 2325, 2329, 2333, 2338, 2342, 2346, 2350, 2354, 2358, 2362, 2367, 2371, 2375, 2379, 2383, 2387, 2391, 2395, 2400, 2404, 2408, 2412, 2416, 2420, 2424, 2428, 2433, 2437, 2441, 2445, 2449, 2453, 2457, 2461, 2466, 2470, 2474, 2478, 2482, 2486, 2490, 2495, 2499, 2503, 2507, 2511, 2515, 2519, 2523, 2528, 2532, 2536, 2540, 2544, 2548, 2552, 2556, 2561, 2565, 2569, 2573, 2577, 2581, 2585, 2589, 2594, 2598, 2602, 2606, 2610, 2614, 2618, 2623, 2627, 2631, 2635, 2639, 2643, 2647, 2651, 2656, 2660, 2664, 2668, 2672, 2676, 2680, 2684, 2689, 2693, 2697, 2701, 2705, 2709, 2713, 2717, 2722, 2726, 2730, 2734, 2738, 2742, 2746, 2751, 2755, 2759, 2763, 2767, 2771, 2775, 2779, 2784, 2788, 2792, 2796, 2800, 2804, 2808, 2812, 2817, 2821, 2825, 2829, 2833, 2837, 2841, 2845, 2850, 2854, 2858, 2862, 2866, 2870, 2874, 2879, 2883, 2887, 2891, 2895, 2899, 2903, 2907, 2912, 2916, 2920, 2924, 2928, 2932, 2936, 2940, 2945, 2949, 2953, 2957, 2961, 2965, 2969, 2973, 2978, 2982, 2986, 2990, 2994, 2998};
    for (int i=1; i<678; ++i)
        if (DilamiYear == leaps[i])
            return true;
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


bool DilamiCalendar::isLeap(bool isJalali){
    if (isJalali)
        return is_jalali_leap_year(jy);
    else
        return is_dilami_leap_year(dy);
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

