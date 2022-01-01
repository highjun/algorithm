#include<iostream>

using namespace std;

//N!의 0의 개수는 소인수 5의 개수 = 5의배수 + 25의 배수 +... 
int main(){
    int N;
    cin >> N;
    int cnt = 0;
    while(N!=0){
        cnt += N/5;
        N /= 5;
    }
    cout << cnt << "\n";
    return 0;
}