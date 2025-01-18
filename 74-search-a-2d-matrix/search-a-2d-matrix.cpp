class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

     for(int i=0; i< m; i++){
        if(matrix[i][0] <= target && target <= matrix[i][n-1]){
           int low =  0;
           int high = n-1;
           while(low <= high){
               int mid = low + (high -low)/2;
               cout<<mid<<'\n';
               if(matrix[i][mid] > target){
                  high = mid - 1;
               }
               if(matrix[i][mid] < target){
                
                 low = mid +1;
               }
               if(matrix[i][mid]==target){
                return true;
               }
           }
        }
     }
     return false;   
    }
};