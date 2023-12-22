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
    //Position(int _x, int _y) : Point(_x, _y) {}
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

   bool is_corridor(int _x,int _y,int &a_x,int &a_y){
        bool cor=false;
        //int cnt=0;

        if(a_x&&(int)maze.isFree(_x+a_x,_y)+(int)maze.isFree(_x,_y+1)+(int)maze.isFree(_x,_y-1)==1){
            if(maze.isFree(_x,_y-1)){
                a_x=0;
                a_y=-1;
            }
            else if(maze.isFree(_x,_y+1)){
                a_x=0;
                a_y=1;
            }

            cor=true;
        }
        else if(a_y&&(int)maze.isFree(_x,_y+a_y)+(int)maze.isFree(_x+1,_y)+(int)maze.isFree(_x-1,_y)==1){
            if(maze.isFree(_x-1,_y)){
                a_x=-1;
                a_y=0;
            }
            else if(maze.isFree(_x+1,_y)){
                a_x=1;
                a_y=0;
            }
            cor=true;
        }

        return cor;
    }


  /*std::vector<PositionPtr> children()
    {
        // this method should return  all positions reachable from this one
        std::vector<PositionPtr> generated;


        int _x,_y;
        int steps;

        for(int i=0;i<4;i++){
            _x=x+a_x[i];
            _y=y+a_y[i];
            steps=1;
            if(maze.isFree(_x,_y)){
                while(is_corridor(_x,_y,a_x[i],a_y[i])&&(_x!=goal_x||_y!=goal_y)){
                        _x+=a_x[i];
                        _y+=a_y[i];
                        steps++;
                }
                generated.push_back(std::make_unique<Position>(_x,_y,steps));
            }
        }


        return generated;
    }*/
    /*try*/
   std::vector<PositionPtr> children()
   {
       // this method should return  all positions reachable from this one
       std::vector<PositionPtr> generated;
       int _x,_y;
       int ax,ay;
       int steps=1;

       if(maze.isFree(x-1,y)){
           ax=-1;
           ay=0;
           _x= x+ax;
           _y= y+ay;
           while(is_corridor(_x,_y,ax,ay) && (_x != end_x || _y!=end_y)){
               _x += ax;
               _y += ay;
               steps++;
           }
           generated.push_back(std::make_unique<Position>(_x, _y, steps));
       }

       if(maze.isFree(x+1,y)){
           ax=1;
           ay=0;
           _x= x+ax;
           _y= y+ay;
           while(is_corridor(_x,_y,ax,ay) && (_x != end_x || _y!=end_y)){
               _x += ax;
               _y += ay;
               steps++;
           }
           generated.push_back(std::make_unique<Position>(_x, _y, steps));
       }

       if(maze.isFree(x,y-1)){
           ax=0;
           ay=-1;
           _x= x+ax;
           _y= y+ay;
           while(is_corridor(_x,_y,ax,ay) && (_x != end_x || _y!=end_y)){
               _x += ax;
               _y += ay;
               steps++;
           }
           generated.push_back(std::make_unique<Position>(_x, _y, steps));
       }

       if(maze.isFree(x,y+1)){
           ax=0;
           ay=1;
           _x= x+ax;
           _y= y+ay;
           while(is_corridor(_x,_y,ax,ay) && (_x != end_x || _y!=end_y)){
               _x += ax;
               _y += ay;
               steps++;
           }
           generated.push_back(std::make_unique<Position>(_x, _y, steps));
       }
       return generated;
   }
    /*try_end*/

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
    Position::maze.saveSolution("101x201_corridor");
    cv::waitKey(0);

}
