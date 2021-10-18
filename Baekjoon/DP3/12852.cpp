#include<iostream>
#include<memory.h>

using namespace std;

int dp(int* save, int n){
    int idx = n-1;
    if(save[idx] == INT32_MAX){
        int tmp = INT32_MAX;
        if(n %2 ==0)    tmp = min(dp(save, n/2)+1, tmp);
        if(n %3 ==0)    tmp = min(dp(save, n/3)+1, tmp);
        tmp = min(dp(save, n-1)+1, tmp);
        save[idx] = tmp;
    }
    return save[idx];
}

//dp로 연산의 최솟값 계산 O(n)
//이후에 그냥 최단경로 검색 cnt<=2log_2 n로 검색에 시간 거의 안 걸림 
int main(){
    int N;
    cin >> N;
    int save[N];
    fill(save, save + N, INT32_MAX);
    save[0] = 0;
    int cnt = dp(save, N);
    cout << cnt <<"\n";
    while(N != 1){
        cnt--;
        cout << N << " ";
        if(N%3 ==0&& dp(save, N/3) == cnt) N /= 3;
        else if(N%2 == 0 && dp(save, N/2) == cnt) N /= 2;
        else N--;
    }
    cout << 1 <<"\n";
    return 0;
}