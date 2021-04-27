#include<iostream>
using namespace std;

int cache[20][20][20];
int calW(int a, int b, int c){
    if(a<= 0 || b<=0 || c<= 0){
        return 1;
    }
    else if(a> 20 || b>20 || c> 20){
        return calW(20,20,20);
    }else if(a<b && b< c){
        if(cache[a-1][b-1][c-1] == -1){
            cache[a-1][b-1][c-1] = calW(a,b,c-1)+ calW(a,b-1,c-1)- calW(a, b-1, c);
        }
        return cache[a-1][b-1][c-1];
    }else{
        if(cache[a-1][b-1][c-1] == -1){
            cache[a-1][b-1][c-1] = calW(a-1,b,c)+ calW(a-1,b-1,c)+ calW(a-1, b, c-1)-calW(a-1, b-1, c-1);
        }
        return cache[a-1][b-1][c-1];
    }
}
int main(){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            for(int k=0;k<20;k++){
                cache[i][j][k] = -1;
            }
        }    
    }
    while(1){
        int a,b,c;
        cin >> a >> b >> c;
        if(a== -1 && b==-1 && c== -1) break;
        cout << "w(" << a <<", " << b <<", "<< c <<") = " <<calW(a,b,c) << endl;
    }
}