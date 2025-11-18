# Laboratory #5

This repository contains implementations of dynamic arrays, doubly linked lists, and stacks. Each data structure comes 
with functions to manipulate and access its elements.

## Features

### Dynamic Arrays
- **Create an array**  
- **Add an element**  
- **Remove an element**  
- **Get element by index**  
- **Print the array**
Note: The arrays generated and used in this functions contain the size of the array in their first element to free the user 
from the burden of carrying it, thats why the normalize_array function was added:
- **Eliminates the size of the array from the first element of the array and move every other element to the left
Note: It is advised to save the element counter in a variable before normalizing (read src/dynamic_arrays.c to learn how)

### Doubly Linked Lists
- **Insert at the beginning**  
- **Insert at the end**  
- **Insert at a specific position**  
- **Remove an element (by value)**  
- **Search for an element**  
- **Print the list forwards**  
- **Print the list backwards**

### Stack
- **Push**: Add an element to the top of the stack  
- **Pop**: Remove and return the element at the top  
- **Peek / Top**: Return the top element without removing it  
- **isEmpty**: Check if the stack is empty  

## Compilation and Execution

To compile just run make, it will generate a test executable so just run
./test in orded to execute the domonstration
It will contain a demonstration of every feature. It is advised to revise the main.c to undesrtand how the demonstration is implemented
Also, be sure to read the source code to fully understand how everything is implemented as well as error management

Developers:
Sebastian Araya C4C532
Jonatan Hidalgo C4G083
Andres Zumbado C4L225
