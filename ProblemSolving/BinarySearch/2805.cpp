#include<iostream>
#include<algorithm>

using namespace std;

long long calMax(int x[],int N, int len){
    long long cnt = 0;
    for(int i = 0; i< N; i++){
        cnt += x[i] > len? x[i]-len: 0;
    }
    return cnt;
}


int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N>> M;
    int x[N];
    for(int i = 0; i<N;i++){
        cin >> x[i];
    }
    int idx = 0;

    for(int i = 30;i>=0 ; i--){
        // cout << cnt <<" " << i << " " <<  idx << "\n";
        if(calMax(x, N, idx+(1<<i)) >= M){
            idx += (1<< i);
        }
    }
    cout << idx << endl;
    return 0;
}