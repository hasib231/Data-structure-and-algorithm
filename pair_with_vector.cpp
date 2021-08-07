#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector < pair<int, string> > v;
    vector < pair<int, string> >::iterator it;

    //0 - 21, dipta
    //1 - 22, nabil
    v.push_back(make_pair(21, "dipta"));
    v.push_back(make_pair(22, "nabil"));

    //cout<<v[0].second<<endl;

    for(it=v.begin(); it!=v.end(); it++){
        cout<< it->first <<" "<<it->second<<endl;
    }
}
