class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majEle = 0;
        int freque = 0;

        for(int num : nums){
             if(freque == 0){
                majEle = num;
                freque = 1;
             }else if(majEle==num){
                freque++;
             }else freque--;
        }

        return majEle;
    }
};