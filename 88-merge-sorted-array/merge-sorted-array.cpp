class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0) {nums1=nums2; return;}
        if(n==0) return;
        int i = m - 1;
        int j = n - 1;
        int l = nums1.size()-1;
        while( i>=0 ){
            if( j >=0 && nums1[i] < nums2[j]) nums1[l] = nums2[j--];
            else nums1[l] = nums1[i--];
            l--;
        }
        while( i >=0 ) nums1[l--] = nums1[i--];
        while( j >=0 ) nums1[l--] = nums2[j--];
    }
};