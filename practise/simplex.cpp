#include<bits/stdc++.h>
using namespace std;


void print_table(vector<vector<double> > arr, vector<double> c, vector<int> bv, vectro<int> nbv)
{
	int m = 
}




int main()
{
	int m, n;
	cout<<"Enter number of variables [n]"<<endl;
	cin>>n;
	cout<<"Enter number of eq [m]"<<endl;
	cin>>m;
	int n_nbv = n - m;
	vector<vector <double>> arr;
	vector<double> c;
	vector<int> bv;
	vector<int> nbv;
	for(int i=0;i<m;i++)
	{
		vector<int> tmp;
		for(int j=0;j<n;j++)
		{
			int t;
			cin>>t;
			tmp.push_back(t);
			bv.push_back(j);
		}
		for(int j=0;j<n_nbv;j++)
		{
			nbv.push_back(j+i+1);
			tmp.push_back((j==i)?1:0);
		}
		arr.push_back(tmp);
		cin>>tmp;
		c.push_back(tmp);

	}
	print_table(arr, c, bv, nbv);
	return 0;
}
