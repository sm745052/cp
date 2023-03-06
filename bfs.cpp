#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n, m;
vector<vector<char>> arr;
int ii, ij, fi, fj;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<vector<int>> dis;
int check(pair<int, int> pos){
    if(pos.F<n && pos.S<m && pos.F>=0 && pos.S>=0 && arr[pos.F][pos.S]!='#')return 1;
    return 0;
}


void bfs(pair<int, int> pos)
{
    queue<pair<int, int>> q;
    q.push(pos);
    while (!q.empty())
    {
        // cout<<("hello");
        auto fr = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            if (check({fr.F + dx[k], fr.S + dy[k]}) && dis[fr.F + dx[k]][fr.S + dy[k]] >= dis[fr.F][fr.S]+1){
                dis[fr.F + dx[k]][fr.S + dy[k]] = dis[fr.F][fr.S]+1;
                q.push({fr.F + dx[k], fr.S + dy[k]});
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    arr = vector<vector<char>>(n, vector<char>(m));
    dis = vector<vector<int>>(n, vector<int>(m, 1e9));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    cin >> ii >> ij >> fi >> fj;
    dis[ii][ij]=0;
    bfs({ii, ij});
    cout<<dis[fi][fj]<<endl;
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}