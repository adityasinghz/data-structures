class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        for(int i=0;i<nums.size();i++){
            int initial = i;
            int finally = -1;
            long long int curr = nums[initial];
            while(i < nums.size()-1){
                  if(curr + 1 == nums[i+1]){
                    finally = i + 1;
                    i++;
                    curr++;
                  }
                  else break;
            }
            finally==-1?ans.push_back(to_string(nums[initial])) : ans.push_back(to_string(nums[initial]) + "->" + to_string(nums[finally]));
        }
        return ans;
    }
};