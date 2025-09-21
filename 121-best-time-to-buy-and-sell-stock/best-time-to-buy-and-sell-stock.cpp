class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minEle = INT_MAX;
        int maxEle = INT_MIN;

        for(auto price : prices){
            minEle = min(minEle, price);
            maxEle = max(price - minEle, maxEle);
        }
        return maxEle;
    }
};