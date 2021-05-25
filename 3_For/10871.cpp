#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,X;
    cin >> N >> X;
    for(int i =0 ; i< N;i++){
        int tmp;
        cin >> tmp;
        if(tmp < X){
            cout << tmp << " ";
        }
    }
    cout << "\n";
    return 0;
}