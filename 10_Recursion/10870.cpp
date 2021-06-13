#include<iostream>

using namespace std;

//0 - 0 , 1 - 1이고 그이상은 점화식을 통한 재귀문
int fibonacci(int N){
    if(N > 1)
        return fibonacci(N-1) + fibonacci(N-2);
    else
        return N;
}

int main(){
    int N;
    cin >> N;
    cout << fibonacci(N) << "\n";
    return 0;
}