// Represent a graph of your college campus using adjacency list /adjacency matrix. Nodes should 
// represent the various departments/institutes and links should represent the distance between them. 
// Find minimum spanning tree
// a) Using Kruskal’s algorithm.
// b) Using Prim’s algorithm.



#include <bits/stdc++.h>
using namespace std;
#define v 5

int arr[v];
int find(int i){
    while(i!=arr[i])
        i = arr[i];
    return i;
}

void uni(int i,int j){
    int a = find(i);
    int b = find(j);
    arr[a] = b;
}

void krus(int cost[][v]){
    int minc = 0, ed = 0;
    for(int i=0;i<v;i++){
        arr[i] = i;
    }
    while(ed<v-1){
        int min = 999999, a = -1, b=-1;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(find(a) != find(b) && cost[i][j] < min){
                min = cost[i][j];
                a = i;
                b=j;
            }
        }
    }
    uni(a,b);
    ed++;
    minc+=min;
    }
}

class graph{
    public:
    vector<vector<int>> mat;
    graph(int n){
        vector<int> x(n,0);
        // vector<vector<int>> mat(n,x);
        for(int i=0;i<n;i++){
            mat.push_back(x);
        }
    }
    void connect(int i, int j, int w){
        mat[i][j] = mat[j][i] = w;
    }
    void discon(int i, int j){
        mat[i][j] = mat[j][i] = 0;
    }

    vector<vector<int>> prim(int m){
        vector<int> x(mat.size(),0);
        vector<vector<int>> sptr(mat.size(), x);
        vector<bool> visited(mat.size(), false);
        visited[m] = true;
        // int i = m;
        int edgeno = 0;
        while(edgeno < mat.size()-1){
            int min = 999999999;
            int x = 0, y = 0;
            for(int i=0;i<mat.size();i++){
                if(visited[i]){
                    for(int j=0;j<mat.size();j++){
                        if(!visited[j] && mat[i][j]){
                            if(min > mat[i][j]){
                                min = mat[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
                // i = (i+1)%mat.size();
            }
            sptr[x][y] = sptr[y][x] = 1;
            visited[y] = true;
            edgeno++;
        }
        return sptr;
    }

    void print(vector<vector<int>> v){
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};


int main(){
    vector<vector<int>> sptr;
    graph g(5);
    g.connect(0,4,4);
    g.connect(0,3,3);
    g.connect(3,1,1);
    g.connect(3,2,4);
    g.connect(1,2,2);
    g.connect(2,4,5);
    // sptr = g.prim(0);
    // cout<<sptr[0][0]<<"\n"

    g.print(g.prim(2));

    return 0;
}
