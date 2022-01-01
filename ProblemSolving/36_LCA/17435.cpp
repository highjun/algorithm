#include<iostream>

using namespace std;

// dynamic programming으로 f_{2^k}(x)를 미리 계산해놓는다.
// LCA에서도 이와같이 2진법으로 미리 계산 후 대입만 하는 방식으로 LogN을 만들 수 있다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int M;  cin >> M;
    int dp[M][20];
    for(int i = 0;i<M;i++){
        cin >> dp[i][0];
        dp[i][0]--;
    } 
    for(int i = 1;i < 20; i++){
        for(int j = 0;j < M; j++){
            //f_{2^k}(x) = f_{2^(k-1)}(f_{2^(k-1)}(x))
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
    int Q; cin >> Q;
    for(int i = 0;i<Q;i++){
        int n, x;
        cin >> n >> x;
        x--;
        int k = 0;
        while(n!=0){
            if(n%2==1){
                x = dp[x][k];
            }
            n /= 2;
            k++;
        }
        cout << x+1 <<"\n";
    }
    return 0;
}