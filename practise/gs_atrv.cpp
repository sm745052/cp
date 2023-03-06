#include<bits/stdc++.h>
using namespace std;


void gauss_scheidel(vector<vector <double> > A, vector<double>b, vector<double>& x, double tol, int max_iterations)
{
        int n = b.size();
	x.resize(n, 0);
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
}


/*
vector<vector<int> > combination(int n, int r)
{
        vector<bool> v(n);
        vector<vector<int> > to_make_zero;
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
                to_make_zero.push_back(tmp);
        } while(next_permutation(v.begin(), v.end()));
        return to_be_zeroed;
}



double objective(vector<double> C, vector<double> x)
{
        double sum = 0;
        for(int i=0;i<x.size();i++)
        {
                sum += C[i]*x[i];
        }
        return sum;
}

*/


/*vector<vector<double> > BFS(vector<vector <double> > A, vector<double>b)
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

*/






void take_input(vector<vector<double> > &A, vector<double> &b)
{
	cout<<"Enter no of eqn"<<endl;
	int m;
	cin>>m;
	cout<<"Enter no of variables"<<endl;
	int n;
	cin>>n;
	cout<<"Enter A"<<endl;
	A.resize(0);
	for(int i=0;i<m;i++)
	{
		vector<double> row;
		row.resize(n);
		for(int j=0;j<n;j++)
		{
			cin>>row[i];
		}
		A.push_back(row);
	}
	cout<<"Enter b\n";
	b.resize(m);
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
}






int main()
{
	vector<vector<double> >A;
	vector<double> b;
	take_input(A, b);
	vector<double> x;
	gauss_scheidel(A, b, x, 0.001, 1000);
	for(int i=0;i<x.size();i++)
	{
		cout<<x[i]<<(i==x.size()-1)?", ":"\n";
	}
	return 0;
}
