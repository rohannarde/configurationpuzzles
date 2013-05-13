// File:         $Id: jam.cpp,v 1.2 2011/05/06 00:11:46 rsn5770 Exp $
// Author:       Anand Rathod
// Description:	 Contains the main method to initiate the 
// Traffic jam puzzle and take input values from user.
// Revisions:
//              $Log: jam.cpp,v $
//              Revision 1.2  2011/05/06 00:11:46  rsn5770
//              error messages revised
//              indentations checked
//
//              Revision 1.1  2011/05/06 00:03:46  p334-70c
//              Initial revision
//
//              Revision 1.1  2011/04/03 18:25:05  agr5046
//              Initial revision
//
//

#include <iostream>
#include <vector>
#include <set>
#include "JamPuzzle.h"
#include <fstream>
#include "Solver.h"
using namespace std;

int main(int argc, char *argv[])
{
    int invalidInputs = 0;

    if (argc != 3)
    {
        cerr << "Usage : ./jam input output" << endl;
        return -1;
    }

    istream *isp;
    ifstream ifs;
    ostream *osp;
    ofstream ofs;

    if (argv[1][0] == '-' && argv[1][1] == '\0')
    {
        isp = &cin;
    }
    else
    {
        ifs.open(argv[1]);
        if(ifs.is_open())
            isp = &ifs;
        else
            invalidInputs = 1;
    }
    istream &is = *isp;

    if (argv[2][0] == '-' && argv[2][1] == '\0')
    {
        osp = &cout;
    }
    else
    {
        ofs.open(argv[2]);

        if(ofs.is_open())
            osp = &ofs;
        else
            invalidInputs =1;
    }

    ostream &os = *osp;

    // 0- vertical, 1- horizontal
    int parkingLotDimension;

    int dimension1;
    int dimension2;

    vector< vector<int> > pathForDestination;
    vector< vector<int> > cars;
    set<int> freeSpace;
    vector< vector<int> > movesMade;


    if (invalidInputs!=1)
    {
        is>>dimension1;
        is>>dimension2;

        int size=0;

        is>>size;

        if(size>= dimension1 * dimension2)
        {
            cout<<"Invalid inputs";
            return -1;
        }

        for(int i=0; i<size; i++)
        {
            vector<int> values;
            int val1,val2,val3,val4;

            is>>val1;
            is>>val2;
            is>>val3;
            is>>val4;

            if(val1 < 0 || val2 <0 || val3 <0 ||
                    val4 <0 || val1 > dimension2 - 1 || val3 > dimension2 -1 ||
                    val2 > dimension1 -1 || val4 > dimension1 -1)
            {
                invalidInputs =1;
                break;
            }

            if( (val1 == val3 && val2 == val4))
            {
                invalidInputs =1;
                break;
            }

            if(val1 == val3)
                values.push_back(0);
            else
                values.push_back(1);

            values.push_back(val1 + dimension2 * val2);
            values.push_back(val3 + dimension2 * val4);

            cars.push_back(values);
        }

        for(int i=0; i< dimension1 * dimension2; i++)
            freeSpace.insert(i);

        for(unsigned int i=0; i<cars.size(); i++)
        {
            if(cars[i][0] == 0)
            {
                for(int j = cars[i][1];
                        j<=cars[i][2]; j = j + dimension1)
                    freeSpace.erase(j);
            }
            else
            {
                for(int j = cars[i][1];
                        j<=cars[i][2]; j = j + 1)
                    freeSpace.erase(j);
            }
        }

        if(freeSpace.empty())
            invalidInputs =1;
    }

    else
    {
        cout << "Unable to open file"<<endl;
        cout<<"no solution exists";
        return -1;
    }


    if(invalidInputs ==1)
    {
        cout<<"Invalide input"<<endl;
        cout<<"no solution exists";
        return -1;
    }


    JamPuzzle jamPuzzle(dimension1, dimension2, cars,
                        freeSpace, movesMade, pathForDestination);

    Solver<JamPuzzle> solver(jamPuzzle);
    // Solver initialized.
    JamPuzzle sol(solver.solve());
    // Checking for possible best solution.

    if (sol.IsPuzzleComplete())
    {

        os << "Possible Best Solution :" << endl;
        vector< vector<int> > solveList(sol.pathForSolution());


        for(unsigned int i=0; i<solveList.size(); i++)
        {
            vector<int> temp = solveList[i];

            os<<"move car from position : "<<temp[1]<<" "<<
            temp[2]<<" to position : "<<temp[3]<<" "<<temp[4]<<endl;
        }
    }
    else
        cout << "There is no solution for given problem" << endl;


    return 0;
}
