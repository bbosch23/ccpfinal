#include "sandpile.h"
using namespace std;

// define a function that takes a Sandpile by reference and returns a bool (to indicate if the Sandpile is stable)
bool sandpile::nodeExists(Sandpile P) 
{
    int Psize = P.size();
    //checking to see if node >= 4 exists
    for(int i = 0; i < Psize; i++) //loop for rows
    {
        for(int j = 0; j < Psize; j++) //loop thru nodes of pile
        {
            if(P[i][j] >= 4) //node exists that is > or = to 4
            {
            return true; //return true
            }
        }
    }
    return false; //no node found.

}