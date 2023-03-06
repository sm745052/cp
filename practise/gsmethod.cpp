#include<bits/stdc++.h>
using namespace std;


void gauss_scheidel(vector<vector <double> > A, vector<double>b, vector<double>& x, int n, double tol=0.1, int max_iterations = 1000)
{
	n = b.size();
	vector<double> prev_x(n, 0);
	for(int i=0;i<n;i++)
	{
		prev_x[i] = x[i];
	}
	int iterations = 0;
	while(true)
	{
		iterations += 1;
		for(int i=0;i<n;i++)
		{
			double sum_row = 0;
			for(int j=0;j<n;j++)
			{
				sum_row += A[i][j] * x[j];
			}
			double sum_row_except_this = sum_row - A[i][i]*x[i];
			x[i] = (b[i] - sum_row_except_this)/A[i][i];
		}
		double max_change = 0;
		for(int i=0;i<n;i++)
		{
			max_change = max(max_change, abs(prev_x[i]-x[i]));
			prev_x[i] = x[i];
		}
		if(max_change<=tol)
		{
			break;
		}
		if(iterations == max_iterations)
		{
			cout<<"solution didnot converge"<<endl;
			break;
		}
	}
	cout<<"no of iterations -- "<<iterations<<endl;
}





vector<vector<int> > chooser(int n, int r)
{
	vector<bool> v(n);
	vector<vector<int> > to_be_zeroed;
	fill(v.end() - r, v.end(), true);
	int ctr = 0;
	do {
		ctr++;
		vector<int> tmp;
		for (int i = 0; i < n; ++i) {
		    if (v[i]) {
		        tmp.push_back(i);
		    }
		}
		to_be_zeroed.push_back(tmp);
	} while(next_permutation(v.begin(), v.end()));
	cout<<"total number of permutations -- "<<ctr<<endl;
	return to_be_zeroed;
}


double z(vector<double> C, vector<double> x)
{
	double sum = 0;
	for(int i=0;i<x.size();i++)
	{
		sum += C[i]*x[i];
	}
	return sum;
}




vector<vector<double> > BFS(vector<vector <double> > A, vector<double>b)
{
	int m = A.size();
	int n = A[0].size();
	vector<vector<int> > to_be_zeroed = chooser(n, n-m);
	vector<vector<double> > all_feasible;
	for(auto &ind:to_be_zeroed)
	{
		cout<<"----------------\nto be zeroed:\n";
		for(auto &k:ind)
		{
			cout<<"x_"<<k<<endl;
		}
		cout<<"-----------------\n";
		vector<vector<double> > A_tmp;
		for(int i=0;i<m;i++)
		{
			vector<double> a_row;
			for(int j=0;j<n;j++)
			{
				bool iszeroed = false;
				for(auto &k:ind)
				{
					if(k==j){iszeroed=true;break;}
				}
				if(!iszeroed)
					a_row.push_back(A[i][j]);
			}
			A_tmp.push_back(a_row);
		}
		cout<<"A tmp\n---------\n";
		for(auto &i:A_tmp)
		{
			for(auto &j:i)
			{
				cout<<j<<" ";
			}
			cout<<endl;
		}
		cout<<"-----------\nb\n";
		for(auto &i:b)
		{
			cout<<i<<endl;
		}
		cout<<"-----------\n";
		vector<double> x(m, 0);
		gauss_scheidel(A_tmp, b, x, m, 0.000000001, 1000);
		int ctr1=0;
		bool feasible=1;
		vector<double> x_updated(n, 0);
		for(int i=0;i<n;i++)
       		{
			int flag = 0;
			for(auto &k:ind)
               	        {
				if(k==i){cout<<"x"<<i<<" = "<<0<<endl;flag=1;break;}
                        }
			if(!flag)
			{
                		cout<<"x"<<i<<" = "<<x[ctr1]<<endl;
				if(x[ctr1]<0 || isnan(x[ctr1]))
					feasible = 0;
				x_updated[i] = x[ctr1];
				ctr1++;
			}
	        }
		if(!feasible)
		{
			cout<<"unfeasible solution"<<endl;
		}
		else
		{
			cout<<"feasible"<<endl;
			all_feasible.push_back(x_updated);
		}
	}
	return all_feasible;
}




int main()
{
	int n, m;
	cout<<"Enter number of equations [m]:";
	cin>>m;
	cout<<"Enter number of variables [n]:";
	cin>>n;
	if(m>n)cout<<"this system is over constrained"<<endl;
	vector<vector<double> > A(m, vector<double>(n));
	vector<double> b(m, 0);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"Enter A"<<i<<"_"<<j<<":";
			cin>>A[i][j];
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<"Enter b"<<i<<":";
		cin>>b[i];
	}
	vector<double> x(n, 0);
	cout<<"A entered:\n---------\n";
        for(auto &i:A)
        {
		for(auto &j:i)
                {
			cout<<j<<" ";
                }
                cout<<endl;
        }
	cout<<"-----------\nb entered:\n";
        for(auto &i:b)
        {
		cout<<i<<endl;
        }






	auto all_feasible = BFS(A, b);
	if(all_feasible.size()==0)
        {
                cout<<"No feasible solutions found"<<endl;
                return 0;
        }
	cout<<"-------------------------------------------------------------------\nFeasible solutions are\n";
	for(auto &i:all_feasible)
        {
		cout<<"[";
                for(int j=0;j<i.size();j++)
                {
                        cout<<i[j]<<((j!=i.size()-1)?", ":"]\n");
                }
        }


	cout<<"-----------------------------------------------------------------\nEnter objective function[z] coeffecients:\n";
	vector<double> C(n, 0);
	for(int i=0;i<n;i++)
	{
		cout<<"Enter coeffecient of x_"<<i<<":";
		cin>>C[i];
	}
	cout<<"---------------------------------------------------------------\nEnter 1 if maximize, 0 if minimize:";
	bool to_max;
	cin>>to_max;


	vector<double> z_vals;
	for(auto &i:all_feasible)
	{
		z_vals.push_back(z(C, i));
	}

	cout<<"corresponding z values are: \n";
	double our_val = (to_max)?DBL_MIN:DBL_MAX;
	vector<double> our_x;
	for(int i=0;i<z_vals.size();i++)
	{
		if((to_max)?(our_val<z_vals[i]):(our_val>z_vals[i]))
		{
			our_val = z_vals[i];
			our_x = all_feasible[i];
		}
		cout<<z_vals[i]<<endl;
	}
	cout<<"Final solution for "<<((to_max)?"max":"min")<<"imization is :[";
	for(int j=0;j<n;j++)
        {
		cout<<our_x[j]<<((j!=n-1)?", ":"]\n");
	}
	cout<<((to_max)?"max":"min")<<" value of z = "<<our_val<<endl;
	return 0;
}
