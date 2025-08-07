class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minEle = INT_MAX;
        int maxEle = INT_MIN;
        for(int i=0;i<prices.size();i++){
            minEle = min(minEle, prices[i]);
            maxEle = max(maxEle, prices[i] - minEle);
        }
        return maxEle;
    }
};