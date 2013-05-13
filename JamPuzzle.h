// File:         $Id: JamPuzzle.h,v 1.2 2011/05/06 00:10:31 rsn5770 Exp rsn5770 $
// Author:       Anand Rathod Rohan Narde
// Description:  Provides the method declaration for Traffic Jam problem solving.
// Revisions:
//              $Log: JamPuzzle.h,v $
//              Revision 1.2  2011/05/06 00:10:31  rsn5770
//              Function declaration added
//              Indetantions added
//              Comments added
//
//              Revision 1.1  2011/05/06 00:04:20  p334-70c
//              Initial revision
//
//              Revision 1.1  2011/04/21 19:44:06  agr5046
//              Initial revision
//
//

#ifndef JAM_PUZZLE_H
#define JAM_PUZZLE_H


#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


class JamPuzzle
{

private:

    int _dimension1;
    int _dimension2;
    vector< vector<int> > pathForDestination;
    vector< vector<int> > cars;
    set<int> freeSpace;

public:

    // Constructor for input of initial time, destination time and number
    // of hours on the dial.
    JamPuzzle(const int & dimension1, const int & dimension2,
              const vector< vector<int> > carPositions,
              const set<int> freeSpaceInLot,
              const vector<vector <int> > move,
              const vector< vector<int> > & path);

    // condition to check whether the conditions are met or not.
    bool IsPuzzleComplete() const;

    // Returns the trace of path for solution.
    vector< vector<int> > pathForSolution() const;

    // Returns the possible moves for that point.
    void getPossibleMoves(list<JamPuzzle> & possibleMoves);

    // Overloaded == operator for compairsion.
    bool operator==(JamPuzzle & check) const;

    // Overloaded < operator for comparision.
    bool operator<(const JamPuzzle & check) const;

    // Destructor.
    ~JamPuzzle();
};
#endif
