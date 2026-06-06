class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
       sort(nums.begin(),nums.end());
       int i = 0;
       int j = nums.size() - 1;
       int b = 0;
       while( i <=j){
           if(nums[j] + nums[i] <=limit ){
            i++;
           }
           j--;
           b++;
       }
       return b;
    }
};