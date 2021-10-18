#include<iostream>

using namespace std;

int main(){
    int x[10000];
    fill(x, x+10000, 0);
    for(int i = 0;i< 10000;i++){
        int num = i+1;
        int tmp = num;
        while(num!=0){
            tmp += num%10;
            num /= 10;
        }
        if(tmp <= 10000){
            x[tmp-1]++;
        }
    }
    for(int i = 0;i<10000;i++){
        if(x[i] == 0){
            cout << i+1 <<"\n";
        }
    }
    return 0;
}