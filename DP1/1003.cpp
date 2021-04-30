#include<iostream>
using namespace std;

long long cache[41][2];
void cntFibonacci(int n){
    if(n == 0){
        if(cache[0][0] == -1){
            cache[0][0] = 1;
            cache[0][1] = 0;
        }
    }else if(n == 1){
        if(cache[1][0] == -1){
            cache[1][0] = 0;
            cache[1][1] = 1;
        }
    }else{
        if(cache[n][0] == -1){
            cntFibonacci(n-1);
            cntFibonacci(n-2);
            cache[n][0] = cache[n-1][0]+ cache[n-2][0];
            cache[n][1] = cache[n-1][1]+ cache[n-2][1];
        }
    }
}
int main(){
    int N;
    cin >> N;
    for(int i= 0;i<41; i++){
        cache[i][0] = -1;
        cache[i][1] = -1;
    }
    for(int i =0 ; i<N; i++){
        int n;
        cin >> n;
        cntFibonacci(n);
        cout << cache[n][0] << " " << cache[n][1] << endl;
    }
}