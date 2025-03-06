class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        rev(0, nums.size(), nums);
        rev(0, k, nums);
        rev(k, nums.size(), nums);
    }
    void rev(int low , int high , vector<int>&nums){
          reverse(nums.begin()+low, nums.begin()+high);
    }
};