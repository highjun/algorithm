#include<iostream>

using namespace std;

// 3x+5y = N이어야 한다.
// x가 작을수록 x+y가 작으므로 for문을 x에 대해 돌린다.
int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i< N;i++){
        if(N>=  3*i &&(N- 3*i)%5 == 0){
            cout << i+ (N-3*i)/5 << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}