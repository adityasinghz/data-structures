class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        if(m==0){ nums1=nums2; return;}
        nums1.erase(nums1.begin() + m, nums1.end());
        nums2.erase(nums2.begin() + n, nums2.end());
        cout<<nums1.size()<<' '<<nums2.size()<<'\n';
        int i = m-1;
        int j = 0;

        while(i>= 0 && j < n){
            //cout<<i<<' '<<j<<'\n';
            if(nums1[i] >= nums2[j]){
               swap(nums1[i--] , nums2[j++]);
            }else{
                i--;
            }
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int j = 0;j<n;j++){
            nums1.push_back(nums2[j]);
        }
    }
};