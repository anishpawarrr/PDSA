// mplement Circular Queue using Array. Perform following operations on it.
// a) Insertion (Enqueue)
// b) Deletion (Dequeue)
// c) Display
// (Note: Handle queue full condition by considering a fixed size of a queue.)

#include<bits/stdc++.h>
using namespace std;
#define maxsize 6

class cqueue{
    public:
    // int s = maxsize;
    int f=-1,r=-1;
    int arr[maxsize];
    bool isempty(){
        if(f==-1){
            return true;
        }else{
            return false;
        }
    }
    bool isfull(){
        if((r+1)%maxsize == f){
            return true;
        }else{
            return false;
        }
    }
    void push(int i){
        if(isempty()){
            f++;
            r++;
            arr[f] = i;
        }else{
            if(!isfull()){
                r = (r+1)%maxsize;
                arr[r] = i;
            }else{
                cout<<"Array is already full!\n";
            }
        }
    }
    void pop(){
        if(!isempty()){
            f = (f+1)%maxsize;
            if(f==(r+1)%maxsize){
                f=r=-1;
            }
        }
    }
    void destroy(){
        f=r=-1;
    }
    void print(){
        int x = f;
        if(!isempty()){
            do{
                cout<<arr[x]<<" ";
                x = (x+1)%maxsize;
            }while(x!= (r+1)%maxsize);
            // cout<<arr[x]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    cqueue c;
    int d=1;
    while(d!=5){
        cout<<"Enter\n1. to insert element in QUEUE\n2. to delete element from QUEUE\n3. to destroy QUEUE\n4. to print queue\n5. to exit program\n";
        cin>>d;
        while(d<1 || d>5){
            cout<<"Enter valid number\n";
            cin>>d;
        }
        if(d==1){
            int i;
            cout<<"Enter the number you want insert\n";
            cin>>i;
            c.push(i);
        }else if(d==2){
            c.pop();
        }else if(d==3){
            c.destroy();
        }else if(d==4){
            c.print();
        }else if(d==5){
            break;
        }
    }
    // cout<<c.isempty()<<"\n";
    // c.push(1);
    // c.push(2);
    // c.push(3);
    // c.pop();
    // c.push(4);
    // c.push(5);
    // cout<<c.isempty()<<"\n";
    // c.push(6);
    // c.push(7);
    // cout<<c.isfull()<<"\n";
    // c.print();

    return 0;
}