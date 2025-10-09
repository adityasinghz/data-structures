class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>stk;
        int n = temp.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
             while(!stk.empty() && temp[i] >temp[stk.top()]){
                  int p_indx = stk.top();
                  stk.pop(); 
                  ans[p_indx] = i - p_indx;
             }
             stk.push(i);
        }
        return ans;
    }
};