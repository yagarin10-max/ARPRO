#include <a_star.h>
#include <maze.h>

using namespace std;
using namespace ecn;

// a node is a x-y position, we move from 1 each time
class Position : public Point
{
    typedef std::unique_ptr<Position> PositionPtr;

public:
    int distance;
    std::vector<int> a_x{-1,0,1,0};
    std::vector<int> a_y{0,1,0,-1};
    int start_x=maze.start().x;
    int start_y=maze.start().y;
    int end_x=maze.end().x;
    int end_y=maze.end().y;
    // constructor from coordinates
    Position(int _x,int _y, int _distance){
        x=_x;
        y=_y;
        distance=_distance;
    }

    // constructor from base ecn::Point
    Position(ecn::Point p) : Point(p.x, p.y) {}

    int distToParent()
    {
        // in cell-based motion, the distance to the parent is always 1
        return distance;
    }
    bool is_corridor(int _x,int _y,int &dx,int &dy){
         bool isCorridor=false;
         //int cnt=0;

         if(dx&&(int)maze.isFree(_x+dx,_y)+(int)maze.isFree(_x,_y+1)+(int)maze.isFree(_x,_y-1)==1){
             if(maze.isFree(_x,_y-1)){
                 dx=0;
                 dy=-1;
             }
             else if(maze.isFree(_x,_y+1)){
                 dx=0;
                 dy=1;
             }

             isCorridor=true;
         }
         else if(dy&&(int)maze.isFree(_x,_y+dy)+(int)maze.isFree(_x+1,_y)+(int)maze.isFree(_x-1,_y)==1){
             if(maze.isFree(_x-1,_y)){
                 dx=-1;
                 dy=0;
             }
             else if(maze.isFree(_x+1,_y)){
                 dx=1;
                 dy=0;
             }
             isCorridor=true;
         }

         return isCorridor;
   }


    std::vector<PositionPtr> children() {
        std::vector<PositionPtr> generated;
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        for (int i = 0; i < 4; ++i) {
            if (maze.isFree(x + dx[i], y + dy[i])) {
                int _x = x + dx[i], _y = y + dy[i], steps = 1;
                while (is_corridor(_x, _y, dx[i], dy[i]) && (_x != end_x || _y != end_y)) {
                    _x += dx[i];
                    _y += dy[i];
                    steps++;
                }
                generated.push_back(std::make_unique<Position>(_x, _y, steps));
            }
        }
        return generated;
    }

    void show(bool closed,const Point &parent){
        int _x,_y;
        const int b=closed?255:0,r=closed?0:255;
        std::vector<std::pair<int,int>> flag;

        if(parent.x||parent.y){

       for(int i=0;i<4;i++){
            _x=x+a_x[i];
            _y=y+a_y[i];
            flag.clear();
            if(maze.isFree(_x,_y)){
                flag.push_back({_x,_y});
                while(is_corridor(_x,_y,a_x[i],a_y[i])&&(_x!=start_x||_y!=start_y)){
                    _x+=a_x[i];
                    _y+=a_y[i];
                    flag.push_back({_x,_y});
                }
                if(_x==parent.x&&_y==parent.y){
                    for(const auto &p:flag){
                        maze.write(p.first,p.second,r,0,b,false);
                    }
                    break;
                }
            }
        }
        }
        maze.write(x,y,r,0,b);
    }

    void print(const Point &parent){
        int _x,_y;
        std::vector<std::pair<int,int>> flag;
        if(parent.x||parent.y){
        for(int i=0;i<4;i++){
          _x=x+a_x[i];
          _y=y+a_y[i];
          flag.clear();
          if(maze.isFree(_x,_y)){
              flag.push_back({_x,_y});
              while(is_corridor(_x,_y,a_x[i],a_y[i])&&(_x!=start_x||_y!=start_y)){
                  _x+=a_x[i];
                  _y+=a_y[i];
                  flag.push_back({_x,_y});
              }
              if(_x==parent.x&&_y==parent.y){
                  for(auto p=flag.rbegin();p!=flag.rend();p++){
                      maze.passThrough(p->first,p->second);
                  }
                  break;
              }
          }
        }
        }
        maze.passThrough(x,y);
    }

};

typedef std::pair<int,int> Pair;





int main( int argc, char **argv )
{
    // load file
    std::string filename = Maze::mazeFile("maze.png");
    if(argc == 2)
        filename = std::string(argv[1]);

    // let Point know about this maze
    Position::maze.load(filename);

    // initial and goal positions as Position's
    Position start = Position::maze.start(),
             goal = Position::maze.end();

    // call A* algorithm
    ecn::Astar(start, goal);

    // save final image
    Position::maze.saveSolution("corridor");
    cv::waitKey(0);

}
