HOMEWORK 7: SPATIALLY-EMBEDDED ADJACENCY MAPS


NAME:  < Arthur Mosley >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< vivek verghese >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 20>



ORDER NOTATION ANALYSIS:
Consider the following variables and give the complexity along with a short
justification for each of the functions below:

n: The total number of users
l: The total number of users with a location
d: The total number of users with degree >= 1
m: The total number of connections
p: The number of users that a function will print out
b: The number of bits required to represent the largest ID
i: The number of decimal digits required to represent the largest ID

loadConnections():
O(mlog(n))
While loop runs m times for how many connections there are. Filling map is log(n) speed.

loadLocations():
O(l*log(l))
While loop creates a pair as the value (constant run time) and the map has log(l) run time.

printAllUsersWithinDistance():
O(l+p*log(n))
Function will go through num users to print out. Filling map sorted = log(n). Goes through all users with location.

printDegreesHistogram():
O(n+p*log(p))
CountOccurences map stores users going to print out so log(p). Other for loops are just O(n) + O(p).

printDegreesOfAll():
O(p)
For loops run through the the number of people going to print out and then runs through printing them out.

printFriendsWithDegree():
O(log(n)*p)
Filling the for loop is p run time. Log(n) comes from the using the find function on the map to find the start_id.

printFriendsWithinDistance():
O(log(p)*n+p)
log(p) for the find function. Secondly, n run time because of the for loop going through all of the users and calling the find function. Lastly, for loop for printing out the friuends

printUsersWithinIDRange():
O(n+p+m)
Not filling or searching through a map so only n and p run time because I'm pushing back valid ID's that are in range and secondly p for the printing of the users within the range. Lastly m because of the iterator.

MISC. COMMENTS TO GRADER:  
(optional, please be concise!)
In the function, printUsersWithinIDRange, it says that when iterating there should be O(m) time. I took this literally in the sense that my iterators by themselves run at a O(m) run time but then the vectors add on to it but that was not explicitly specified against.





