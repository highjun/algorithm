#include<iostream>

using namespace std;

//숫자가 공백없이 주어지므로, 문자열로 받는다.
//문자열의 경우, 값이 char가 되므로 '0'에서 빼
//실제 값으로 변환하여 합산한다.
int main(){
    int N;
    cin >> N;
    string x;
    cin >> x;
    int cnt = 0;
    while(N--){
        cnt += x[N] - '0';
    }
    cout << cnt << "\n";
    return 0;
}