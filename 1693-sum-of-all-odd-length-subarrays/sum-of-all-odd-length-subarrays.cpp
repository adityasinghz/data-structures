class Solution {
public:
    bool isOdd(int num){
      return num%2;
    }
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res=0;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
               sum+=arr[j];
               if(isOdd(j-i+1)) res+=sum;
            }
        }
        return res;
    }
};