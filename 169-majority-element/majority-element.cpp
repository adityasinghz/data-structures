class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct = 0;
        int ans = -1;
        for(int i = 0;i<nums.size();i++){
            if(ct == 0){
                ans = nums[i];
            }
            if(ans != nums[i]){
                ct--;
            }else{
                ct++;
            }
        }
        return ans;
    }
};