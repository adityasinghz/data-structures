class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int ans = 0;
        while( i < height.size() && j >=0){
            ans = max(ans, min(height[i], height[j])*(j-i));
            height[i] > height[j]? j-- : i++;
        }
        return ans;
    }
};