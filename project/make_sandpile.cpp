#include <algorithm>
#include <fstream>
#include <iterator>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "make_sandpile.h"
using namespace std;

// define a function for generating a random sandpile given a size and count

Sandpile make_sandpile::generate(int S,int N)
{
    
    //creations
    Sandpile P; //sandpile
    mt19937_64 eng(1337); //engine
    uniform_int_distribution<int> distro(0,S); //distrobution



    for(int i = 0; i < S; i++)
    {
        Row node(S,0);
        P.push_back(node);
    }


    for(int i = 0; i < N; i++)
    {
        int x = distro(eng);
        int y = distro(eng);
        P[x][y]++;
    }

    return P;
}
// define a function for reading a sandpile from a file given its filename
Sandpile make_sandpile::readSandpile(ifstream &file){
    Sandpile Pile;
    string buffer="";
    
    while(getline(file,buffer))
    {
        istringstream ss(buffer);
        copy(istream_iterator<int>(ss), {}, back_inserter(Pile.emplace_back()));
    }
    
    return Pile;
}
