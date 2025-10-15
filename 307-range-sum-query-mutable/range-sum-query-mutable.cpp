class NumArray {
public:
    vector<int>seg, arr;
    int n;
    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        seg.resize(4*n);
        build(0, 0, n-1);
    }
    void build(int indx, int low, int high){
        if(low==high){
            seg[indx] = arr[low];
            return;
        }

        int mid = low + (high - low)/2;

        build(2 * indx + 1, low , mid);
        build(2 * indx + 2, mid+1, high);

        seg[indx] =  seg[2*indx+1] + seg[2*indx + 2];
    }

    void update(int pos, int val, int low, int high, int indx){
         if(low==high){
            seg[indx] =  val;
            return;
         }
         int mid = low + (high - low)/2;
         if(pos<=mid){
            update(pos, val, low, mid, 2*indx+1);
         }
         else update(pos, val, mid+1, high, 2*indx+2);

         seg[indx] = seg[2*indx+1] + seg[2*indx+2];
    }
    int query(int indx, int left, int right, int low , int high){
          if(left > high || right < low) return 0;
          if(left<=low && high<=right) return seg[indx];
          
          int mid = low + (high - low)/2;

    return query(2*indx+1, left, right, low, mid) + query(2*indx+2,left, right, mid + 1, high);
    }

    void update(int pos, int val) {
        update(pos, val, 0, n-1, 0);
    }
    
    int sumRange(int left, int right) {
      return query(0, left, right, 0 , n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */