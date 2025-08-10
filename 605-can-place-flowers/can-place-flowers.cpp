class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        for(int i=0;i<arr.size();i++){
            if(arr[i]== 0){
                bool left = false;
                bool right = false;
                if(i-1 < 0 || (i-1 >=0 && arr[i-1]==0) ) left = true;
                if(i+1 >= arr.size()||(i+1 < arr.size() && arr[i+1]==0)) right = true;
                if(left&&right){
                    arr[i]=1;
                    n--;
                }
            } 
        }
        return n<=0;
    }
};