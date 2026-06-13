class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans = arr, aux;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i = 0; i < arr.size(); i++){
           ans[i] = abs(ans[i] - x);
           pq.push({ans[i],arr[i]}); 
        }
        while(!pq.empty()){
            if(aux.size()<k) aux.push_back(pq.top().second);
            pq.pop();
        }
        sort(aux.begin(),aux.end());
        return aux;
    }
};