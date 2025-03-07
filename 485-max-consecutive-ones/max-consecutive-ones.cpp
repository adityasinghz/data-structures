class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int acc = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                acc++;
            }
            else{
                acc = 0;
            }
            maxi = max(maxi, acc);
        }
        return maxi;
    }
};