class Solution {
public:
    vector<int> daysInAMonth = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    bool isLeapYear(int year){
        return ((year%4==0 && year%100!=0) || year%400==0);
    }
    int returnDays(string date){
         int y = stoi(date.substr(0,4));
         int m = stoi(date.substr(5,2));
         int d = stoi(date.substr(8,2));
         int totalDays = 0;
         for(int i=0;i<y;i++){
            totalDays+=isLeapYear(i)? 366: 365;
         }
         for(int i=1;i<m;i++){
            if( i== 2 && isLeapYear(y)) totalDays+=29;
            else totalDays+=daysInAMonth[i];
         }
         totalDays+=d;
         return totalDays;
    }
    int daysBetweenDates(string date1, string date2) {
        return abs(returnDays(date1) - returnDays(date2));
    }
};