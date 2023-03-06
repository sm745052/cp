#include<bits/stdc++.h>
using namespace std;
int foo(int x, int y)
{
    return stoi(to_string(x) + to_string(y));
}
vector<int> generate()
{
    vector<int> v;
    for(int i=1;i<=9;i++)
    {
        if(i==1)
        {
            v.push_back(4);
            v.push_back(7);
        }
        vector<int> v2 = vector<int>(v.begin(), v.end());

    }
    return v;
}
int main()
{
    int a, b;
    cin>>a>>b;
    int arr[] = generate();
}