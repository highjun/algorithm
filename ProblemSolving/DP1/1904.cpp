#include<iostream>
using namespace std;

int cache[1000000];
void cntFibonacci(int n){
    if(n == 1){
        if(cache[0] == -1){
            cache[0] = 1;
        }
    }else if(n== 2){
        if(cache[1] == -1){
            cache[1] = 2;
        }
    }else{
        if(cache[n-1] == -1){
            cntFibonacci(n-1);
            cntFibonacci(n-2);
            cache[n-1] = (cache[n-2]+ cache[n-3])%15746;
        }
    }
}
int main(){
    for(int i = 0 ; i<1000000; i++){
        cache[i] = -1;
    }
    int N;
    cin >> N;
    cntFibonacci(N);
    cout << cache[N-1] << endl;
}