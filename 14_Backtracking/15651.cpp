#include<iostream>

using namespace std;

bool nextSeqeunce(int* x,int M,int N){
    int idx = M-1;
    while(idx >= 0){
        if(x[idx] == N){
            x[idx] = 1;
            idx--;
        } 
        else{
            x[idx] += 1;
            break;
        }
    }
    if(idx == -1) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M;
    cin >> N >>M;
    int x[M];
    for(int i = 0;i<M;i++){ x[i] = 1;}
    do
    {
        for(int i = 0;i<M;i++) cout << x[i] << " ";
        cout << "\n";
    } while (nextSeqeunce(x, M, N));
    return 0;
}