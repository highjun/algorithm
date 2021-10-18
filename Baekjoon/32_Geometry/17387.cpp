#include<iostream>

using namespace std;

#define ll long long

int ccw(pair<ll, ll> x,pair<ll, ll> y,pair<ll, ll> z){
    ll tmp = (y.first - x.first)*(z.second-x.second) -(z.first - x.first)*(y.second-x.second);
    if(tmp == 0){
        return 0;
    } else if(tmp < 0){
        return -1;
    } else{
        return 1;
    }
}

int main(){
    //같은 점이라서 일직선 상인 경우를 고려했어야 함!
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    pair<ll,ll> x[4];
    for(int i = 0; i<4;i++) cin >> x[i].first >> x[i].second;
    int xxy = ccw(x[0],x[1],x[2])* ccw(x[0],x[1],x[3]);
    int yyx = ccw(x[2],x[3],x[0])* ccw(x[2],x[3],x[1]);
    bool intersect = xxy <=0 && yyx <= 0;
    if (xxy==0 && yyx == 0){
        if(x[0] > x[1]) swap(x[0],x[1]);
        if(x[2] > x[3]) swap(x[2],x[3]);
        intersect = x[1] >= x[2] && x[3] >= x[0];
    }
    cout << (intersect? 1:0) << "\n";

    return 0;
}