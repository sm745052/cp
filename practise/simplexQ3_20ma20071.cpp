#include <bits/stdc++.h>
using namespace std;

void gauss_scheidel(vector<vector<double>> A, vector<double> b, vector<double> &x, int n, double tol, int max_iterations)
{
	n = b.size();
	vector<double> prev_x(n, 0);
	for (int i = 0; i < n; i++)
	{
		prev_x[i] = x[i];
	}
	int iterations = 0;
	while (true)
	{
		iterations += 1;
		for (int i = 0; i < n; i++)
		{
			double sum_row = 0;
			for (int j = 0; j < n; j++)
			{
				sum_row += A[i][j] * x[j];
			}
			double sum_row_except_this = sum_row - A[i][i] * x[i];
			x[i] = (b[i] - sum_row_except_this) / A[i][i];
		}
		double max_change = 0;
		for (int i = 0; i < n; i++)
		{
			max_change = max(max_change, abs(prev_x[i] - x[i]));
			prev_x[i] = x[i];
		}
		if (max_change <= tol)
		{
			break;
		}
		if (iterations == max_iterations)
		{
			cout << "solution didnot converge" << endl;
			break;
		}
	}
	cout << "no of iterations -- " << iterations << endl;
}

vector<vector<int>> chooser(int n, int r)
{
	vector<bool> v(n);
	vector<vector<int>> to_be_zeroed;
	fill(v.end() - r, v.end(), true);
	int ctr = 0;
	do
	{
		ctr++;
		vector<int> tmp;
		for (int i = 0; i < n; ++i)
		{
			if (v[i])
			{
				tmp.push_back(i);
			}
		}
		to_be_zeroed.push_back(tmp);
	} while (next_permutation(v.begin(), v.end()));
	cout << "total number of permutations -- " << ctr << endl;
	return to_be_zeroed;
}

double z(vector<double> C, vector<double> x)
{
	double sum = 0;
	for (int i = 0; i < x.size(); i++)
	{
		sum += C[i] * x[i];
	}
	return sum;
}

vector<vector<double>> BFS(vector<vector<double>> A, vector<double> b)
{
	int m = A.size();
	int n = A[0].size();
	vector<vector<int>> to_be_zeroed = chooser(n, n - m);
	vector<vector<double>> all_feasible;
	for (auto &ind : to_be_zeroed)
	{
		cout << "----------------\nto be zeroed:\n";
		for (auto &k : ind)
		{
			cout << "x_" << k << endl;
		}
		cout << "-----------------\n";
		vector<vector<double>> A_tmp;
		for (int i = 0; i < m; i++)
		{
			vector<double> a_row;
			for (int j = 0; j < n; j++)
			{
				bool iszeroed = false;
				for (auto &k : ind)
				{
					if (k == j)
					{
						iszeroed = true;
						break;
					}
				}
				if (!iszeroed)
					a_row.push_back(A[i][j]);
			}
			A_tmp.push_back(a_row);
		}
		cout << "A tmp\n---------\n";
		for (auto &i : A_tmp)
		{
			for (auto &j : i)
			{
				cout << j << " ";
			}
			cout << endl;
		}
		cout << "-----------\nb\n";
		for (auto &i : b)
		{
			cout << i << endl;
		}
		cout << "-----------\n";
		vector<double> x(m, 0);
		gauss_scheidel(A_tmp, b, x, m, 0.000000001, 1000);
		int ctr1 = 0;
		bool feasible = 1;
		vector<double> x_updated(n, 0);
		for (int i = 0; i < n; i++)
		{
			int flag = 0;
			for (auto &k : ind)
			{
				if (k == i)
				{
					cout << "x" << i << " = " << 0 << endl;
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				cout << "x" << i << " = " << x[ctr1] << endl;
				if (x[ctr1] < 0 || isnan(x[ctr1]))
					feasible = 0;
				x_updated[i] = x[ctr1];
				ctr1++;
			}
		}
		if (!feasible)
		{
			cout << "unfeasible solution" << endl;
		}
		else
		{
			cout << "feasible" << endl;
			all_feasible.push_back(x_updated);
		}
	}
	return all_feasible;
}

void BFSmain(vector<vector<double>> A, vector<double> b, int m, int n)
{

	if (m > n)
	{
		cout << "this system is over constrained" << endl;
		return;
	}

	vector<double> x(n, 0);
	cout << "A entered:\n---------\n";
	for (auto &i : A)
	{
		for (auto &j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	cout << "-----------\nb entered:\n";
	for (auto &i : b)
	{
		cout << i << endl;
	}

	auto all_feasible = BFS(A, b);
	if (all_feasible.size() == 0)
	{
		cout << "No feasible solutions found" << endl;
		return;
	}
	cout << "-------------------------------------------------------------------\nFeasible solutions are\n";
	for (auto &i : all_feasible)
	{
		cout << "[";
		for (int j = 0; j < i.size(); j++)
		{
			cout << i[j] << ((j != i.size() - 1) ? ", " : "]\n");
		}
	}
}

class Simplex
{

public:
	int rows, cols;
	vector<vector<double>> A;
	vector<double> B;
	vector<double> C;
	double maximum;
	bool isUnbounded;
	vector<int> basis;
	vector<double> ratios;

public:
	Simplex(vector<vector<double>> matrix, vector<double> b, vector<double> c)
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
		for (int i = rows; i < rows + cols; i++)
		{
			basis[i - rows] = i;
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

	bool simplex_iteration()
	{
		if (checkOptimality() == true)
		{
			return true;
		}
		int pivotColumn = findPivotColumn();
		if (isUnbounded == true)
		{
			cout << "Error unbounded" << endl;
			return true;
		}
		int pivotRow = findPivotRow(pivotColumn);
		printf("pivoting %d %d element whose value is %f\n", pivotRow, pivotColumn, A[pivotRow][pivotColumn]);
		doPivotting(pivotRow, pivotColumn);
		print('t');
		print('i');
		print('c');
		cout << "Objective value = " << maximum << endl;
		return false;
	}
	bool checkOptimality()
	{
		bool isOptimal = false;
		int positveValueCount = 0;

		for (int i = 0; i < C.size(); i++)
		{
			double value = C[i];
			if (value >= 0)
			{
				positveValueCount++;
			}
		}

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
		double pivetValue = A[pivotRow][pivotColumn]; // gets the pivot value

		double pivotRowVals[cols]; // the column with the pivot

		double pivotColVals[rows]; // the row with the pivot

		double rowNew[cols]; // the row after processing the pivot value

		maximum = maximum - (C[pivotColumn] * (B[pivotRow] / pivetValue)); // set the maximum step by step
		for (int i = 0; i < cols; i++)
		{
			pivotRowVals[i] = A[pivotRow][i];
		}
		for (int j = 0; j < rows; j++)
		{
			pivotColVals[j] = A[j][pivotColumn];
		}
		for (int i = 0; i < rows; i++)
		{
			ratios[i] = B[i] / pivotColVals[i];
		}
		for (int k = 0; k < cols; k++)
		{
			rowNew[k] = pivotRowVals[k] / pivetValue;
		}

		B[pivotRow] = B[pivotRow] / pivetValue;

		for (int m = 0; m < rows; m++)
		{
			if (m != pivotRow)
			{
				for (int p = 0; p < cols; p++)
				{
					double multiplyValue = pivotColVals[m];
					A[m][p] = A[m][p] - (multiplyValue * rowNew[p]);
				}
			}
		}

		for (int i = 0; i < B.size(); i++)
		{
			if (i != pivotRow)
			{

				double multiplyValue = pivotColVals[i];
				B[i] = B[i] - (multiplyValue * B[pivotRow]);
			}
		}
		double multiplyValue = C[pivotColumn];
		for (int i = 0; i < C.size(); i++)
		{
			C[i] = C[i] - (multiplyValue * rowNew[i]);
		}

		for (int i = 0; i < cols; i++)
		{
			A[pivotRow][i] = rowNew[i];
		}
		basis[pivotRow] = pivotColumn;
	}

	void print(char choose)
	{
		if (choose == 'c')
		{
			cout << "Current c is" << endl;
			for (int i = 0; i < C.size(); i++)
			{
				cout << C[i] << " ";
			}
			cout << endl;
			return;
		}
		if (choose == 't')
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
		if (choose == 'r')
		{
			cout << "ratios are: \n";
			for (int i = 0; i < rows; i++)
			{
				cout << ratios[i] << endl;
			}
			return;
		}
		if (choose == 'i')
		{
			cout << "values of BFS" << endl;
			for (int i = 0; i < cols - rows; i++)
			{
				int flag = 0;
				int ind = 0;
				for (int j = 0; j < basis.size(); j++)
				{
					if (basis[j] == i)
					{
						flag = 1;
						ind = j;
						break;
					}
				}
				if (flag == 1)
				{
					cout << "x" << i << "=" << B[ind] << endl;
				}
				else
				{
					cout << "x" << i << "=" << 0 << endl;
				}
			}
			cout << "" << endl;
		}

		if (choose == 'n')
		{
			cout << "Values of non basic variables:\n";
			for (int i = 0; i < C.size(); i++)
			{
				int flag = 0;
				for (int j = 0; j < basis.size(); j++)
				{
					if (i == basis[j])
					{
						flag = 1;
						break;
					}
				}
				if (flag)
				{
					continue;
				}
				cout << "x" << i << "=" << 0 << endl;
			}
			return;
		}
		if (choose == 'b')
		{
			cout << "Values of basic variables:\n";
			for (int i = 0; i < B.size(); i++)
			{
				cout << "x" << basis[i] << "=" << B[i] << endl;
			}
			return;
		}
		cout << endl;
	}

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

	int findPivotRow(int pivotColumn)
	{
		double positiveValues[rows];
		vector<double> result(rows, 0);
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

			bool result = simplex_iteration();
			if (result == true)
			{
				end = true;
			}
		}
		cout << "values of input variables" << endl;
		for (int i = 0; i < B.size(); i++)
		{
			int flag = 0;
			int ind = 0;
			for (int j = 0; j < basis.size(); j++)
			{
				if (basis[j] == i)
				{
					flag = 1;
					ind = j;
					break;
				}
			}
			if (flag == 1)
			{
				cout << "x" << i << "=" << B[ind] << endl;
			}
			else
			{
				cout << "x" << i << "=" << 0 << endl;
			}
		}
		cout << "" << endl;
		cout << "maximum value: " << maximum << endl; // print the maximum values
	}
};

int main()
{
	cout << "Enter number of eqns: ";
	int m;
	cin >> m;
	cout << "enter number of variables: ";
	int n;
	cin >> n;
	vector<pair<int, int>> free_variables;

	cout << "Enter 1 if free variable else 0 for n variables: \n";
	int ctr = 0;
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		cin >> t;
		if (t)
		{
			free_variables.push_back(make_pair(ctr, ctr + 1));
			ctr++;
		}
		ctr++;
	}
	n = ctr;
	cout << "enter the coeffecients" << endl;
	double tmp_arr[m][m + n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m + n; j++)
		{
			if (j < n)
			{
				cin >> tmp_arr[i][j];
				if (find(free_variables.begin(), free_variables.end(), make_pair(j, j + 1)) != free_variables.end())
				{
					tmp_arr[i][j + 1] = -tmp_arr[i][j];
					j++;
				}
			}
			else if (j == n + i)
			{
				tmp_arr[i][j] = 1;
			}
			else
			{
				tmp_arr[i][j] = 0;
			}
		}
	}
	cout << "Enter RHS of the equations\n";
	double tmp_b[m];
	for (int i = 0; i < m; i++)
	{
		cin >> tmp_b[i];
	}
	cout << "Enter the coefficients of objective function" << endl;
	double tmp_c[n];
	for (int i = 0; i < n; i++)
	{
		cin >> tmp_c[i];
		tmp_c[i] = -tmp_c[i];
		if (find(free_variables.begin(), free_variables.end(), make_pair(i, i + 1)) != free_variables.end())
		{
			tmp_c[i + 1] = -tmp_c[i];
			i++;
		}
	}
	int colSizeA = m + n; // should initialise columns size in A
	int rowSizeA = m;	  // should initialise columns row in A[][] vector
	double C[n];		  // should initialise the c array here
	double B[m];		  // should initialise the b array here
	for (int i = 0; i < n; i++)
	{
		C[i] = tmp_c[i];
	}
	for (int i = 0; i < m; i++)
	{
		B[i] = tmp_b[i];
	}
	double a[m][m + n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m + n; j++)
		{
			a[i][j] = tmp_arr[i][j];
		}
	}
	vector<vector<double>> vec2D(rowSizeA, vector<double>(colSizeA, 0));
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
	for (int i = 0; i < n; i++)
	{
		c[i] = C[i];
	}

	Simplex simplex(vec2D, b, c);
	simplex.print('t');
	simplex.print('i');
	simplex.print('c');
	bool res = false;
	while (!res)
	{
		res = simplex.simplex_iteration();
	}
	vector<int> basic_variables_list = simplex.basis;
	vector<double> basic_variables_values = simplex.B;
	map<int, double> var_values;
	for (int i = 0; i < n; i++)
	{
		if (find(basic_variables_list.begin(), basic_variables_list.end(), i) != basic_variables_list.end())
		{
			var_values[i] = basic_variables_values[find(basic_variables_list.begin(), basic_variables_list.end(), i) - basic_variables_list.begin()];
		}
		else
		{
			var_values[i] = 0;
		}
	}
	cout << "Variable values are: " << endl;
	ctr = 0;
	for (auto itr = var_values.begin(); itr != var_values.end(); itr++)
	{
		if (find(free_variables.begin(), free_variables.end(), make_pair(itr->first, itr->first + 1)) != free_variables.end())
		{
			cout << "x" << ctr << "=" << itr->second - next(itr)->second << endl;
			itr++;
			ctr++;
		}
		else
		{
			cout << "x" << ctr << "=" << itr->second << endl;
		}
		ctr++;
	}
	return 0;
}