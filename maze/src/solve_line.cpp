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
    // constructor from coordinates
    Position(int _x, int _y) : Point(_x, _y) {}

    // constructor from base ecn::Point
    Position(ecn::Point p) : Point(p.x, p.y) {}

    Position(int _x, int _y, int _distance)
    {
        x = _x;
        y = _y;
        distance = _distance;
    }

    int distToParent()
    {
        // in cell-based motion, the distance to the parent is always 1
        return distance;
    }

    bool is_line(int x, int y)
    {
        //Corners,Intersections and Dead end
        if((Position::maze.isFree(x+1,y) && Position::maze.isFree(x-1,y)) &&
           (!Position::maze.isFree(x,y+1) && !Position::maze.isFree(x,y-1)))
                return true;
        else if((!Position::maze.isFree(x+1,y) && !Position::maze.isFree(x-1,y)) &&
                (Position::maze.isFree(x,y+1) && Position::maze.isFree(x,y-1)))
                return true;
        else
            return false;

    }


    std::vector<PositionPtr> children()
    {
        // this method should return  all positions reachable from this one
        std::vector<PositionPtr> generated;

        // TODO add free reachable positions from this point
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        for(int i = 0; i < 4; ++i) {
            int localDistance = 1;
            int newX = x + dx[i], newY = y + dy[i];
            if(Position::maze.isFree(newX, newY)) {
                while (is_line(newX, newY)){
                    newX += dx[i];
                    newY += dy[i];
                    localDistance++;
                }
                generated.push_back(std::make_unique<Position>(newX, newY, localDistance));
            }
            std::cout << localDistance << std::endl;
            // Create a new Position only if it's different from the current

        }
        return generated;
    }
};



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
    Position::maze.saveSolution("line");
    cv::waitKey(0);

}
