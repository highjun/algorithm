#include<iostream>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    int x[N];
    for(int i=0; i<N; i++){
        cin >> x[i];
    }
    int cnt = 0;
    for(int i=N-1; i>=0; i--){
        int div = K/x[i];
        K = K- div *x[i];
        cnt += div;
    }
    cout << cnt << endl;
    return 0;
}