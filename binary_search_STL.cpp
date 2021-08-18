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
