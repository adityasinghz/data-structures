class Solution {
public:
    int find(int x , vector<int>&par){
       if(x==par[x]) return par[x];
       return par[x]=find(par[x], par);
    }
    void disjoint(int x, int z,vector<int>&par, int &extraEdge, vector<int>&len){
       int par_x = find(x,par);
       int par_z = find(z,par);
       if(par_x!=par_z){
        if(len[par_x] < len[par_z]){
            len[par_z]+=len[par_x];
            par[par_x]=par_z;
        }else{
           len[par_x]+=len[par_z];
           par[par_z]=par_x;
        }
       }else{
        extraEdge++;
       }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraEdge = 0;
        int connected = 0;
        vector<int>par(n);
        vector<int>len(n,1);
        for(int i  = 0;i<n;i++)par[i]=i;
        
        for(int i=0;i<connections.size();i++){
            disjoint(connections[i][0], connections[i][1], par, extraEdge, len);
        }
        
        for(int i=0;i<n;i++){
          if(par[i]==i)connected++;
        }
        if(extraEdge>=connected-1) return connected-1;
        return -1;
    }
};