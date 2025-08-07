class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = -1;
        int ct = 0;

        for(int i=0;i<nums.size();i++){
            if(ct==0) res = nums[i];
            if(nums[i]!=res){
                ct--;
            }else{
                ct++;
            }
        }
        return res;
    }
};