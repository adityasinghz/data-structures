class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        priority_queue<pair<int,double>>pq;
        int n = pos.size();
        int res = 0;
        for(int i=0;i<n;i++){
            pq.push(make_pair(pos[i], (double)(target-pos[i])/sp[i]));
        }
        double curr = 0;
        while(!pq.empty()){
           if(pq.top().second > curr){
              curr = pq.top().second;
              res++;
           }
           pq.pop();
        }
        return res;
    }
};