#include<iostream>

using namespace std;

//21억 이하의 자연수로 int 범위가 아슬아슬하다.
//long long으로 사용한다.
//필요한 생산은 A/(B-C)면 손익분기점.
int main(){
    long long A,B,C;
    cin >> A >> B >> C;
    if(B >= C){
        cout << "-1\n";
    }else{
        cout << A/(C-B) +1 <<"\n";
    }
    return 0;
}