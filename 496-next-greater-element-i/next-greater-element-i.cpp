class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>stk;
        unordered_map<int,int>freq;
        vector<int>res(nums1.size(),-1);
        for(int i = nums2.size()-1;i>=0;i--){
            
            while(!stk.empty() && stk.top()<=nums2[i]){
                stk.pop();
            }

            freq[nums2[i]] = !stk.empty()?stk.top() : -1;
            stk.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
            res[i] = freq[nums1[i]];
        }

        return res;

    }
};