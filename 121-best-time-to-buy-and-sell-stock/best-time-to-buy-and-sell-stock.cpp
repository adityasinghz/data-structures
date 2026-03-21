class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minAmount = INT_MAX;
        int n  = prices.size();
        for(int i=0;i<n;i++){
            minAmount = min(minAmount, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minAmount);
        }
        return maxProfit;
    }
}; 