class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool>freq;
        while(true){
            int num = n;
            int sum = 0;
            freq[n]=true;
            while(num){
                int r = num%10;
                sum+=(r*r);
                num/=10;
            }
            if(sum == 1) return true;
            if(freq[sum]) return false;
            n = sum;
        }
        return false;
    }
};