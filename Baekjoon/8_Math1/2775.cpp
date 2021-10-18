#include<iostream>
#include<cmath>

using namespace std;

// 점화식으로 모든 k층 n호를 저장한 뒤 시작
// (k,n) = (k-1,n) + (k,n-1)  (k-1,n이 1호부터 k-1호의 합이므로)
int main(){
    int T;
    cin >> T;
    int x[15][15];
    for(int i = 0; i<15 ;i++) x[0][i] = i;
    for(int i = 1; i<15;i++){
        x[i][0] = 0;
        for(int j = 1; j <15; j++){
            x[i][j] = x[i][j-1] + x[i-1][j];
        }
    }
    while(T--){
        int k,n;
        cin >> k >> n;
        cout << x[k][n] << "\n";
    }
    return 0;
}