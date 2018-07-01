#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int Cnt;
int M,N;
void cnt_method(int index,int last_energy,int sum_energy);
int main()
{
    int t=0;
    cin>>t;
    while(t--){
    Cnt=0;
    cin>>M>>N;
    cnt_method(1,0,0);
    cout<<Cnt<<endl;
    }
    return 0;
}
void cnt_method(int index,int last_energy,int sum_energy)
{
    if(M-sum_energy<last_energy) return;//剪纸
    if(index==N){
        ++Cnt;
        return;
    }
    for(int temp_energy=last_energy;temp_energy<=M-sum_energy;temp_energy++){
        cnt_method(index+1,temp_energy,sum_energy+temp_energy);
    }

}
