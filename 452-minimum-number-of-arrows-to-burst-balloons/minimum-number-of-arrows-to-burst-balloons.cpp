class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int start = points[0][0];
        int end = points[0][1];
        int n = points.size();
        int ans = 1;
        for(int i=1; i<n; i++){
             if(end  >= points[i][0]){
                if(points[i][1]<end){
                    start = points[i][0];
                    end = points[i][1];
                }
             }
             else if(end  < points[i][1]){
                ans++;
                start = points[i][0];
                end = points[i][1];
             }
        }
        return ans;
    }
}; 

