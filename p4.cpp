// uct an Expression Tree from postfix and prefix expression. Perform recursive and non recursive In-order, pre-order and post-order traversals.

#include<bits/stdc++.h>
using namespace std;

template<class T>



class Stack{
public:
    struct node
    {
        T data;
        node *next;
    };
    node *top = new node();
    Stack(){
        top = NULL;
    }
    bool isempty(){
        if(top==NULL){
            return true;
        }else{
            return false;
        }
    }
    void push(T d){
        node *temp = new node();
        temp->data = d;
        temp->next = top;
        top = temp;
    }
    void pop(){
        if(!isempty()){
            top = top->next;
        }
    }
    void print(){
        node *temp = new node;
        temp = top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    T toop(){
        return this->top->data;
    }
};
bool isope(char c){
    if(c=='^' || c=='*' || c=='-' || c=='+' || c=='/'){
        return true;
    }else{
        return false;
    }
}
int decide(char c){
    if(c=='^'){
        return 3;
    }else if(c=='*' || c=='/'){
        return 2;
    }else if(c=='+' || c=='-'){
        return 1;
    }else{
        return -1;
    }
}

string intopost(string s){
    Stack<char> st;
    string ans = "";
    for(int i=0;i<s.length();i++){
        if(!isope(s[i]) && s[i] != '(' && s[i] != ')'){
            ans.push_back(s[i]);
        }else if(s[i] == '('){
            st.push(s[i]);
        }else if(s[i] == ')'){
            while(st.toop() != '('){
                ans.push_back(st.toop());
                st.pop();
            }
            st.pop();
        }else{
            while(!st.isempty() && decide(s[i]) <= decide(st.toop())){
                ans.push_back(st.toop());
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.isempty()){
        ans.push_back(st.toop());
        st.pop();
    }
    return ans;
}
template <class Y>
class node{
    public:
    Y data;
    node *left, *right;
    node(){
        data = NULL;
        left = right = NULL;
    }
    node(Y d){
        data = d;
        left = right = NULL;
    }
};

node<char> *rootpost(string s){
    string post = s;
    // post = intopost(s);
    cout<<post<<endl;
    Stack<node<char>*> st;
    for(char c:post){
        if(!isope(c)){
            node<char> *temp = new node<char>(c);
            st.push(temp);
        }else{
            node<char> *temp = new node<char>(c);
            node<char> *rightt = st.toop();
            st.pop();
            node<char> *leftt = st.toop();
            st.pop();
            temp->left = leftt;
            temp->right = rightt;
            st.push(temp);
        }
    }
    return st.toop();

}

void printinfix(node<char> *root){
    if(root == NULL){
        return;
    }else{
        printinfix(root->left);
        cout<<root->data<<" ";
        printinfix(root->right);
    }
}
node<char> *mirror(node<char> *rt){
    if(rt==NULL){
        return NULL;
    }
    node<char> *temp = new node<char>(rt->data);
    temp->left = mirror(rt->right);
    temp->right = mirror(rt->left);
    return temp;
}

node<char> *rootpre(string s){
    reverse(s.begin(),s.end());
    node<char> *rt = rootpost(s);
    rt = mirror(rt);
    return rt;
}

int main(){
    string in,post;
    in = "*+abc";
    node<char> *rt = rootpre(in);
    // rt = mirror(rt);
    printinfix(rt);
    cout<<endl;
    return 0;
}