class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        int curr = 1;
        for(int i = 0; i < n; i++) {
            ans[i] *= curr;
            curr *= nums[i];
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<' ';
        curr = 1;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] *= curr;
            curr *= nums[i];
        }
        cout<<'\n';
        for(int i=0;i<n;i++) cout<<ans[i]<<' ';
        return ans;
        
    }
};