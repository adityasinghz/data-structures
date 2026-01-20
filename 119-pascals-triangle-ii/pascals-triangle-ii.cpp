class Solution {
public:

    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans={{1}};
        for(int i = 1; i<=33;i++){
            vector<int>temp(i+1);
            temp[0] = 1;
            temp[i] = 1;
            int n = ans[i-1].size();
            int k = 1;
            for(int j =0;j<n;j++){
                if(j + 1 < n) temp[k++] = ans[i-1][j] + ans[i-1][j+1];
            }
            ans.push_back(temp);
        }
        //for(int)
        return ans[rowIndex];
    }
};