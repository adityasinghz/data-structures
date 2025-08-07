class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        // 0, 1, 3, 6, 5
        // number of papers and number == citations
        int low = 0;
        int high = citations.size() - 1;
        int n = citations.size();
        int maxi = 0;
        while( low <=high){
            int mid = low + (high - low)/2;
            if(citations[mid] >= n - mid){
               maxi = max(maxi , n-mid);
               high = mid -1;
            }else{
               low = mid + 1;
            }
        }
        return maxi;
    }
};