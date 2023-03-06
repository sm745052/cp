#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<int> even, odd;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		(tmp%2==0)?even.push_back(tmp):odd.push_back(tmp);
	}
	sort(even.begin(), even.end(), greater<int>());
	sort(odd.begin(), odd.end(), greater<int>());
	int ectr=0;
	int octr=0;
	int sum1=0;
	for(int i=0;i<n;i++)
	{
		if(i==0)
                {
                        if(ectr<even.size())
                        {
                                sum1+=even[ectr];
                                ectr++;
                        }
                        continue;
                }
		if(i%2==0)
		{
			if(ectr<even.size()-1)
			{
				ectr++;
				sum1+=even[ectr];
				ectr++;
			}
		}
		else
		{
			if(octr<odd.size()-1)
			{
				octr++;
				sum1+=odd[octr];
				octr++;
			}
		}
	}
	ectr=0;
	octr=0;
	int sum2=0;
        for(int i=0;i<n;i++)
        {
		if(i==0)
		{
			if(octr<odd.size())
                        {
                                sum2+=odd[octr];
                                octr++;
                        }
			continue;
		}
                if(i%2==1)
                {
                        if(ectr<even.size()-1)
                        {
				ectr++;
                                sum2+=even[ectr];
                                ectr++;
                        }
                }
                else
                {
                        if(octr<odd.size()-1)
                        {
				octr++;
                                sum2+=odd[octr];
                                octr++;
                        }
                }
        }
	ectr=0;
	octr=0;
	int sum3=0;
        for(int i=0;i<n;i++)
        {
                if(i==0)
                {
                        if(ectr<even.size())
                        {
                                sum3+=even[ectr];
                                ectr++;
                        }
                        continue;
                }
		if(i==1)
                {
                        if(octr<odd.size())
                        {
                                sum3+=even[octr];
                                octr++;
                        }
                        continue;
                }
                if(i%2==0)
                {
                        if(ectr<even.size()-1)
                        {
                                ectr++;
                                sum3+=even[ectr];
                                ectr++;
                        }
                }
                else
                {
                        if(octr<odd.size()-1)
                        {
                                octr++;
                                sum3+=odd[octr];
                                octr++;
                        }
                }
        }
	ectr=0;
        octr=0;
        int sum4=0;
        for(int i=0;i<n;i++)
        {
                if(i==0)
                {
                        if(octr<odd.size())
                        {
                                sum4+=odd[octr];
                                octr++;
                        }
                        continue;
                }
		if(i==1)
                {
                        if(ectr<even.size())
                        {
                                sum4+=even[ectr];
                                ectr++;
                        }
                        continue;
                }
                if(i%2==1)
                {
                        if(ectr<even.size()-1)
                        {
                                ectr++;
                                sum4+=even[ectr];
                                ectr++;
                        }
                }
                else
                {
                        if(octr<odd.size()-1)
                        {
                                octr++;
                                sum4+=odd[octr];
                                octr++;
                        }
                }
        }

	cout<<max({sum1, sum2, sum3, sum4})<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
