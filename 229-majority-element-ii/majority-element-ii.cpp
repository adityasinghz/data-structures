class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int firstEle = INT_MIN;
        int secondEle = INT_MIN;

        int countFirst = 0;
        int countSecond = 0;
        
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(firstEle==nums[i])countFirst++;
            else if(secondEle==nums[i])countSecond++;
            else if(countFirst==0) {firstEle = nums[i]; countFirst=1;}
            else if(countSecond==0){ secondEle = nums[i]; countSecond=1;} 
            else{
                countSecond--;
                countFirst--;
            }
        }
        vector<int>aux;
        int ct1 = 0;
        int ct2 = 0; 
        for(int i=0;i<n;i++){
             if(nums[i] == firstEle) ct1++;
             if(nums[i] == secondEle) ct2++;
        }

        if(ct1 > n/3) aux.push_back(firstEle);
        if(ct2 > n/3) aux.push_back(secondEle);

        return aux;
    }
};