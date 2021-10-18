#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
    cout << fixed << setprecision(9);
    int X,Y,D,T;
    cin >> X >> Y >> D >> T;
    double dist = pow(pow(X,2)+ pow(Y,2),.5);
    if(T> D){
        cout << dist << "\n";
    }else{
        double min_;
        int n_jump = floor(dist/D);
        //최대한 뛰고 남은 거리를 걸어간다.
        min_ = n_jump*T+ dist-D*n_jump;
        if(n_jump == 0){
            //1번 뛰고 남은 거리를 걸어간다. 
            min_ = min((D+T)-dist, min_);
            //2번 뛰어서 간다.
            min_ = min((double)2*T, min_);
        }else{
            //2번 이상 뛰어가므로 조금 비스듬히 점프로 도착 가능
            min_ = min((double)(n_jump+1)*T,min_);
        }
        cout << min_ <<"\n";
    }
    return 0;
}