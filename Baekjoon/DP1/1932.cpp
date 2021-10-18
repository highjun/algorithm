#include<iostream>
using namespace std;

int cache[500];

void calMaxPath(int x[], int n){
    for(int i = n; i>=0 ; i--){
        if(i == n ){
            if(n == 0){
                cache[0] = x[0];
                return;
            }
            cache[i] = cache[i-1] + x[i];
        }else{
            cache[i] = max(cache[i], cache[i-1])+ x[i];
        }
    }
}

int main(){
    int N;
    cin >> N;
    for(int i = 1; i< N+1; i++){
        int x[N];
        for (int j = 0; j< i; j++){
            cin >> x[j];
        }
        calMaxPath(x, i-1);
    }
    int max_ = 0;
    for(int i = 0; i< N; i++){
        max_ = max(max_, cache[i]);
    }
    cout << max_ << endl;
    return 0;
}