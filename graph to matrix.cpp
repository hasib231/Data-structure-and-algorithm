#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s="abcsrj";
    list <string> li;
    li.push_back("ab");
    li.push_back("bc");
    li.push_back("ac");
    li.push_back("cs");
    li.push_back("rj");

    map <char,int> mp;
    for(int i=0;s[i];i++){
        mp[s[i]]=i;
    }
    bool a[6][6];
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            a[i][j]=0;
        }
    }
    for(auto it=li.begin();it!=li.end();it++){
        string temp=*it;
        a[mp[temp[0]]][mp[temp[1]]]=true;
        a[mp[temp[1]]][mp[temp[0]]]=true;
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
