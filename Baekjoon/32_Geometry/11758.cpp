#include<iostream>
#include<iomanip>

using namespace std;

double calTriangle(pair<int,int> x, pair<int,int> y){
    return ((double)(x.first *y.second -y.first*x.second))/2;
}

int main(){
    pair<int,int> x,y,z;
    cin >> x.first >> x.second;
    cin >> y.first >> y.second;
    cin >> z.first >> z.second;

    double area = calTriangle(make_pair(y.first-x.first, y.second-x.second), make_pair(z.first-y.first, z.second-y.second));
    if(area > 0){
        cout << 1<<"\n";
    }else if(area == 0){
        cout << 0<<"\n";
    }else{
        cout << -1<<"\n";
    }
    return 0;
}