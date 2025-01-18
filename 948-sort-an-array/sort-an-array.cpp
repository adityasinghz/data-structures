class Solution {
public:
    void merge(vector<int>&a, int l ,int mid, int h){
        int j=mid+1;
        int i=l;
        int k=l;
        int b[h+1];
        while(i<=mid&&j<=h){
            if(a[i]<a[j])
                b[k++]=a[i++];
            else
                b[k++]=a[j++];
        }
        while(i<=mid)
            b[k++]=a[i++];
        while(j<=h)
            b[k++]=a[j++];
        
        for(int i=l;i<=h;i++){
            a[i]=b[i];
        }
    }
    void mergesort(vector<int>&a,int l, int h){
        if(l<h){
            int mid= l+(h-l)/2;
            mergesort(a,l,mid);
            mergesort(a,mid+1,h);
            merge(a,l,mid,h);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};