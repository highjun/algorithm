#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int x[N];
    for(int i = 0;i<N;i++){
        cin >> x[i];
    }
    cout<< *min_element(x, x+N) << " "<< *max_element(x,x+N) <<"\n";
    return 0;
}