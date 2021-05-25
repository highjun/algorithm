#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for(int i = 1;i<T+1;i++){
        int A,B;
        cin >> A >> B;
        cout << "Case #" << i << ": " << A <<" + " << B <<" = " << A+B <<"\n";
    }
    return 0;
}