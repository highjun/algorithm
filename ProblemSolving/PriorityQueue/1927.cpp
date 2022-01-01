#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin >> N;
    priority_queue<int , vector<int>, greater<int>> q;
    for(int i = 0;i<N;i++){
        int tmp;
        cin >> tmp;
        if(tmp == 0){
            if(!q.empty()){
                cout << q.top() << "\n";
                q.pop();
            }else{
                cout << 0 << "\n";
            }
        }else{
            q.push(tmp);
        }
        
    }
    return 0;
}