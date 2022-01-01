#include<iostream>

using namespace std;

//a^2+b^2=c^2으로 판단
int main(){
    int x,y,z;
    while(cin >> x>> y >>z){
        if(x== 0 && y==0 && z == 0) break;
        int c = max(max(x,y),z);
        if(x*x+y*y+z*z == 2*c*c){
            cout << "right\n";
        }else{
            cout << "wrong\n";
        }
    }
    return 0;
}