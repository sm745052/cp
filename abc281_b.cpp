#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    if(s.length()==1+6+1){
        if(s[0]>='A' && s[0]<='Z'){
            int f = 0;
            for(int i=0;i<6;i++){
                if(s.substr(1, 6)[i]<'0' || s.substr(1, 6)[i]>'9')f = 1;
            }
            if(!f){
                if(s[1]!='0'){
                    if(s[7]>='A' && s[7]<='Z'){
                        cout<<"Yes"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}