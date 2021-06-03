#include<iostream>

using namespace std;

bool isValid(int *q, int idx){
    for(int i = 0;i<idx;i++){
        if(q[i]+i == idx + q[idx] || q[idx] == q[i] || q[idx]-idx == q[i]-i){
            return false;
        }
    }
    return true;
}

int backtracking(int *q, int N, int idx){
    int cnt = 0;
    if(idx == N){
        return 1;
    }
    for(int i = 0; i<N;i++){
        q[idx] = i;
        if(isValid(q, idx)){
            cnt += backtracking(q,N,idx+1);
        }
    }
    return cnt;
}
//DFS를 이용한 BackTracking
int main(){
    int N;
    cin >> N;
    int q[N], *cnt;
    cout << backtracking(q, N, 0) << "\n";
    return 0;
}