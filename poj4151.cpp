// poj4151电影节
//贪心就好了，按电影结束时间排序即可。

#include <iostream>
#include <algorithm>
using namespace std;

struct Info{
    int Beg;
    int End;
}movie[1005];
int Num;
int MyCmp(Info i1,Info i2)
{
    if(i1.End<i2.End) return 1;
    else if(i1.End==i2.End&&i1.Beg>=i2.Beg) return 1;
    else return 0;
}
int main()
{
    while(cin>>Num){
        if(Num==0) break;
        for(int i=0;i<Num;i++){
            cin>>movie[i].Beg>>movie[i].End;
        }
        sort(movie,movie+Num,MyCmp);
        /*
        for(int i=0;i<Num;i++){
            cout<<movie[i].Beg<<' '<<movie[i].End<<endl;
        }
        */
        int Cnt=1;
        int lst_end=movie[0].End;
        for(int i=1;i<Num;i++){
            if(movie[i].Beg>=lst_end){
                lst_end=movie[i].End;
                Cnt++;
            }
        }
        cout<<Cnt<<endl;
    }


    return 0;
}
