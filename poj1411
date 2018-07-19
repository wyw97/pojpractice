# Calling Extraterrestrial Intelligence Again
# 简单枚举即可
# http://poj.org/problem?id=1411
# poj上sqrt很奇怪啊，ce了好几次，没啥好说的
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int Prime[10000]={2};
int cnt_Prime=1;
int m,a,b;
void cal_prime();
bool is_prime(int i);
int binary_search(int num);
int main()
{
    cal_prime();
    while(scanf("%d %d %d",&m,&a,&b)){
        if(!m&&!a&&!b) break;
        int max_mul=0;
        int final_p=0,final_q=0;
        int upper_bound=(int)sqrt((float)m);
        int pos1=binary_search(upper_bound);
        for(int t1=pos1;t1>=0;--t1){
            int pos2=min(binary_search(m/Prime[t1]),binary_search(Prime[t1]*b/a));
            if(max_mul<Prime[t1]*Prime[pos2]){
                max_mul=Prime[t1]*Prime[pos2];
                final_p=Prime[t1];
                final_q=Prime[pos2];
            }
        }
        cout<<final_p<<' '<<final_q<<endl;
    }
    return 0;
}
int binary_search(int num)
{
    int l=0,r=cnt_Prime-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(Prime[mid]>num){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }

    return r;
}
bool is_prime(int i)
{
    int max_poss=(int)sqrt((float)i);
    for(int t=0;t<cnt_Prime&&Prime[t]<=max_poss;t++){
        if(i%Prime[t]==0) return false;
    }
    return true;
}
void cal_prime()
{
    for(int t=3;t<=100000;t+=2){
        if(is_prime(t)){
            Prime[cnt_Prime]=t;
            cnt_Prime++;
        }
    }
}
