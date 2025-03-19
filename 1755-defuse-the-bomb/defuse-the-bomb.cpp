class Solution {
public:
    vector<int> decrypt(vector<int>& nums, int k) {
        if(k == 0 ) return vector<int>(nums.size(),0);
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int sum = 0;
            int r = i + k;
            if(k  > 0){
                for(int j = i+1; j<=r;j++){
                   sum+=nums[j%n];
                }
            }
            if(k  < 0){
                for(int j = i-1; j>=r;j--){
                   if(j<0)
                   sum+=nums[n+j%n];
                   else
                   sum+=nums[j%n];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

// 0 - 100  5
//  