class Solution {
public:
    void merge(int low, int mid, int high, vector<int>&nums){

           int i = low;
           int k = 0;
           int j = mid+1;
           vector<int>aux(high-low+1,0);
           while(i<=mid && j<=high){
             if(nums[i] >= nums[j]){
                aux[k++] = nums[j++];
             }else{
                aux[k++] = nums[i++];
             }
           }
           while(i<=mid){
             aux[k++] = nums[i++];
           }
           while(j<=high){
             aux[k++] = nums[j++];
           }

           for(int l = 0;l<aux.size();l++){
               nums[low+l] = aux[l];
           }
    }
    int countReversePairs(int low, int mid, int high, vector<int>& nums) {
    int count = 0;
    int j = mid + 1;

    // Count reverse pairs
    for (int i = low; i <= mid; i++) {
        while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    return count;
}
    int mergeSort(int low, int high, vector<int>&nums){
            int inv = 0;
            
            if(low >= high)return 0;

            int mid = low + (high-low)/2;
            int temp_i = low;
            int temp_j = mid+1;
        
            inv+=mergeSort(low, mid, nums);
            inv+=mergeSort(mid+1,high, nums);
            inv += countReversePairs(low, mid, high, nums);

            merge(low, mid, high, nums);
          return inv;
    }
    int reversePairs(vector<int>& nums) {

        int inv = mergeSort(0, nums.size()-1, nums);
        return inv;
    }
};