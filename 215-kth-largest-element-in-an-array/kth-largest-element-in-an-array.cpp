class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int>, greater<int>>q;
        int n = nums.size();
        int i = 0;
        while( i < n ){
            q.push(nums[i]);
            if(q.size() > k) q.pop();
            i++;
        }
        return q.top();
    }
};