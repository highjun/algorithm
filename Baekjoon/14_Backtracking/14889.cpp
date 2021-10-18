#include<iostream>
using namespace std;

int backtracking(int* x,int N,bool *team, int idx, int n_t1, int t1, int t2){
    int min_ = INT32_MAX;
    if(idx == N){
        // for(int i = 0;i<N;i++)
        //     cout << team[i] << " ";
        // cout << ":" << abs(t1-t2) << "\n";
        return abs(t1-t2);
    }
    if(n_t1 < N/2){
        team[idx] = true;
        int tmp = t1;
        for(int i = 0; i< idx;i++){
            if(team[i]){
                tmp += x[idx*N+i] + x[i*N+idx];
            }
        }
        min_ = min(min_,backtracking(x,N,team,idx+1,n_t1+1, tmp, t2));
    }
    if(idx-n_t1 < N/2){
        team[idx] = false;
        int tmp = t2;
        for(int i = 0; i< idx;i++){
            if(!team[i]){
                tmp += x[idx*N+i] + x[i*N+idx];
            }
        }
        min_ = min(min_,backtracking(x,N,team,idx+1,n_t1, t1, tmp));
    }
    return min_;
}

int main(){
    int N;
    cin >> N;
    int x[N*N];
    for(int i = 0;i<N*N;i++) cin >> x[i];
    bool team[N];
    cout << backtracking(x,N,team, 0, 0, 0, 0) << "\n";
    return 0;
}