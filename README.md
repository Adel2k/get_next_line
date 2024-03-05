# get_next_line

## Description
get_next_line is a function that reads a line from a file descriptor and returns it without the newline character. It allows reading from multiple file descriptors in a non-blocking manner. This project is part of the curriculum at 42 ecole.

## Motivation
The motivation behind creating this project is to understand file I/O operations, memory management, and handling of file descriptors in C programming.

## Features
- Ability to read lines from multiple file descriptors.
- Support for reading lines from files, standard input, or any valid file descriptor.
- Handles text files, binary files, and special files.
- Works in both blocking and non-blocking modes.
- Well-documented code with clear explanations of each function's purpose and usage.

## Getting Started
1. Clone the repository: git clone https://github.com/Adel2k/get_next_line.git
2. Navigate to the `get_next_line` directory:
  cd get_next_line
4. Compile the library:
  make
## Tester
- https://github.com/Tripouille/gnlTester.git
- https://github.com/kodpe/gnl-station-tester.git
## Usage
- To use this function in your projects, include the `get_next_line.h` header file in your source files.
- Example usage:
```c
#include "get_next_line.h"

int main() {
   int fd = open("example.txt", O_RDONLY);
   char *line;
   while (get_next_line(fd, &line) > 0) {
       printf("%s\n", line);
       free(line);
   }
   close(fd);
   return 0;
}
