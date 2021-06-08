#include<iostream>

using namespace std;

//[r,r+n)x[c, c+n)
pair<int,int> func(int* x, int N,int n, int r, int c){
    if(n ==  1){
        int cnt = x[r*N+c];
        return make_pair(1-cnt, cnt);
    }else{
        pair<int,int> a= func(x,N, n/2, r,c);
        pair<int,int> b= func(x,N, n/2, r+n/2,c);
        pair<int,int> d= func(x,N, n/2, r, c+n/2);
        pair<int,int> e= func(x,N, n/2, r+n/2,c+n/2);
        if(a.first == 0 && b.first == 0 && e.first == 0 && d.first == 0){
            return make_pair(0,1);
        }
        if(a.second == 0 && b.second == 0 && e.second == 0 && d.second == 0){
            return make_pair(1,0);
        }
        return make_pair(a.first+ b.first +d.first + e.first, a.second+b.second+d.second+e.second);
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int x[N*N];
    for(int i = 0; i< N*N;i++){
        cin >> x[i];
    }
    pair<int,int> result = func(x, N, N, 0,0);
    cout << result.first <<"\n" << result.second <<"\n";

    return 0;
}