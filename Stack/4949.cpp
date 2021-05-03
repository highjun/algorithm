#include<iostream>
#include<stack>

using namespace std;

int main(){
    string x;
    getline(cin, x);
    while(!(x.size()==1 && x[0] == '.')){
        stack<char> s;
        bool pass = true;
        for(int i = 0; i<x.length();i++){
            if(x[i]== '('){
                s.push('(');
            }else if(x[i] == '['){
                s.push('[');
            }else if(x[i] == ']'){
                if(!s.empty() &&s.top()== '['){
                    s.pop();
                }else{
                    pass = false;
                    break;
                }
            }else if(x[i] == ')'){
                if(!s.empty() && s.top()=='('){
                    s.pop();
                }else{
                    pass = false;
                    break;
                }
            }
        }
        if(!s.empty()){
            pass = false;
        }
        cout << (pass? "yes":"no") << endl;
        getline(cin, x);
    }   
    return 0;
}