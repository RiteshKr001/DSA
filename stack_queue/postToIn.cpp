#include<bits/stdc++.h>
using namespace std;


int main(){
    string exp;
    cin>>exp;

    stack <string> st;
    int i = 0;

    int n = exp.size();

    while (i<n)
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

            st.push( "(" +o1 + c + o2 + ")");
        }
        i++;
    }

    cout<<st.top();
    

    return 0;
}