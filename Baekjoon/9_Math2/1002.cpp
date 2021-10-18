#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double getDist(pair<int,int> x, pair<int,int> y){
    return pow(pow(x.first- y.first ,2) + pow(x.second - y.second , 2),.5);
}
//r1,r2, d가 삼각형을 이룰 수 있는지에 따라 판단
int main(){
    int T;
    cin >> T;
    while(T--){
        pair<int,int> p1, p2;
        double r1, r2;
        cin >> p1.first >> p1.second >> r1 >> p2.first >> p2.second >> r2;
        double d = getDist(p1,p2);
        double h = max(r1,max(r2, d));
        if(d == 0 && r1 == r2){
            cout << "-1\n";
            continue;
        }
        if(2*h < d+r1+r2){
            cout << "2\n";
        }else if(2*h == d+r1+r2){
            cout << "1\n";
        }else{
            cout << "0\n";
        }
    }
    return 0;
}