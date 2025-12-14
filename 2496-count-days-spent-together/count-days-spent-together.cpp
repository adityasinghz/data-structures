class Solution {
public:
    vector<int>monthHash  =  {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int totalDays(string date){
          int m = stoi(date.substr(0,2));
          int d = stoi(date.substr(3,2));
          int days = 0;
          for(int i=0;i<m;i++){
             days+=monthHash[i];
          }
          days+=d;
          return days;
    }
    int countDaysTogether(string f1, string l1, string f2, string l2) {
        if((f2 > l1 && l2 > l1) || (f1 > l2 && l1 > l2)) return 0;
        string buffF = f1 > f2 ? f1 : f2;
        string buffS = l1  > l2 ? l2 :l1;
        
        return abs(totalDays(buffF) - totalDays(buffS))+1;

    }
};