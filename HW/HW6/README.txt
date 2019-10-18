HOMEWORK 6: BATTLESHIP RECURSION


NAME:  < insert name >



COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Vivek Verghese >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < insert 45 hours >



ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:
(order notation & concise paragraph, < 200 words)
The dimensions of the board (w and h) 
The number of ships (s)? 
The total number of occupied cells (o) or open water (w)? 
The number of constraints (c)? 
The number of unknown sums (u) or unspecified ship types (t)? 
Etc. 

With the dimensions of the board, the worst possible scenario is that it runs O(w*h) it terms of big O notation. Secondly, in terms of the number of ships, the program runs at a speed of O(s) in respect to the number of ships. In terms of the number of occupied cells, it runs by O(o*w) because that is the dimensions of the board. Next, the number of contraints run time would be O(w*h) because you are parsing thorugh by a 2D vector. The number of unknowns I don't know because I didn't quite get up to it.


SUMMARY OF PERFORMANCE OF YOUR PROGRAM ON THE PROVIDED PUZZLES:
# of solutions & approximate wall clock running time for different
puzzles for a single solution or all solutions.

IN this assignment I can firmly say that I had puzzle 1 working with a timestamp of 1 second, puzzle 2 with a time of 2.35 seconds, and puzzle sample with contraints with a run time of 2 seconds. Furthermore I had written but couldn't implement optimizations. These optimizations would have hypothetically lowered my run time by a lot. Specifically fillWater and fillShips would have been able to very easily assumed that a row were to be completely filled with the respective type of filling. Therefore taking out as much as an entire row or column before the recursion was handled.



MISC. COMMENTS TO GRADER:  
(optional, please be concise!)
I wrote a lot of additional code that ultimately didn't work. Please take a look at is as conceptually it was there and pretty close to the correct algorithm. Thank you.


