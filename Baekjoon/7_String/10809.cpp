#include<iostream>

using namespace std;

//입력을 문자열로 받고, 순서대로 확인하여
//첫 위치를 저장한다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string x;
    cin >> x;
    int n_alphabet = 'z'-'a'+1;
    int first[n_alphabet];
    fill(first, first+ n_alphabet, -1);
    for(int i = 0; i<x.size();i++){
        if(first[x[i]-'a']== -1)
            first[x[i]-'a'] = i;
    }
    for(int i = 0 ; i<n_alphabet;i++){
        cout << first[i] <<" ";
    }
    cout <<"\n";
    return 0;
}