#include <iostream>
using namespace std;
#define n 20
class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front=-1;
        back=-1;

    }
    void push(int x){
        if(back==n-1){
            cout<<"Queue overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;
        if(front==-1){
            front++;

        }

    }
    void pop(){
        if(front==-1 || front>back){
            cout<<"no elemnts present in queue"<<endl;
            return;

        }
        front++;

        
         
    }
};

int main()
{

    return 0;
}
