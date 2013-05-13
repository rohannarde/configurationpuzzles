// File:         $Id: WaterJugPuzzle.cpp,v 1.2 2011/04/21 22:34:09 rsn5770 Exp rsn5770 $
// Author:       Anand Rathod Rohan Narde
// Description:	Provides the method implementation for Water Jug problem solving.
// Revisions:
//              $Log: WaterJugPuzzle.cpp,v $
//              Revision 1.2  2011/04/21 22:34:09  rsn5770
//              methods revised , comments added
//
//              Revision 1.1  2011/04/21 22:22:03  p334-70c
//              Initial revision
//
//              Revision 1.1  2011/04/03 18:25:05  agr5046
//              Initial revision
//
//

#include "WaterJugPuzzle.h"
using namespace std;

// Constructor for input of initial time, destination time and number
// of hours on the dial.
WaterJugPuzzle::WaterJugPuzzle(const int & currentJugIndex,
const int & destinationJugIndex, const int & finalValue,
const vector<int> &jugValues, const vector<int> &jugSizes , 
const vector< vector<int> > & path, const int & oper)
:currentContainerIndex(currentJugIndex), 
destinationContainerIndex(destinationJugIndex), 
finalDestinationValue(finalValue), containerValues(jugValues) ,
containerSizes(jugSizes), pathForDestination(path), operation(oper){

				   
	static double counter = 0;
	index = counter++;
	vector<int> values; // keeps track for the moves made to reach solution.

	// Enters values to keep track of the destination path.
	values.push_back(currentContainerIndex);
	values.push_back(destinationContainerIndex);
	values.push_back(operation);

	pathForDestination.push_back(values);
}

// condition to check whether the conditions are met or not.
bool WaterJugPuzzle::IsPuzzleComplete() const{

	if(containerValues[currentContainerIndex] == finalDestinationValue || 
		containerValues[destinationContainerIndex] == finalDestinationValue)
		return true;
	else
		return false;
}

// Returns the trace of path for solution.
vector< vector<int> > WaterJugPuzzle::pathForSolution() const{
  return pathForDestination;
}
  
// Returns the possible moves for that point.
void WaterJugPuzzle::getPossibleMoves(list<WaterJugPuzzle>  & possibleMoves){

	for(unsigned int j=0; j<containerSizes.size(); j++)
	{
		currentContainerIndex = j; // denotes the current jar.

		// Generating moves for empty jar.
		if(containerValues.at(currentContainerIndex) == 0)
		{
			int temp = containerValues.at(currentContainerIndex);

			containerValues.at(currentContainerIndex) = 
				containerSizes.at(currentContainerIndex);

			operation = 0;  // denotes fill operation.
			WaterJugPuzzle move(currentContainerIndex, currentContainerIndex, 
				finalDestinationValue, containerValues, containerSizes , 
				pathForDestination,operation);

			possibleMoves.push_back(move);

			containerValues.at(currentContainerIndex) = temp;
		}
		else
		{
			for(unsigned int i=0; i < containerValues.size(); i++)
			{
				// Generating moves by taking out jar contents.
				if(i==j)
				{
					int currentValue = containerValues.at(currentContainerIndex);
					containerValues.at(currentContainerIndex) = 0;
					operation =1;  // Denotes empty operation.

					WaterJugPuzzle move(currentContainerIndex, i, finalDestinationValue,
					containerValues, containerSizes , pathForDestination,operation);

					possibleMoves.push_back(move); 

					containerValues.at(currentContainerIndex) = currentValue;
				}
				else
				{
					// Generating moves for jar while it is full.
					if(containerValues.at(i) == containerSizes.at(i))
					{
					}
					else
					{
						if(containerValues.at(currentContainerIndex) <=
						(containerSizes.at(i) - containerValues.at(i)))
						{
							int currentValue = containerValues.at(currentContainerIndex);
							int destinationValue = containerValues.at(i);

							containerValues.at(i) = containerValues.at(i) + containerValues.at(currentContainerIndex);
							containerValues.at(currentContainerIndex) = 0;

							operation = 2;  // denotes pour operation.
							WaterJugPuzzle move(currentContainerIndex, i, finalDestinationValue,
							containerValues, containerSizes , pathForDestination,operation);

							possibleMoves.push_back(move); 

							containerValues.at(currentContainerIndex) = currentValue;
							containerValues.at(i) = destinationValue;
						}
						else
						{
							// Generating moves for jar for transfering its contents to another jar.	
							int currentValue = containerValues.at(currentContainerIndex);
							int destinationValue = containerValues.at(i);

							int temp=0;

							if(containerValues.at(currentContainerIndex) <= (containerSizes.at(i) - containerValues.at(i)))
								temp  = containerValues.at(currentContainerIndex);
							else
								temp = containerSizes.at(i) - containerValues.at(i);
							
							containerValues.at(currentContainerIndex) = containerValues.at(currentContainerIndex) - temp;
							containerValues.at(i) = containerValues.at(i) + temp;

							operation = 2; // denotes pour operation.
							WaterJugPuzzle move(currentContainerIndex, i, finalDestinationValue,
							containerValues, containerSizes , pathForDestination, operation);

							possibleMoves.push_back(move);

							containerValues.at(currentContainerIndex) = currentValue;
							containerValues.at(i) = destinationValue;
						}
					}
				}		
			}
		}	
	}
}

// Overloaded == operator for compairsion.
bool WaterJugPuzzle::operator==(WaterJugPuzzle & check) const{
	return containerValues == check.containerValues;
}

// Overloaded < operator for comparision.
bool WaterJugPuzzle::operator<(const WaterJugPuzzle & check) const{
	return  index < check.index ;
}

// Destructor.
WaterJugPuzzle::~WaterJugPuzzle(){
}
