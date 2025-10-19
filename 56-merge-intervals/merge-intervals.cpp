class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i =1;i<intervals.size();i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            if( end >=s && e >=end){
                  end = e;
            }else if(end < e){
                res.push_back({start,end});
                start = s;
                end = e;
            }
        }
         res.push_back({start,end});
        return res;
    }
};