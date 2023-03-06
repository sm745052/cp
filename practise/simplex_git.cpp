#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Simplex
{

private:
    int rows, cols;
    // stores coefficients of all the variables
    vector<vector<double>> A;
    // stores constants of constraints
    vector<double> B;
    // stores the coefficients of the objective function
    vector<double> C;
    double maximum;
    bool isUnbounded;
    vector<int> basis;

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
        for(int i =0;i<b.size();i++)
        {
            basis[i] = i;
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
            print();
        }
        else
        {
            print();
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
    void print()
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
        cout<<"Values of B:\n";
        for (int i = 0; i < B.size(); i++)
        {
            cout << B[i] << " ";
        }
        cout << "" << endl;
        cout<<"Values of C:\n";
        for (int i = 0; i < C.size(); i++)
        {
            cout << C[i] << " ";
        }
        cout << "values of input variables" << endl;
        cout << (A.size() == rows)<<endl;
        for(int i=0;i<basis.size();i++)
        {
            cout<<"variable"<<basis[i]<<"="<<B[i]<<endl;
        }
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

        cout << "initial array(Not optimal)" << endl;
        print();

        while (!end)
        {

            bool result = simplexAlgorithmCalculataion();
            if (result == true)
            {
                end = true;
            }
        }
        cout << "values of input variables" << endl;
        cout << (A.size() == rows)<<endl;
        for(int i=0;i<basis.size();i++)
        {
            cout<<"variable"<<basis[i]<<"="<<B[i]<<endl;
        }
        cout << "" << endl;
        cout << "maximum value: " << maximum << endl; // print the maximum values
    }
};



int main()
{

    int colSizeA = 5; // should initialise columns size in A
    int rowSizeA = 3; // should initialise columns row in A[][] vector

    double C[] = {-2, -5}; // should initialise the c array here
    double B[] = {24, 21, 9};       // should initialise the b array here

    double a[3][5] = {// should intialis the A[][] array here
                     {1, 4, 1, 0, 0},
                     {3, 1, 0, 1, 0},
                     {1, 1, 0, 0, 1}};
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
    for (int i = 0; i < colSizeA; i++)
    {
        c[i] = C[i];
    }

    // hear the make the class parameters with A[m][n] vector b[] vector and c[] vector
    Simplex simplex(vec2D, b, c);
    simplex.CalculateSimplex();

    return 0;
}
