#include<iostream>

using namespace std;

void mulMatrix(int * x, int * y, int*z, int N, int M, int K){
    fill(z, z+N*K,0);
    for(int i = 0; i<N;i++){
        for(int j = 0; j<K;j++){
            int idx = i*K+j;
            for(int k = 0; k<M;k++){
                z[idx] += x[i*M+k] * y[k*K+ j];
            }
        }
    }
}
//행렬의 곱셈. 1차원 배열을 가지고 구현!
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M;
    cin >> N >> M;
    int x[N*M];
    for(int i = 0; i <N*M;i++){
        cin >> x[i];
    }
    int K;
    cin >> M >> K;
    int y[M*K];
    for(int i = 0; i <M*K;i++){
        cin >> y[i];
    }
    int z[N*K];
    mulMatrix(x,y,z,N,M,K);
    for(int i = 0; i < N*K; i++){
        cout << z[i] << " ";
        if((i+1)%K == 0) cout << "\n";
    }
    return 0;
}