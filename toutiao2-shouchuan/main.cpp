//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//int mp[10005][55];
//
//int main()
//{
//    freopen("in.txt","r",stdin);
//    int n,m,c;
//    cin>>n>>m>>c;
//    for(int i = 1; i <= n; i++) {
//        int t;
//        cin>>t;
//        while(t--) {
//            int tmp;
//            cin>>tmp;
//            mp[tmp][i] = 1;
//        }
//    }
//    int ans = 0;
//    for(int i = 1; i <= c; i++) {//枚举颜色
////        for(int k = 1; k <= m; j++) {
////            if(mp[i][n]==1&&mp[i][1]==1)
////                ans++;
//        for(int j = 1; j <= n; j++) {//枚举串珠标号
//            int flag = 1;
//            for(int d = 1; d<=m; d++)
//            for(int k = 0; k <= m-2; k++ ) {
//                int cur;//当前串珠标号
//                int pre;//前一个串珠编号
//                if(j+k+1>n) {
//                    cur = j+k+1-n;
//                }else {
//                    cur = j+k+1;
//                }
//                if(cur-1<1) {
//                    pre = 6-cur;
//                }else {
//                    pre = cur-1;
//                }
//                if(mp[i][pre]==1&&mp[i][cur]==1) {
//                    continue;
//                }else {
//                    flag = 0;
//                    break;
//                }
//            }
//            if(flag)
//                ans++;
//
//        }
//    }
//    cout<<ans<<endl;
//}

//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//int a[10005][55];
//int b[10005];
//
//int main()
//{
//    freopen("in.txt","r",stdin);
//    int n,m,c,num,color,cnt=0;
//    cin >> n >> m >> c;
//    for(int i=1;i<=n;i++)
//    {
//        cin >> num;
//        for(int j=1;j<=num;j++)
//        {
//            cin >> color;
//            a[color][i] = 1;
//        }
//    }
//
//    for(int i=1;i<=c;i++)//遍历颜色
//    {
//        int k=0;
//        for(int j=1;j<=n;j++)//遍历珠子编号
//        {
//            if(a[i][j] == 1)
//                b[k++] = j;
//        }
//
//        if(k != 1)
//        {
//            if(b[0]==1&&b[k-1]==n&&m==2) cnt++;
//            for(int i=0;i<k-1;i++)
//            {
//                if(m > b[i+1]-b[i])
//                {
//                    cnt++;
//                    break;
//                }
//
//            }
//
//        }
//
//    }
//    cout << cnt <<endl;
//    return 0;
//}
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

bool color[55];
vector<int> V[10005];

int main()
{
    freopen("in.txt","r",stdin);
    int n, m, c, num, x;
    while(cin >> n >> m >> c)
    {
        memset(color, 0, sizeof(color));
        for(int i = 0; i < n; ++i)
            V[i].clear();
        for(int i = 0; i < n; ++i)
        {
            cin >> num;
            while(num--)
            {
                cin >> x;
                V[i].push_back(x);
            }
        }
        if(m==1)
        {
            cout << 0 << endl;
            continue;
        }
        if(m>=n)
        {
            cout << c << endl;
            continue;
        }

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(ans==c)
                break;
            for(int j = 0; j < V[i].size(); ++j)
            {
                if(color[V[i][j]])
                    continue;
                int tmp = 1;
                int k = i+1;
                while(tmp<m)
                {
                    if(k==n)
                        k = 0;
                    for(int l = 0; l < V[k].size(); ++l)
                        if(V[k][l]==V[i][j] && !color[V[i][j]])
                        {
                            color[V[i][j]] = true;
                            ans++;
                        }
                    k++;
                    tmp++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
