// Consider a student database of SEIT class (at least 15 records). Database contains different fields of 
// every student like Roll No, Name and SGPA.(array of structure)
// a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use 
// Bubble Sort)
// b) Arrange list of students alphabetically. (Use Insertion sort)
// c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
// d) Search students according to SGPA. If more than one student having same SGPA, then print list 
// of all students having same SGPA.
// e) Search a particular student according to name using binary search without recursion. (all the 
// student records having the presence of search key should be displayed)
// (Note: Implement either Bubble sort or Insertion Sort.)

#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    int rollno;
    float sgpa;
    string name;
    student(){
        rollno = 0;
        sgpa = 0;
        name = "NULL";
    }
    student takeinput(){
        student v;
        cout<<". Enter name of Student\n";
        cin>>v.name;
        cout<<". Enter roll number of Student\n";
        cin>>v.rollno;
        cout<<". Enter sgpa of Student\n";
        cin>>v.sgpa;
        return v;
    }
    void display(student s){
        cout<<s.rollno<<"\t"<<s.name<<"\t"<<s.sgpa<<endl;
    }
    void display(vector<student> s){
        cout<<"Roll no. \t\tName \t\tSGPA"<<endl;
        for(int i=0;i<s.size();i++){
            cout<<s[i].rollno<<"\t"<<s[i].name<<"\t"<<s[i].sgpa<<endl;
        }
        cout<<endl;
    }
    void display(student s[], int n){
        cout<<"Roll no. \tName \tSGPA"<<endl;
        for(int i=0;i<n;i++){
            cout<<s[i].rollno<<"\t\t"<<s[i].name<<"\t\t"<<s[i].sgpa<<endl;
        }
        cout<<endl;
    }
    void rollasc(vector<student> &v){
        for(int i=0;i<v.size()-1;i++){
            for(int j=0;j<v.size()-1-i;j++){
                if(v[j].rollno > v[j+1].rollno){
                    swap(v[j], v[j+1]);
                }
            }
        }
    }
    void namasc(vector<student> &v){
        int i,j;
        for(i=1;i<v.size();i++){
            j=i-1;
            student temp = v[i];
            while(j>=0 && v[j].name > temp.name){
                // swap(v[j], v[j+1]);
                v[j+1] = v[j];
                j--;
            }
            v[j+1] = temp;
        }
    }
    void sgqs(vector<student> &v, int l, int r){
        int m = partition(v,l,r);
        sgqs(v,l,m-1);
        sgqs(v,m+1,r);
    }
    int partition(vector<student> &v, int l, int r){
        student x = v[r];
        int i,j;
        j = l;
        i=j-1;
        for(j=l;j<r;j++){
            if(v[j].rollno <= x.rollno){
                i++;
                swap(v[i], v[j]);
            }
        }
        swap(v[i+1], v[r]);
        return i+1;
    }

};

int main(){
    // cout<<"Hello world\n";
    student s;
    vector<student> st(5,s);
    for(int i=0;i<5;i++){
        st[i] = st[i].takeinput();
    }
    st[0].display(st);
    // st[0].rollasc(st);
    // st[0].display(st);
    st[0].sgqs(st,0,4);
    st[0].display(st);
    
    return 0;
}