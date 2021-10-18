#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin >> N;
    int target[N];
    char operation[2*N];
    for(int i=0; i< N; i++){
        cin >> target[i];
    }
    stack<int> s;
    int tmp = 0, last = 1, op =0;
    for(int i = 0; i< 2*N; i++){
        if(last <= target[tmp]){
            s.push(last);
            operation[i] = '+';
            last += 1;
        }else{
            if(!s.empty() && s.top() == target[tmp]){
                tmp+=1;
                s.pop();
                operation[i] ='-';
            }else{
                cout << "NO" << endl; 
                return 0;
            }
        }    
    }
    for(int i = 0; i< 2*N; i++){
        cout << operation[i] << "\n";
    }
    return 0;
}