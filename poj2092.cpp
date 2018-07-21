// http://bailian.openjudge.cn/practice/2092/
// Grandpa is Famous
// 据说是排序？懒得写排序，反正数据量很小，就直接统计了。
#include <iostream>
#include <cstring>
using namespace std;
int Cnt[10005];
int N,M;
int main()
{
    while(cin>>N>>M){
        if(N==0&&M==0) break;
        memset(Cnt,0,sizeof(Cnt));
        int cnt_num=N*M;
        //cout<<"cnt_num "<<cnt_num<<endl;
        int max_time1=0;
        int max_time2=0;
        int temp_num=0;
        for(int i=0;i<cnt_num;i++){
            cin>>temp_num;
            Cnt[temp_num]++;
            if(Cnt[temp_num]>=max_time1) {
                max_time1 = Cnt[temp_num];
            }
        }
        for(int i=1;i<=10000;i++){
            if(Cnt[i]>max_time2&&Cnt[i]<max_time1){
                max_time2=Cnt[i];
            }
        }
        for(int i=1;i<=10000;i++){
            if(Cnt[i]==max_time2){
                cout<<i<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}
