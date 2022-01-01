#include<iostream>
#include<memory.h>

using namespace std;


int main(){
    int N,M;
    cin >> N >> M;
    int cost[N], memory[N];
    for(int i=0; i<N;i++){
        cin >> memory[i];
    }
    for(int i=0; i<N;i++){
        cin >> cost[i];
    }
    int new_[M+1];
    int old[M+1];
    //c(n,m) = min(c(n-1,m), c(n-1, m- m[n])+c[n])으로 푼다.
    memset(old, -1, sizeof(int)*(M+1));
    old[0] = 0;
    for(int i = 0; i< N; i++){
        memset(new_, -1, sizeof(int)*(M+1));
        for(int j =0 ;j<M+1; j++){
            if(j==0) new_[j] = 0;
            else{
                int check = -1;
                if(j >= memory[i] && old[j-memory[i]] != -1){
                    check = old[j-memory[i]] + cost[i];
                }
                if(old[j] != -1){
                    if(check == -1) check = old[j];
                    else check = min(check, old[j]);
                }
                if(memory[i] >= j){
                    if(check == -1) check = cost[i];
                    else check = min(check, cost[i]);
                }
                new_[j] = check;
            }
        }
        memcpy(old, new_, sizeof(int)*(M+1));
    }
    cout << old[M] <<endl;

    return 0;
}