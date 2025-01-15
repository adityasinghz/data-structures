class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>res{arr[0]};
        for(int i=1;i<arr.size();i++){
            if(res.back()[1] >= arr[i][0]){
                res.back()[1] = max(res.back()[1],arr[i][1]);
            }else{
                res.push_back(arr[i]);
            }
        }
        return res;
    }
};