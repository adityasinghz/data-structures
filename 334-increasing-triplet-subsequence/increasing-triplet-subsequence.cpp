class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstNum = INT_MAX;
        int lastNum =  INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(firstNum < lastNum && lastNum < nums[i]) return true;
            if(firstNum > nums[i]) firstNum = nums[i];
            else if(firstNum < nums[i] && nums[i] < lastNum) lastNum = nums[i];
        }
        return false;
    }
};