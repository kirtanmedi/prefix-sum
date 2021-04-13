Kirtan Medicharla KXM180040 
Trent Haines TSH160220

This project implements a barrier using semaphores. The main function implemented in the barrier is the arriveAndWait() function which waits for all threads to finish processing in order to be released once again.The program ensures that the barrier object is reusable and that all threads wait for the rest of the threads to be completed and ensures all threads are used.
This barrier program is tested by running the prefix sum problem using Hillis and Steele's parallel algorithm. The phases of this algorithm are completed and managed using the barrier program. 
The project can be compiled by typing 
    $make
The project can then be run by typing 
    $./prefix-sum outputCount threadCount 
where outputCount and threadCount are command line arguments specified by the user.
The program will then output result of the prefix sum problem.