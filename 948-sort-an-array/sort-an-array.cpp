class Solution {
public:
   void merge(vector<int>&nums, int low, int mid, int high){
        int i = low;
        int j = mid+1;
        int k = low;
        int aux[high+1];
        while(i<=mid && j<=high){
           if(nums[i] > nums[j])
              aux[k++] = nums[j++];
           else
              aux[k++] = nums[i++];
        }

        while(i<=mid){
            aux[k++] = nums[i++];
        }
        
        while(j<=high){
            aux[k++] = nums[j++];
        }

        for(int l = low; l<=high; l++)
          nums[l] = aux[l];
   }
   void mergeSort(vector<int>&nums, int low, int high){
        if(low < high){
            int mid = low + (high - low)/2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid+1, high);
            merge(nums,low, mid, high);
        }
   }
    vector<int> sortArray(vector<int>& nums) {
       int n = nums.size();
       mergeSort(nums, 0 , n-1);
       return nums;
    }
};