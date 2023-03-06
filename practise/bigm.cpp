#include <bits/stdc++.h>
using namespace std;

class Simplex
{
public:
    int rows, cols;
    vector<vector<double>> A;
    vector<double> b;
    vector<string> var;
    vector<string> varB;
    map<string, double> coefficients;
    vector<double> Z, C, Z_C;

public:
    Simplex(vector<vector<double>> tmp_matrix, vector<double> tmp_b, vector<string> tmp_var, vector<string> tmp_varB, map<string, double> tmp_coefficients)
    {
        rows = tmp_matrix.size();
        cols = tmp_matrix[0].size();
        A = tmp_matrix;
        b = tmp_b;
        var = tmp_var;
        varB = tmp_varB;
        coefficients = tmp_coefficients;
        Z_C.resize(cols);
        Z.resize(cols);
        C.resize(cols);
        calculate_Z_C();
    }
    void printTableau()
    {
        cout << "Tableau" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << " | " << b[i] << endl;
        }
        cout << "Z_C: ";
        for (int i = 0; i < cols; i++)
        {
            cout << Z_C[i] << " ";
        }
        cout << endl;
        cout << "Z: ";
        for (int i = 0; i < cols; i++)
        {
            cout << Z[i] << " ";
        }
        cout << endl;
        cout << "C: ";
        for (int i = 0; i < cols; i++)
        {
            cout << C[i] << " ";
        }
        cout << endl;
        cout << "all Variables: ";
        for (int i = 0; i < var.size(); i++)
        {
            cout << var[i] << " ";
        }
        cout << endl;
        cout << "Basic variables: ";
        for (int i = 0; i < varB.size(); i++)
        {
            cout << varB[i] << "=" << b[i] << " ";
        }
        cout << endl;
    }
    void calculate_Z()
    {
        for (int i = 0; i < cols; i++)
        {
            Z[i] = 0;
            for (int j = 0; j < rows; j++)
            {
                Z[i] += A[j][i] * coefficients[varB[j]];
            }
        }
    }
    void calculate_C()
    {
        for (int i = 0; i < cols; i++)
        {
            C[i] = coefficients[var[i]];
        }
    }
    void calculate_Z_C()
    {
        calculate_C();
        calculate_Z();
        for (int i = 0; i < cols; i++)
        {
            Z_C[i] = Z[i] - C[i];
        }
    }

    double objective_value()
    {
        double obj = 0;
        for (int i = 0; i < rows; i++)
        {
            obj += coefficients[varB[i]] * b[i];
        }
        return obj;
    }

    bool simplexIteration()
    {
        if (checkOptimality() == true)
        {
            return true;
        }
        int pivotColumn = findPivotColumn();
        int pivotRow = findPivotRow(pivotColumn);
        printf("pivoting %d %d element whose value is %f\n", pivotRow, pivotColumn, A[pivotRow][pivotColumn]);
        doPivotting(pivotRow, pivotColumn);
        cout << "Objective value = " << objective_value() << endl;
        return false;
    }
    int findPivotRow(int PivotColumn)
    {
        double min = DBL_MAX;
        int pivotRow = -1;
        for (int i = 0; i < rows; i++)
        {
            if (A[i][PivotColumn] > 0)
            {
                if (min > b[i] / A[i][PivotColumn])
                {
                    min = b[i] / A[i][PivotColumn];
                    pivotRow = i;
                }
            }
        }
        if (pivotRow == -1)
        {
            cout << "Unbounded" << endl;
            exit(0);
        }
        return pivotRow;
    }

    int findPivotColumn()
    {
        int pivotColumn = -1;
        double min = 0;
        for (int i = 0; i < cols; i++)
        {
            if (Z_C[i] < min)
            {
                min = Z_C[i];
                pivotColumn = i;
            }
        }
        return pivotColumn;
    }

    void doPivotting(int pivotRow, int pivotColumn)
    {
        double pivotElement = A[pivotRow][pivotColumn];
        for (int i = 0; i < cols; i++)
        {
            A[pivotRow][i] /= pivotElement;
        }
        b[pivotRow] /= pivotElement;
        for (int i = 0; i < rows; i++)
        {
            if (i != pivotRow)
            {
                double multiplier = A[i][pivotColumn];
                for (int j = 0; j < cols; j++)
                {
                    A[i][j] -= multiplier * A[pivotRow][j];
                }
                b[i] -= multiplier * b[pivotRow];
            }
        }
        varB[pivotRow] = var[pivotColumn];
        calculate_Z_C();
    }

    bool checkOptimality()
    {
        for (int i = 0; i < cols; i++)
        {
            if (Z_C[i] < 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    cout << "BIG M METHOD" << endl;
    cout << "-----------------------------------------------------------\n";
    cout << "Enter number of eqns: ";
    int m;
    cin >> m;
    cout << "enter number of variables: ";
    int n;
    cin >> n;
    double M = 1000000;
    vector<string> ops;
    vector<vector<double>> tmp_matrix(m, vector<double>(n, 0));
    vector<string> tmp_var;
    vector<string> tmp_varB;
    vector<double> tmp_b(m);
    map<string, double> tmp_coefficients;
    for (int i = 0; i < n; i++)
    {
        tmp_var.push_back("x" + to_string(i + 1));
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter the coefficient of x" << j + 1 << " in eqn " << i + 1 << ": ";
            cin >> tmp_matrix[i][j];
        }
        cout << "Enter relation operator: ";
        string op;
        cin >> op;
        ops.push_back(op);
        cout << "enter the constant: ";
        cin >> tmp_b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the coefficient of x" << i + 1 << " in objective function: ";
        double coeff;
        cin >> coeff;
        tmp_coefficients["x" + to_string(i + 1)] = coeff;
    }
    cout << "enter 1 if maximization problem, 0 if minimization problem: ";
    int max;
    cin >> max;
    if (max == 0)
    {
        for (int i = 0; i < n; i++)
        {
            tmp_coefficients["x" + to_string(i + 1)] *= -1;
        }
    }
    int slack_ctr = 0;
    int surplus_ctr = 0;
    int artificial_ctr = 0;
    for (int i = 0; i < ops.size(); i++)
    {

        string op = ops[i];
        if (op == "<=")
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                {
                    tmp_matrix[j].push_back(1);
                }
                else
                {
                    tmp_matrix[j].push_back(0);
                }
            }
            tmp_var.push_back("s" + to_string(slack_ctr + 1));
            tmp_varB.push_back("s" + to_string(slack_ctr + 1));
            slack_ctr++;
            tmp_coefficients["s" + to_string(slack_ctr)] = 0;
        }
        else if (op == ">=")
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                {
                    tmp_matrix[j].push_back(-1);
                    tmp_matrix[j].push_back(1);
                }
                else
                {
                    tmp_matrix[j].push_back(0);
                    tmp_matrix[j].push_back(0);
                }
            }
            tmp_var.push_back("su" + to_string(surplus_ctr + 1));
            surplus_ctr++;
            tmp_var.push_back("a" + to_string(artificial_ctr + 1));
            tmp_varB.push_back("a" + to_string(artificial_ctr + 1));
            artificial_ctr++;
            tmp_coefficients["su" + to_string(surplus_ctr)] = 0;
            tmp_coefficients["a" + to_string(artificial_ctr)] = -M;
        }
        else if (op == "=")
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                {
                    tmp_matrix[j].push_back(1);
                }
                else
                {
                    tmp_matrix[j].push_back(0);
                }
            }
            tmp_var.push_back("a" + to_string(artificial_ctr + 1));
            tmp_varB.push_back("a" + to_string(artificial_ctr + 1));
            artificial_ctr++;
            tmp_coefficients["a" + to_string(artificial_ctr)] = -M;
        }
    }
    cout << "The augmented matrix is: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < tmp_matrix[i].size(); j++)
        {
            cout << tmp_matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The objective function is: " << endl;
    for (int i = 0; i < tmp_var.size(); i++)
    {
        cout << tmp_coefficients[tmp_var[i]] << " " << tmp_var[i] << " ";
    }
    cout << endl;
    cout << "The basic variables are: " << endl;
    for (int i = 0; i < tmp_varB.size(); i++)
    {
        cout << tmp_varB[i] << " ";
    }
    cout << endl;
    cout << "The non-basic variables are: " << endl;
    for (int i = 0; i < tmp_var.size(); i++)
    {
        cout << tmp_var[i] << " ";
    }
    cout << endl;
    cout << "The constants are: " << endl;
    for (int i = 0; i < tmp_b.size(); i++)
    {
        cout << tmp_b[i] << " ";
    }
    cout << endl;
    Simplex simplex(tmp_matrix, tmp_b, tmp_var, tmp_varB, tmp_coefficients);
    simplex.printTableau();
    int ctr = 0;
    while (true)
    {
        cout << "--------------------------Iteration " << ++ctr << "------------------------------------" << endl;
        bool res = simplex.simplexIteration();
        if (res == true)
        {
            printf("DONE\n");
            break;
        }
        simplex.printTableau();
        ctr++;
    }
    cout << "----------------------------------------------------------------------------------\n";
    for (int i = 0; i < simplex.varB.size(); i++)
    {
        if (simplex.varB[i][0] == 'a' && simplex.b[i] != 0)
        {
            cout << "The problem is infeasible" << endl;
            return 0;
        }
    }
    cout << "optimal Value: " << simplex.objective_value() * ((max) ? 1 : -1) << endl;
    cout << "optimal solution: " << endl;
    for (int i = 0; i < n; i++)
    {
        int basic_flag = 0;
        int j = 0;
        for (; j < m; j++)
        {
            if (simplex.varB[j] == "x" + to_string(i + 1))
            {
                basic_flag = 1;
                break;
            }
        }
        cout << "x" << i + 1 << " = " << ((basic_flag) ? simplex.b[j] : 0) << endl;
    }
    return 0;
}
