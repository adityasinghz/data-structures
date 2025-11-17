class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int start = -1;
        for(int i=0;i<n;i++){
          if(nums[i]==1 && (start == -1 || i-start-1>=k))start = i;
          else if(nums[i]==1 && i-start-1<k) return false; 
        }
        return true;
    }
};