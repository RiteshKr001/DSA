#include<bits/stdc++.h>
using namespace std;


int main(){
    string exp;
    cin>>exp;

    stack <string> st;
    
    int n = exp.size();
    int i = n-1;

    while (i>=0)
    {
        char c = exp[i];
        if(isalnum(c)){
            string t = "";
            t += c;
            st.push(t);
        }
        else{
            string o2 = st.top();
            st.pop();
            string o1 = st.top();
            st.pop();

            st.push( "(" +o2 + c + o1 + ")");
        }
        i--;
    }

    cout<<st.top();


    return 0;
}