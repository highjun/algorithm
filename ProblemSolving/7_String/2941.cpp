#include<iostream>

using namespace std;

// = , - , j로 모든 문자가 끝나고, 마지막 자리에만 온다.
// 이들에 대해서 조건을 나누어 준다.    
int main(){
    string x;
    cin >> x;
    int cnt = 0;
    for(int i = 0; i<x.size();i++){
        if(x[i] == '='){
            if(i > 1){//dz=인 경우만 앞의 알파벳에서 2번 세지므로 한번 뺀다.
                cnt -= x[i-1] == 'z' && x[i-2] == 'd';
            }
        }else if(x[i] =='j'){
            if(i > 0){//평범한 j인 경우는 Counting
                cnt += x[i-1]!= 'l' && x[i-1]!= 'n';
            }else{
                cnt++;
            }
        }else if(x[i] == '-'){
            //2글자 짜리므로 무시 가능
        }else{
            cnt++;
        }
    }
    cout << cnt  <<"\n";
    return 0;
}