/*
 *using KMP to find the length of repeat substing 
 *in given power string
 */

#include <cstdio>
#include <cstring>

using namespace std;

char input[85];
int len;

int check(int sublen)
{
    //do KMP
    for(int i=sublen;i+sublen<=len;i+=sublen){
        int temp = i;
        for(int j=0;j<sublen;++j){
            //printf("%d input:%c input_compare:%c\n",i,input[temp+j],input[(temp+j)%sublen]);
            if(input[temp+j]!=input[(temp+j)%sublen]){
                return -1;
            }
        }
    }

    return 1;
}

int main()
{
    int first=1;
    int case_num=0;
    scanf("%d",&case_num);

    while(case_num>0)
    {
        scanf("%s",input);

        //deal with input string with a character
        len=strlen(input);
        if(len==1){
            if(first==1){
                    printf("1\n");
                    first=0;
                }
                else
                    printf("\n1\n");
            case_num--;
            continue;
        }

        for(int i=1;i<=len;++i){
            int check_num = check(i);
            //printf("check: %d\n",check_num);
            if(len%i==0 && check_num==1){
                if(first==1){
                    printf("%d\n",i);
                    first=0;
                }
                else
                    printf("\n%d\n",i);
                break;
            }
        }
        case_num--;
    }

    return 0;
}
