#include<iostream>
#include<iomanip>

using namespace std;

long long calTriangle(pair<long long,long long> x, pair<long long,long long> y){
    return (x.first *y.second -y.first*x.second);
}
// xy, xz의 방향
long long ccw(pair<long long,long long> x, pair<long long,long long> y, pair<long long,long long> z){
    long long tmp = calTriangle(make_pair(y.first-x.first, y.second-x.second), make_pair(z.first-x.first, z.second-x.second));
    return tmp/abs(tmp);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    pair<int,int> x1, x2;
    pair<int,int> y1, y2;
    cin >> x1.first >> x1.second;
    cin >> x2.first >> x2.second;
    cin >> y1.first >> y1.second;
    cin >> y2.first >> y2.second;
    bool intersect = !(ccw(x1,y1,y2) * ccw(x2,y1,y2) > 0 || ccw(y1,x1,x2) * ccw(y2,x1,x2) > 0);
    cout << (intersect? 1: 0) <<"\n";

    return 0;
}