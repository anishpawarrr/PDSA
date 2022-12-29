// Implement stack as an abstract data type using singly linked list and use this ADT for conversion of 
// infix expression to postfix, prefix and evaluation of postfix and prefix expression.

#include <bits/stdc++.h>
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

string intopre(string s){
    reverse(s.begin(), s.end());
    int i=0;
    while(i<s.length()){
        if(s[i] == ')'){
            s[i] = '(';
            i++;
        }else if(s[i] == '('){
            s[i] = ')';
            i++;
        }
        i++;
    }
    string ans = intopost(s);
    reverse(ans.begin(),ans.end());
    return ans;
}

double posteva(string s){
    map<char, double> m;
    string ans = intopost(s);
    // ans = s;
    for(char c:ans){
        if(!isope(c)){
            double d;
            cout<<"Enter value of "<<c<<endl;
            cin>>d;
            m[c] = d;
        }
    }
    Stack<double> d;
    for(char c:ans){
        if(!isope(c)){
            d.push(m[c]);
        }else{
            double x,y,z;
            x = d.toop();
            d.pop();
            y = d.toop();
            d.pop();
            if(c=='+'){
                z = x + y;
            }
            else if(c=='-'){
                z = y-x;
            }
            else if(c=='/'){
                z = y/x;
            }
            else if(c=='*'){
                z = x * y;
            }
            else if(c=='^'){
                z = pow(y,x);
            }
            d.push(z);
        }
    }
    return d.toop();
}

double ineva(string s){
}

int main(){
    // Stack<int> s;
    string s = "a+b^d";
    double d = posteva(s);
    cout<<d<<endl;
    return 0;
}