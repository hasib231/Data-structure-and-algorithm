#include<bits/stdc++.h>

using namespace std;

int main()
{
    //vector <int> v = {1,3,5,8,9,12};
    int arr[] = {1,3,4,5,8,9,12};
    //bool ans = binary_search(v.begin(),v.end(),5);
    bool ans = binary_search(arr,arr+7,5);

    if(ans) cout<<"found" <<endl;
    else cout<<"not found" <<endl;

    return 0;

}

//lower_bound
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> v = {1,3,5,8,9,12};
    vector <int>::iterator it=lower_bound(v.begin(),v.end(),6);

    cout<<*it<<endl;
    cout<<distance(v.begin(),it)<<endl;
    cout<<(it-v.begin())<<endl;

    if(it==v.end()){
        cout<<"not found"<<endl;
    }
    else{
        cout<<"found"<<endl;
    }

    return 0;

}

//upper_bound
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> v = {1,3,7,5,8,9,12};
    vector <int>::iterator it=upper_bound(v.begin(),v.end(),8);

    cout<<*it<<endl;
    cout<<distance(v.begin(),it)<<endl;
    cout<<(it-v.begin())<<endl;

    cout<<((it==v.end())? "Not found" : to_string(*it))<<endl;

    return 0;

}


//with set
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> v = {1,3,5,8,9,12};
    set <int> s(v.begin(),v.end());
    auto it=s.lower_bound(8);
    cout<<*it<<endl;


    if(it==s.end()){
        cout<<"not found"<<endl;
    }
    else{
        cout<<"found"<<endl;
    }

    return 0;

}



