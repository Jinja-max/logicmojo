#include<bits/stdc++.h>
using namespace std;

  int sizeofarr=1;
    int* intRevToarr(int k){
        int* ptr=new(nothrow) int{k%10};
        k=k/10;
        while(k!=0){
            int r=k%10;
            sizeofarr++;
            int* temp;
            temp=ptr;
            ptr=(int*)realloc(ptr,sizeofarr*sizeof(int));
            *(ptr+sizeofarr-1)=r;
            free(temp);
            temp=nullptr;
            k=k/10;
        }
        return ptr;
    }

    int arrToint(int* ptr,int size){
        int num=0;
        for(int i=size-1;i>=0;i--){
            num=num*10+*(ptr+i);
        }
        numeric_limits<int> limit;
        if(num<=limit.max()) return num;
        else return -1;
    }

    int nextGreaterElement(int n) {
        int* ptr=intRevToarr(n);
        for(int i=0;i<sizeofarr-1;i++){
            if(*(ptr+i+1)<*(ptr+i)){
                swap(*(ptr+i+1),*(ptr+i));
                return arrToint(ptr,sizeofarr);
            }
        }
    return -1;
    } 


int main()
{   int k=4576;
    cout<<nextGreaterElement(k);

    cout<<endl;
    return 0;
}