#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ans;
    cin>>ans;
    vector<int> arr;
    for(int i=0;i<ans.size();i++)
    {
        int num = ans[i] -49;
        if(num >=0 && num<=9)
        {
            arr.push_back(num);
        }
    }

    sort(arr.begin() ,arr.end());
    int j=0;
        for(int i=0;i<ans.size();i++)
    {
        int num = ans[i] -49;
        if(num >=0 && num<=9)
        {
            ans[i] = arr[j++]+49;
        }
    }
    cout<<ans<<endl;
}