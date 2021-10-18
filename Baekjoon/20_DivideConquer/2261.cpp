#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

bool compareY(pair<int,int> x, pair<int,int>y){
    return x.second < y.second;
}

int dist(pair<int,int> x, pair<int,int> y){
    return pow(x.first - y.first,2) + pow(x.second-y.second,2);
}

//[L,R) 사이의 점들에 대해서 최근접쌍
int func(pair<int,int> * x, int L, int R){
    if(R-L <= 1) return INT32_MAX;
    int d = min(func(x, L, (L+R)/2), func(x, (L+R)/2, R));
    int l = (L+R)/2 - 1,  r= (L+R)/2;
    int x_axis = x[r].first;
    vector<pair<int,int>> v;
    while(l >= L){
        if(pow(x_axis - x[l].first,2) <= d){
            v.push_back(x[l]);
            l--;
        }else{
            break;
        }
    }
    while(r < R){
        if(pow(x_axis - x[r].first,2) <= d){
            v.push_back(x[r]);
            r++;
        }else{
            break;
        }
    }
    sort(v.begin(),v.end(),compareY);
    for(int i = 0; i < v.size();i++){
        for(int j = 1;j< 6;j++){
            if(i+j < v.size()){
                d = min(dist(v[i],v[i+j]),d);
            }
        }
    }
    return d;
}

// 최근접쌍 알고리즘
// x좌표에 대한 sorting후 반으로 가른다.
// 각각에서의 최소 거리를 구한다.
// 반으로 가르는 기준이 되는 x좌표에서의 최소 거리보다 작은 점들을 모두 모은다.
// 이들을 y축으로 정렬 후 바로 위의점 5개와의 거리 비교. 최소 거리는 비둘기집의 원리에
// 의해 이들 중 하나!
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    pair<int,int> x[N];
    for(int i = 0;i<N;i++) 
        cin >> x[i].first >> x[i].second;
    sort(x, x+N);
    cout << func(x, 0, N) << "\n";

    return 0;
}