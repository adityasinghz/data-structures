class Solution {
public:
    int timeToMinute(string time){
        int h = stoi(time.substr(0,2));
        int m = stoi(time.substr(3,2));

        int minute = 60 * h + m;
        return minute;
    }
    int convertTime(string current, string correct) {
        int curr =  timeToMinute(current);
        int corr =  timeToMinute(correct);
        int ans = 0;
        int diff = abs(curr - corr);
        ans+= diff/60;
        diff%=60;
        ans+= diff/15;
        diff%=15;
        ans+=diff/5;
        diff%=5;
        ans+=diff;
        return ans;
    }
};