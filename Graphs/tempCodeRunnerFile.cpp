#include <bits/stdc++.h>
using namespace std;

void edge(vector<vector<int>> &adj, int a, int b)
{
    adj[b].push_back(a);
    adj[a].push_back(b);
}
void dfs(int node, vector<vector<int>> adj, vector<int> &v, vector<int> &ls)
{
    v[node] = 1;
    ls.push_back(node);

    for (int it : adj[node])
    {
        if (!v[it])
            dfs(it, adj, v, ls);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v;
    vector<vector<int>> adj;
    v.assign(n, false);
    adj.assign(n, vector<int>());

    int start = 0;
    vector<int> ls;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edge(adj, a, b);
    }
    dfs(start, adj, v, ls);

    for (int i = 0; i < ls.size(); i++)
        cout << ls[i] << ' ';
}