class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int firstEle = -1;
        int secondEle = -1;

        int firstCount = 0;
        int secondCount = 0;

        for(int i=0;i<nums.size();i++){
            if(firstEle == nums[i]){
               firstCount++;
            }else if(secondEle==nums[i]){
              secondCount++;
            }else if(firstCount==0){
              firstEle = nums[i];
              firstCount=1;
            }else if(secondCount==0){
             secondEle = nums[i];  
             secondCount=1;
            }else{
                firstCount--;
                secondCount--;
            }
        }
        vector<int>res;
        int ct1 = 0;
        int ct2 = 0;
        cout<<firstEle<<' '<<secondEle<<'\n';
        for(int i=0;i<nums.size();i++){
            if(nums[i]==firstEle) ct1++;
            else if(nums[i]==secondEle) ct2++;
        }

        if(ct1 > nums.size()/3) res.push_back(firstEle);
        if(ct2 > nums.size()/3) res.push_back(secondEle); 
        return res;
    }
};