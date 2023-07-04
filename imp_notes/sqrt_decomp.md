# Sqrt decomposition

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int bs = (int)sqrt(n+0.0) + 1;
    vector<int> b(n/bs + 1, INT_MIN), a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i/bs] = max(a[i], b[i/bs]);
    }
    int q;
    cin>>q;
    while(q--){
        int l; int r;
        cin>>l>>r;
        l--, r--;
        int res = INT_MIN;
        for(int i=l;i<=r;){
            if(i%bs==0 && i+bs-1<=r){
                res = max(res, b[i/bs]);
                i+=bs;
            }
            else{
                res = max(res, a[i]);
                i++;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
```

## Note
We can set block size to any thing (Except 0) and set length of the blocks array to (n/bs + 1). but when done to sqrt(n) it is optimized.
This is done when merging the blocks is easy. When it is hard, we can see MO's algorithm.
