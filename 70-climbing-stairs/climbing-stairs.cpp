class Solution {
public:
    int arr[50];
    int climbStairs(int n) {
        if( n == 1 || n == 0 ) return 1;
        if(arr[n] != 0) return arr[n];
        return arr[n] = climbStairs( n - 1) + climbStairs(n-2);
    }
};