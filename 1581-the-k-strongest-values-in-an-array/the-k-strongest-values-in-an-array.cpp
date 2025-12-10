class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        vector<int>ans(k);
        int m = (n-1)/2;
        for(int i=0;i<n;i++){
            pq.push({abs(arr[i]-arr[m]),arr[i]});
        }
        int i = 0;
        while(!pq.empty()&&k--){
           int num = pq.top().second;
           pq.pop();
           ans[i++] = num;
        }
        return ans;
    }
};