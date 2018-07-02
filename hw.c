/*
poj 4122 切割回文
主要是利用动态规划判定是否为回文，然后利用一维数据判断即可。
Openjudge：4096kb 57ms
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int T;
char Str[1005];
int len_str;
int is_hw[1005][1005];
int cnt[1005];
int main()
{
    cin>>T;
    while(T--){
        memset(Str,0,sizeof(Str));
        memset(cnt,0,sizeof(cnt));
        memset(is_hw,0,sizeof(is_hw));
        cin>>Str;
        len_str=strlen(Str);
        for(int len=0;len<len_str;len++){
            for(int i=0;i<len_str;i++){
                if(i+len>=len_str) break;
                int j=i+len;
                if(Str[i]==Str[j]){
                    if(len<2){
                        is_hw[i][j]=1;
                    }
                    else{
                       if(is_hw[i+1][j-1]) {
                          is_hw[i][j] = 1;
                        }
                    }
                }
            }
        }
         for(int i=1;i<len_str;i++){
            cnt[i]=i;
            if(is_hw[0][i]){
                cnt[i]=0;
            }
            else{
                for(int j=1;j<=i;j++){
                 if(is_hw[j][i])
                     cnt[i]=min(cnt[i],1+cnt[j-1]);
                }
            }
        }

         cout<<cnt[len_str-1]<<endl;
    }
    return 0;
}
