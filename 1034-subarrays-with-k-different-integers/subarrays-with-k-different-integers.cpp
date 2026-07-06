class Solution {
public:
    int kthValue(vector<int>& nums, int k){
         unordered_map<int, int>freq;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int ct = 0;
        while( j < n ){
            freq[nums[j]]++;
            while(freq.size() > k){
                if(--freq[nums[i]]==0) freq.erase(nums[i]);
                i++;
            }
            
            if(freq.size() <=k ){
                ct+=(j - i + 1);
            }
            j++;
        }
        return ct;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return kthValue(nums, k) - kthValue(nums, k-1);
    }
};