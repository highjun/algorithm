#include<iostream>
#include<vector>
#include<cmath>
#include<float.h>

using namespace std;

double calDist(pair<double,double> a, pair<double,double> b){
    return sqrt(pow((a.first-b.first),2) + pow((a.second-b.second), 2));
}

//Prim 알고리즘
//이제까지 나온 점들과 가장 가까운 점을 선택해서 추가한다.
int main(){
    int N;
    cin >> N;
    vector<pair<double,double>> v;
    for(int i = 0; i<N;i++){
        double u,w;
        cin >> u >> w;
        v.emplace_back(u,w);
    }
    bool visit[N];
    fill(visit, visit+N, false);
    double adj[N*N];
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            adj[i*N+j] = calDist(v[i],v[j]);
        }
    }
    double dist[N];
    fill(dist, dist+N, DBL_MAX);
    int start = 0;
    double cost = 0;
    visit[start] = true;
    while(1){
        //distance update + find min
        int idx = -1;
        double min_ = -1;
        for(int i = 0; i< N;i++){
            dist[i] = min(dist[i], adj[start*N+i]);
            if((!visit[i]) &&min_ == -1){
                idx = i;
                min_ = dist[i];
            }
            if((!visit[i]) && dist[i] < min_){
                idx = i;
                min_ = dist[i];
            }
        }
        if(idx == -1) break;
        visit[idx] = true;
        start = idx;
        if(min_ != DBL_MAX)
            cost += min_;
    }
    cout << fixed;
    cout.precision(3);
    cout << cost << "\n";
    return 0;
}