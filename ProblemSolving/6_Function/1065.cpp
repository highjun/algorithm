#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int cnt  = 0;
    for(int i = 0; i< N; i++){
        int prev= -1, d = 10;
        int num = i+1;
        while(num!=0){
            if(prev == -1){
                prev = num%10;
            }else if(d== 10){
                d = num%10 - prev;
                prev = num%10;
            }else{
                if(d!= num%10 -prev){
                    break;
                }
                prev = num%10;
            }
            num/= 10;
        }
        if(d== 10 || prev == -1 || num== 0){
            // cout << i+1 << "\n";
            cnt++;
        } 
    }
    cout << cnt <<"\n";
    return 0;
}