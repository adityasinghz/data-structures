class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        long long ans = 0;
        while( j < n){
           while(j+1<n && nums[j]- nums[j+1]==1){j++;}
           long  long len = j-i+1;
           ans+=(len*(len+1)/2);
           i=j+1;
           j++;
        }
        return ans;
    }
};