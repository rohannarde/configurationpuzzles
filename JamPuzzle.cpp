// File:         $Id: JamPuzzle.cpp,v 1.2 2011/05/06 00:08:23 rsn5770 Exp $
// Author:       Anand Rathod
// Description:	 Contains the main method to initiate the Traffic
//Jam puzzle and take input values from user.
// Revisions:
//              $Log: JamPuzzle.cpp,v $
//              Revision 1.2  2011/05/06 00:08:23  rsn5770
//              Function removed .
//              Indentations checked.
//              Destructor added.
//
//              Revision 1.1  2011/05/06 00:03:46  p334-70c
//              Initial revision
//
//              Revision 1.1  2011/04/03 18:25:05  agr5046
//              Initial revision
//
//

#include "JamPuzzle.h"
using namespace std;

// Constructor for input of initial time, destination time and number
// of hours on the dial.
JamPuzzle::JamPuzzle(const int & dimension1, const int & dimension2,
                     const vector< vector<int> > carPositions,
                     const set<int> freeSpaceInLot,
                     const vector< vector <int> > move,
                     const vector< vector<int> > & path)
    :_dimension1(dimension1), _dimension2(dimension2), cars(carPositions),
    freeSpace(freeSpaceInLot),
    pathForDestination(path)
{
    for(int i=0; i<move.size(); i++)
    {
        pathForDestination.push_back(move[i]);
    }
}


// condition to check whether the conditions are met or not.
bool JamPuzzle::IsPuzzleComplete() const
{

    vector<int> temp = cars[cars.size()-1];

    if( (temp[2]+1) % _dimension2 == 0)
        return true;
    else
        return false;
}

// Returns the trace of path for solution.
vector<vector<int> > JamPuzzle::pathForSolution() const
{
    return pathForDestination;
}

// Returns the possible moves for that point.
void JamPuzzle::getPossibleMoves(list<JamPuzzle>  & possibleMoves)
{

    for(unsigned int i=0; i< cars.size(); i++)
    {
        vector<int> carMove;
        vector< vector<int> > movesMade;

        //Vertical movements
        if(cars[i][0] == 0)
        {
            set<int> freePos = freeSpace;
            vector< vector<int> > carTemp = cars;


            //check for top free spaces.
            int top = cars[i][1] - _dimension1;
            while (top >=0 && freePos.find(top)!=freePos.end())
            {
                vector<int> carDimensions = carTemp[i];

                carMove.push_back(i);
                carMove.push_back(carDimensions[1]);
                carMove.push_back(carDimensions[2]);
                carMove.push_back(carDimensions[1] -
                                  _dimension1);
                carMove.push_back(carDimensions[2] -
                                  _dimension1);

                movesMade.push_back(carMove);

                freePos.erase(top);
                freePos.insert(carDimensions[2]);

                carDimensions[1] = carDimensions[1] - _dimension1;
                carDimensions[2] = carDimensions[2] - _dimension1;
                carTemp[i] = carDimensions;

                JamPuzzle newCarMove(_dimension1, _dimension2,
                                     carTemp, freePos, movesMade,
                                     pathForDestination);
                possibleMoves.push_back(newCarMove);

                carMove.clear();
                top = top - _dimension1;
            }

            carTemp.clear();
            carTemp = cars;
            freePos.clear();
            freePos = freeSpace;
            movesMade.clear();

            //check for bottom free spaces.
            int bottom = cars[i][2] + _dimension1;
            while (bottom <= ((_dimension1 * _dimension2) - 1)
                    && freePos.find(bottom)!=freePos.end())
            {
                vector<int> carDimensions = carTemp[i];

                carMove.push_back(i);
                carMove.push_back(carDimensions[1]);
                carMove.push_back(carDimensions[2]);
                carMove.push_back(carDimensions[1] + _dimension1);
                carMove.push_back(carDimensions[2] + _dimension1);

                movesMade.push_back(carMove);

                freePos.erase(bottom);
                freePos.insert(carDimensions[1]);

                carDimensions[1] = carDimensions[1] + _dimension1;
                carDimensions[2] = carDimensions[2] + _dimension1;
                carTemp[i] = carDimensions;

                JamPuzzle newCarMove(_dimension1, _dimension2,
                                     carTemp, freePos, movesMade,
                                     pathForDestination);
                possibleMoves.push_back(newCarMove);

                carMove.clear();
                bottom = bottom + _dimension1;
            }

            movesMade.clear();
        }

        else  // Horizontal movements
        {
            vector< vector<int> > carTemp = cars;
            set<int> freePos = freeSpace;

            //check for left free spaces.
            int left = cars[i][1] - 1;
            while ( ((left + 1) % _dimension2 !=0) &&
                    freePos.find(left)!= freePos.end())
            {
                vector<int> carDimensions = carTemp[i];

                carMove.push_back(i);
                carMove.push_back(carDimensions[1]);
                carMove.push_back(carDimensions[2]);
                carMove.push_back(carDimensions[1] - 1);
                carMove.push_back(carDimensions[2] - 1);

                movesMade.push_back(carMove);

                freePos.erase(left);
                freePos.insert(carDimensions[2]);

                carDimensions[1] = carDimensions[1] - 1;
                carDimensions[2] = carDimensions[2] - 1;
                carTemp[i] = carDimensions;

                JamPuzzle newCarMove(_dimension1, _dimension2,
                                     carTemp, freePos, movesMade,
                                     pathForDestination);
                possibleMoves.push_back(newCarMove);

                carMove.clear();
                left--;
            }

            carTemp.clear();
            carTemp = cars;
            freePos.clear();
            freePos = freeSpace;
            movesMade.clear();

            //check for right free spaces.
            int right = cars[i][2] + 1;
            while ((right % _dimension2 !=0) &&
                    freePos.find(right)!=freePos.end())
            {
                vector<int> carDimensions = carTemp[i];

                carMove.push_back(i);
                carMove.push_back(carDimensions[1]);
                carMove.push_back(carDimensions[2]);
                carMove.push_back(carDimensions[1] + 1);
                carMove.push_back(carDimensions[2] + 1);

                movesMade.push_back(carMove);

                freePos.erase(right);
                freePos.insert(carDimensions[1]);

                carDimensions[1] = carDimensions[1] + 1;
                carDimensions[2] = carDimensions[2] + 1;
                carTemp[i] = carDimensions;

                JamPuzzle newCarMove(_dimension1, _dimension2,
                                     carTemp, freePos, movesMade,
                                     pathForDestination);
                possibleMoves.push_back(newCarMove);

                carMove.clear();
                right++;
            }

            movesMade.clear();
        }
    }
}

// Overloaded == operator for compairsion.
bool JamPuzzle::operator==(JamPuzzle & check) const
{

    if(cars == check.cars)
        return true;
    else
        return false;
}

// Overloaded < operator for comparision.
bool JamPuzzle::operator<(const JamPuzzle & check) const
{
    return (cars < check.cars);
}


// Destructor.
JamPuzzle::~JamPuzzle()
{
}
