class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        int first = intervals[0][0];
        int second = intervals[0][1];
        sort(intervals.begin(),intervals.end());
       for(int i = 1;i<intervals.size();i++){
          if(intervals[i][0] <= second){
            if(intervals[i][1] > second)
              second = intervals[i][1];
          }
          if(intervals[i][0] > second){
            res.push_back({first,second});
            first = intervals[i][0];
            second = intervals[i][1];
          }
       }
       res.push_back({first, second});
       return res; 
    }
};