#include<iostream>

using namespace std;

void failure(int *ps,string str){
    int prev = 0;
    ps[0] = 0;
    for(int i = 1; i< str.size(); i++){
        if(str[prev]== str[i]){
            prev++;
            ps[i] = prev;
        }else{
            if(prev > 0){
                prev = ps[prev-1];
                i--;
            }else{
                ps[i] = 0;
            }
        }
    }
}

// failure Function을 활용
// ps[str.size()-1]이 n-1제곱이 될 것이다.
// result = size / (size - fail) 로 나누어떨어지는 경우.
int main(){
    string str;
    while(cin >> str){
        // cout << str <<"\n";
        if(str==".") break;
        //kmp의 Failure fucntion
        int ps[str.size()];
        failure(ps, str);
        int partial = str.size()-ps[str.size()-1];
        if(str.size()%partial == 0){
            cout << str.size()/partial << "\n";
        }else{
            cout << 1 <<"\n";
        }
    }
    return 0;
}