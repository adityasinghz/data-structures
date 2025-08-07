class Solution {
public:
    int jump(vector<int>& nums) {
        int f = 0, e = 0, j = 0;

        for(int i=0;i<nums.size()-1;i++){
            f = max(f , nums[i] + i);
            if(e == i){
                e = f;
                j++;
            }
        }
        return j;
    }
};