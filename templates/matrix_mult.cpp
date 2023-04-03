template<class T>
vector<vector<T>> matrix_mult(vector<vector<T>> A, vector<vector<T>>B){
    int a = A.size(), b = A[0].size(), c = B[0].size();
    vector<vector<T>>C(a, vector<T>(c, 0));
    for(int i=0;i<a;i++){
        for(int j=0;j<c;j++){
            for(int k=0;k<b;k++){
                C[i][k] += A[i][j]*B[j][k];
            }
        }
    }
    return C;
}
