
#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct Point{
    int x, y;
};

struct Result {
    int step;
    Point pos0;
    
};

vector<Point> move_adjs = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(Point &p){
    if(p.x>=0 && p.x<3 && p.y>=0 && p.y<3){
        return true;
    }
    
    return false;
}
bool unvisited(map<vector<vector<char>>,Result> &m, vector<vector<char>> &state){
    return m.find(state)==m.end();
}


bool handleQueue(queue<vector<vector<char>>> &q1, map<vector<vector<char>>,Result> &m1,map<vector<vector<char>>,Result> &m2){
    
    if(!q1.empty()){
        auto t = q1.front();
        Point pos0 = m1[t].pos0;
        int next_step = m1[t].step+1;
        q1.pop();
        
        for(auto move_adj: move_adjs){
            Point next_pos = {pos0.x+move_adj.x, pos0.y+move_adj.y};
            

            if(valid(next_pos) ){
                vector<vector<char>> next_state(t);
                // swap
                auto tmp = next_state[next_pos.x][next_pos.y];
                next_state[next_pos.x][next_pos.y] = next_state[pos0.x][pos0.y];
                next_state[pos0.x][pos0.y] = tmp;
                
                if(!unvisited(m2, next_state)){
                    // override
                    cout<<next_step+m2[next_state].step<<endl;
                    return true;
                }
                if(unvisited(m1, next_state)){
                    // push into queue
                    q1.push(next_state);
                    m1[next_state] = {next_step,next_pos};
                }
                
            }
        }

    }
    return false;
    
    
}

int main() {
    
    vector<vector<char>> start(3,vector<char>(3,0));
    Point pos0_start;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>start[i][j];
            if(start[i][j]=='0'){
                pos0_start = {i,j};
            }
        }
    }
    vector<vector<char>> end(3,vector<char>(3,0));
    end[0][0]='1';
    end[0][1]='2';
    end[0][2]='3';
    end[1][2]='4';
    end[2][2]='5';
    end[2][1]='6';
    end[2][0]='7';
    end[1][0]='8';
    end[1][1]='0';
    Point pos0_end = {1,1};
    
    map<vector<vector<char>>,Result> m1,m2;
    queue<vector<vector<char>>> q1,q2;
    q1.push(start);
    q2.push(end);
    m1[start] = {0,pos0_start};
    m2[end] = {0,pos0_end};
    
    while (!q1.empty()&&!q2.empty()) {
        if(handleQueue(q1,m1,m2)){
            return 0;
        }
        if(handleQueue(q2,m2,m1)){
            return 0;
        }
    }
    
    return 0;
}

/**
 
283104765
answer:
4
 
427068153
answer:
21
 */
