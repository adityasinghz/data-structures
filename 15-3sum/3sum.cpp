class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0; i < n; i++){
                int low = i+1;
                int high = n - 1;
                while( low < high){
                    if(nums[i] + nums[low] + nums[high] > 0) high--;
                    else if(nums[i] + nums[low] + nums[high] < 0) low++;
                    else{
                        res.push_back({nums[i],nums[low],nums[high]});
                        int temp_l = nums[low];
                        int temp_h = nums[high];

                        do{low++;}while(low < high && temp_l==nums[low]);
                        do{high--;}while(low < high && temp_h==nums[high]);
                    }
                }
            int temp_i = nums[i];
            while( i + 1 < n && nums[i+1] == temp_i) i++;
        }
        return res;
    }
};