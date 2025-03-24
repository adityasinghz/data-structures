class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>mergedInterval;
        int ans = 0;
        for(int i = 0;i<meetings.size();i++){
            if(mergedInterval.empty()  || mergedInterval.back()[1] < meetings[i][0]){
                 mergedInterval.push_back(meetings[i]);
            }else{
                mergedInterval.back()[1] = max(mergedInterval.back()[1], meetings[i][1]); 
            }
        }

        for(int i = 0;i<mergedInterval.size();i++){
            cout<<mergedInterval[i][0]<<' '<<mergedInterval[i][1]<<'\n';
            ans+= (mergedInterval[i][1] - mergedInterval[i][0] + 1);
        }
        return days - ans;
    }
};