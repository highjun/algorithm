#include<iostream>

using namespace std;

//약배수는 나머지 연산이 0인 것을 통해서 확인 가능
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N,M;
    while(cin >> N >> M){
        if(N==0 && M==0) break;
        if(M%N == 0) cout << "factor\n";
        else if(N%M == 0) cout << "multiple\n";
        else cout << "neither\n";
    }
    return 0;
}