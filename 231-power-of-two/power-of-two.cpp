class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n){
            if(n==1) return true;
            if(n%2!=0) return false;
            n/=2; 
        }
        return false;;
    }
};