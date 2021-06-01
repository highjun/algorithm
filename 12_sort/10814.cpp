#include<iostream>
#include<tuple>
#include<algorithm>

using namespace std;

bool compare(pair<int,pair<int,string>> x, pair<int,pair<int,string>> y){
    return x.second.first < y.second.first || (x.second.first == y.second.first && x.first < y.first);
}
//idx를 사용하므로, idx를 함께 저장
//Stable Sort
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    pair<int,pair<int, string>> x[N]; 
    for(int i = 0; i<N;i++){
        x[i].first = i;
        cin >> x[i].second.first >> x[i].second.second;
    }
    sort(x, x+N, compare);
    for(int i = 0; i<N;i++){
        cout << x[i].second.first <<" "<< x[i].second.second<<"\n";
    }
    return 0;
}