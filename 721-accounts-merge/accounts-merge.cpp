class Solution {
public:
    int find(int x, vector<int>&par){
        if(x==par[x]) return x;
        return par[x] = find(par[x], par);
    }

    void disjoint(int x, int z, vector<int>&par, vector<int>&len){
       int par_x = find(x, par);
       int par_z = find(z, par);
       if(par_z == par_x) return;
       if(len[par_z] > len[par_x]){
           len[par_z]+=len[par_x];
           par[par_x] = par_z;
       }else{
           len[par_x]+=len[par_z];
           par[par_z] = par_x;
       }
    } 
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mp;
        int n = accounts.size();
        vector<int>par(n), len(n, 1);
        vector<vector<string>>res;
        map<int, set<string>>cp;
        for(int i=0;i<n;i++){
            par[i] = i;
        }

        for(int i = 0;i<n;i++){
            for(int j=1; j<accounts[i].size();j++){
                 if(mp.find(accounts[i][j])!=mp.end()){
                    disjoint(mp[accounts[i][j]] , i, par, len);
                 }else{
                    mp[accounts[i][j]] = i;
                 }
            }
        }

        for(int i = 0; i < n ; i++){
            if(par[i] == i){ 
                cp[i] = set<string>(accounts[i].begin()+1,accounts[i].end());
            }
        }
       
        for(int i=0;i<n;i++){
            if(par[i] == i) continue;
            int root = find(i, par);
            cp[root].insert(accounts[i].begin()+1,accounts[i].end());
        }

        for (auto &m : cp) {
        vector<string> mergedEmails(m.second.begin(), m.second.end());
        mergedEmails.insert(mergedEmails.begin(), accounts[m.first][0]);  // Add name
        res.push_back(mergedEmails);
         }
        
        return res;
    }
};