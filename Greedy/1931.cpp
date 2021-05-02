#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Int2 {
  int a[2];
};

bool compare(Int2 x, Int2 y){
    return (x.a[0] < y.a[0]) || (x.a[0] == y.a[0] && x.a[1]< y.a[1]);
}

int main(){
    int N;
    cin >> N;
    vector<Int2> x;
    for(int i=0; i<N; i++){
        Int2 tmp;
        cin >> tmp.a[0] >> tmp.a[1];
        x.push_back(tmp);
    }
    sort(x.begin(), x.end(), compare);
    // for(int i=0; i<N; i++){
    //     cout << x[i].a[0] << " " << x[i].a[1] << endl;
    // }
    int cnt = 0, end = -1;
    for(int i = 0 ; i< N ; i++){
        if(end<= x[i].a[0]){
            cnt += 1;
            end = x[i].a[1];
        }
        if(end > x[i].a[1]) end = x[i].a[1];
    }
    cout << cnt << endl;
    return 0;
}