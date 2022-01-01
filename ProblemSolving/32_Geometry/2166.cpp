#include<iostream>
#include<iomanip>

using namespace std;

double calTriangle(pair<double,double> x, pair<double,double> y){
    return (x.first *y.second -y.first*x.second)/2;
}

int main(){
    int N;
    cin >> N;
    pair<double,double> x[N];
    for(int i = 0; i<N;i++){
        cin >> x[i].first >> x[i].second;
    }
    double area = 0;
    for(int i = 0;i<N;i++){
        area += calTriangle(x[i], x[(i+1)%N]);
    }

    cout << fixed << setprecision(1);
    cout << abs(area) << "\n";
    return 0;
}