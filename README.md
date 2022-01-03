# Push_Swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

# Introduction
The Push_swap project is a very simple and highly effective algorithm project: data will
need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of
instructions to manipulate both stacks.
Your goal ? Write a program in C called push_swap which calculates and displays
on the standard output the smallest program using Push_swap instruction language that
sorts the integer arguments received.
Easy?
We’ll see about that...

# Commands
We need to sorte the stack only with these commands.
|Command | Description|
|-----|-----|
|sa| Swap A - swap the first 2 elements at the top of stack A.|
|sb| Swap B - swap the first 2 elements at the top of stack B.|
|pa| Push A - take the first element at the top of B and put it at the top of A.|
|pb| Push B - take the first element at the top of A and put it at the top of B.|
|ra| Rotate A - shift up all elements of stack a by 1. The first element becomes the last one.|
|rb| Rotate B - shift up all elements of stack a by 1. The first element becomes the last one.|
|rra| Reverse rotate A - shift down all elements of stack a by 1. The last element becomes the first one.|
|rrb| Reverse rotate B - shift down all elements of stack a by 1. The last element becomes the first one.||

# Algorithm
The algorithm work with some steps and with the concept of chunks. This algorithm is used just for lists bigger then 5 numbers:  
* Step 1: I find the first 25 smallest numbers, this numbers will make my chunk, and i find the biggest number into this chunk.
* Step 2: I verify the position of each number that is into the chunk and take the number that is more close of the top of the list, and i make 'ra' or 'rra' to put this number to top of the list.
* Step 3: I prepare list b for the coming of a new number by putting at the top of list b the number that is less than the number to come and that comes closest to the next number, the **perfect match.**
* Go back to step 2 until the block is empty, when that happens and still have numbers in the list A, go back to step 1 and do it all over again.
* When the list A is empty, put the biggest number of list b at the top and make 'pa' until the list b is empty.

## How to use
```
Compile the executable with `make`.
Then execute with the numbers you want:
./push_swap 2 4 5 6 0
```

Have some fun!
