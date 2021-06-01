#include<iostream>
#include<algorithm>

using namespace std;

//0이상 N미만의 수로 변경
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    pair<int,int> x[N];
    for(int i = 0;i<N;i++){
        cin >> x[i].first;
        x[i].second = i;
    } 
    sort(x, x+N);
    int tmp[N];
    int prev;
    int cnt = 0;
    for(int i = 0; i<N;i++){
        if(i== 0){
            prev = x[i].first;
            tmp[x[i].second] = 0;
        }else{
            if(prev != x[i].first){
                prev = x[i].first;
                cnt++;
            }
            tmp[x[i].second] = cnt;
        }
    }
    for(int i = 0;i<N;i++) cout << tmp[i] << " ";
    cout << "\n";
    return 0;
}