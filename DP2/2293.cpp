#include<iostream>
#include<memory.h>

using namespace std;

int new_[10001];
int old[10001];


int checkValue(int coin_value, int value){
    if(value == 0){
        new_[value]= 1;
        return 1;
    }
    int check = 0, tmp = 0;
    while(tmp<= value){
        check += old[value-tmp];
        tmp += coin_value;
    }
    new_[value] = check;
    return check;
}

int main(){
    int N,K;
    cin >> N >> K;
    //초기 조건
    memset(old, 0, sizeof(int)* 10001);
    old[0] =1;

    for(int i=0 ; i< N;i++){
        int coin_val;
        cin >> coin_val;
        //bottom-up
        for(int j = 0; j<=K; j++){
           checkValue(coin_val, j);
        }
        // cout << endl;
        memcpy(old, new_, sizeof(int)* 10001);
    }
    cout << old[K] << endl; 

    return 0;
}