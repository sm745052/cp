#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, q;
    cin >> n >> q;
    int q1 = q;
    vector<int> a(n);
    vector<pair<int, int>> pre(n), post(n);
    int ctr1=1, ctr2=n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        pre[i] = {a[i]+ctr1, i};
        post[i] = {a[i]+ctr2, i};
        ctr1++;
        ctr2--;
    }
    int flag = 0;
    sort(pre.begin(), pre.end());
    sort(post.begin(), post.end());
    int c = 0;
    int min_d = INT_MAX;
    int min_ctr=0;
    int ffff=0;
    while(q>=0){
        if(c==-1){
            if(pre[0].first<=q){
                q-=pre[0].first;
                c++;
                auto j=post.begin();
                for(; j!=post.end();j++){
                    if(j->second==pre[0].second)break;
                }
                post.erase(j);
                pre.erase(pre.begin());
            }
            else{
                cout<<c<<endl;
                return;
            }
        }
        else{
            if(pre.size()>0 && post.size()>0 && pre[0].first<post[0].first){
                if(pre[0].first<=q){
                    flag = 1;
                    // cout<<"flagging1"<<pre[0].first<<endl;
                    q-=pre[0].first;
                    c++;
                    auto j=post.begin();
                    for(; j!=post.end();j++){
                        if(j->second==pre[0].second)break;
                    }
                    post.erase(j);
                    pre.erase(pre.begin());
                }
                else{
                    if(flag){
                        cout<<c<<endl;
                        return;
                    }
                }
            }
            else if(pre.size()>0 && post.size()>0 && pre[0].first>=post[0].first){
                if(post[0].first<=q){
                    if(min_d<pre[0].first-post[0].first){
                        min_d = pre[0].first-post[0].first;
                        min_ctr = c;
                    }
                    q-=post[0].first;
                    c++;
                    auto j=pre.begin();
                    for(; j!=pre.end();j++){
                        if(j->second==post[0].second)break;
                    }
                    pre.erase(j);
                    post.erase(post.begin());
                }
                else{
                    if(flag || min_d == INT_MAX){
                        cout<<c<<endl;
                        return;
                    }
                    ffff=1;
                }
            }
            else{
                if(flag || min_d==INT_MAX){
                    cout<<c<<endl;
                    return;
                }
                ffff=1;
            }
        }
        if(ffff)break;
    }
    q = q1;
    pre.resize(n), post.resize(n);
    ctr1=1, ctr2=n;
    // cout<<"hello"<<flag<<endl;
    for (int i=0;i<n;i++)
    {
        pre[i] = {a[i]+ctr1, i};
        post[i] = {a[i]+ctr2, i};
        ctr1++;
        ctr2--;
    }
    sort(pre.begin(), pre.end());
    sort(post.begin(), post.end());
    c = 0;

    cout<<"mind = "<<min_d<<endl;
    while(q>=0){
        if(c==-1){
            if(pre[0].first<=q){
                q-=pre[0].first;
                c++;
                auto j=post.begin();
                for(; j!=post.end();j++){
                    if(j->second==pre[0].second)break;
                }
                post.erase(j);
                pre.erase(pre.begin());
            }
            else{
                cout<<c<<endl;
                return;
            }
        }
        else{
            if((c==min_ctr) || (pre.size()>0 && post.size()>0 && pre[0].first<post[0].first)){
                if(pre[0].first<=q){
                    q-=pre[0].first;
                    c++;
                    auto j=post.begin();
                    for(; j!=post.end();j++){
                        if(j->second==pre[0].second)break;
                    }
                    post.erase(j);
                    pre.erase(pre.begin());
                }
                else{
                    cout<<c<<endl;
                    return;
                }
            }
            else if(pre.size()>0 && post.size()>0 && pre[0].first>=post[0].first){
                if(post[0].first<=q){
                    q-=post[0].first;
                    c++;
                    auto j=pre.begin();
                    for(; j!=pre.end();j++){
                        if(j->second==post[0].second)break;
                    }
                    pre.erase(j);
                    post.erase(post.begin());
                }
                else{
                    cout<<c<<endl;
                    return;
                }
            }
            else{
                cout<<c<<endl;
                return;
            }
        }
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
