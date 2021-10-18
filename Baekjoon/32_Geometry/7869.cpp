#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double calD(double x1, double x2, double y1, double y2){
    return pow(pow(x1-x2,2)+pow(y1-y2,2),.5);
}

int main(){
    cout << fixed << setprecision(3);

    double x1,y1, r1, x2,y2,r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d = calD(x1,x2,y1,y2);
    // cout << d <<"\n";
    if(r1+r2 <= d) cout << 0.0 <<"\n";
    else if(r1 >= d+ r2){
        cout << pow(r2,2)*M_PI << "\n";
    }else if(r2 >= d+r1){
        cout << pow(r1,2)*M_PI << "\n";
    }else{
        double theta1 = (pow(d,2) + pow(r1,2) -pow(r2,2))/(2*r1*d);
        double theta2 = (pow(d,2) + pow(r2,2) -pow(r1,2))/(2*r2*d);
        // cout << theta1 << "\n";
        // cout << theta2 <<"\n"; 
        // cout << acos(theta1) << "\n";
        // cout << acos(theta2) << "\n";
        double S = pow(r1,2)* acos(theta1) + pow(r2,2)* acos(theta2);
        S -= d* r2 * sin(acos(theta2));
        cout << S << "\n";
    }
    return 0;
}