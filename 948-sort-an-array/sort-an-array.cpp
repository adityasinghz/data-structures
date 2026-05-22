class Solution {
public:
    void heapify(int i , int n, vector<int>&arr){
        int left   = 2*i + 1;
        int right  = 2*i + 2;

        int largest = i;

        if(left < n && arr[left] > arr[largest])
          largest = left;

        if(right < n && arr[right] > arr[largest])
          largest = right;
        
        if(i!=largest){
            swap(arr[i], arr[largest]);
            heapify(largest, n, arr);
        }
    }

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        for(int i=n/2-1; i>=0; i--){
              heapify(i,n,nums);
        }
        
        for(int i = n-1; i>0; i--){
            swap(nums[i], nums[0]);
            heapify(0, i, nums);
        }

        return nums;
    }
};