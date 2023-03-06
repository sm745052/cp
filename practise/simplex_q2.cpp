#include <iostream>
#include <cmath>
#include <vector>
#include<bits/stdc++.h>
using namespace std;


void gauss_scheidel(vector<vector <double> > A, vector<double>b, vector<double>& x, int n, double tol, int max_iterations)
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




void BFSmain(vector<vector<double> > A, vector<double> b, int m, int n)
{

	if(m>n)
	{
		cout<<"this system is over constrained"<<endl;
		return;
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
                return;
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
}





















class Simplex
{

private:
    int rows, cols;
    // stores coefficients of all the variables
    vector<vector<double> > A;
    // stores constants of constraints
    vector<double> B;
    // stores the coefficients of the objective function
    vector<double> C;
    double maximum;
    bool isUnbounded;
    vector<int> basis;
    vector<double> ratios;

public:
    Simplex(vector<vector<double> > matrix, vector<double> b, vector<double> c)
    {
        maximum = 0;
        isUnbounded = false;
        rows = matrix.size();
        cols = matrix[0].size();
        A.resize(rows, vector<double>(cols, 0));
        B.resize(b.size());
        C.resize(c.size());
        basis.resize(rows, 0);
        ratios.resize(rows, 0);
        for(int i = rows;i<rows+cols;i++)
        {
            basis[i-rows] = i;
        }
        for (int i = 0; i < rows; i++)
        { // pass A[][] values to the metrix
            for (int j = 0; j < cols; j++)
            {
                A[i][j] = matrix[i][j];
            }
        }

        for (int i = 0; i < c.size(); i++)
        { // pass c[] values to the B vector
            C[i] = c[i];
        }
        for (int i = 0; i < b.size(); i++)
        { // pass b[] values to the B vector
            B[i] = b[i];
        }
    }

    bool simplexAlgorithmCalculataion()
    {
        // check whether the table is optimal,if optimal no need to process further
        if (checkOptimality() == true)
        {
            return true;
        }
        // find the column which has the pivot.The least coefficient of the objective function(C array).
        int pivotColumn = findPivotColumn();

        if (isUnbounded == true)
        {
            cout << "Error unbounded" << endl;
            return true;
        }

        // find the row with the pivot value.The least value item's row in the B array
        int pivotRow = findPivotRow(pivotColumn);

        // form the next table according to the pivot value
        doPivotting(pivotRow, pivotColumn);

        return false;
    }
    bool checkOptimality()
    {
        // if the table has further negative constraints,then it is not optimal
        bool isOptimal = false;
        int positveValueCount = 0;

        // check if the coefficients of the objective function are negative
        for (int i = 0; i < C.size(); i++)
        {
            double value = C[i];
            if (value >= 0)
            {
                positveValueCount++;
            }
        }
        // if all the constraints are positive now,the table is optimal

        if (positveValueCount == C.size())
        {
            isOptimal = true;
            print(0);
        }
        else
        {
            print(0);
        }
        return isOptimal;
    }

    void doPivotting(int pivotRow, int pivotColumn)
    {
        cout<<"pivoting r = "<<pivotRow<<" c = "<<pivotColumn<<endl;
        double pivetValue = A[pivotRow][pivotColumn]; // gets the pivot value

        double pivotRowVals[cols]; // the column with the pivot

        double pivotColVals[rows]; // the row with the pivot

        double rowNew[cols]; // the row after processing the pivot value

        maximum = maximum - (C[pivotColumn] * (B[pivotRow] / pivetValue)); // set the maximum step by step
        // get the row that has the pivot value
        for (int i = 0; i < cols; i++)
        {
            pivotRowVals[i] = A[pivotRow][i];
        }
        // get the column that has the pivot value
        for (int j = 0; j < rows; j++)
        {
            pivotColVals[j] = A[j][pivotColumn];
        }
        for(int i=0;i<rows;i++)
        {
        	ratios[i] = B[i]/pivotColVals[i];
        }
        // set the row values that has the pivot value divided by the pivot value and put into new row
        for (int k = 0; k < cols; k++)
        {
            rowNew[k] = pivotRowVals[k] / pivetValue;
        }

        B[pivotRow] = B[pivotRow] / pivetValue;

        // process the other coefficients in the A array by subtracting
        for (int m = 0; m < rows; m++)
        {
            // ignore the pivot row as we already calculated that
            if (m != pivotRow)
            {
                for (int p = 0; p < cols; p++)
                {
                    double multiplyValue = pivotColVals[m];
                    A[m][p] = A[m][p] - (multiplyValue * rowNew[p]);
                    // C[p] = C[p] - (multiplyValue*C[pivotRow]);
                    // B[i] = B[i] - (multiplyValue*B[pivotRow]);
                }
            }
        }

        // process the values of the B array
        for (int i = 0; i < B.size(); i++)
        {
            if (i != pivotRow)
            {

                double multiplyValue = pivotColVals[i];
                B[i] = B[i] - (multiplyValue * B[pivotRow]);
            }
        }
        // the least coefficient of the constraints of the objective function
        double multiplyValue = C[pivotColumn];
        // process the C array
        for (int i = 0; i < C.size(); i++)
        {
            C[i] = C[i] - (multiplyValue * rowNew[i]);
        }

        // replacing the pivot row in the new calculated A array
        for (int i = 0; i < cols; i++)
        {
            A[pivotRow][i] = rowNew[i];
        }
        // changing the basis
        basis[pivotRow] = pivotColumn;
    }

    // print the current A array
    void print(char sel)
    {
    	if(sel=='t')
    	{
    		cout << "The current table is : " << endl;
		    for (int i = 0; i < rows; i++)
		    {
		        for (int j = 0; j < cols; j++)
		        {
		            cout << A[i][j] << " ";
		        }
		        cout << "" << endl;
		    }
		    return;
    	}
    	if(sel=='r')
    	{
    		cout<<"ratios are: \n";
    		for(int i=0;i<rows;i++)
    		{
    			cout<<ratios[i]<<endl;
    		}
    		return;
    	}
    	if(sel=='n')
    	{
    		cout<<"Values of non basic variables:\n";
		    for (int i = 0; i < C.size(); i++)
		    {
		    	int flag = 0;
		    	for(int j=0;j<basis.size();j++)
		    	{
		    		if(i==basis[j])
		    		{
		    			flag = 1;
		    			break;
					}
		    	}
		    	if(flag)
		    	{
		    		continue;
		    	}
		        cout <<"x"<<i<<"="<< 0<<endl;
		    }
		    return;
    	}
    	if(sel=='b')
    	{
    		cout<<"Values of basic variables:\n";
		    for (int i = 0; i < B.size(); i++)
		    {
		        cout <<"x"<<basis[i]<<"="<< B[i] <<endl;
		    }
		    return;
    	}
        cout << "The current table is : " << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << "" << endl;
        }
        cout<<"Values of basic variables:\n";
        for (int i = 0; i < B.size(); i++)
        {
            cout <<"x"<<basis[i]<<"="<< B[i] <<endl;
        }
        cout<<"Values of C:\n";
        for (int i = 0; i < C.size(); i++)
        {
            cout << C[i] << " ";
        }
        cout<<endl;
        cout << "values of input variables" << endl;
        for(int i=0;i<B.size();i++)
        {
        	int flag = 0;
        	int ind = 0;
        	for(int j = 0;j<basis.size();j++)
        	{
        		if(basis[j]==i)
        		{
        			flag = 1;
	        		ind = j;
	        		break;
        		}
        	}
        	if(flag==1)
        	{
        		cout<<"x"<<i<<"="<<B[ind]<<endl;
        	}
        	else
        	{
        		cout<<"x"<<i<<"="<<0<<endl;
        	}
        }
        cout << "" << endl;
        cout<<"\n------------------"<<endl;
    }

    // find the least coefficients of constraints in the objective function's position
    int findPivotColumn()
    {

        int location = 0;
        double minm = C[0];

        for (int i = 1; i < C.size(); i++)
        {
            if (C[i] < minm)
            {
                minm = C[i];
                location = i;
            }
        }

        return location;
    }

    // find the row with the pivot value.The least value item's row in the B array
    int findPivotRow(int pivotColumn)
    {
        double positiveValues[rows];
        vector<double> result(rows, 0);
        // double result[rows];
        int negativeValueCount = 0;

        for (int i = 0; i < rows; i++)
        {
            if (A[i][pivotColumn] > 0)
            {
                positiveValues[i] = A[i][pivotColumn];
            }
            else
            {
                positiveValues[i] = 0;
                negativeValueCount += 1;
            }
        }
        // checking the unbound condition if all the values are negative ones
        if (negativeValueCount == rows)
        {
            isUnbounded = true;
        }
        else
        {
            for (int i = 0; i < rows; i++)
            {
                double value = positiveValues[i];
                if (value > 0)
                {
                    result[i] = B[i] / value;
                }
                else
                {
                    result[i] = 0;
                }
            }
        }

        // find the minimum's location of the smallest item of the B array
        double minimum = 99999999;
        int location = 0;
        for (int i = 0; i < sizeof(result) / sizeof(result[0]); i++)
        {
            if (result[i] > 0)
            {
                if (result[i] < minimum)
                {
                    minimum = result[i];
                    location = i;
                }
            }
        }
        return location;
    }
    void CalculateSimplex()
    {
        bool end = false;
        while (!end)
        {

            bool result = simplexAlgorithmCalculataion();
            if (result == true)
            {
                end = true;
            }
        }
        cout << "values of input variables" << endl;
        for(int i=0;i<B.size();i++)
        {
        	int flag = 0;
        	int ind = 0;
        	for(int j = 0;j<basis.size();j++)
        	{
        		if(basis[j]==i)
        		{
        			flag = 1;
	        		ind = j;
	        		break;
        		}
        	}
        	if(flag==1)
        	{
        		cout<<"x"<<i<<"="<<B[ind]<<endl;
        	}
        	else
        	{
        		cout<<"x"<<i<<"="<<0<<endl;
        	}
        }
        cout << "" << endl;
        cout << "maximum value: " << maximum << endl; // print the maximum values
    }
};



int main()
{
	cout<<"Enter number of eqns: ";
	int m;
	cin>>m;
	cout<<"enter number of variables: ";
	int n;
	cin>>n;
	cout<<"enter the coeffecients"<<endl;
	double tmp_arr[m][m+n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m+n;j++)
		{
			if(j<n)
			{
				cin>>tmp_arr[i][j];
			}
			else if(j==n+i)
			{
				tmp_arr[i][j] = 1;
			}
			else
			{
				tmp_arr[i][j] = 0;
			}
		}
	}
	cout<<"Enter RHS of the equations\n";
	double tmp_b[m];
	for(int i=0;i<m;i++)
	{
		cin>>tmp_b[i];
	}
	cout<<"Enter the coefficients of objective function"<<endl;
	double tmp_c[n];
	for(int i=0;i<n;i++)
	{
		cin>>tmp_c[i];
		tmp_c[i] = -tmp_c[i];
	}
    int colSizeA = m+n; // should initialise columns size in A
    int rowSizeA = m; // should initialise columns row in A[][] vector
    
    
    double C[n]; // should initialise the c array here
    double B[m];       // should initialise the b array here
	for(int i=0;i<n;i++)
	{
		C[i] = tmp_c[i];
	}
	for(int i=0;i<m;i++)
	{
		B[i] = tmp_b[i];
	}
	double a[m][m+n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m+n;j++)
		{
			a[i][j] = tmp_arr[i][j];
		}
	}
    vector<vector<double> > vec2D(rowSizeA, vector<double>(colSizeA, 0));
    vector<double> b(rowSizeA, 0);
    vector<double> c(colSizeA, 0);
    for (int i = 0; i < rowSizeA; i++)
    { // make a vector from given array
        for (int j = 0; j < colSizeA; j++)
        {
            vec2D[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < rowSizeA; i++)
    {
        b[i] = B[i];
    }
    for (int i = 0; i < rowSizeA; i++)
    {
        c[i] = C[i];
    }
    
    // hear the make the class parameters with A[m][n] vector b[] vector and c[] vector
    Simplex simplex(vec2D, b, c);
    
    
    
    while(1)
    {
		cout<<"(a) List of all BFS (b) Print the initial simplex table (c) List of all Non-basic variables in the initial table (d) List of Basic variables along with ratios in the previous iteration (e) simplex table of the second iteration"<<endl;
		char ch;
		cin>>ch;
		switch(ch)
		{
			case 'a':
				BFSmain(vec2D, b, rowSizeA, colSizeA);
				break;
			case 'b':
				simplex.print('t');
				break;
			case 'c':
				simplex.print('n');
				break;
			case 'd':
				simplex.print('b');
				simplex.print('r');	
				break;
			case 'e':
				bool res = simplex.simplexAlgorithmCalculataion();
				simplex.print('t');
		}
	}
    return 0;
}
