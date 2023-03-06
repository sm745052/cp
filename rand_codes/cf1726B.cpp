#include<bits/stdc++.h>
using namespace std;


void solve()
{
        int n;
        cin>>n;
        int arr[n]={0};
        int m;
	cin>>m;
	if(n>m)
	{
		cout<<"NO"<<endl;
		return;
	}
	else if(n==1)
	{
		cout<<"YES\n"<<m<<endl;return;
	}
	else if(m==n)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			arr[i]=1;
		}
	}
	else if(n%2==0 && m%2==0)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			arr[i] += 1;
		}
		arr[0] += (m-n)/2;
		arr[1] += (m-n)/2;
	}
	else if(n%2!=0 && m%2==0)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			arr[i]+=1;
		}
		arr[0] += m-n;
	}
	else if(n%2!=0 && m%2!=0)
	{
		if(m==n){cout<<"NO"<<endl;return;}
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
                {
                        arr[i]+=1;
                }
                arr[0] += m-n;
	}
	else
	{
		cout<<"NO"<<endl;
		return;
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<((i==n-1)?"\n":" ");
	}
}


int main()
{
        int t;
        cin>>t;
        while(t--)
        {
                solve();
        }
        return 0;
}

