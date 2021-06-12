#include<iostream>
#include<memory.h>

using namespace std;


void mulMatrix(int * x, int * y, int*z, int N, int M, int K){
    fill(z, z+N*K,0);
    for(int i = 0; i<N;i++){
        for(int j = 0; j<K;j++){
            int idx = i*K+j;
            for(int k = 0; k<M;k++){
                z[idx] += x[i*M+k] * y[k*K+ j];
            }
            z[idx] %= 1000;
        }
    }
}
void powerMatrix(int *x, int * y, int N, long long M){
    int z[N*N];
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
        memcpy(y,z,sizeof(int) * N*N);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    long long B;
    cin >> N >> B;
    int x[N*N];
    for(int i = 0;i<N*N;i++){
        cin >> x[i];
    }
    int y[N*N];
    powerMatrix(x,y, N,B);
    for(int i = 0;i<N*N;i++){
        cout << y[i] <<" ";
        if((i+1)%N==0) cout <<"\n";
    }
    return 0;
}