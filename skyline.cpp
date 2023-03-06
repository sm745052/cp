#include<bits/stdc++.h>
using namespace std;



int main(){
    vector<vector<int> > buildings= {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    set<int> coor;
    for(auto i:buildings){
        coor.insert(i[0]);
        coor.insert(i[1]);
    }
    map<int, int> cmp, dcmp;
    int ctr=0;
    for(auto it = coor.begin();it!=coor.end();it++){
        cmp[*it] = ctr;
        dcmp[ctr] = *it;
        ctr++;
    }
    pair<vector<int>, vector<int> > arr[coor.size()];
    for(auto i:buildings){
        arr[cmp[i[0]]].first.push_back(i[2]);
        arr[cmp[i[1]]].second.push_back(i[2]);
    }
    multiset<int> tr;
    int fin_arr[coor.size()] = {0};
    for(int i=0;i<coor.size();i++){
        for(auto j:arr[i].first){
            tr.insert(j);
        }
        for(auto j:arr[i].second){
            if(tr.find(j)!=tr.end())
                tr.erase(tr.find(j));
        }
        if(tr.size()!=0){
            fin_arr[i] = *(tr.rbegin());
        }
    }
    vector<vector<int> >g1;
    g1.push_back({dcmp[0], fin_arr[0]});
    for(int i=1;i<coor.size();i++){
        if(fin_arr[i]!=fin_arr[i-1]){
            g1.push_back({dcmp[i], fin_arr[i]});
        }
    }
    for(auto i:g1){
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    return 0;
}