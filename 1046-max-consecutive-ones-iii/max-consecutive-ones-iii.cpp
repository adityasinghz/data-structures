class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxLen = 0;
        while( j < n){
             if(nums[j] == 0) k--;
             if( k < 0){
                while(nums[i]==1) i++;
                if(nums[i]==0){i++; k++;}
             }
            maxLen = max(maxLen, j - i + 1);
            j++;
        } 
        return maxLen;
    }
};