#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin>>x1>>y1>>x2>>y2;
    if(x1!=x2 && y1!=y2)
    {
        if(abs(x2-x1)==abs(y2-y1))
        {
            cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<endl;
            return 0;
        }
        cout<<"-1"<<endl;
        return 0;
    }
    int l = abs(x1-x2+y1-y2);
    if(x1==x2)
    {
        cout<<x1+l<<" "<<y1<<" "<<x2+l<<" "<<y2<<endl;
        return 0;
    }
    else
    {
        cout<<x1<<" "<<y1+l<<" "<<x2<<" "<<y2+l<<endl;
        return 0;
    }
    return 0;
}