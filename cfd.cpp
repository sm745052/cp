#include<bits/stdc++.h>
using namespace std;



int solve(){
    int n;
    cin>>n;
    int n_ = 3*100000;
    vector<int> is_prime(n_+1, 1);
    for(int i=2;i*i<=n_;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=n_;j+=i){
                is_prime[j]=0;
            }
        }
    }
    vector<int> prime;
    for(int i=2;i<=n_;i++)if(is_prime[i])prime.push_back(i);
    vector<vector<int>> g(n+1+prime.size()+2);
    map<int, int> primepos;
    for(int i=n+1;i<n+1+prime.size();i++){
        primepos[prime[i-(n+1)]] = i;
    }
    vector<int>a(n);
    for(auto &i:a)cin>>i;

    for(int i=0;i<n;i++){
        int num = a[i];
        if(num%2==0){
            g[i+1].push_back(primepos[2]);
            g[primepos[2]].push_back(i+1);
            while(num%2==0)num/=2;
        }
        for(int j=3;j*j<=num;j++){
            if(num%j==0){
                g[i+1].push_back(primepos[j]);
                g[primepos[j]].push_back(i+1);
                while(num%j==0)num/=j;
            }
        }
        if(num>2)g[i+1].push_back(primepos[num]), g[primepos[num]].push_back(i+1);
    }
    int s ,d;
    cin>>s>>d;
    queue<int>q;
    q.push(s);
    vector<int>vis(g.size(), 0);
    vis[s]=-1;
    vector<int>ans;
    while(!q.empty()){
        if(q.front()==d){
            int t=d;
            int ctr;
            ctr=0;
            while(vis[t]!=-1){
                // cout<<vis[t]<<endl;
                if(ctr%2==0){
                    ans.push_back(t);
                }
                t=vis[t];
                ctr++;
            }
            ans.push_back(s);
            reverse(ans.begin(), ans.end());
            cout<<ans.size()<<endl;
            for(auto i:ans){
                cout<<i<<" ";
            }
            cout<<endl;
            return 0;
        }
        else{
            int nd = q.front();
            q.pop();
            for(auto j:g[nd]){
                if(!vis[j]){
                    vis[j]=nd;
                    q.push(j);
                }
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}



int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}