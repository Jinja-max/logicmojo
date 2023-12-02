#include<bits/stdc++.h>
using namespace std;
//this is to find maximum odd number from given binary string
string maximumOddBinaryNumber(string& s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            while(s[count]!=0){
                count++;
            }
            if(count<i && s[i]=='1') {
                char t=s[i];
                s[i]=s[count];
                s[count]=t;
            }
        }
    
          char t=s[count-1];
                s[count-1]=s[n-1];
                s[n-1]=t;
        return s;
    }

int main()
{   string s="010";
    cout<<endl<<maximumOddBinaryNumber(s);
    cout<<endl;
    return 0;
}