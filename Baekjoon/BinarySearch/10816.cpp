#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int x[N];
    for(int i=0;i<N;i++){
        cin >> x[i];
    }
    sort(x, x+N);
    int M;
    cin >> M;
    for(int i = 0; i< M ; i++){
        int tmp;
        cin >> tmp;
        int l = 0, r= N-1;
        while(r -l >1){
            int center = (l+r)/2;
            if(tmp >= x[center]){
                l = center;
            }else{
                r = center;
            }
        }
        // cout << "r,l:" << r <<", " <<l << "\n";
        int r_idx = (x[r] == tmp)? r: l;
        l = 0, r= N-1;
        while(r -l >1){
            int center = (l+r)/2;
            if(tmp > x[center]){
                l = center;
            }else{
                r = center;
            }
        }
        int l_idx = (x[l] == tmp)? l: r;
        // cout << r_idx << " "<< l_idx << "\n"; 
        cout << r_idx - l_idx + 1 << " ";
    }
    return 0;
}