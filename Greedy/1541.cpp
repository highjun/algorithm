#include<iostream>
#include<memory.h>

using namespace std;

int main(){
    string x;
    cin >> x;
    int arr[50];
    memset(arr, 0, sizeof(int) * 50);
    int tmp = 0;
    int sign = 1;
    for(int i = 0; i<x.length(); i++){
        if(x[i] != '+' && x[i] !='-'){
            // cout << x[i]-'0' << " ";
            arr[tmp] = arr[tmp]*10 + sign*(x[i]- '0');
        }else{
            sign = (x[i] == '+' && sign == 1)? 1: -1;
            tmp += 1;
        }
    }
    
    int cnt = 0;

    for(int i = 0 ; i< tmp+1; i++){
        cnt += arr[i];
        // cout << arr[i] <<" "; 
    }
    cout << cnt << endl;
    return 0;
}