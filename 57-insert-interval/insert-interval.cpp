class Solution {
public:
    vector<vector<int>> mergeInterval(vector<vector<int>>& intervals){
         vector<vector<int>>res;
         int n = intervals.size();
         res.push_back(intervals[0]);
         for(int i=1; i<n; i++){
            if(res.back()[1] >= intervals[i][0]) res.back()[1] = max(res.back()[1], intervals[i][1]);
            else res.push_back(intervals[i]);
         }
         return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

         intervals.push_back(newInterval);
         sort(intervals.begin(),intervals.end());
         return mergeInterval(intervals);
    }
};