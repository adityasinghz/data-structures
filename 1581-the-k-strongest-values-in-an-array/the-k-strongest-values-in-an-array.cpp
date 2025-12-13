class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int>res;
        res.reserve(k);
        int n = arr.size();
        int mid = arr[(n-1)/2];
        int low = 0;
        int high = n-1;
        while(k--){
            int lowEle = abs(arr[low]-mid);
            int highEle = abs(arr[high]-mid);
            if(lowEle > highEle){ 
             res.push_back(arr[low++]);
            }else {
             res.push_back(arr[high--]);
            }
        }
        return res;
    }
};