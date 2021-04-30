#include<iostream>

using namespace std;

bool cache[2000][2000];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    int N;
    cin >>N;
    int x[N];
    for(int  i = 0;i<N; i++){
        cin >> x[i];
    }
    for(int i=0; i< N; i++){
        for(int j = 0; j+i< N; j++){
            //[j, j+i]
            if(i == 0){
                cache[j][j+i] = true;
            }else if(i == 1){
                cache[j][j+i] = (x[j]==x[j+1]);
            }else{
                cache[j][j+i] = (x[j]== x[j+i] && cache[j+1][j+i-1]);
            }
        }
    }
    // for(int i=0;i<N;i++){
    //     for(int j=0; j< N; j++){
    //         cout << cache[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int M;
    cin >> M;
    for(int  i = 0;i<M; i++){
        int start, end;
        cin >> start >> end;
        cout << (cache[start-1][end-1]? 1: 0) << "\n"; //endl;
    }
    return 0;
}   