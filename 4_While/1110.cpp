#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int cnt = 0, tmp = N;
    do
    {
        cnt++;
        tmp = (tmp%10) * 10+ (tmp/10 + tmp%10)%10;
        // cout << tmp << "\n";
    } while (tmp!=N);
    cout << cnt << "\n";
    return 0;
}