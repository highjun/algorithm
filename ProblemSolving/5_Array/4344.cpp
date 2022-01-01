#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int len;
        cin >> len;
        int x[len];
        double sum = 0;
        for(int i = 0;i<len;i++){
            cin >> x[i];
            sum += x[i];
        }
        sum/= len;
        int cnt = 0;
        for(int i = 0; i<len;i++){
            if(x[i]> sum){
                cnt++;
            }
        }
        cout << fixed << setprecision(3);
        cout << ((double)cnt)/len * 100 <<"%\n";
    }
    return 0;
}