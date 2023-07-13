int re;
void msort(vector<int>&a, int l, int r){
    if(l==r)return;
    int mid = (l+r)>>1;
    msort(a, l, mid);
    msort(a, mid+1, r);
    vector<int> k;
    int i=l, j=mid+1;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            k.push_back(a[i]);
            i++;
        }
        else{
            re += mid-i+1;
            k.push_back(a[j]);
            j++;
        }
    }
    while(i<=mid){
        k.push_back(a[i]);
        i++;
    }
    while(j<=r){
        k.push_back(a[j]);
        j++;
    }
    for(int i=l;i<=r;i++){
        a[i] = k[i-l];
    }
}


int count_inv(vector<int> a){
    re=0;
    msort(a, 0, a.size()-1);
    return re;
}
