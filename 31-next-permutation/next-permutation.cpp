class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int indx = -1;
        // First we need to find first breakpoint from back where it is breaking the decreasing sequence (3,2,1)
        for(int i = n-2; i>=0 ; i--){
            if(nums[i+1] > nums[i]){
               indx=i;
               break;
            }
        }
        if(indx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>indx;i--){  // finding next greater element from the range of last element to wrt indx 
            if(nums[indx] < nums[i]){
                swap(nums[i],nums[indx]);
                break;
            }
        }
        reverse(nums.begin()+indx+1,nums.end());

    }
};