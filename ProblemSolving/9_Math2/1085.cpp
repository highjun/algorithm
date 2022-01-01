#include<iostream>

using namespace std;

//x,w-x, y, h-y의 min을 출력한다.
int main(){
    int x,y,w,h;
    cin >> x >> y >> w >> h;
    int min_ = min(x,w-x);
    min_ = min(y, min_);
    min_ = min(h-y, min_);
    cout << min_ <<"\n";
    return 0;
}