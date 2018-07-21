// http://acm.pku.edu.cn/JudgeOnline/problem?id=2377
// poj 2377 Bad Cowtractors
// 最大生成树，用Kruskal构建最大边即可。
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct Edge{
    int From;
    int To;
    int Cost;
    friend bool operator<(const Edge& e1,const Edge& e2){
        return e1.Cost>e2.Cost;
    }
}edge[20005];
int Father[1005];
int N,M;
void Kruskal();
int FindFather(int i);
int main()
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d %d %d",&edge[i].From,&edge[i].To,&edge[i].Cost);
    }
    for(int i=1;i<=N;i++){
        Father[i]=i;
    }

    sort(edge,edge+M);
    Kruskal();
    return 0;
}
int FindFather(int i)
{
    if(Father[i]==i) return i;
    int temp_fat=Father[i];
    Father[i]=FindFather(temp_fat);
    return Father[i];
}
void Kruskal()
{
    int Point=0;
    int Cnt=N;
    int tot_cost=0;
    while(Cnt>1&&Point<M){
        int From=edge[Point].From;
        int To=edge[Point].To;
        int father1=FindFather(From);
        int father2=FindFather(To);
        if(father1==father2){
            ++Point;
            continue;
        }
        else{
            Father[father1]=father2;
            tot_cost+=edge[Point].Cost;
            ++Point;
            --Cnt;
        }
    }
    if(Point>=M&&Cnt>1) cout<<"-1"<<endl;
    else cout<<tot_cost<<endl;
}
