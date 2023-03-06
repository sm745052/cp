#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007 //10^9+7

bool cmp(vector<int> a, vector<int> b){
    if(a[0]==b[0]){
        return a[2]<b[2];
    }
    return a[0]<b[0];
}



void solve(int test){
    int n 
   cin>>n;
    vector<vector<int>>rectangles(n, vector<int>(4, 0));
    set<int, greater<int> > x_coords;
    for(int i=0;i<n;i++){
        cin>>rectangles[i][0]>>rectangles[i][1]>>rectangles[i][2]>>rectangles[i][3];
        x_coords.insert(rectangles[i][0]);
    }
    sort(rectangles.begin(), rectangles.end(), cmp);
    auto myrect = rectangles.begin(); 
    int p_area=0;
    for(auto it=x_coords.begin(); it!=x_coords.end(); it++){
        if(*myrect[2]>)
    }
    cout<<endl;
}




signed main() {


#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }
    return 0;
}