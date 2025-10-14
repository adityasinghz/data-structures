class NumArray {
public:
    vector<int>seg, arr;
    int n;
    NumArray(vector<int>& nums) {
        seg.resize(4 * nums.size());
        n = nums.size();
        arr =  nums;
        build(0, 0, nums.size() - 1);
    }
    void build(int i, int low, int high){
          if(low == high){ seg[i] = arr[low]; return;}
          int mid = low + (high-low)/2;
          build(2*i+1, low, mid);
          build(2*i+2, mid+1,high);
          seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    int query(int l, int r, int left, int right, int indx){
        if(left > r || right < l) return 0;

        if(l>=left && r <= right ) return seg[indx];
        
        int mid = l + (r - l)/2;
return query( l, mid, left, right, 2*indx+1) + query(mid + 1 , r, left, right, 2*indx +2);
    }

    int sumRange(int left, int right) {
     return query(0, n-1, left, right, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */