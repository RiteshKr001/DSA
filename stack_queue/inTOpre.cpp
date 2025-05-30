#include<bits/stdc++.h>
using namespace std;

int prior(char c){
    if(c == '^') return 3;

    if(c == '*' or c == '/') return 2;

    if( c == '+' or c == '-') return 1;

    return -1;

}

int main(){
    int i =0;
    string str;
    cin>>str;

    string ans = "";
    stack<char> st;

    int n = str.size();

    reverse(str.begin(), str.end());

    while(i<n){
        char c = str[i];

        if((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or (c >= '0' and c <= '9')){
            ans += c;
        }
        else if( c == ')'){
            st.push(c);
        }
        else if(c == '('){
            while(!st.empty() && st.top() != ')'){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(c == '^'){
                while(!st.empty() && prior(c) <= prior(st.top())){
                    ans += st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && prior(c) < prior(st.top())){
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }

        i++;
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    cout<<ans;

    return 0;
}