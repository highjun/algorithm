#include<iostream>

using namespace std;


struct Matrix2x2{
    long long a00;
    long long a01;
    long long a10;
    long long a11;
};

Matrix2x2 a{1,1,1,0};
int divider = 1000000007;

Matrix2x2 mulMatrix(Matrix2x2 A, Matrix2x2 B){
    Matrix2x2 result;
    result.a00 = A.a00 *B.a00 + A.a01 * B.a10;
    result.a01 = A.a00 *B.a01 + A.a01 * B.a11;
    result.a10 = A.a10 *B.a00 + A.a11 * B.a10;
    result.a11 = A.a10 *B.a01 + A.a11 * B.a11;
    return result;
}
//return 
// | F_N+1, F_N  | - | 1 1 |^N
// | F_N , F_N-1 | - | 1 0 | 
Matrix2x2 calFibo(long long N){
    if(N==1){
        return a;
    }
    if(N%2 ==0){
        Matrix2x2 result = calFibo(N/2);
        Matrix2x2 result_ = mulMatrix(result, result);
        result_.a00 = result_.a00%divider;
        result_.a01 = result_.a01%divider;
        result_.a10 = result_.a10%divider;
        result_.a11 = result_.a11%divider;
        return result_;
    }else{
        Matrix2x2 result_ = mulMatrix(calFibo(N-1), a);
        result_.a00 = result_.a00%divider;
        result_.a01 = result_.a01%divider;
        result_.a10 = result_.a10%divider;
        result_.a11 = result_.a11%divider;
        return result_;
    }
}

// 피보나치 분할 정복
// | F_n+1, F_n  | - | 1 1 |^n
// | F_n , F_n-1 | - | 1 0 | 
int main(){
    long long N;
    cin >> N;
    if(N<=1){
        cout << N <<endl;
    }else{
        Matrix2x2 m= calFibo(N-1);
        cout << m.a00 <<endl;
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0; j<N; j++){
    //         cout << a[i][j];
    //     }
    //     cout << "\n";
    // }
    return 0;
}