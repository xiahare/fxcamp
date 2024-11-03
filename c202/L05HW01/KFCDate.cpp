
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Point{
    int x, y;
};

vector<Point> adjs = {{-1,0},{1,0},{0,-1},{0,1}}; // up down left right
void floodfill(int x, int y, vector<vector<int>> &dis_grid, vector<vector<char>> &maze, int n, int m){
    queue<Point> q;
    vector<vector<bool>> visited(n,vector<bool>(m, false));
    
    q.push({x,y});
    visited[x][y]=true;
    dis_grid[x][y]=0;
    
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int next_step = dis_grid[p.x][p.y]+1;
        
        for(auto adj: adjs){
            int n_x = p.x+adj.x;
            int n_y= p.y+adj.y;
            if(n_x>=0 && n_x<n && n_y>=0 && n_y<m && maze[n_x][n_y]!='#' && !visited[n_x][n_y]){
                dis_grid[n_x][n_y]=next_step;
                visited[n_x][n_y]=true;
                q.push({n_x,n_y});
            }
        }
    }
    
}

int main() {
    int n, m;
    cin>>n>>m;
    
    vector<vector<char>> maze(n,vector<char>(m,'#'));
    int myx,myy,frx,fry;
    vector<Point> kfcs;
    for(int i= 0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>maze[i][j];
            if(maze[i][j]=='@'){
                myx=i;
                myy=j;
            }
            if(maze[i][j]=='&'){
                frx=i;
                fry=j;
            }
            if(maze[i][j]=='F'){
                kfcs.push_back({i,j});
            }
            
        }
    }
    
    vector<vector<int>> my_dis_grid(n,vector<int>(m, INT_MAX));
    floodfill(myx,myy,my_dis_grid,maze,n,m);
    vector<vector<int>> fr_dis_grid(n,vector<int>(m, INT_MAX));
    floodfill(frx,fry,fr_dis_grid,maze,n,m);
    
    int best_dis = INT_MAX;
    for(auto kfc: kfcs){
        int x=kfc.x, y=kfc.y;
        if(best_dis,my_dis_grid[x][y]!=INT_MAX && fr_dis_grid[x][y]!=INT_MAX ){
            best_dis = min(best_dis,my_dis_grid[x][y] + fr_dis_grid[x][y]);
        }
        
    }
    if(best_dis==INT_MAX){
        cout << "Meeting cancelled" << endl;
    } else {
        cout << best_dis << endl;
    }
    
    return 0;
}
/**
4 4
@.#F
....
.#..
F..&

answer:
6

4 4
&.#F
....
.#..
F#.@

answer:
8

 
122 191
#.#.###.###.#####.#F#.FF.#F##.#..FF#FFFF.##FFFF.#.#.##F.F..F##F##.#F.F#F..#F.F.F.#.#.FF#F#.#.FF#.#F##.#...#..#.#F#.#.FF...FFFF#F..F###.FFF.F..FFF##..F#FFF#..FFFF#FF#..#.F.##FF.#F.##.#FFF.F.##
F..FFF##..##F#FF..FF#####..F.FF.##.#...F.F.#.#F.##.F#...#F#.#...F.F..F.FFF#F##F###.F#.FFF.#FFFF####F#.##FF##FF...#.#..#FF.F####..F#FF.F..FF..##.F.F.##..#.F#.#F##.###F...F..#F#.FF#.F.#F..#F.F#
..F#F#.F.#F..#.#..F##F.FF.FF.F.#F.#.##.####.#F#F#FF.FFF..F#..F.#FF.#.#FF####.....#..#F##FF.#F.#.F#.######F#.#..#####F#F#FF..#..F#..FFF#F.#F.#FF.F#FF#F#FF##F###.F.#.##.......#F#.F#F..F.FFF#FF.
#FF..###..F..F#.F.#F#FF###F.##F#.#.FFF.F.FF#F...#.###F#..#.F..F##FF#F..F#F#.F#F.FFFF#FFF.##F###F#.FF.F#..FF..F..##..#.#F#....F#.####...##..##.#F.F#F#..F##F#FFFF.#FFFF..#FF..F.#...F.##..F#F#.#
...F.#FFF....F.#FF..F..FF#.F.#.F.FF#.#.F.##F...F.F.F###..FFF.F.F..#FFFF.#F...F.FF#F#F.#FF..#FFF.#####.##F...#.#.FF#.#..#.#F#.######..F.###FF.##....#F#F.##.F#..#.F#FF.##.FF.#..#.#..F##F.F.FF##
.#F##F.#F#FF.F...###FFF..FFF#.FF#.##FFFFF...F..F#F..F#.F....#....###F.#F#.#....#F.#F.F.FFF##F.F.##...FF.FF#F#..F#F.F.#.#F#FF##FF##F#F.##.F#.#.#F#F.FF#FFF..F.##F..F..##.F##F...#.#FF#.#FFF.#F##
F..#.#.##.F#F#.##.#.FFFFF#F.#.F#F.#F#F#.F#..##F.FF.F..#...F..F#..#F.F..FF.FFF.#F.###....#....F.F#..F....F.#F#.F.F...F#F.##.FFF.#.##FF#.#F.##..FF#####.FFF#.FFF.F....#F.##FF.#....#F..F.FFF..#.F
..F#####.F.F.##F..#FF#FFF.#F.#FF.F.FFF#FF#.....##F#.#F##FFF#F#F#F.##.##F.F#######.#.F####F##F.F#FF#FF.#F###F.#.#FF#.FF.FF###.#..#FFF.F###.#.FF..F.#F#F#F#FF#.###..#.#.#FFFFFFF##FF###F.#F.F.###
###..FFF#..FF#..F..#.###...F.FF.FF.F#.#..#.F..##.#..F.#.F#FF###F#FFFF.##FF#F#####F###F###FFF...#.#.......FF#....F##FF#...#FF#F#F#F.#FF..F##.#....F.#####F.F#F.FF#.##.FF###..##F####.FF#F..###.F
FFF..FF#..#F#F#F#.FF#FF.#.F.#.##..###F##FFF.FFF..F#.#.F#.#F..#F.........F..FFF..#.FF.##FF#.##F.FF##..F..FF#FF#.F#FF.F...##F..#.##.FF#.#.#F..#.FFF.#F...#FF##F#######.F#.#FF....#.#F.#.#.F#F##.#
.F..###.#.F#.#.FF##F.FF.....#F#FF..F.FFF.F.F.F#####F#FF.#F###F.#F##.##FFF#..##F.FFF.#.F..##F##.FF###.....FF#.F.FF####F####...FFFFF.FF.#....F#..F.###F#.#.F#.#F#..F#F##...##F..#F.FF#..F.#FF.#F.
.F##.F####F.##FF.F#FF..F...#FF.F##.F##FFF#F.F###..##.F##....####.#F#.##...##.F.##.F.##.##.F..FF.FF.###.F.FF##..#....FFFFFF#FF#FF.......#.FF.##FFF#F#.F.......#FF..###.#F..FFF#F.F#..##..#F#FF#.
#.#FF.#.F###.#F.FF.FF#.#FF.F#.F#..F.#.##F#F#####....#..#F#####F..#.#FF..F#F#FFF#FF#.F#FFF#F.F....#.F###F.F.FF.FFFFFF....FF.FFFF.##.##F..FFFF.FF.#..F.FF#.#.##F#FF##FFFF.F##.FF.###.###FF#F.#.#F
F#...##.#F.F.F###..##..#.F#.###FF.##..####F.##FFFF..###F...#.#F###.....F#.FF#F.F#.F..F#FF###F.F.FF##F...F#F#.F..###F.F##F##.F#...F.FFFFFFFF###F.#F......#..#.FF.FF..F##F..#.#..##F#F.F#F#F##F.F
.#FFF.F#F.#.#..####.##..F.#..##...F.##..#.F.###..##.#.#F#.#FF.###.#..F..#.F.F#F.....F.F.F.#F..FF.####....F#F#F#...F##.FF...FFF##F#...F.F#F.FFF#F#F#F###F#F.F#.FFF##.F.FF#..#F.F#F##.FF###.F##.#
F.F###..FF##.#.#FF.F.#...F.#...F#F.F.FF..F#F####F##FF#FFFF.FF.##.#FF#...##.....##FFF.F..FFF..#F#FF#.#F#F####.F#F.F#...F#.F##FFF#.F..F..F.F###F.F....#.#F#FF.FF#F..F.FF...FFF#.FF.F#.#F#F#F#F.##
#F...F...#.FFF.FF.F#.#FF.F#..F#F##FFF.FFFF.#.#F##FF.....#FFF...#F#F.FF..F.F#.###FFFFF.F..##F..#F##.#..FFF##..F#FF#F#..#...##FFF##FF#....FF#FFF..#.#.F#F##.FFFFFF.##F.#FF.F.##..##.FFFF##.F#F##F
..#..FF#F##.F#F.F##.FFF#.F#.##.F.F.##F###.#.F#FFF##.F#.F..F#F#..FF.F##FF##FFFFFF..F.#.#FF#F.FF.##F#.##.#FFFFFFFFF.#.##.F.#.F........F#F##F.#.F..F.F.#FFF#F#F#F.F#.#.F#.##.FF#F##..##F..#F.#.#.#
F.F.#F.F#FF..#....FF##F#F.F.#FF.#..###F#FF..F..#.F..##....F##F.F#.FF#F..F..F###.FF.F##.F#...F.#F.F.FF###F.#FF.F#.#FF.F.#.FFF.F.FF.FF.###F....FF..#FFF.#.F..###..##F#.F##F.##.#F####FF.#FFFF.FF.
#.FFFF.##FFF.FF..F#F##F###F.#F#F.#F.F.FF.#..#F.##F.#F#.###.F######F###F##F.#.FF#F#F##FF.#F..#FF#....F.F.F..F#..#F##FFF#.FF#FFFF..F.#..F#F##F.....###..FF.##F.F.FF#F#.###FF..#.FFFF#.F.F#F#.F#..
#F.##FF.#FF..####...F.#F#FFF#.F.F.#.F..F.#..FF#F.#F.FF..F#..FFF.#.##.#..##..##FFFF..F##F###.F#####..##..F#.#F..##..##FFFFF#..#.FFF#..##F#F#F...#FF#FFF.F#F.#..#.F.F#FFF#F.#FF...FF.FF#F..#F.FF.
..##F.###F##FF.F.#.#F#.F.##.#FF..#F.#F#.FF...FF#F#..#.#FF.F.FFFFFF.##F####.##.F#.#F##.FF...###.F#FF..#F.FFFF#.#...F.#F#FF#..#F.#.F#####.#F#F#FF.##F..#.FF.#FF.FF.#FFFF#F..FF.F.F##.F..#..F.#FF.
.#F.#FF##F#.F.F#F..FF.FF#..##FF#.#..#..F#.FF#F.F.#.FFF#..#F#FF..FFF...F.FFFF.FF.#F#.F#F#.#FF.FF.F.#.F#.FF.FFFF.FFF.##FFF.#F#FF.F#F#..#F#F..#....##FF#.#.#FFFFFF##..FFFFFF##.#F.#FFF###.FFF#F.##
##F#FFF#F.#.F..FFFFF#FF....#.FF.#......F..F#F.FF####F.##F......##.#.#F.FFF.FF#..F#..#.#F#F#.#.F##FFF#.##.F#.#FF#F.F##F.##..FF.######.#.##FF#.#...#FF#F#F.###F#...FF.F#####.FF#..#F##.F#...#F.F.
F##F#F.#.F#.F..#..F.F...#F.#.....#.F.#.F##.F##F#.#F#FF...F#.F#F..F.F#.#F#....FFFF#F...##.FFF#F.#F###F#F.F#.###F..FF.#FF.#.F.F.##.#F.##.F.#.F.#FFF####..FFF.F.#.....##...F....F##F##F#FFF....##.
FF##FFFF#F.#..F#..F#.F..FFFF.###FF..F##.F...#.FF#..#FF..##.F##FF#.##F##FF#FF..#F.F.#F.##.##....#...FF..F.#...#FF.#FF....#.#F#F..#.#FF....F##FF##...F###FF#FF#.FF..##.##FF#F.FF#F.FFF.F#..#FFFF.
FFF#.##F#.#F#..FFF.###F....#..F##.##F.FF#...##.##...FFFFFF##...FF#..F#F...F#..F.##.###.F#..###.##.F.F#FF.###FF.FF####F....F#FFFF#F#.F.F#FF#.#FFFFFF..#FFF..F.F####..#.#.FF#....##F.FF.#..FFF.#F
.F#..FFF#F..##FFF#F.F#FF##F.F.#.#FF#.##F#.#F#F##..##.F...F.##.F.F...FF..F.#.#F.#.F..##F..#FF#FF#.#FF#F#.F.##.F.FFFF#...F##...#.#.F.F#F#..F###...F.#FF.#F#..FF##FF###.....#.F.FF.F#FF.##F#F.#FFF
......F.F###.#FFFFF#FFFF.FF#.F#FF#.F#...F#F.FF.FFF#F.#.F##F.#FFFF.####.FF..F#.FFF.F#..#FF..##F.F.FF###.#.#F.#.#.#F.F..F...##FFFFF.F.....#FF.F#F#F..##..#F#.#F.#F###F.F#F..FFFF..F##..#.FFF.##..
#F###F#FF.#F.F##.F#FFF.#F#F.####FF.#..#..#.F..#..#.#FF.F####FF#FF.#F.#FF###.#FFF.F##FFFF.#..#..FF####F.#F#F.#FF#.F#..F##FFF##.F#.#.###.####...#.#F..F#.F#.#.FFF#FF.#F.F.F.F..FFF..F..F..F######
FF.#.F.####F#F.#F#.#F#.#..F..#.#..F##F.#F.F..F##..#.F..#..FF#F.#.#F..###.##.F.FFF.#.#..#..#FF.###F##FFF#FF....FFF#..FF#.#FF##F.#..F.F##.F..F.F....##.FFF##F#F....#F#######F##F#FF#.FF##.#.#.F#F
###.F..#.FF##..FF.#.##.F#F.###F#..F..#F.#.#.F###FF#.###..##.FF#F##..#FF.F.F.#F#F.#F##FFF#F..#FF.##F###FFF.#FF#FF#FF..FF##.FF.F.FF#F#...#FF#FF.F#..#FF#...##.FF#.##.##.F#.###.F##.F#.#F.###F.F..
.#F##.F##F...#.#FF##.#F..##..##F#FF#..FFFF#.#F#FF###.FF.FF..#.#..#FFF.####.###.FF#.##F#F#F#F##F##..#F#..F##FF#F#F#FFFF##FFF.F#FF##FFF..#F.#.##F#FFF#FF#FF#..FFF.F#FF#F.F#..F.####F.FF#FF.##F..#
FF..F..####FFF.F.FFF#.FFF.F##..##.#..F..F#F.F#F..FF.F##..###.F#.F#FF..#FF#.FF#.F###F.F.FFFF#.#F.F#....F.FFF...FF#.#..F#F##FFF.FFF#F#FF.FF.F..##.FFF.F.F##...#F.#F.F.F..#..##FFF.F#FF...F##F.#..
...FF...FF.F#.F.#..#FF###F.##FFF##FF..#F.#F#F#F.F.##F###F#F.#.F#F#.##..##FF##F.F.#F#.#.FF.#.##.##.##.#.##F#.#####.F##..###F#F#F..#F.#FFFF.FFFF..#F.####F#FFF#FF#F#.F....#..###.F...##.#F#FF#.#F
##.....FF#.F.#..#F.F#..##FFFF.F.F.FF#.FF#FFFF#FF#.#F.#F..F#.F.F.FFFF#F....##F#.#FFF#.F..F#F##FF#.#.##.F.F#F#####FF.F...FF#..FFF#F#F..#.F.F..F....FFFF##F..#F..F.F..F#..F.F.FF#.F.F.FF##.FF#...F
F.#F#####.#F...F#.F..#..#.#F..FF#...FF#.FFF#FFF..#.F..#FFF##..FFF..####.#F#.#.#..#FFF##FF.FF##FF.FFF.F..F#..F#.##.####F#F.F##FF.#..F##.#F###.#FFF.#.#F.#FF....F#F.F#.#FF.F#FF...#FFF#.F#.FF#...
.#F.F..#..F.##.#F#.#F#..F#F.F##.#.##.#FF#FF#.#####F#F.#.FF#.F###...F.F..#..#FFF.FF.#F###F####FFF#.FF.F..FF.##.F.F#..F##F..#FFFF#..###.F#.##F#F#.F##..F#F#FFF#.FF.#..##F#..F#F##F#.##F.F##FFF.F.
#F#.#..#.#..##.FF........F#.#F#FF.#F..#.#.F#.#.FFFF#...#.#F..##..#F###.FFF.FF#F.###..F..####..##FF.F.F.#..F#F.#FF.F...##..F#FFF.#..F..F..FF###.FFF.F.F.FF.F##F.#FF#FF#F#FF.F#.#F.FFFF...F..#.F#
.#F#F..##FFF.####FF#FF##....##.FF#.F..##..###F...##F.#F#.##F.##.###FF...##F#.F##..F.##FFF###.###F#..#.....#..F##..#.##..F##FF#F#....F..FFFFF#FF..FFF.FF##F...F.#FFF...#..F######.F#F...F..FF.FF
#F#.F#FF#.F#.F.##F.#.F.FFF##FF##..##FF#.###F.#F###.F##.#FF##F#F.##.F.#..F.##F####F###F#.F#F.###F.F.F#.F##.###F##F.##..FFFF##.FF#.F.##FFFF#F..#F###.#FF.#..#FFFF#..F....#FFFF..##.#..F#F....#FF.
F##.FF#F#FFF.FF#FF##.#.FF.###FFFFFFF.#..##F...##..FF.#...#F.F##.###.F#....FF##F##.#F#...###..#F#.#F##FF#F...F.F#.F.#F.....F#.#FF##..##..F.....FF#F#F#...##.FF..#.######.F##..#F.#.F#.F..F#FF#FF
F#F.######.F.#.###.#.#.F.F#####F..##.F####F..F#FF.F##F.#.##.F#....###F..##FFF#.FF#.##...F#.#FFF.FF#..#F..F.FF.F.F..FF.#.F.F#..FF##FFFF##.#F.#..F.F.FF.F.F#F##F...###.F.F.F#F##F#.#.#FF####F...#
.#.##.F#FF....##F.#.F#.F#F#.###.FFFFFF.###F...#F.F#FFF##FF#FF....F##...##.##F#FFFF#...#####F#.FFF.#.F#FF#.F#..##.FF#.####F#F#FF##.F##FFF#.FF..##F#.###.###F##.#...##....#.#F.#.FF.FF#F.##F.F#FF
F..FF.F.#FF.#..F#F##...##.F#F#.#....##.#.#..F#FFF##..F#F#.F.#.#..#FFF#F.F##.#.#.F#F#FF#....F#...#FF#F..F##FF.#F##..#F#FF#..##..#..#F.##FF.#F#F.#..F.#FF.F#.F#F.##....##F##.F.##.FF#.##...F.F##.
F..##FFF.FF#..#F..F#F#####F#.#.#FFFF##F###F....FFF...##.F.F.F..#.#FF.FF####.#F.#F.FF#.F.F#FF#.F#F#FF##F###.F##.#F.#.F.#..#F##..#####F.FFFF##.F...#.FF#.FFFF.F#.F#..##F###...F#FF.#F#F.FFF.F#F..
#....F...#..F##.#F..#F##F.F.F..F.F.#..#F##.F.#.FFF.....#..F#.#F#...F##.####.##.FF#FF...#FF.F.F#F..FF..#FF#F#FF#FF#FFF##..##.F.#.FF#..F..#F.FFF#..##.F..F.#..FF##FF.#.FF.#FF.F.#.F##..##.FF#F#.F
F.#.F##..#FF#.###FF.FF.#.##..#FF.#.F..F##.##.##.F..FF..F.#.F###.#F#.###.##..F#.FFFF.##F#..####...#..##.FF....#F.....##FF.F..F#..#F.###...#..##.#FF.##..##F.#F.FFFFFFF.FFF.#.#F#.F##...FF.F.FFF.
#..F#..FF.#.FF..######.#F#FF##.#F###.###F....F#.FFF..##F#..#F.#.###..##FFFF.FF..F.F###.F#.F#.#FF.#.FF#.#.F..FF##FF#F#F#.#F#.#F##F..####FF.##..F.#..#.#F#F##F#FF#FFFF...F.F.FFF#FF#FFF.#.FF###F.
FFFF#FF..#F..#F#F.##.F.F#.##F...##..##F###.F#F.FF.#.FFFF##F#.#.F.F.FF#.#FFF.F##..##.F###FFF..F..F....F##F#.F.F#.F#FFF.#FFF.#.F..FF###...#FF#F.FF#.#F#.....##F#.FF#FF#.F#F###FFF.#.F.....F...F#F
###F#.F#.#F.###.FFF###FF#.##F###F..#F#.....F.#...F#....FF##.F.FF#..F.F#FFF##.#..##F..FFF.F#F#...FFFF.#.F##F#.#F.FF.F#FF.F#..FF.###.##FFFF..##..F..F#FF##FFF..F..F.##.F..F###F..F.FF...FF.F##FFF
FFF..FFFF#FF#.##...FFF#F.FF.FF#.FF..F.F..#.#F#.##FF.#FFF#.#..F#.F#FF#F#F#FFFF.#FFFFF..F#F.F#.........#FF#...F######F.##F.F#..##...FF........F#FFFF##F.F###FFF..##FF#.F##F.##.#F.#.FF#FFFF##.F.F
F..F#..##F#..#FFF.FF#.FFF.FF#.F.F.....F##FF.#..#F.###F#F##..#..F#F.F..#..#.F.#.#F##.F#FFF.#.#FF.F#FF.FF#.....#..#FFF##FF##F.F.FF.....F.FF#.#FFF.#F.F..F#.#F#.FF.#F##.F.#F..##F..F#F.....F.FF.##
###.###.#.FF#..#.F#.F.F##F#F.FF#F..#F#..##.F..F...#.F##.F.F#FF.FF#.#.##F.F.F#F..##FFFF..##F#F.#F..F#F#FF##..F.FFFF#F.#F..F...F#..#F.##FF.###F#.F.FFF#..FF.F#...F.F#.#.F#FFF#FF..#FF#.#F#.#####.
F###FFF.#...FF#.##F##F#F#F#.###.F###.#.F#FF....FF...#..##.F.FF.F#.#.#F##.#....#F.F##FF#FF.#....###.#F.##F#F####..FFF..#.F.F###...#F.#F..F.F.###..F.#F.###F#F.#F#F.##...#F#F#FFFF###FF#FF#.#FF##
F.#.F.F#F#.####F#FFFF####FF##FF..##FF...#.#F..F#FF...F...F.....#.#.#F.F##FFFFF#FF#F..F#...F#F#FF#FFF...##.#.#...#F#.FFFFFFF##FF##F.##.FFF....F.F#..#.#F#F..F...F###.F.F#.##..F#.F#.#F#F..#.F#.#
.##.F.F##F..#F.###FFF.FF.#F#.F#F##FF.F.##.F..#F.#F.FF.F.##..##FFFF.##F#...FF.FF...FFF..##FF..##...F#.##F..##F###..#FFFFF#F.FFF####.FFF..#F.####.##.#FF.FF#..####.F#.F#F#F#.FFF.##FFF.F...F##FF#
.#F###F##...#F..F#F#.F#.F#F.#.F.FF#.F...###..##.F.FF#.F##F#F#...FF..FFF###.#F..FF.##.##..#.FF#FF#F#.FFFF##.F####.##F...#F.##..##.F#F#F.###.F###....F.##F#.FF#.#F.#.F#.FF##..FF#.F..FF#F#F...F##
######F.#F##.##F#.F..#.#.F##.FF.#F##F###FF#F..F.#..F#F..F#..#FF.#..##F.#FF.#F##F..##.#.F#####FFF#F.#FF#F##F#.##FF#..#.FF.F#..F..FF#F..F#FFF..FFF.F...#..#F##F#####F##.#F#..#..F.##..#.FF#..FF#.
F...F..F#FF#..FFF...FF#.F#F.###FFFF.F###.#F.F..##.FF##.F#.#F.F#F.F.#.FF..##F#FF#.###.F.F##F#.#FF.FF###.FF..##FF....###FFFF##F.FF..#F###F##.#.FF.#.F..#F.#.F#...FF##FF.F.F.F#F####..F..#F#.FF#FF
##F.....##FF#F##..F.#F....#.##.#FF.F#.FF#FF#..#..#F#F.#.#FFF#F#....FF..#####F##F##.F.#FFF.#F.F..#..##.FF#..##..#F.FF..FF#.#F#.FF.F.##F..FFF.F..F.F.F..FF.#F#FF###F#.F#F..F#...#F##..FFF..FF##FF
#F.#.F##F..FF.F.#.F.##..F.F#..#...F#.#.#F..F.F#F##.F..#FF.#FF#FFF.F##.F..#F##FF.F##..F.##.F#.#F.#.F##F#F#.F..#FF...#F###.##F...#F#FF..#...F...F#F.#.F#F..#F#FF.F.###F.##..FFF.F.F#..#.F.#F.FFFF
.#F#F##F####..F##.F#.FFF.##.#FFFFFF#F#.F...##.F#.FF#.#F.##F#FFF.FFF.FF.....###.F#FF.#.#.#F.#.F##.##F.#..#F##...F#FFF########.#F#.#F#.F..F..##F..##.##.F.FF.#.F..F##FFFF#..#F#F.#.#F#.FF.#.F##..
.F#.##F#..#FF##F.##.FF.F###.#.F#F#F....###..##F.#FF##F#.#F#F..F.FFF#FFF#FFFF.F#FFF#..F#F##.F#FFF#F#F#....##F.###.##...FF..##....#F#FF.##FF.#.F.#F#F#F..FFF#.##.##..##F..FF..#.#F####F#FFF...#..
.FFFF.##.F...F#.#.#FF#FFF.F#..FF#..FFFF..F#.F#F.FF..#F#FF...F....F..#FFF.#.#FF#FFF##..#F##F.F#FFF##F.#..#F#F.FFF##F#...FF.FF#F#.F.##...#F#FF..F##.#.##F#F.F#F..F..##F#F#...F##F#F##FFF#.F#.#F#F
F.F#.FF#####...#.#FFF#F#.FF.#F#FF#F.##FF..#FF#...###..#.#.#.#F##....F.F#F..F###FF##.#........#.#.F#F###F..F.#F##F#..F##FF##F#FF.#FF..#F.##FFFF#.F#.FF.#F.###.F.#F#F..F#F##F#FFFF#.FF###FF##...F
##FF#.F..FF#FF##.#.F##FF##F.#F..F#.F#F#F.####.#.#F..FF#.F##F#..#.F.#FF##.##.#.#FFFFF.F.FF.#.#F.F#.F..#F#FFFF#FFF#FF...F#.FF#F#.###F##FF.F.F.FFF....##..F.#.#FF#.#F#..FFF.#.....#F.FF#.##..F#..#
..#F###F.#.#.F...#######..F.FFFFFF##F...#F#.#.FFFF##FFFF.#FF#.F#.F..#.#F##F..FF.F..FFF#F#.#....F#F#F....F##.##.F##..FFF#F..F#..F.##FF#..FF####.FF.F#.FF#.###FFF.F#.F#F#FFFFF...F.#F##.F....F..F
F#.F..#####.F#.F.####..F#F..##.#FFF#F.#.#F..FF.#.#.F#.#FF##..F#..F#.....###..FFFF#.FFF#F#..#..F#..F.#.F.F#FF.###.#.F#..F..FFFF##F.FFFF###.F.##.#.#FF..F.F.F#FFFF.FFF.F#.F..FFF.#.FF.FF..#FFF.FF
.FF#.#F##F.FF#...##...#F.F##..#F.F#...F.###F.##F..#FF###F##FF.#.#FF#..#.#FF#.##F#F##.##.###FFFF#FF...#F#F.#F##.##.F#.F##.###F#F#FF.#.F.FF##.F.#..##F.##F#.#.F.F.#.F..##F#F..FF#FF.F..F#F##.....
..##....####F.F.F#.###.F#F##.#.#F.F#F.F#.##..FF#F.F...FF####..FFFF.####FF.FF#F.F#F.F.F#.F#.F##.F#FF#FFF.F.F##FFF#F#F.F#F.#.FF..F.F#FFF.#F.#.#.F#F##..F.#...FFF#..F..##FF##F###F.F.FF##F##F.F.F#
.#FF##F#.F###F.FF##.##FF.#F#FF..F..FF##.FF.FFF.F##.##F###FF.FF#.F.#F#.F...#F#.###.#...##F.#.#.F.#F#.F#.FF.###.FFFF#F.F#.##FF..F##F#F#..#FF.#...F.FFFF#..F#FF..#F..#F..F..#.##F.#F##....##.F..##
###.F.F..FFF.....##..FF#.#.F#FFF#FF.#.F#.F....F#.####F.#.###.F..#F#.F.##.##F#F.FF.F.##.F.#.FF.F.FF.F.FF.F.F.#F#F..#F#.F#.#F#F#F.F.F##.##F#..F#...F#.F.F..##.F..F#F.#..#F.F.#F#F..####.######..#
..#..F#F#.##F########F##FF#.FF##F#F###..##FF.##FF...F##.F##F.###FFFF##F.FFFF##.#.##F###.F....####.#.FF.F#F..#F##.##F#.F.#FF.#.###FFF.#F#F#FF#...#F.##.FFFF##FFFFFF#F..#####FF.##F.#.F##..#FFFF.
FFFF.FFF.F.#..FF#.FFF.F#F#FFF.#.#...F..FF#F..FF#.#.##F#......F.F##.....##F#.##F#.F#F.##FF...#.#F#.#.F.###.#.F.#FFF.#FF#..#.#..#..#F##F.##F###.F..FF..###..F.#...##....#FF.####F#.#F.FF#.#F.#...
.#F#.FF.#..F###.#F.F...##.#FF.#FFFF..F.#####.F.FF#F..F##FFF.F#FF##.F#FF.F#FF#.FF.F....#..##....#.###.#.F..#FF#FF.#.F..F.##F..F#F.#FF.FF##F.#F.###.FF.#.##FF#.F#FF.F.F##F#.F#.#..#.#FF...#..##FF
##.F.F###..F..#F###..F..##.F..FFF.###.FF#.FF#F.##F.FFFF...#FF#.FFF.F#FFF#..#...F##..F#.FF.#FFF.FFF.F#FFF...#..FFF#F.#.F#F#..FFF.#.#.#F#F#.#..FF.F.......#..F.F##F..####.#F...FF.##F.F#.FFFF##FF
##F##F..F#F####...F.F###FF##F.FF..F.F###..#.#FFF..#F###F.#..#FF..F.#...####F###FF#.#F#.#FF.F#FFFF..F#.#.F#FF.#FF.F#....#..#..FFF.#F..#..F###.#.F.F#F..FFFF#F#F..##FFF###.#.FFFF.#F.#.F##..F#.FF
.F.FF....F.F#FF#F##.#F.##F##F##.#FF###FF...#.F...##.FF####F#.F.#F###F.F#FF.....#F#.##F#..##F.F.F.#FFF#.FFF..F#FFF#F##..#.FF#.F#F.F.F..###F.FFF.##.#.FFF#F##.###...#F.F#FF..FF#FFF#..F#F.F.#..#F
#FF##FF.##FFFF#.F.#.F##...#..#FFF##..##.##F.F.FF#.F#FF.FFFF###.F##.F.#.#.##F..##F..F.FF#F..F.F##.F.#.F.#F#.##.#.F...F.#.#.#F#####FF..F##.FFF.#F#.F##..FFFF..#F.F#.#F.F#.#F.#F#..####.F.###F#.#F
.F#.#FF..#.F#F#FF#...F#FF##.#F#F##.#.##.FF#.#F...F#..F..FF....##FFF.#.###F.##F#F###FFF.F..F..F#.F##.#...FF...F.#####...FF.#FF...#..FF####.F.#FFFF#.#F#F..##.#F#FF##F.F#FF#F#F#F##.#F.#F.F#.#...
...##.F###.FF.#.#F.F#F#..#..F.F#FF.#.F####..###.....F##F#..##FF...#..#FF..##FFF#F##.F#..#F.#.#.F###...#F#F.FFF.F######F#.F#FF..F.FF.##..#.#.#F.#FF..#F..FF#....#.F.#..#####F#F#F..#..F##.#..##.
#..FFFF...FF..#F#...#.#F##...FF#.##..FF.FFF.####.....FF.##F#...F.FF#F#F.#FF#FF...#FF.F##F.#F#.##FF.F#F#F.#......FF##.FFF.#F#.FF#.###FFF.F.FF.FF#F.####F..FFFF#.#FF##.#.##FFF#FF.##..#..#.##F##.
F#F...##FF#.FFF.......F...F.##.FFF.#..F.#F.FF.F###F...F.F#..#.#FF...#F#F..F.#.....F.#F.##FF#FF#FF.##F#F##F.#F.F#F#.#.F...#.#F.#.FFF##.F#.##FF.F#F.#F..FFFF.##F#.#F..####..F#.##.F.F###.F...#..F
#F#.###F.F#.#F....#.#.#F....FF.F.F.F.F..#FF..##.#F..FF.F..&FF.#.F##FF##F.##.#F.##FF.F.FF.F#..#.#..F.#F##...FFF.F#F.#F.F.#F.F##F..FFFFF###F...F..#..F###..F.#FF#.##F.F..F#F..#F..##..F#F.#FFFFFF
.F#..#...FF#FF.#FF.####..###.####.#F#F..F....F###.FF.FFF##FFFF#.##F...F#F##.#.#FF#...FFF##.F.#..#.##F#FFF.FFFFF##FFFF....#.#..FF..F.FF#F#F#..##.#F#FFFF..#...#F.##F.F.F#..F.F#F##.#F.#F.FFF.#.F
.F.#.#F#.F..##..F.#FF.#...###F.F#F##F.F.F..F###F#F.#.F.#F.#.F#F##F.#.####.F....FFF.F#F..F#FF#FF...#FF.F#..##.FFF.#.#F#..###.###FF.FF#F#..F...FFF.###.F##.F#FF....FFF.#.#FF..#.F#FFF##..##F#F#FF
#FFFF#F#.#.F#.FF###FF..F.#....#F#F#.#F#.FF.#.FF.#..#.#FF#...F.#FF...##F#FFF#F...FF#F.FF...FF..#.FFF#.#.F.FF#..#F#..F.....#..#FF.#..###.#..####FF##F#F##F.FF####..FFF.FF...#####.##FF..F.F##.#F.
F#FF.F##.F.F#F#.#.#.F.F.F.F#.#FF##.#.F#F.FF..#.##.##FFF.F.##.#F.F.F..#FF#F##F#..F#FF##F#F##FF.#F#.#.FFFF.FF...F.#.F...F.#..F#...F..F.F.FF.FF.F#FF.#F##FF#...#..FFFFFF.##F.#....F.#.#F##..FF.F.#
F#F..F.F#F#.F.FFF#.FF#F..#F.#F..F##F#F.F##.##FF.##.F..##..F#F...####FF###..#F..F..##....F#.F#..#FF.##.#..FF.##F#F.##FF#.##....#.#..#.F#FF..F...FFF..F..#F###.F#F####.F.####..#F.F.#..#F#.#.####
FFF#..FF...#F.FF#.F#.#.F...#F..#...#..F#.#F.#.F#F#..#F#.#FF...#..#F##F..FFFFF#.FFF#.#.FFF#..#####FFFF.F..F.F.FF..F.#F.FF..F####.#.F..#F#F#..F..FF.#FF.##.##..F..F.F#F#F#..F.###F..#.##.##F###F#
#F..F##FFF...F##..FF.F##FF..F#FFFF#.#F#.#F..F.###.#...FFF##....F....FF##..#.#..F#FFF#F#.#F##F.#.F#FFF#FFF##.#.F#F.FFF#F###.FF........##.##F.##F#F##.#F.#..#.F#.F.FF#F#..F##F##..##.FFF#.#.#.F..
..#FF#..#F#F#.#F#..##.F#.F.##FF#F.#..F##FFFF.#.F..F##F###.#FFF##..F#..F#FFF#FF..##F.#F##..###F#.#F#...F.###FF..##.#####.F....FFFFF..F.#.####...F..###....#.#.#F....#F#.#F..#FF#F##F#FF##.##FF.F
.#.F..FF#.#.F.FF....FF....##F###.##.FF#FF..FFF#F##.#F#..#.##F#F...###..F..#.##.#.##..#....#FFFF.F.FFFFF.F.F..F..#..F#FF#FFF.F#.#.FFFFF#.#.#.#FF.#.##..#FFF.#FF....FF.FF.#.#..F#..FF#F#.#FF##.##
#.F.F#FF.F#F#F##.#F.F.#F#F..F..#FF..FFFFF..#.FF..#.#...###F#F.FF.#F#.F.###...F#F.#.F#F..#F#F..#.#FFF#....#####F.F..F##..#FFF..#...FFFFF####FF..FF#.#F.#.#.F.FF.#F#..#F.F###.#F#F###F#.F#FF##..#
.F#.#F#.##...##.F..##FF.#F.##F#.....##.F.##.#.#FF..FFF..F.###.FFF##....#..##....F.FFFF..F.#F.FFF.F###..F.###F#FFF....#.#.F##F#....###.F#F..##.#F..##F#.FF.##.##F#F#.FF..FF#####.F#.F.F#F.#FFF..
.#.F.F.#FF.#F#..FF...FF.F#.F##FF#####F#F###...#...F#F.FF#.F.F##.F##FF#FFF#.#.F#...F.F.#..F###.#...FF#.##.F..F..F.#.F###F#F.F##F##FF.FFF#F##.#F...###.F#..##F.F...#.#.#.#.#F#F#FF##.##F.F..F.FFF
FF.F##F##F#F..F..F##.....###FF#.FFFF.FF#FFF#.#.##.F.#FF...#....FF##FF#FF#FF.FFF#.....##F...F..FFF.#F..#.#...F#..#FF#...#F##.F##FFF#F.F.##.#.#F#..F#.F##F#F#.F.##..F....F.#..F#F.F#F#FF.##F#.F..
..#FFF.FF##.FFF#..##F#.#F...#..#F.##F##.###..F.#F.F###...#F##..FFF..##F..#F#F##.###FFFF.F#.#.F..#F..F..#.F..F#.#F.#..##F#..F#F.F.FF#F.F#F.F##FFFFF..FFF#####..####FF.FFF####..##FF##.F..##..F.F
###F..F#F.FF#..F..F..F##.#....##...#.F#F.#...#.F#FF#FF.#FF...#F.FFF.F..F..#F##.#F#FF#...F.#...#F#.#F..#..FF.##F.F.F#.##F.#F##FFF..F##.#.#F..#F.FF.F..#F.###.F.##F##..F#..FF#.F#####..F###.F##FF
#F#F###..#..###..#.F....FF#F.###FF...F#.#.FFFF.###F#FF#F#F......F.F###..FFF##F...#.FF##F#F###.#.F##F.FF#FFFF#F.#.F##F#F#FF.F.#.#FFF#.##..#..FFF##.....#F..FF##..###.F..#FF.FF.#F#.F#.###.F..#F.
.F.##F..FF#.FF.F#..F##.FFF#..##.F..FFF##FF#FF#####F.##F#F#.F.#..#.##F#F.##FF###.F.F#..FF##F.F##.#.FFFF#FF#F#....F...F####.#.F...FF#FF.###.F.F#FF.F##F#F#.F###.##F#..F#.F#F.FF.#FFF.#.F#F####.#.
######.#F##...F.###FF###.F.##.#..F...F...#.#.F#F##F#F###.FF#F..F.#.F...F#...#.F#F#F.F##...###.#.#F##F..F.FF#.##FF#F##...#.#F#..#F#F.F#.F.#.#.#.#F.####F.#...F..F.F.#F#F#.F.F#F#.FF#FF.#F..#.F..
###.FF##..#F#...#F..F.#F.FF..##....#FFF#.F..F.#.#.#.F...F##F#FF##..F.##.F.F##F#F.#.F#.FF..FF.FF#FF.#.##F##.F#F..FF#....#..F.#...##..F.F#..FFFF#.F#F.##F#FF#FF..FFF#...FF.#..FF..###...F..F#FFFF
.#F#...F#..#F..FF.#F#.F.F#.F.FF.#.#....##.##F##F.#FF.#.....#FF..F...F#F#F.F#F#F.#FF.FFF.#.FFFF##F.#F####FF..#.FF##F.FF.#.F.F##..#FFFF.#.#FF#F...#.#F#FF.##.#.F#..#.F#FF####F.F#F#FF#.#.#.F##.FF
F#.#.FF#...##...#...F..#FF#F..F##.F...F#F##.F#.#.F#.#F##F#.#F#.F##F#.FF#F.FF.#F#.F....F#FF#.F.F#F..F.#F#F#F..##F#F.#..##FFFFFFF.FF.#F#.F#...FFF....#F.FFF.##.F.#FF.F.FF##F#######FF#..F#FFF#F#F
.#....###F.....#FF#.#F..#F#.###F.##F..#FFF.F#F#..#F##.F##F....#.FF##..#F#.F#..#.FFF.FFFF#FF..F.FF.F.##FFF..FFF.F..F#FF.#F..###F#..##.F#.#..#F.##.FF##..FF.##.F#.F##.#F.#...FF.##FF.FF#F#F.#F##.
FF#.#...FFF#FFFF....F.F#..#.F#...#.###..F.FF##FF..#.#.F.###.FF.F..#...#.F.#F.##F.#.#F#FF#F..#FF###F##F#FF#..F#FFF#.#F#..#FFFF#F.#.#.F#FFF#.FF#F.F.#F#F#F.#.#..FF##F#F.#.##FF#.FFF..FF.FF#FFF##F
.FF#.FF.##F.F#F.#####F.F.#...#.#.#.#F#F##FF.#FF...#.##FF#.FF..###F##.#.#.F#..##.##.FFF#..###F...F.#F.#..#.F#.#F.#.F#..FF##.FF.###F#F.FF##...F#.F.F.F##F.#.#F###F..#.##F#F.##.F#F..F###FF.#.###.
.#F..#####.##..#F#...F#.#F.FF.#FFF.##.F#.#.#.##F##.#.F#F..##.#FFF.F##F###..#F####.#.F.#.FF##F.....F.F.F.F.##FF.FF#FFF..##.F.F#.FF.#.FF#.#.F#F.#.#..F..F.F.F##F.#.#..#######.##F.##.F.F##FF#F#..
#FF.F...F.F##.#F##.#..F..#F..F#F.F.##....#F####.##..#..F.....#F.F##..FF.F##FF.F#.F..#FF.F#FFF.FF.##F#F.F..#FFFFF.F##.FFFF#FF#F#####.#.F.###...F...#.F##.#.##.#.##F#.#.FF.F##F#.#F#..FFFFFF.##F#
##F.#.F..FF..F#.FF##.FF#.#.F.#F#F#.F#F#FF...##F##FF#.FFF#FFF.F.F..##F..F##F#FFFF.#FFF#.###..FFFF##FF##.F#.FFFF###.##FFF.#F..#.###.##.F##.F....###F#FF#F##F##F#F.FF..#..#.F.#..FF.#.#F##F#FFFFF.
.#FF.#.F.####F##.F.F##..F.F.#.#F#.#F.#F##FFF#FF..#..F.FF.F##.F#.##FF..F.###.##.#.F.F#F...##.#F.F...#F#.FFF.##.##FF#...FF.#.F..####..##.#..F#.FF#...#.#.F#FFF.#.#F#FF#FFF.FFF.F#.FFF.###...#F#.#
#.FF.#.FFF####F.FF#F..#FFFF.F.##.F#..F#..FF#..F###.###F.#F#..#F..F....F##.F##F#.F...F#.##F.#.F.#####...#F#.#F.F#F.F#.FF....##.#F.#.FFFF#.#.FF.F.FFF##F#.#FF#FF..#.##F..F.....#F.F..F#F#.F.#...#
.FF#F#F#F.F#F.#..F###.#.#...#.F.F#.F##.#.F#FF##F###..F#..#F###FF.#..#F##F###FFFFF...#FF.F###.#.##.FF..F...F#FF.###FF.F.#.FF.#.##F##.###F.F.F..#FF#..F.##....F.F#F.#F...###.FF##F#.F..##F#.#.F..
.FF...#.#.F.F.F..##.#.F###F.F.F.F.#F#.F##.FF#.#FF##F#F.F#..F.F#F....FF##.F###..F.#.#F.#.F.F...FF.F##.#.FFF#FFF##..#FF...F##..F##.#F#FF....F.F.F#..FF#.FF#F#F....#F..FF..###F#F..F..##F#..#F.FFF
.FF.F##F#..F.FFFFF.#F.##FFFF..FFFF.F#F#.F#FF#F.##F.F.F####F##F##F#FFF#FF#.F#F##F.F.FF.###.#.F.F.F..FF.#.#.#F.F.@F.F#.#.F##..F.#FF.#.#F.#F.FF.F..#.F##F#.#####F#F#F###.#.##.#FFFF..FF...F###.##F
F..F#.#.####FFF##FF#FF.F#FFF.FFF.#.#.F.F.#..F.#.F####F##FFF.F#.FFF#F##.F###F##FF...#FF..F.#FF##.##F.FF###F###..#F#.F#...FFFF#.FF.#F.##.F#.##.##F###FFF.FF#.##F.#..F#F##..#F#F.F..#FF.#F.#.#.FF#
F.#F##F#F..#.#.#F##.#F#F#.#F.##.####.F..#####F#.FF#.....FFFF#FFF.#.FFF#FFF..F###FFFF..FF#.FF.#.#FFFF...FFF###.###F##F...#F..#.##F.F#FF###..#FF.F.F#.##.##..F..F#F.F.#......FFF#F.#F..F..###F#.#
FFFF#F.F##.##...F..#.#F####.#..F.##.#F#F.F#FF#..F..#.FF.F..##F....#####.#F#FF##F..FF.#FF#.F#.##.##FF.FF#F#F.FF#F#F#.#...F.#F.##F.F....F###F.FF..F.#F.F.FFFFF..#F.F.F#.#F..#...#..F##.F.F#FF####
#....#..#F#.#F...##.F.#..FF.#FF#....FFF#.#FFFF##..F#.#F.FFF##F#.#..##F#.F.#.###F...F#F.##..F..FFF.FF.F.##FFF..#F#FF.F...#F.###########.F.#.##.F#F##...#.#F#.F#FF###F##..#F#..#F#F#.FF###.F#.FF#
FF.###F#FF##.FF.....FF..##..#.#.####FF###.#....#F#F.#.F#.#..FF.F.F.##F.F.F.FF.#F..#..###F.#F.F..#..#F.F..#FF#.###.#########F....FF.##..#.F.F##F#.#.#.#.F#FF.#F#F##FF###.F..#FFFF#...##.F...F#.#

answer:
89
 */

