#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string x;
    int cnt = 0;
    //while문이 EOF(End Of File)를 만나면 멈춘다.
    while(cin >> x){
        cnt++;
    }
    cout << cnt <<"\n";
    return 0;
}