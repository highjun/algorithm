#include<iostream>

using namespace std;

typedef long long ll;
#define MAX 1000000003

ll save[1000][1000];
//N Ck
ll dp(int N, int k){
    if(save[N][k] == -1){
        save[N][k] = (dp(N-1,k-1) + dp(N-1,k))%MAX;
    }
    return save[N][k];
}

//색 1개에 대한 사용여부로 경우를 나눔
//f(N,K) = N-1개중 K개를 이웃하지 않게 + N-3개 중 K-1개를 이웃하지 않게
// = (N-k)Ck + (N-k-1)C(k-1)
int main(){
    int N;
    cin >> N;
    int K;
    cin >> K;
    fill(&save[0][0], &save[0][0] + 1000*1000, -1);
    for(int i = 0; i <1000;i++){
        save[i][0] = 1;
        save[i][i] = 1;
    }
    ll cnt = 0;
    if(N-K>= K) cnt+= dp(N-K,K);
    if(N-K-1>= K-1) cnt+= dp(N-K-1,K-1);
    // for(int i = 0;i<N;i++){
    //     for(int j = 0; j<=i;j++){
    //         cout << save[i][j] <<" ";
    //     }
    //     cout << "\n";
    // }
    cout << cnt%MAX << "\n";
    return 0;
}