// Implement In-order Threaded Binary Tree and traverse it in In-order and Pre-order.
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    bool th = false;
    node *left = NULL, *right = NULL;
    node(int d){
        data = d;
        th = false;
    }
};

node *lefmost(node *rt){
    node* temp = rt;
    while(temp && temp->left){
        temp = temp->left;
    }
    return temp;
}

void populatenext(node* cur, node *&prev){
    if(!cur){
        return;
    }
    populatenext(cur->left, prev);
    if(prev && !prev->right){
        prev->right = cur;
        prev->th = true;
    }
    prev = cur;
    populatenext(cur->right,prev);
}

void convert(node *rt){
    node *prev = NULL;
    populatenext(rt,prev);
}

void traverse(node *rt){
    if(!rt){
        return;
    }
    node *cur = lefmost(rt);
    while(cur){
        cout<<cur->data<<" ";
        if(cur->th){
            cur = cur->right;
        }else{
            cur = lefmost(cur->right);
        }
    }
}

int main(){

    return 0;
}