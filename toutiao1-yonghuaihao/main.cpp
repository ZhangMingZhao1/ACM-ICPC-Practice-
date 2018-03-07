#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[300005];
int main()
{
//   freopen("in.txt","r",stdin);
   int n;
   cin>>n;
   for(int i = 1; i <= n; i++) {
        cin>>a[i];
   }

   int t;
   cin>>t;
   for(int i = 0; i < t; i++) {
        int l,r,q;
        cin>>l>>r>>q;
        int sum = 0;
        for(int j = l; j<= r; j++) {
            if(a[j]== q)
                sum++;
        }
        cout<<sum<<endl;
   }
   return 0;
}
