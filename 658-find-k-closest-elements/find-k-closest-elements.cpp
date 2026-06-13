class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int low = 0;
        int high = arr.size() - 1;
        vector<int>ans;
        while( low < high){
            int left = abs(arr[low] - x);
            int right = abs(arr[high]- x);
            if(high - low + 1 == k) break;
            else if(left > right) low++;
            else if(right > left) high--;
            else if(left==right){
                if(arr[high] > arr[low]) high--;
                else low++;
            }
        }
        for(int i = low; i<=high; i++){
           ans.push_back(arr[i]);
        }
        return ans;
        
    }
};