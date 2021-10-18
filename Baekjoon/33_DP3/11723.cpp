#include<iostream>

using namespace std;

//Bitmask bit연산 OR, XOR, AND, NOT를 적당히 이용해서 구현
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int x= 0;
    for(int i = 0;i<N;i++){
        string tmp;
        cin >> tmp;
        int num, mask;
        if(tmp == "add"){
            cin >> num;
            mask = 1<< num;
            x = x | mask;
        }else if(tmp == "check"){
            cin >> num;
            mask = 1 << num;
            cout << ((x & mask) == mask) << "\n";
        }else if(tmp == "remove"){
            cin >> num;
            mask = 1 << num;
            x = x & ~mask;
        }else if(tmp == "toggle"){  
            cin >> num;
            mask = 1 << num;
            x = x ^ mask;
        }else if(tmp == "all"){
            x = ~(x ^ x);
        }else if(tmp == "empty"){
            x = 0;
        }
    }
    

    return 0;
}