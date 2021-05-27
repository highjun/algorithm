#include<iostream>

using namespace std;

//숫자를 뒤짐는데, 3자리라는 조건이 주어져 있으므로 계산을 통해 뒤집는다.
int main(){
    int A,B;
    cin >> A >> B;
    A = (A/100) + (A/10)%10 * 10 + (A%10)*100;
    B = (B/100) + (B/10)%10 * 10 + (B%10)*100;
    cout << max(A,B) <<"\n";
    return 0;
}