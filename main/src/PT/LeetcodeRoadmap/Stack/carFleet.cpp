#include <iostream>
#include <vector>

/*
    There are n cars going to the same destination along a one-lane road. The destination is target miles away.

    You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] 
    is the speed of the ith car (in miles per hour).

    A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. 
    The faster car will slow down to match the slower car's speed. The distance between these two cars is ignored (i.e., they are assumed to have the same position).

    A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

    If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

    Return the number of car fleets that will arrive at the destination.

    

    Example 1:

    Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
    Output: 3
    Explanation:
    The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12.
    The car starting at 0 does not catch up to any other car, so it is a fleet by itself.
    The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
    Note that no other cars meet these fleets before the destination, so the answer is 3.
*/

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        // check if any car moved in the respective iteration
        bool moved = false;
        int nrOfFleets = 0;

        do
        {
            moved = false;
            bool fleetAtEnd = false;

            // move the cars out of the race if they reached the target
            for (int i = 0; i < position.size(); i++)
            {
                if (position[i] == target)
                {
                    position[i] = target + 1;
                    fleetAtEnd = true;
                }
                
            }
            if (fleetAtEnd)
            {
                nrOfFleets++;
                fleetAtEnd = !fleetAtEnd;
            }
            
            

            // iterate through all the positions and if they haven't reached the target move them (1 iteration - 1h)
            for (int i = 0; i < position.size(); i++)
            {
                if (position[i] < target)
                {
                    if ((position[i] + speed[i]) <= target)
                    {
                        position[i] += speed[i];
                    } else {
                        position[i] = target;
                    }
                    
                    moved = true;
                }
                
            }

            // check if any fleet has been made and change their speed
            for (int i = 0; i < position.size(); i++)
            {
                if (position[i] < target)
                {
                   checkFleet(i, target, position, speed);
                }
                
            }
            
            
        } while (moved);

        return nrOfFleets;
        
    }

    bool checkFleet(int i, int target, std::vector<int>& position, std::vector<int>& speed) {
        for (int j = 0; j < position.size(); j++)
        {
            if (j != i && position[j] == position[i] && position[j] < target)
            {
                if (speed[i] > speed[j])
                {
                    speed[i] = speed[j];
                } else if (speed[i] < speed[j]) {
                    speed[j] = speed[i];
                } else {
                    return false;
                }
                
                return true;
            }
            
        }
        
        return false;
    }
};

int main() {
    Solution s;
    int target = 12;
    std::vector<int> position = {10, 8, 0, 5, 3};
    std::vector<int> speed = {2, 4, 1, 1, 3};

    std::cout << s.carFleet(target, position, speed) << std::endl;

    return 0;
}