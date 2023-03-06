#include<bits/stdc++.h>
using namespace std;

map<int, int> freq;
bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b)
{
	return a.second.size()<b.second.size();
}

bool cmp1(int a, int b)
{
	return freq[a]>freq[b];
}



void solve()
{
	int n;
	cin>>n;
	vector<int> sqs;
	map<int, vector<int>>candidates;
	map<int, map<int, int>>used;
	map<int, int>candidates_lengths;
	for(int i=0;i*i<=2*(n-1);i++)
	{
		sqs.push_back(i*i);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<sqs.size();j++)
		{
			if(sqs[j]-i>=0 && used[i][sqs[j]-i]==0 && sqs[j]-i!=n)
			{
				candidates[i].push_back(sqs[j]-i);
				used[i][sqs[j]-i] = 1;
				freq[sqs[j]-i]++;
				candidates_lengths[i]++;
			}
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		cout<<candidates_lengths[i]<<endl;
	}
	*/
	vector<pair<int, vector<int>>> candidates_pairs;
	for(auto &i:candidates)
	{
		sort(i.second.begin(), i.second.end(), cmp1);
		candidates_pairs.push_back({i.first, i.second});
	}
	sort(candidates_pairs.begin(), candidates_pairs.end(), cmp);
	map<int, int> n_used;
	int arr[n];
//	cout<<"hlo"<<endl;
	for(auto i:candidates_pairs)
	{
		//cout<<"hlo"<<endl;
		for(auto j = i.second.begin();;j++)
		{
			//cout<<"hlo"<<endl;
			if(j == i.second.end())
			{
			//	cout<<"hlo"<<endl;
				cout<<-1<<endl;
				return;
			}
			if(n_used[*j]==0)
			{
				arr[i.first] = *j;
				n_used[*j] = 1;
				//cout<<"hello"<<endl;
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<((i==n-1)?"\n":" ");
	}
	freq.clear();
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
