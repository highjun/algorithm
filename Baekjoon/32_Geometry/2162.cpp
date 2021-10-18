#include<iostream>
#include<tuple>
#include<algorithm>

using namespace std;

#define ll long long

//find root
int find(int x, int* parent){
    if(parent[x] == x){
        return x;
    }else{
        //path compression
        //root로 가는 길에 있는 노드를 root의 child로 올려버린다.
        parent[x] = find(parent[x], parent);
        return parent[x];
    }
}
void union_(int x, int y, int* parent, int* rank){
    x = find(x, parent);
    y = find(y, parent);
    if(x == y) return;
    // union-by-rank 알고리즘
    // rank는 root Node에서만 업데이트된다. 
    if(rank[x] < rank[y]){
        parent[x] = y;
    }else{
        parent[y] = x;
        if(rank[x] == rank[y]){
            rank[x]++;
        }
    }
}

pair<ll,ll> operator-(pair<ll,ll> l,pair<ll,ll> r) {   
    return {l.first-r.first,l.second-r.second};                                    
}

ll cp(pair<ll, ll> x, pair<ll,ll> y){
    return x.first*y.second - y.first*x.second;
}
int ccw(pair<ll,ll>x , pair<ll,ll>y, pair<ll,ll>z){
    ll tmp = cp(y-x, z-x);
    if(tmp == 0) return 0;
    else if(tmp > 0) return 1; //반시계
    else return -1;
}

bool isIntersect(tuple<ll,ll,ll,ll> line1,tuple<ll,ll,ll,ll> line2){
    pair<ll,ll> x1,x2;
    pair<ll,ll> y1,y2;
    tie(x1.first, x1.second,x2.first, x2.second) = line1;
    tie(y1.first, y1.second,y2.first, y2.second) = line2;
    int xxy = ccw(x1,x2,y1)* ccw(x1,x2,y2);
    int yyx = ccw(y1,y2,x1)* ccw(y1,y2,x2);
    bool intersect = xxy <=0 && yyx <= 0;
    if (xxy==0 && yyx == 0){
        if(x1 > x2) swap(x1,x2);
        if(y1 > y2) swap(y1,y2);
        intersect = x2 >= y1 && y2 >= x1;
    }
    return intersect;
}

//union find를 이용해서 선분의 그룹을 찾는다.
int main(){
    int N;
    cin >> N;
    tuple<ll,ll,ll,ll> x[N];
    for(int i = 0;i<N;i++){
        ll a,y,z,w;
        cin >> a>> y>> z>> w;
        x[i] = make_tuple(a,y,z,w);
    }
    int parent[N];
    for(int i = 0;i<N;i++) parent[i] =i;
    int rank[N];
    fill(rank, rank+N,0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j<N;j++){
            if(find(i, parent) != find(j,parent)){
                if(isIntersect(x[i],x[j])){
                    union_(i,j, parent, rank);
                }
            }
        }
    }
    int component[N];
    fill(component, component+N,0);
    int n_comp = 0;
    for(int i = 0; i<N;i++){
        component[find(i,parent)]++;
        if(component[find(i,parent)] == 1) n_comp++;
    }
    cout <<n_comp <<"\n" << *max_element(component, component+N) <<"\n";
    return 0;
}