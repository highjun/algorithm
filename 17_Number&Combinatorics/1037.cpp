#include<iostream>
#include<algorithm>

using namespace std;

//가장 작은 진약수와 가장 큰 진약수의 곱은 N이 된다.
int main(){
    int n_factor;
    cin >> n_factor;
    int x[n_factor];
    for(int i = 0;i<n_factor;i++){
        cin >> x[i];
    }
    sort(x, x+n_factor);
    cout << x[0] * x[n_factor-1] << "\n";
    return 0;
}