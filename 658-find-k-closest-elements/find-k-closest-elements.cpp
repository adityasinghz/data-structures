class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        map<int,vector<int>>mp;
        int n = arr.size();
        for(int i=0; i < n; i++){
            int diff = abs(x-arr[i]);
            mp[diff].push_back(arr[i]);
        }
        vector<int>ans;
        for(auto vec : mp){
           for(auto v : vec.second){
               if(ans.size() == k) break;
               ans.push_back(v);
           }
           if(ans.size() > k) break;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};