#include<iostream>

using namespace std;

int choose(int x[11][11], int n, int k){
    if(x[n][k] == -1){
        x[n][k] = choose(x,n-1,k-1) + choose(x,n-1,k);
    }
    return x[n][k];
}

int main(){
    int N,K;
    int x[11][11];
    fill(&(x[0][0]), &(x[0][0])+11*11,-1);
    for(int i =0; i<11;i++){
        x[i][i] = x[i][0] = 1; 
    }
    cin >> N >> K;
    cout << choose(x,N,K) << "\n";
    return 0;
}