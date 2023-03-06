#include<bits/stdc++.h>
using namespace std;




vector<vector<double> > matmul(vector<vector<double> > A, vector<vector<double> > B){
	if(A[0].size()!=B.size()){
		cout<<"MATRIX MULTIPLICATION ERROR _ COMPATIBLITY"<<endl;
		exit(0);
	}
	vector<vector<double> > C = vector<vector<double> >(A.size(), vector<double>(B[0].size(), 0));
	int a = A.size();
	int b = A[0].size();
	int c = B[0].size();
	for(int i=0;i<a;i++){
		for(int j=0;j<c;j++){
			for(int k=0;k<b;k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}



vector<vector<double> > vector2matrix(vector<double> A){
	vector<vector<double> > B;
	for(int i=0;i<A.size();i++){
		B.push_back(vector<double>(1, A[i]));
	}
	return B;
}



vector<vector<double> > transpose(vector<vector<double> > A){
	vector<vector<double> > B = A;
	int r = A.size();
	int c = A[0].size();
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			B[i][j] = A[j][i];
		}
	}
	return B;
}







class revised_simplex{
private:
	vector<vector<double> > A, Y;
	map<string, double> C;
	vector<double> Cb, b;
	vector<string> var;
	vector<string> varB;
	int m, n, rows, cols;
	vector<double>Z_C;
	vector<vector<vector<double> > > Bs, Binvs, Es;
	int iter;

public:
	revised_simplex(vector<vector<double> > A, map<string, double> C, vector<double> b, vector<string> var, vector<string> varB){
		m = A.size();
		n = A[0].size()-m;
		rows = m;
		cols = m+n;
		this->A = A;
		this->C = C;
		this->b = b;
		this->varB = varB;
		this->var = var;
		iter = 0;


		vector<vector<double> > B(m, vector<double>(m, 0));
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				if(i==j){
					B[i][i]=1;
				}
			}
		}
		Bs.push_back(B);
		Binvs.push_back(B);
		Cb.resize(m, 0);
		Z_C.resize(cols, 0);
		Es.resize(100, B);
	}


	void compute_Cb(){
		for(int i=0;i<rows;i++){
			Cb[i] = C[varB[i]];
		}
	}



	void compute_Y(){
		Y = matmul(transpose(vector2matrix(Cb)), Binvs[iter-1]);
	}

	vector<double> P(int j){
		vector<double>p;
		for(int j=0;j<rows;j++){
			p.push_back(A[rows][j]);
		}
		return p;
	}

	void compute_Z_C(){
		compute_Y();
		for(int i=0;i<cols;i++){
			Z_C[i] = matmul(Y, vector2matrix(P(i)))[0][0] - C[var[i]];
		}
	}

	bool check_optimatlity(){
		compute_Z_C();
		for(int i=0;i<cols;i++){
			if(Z_C[i]<0)return 0;
		}
		return 1;
	}




	int find_pivcol(){
		int k = -1;
		for(int i=0;i<n;i++){
			if(Z_C[k]<0){
				if(k==-1)k=i;
				else{
					if(Z_C[k]>Z_C[i]){
						k=i;
					}
				}
			}
		}
		if(k==-1){
			cout<<"PIVOT COLUMN ERROR"<<endl;
		}
		return k;
	}




	int find_pivrow(int col){
		vector<vector<double> > Xb = matmul(Binvs[iter-1], vector2matrix(b));
		vector<vector<double> > alpha = matmul(Binvs[iter-1], vector2matrix(P(col)));
		int row = -1;
		for(int i=0;i<rows;i++){
			if(alpha[i][0]>0){
				if(row==-1){
					row = i;
				}
				else{
					if(Xb[i][0]/alpha[i][0]<Xb[row][0]/alpha[row][0]){
						row = i;
					}
				}
			}
		}
		if(row = -1){
			cout<<"UNBOUNDED SOLUTION"<<endl;
			exit(0);
		}
	}




	bool iterate(){
		iter++;
		if(check_optimatlity()){
			return 1;
		}
		int pivcol = find_pivcol();
		int pivrow = find_pivrow(pivcol);
		varB[pivrow] = var[pivcol];
		Bs[iter] = Bs[iter-1];
		vector<vector<double> > e = matmul(Binvs[iter-1], vector2matrix(P(pivcol)));
		for(int i=0;i<rows;i++){
			Es[iter][i][iter-1] = e[i][0]/e[i][iter-1];
			Bs[iter][i][iter-1] = A[i][pivcol];
		}
		Binvs[iter] = matmul(Es[iter], Binvs[iter-1]);
	}
}
;







int main(){
#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
   
#endif
	cout<<fixed<<setprecision(10);
    cout<<"REVISED SIMPLEX METHOD"<<endl;
    cout<<"-----------------------------------------------------------\n";
    cout << "Enter number of eqns: ";
    int m;
    cin >> m;
    cout << "enter number of variables: ";
    int n;
    cin >> n;
    vector<string> ops;
    vector<vector<double>> tmp_matrix(m, vector<double>(n, 0));
    vector<string> tmp_var;
    vector<string> tmp_varB;
    vector<double> tmp_b(m);
    map<string, double> tmp_coefficients;
    int slack_ctr = 0;
    for(int i=0;i<m;i++)
    {
        cout<<"Enter the equation "<<i+1<<endl;
        for(int j=0;j<n;j++)
        {
            cin>>tmp_matrix[i][j];
        }
        string op;
        cin>>op;
        ops.push_back(op);
        cin>>tmp_b[i];
    }
    cout<<"Enter the coefficients of the variables in the objective function"<<endl;
    for(int i=0;i<n;i++)
    {
        string var;
        var = "x" + to_string(i + 1);
        tmp_var.push_back(var);
        cin>>tmp_coefficients[var];
    }
    cout<<"enter 1 if maximization problem, 0 if minimization problem: ";
    int max;
    cin>>max;
    if(max==0)
    {
        for(int i=0;i<n;i++)
        {
            tmp_coefficients["x"+to_string(i+1)]*=-1;
        }
    }


    for(int i=0;i<ops.size();i++)
    {
        string op = ops[i];
        if(op=="<=")
        {
            for(int j=0;j<m;j++)
            {
                if(i==j)
                {
                    tmp_matrix[j].push_back(1);
                }
                else
                {
                    tmp_matrix[j].push_back(0);
                }
            }
            tmp_var.push_back("s"+to_string(slack_ctr+1));
            tmp_varB.push_back("s"+to_string(slack_ctr+1));
            tmp_coefficients["s"+to_string(slack_ctr+1)]=0;
            slack_ctr++;
        }
        else if(op==">=")
        {
            for(int k=0;k<n;k++)
            {
                tmp_matrix[i][k]*=-1;
            }
            tmp_b[i]*=-1;
            for(int j=0;j<m;j++)
            {
                if(i==j)
                {
                    tmp_matrix[j].push_back(1);
                }
                else
                {
                    tmp_matrix[j].push_back(0);
                }
            }
            tmp_var.push_back("s"+to_string(slack_ctr+1));
            tmp_varB.push_back("s"+to_string(slack_ctr+1));
            tmp_coefficients["s"+to_string(slack_ctr+1)]=0;
            slack_ctr++;
        }
    }
    revised_simplex ob(tmp_matrix, tmp_coefficients, tmp_b, tmp_var, tmp_varB);
	cout<<"HELLO"<<endl;
	return 0;
}