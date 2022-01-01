#include<iostream>
#include<cmath>

using namespace std;

//xx01호부터 채워지므로 H로 나눈 몫이 호수가 되고, 나머지가 층수가 된다.
int main(){
    int T;
    cin >> T;
    while(T--){
        int H,W,N;
        cin >> H >> W >> N;
        int X = (N-1)/H +1;
        int Y = (N-1)%H +1;
        cout << Y*100 + X << "\n";
    }
    return 0;
}