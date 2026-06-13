class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        for(int i = 0; i < arr.size(); i++){
           arr[i]= arr[i] - x; 
        }
        
        int low = 0;
        int high = arr.size() - 1;
        vector<int>ans;
        while( low < high){
            cout<<arr[low]<<' '<<arr[high]<<'\n';
            if(high - low + 1 == k) break;
            else if(abs(arr[low]) > abs(arr[high])) low++;
            else if(abs(arr[high]) > abs(arr[low])) high--;
            else if(abs(arr[high])==abs(arr[low])){
                if(arr[high] + x > arr[low] + x) high--;
                else low++;
            }
        }
        for(int i = low; i<=high; i++){
           ans.push_back(arr[i]+x);
        }
        return ans;
        
    }
};