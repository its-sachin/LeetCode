#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:

    bool rowcol(vector<vector<char>>& board, int i){

        unordered_map<int,bool> m;
        
        for (int j = 0; j < 9; j++){
        
            if(board[i][j]!='.'){
                if(board[i][j]>57 or board[i][j]<48){
                    return false;
                }

                if(m.find(board[i][j])!=m.end())
                    return false;
                m.insert({board[i][j],true});
            }
        }

        m.clear();

        int j=i;
        for (i = 0; i < 9; i++){
        
            if(board[i][j]!='.'){
                if(board[i][j]>57 or board[i][j]<48){
                    return false;
                }

                if(m.find(board[i][j])!=m.end())
                    return false;
                m.insert({board[i][j],true});
            }
        }

        return true;

    }

    bool block(vector<vector<char>>& board, int i, int j){
        unordered_map<int,bool> m;

        for (int k = 0; k < 3; k++){
        
            for (int l = 0; l < 3; l++){
            
                if(board[i+k][j+l]!='.'){

                    if(m.find(board[i+k][j+l])!=m.end())
                        return false;
                    m.insert({board[i+k][j+l],true});
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i+=1){
        
            if(!rowcol(board,i))
                return false;
        }

        for (int i = 0; i < 9; i+=3){
        
            for (int j = 0; j < 9; j+=3){
            
                if(!block(board,i,j))
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    vector<vector<char>> v ={
    {'.','.','4',   '.','.','.',    '6','3','.'},
    {'.','.','.',   '.','.','.',    '.','.','.'},
    {'5','.','.',   '.','.','.',    '.','9','.'},
    
    {'.','.','.',   '5','6','.',    '.','.','.'},
    {'4','.','3',   '.','.','.',    '.','.','1'},
    {'.','.','.',   '7','.','.',    '.','.','.'},

    {'.','.','.',   '5','.','.',    '.','.','.'},
    {'.','.','.',   '.','.','.',    '.','.','.'},
    {'.','.','.',   '.','.','.',    '.','.','.'}};

    Solution o;
    cout<<o.isValidSudoku(v)<<endl;
    return 0;
}