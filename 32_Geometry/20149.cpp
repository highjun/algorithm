#include<iostream>
#include<iomanip>

using namespace std;

#define ll long long

pair<ll,ll> operator+(pair<ll,ll> l,pair<ll,ll> r) {   
    return {l.first+r.first,l.second+r.second};                                    
}  
pair<ll,ll> operator-(pair<ll,ll> l,pair<ll,ll> r) {   
    return {l.first-r.first,l.second-r.second};                                    
}

double cp(pair<ll, ll> x, pair<ll,ll> y){
    return x.first*y.second - y.first*x.second;
}
int ccw(pair<ll,ll>x , pair<ll,ll>y, pair<ll,ll>z){
    ll tmp = cp(y-x, z-x);
    if(tmp == 0) return 0;
    else if(tmp > 0) return 1; //반시계
    else return -1;
}

int main(){
    pair<ll,ll> x1,x2;
    pair<ll,ll> y1,y2;
    cin >> x1.first >> x1.second;
    cin >> x2.first >> x2.second;
    cin >> y1.first >> y1.second;
    cin >> y2.first >> y2.second;
    ll xy1 = ccw(x1,x2, y1), xy2= ccw(x1,x2,y2);
    ll yx1 = ccw(y1,y2, x1), yx2= ccw(y1,y2,x2);
    //평행인 경우
    if(xy1 == 0 && xy2 == 0){
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        cout << ((x2 >=y1) && (y2 >= x1)) << "\n";
        if(x2 == y1){
            cout << x2.first <<" " << x2.second <<"\n";
        }
        if(x1 == y2){
            cout << x1.first <<" " << x1.second <<"\n";
        }
        return 0;
    }
    //끝점이 겹치는 경우
    if(x1 == y1 || x1 == y2){
        cout<< "1\n";
        cout << x1.first <<" " << x1.second <<"\n";
        return 0;
    }
    if(x2 == y1 || x2 == y2){
        cout<< "1\n";
        cout << x2.first <<" " << x2.second <<"\n";
        return 0;
    }

    //세 점이 일직선에 있는 경우
    if(xy1 *xy2 <= 0 && yx1 *yx2 <=0){
        if(xy1 == 0){
            cout<< "1\n";
            cout << y1.first <<" " << y1.second <<"\n";
            return 0;
        }else if(xy2 == 0){
            cout<< "1\n";
            cout << y2.first <<" " << y2.second <<"\n";
            return 0;
        }else if(yx1 == 0){
            cout<< "1\n";
            cout << x1.first <<" " << x1.second <<"\n";
            return 0;
        }else if(yx2 == 0){
            cout<< "1\n";
            cout << x2.first <<" " << x2.second <<"\n";
            return 0;
        }
    }

    //교차하는 경우
    if(xy1*xy2<0 && yx1*yx2<0){
        cout << "1\n";
        double alpha = -cp(x2-y2, y1-y2)/cp(x1-x2, y1-y2);
        cout << fixed << setprecision(9);
        cout << alpha*x1.first + (1-alpha)*x2.first << " " <<alpha*x1.second + (1-alpha)*x2.second <<"\n";
        return 0;
    }
    //교차하지 않는 경우
    cout << "0\n";
    return 0;
}