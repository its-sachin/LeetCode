#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    
bool tryit(vector<vector<char> > &A, unordered_map<int,bool> rows[9], unordered_map<int,bool> cols[9], unordered_map<int,bool> block[3][3]){

    for (int i = 0; i < 9; i++){
    
        for (int j = 0; j < 9; j++){
        
            if(A[i][j]=='.'){
                vector<int> v;
                for(auto k: rows[i]){
                    if(cols[j].find(k.first) != cols[j].end() and block[i/3][j/3].find(k.first) != block[i/3][j/3].end()){
                        v.push_back(k.first);
                    }
                }

                if(v.size()==0)
                    return false;

                bool done =false;
                for(int l:v){

                    A[i][j] = l+48;
                    rows[i].erase(rows[i].find(l));
                    cols[j].erase(cols[j].find(l));
                    block[i/3][j/3].erase(block[i/3][j/3].find(l));

                    if(tryit(A,rows,cols,block)){
                        done =true;
                        break;
                    }

                    else{
                        rows[i][l]=true;
                        cols[j][l]=true;
                        block[i/3][j/3][l]=true;
                    }
                }
                if(!done){
                    A[i][j]='.';
                    return false;
                }
            }
        }
    }
    return true;

}

void solveSudoku(vector<vector<char> > &A) {
    unordered_map<int,bool> rows[9];
    unordered_map<int,bool> cols[9];
    unordered_map<int,bool> block[3][3];

    for (int i = 0; i < 9; i++){
    
        for (int j = 1; j <= 9; j++){
        
            rows[i][j]=true;
            cols[i][j]=true;
        }
    }

    for (int i = 0; i < 3; i++){
    
        for (int j = 0; j < 3; j++){
        
            for (int k = 1; k <=9; k++){
                
                block[i][j][k]=true;
                
            }
        }
    }

    for (int i = 0; i < 9; i++){
    
        for (int j = 0; j < 9; j++){
            
            if(A[i][j]!='.'){
                rows[i].erase(rows[i].find(A[i][j]-48));
                cols[j].erase(cols[j].find(A[i][j]-48));
                block[i/3][j/3].erase(block[i/3][j/3].find(A[i][j]-48));
            }
        }
    }

    tryit(A,rows,cols,block);

}
};

int main(int argc, char const *argv[])
{
    return 0;
}