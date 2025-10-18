class NumArray {
public:
    vector<int>arr, tree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        tree.resize(4*n);
        build(0,0,n-1);
    }
    void build(int indx, int low, int high){
       if(low==high){
          tree[indx] = arr[low];
          return; 
       }
       int mid = low + (high - low)/2;
       build(2*indx+1,low,mid);
       build(2*indx+2,mid+1,high);
       tree[indx] = tree[2*indx+1] + tree[2*indx+2];
    }
    void update(int indx, int low, int high, int val, int pos){
       if(low==high){
           tree[indx] = val;
           return;
       }    
       int mid = low + (high - low)/2;
       if(pos<=mid){
         update(2*indx+1, low, mid, val, pos);
       }else{
         update(2*indx+2,mid+1,high,val, pos);
       }
       tree[indx] = tree[2*indx+1] + tree[2*indx+2];
    }
    
    int query(int indx, int low, int high, int left, int right){
         if(high < left || right < low) return 0;

         if(left<=low && high<=right)  return tree[indx];
         
         int mid = low + (high - low)/2;

         return query(2*indx+1,low, mid, left, right) + query(2*indx+2,mid+1,high,left,right);
    }

    void update(int pos, int val) {
        update(0, 0, n-1, val, pos);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */