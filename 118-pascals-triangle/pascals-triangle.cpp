class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        res.push_back({1});
       for(int i = 1;i<numRows;i++){
           vector<int>present(i+1);
           present[0] = 1;
           present[present.size()-1] = 1;
           int idx = 1;
           for(int j=0;j<res[res.size()-1].size();j++){
              if(j+1 < res[res.size()-1].size() && idx+1 < present.size() && idx< present.size()-1){
                present[idx++] = res[res.size()-1][j] + res[res.size()-1][j+1];
              } 
           }
           res.push_back(present);
       }
       return res;
    }
};