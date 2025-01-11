class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ct = 0;
        for(int i = 0;i< nums.size();i++){
            int left_diff = 0;
            int right_diff = 0;
            for(int j=0;j<i;j++) 
              if(nums[i]-nums[j]==diff)
                left_diff++;

            for(int k=i+1;k<nums.size();k++) 
                if(nums[k]-nums[i]==diff)
                   right_diff++;

            ct+=min(right_diff,left_diff);
        }
        return ct;
    }
};