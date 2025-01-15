class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int>past(1,1);
        vector<vector<int>>res;
        res.push_back(past);
       for(int i = 1;i<numRows;i++){
           vector<int>present(i+1);
           present[0] = 1;
           present[present.size()-1] = 1;
           int idx = 1;
           for(int j=0;j<past.size();j++){
              if(j+1 < past.size() && idx+1 < present.size() && idx< present.size()-1){
                present[idx++] = past[j] + past[j+1];
              } 
           }
           past=present;
           res.push_back(present);
       }
       return res;
    }
};