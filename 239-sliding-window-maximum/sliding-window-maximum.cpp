class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxNum = INT_MIN;
        deque<int>dq;
        vector<int>res;
        while( j < n){
            while(!dq.empty() && nums[j] > nums[dq.back()]) dq.pop_back();
            dq.push_back(j);
            while(!dq.empty() && dq.front()  < i ) dq.pop_front();
            if( j - i + 1 == k){
                res.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        return res;
    }
};