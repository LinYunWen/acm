/*
 *It is a LCS problem and it will give us 
 *two articles to find out LCS in words
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string input1[110];
string input2[110];
int LCS[110][110];
int pre[110][110];
int index1,index2;
vector<string> solution;

int breakpoint;

void Find_LCS()
{
    for(int i=1;i<index1;i++){
        for(int j=1;j<index2;j++){
            if(input1[i]==input2[j]){
                LCS[i][j]=LCS[i-1][j-1]+1;
                pre[i][j]=0;
            }
            else{
                if(LCS[i-1][j]>=LCS[i][j-1]){
                    LCS[i][j]=LCS[i-1][j];
                    pre[i][j]=1;
                }
                else{
                    LCS[i][j]=LCS[i][j-1];
                    pre[i][j]=2;
                }
            }
        }
    }

    //get solution
    int i=index1-1;
    int j=index2-1;
    //while(true){
    while(i && j){
        if(pre[i][j]==0){
            solution.push_back(input1[i]);
            i--;j--;
        }
        else if(pre[i][j]==1)
            i--;
        else if(pre[i][j]==2)
            j--;
        else if(pre[i][j]<0)
        //else if(i && j)
            break;
    }

    //print solution
    cout << solution.back();
    solution.pop_back();
    while(!solution.empty()){
        cout << " " << solution.back();
        solution.pop_back();
    }

    printf("\n");

    return;
}

int main()
{
    index1=1;
    index2=1;
    char temp[30];
    int flag=0;

    while(cin >> input1[index1] && input1[index1]!="#"){
        index1++;
        while(cin >> input1[index1] && input1[index1]!="#")
            index1++;
        while(cin >> input2[index2] && input2[index2]!="#")
            index2++;

        memset(LCS,0,sizeof(LCS));
        memset(pre,-1,sizeof(pre));
        solution.clear();

        Find_LCS();

        index1=1;
        index2=1;

    }
    return 0;
}
