#include <treasure_hunt_ai.h>
#include <duels/utils/grid_point.h>

#include <duels/algo/a_star.h>

constexpr int FREE{0};
constexpr int ROCK{1};
constexpr int UNKNOWN{2};

TreasureHuntAI::TreasureHuntAI()
  : map(20, 30, UNKNOWN) // fill the 20x30 map with 2's (unknown)
{
  // register this map for all grid points
  pose.setMap(map);

  // TODO the treasure may be at any position: update candidates
  for(int x = 0; x < map.height(); x++) {
      for(int y = 0; y < map.width(); y++) {
          candidates.emplace_back(x,y);
//          std::cout<< map.height() << std::endl;
//          std::cout<< x*map.height() + y << std::endl;
//          std::cout << candidates[x*map.height() + y] << std::endl;
      }
  }
}

Action TreasureHuntAI::computeFrom(const Feedback &feedback)
{
  // register where we are
  pose.set(feedback.pose);
  // if we are here then it is not a treasure position
  removeCandidate(pose);

  // TODO process feedback.scan to update map
  for(const auto &[x,y,rock]: feedback.scan)
  {
      if (rock == true) {
          map.cell(x,y) = ROCK;
      } else {
          map.cell(x,y) = FREE;
      }
  }

  // Function to process feedback.treasure_distance to update candidates
  // as we compare floating points, a small threshold is useful to tell if two values are equal
  const auto threshold{1};
  pruneCandidates([&](const Vector2D<int> &candidate)
  {
    // TODO return true if this candidate cannot be the treasure position
    Vector2D vec(feedback.pose.x, feedback.pose.y);
    auto distance = candidate.distance(vec);
    if (abs(distance-feedback.treasure_distance) > threshold) return true;

    return false;
  });

//  // use A* to find shortest path to first candidate, will assume unknown cells are free
  const auto path{Astar(pose, candidates[0])};
  const auto next{path[1]};
//  // need a condition when next is a rock

  Action action; // compute it from pose and next
//  // TODO identify which move from pose to next

  std::cout << "next: " << map.cell(next) << std::endl;
//  // TODO do not use Action::MOVE if the next cell is unknown
  if (next.orientation == pose.orientation) {
      action = Action::MOVE;
  } else {
      action = Action::TURN_LEFT;
  }
  if(map.cell(next) == UNKNOWN){
      action = Action::SONAR;
  }

  return action;
}
