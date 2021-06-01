#include<iostream>
#include<algorithm>

using namespace std;

bool compare(pair<int,int> x, pair<int,int>y){
    return x.first < y.first || (x.first == y.first && x.second < y.second); 
}

//Compare로 연산을 정의해서 sort하도록 할 수 있다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    pair<int,int> x[N];
    for(int i = 0;i<N;i++){
        cin >> x[i].first >> x[i].second;
    }
    sort(x, x+N,  compare);
    for(int i = 0;i<N;i++){
        cout << x[i].first << " "<< x[i].second;
        cout << "\n";
    }
    return 0;
}