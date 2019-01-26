/*
 *problem gives you many different currency eschange
 *rate and we should find out is it possible to make 
 *money become more by some eschanging. It means is 
 *there any negative cycle.
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

double dis[101];
double R[101][101];
double C[101][101];
vector<int> adj[101];

int main()
{
    int N,line_num,dollar_num;
    double dollar;
    scanf("%d %d %d %lf",&N,&line_num,&dollar_num,&dollar);

    //initialize and get inputs
    memset(R,0,sizeof(R));
    memset(C,0,sizeof(C));
    int nodeA,nodeB;
    double Rab,Rba,Cab,Cba;
    for(int i=0;i<line_num;++i){
        scanf("%d %d %lf %lf %lf %lf",&nodeA,&nodeB,&Rab,&Cab,&Rba,&Cba);
        R[nodeA][nodeB] = Rab;
        R[nodeB][nodeA] = Rba;
        C[nodeA][nodeB] = Cab;
        C[nodeB][nodeA] = Cba;
        adj[nodeA].push_back(nodeB);
        adj[nodeB].push_back(nodeA);
    }

    //SPFA
    bool inqueue[101];
    int counter[101];
    queue<int>qu;
    for(int i=0;i<101;++i){
        dis[i] = 0;
        inqueue[i] = false;
        counter[i] = 0;
    }
    dis[dollar_num]=dollar;
    qu.push(dollar_num);
    inqueue[dollar_num]=true;

    while(!qu.empty())
    {
        int now = qu.front();
        qu.pop();
        inqueue[now]=false;

        for(int i=0;i<adj[now].size();++i){
            int next = adj[now][i];
            if((dis[now]-C[now][next])*R[now][next]>dis[next]){
                dis[next] = (dis[now]-C[now][next])*R[now][next];
                if(!inqueue[next]){
                    qu.push(next);
                    inqueue[next] = true;
                }
            }
        }
    }

    //print answer
    if(dis[dollar_num]>dollar)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
