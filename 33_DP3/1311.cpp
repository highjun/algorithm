#include<iostream>

using namespace std;

//bit는 DP를 위한 저장소
//arr는 각 비용
//mask는 구하고자 하는 마스크, k는 명수
int dp(int * bit, int* arr, int mask, int N, int k){
    // cout << mask /<< ", " << k << "\n";
    if(bit[mask] == -1){
        int min_ = INT32_MAX;
        for(int i = 0;i<N;i++){
            int tmp = 1 << i;
            if(tmp == (tmp & mask)){
                min_ = min(min_, dp(bit,arr,mask & (~tmp), N,k-1)+ arr[(k-1)*N+i]);
            }
        }
        bit[mask] = min_;
    }
    return bit[mask];
}

//이제까지 배정된 일을 비트마스크로 한다. 일은 사람에게 차례대로 분배
int main(){
    int N;
    cin >> N;
    int arr[N*N];
    for(int i = 0;i<N*N;i++){
        cin >> arr[i];
    }
    int bit[1<<N];//k명에게 할당한 일의 상태
    fill(bit, bit + (1<<N), -1);
    bit[0] = 0;
    cout << dp(bit,arr, (1<<N) -1, N, N) <<"\n";
    // for(int i = 0;i<(1<<N);i++){
    //     cout << bit[i] << " ";
    // }
    // cout << "\n";
    return 0;
}