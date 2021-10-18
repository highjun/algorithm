#include<iostream>

using namespace std;

long long func(long long A, long long B, long long C){
    if(B == 1){
        return A%C;
    }
    long long result = func(A, B/2, C);
    result = (result * result)%C;
    if(B%2 == 1){
        result = (result * A)%C;
    }
    return result;
}

//A,B,C는 int 범위지만 곱하면 long long의 범위까지 확장될 수 있으므로,
//long long을 사용.
int main(){
    long long A,B,C;
    cin >> A >> B >> C;
    cout << func(A,B,C) <<"\n";
    return 0;
}