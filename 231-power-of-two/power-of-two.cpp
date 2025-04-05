class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long one = 1;
        int ct = 0;
        while(one){
           if(n&one)ct++;
           one<<=1;
        }
        return ct==1;
    }
};