#include<iostream>

using namespace std;

//A,B의 범위가 무식하게 크므로 문자열로 받고 계산해야 한다.
int main(){
    string x,y;
    cin >> x >> y;
    int x_idx = x.size()-1;
    int y_idx = y.size()-1;
    string z;
    int up = 0, tmp;
    while(1){
        if(x_idx >= 0 && y_idx >= 0)
            tmp = x[x_idx] - '0' + y[y_idx] - '0' + up;
        else if(x_idx < 0){
            tmp = y[y_idx]-'0' + up;
        }else if(y_idx < 0){
            tmp = x[x_idx]-'0' + up;
        }
        up = tmp/10;
        z.push_back((tmp%10 +'0'));
        x_idx--, y_idx--;
        if(x_idx <0 && y_idx <0) break;
    }
    if(up > 0) cout << up;
    for(int i = z.size();i>0; i--){
        cout << z[i-1];
    }
    cout << "\n";
    return 0;
}