class Solution {
public:
    bool checkMap(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 128; i++) {
            if (a[i] > b[i])
                return false;
        }
        return true;
    }
    void checkMinStr(long long& firstPoint, long long& minLen, long long& lastPoint, int& initialMin,
                     string& s, vector<int>& a, vector<int>& b) {
        if (lastPoint - firstPoint + 1 < minLen) {
            minLen = min(minLen, lastPoint - firstPoint + 1);
            initialMin = firstPoint; 
        }
    }
    string minWindow(string s, string t) {
        long long int firstPoint = 0;
        long long int lastPoint = 0;
        int initialMin = INT_MAX;
        long long int n = s.size();
        long long int m = t.size();
        vector<int> a(128, 0), b(128, 0);
        for (long long i = 0; i < m; i++) a[t[i]]++;
        for (; firstPoint < n; firstPoint++) if (a[s[firstPoint]]) break;
        if (firstPoint == n) return "";
        
        lastPoint = firstPoint;
        long long minLen = INT_MAX;
        string res;
        while (lastPoint < n) {
            if (a[s[lastPoint]]) b[s[lastPoint]]++;
            while(checkMap(a, b)) {
                checkMinStr(firstPoint, minLen, lastPoint, initialMin, s, a, b);
                if(a[s[firstPoint]])b[s[firstPoint]]--;++firstPoint;
                while(firstPoint < lastPoint && !a[s[firstPoint]])firstPoint++;
            }
            ++lastPoint;
        }
        return minLen == INT_MAX ? "" : s.substr(initialMin, minLen);
    }
};