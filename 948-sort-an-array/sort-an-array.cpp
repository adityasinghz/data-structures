class Solution {
public:
    void merge(int low, int mid, int high, vector<int>&arr){
        vector<int>aux;
        int i = low;
        int j = mid + 1;
    
        while( i<=mid && j<=high){
            if(arr[i] < arr[j]) aux.push_back(arr[i++]);
            else aux.push_back(arr[j++]);
        }
        while( i <=mid)  aux.push_back(arr[i++]);
        while( j <=high) aux.push_back(arr[j++]);

        int k = low;
        for(int l=0;l<aux.size();l++){
            arr[k++] = aux[l];
        }
    }

    void mergeSort(int low, int high, vector<int>&arr){
        int mid = low + (high - low)/2;
        if(low < high){
           //cout<<low<<' '<<high<<'\n';
           mergeSort(low, mid, arr);
           mergeSort(mid+1, high, arr);
           merge(low, mid, high, arr);  
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0, n-1, nums);
        return nums;
    }
};