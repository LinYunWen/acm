/*
 *just to count the number of appearance of
 *every input string, then culculate the 
 *percentages
 */

#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    int case_num=0;
    scanf("%d",&case_num);
    map<string,int> table;
    string input;

    //discard the useless line
    getline(cin,input);
    getline(cin,input);

    //get input
    for(int i=case_num;i>0;--i)
    {
        int total=0;
        while(getline(cin,input)){
            if(input.compare("")==0)
                break;

            if(table.find(input)!=table.end()){
                table[input]++;
                total++;
            }
            else{
                table[input]=1;
                total++;
            }
        }

        //print the percentages
        for(map<string,int>::iterator it=table.begin();it!=table.end();++it){
            int temp = it->second;
            cout << it->first << " " << fixed << setprecision(4) << (temp/(double)total)*100 << endl;
        }
        if(i>1)
            cout << endl;
        table.clear();
    }
    return 0;
}
