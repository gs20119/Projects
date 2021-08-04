
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    int a=0, b=0;
    stack<char> St;
    for(int i=0; i<s.size(); i++){
        if(s[i]==')' && (St.empty() || St.top()!='(')){ printf("NO\n"); return 0; }
        if(s[i]==']' && (St.empty() || St.top()!='[')){ printf("NO\n"); return 0; }
        if(s[i]==')' || s[i]==']') St.pop();
        else St.push(s[i]);
    }if(!St.empty()){ printf("NO\n"); return 0; }
    printf("YES\n");
}

