/*using backtracking to solve given Sudoku
 *rows and cols sre range at 1~3
 */

#include <cstdio>
#include <cstring>

using namespace std;

int input[9][9];
int answer[9][9];
int width;
int num;
int breakpoint;
int temp_index;
int unassign[81][2];
int solve_flag;
int first=1;

int check(int t,int s,int temp_answer);

//bactracking
void Find_solution(int dimension)
{
    if(dimension==temp_index){
        if(first==0)
            printf("\n");
            //printf("Anum:%d\n",num);
        for(int i=0;i<width;i++){
            printf("%d",input[i][0]);
            for(int j=1;j<width;j++)
                printf(" %d",input[i][j]);
            printf("\n");
        }


        //scanf("%d",&breakpoint);
        solve_flag=1;
        return;
    }
    else{
            int t=unassign[dimension][0];
            int s=unassign[dimension][1];
            //printf("before %d\n",dimension);
            for(int i=1;i<width+1;i++){
            //for(int i=9;i>0;--i){
                if(check(t,s,i)==1){
                    input[t][s]=i;

                    Find_solution(dimension+1);

                    if(solve_flag==1)
                        return;

                    input[t][s]=0;

                }

            }

    }

    //printf("return\n");

    return;
}

int check(int t,int s,int temp_answer)
{
    //check rows
    for(int i=0;i<width;i++){
        if(input[i][s]==temp_answer)
            return -1;
    }

    //check cols
    for(int j=0;j<width;j++){
        if(input[t][j]==temp_answer)
            return -1;
    }

    //check blocks
    if(num==2)
    {
        int start_row=t-t%2;
        int start_col=s-s%2;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                if(input[start_row+i][start_col+j]==temp_answer)
                    return -1;
    }
    else if(num==3)
    {
        int start_row=t-t%3;
        int start_col=s-s%3;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(input[start_row+i][start_col+j]==temp_answer)
                    return -1;
    }

    return 1;
}

int main()
{
    while(true){
        num=0;
        if(scanf("%d",&num)==EOF)
            break;
        //printf("%d\n",num);

        if(num==0)
            continue;

        //deal with 1 
        if(num==1){
            if(first==0)
                printf("\n");
            printf("1\n");
            //printf("\n");
            continue;
            //printf("hello\n");
        }
        memset(input,-1,sizeof(input));
        memset(answer,-1,sizeof(answer));
        memset(unassign,-1,sizeof(unassign));
        temp_index=0;
        solve_flag=0;

        //scan input
        width=num*num;
        for(int i=0;i<width;i++)
            for(int j=0;j<width;j++){
                scanf("%d",&input[i][j]);
                if(input[i][j]==0){
                    unassign[temp_index][0]=i;
                    unassign[temp_index][1]=j;
                    temp_index++;
                }
            }

        Find_solution(0);

        //print if no solution
        if(solve_flag==0){
            if(first==0)
                printf("\n");
            printf("NO SOLUTION\n");
            //printf("\n");
        }
        first=0;
    }

    return 0;
}
