Brief Project Overview: https://github.com/bbosch23/ccpfinal.git
Our project was to create the Abelian Sandpile. We implemented the algorithm that was given to us in Pseudocode into our main function.
Project Structure/ Organization:
The files that were already given and needed to be modified were:
Main.cpp
Sandpile.cpp
Make_Sandpile.cpp
Sandpile.h
Make_Sandpile.h
In main.cpp, we 
To compile →
To run → 
In sandpile.cpp, we defined a function that takes a Sandpile by reference and returns a bool to indicate if the Sandpile is stable by using a for loop and set of conditional statements.
In make_sandpile.cpp, we defined a function to generate a random sandpile given a size and count. We also defined a function to read a sandpile from a file.
In make_sandpile.h, we did a forward declaration of the functions mentioned above.
In sandpile.h, we did a forward declaration of a function that takes a Sandpile by reference and returns a bool to indicate if the Sandpile is stable.
Data Visualization & Animation:
As much as we would have loved to see the full animation, we were only able to successfully get the 10x10 grid to perform properly.
Challenges, Struggles, & Issues:
Had struggles understanding what functions were to be passed and how to use them correctly at the start.
When running the code we found out that when feeding it size and count, the program started to throw seg. faults. This happened too late in our development and it was too late to find out why this started happening.
Before the above issue, we could only make sandpile under 15x15. Anything larger would unfortunately continue to throw errors.
When using the sandpile files, the large files threw the same errors as above, and as a result, it would cause docker to freeze and crash shutting down VS Code and with the need of being restarted.
Brian had major docker issues through development.

Takeaways:
Start development earlier. We had code that was still a work in progress until last night and even then we still had and are continuing to have problems.
Communicate better. After starting we should have asked for guidance and further clarification on specific parts of the assignment.
