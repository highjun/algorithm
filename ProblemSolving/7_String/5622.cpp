#include<iostream>

using namespace std;

// 문자를 대응되는 숫자로 변환하여 합산.
int main(){
    string x;
    cin >> x;
    int cnt = 0;
    for(int i = 0;i<x.size();i++){
        int num = (x[i]- 'A');
        if(num<18){//ABC, DEF, GHI, JKL, MNO, PQR까지 처리
            num = num/3 +2;
        }else if(num < 25){// S, TUV, WXY까지
            num = 7+(num - 16)/3;
        }else{
            num = 9;
        }
        cnt += 1+ num;
    }
    cout << cnt << "\n";
    return 0;
}