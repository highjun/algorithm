#include<iostream>
#include<memory.h>
#include<vector>

using namespace std;

int main(){
    string X,Y;
    cin >> X >> Y;

    int save[1001][1001];
    memset(save, 0, sizeof(int)*1001*1001);

    for(int i = 0;i<X.size(); i++){
        for(int j = 0;j<Y.size(); j++){
            if(X.at(i) == Y.at(j)){
                save[i+1][j+1] = save[i][j]+1;
            }else{
                save[i+1][j+1] = max(save[i][j+1], save[i+1][j]);
            }
        }   
    } 
    // for(int i = 0;i<X.size()+1; i++){
    //     for(int j = 0;j<Y.size()+1; j++){
    //         cout << save[i][j] <<" ";
    //     }   
    //     cout << "\n";
    // } 
    int u= X.size(), v= Y.size();
    int tmp = save[u][v]; 
    cout << tmp << "\n";
    vector<char> vec;
    while(tmp){
        if(save[u][v]== save[u-1][v-1]+1 
        && save[u][v-1]+1 == save[u][v]
        && save[u-1][v]+1 == save[u][v]){
            u--;
            v--;
            vec.push_back(X.at(u));
            tmp--;
        }else if(save[u-1][v] == save[u][v]){
            u--;
        }else if(save[u][v-1] == save[u][v]){
            v--;
        }
    }
    if(vec.size()!=0){
        for(int i = vec.size()-1 ; i>=0 ;i--){
            cout << vec[i];
        }
        cout << "\n";
    }

    return 0;
}