#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int A,B,C;
    cin >> A >> B >> C;
    int result = A*B*C;
    int x[10];
    fill(x, x+10,0);
    while(result !=0){
        x[result%10] += 1;
        result /= 10;
    }
    for(int i = 0 ;i<10;i++){
        cout << x[i] << "\n";
    }
    return 0;
}