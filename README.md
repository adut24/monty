# 0x19. C - Stacks, Queues - LIFO, FIFO

## Installation and Usage

This project was realised on **Ubuntu 20.04 LTS** and compiled with **GCC 9.4.0**. Depending on the changes, it may not work on future version. If you want to download and test our project, follow these steps:

```
$ git clone git@github.com:adut24/monty.git
$ cd monty
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
$ ./monty bytecodes/00.m
```

## Description
The **Stacks, Queues - LIFO, FIFO** project is the third team project realised at Holberton School. The purpose is to create a program that will interpret the command known as "opcodes" stored inside files.

## Output
Monty reads ".m" files and interprets the opcodes inside the file:
```
$ ./monty bytecodes/00.m
3
2
1
$
```

## Opcodes present
| Opcode | Description |
| --- | --- |
| `push <int>` | Pushes \<int> to the stack/queue |
| `pall` | Print all the values on the stack/queue starting from the top/front |
| `pint` | Print the top of the stack/queue |
| `pop` | Remove the top element of the stack/queue |
| `swap` | Swap the top two elements of the stack/queue |
| `add` | Add the top two elements of the stack/queue and make the stack/queue one element shorter |
| `nop` | Doesn't do anything |
| `sub` | Subtract the top element of the stack/queue from the second top element and make the stack/queue one element shorter |
| `div` | Divide the second top element of the stack/queue by the top element and make the stack/queue one element shorter |
| `mul` | Multiply the second top element of the stack/queue with the top element and make the stack/queue one element shorter |
| `mod` | Computes the rest of the division of the second top element of the stack/queue by the top element and make the stack/queue one element shorter |
| `#` | Comments |
| `pchar` | Print the char at the top of the stack/queue followed by a new line |
| `pstr` | Print the string starting at the top of the stack/queue followed by a new line |
| `rotl` | Rotate the stack/queue to the top |
| `rotr` | Rotate the stack/queue to the bottom |
| `stack` | Set the format of the data to a stack (LIFO). Default behavior |
| `queue` | Set the format of the data to a queue (FIFO) |

## Examples
```
$ cat bytecodes/06.m
push 1
pint
push 2
pint
push 3
pint
$ ./monty bytecodes/06.m
1
2
3
$ cat bytecodes/47.m
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
add
pall
queue
push 11111
add
pall
$ ./monty bytecodes/47.m
1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111
```

## Tasks

### 0. push, pall
Implement the `push` and `pall` opcodes.

**The push opcode**

The opcode `push` pushes an element to the stack.
* Usage: `push <int>`
	* Where `<int>` is an integer
* If `<int>` is not an integer or if there is no argument given to `push`, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`
	* Where is the line number in the file
* You won’t have to deal with overflows. Use the `atoi` function

**The pall opcode**

The opcode `pall` prints all the values on the stack, starting from the top of the stack.
* Usage `pall`
* If the stack is empty, don’t print anything

### 1. pint
Implement the `pint` opcode.

**The pint opcode**

The opcode `pint` prints the value at the top of the stack, followed by a new line.
* Usage: `pint`
* If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 2. pop
Implement the `pop` opcode.

**The pop opcode**

The opcode `pop` removes the top element of the stack.
* Usage: `pop`
* If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 3. swap
Implement the `swap` opcode.

**The swap opcode**

The opcode `swap` swaps the top two elements of the stack.
* Usage: `swap`
* If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 4. add
Implement the `add` opcode.

**The add opcode**

The opcode `add` adds the top two elements of the stack.
* Usage: `add`
* If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	* The top element of the stack contains the result
	* The stack is one element shorter

### 5. nop
Implement the `nop` opcode.

**The nop opcode**

The opcode `nop` doesn’t do anything.
* Usage: `nop`

### 6. sub
Implement the `sub` opcode.

**The sub opcode**

The opcode `sub` subtracts the top element of the stack from the second top element of the stack.
* Usage: `sub`
* If the stack contains less than two elements, print the error message `L<line_number>: can't sub, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
* *the stack, and the top element is removed, so that at the end:
	* The top element of the stack contains the result
	* The stack is one element shorter

### 7. div
Implement the `div` opcode.

**The div opcode**

The opcode `div` divides the second top element of the stack by the top element of the stack.
* Usage: `div`
* If the stack contains less than two elements, print the error message `L<line_number>: can't div, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	* The top element of the stack contains the result
	* The stack is one element shorter
* If the top element of the stack is 0, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 8. mul
Implement the `mul` opcode.

**The mul opcode**

The opcode `mul` multiplies the second top element of the stack with the top element of the stack.
* Usage: `mul`
* If the stack contains less than two elements, print the error message `L<line_number>: can't mul, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	* The top element of the stack contains the result
	* The stack is one element shorter

### 9. mod
Implement the `mod` opcode.

**The mod opcode**

The opcode `mod` computes the rest of the division of the second top element of the stack by the top element of the stack.
* Usage: `mod`
* If the stack contains less than two elements, print the error message `L<line_number>: can't mod, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	* The top element of the stack contains the result
	* The stack is one element shorter
* If the top element of the stack is `0`, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 10. comments
Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything).

### 11. pchar
Implement the `pchar` opcode.

**The pchar opcode**

The opcode `pchar` prints the char at the top of the stack, followed by a new line.
* Usage: `pchar`
* The integer stored at the top of the stack is treated as the ascii value of the character to be printed
* If the value is not in the ascii table (man ascii) print the error message `L<line_number>: can't pchar, value out of range`, followed by a new line, and exit with the status `EXIT_FAILURE`
* If the stack is empty, print the error message `L<line_number>: can't pchar, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 12. pstr
Implement the `pstr` opcode.

**The pstr opcode**

The opcode `pstr` prints the string starting at the top of the stack, followed by a new line.
* Usage: `pstr`
* The integer stored in each element of the stack is treated as the ascii value of the character to be printed
* The string stops when either:
	* the stack is over
	* the value of the element is 0
	* the value of the element is not in the ascii table
* If the stack is empty, print only a new line

### 13. rotl
Implement the `rotl` opcode.

**The rotl opcode**

The opcode `rotl` rotates the stack to the top.
* Usage: `rotl`
* The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
* `rotl` never fails

### 14. rotr
Implement the `rotr` opcode.

**The rotr opcode**

The opcode `rotr` rotates the stack to the bottom.
* Usage: `rotr`
* The last element of the stack becomes the top element of the stack
* `rotr` never fails

### 15. stack, queue
Implement the `stack` and `queue` opcodes.

**The stack opcode**

The opcode `stack` sets the format of the data to a stack (LIFO). This is the default behavior of the program.
* Usage: `stack`

**The queue opcode**

The opcode `queue` sets the format of the data to a queue (FIFO).
* Usage: `queue`

When switching mode:
* The top of the stack becomes the front of the queue
* The front of the queue becomes the top of the stack

### 16. Brainf*ck
Write a Brainf*ck script that prints `School`, followed by a new line.
* All your Brainf*ck files should be stored inside the `bf` sub directory
* You can install the `bf` interpreter to test your code: `sudo apt-get install bf`
* Read: [Brainf*ck](https://intranet.hbtn.io/rltoken/3YPS6XwLxjZp4qnguP1HYg)

### 17. Add two digits
Add two digits given by the user.
* Read the two digits from stdin, add them, and print the result
* The total of the two digits with be one digit-long (<10)

### 18. Multiplication
Multiply two digits given by the user.
* Read the two digits from stdin, multiply them, and print the result
* The result of the multiplication will be one digit-long (<10)

### 19. Multiplication level up
Multiply two digits given by the user.
* Read the two digits from stdin, multiply them, and print the result, followed by a new line
