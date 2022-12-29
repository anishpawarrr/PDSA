// Implement binary search tree and perform following operations:
// a) Insert (Handle insertion of duplicate entry)..
// b) Delete
// c) Search..
// d) Display tree (Traversal)..
// e) Display - Depth of tree..
// f) Display - Mirror image..
// g) Create a copy..
// h) Display all parent nodes with their child nodes..
// i) Display leaf nodes..
// j) Display tree level wise
// (Note: Insertion, Deletion, Search and Traversal are compulsory, from rest of operations, perform 
// Any three)
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;
    bool th=false;
    node(int d){
        data = d;
        left = right = NULL;
    }
    node(){
        data = 0;
        left = right = NULL;
    }
};

class BST{
    public:
    BST(){
        root = NULL;
    }
    node *root = NULL;
    bool isempty(){
        if(root == NULL){
            return true;
        }else{
            return false;
        }
    }
    void insert(int i, node *rt){
        if(isempty()){
            root = new node(i);
        }else{
            if(i > rt->data){
                if(rt->right == NULL){
                    node *temp = new node(i);
                    rt->right = temp;
                }else{
                    insert(i,rt->right);
                }
            }else{
                if(rt->left == NULL){
                    node *temp = new node(i);
                    rt->left = temp;
                }else{
                    insert(i,rt->left);
                }
            }
        }
    }

    bool search(int i, node *rt){
        if(rt == NULL){
            return false;
        }else if(rt->data == i){
            return true;
        }else if(i > rt->data){
            return search(i, rt->right);
        }else{
            return search(i, rt->left);
        }
    }

    node *copy(node *rt){
        if(rt == NULL){
            return NULL;
        }else{
            node *temp = new node(rt->data);
            temp->left = copy(rt->left);
            temp->right = copy(rt->right);
            return temp;
        }
    }

    node *mirror(node *rt){
        if(rt == NULL){
            return NULL;
        }else{
            node *temp = new node(rt->data);
            temp->left = mirror(rt->right);
            temp->right = mirror(rt->left);
            return temp;
        }
    }

    void inorder(node *rt){
        if(rt == NULL){
            return;
        }else{
            inorder(rt->left);
            cout<<rt->data<<" ";
            inorder(rt->right);
        }
    }

    int depth(node *rt){
        if(rt == NULL){
            return 0;
        }else{
            int ld = depth(rt->left);
            int rd = depth(rt->right);
            if(ld>rd){
                return ld+1;
            }else{
                return rd+1;
            }
        }
    }

    void parentwchild(node *rt){
        if(rt == NULL){
            return;
        }else{
            cout<<"Parent -> "<<rt->data<<" ";
            if(rt->left){
                cout<<"Left child -> "<<(rt->left)->data<<" ";
            }
            if(rt->right){
                cout<<"Right child -> "<<(rt->right)->data<<" ";
            }
            cout<<endl;
        }
        parentwchild(rt->left);
        parentwchild(rt->right);
    }

    void leafnode(node *rt){
        if(rt == NULL){
            return;
        }else{
            if(!rt->left && !rt->right){
                cout<<rt->data<<" "; 
            }
            leafnode(rt->left);
            leafnode(rt->right);
        }
    }

    node *suc(node *rt){
        node *cur = rt;
        while(cur && cur->left){
            cur = cur->left;
        }
        return cur;
    }

    node *del(int d, node *rt){
        if(d < rt->data){
            rt->left = del(d,rt->left);
        }else if(d>rt->data){
            rt->right = del(d,rt->right);
        }else{
            if(rt->left == NULL){
                node *temp = rt->right;
                free(rt);
                return temp;
            }else if(rt->right == NULL){
                node *temp = rt->left;
                free(rt);
                return temp;
            }
            node *temp = suc(rt->right);
            rt->data = temp->data;
            rt->right = del(temp->data ,rt->right);
        }
        return rt;
    }
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

};


int main(){
    int d;
    BST b;
    int a[] = {8,6,7,4,3};
    for(int i:a){
        b.insert(i,b.root);
    }
    node *cp = b.copy(b.root);
    b.convert(cp);
    b.traverse(cp);
    cout<<endl;
    b.insert(5,b.root);
    cp = b.copy(b.root);
    b.convert(cp);
    b.traverse(cp);

    // b.del(5,b.root);
    // b.inorder(b.root);
    // while(d!=9){
    //     cout<<"1-> insert\n2 -> copy & dis\n3 -> mirror & dis \n4 -> dis\n5 -> dis depth\n6 -> par w/ child\n7 -> dis leaf\n8 -> search\n9 to exit\n10 to del\n";
    //     cin>>d;
    //     if(d==1){
    //         int i;
    //         cout<<"Enter int -> ";
    //         cin>>i;
    //         b.insert(i, b.root);
    //     }else if(d==2){
    //         node *cp = b.copy(b.root);
    //         b.inorder(cp);
    //         cout<<endl;
    //     }else if(d==3){
    //         node *cp = b.mirror(b.root);
    //         b.inorder(cp);
    //         cout<<endl;
    //     }else if(d==4){
    //         b.inorder(b.root);
    //         cout<<endl;
    //     }else if(d==5){
    //         cout<<"Depth -> "<<b.depth(b.root)<<endl;
    //     }else if(d==6){
    //         b.parentwchild(b.root);
    //         cout<<endl;
    //     }else if(d==7){
    //         b.leafnode(b.root);
    //         cout<<endl;
    //     }else if(d==8){
    //         int s;
    //         cout<<"Enter ele to search -> ";
    //         cin>>s;
    //         bool f = b.search(s, b.root);
    //         cout<<"Status of "<<s<<" -> "<<f<<endl;
    //     }else if(d==9){
    //         break;
    //     }else if(d==10){
    //         int d;
    //         cout<<"Enter ele to del\n";
    //         cin>>d;
    //         b.del(d,b.root);
    //     }
    // }
    return 0;
}