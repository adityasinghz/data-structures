class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n = matrix[0].size();
        int m = matrix.size();
        int right = 0; // i
        int bottom = n-1; // j
        int left = m-1; // i
        int top = 0; // j

        while(right<=left && top<=bottom){
            
           for(int j = top;j<=bottom;j++){
            cout<<"Loop 1 done "<<matrix[right][j]<<'\n';
            ans.push_back(matrix[right][j]);
           }
           right++;
           for(int i = right;i<=left;i++){
            cout<<"Loop 2 done "<<matrix[i][bottom]<<'\n';
             ans.push_back(matrix[i][bottom]);
           }
           bottom--;
           if(right<=left){
           for(int j=bottom;j>=top;j--){
            cout<<"Loop 3 done "<<matrix[left][j]<<'\n';
             ans.push_back(matrix[left][j]);
           }
           left--;
           }
           if(top<=bottom)
           for(int i=left;i>=right;i--){
            cout<<"Loop 4 done "<<matrix[i][top]<<'\n';
            ans.push_back(matrix[i][top]);
           }
           top++;
        }
        return ans;
    }
};