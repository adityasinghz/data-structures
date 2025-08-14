class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int maxi = 0;
        while(j < nums.size()){
            if(nums[j]==0) k--;
            if( k < 0){
                while(nums[i]==1)i++;
                if(nums[i]==0){k++;i++;}
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};