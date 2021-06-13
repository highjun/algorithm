#include<iostream>
#include<memory.h>

using namespace std;

int DIV = 1000000007;

void mulMatrix(long long * x, long long * y, long long * z, int N, int M, int K){
    fill(z, z+N*K,0);
    for(int i = 0; i<N;i++){
        for(int j = 0; j<K;j++){
            int idx = i*K+j;
            for(int k = 0; k<M;k++){
                z[idx] += x[i*M+k] * y[k*K+ j];
            }
            z[idx] %= DIV;
        }
    }
}
void powerMatrix(long long *x, long long * y, int N, long long M){
    long long z[N*N];
    if(M == 0){
        fill(y, y+N*N,0);
        for(int i = 0; i < N ; i++){
            y[i*N+i] = 1;
        }
        return;
    }
    powerMatrix(x, z, N, M/2);
    mulMatrix(z, z, y, N, N,N);
    if(M%2 == 1){
        mulMatrix(x, y, z, N, N, N);
        memcpy(y,z,sizeof(long long) * N*N);
    }
}


//A= | 1 1 | 
//   | 1 0 |
// | F_n     F_(n-1)| = | F_(n-1) F_(n-2) | | 1 1 |
// | F_(n-1) F_(n-2)|   | F_(n-2) F_(n-3) | | 1 0 |
// 의 행렬의 곱임을 이용한다.
// 즉, A^(n-1)이 된다.
// 행렬의 거듭제곱은 기존의 코드를 이용한다.
int main(){
    long long N;
    cin >> N;
    if(N == 0){
        cout << 0 <<"\n";
        return 0;
    }
    N--;
    long long x[4] = { 1, 1, 1, 0};
    long long y[4];
    powerMatrix(x, y, 2, N);
    cout << y[0] << "\n";
    return 0;
}