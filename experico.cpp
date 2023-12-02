#include<bits/stdc++.h>
using namespace std;



int main()
{
    string str="add";
    string b="dddition";
    vector<string> strs={str,b,"bello"};
    sort(strs.begin(),strs.end()-1);
    for(auto i:strs)
    cout<<i<<" ";
    cout<<endl;
    cout<<str.substr(0,str.length()+100)<<endl;
    cout<<min(str,b);
    cout<<endl<<endl;

    //integer to array of digits present in the integer
    int* ptr1=new(nothrow) int[3]{4,5,6};
      for(int i=0;i<3;i++){
        cout<<*(ptr1+i)<<" ";
    }

    cout<<endl;
    int* ptr2=(int*)realloc(ptr1,5*sizeof(int));
    *(ptr2+3)=6;
    *(ptr2+4)=7;
    for(int i=0;i<5;i++){
        cout<<*(ptr2+i)<<" ";
    }
    free(ptr1);
    ptr1=nullptr;
    cout<<endl;
  //maximum number can be stored in int
    numeric_limits<int> k;
    cout<<k.max()<<endl;
    int m=k.max()+1;
    cout<<m<<endl;
    ///

    

    cout<<endl;
    return 0;
}