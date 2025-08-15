class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m1;
        map<int,int>m2;
        vector<int>a1;
        vector<int>a2;

        for(auto num : nums1)m1[num]=1;
        for(auto num : nums2)m2[num]=1;

        for(auto num : nums1){
            if(!m2[num]){ a1.push_back(num); m2[num]=1;}
        }

        for(auto num : nums2){
            if(!m1[num]){ a2.push_back(num); m1[num]=1;} 
        }

        return {a1,a2};
    }
};