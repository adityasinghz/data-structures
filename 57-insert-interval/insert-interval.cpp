class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        int i = 0;
        int n = intervals.size();
        for(auto interval : intervals){
            if(newInterval[1] < interval[0]) break;
            else if(newInterval[0] > interval[1]) res.push_back(interval);
            else{
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            } 
            i++;
        }
        res.push_back(newInterval);

        while( i < n) res.push_back(intervals[i++]);

        return res;
    }
};