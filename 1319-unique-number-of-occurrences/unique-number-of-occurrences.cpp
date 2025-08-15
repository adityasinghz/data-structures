class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        map<int,bool>occ_mp;

        for(int i=0;i<arr.size();i++) mp[arr[i]]++;
        
        for(auto m : mp) if(occ_mp[m.second]) return false; else occ_mp[m.second]=1;

        return true;

    }
};