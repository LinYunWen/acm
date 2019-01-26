/*using SPFA to find out the shortest path
 *on given graph.
 */

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
#define INF 9999999

int node_num,edge_num,start_node,end_node;
int dis[20010];
int inqueue[20010];
int counter[20010];

struct Edge{
    int to;
    int length;
};

int main()
{
    int case_num;
    scanf("%d",&case_num);

    int case_count=1;
    while(case_num--)
    {
        scanf("%d %d %d %d",&node_num,&edge_num,&start_node,&end_node);

        //get input
        vector<Edge>adj[20010];
        int a,b,len;
        for(int i=0;i<edge_num;++i){
            scanf("%d %d %d",&a,&b,&len);
            adj[a].push_back({b,len});
            adj[b].push_back({a,len});
        }

        //SPFA
        queue<int>qu;
        bool negative_cycle = false;
        for(int i=0;i<node_num;++i){
            dis[i] = INF;
            inqueue[i] = false;
            counter[i] = 0;
        }

        dis[start_node] = 0;
        inqueue[start_node] = true;
        qu.push(start_node);
        while(!qu.empty())
        {
            int now = qu.front();
            inqueue[now] = false;
            qu.pop();
            //for(vector<Edge>::iterator i=adj[now].begin();i!=adj[now].end();++i){
            for(auto &i : adj[now]){
                if(dis[now]+i.length<dis[i.to]){
                    dis[i.to] = dis[now]+i.length;

                    if(!inqueue[i.to]){
                        qu.push(i.to);
                        inqueue[i.to] = true;
                        counter[i.to]++;
                        if(counter[i.to]>=node_num)
                            negative_cycle = true;
                    }
                }
            }
        }

        printf("Case #%d: ",case_count++);
        if(negative_cycle || dis[end_node]==INF)
            printf("unreachable\n");
        else
            printf("%d\n",dis[end_node]);

    }
    return 0;
}
