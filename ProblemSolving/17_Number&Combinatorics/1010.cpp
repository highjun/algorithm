#include<iostream>

using namespace std;


int choose(int x[31][31], int n, int k){
    if(x[n][k] == -1){
        x[n][k] = (choose(x,n-1,k-1) + choose(x,n-1,k));
    }
    return x[n][k];
}


int main(){
    int T;
    cin >> T;
    int x[31][31];
    fill(&(x[0][0]), &(x[0][0])+31*31,-1);
    for(int i =0; i<31;i++){
        x[i][i] = x[i][0] = 1; 
    }
    while(T--){
        int n,k;
        cin >> k >> n;
        cout << choose(x, n, k) << "\n";
    }
    return 0;
}