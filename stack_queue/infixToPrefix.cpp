#include <bits/stdc++.h>
using namespace std;

int prior(char c){
    if(c == '^') return 3;

    if(c == '*' or c == '/') return 2;

    if( c == '+' or c == '-') return 1;

    return -1;

}

int main(){
    int i= 0;
    string str;
    string ans = "";
    stack<char> st;

    cin>>str;

    int n = str.size();

    while(i<n){
        char c = str[i];
        if(c >= 'A' and c <= 'Z' or c >= 'a' and c <= 'z' or c >= '0' and c <= '9'){
            ans += c;
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(!st.empty() and st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() and prior(c) <= prior(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }

        i++;
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    cout<<ans<<endl;

    return 0;
}