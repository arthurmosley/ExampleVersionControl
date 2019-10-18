HOMEWORK 7: MINIBLAST


NAME:  < Arthur Mosley >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Vivek, Ramin, Ding, Andrew Aikens>

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 20 >


HASH FUNCTION DESCRIPTION

As for my hash function, I made a vector of HashNodes. Each index in the vector is HashNode which has the elements of a key and a value. Therefore, it was very similar to handling it as a pair. Within each one I have the values of the integer and a string representing the segments of the DNA information.





HASH TABLE IMPLEMENTATION
As for the implementation. Upon starting I thought of just streaming in value by value but I thought that was way less efficient than handling it as just a large string. THerefore I took the approach of streaming an entire segment of data. In order to find the proper location I used code found online which helped hash the information. Hashing the information gave me the proper location. Furthermore, I attempted to implement the linear probing. Linear probing was meant to check if something already exists within the hash map, then find the closest next location available. Lastly, I called the function that resizes that makes the hash map larger in the case of going over the ratio given.






ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:
(order notation & concise paragraph, < 200 words)

L = length of the genome sequence
q - query length
p - number of different locations where key is found
k - key size (k-mer size)

How much memory will the map data structure require (order notation for memory use)?

O(L) since the length of the genome sequence is what gets sent in as a whole every time.

What is the order notation for performance (running time) of each of
the commands?

resize ----------> O(1)
find ----------> O(p) because of how many key sized.
insertion ------------> O(L) since when I'm feeding in the genome sequence I fill it in all at the same time. IN general it also just matters on how long it is.
HashTable::HashTable (constructor) ---------> since I did my insert in here, I'd say that the run time is again, O(L) since you have to expect the length of genome sequences entered into the insertion. This takes time to feed in through the looping etc.




EXTRA CREDIT
Add a new command to implement the database using one of the other
 data structures that we have covered so far in the course: 
vectors, lists, arrays etc. 

Compare the performance your alternative method to the homework method
by making a table of run times for each of the genomes and query 
sets provided with the homework  and compare the times to build
the index and the times to process the queries. 
Document any new commands you have added in your README file.



MISC. COMMENTS TO GRADER:  
(optional, please be concise!)


