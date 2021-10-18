#include<iostream>

using namespace std;

int main(){
    int H,M;
    cin >> H >> M;
    int tmp = H*60+ M;
    tmp += 24*60 - 45;//1440분을 더하므로써 음수가 되는 것을 방지한다.
    tmp %= 24*60;
    cout << tmp/60 << " " <<tmp%60 <<"\n";
    return 0;
}