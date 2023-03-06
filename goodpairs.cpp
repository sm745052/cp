#include<bits/stdc++.h>;
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int A[n], B[n];
		map<int , vector<int>> val_idxs_A, val_idxs_B;
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
			val_idxs_A[A[i]].push_back(i);
		}
		for(int i=0;i<n;i++)
                {
                        cin>>B[i];
			val_idxs_B[B[i]].push_back(i);
                }
		for(auto &i:val_idxs_A)
		{
			auto val = i.first;
			auto idxs = i.second;
			if(val_idxs_B[val].is_empty())continue;
			for(auto &j_A_val:idxs)
			{
				
			}
		}
	}
	return 0;
}
