#include <string>
#include <vector>


#include <ruc-sci-comp/animate.hpp>

#include "sandpile.h"
#include "make_sandpile.h"
using namespace std;

int main(int argc, char **argv)
{
    make_sandpile Doer;
    Sandpile P; // starting sandpile


    //INPUT VALIDATION below 
    if(argc == 1)
    {
        cout<<"ERROR only name given"<<endl;
        return 0;
    }
    else if(argc == 2) //pogram name and file name
    {
        ifstream inputFile(argv[1]);

        P=Doer.readSandpile(inputFile); //function to read from file

        inputFile.close();
        //cout<<"File read"<<endl;
    }
    else if(argc == 3) //program name size and count
    {
        //stoi string to int argv[x] is string
         P=Doer.generate(stoi(argv[1]), stoi(argv[2])); //generates sanpile with arguments passi
         cout<<"Generation went well"<<endl;
    }
    else
    {
        cout<<"invalid arguments please try again"<<endl;
        return 0;
    }
    
    //cout<<"Argument checks complete"<<endl;

    //animation declaration
    Animation animator;
    animator.push_back(P);

    sandpile stablizer; // used to check if variable exists

    int mSize=P.size(); //work around for not being able to use P.size while itorating over vector

    //cout<< "Starting grid with size" <<endl;
    //cout<< mSize << endl;

    //cout<<"Work has begun"<<endl;
    while(stablizer.nodeExists(P)) // a node >=4 exists
    {   
        Sandpile fP; //final pile.
        for(int i = 0; i < mSize; i++)
        {
            Row nodes(mSize,0); //row of nodes
            fP.push_back(nodes);
        }

        //DO THE MATH 
        for (int i = 0; i < mSize; i++) // ROW
        {
            for (int j = 0; j < mSize; j++) //COLUMN 
            {
                //NODE ALL WORK DO IN HERE
                //P[i][j]  <-- for current node
                

                if(P[i][j] >= 4) //check node for >= 4
                {
                    // subtract 4 from e
                    fP[i][j] = P[i][j] - 4;

                    // add 1 to the neighbor north of e ** (-1 to i index if < 0 do nothing)
                    if(i-1 >= 0)
                    {
                        fP[i-1][j] = P[i-1][j] + 1;
                    }

                    // add 1 to the neighbor south of e ** HOW TO CHECK FOR OUT OF ARRAY BOUNDS???? COUNT? SIZE?
                    if(i > mSize) //CHECK IF ONE LARGER THAN NUMBER OF ROWS
                    {
                        fP[i+1][j] = P[i+1][j] + 1;
                    }
                    // add 1 to the neighbor east of e  ** HOW TO CHECK FOR OUT OF ARRAY BOUNDS???? COUNT? SIZE?
                    if(j > mSize) //CHECK IF ONE LARGER THAN SIZE OF ROW
                    {
                        fP[i][j+1] = P[i][j+1] + 1;
                    }
                    // add 1 to the neighbor west of e  ** (-1 to j index if < 0 do nothing)
                    if(j-1 >= 0)
                    {
                        fP[i][j-1] = P[i][j-1] + 1;
                    }
                    
                }
                else //node is less than 4
                {
                    fP[i][j]=P[i][j]; // node is stored into final pile
                }
                
            }
            
        }
        animator.push_back(fP);
        P=fP;
        
    }
    //cout<<"about to produce animaiton see below starting"<<endl;


    //PRODUCE ANIMATION
    animate(animator); 
    //cout<<"Animaiton complete"<<endl;
    return 0;
}
