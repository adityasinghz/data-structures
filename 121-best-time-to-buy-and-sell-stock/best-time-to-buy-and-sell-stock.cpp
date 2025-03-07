class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxEle = INT_MIN;
        int minEle = INT_MAX;
        for(int i=0;i<prices.size();i++){
           minEle =  min(minEle, prices[i]);
           maxEle =  max(maxEle, prices[i]-minEle);
        }
        return maxEle;
    }
};