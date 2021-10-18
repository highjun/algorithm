#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct compare{
    bool operator()(int a, int b){
        int abs_a= a, abs_b =b;
        if(a < 0){
            abs_a = -a;
        }
        if(b < 0){
            abs_b= -b;
        }
        return abs_a > abs_b || (abs_a == abs_b && a > b) ;
    }
};

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin >> N;
    priority_queue<int , vector<int>, compare> q;
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