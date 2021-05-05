#include<iostream>
#include<algorithm>

using namespace std;

int calMax(int x[],int N, int K, int len){
    int point = x[0];
    int cnt = 1;
    for(int j = 1; j< N; j++){
        if(x[j] - point >= len){
            cnt += 1;
            point = x[j];
            if(cnt >= K){
                return 1;
            }
        }
    }
    return 0;
}


int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N>> K;
    int x[N];
    for(int i = 0; i<N;i++){
        cin >> x[i];
    }
    sort(x, x+N);
    int idx = 0;

    for(int i = 30;i>=0 ; i--){
        // cout << cnt <<" " << i << " " <<  idx << "\n";
        if(calMax(x, N, K, idx+(1<<i)) == 1){
            idx += (1<< i);
        }
    }
    cout << idx << endl;
    return 0;
}