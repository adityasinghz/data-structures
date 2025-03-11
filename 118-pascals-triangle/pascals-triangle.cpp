class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans={{1}};
        for(int i = 1;i<numRows;i++){
           vector<int>temp(i+1);
           int k =0;
           temp[k++]=1;
           temp[i]=1;
           
           for(int j = 1 ; j < ans[i-1].size();j++){
              int sum = ans[i-1][j-1] + ans[i-1][j];
              temp[k++]=sum;
           }
           ans.push_back(temp);
        }
        return ans;
    }
};