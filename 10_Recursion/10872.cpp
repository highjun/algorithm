#include<iostream>

using namespace std;

//0!,1!은 1이 되고 그 이상의 경우는 재귀로 구한다.
int factorial(int N){
    if(N > 1)
        return N*factorial(N-1);
    else
        return 1;
}

int main(){
    int N;
    cin >> N;
    cout << factorial(N) << "\n";
    return 0;
}