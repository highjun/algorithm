#include<iostream>

using namespace std;

int choose(int x[1001][1001], int n, int k){
    if(x[n][k] == -1){
        x[n][k] = (choose(x,n-1,k-1) + choose(x,n-1,k))%10007;
    }
    return x[n][k];
}

int main(){
    int N,K;
    int x[1001][1001];
    fill(&(x[0][0]), &(x[0][0])+1001*1001,-1);
    for(int i =0; i<1001;i++){
        x[i][i] = x[i][0] = 1; 
    }
    cin >> N >> K;
    cout << choose(x,N,K) << "\n";
    return 0;
}