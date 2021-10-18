#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x[42];
    fill(x, x+42,0);
    int tmp;
    int cnt = 0;
    while(cin >> tmp){
        x[tmp%42]++;
        if(x[tmp%42] ==1) cnt++;
    }
    cout << cnt <<"\n";
    return 0;
}