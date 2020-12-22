#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "sandpile.h"
using namespace std;

class make_sandpile{
public:
// forward declare a function for generating a random sandpile given a size and count
Sandpile generate(int S,int N);
// forward declare a function for reading a sandpile from a file given its filename
Sandpile readSandpile(ifstream &file);

};
