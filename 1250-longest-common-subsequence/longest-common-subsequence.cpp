class Solution {
public:
    int LCS(int indx1, int indx2, string &text1, string &text2, vector<vector<int>> &dp) {
    // Base case: If either string is exhausted, LCS length is 0
    if (indx1 == 0 || indx2 == 0) return 0;

    // Return cached result if already computed
    if (dp[indx1][indx2] != -1) return dp[indx1][indx2];

    // If characters match, increment LCS length
    if (text1[indx1 - 1] == text2[indx2 - 1]) {
        return dp[indx1][indx2] = 1 + LCS(indx1 - 1, indx2 - 1, text1, text2, dp);
    }

    // Otherwise, take the maximum LCS length from two possibilities
    return dp[indx1][indx2] = max(
        LCS(indx1 - 1, indx2, text1, text2, dp), // Exclude last character of text1
        LCS(indx1, indx2 - 1, text1, text2, dp)  // Exclude last character of text2
    );
}
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
        return LCS(m, n , text1 , text2, dp);
    }
};