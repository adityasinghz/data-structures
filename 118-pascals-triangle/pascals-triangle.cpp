class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) return {{1}};
        if(numRows==2) return {{1},{1,1}};
        vector<vector<int>>res{{1},{1,1}};

        for(int i=2;i<numRows;i++){
            vector<int>ans{1};
            for(int j=0;j<res.back().size()-1;j++){
               ans.push_back(res.back()[j] + res.back()[j+1]);
            }
            ans.push_back(1);
            res.push_back(ans);
        }
        return res;
    }
};