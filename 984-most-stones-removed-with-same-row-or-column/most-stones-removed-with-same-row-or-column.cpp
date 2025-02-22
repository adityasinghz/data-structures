class Solution {
public:

    int find(int x , vector<int>&par){
        if(par[x]==x)return x;
        return par[x] = find(par[x], par);
    }
    vector<size_t>len;
    void disjoint(int x, int z, vector<int>&par){
          int par_x = find(x, par);
          int par_z = find(z, par);
          if(len[par_x] > len[par_z]){
            par[par_z] = par_x;
            len[par_x]+=len[par_z];
          }else{
            par[par_x] = par_z;
            len[par_z]+=len[par_x];
          }
    }
    int removeStones(vector<vector<int>>& stones) {
        int max_row = 0;
        int max_col = 0;
        for(auto stone : stones){
            max_row = max(max_row, stone[0]);
            max_col = max(max_col, stone[1]);
        }
        len.resize(max_row+max_col+2, 1);

        vector<int>par(max_row+max_col+2);
        set<int>st;
        for(int i=0;i<par.size();i++)par[i]=i;
        
         
         for(auto node : stones){
            int row = node[0];
            int col = node[1] + max_row + 1;
            disjoint(row, col , par);
            st.insert(row);
            st.insert(col);
         }

            int components = 0;

            for(auto s : st){
                if(find(s,par)==s){
                    components+=1;
                }
            }
       
        return stones.size()-components;
    }
};