class Solution {
public:
    int similarPairs(vector<string>& words) {
        vector<int>masks;
        int ans = 0;
        for(auto word : words){
            int mask = 0;
            for(char c : word){
                mask|=(1<<(c-'a'));
            }
            masks.push_back(mask);
        }
        for(int i=0;i<masks.size();i++){
            for(int j=i+1;j<masks.size();j++){
                if(masks[i]==masks[j]) ans++;
            }
        }
        return ans;
    }
};