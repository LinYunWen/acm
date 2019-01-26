/*
 *to find repeat substrings which is the most
 *times of appearance in given string
 */


#include <cstdio>
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num=0;
    string input;
    map<string,int> table;
    while(cin >> num >> input)
    {
        //cout << input <<endl;
        string temp_answer;
        int max_num=0;
        
        //get every substring
        for(int i=0;i<=input.length()-num;++i){
            string temp = input.substr(i,num);
            //cout << temp << endl;
            if(table.find(temp)!=table.end()){
                table[temp]++;
                //cout << temp << endl;
                if(max_num<table[temp]){
                    max_num = table[temp];
                    temp_answer = temp;
                }
            }
            else{
                //cout << "false: " << temp << endl;
                table[temp]=1;
            }
        }
        //print answer
        cout << temp_answer << endl;
        table.clear();
    }
    return 0;
}
