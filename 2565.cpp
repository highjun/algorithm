#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int cache[100];
struct Int2 {
  int a;
  int b;
};
vector<Int2> x;
bool cmp(Int2 a, Int2 b){
    return a.a < b.a;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i<N;i++){
        Int2 a;
        cin >>a.a;
        cin >>a.b;
        x.push_back(a);
    }
    sort(x.begin(), x.end(), cmp);
    // for(int i= 0; i<N; i++){
    //     cout << x[i].a <<" " <<x[i].b <<endl;
    // }
    for(int i = 0; i< N; i++){
        int max_ = 0;
        for(int j= 0; j< i; j++){
            if(x[i].b > x[j].b){
                max_ = max(max_, cache[j]);
            }
        }
        cache[i] = max_ +1;
    }
    int max_ = 0;
    for(int i = 0 ; i< N; i++){
        max_ = max(max_ , cache[i]);
        // cout << cache[i] << " ";
    }
    cout << N-max_ << endl;

    return 0;
}