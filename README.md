*This project has been created as part of the 42 curriculum by abenabde.*




# Get Next Line
aka GNL

Project library: `get_next_line.h`

Prototype: `get_next_line(fd)`




## Description:

Get Next Line, usable with `get_next_line(fd)`, is a C function capable of reading a line from the chosen file descriptor (aka `fd`) and returning a dynamically allocated string containing that line.

When the function is called a second time, the next line of the read file is returned.  
On error or when the end of the file is reached, a `NULL` pointer is returned.




## Instruction:

Get Next Line is a simple function written in C.  
You can use it by including the header `get_next_line.h` and placing the associated source files in your project.

The function exhibits undefined behavior if the file associated with the file descriptor is modified after the last call, while read() has not yet reached the end of the file, and also exhibits undefined behavior when reading a binary file.

The code is provided with a default `BUFFER_SIZE` of `100`, used by the `read()` function from `unistd.h`.
You can change this buffer size at compilation time with the following flag (if your compiler supports it — the project was supported and tested with `gcc`):
`-D BUFFER_SIZE=<chosen_value>`




## Algorithm:

The function reads data from the file descriptor into a buffer of size `BUFFER_SIZE` and stores it in a static variable to keep unread data between calls.

It continues reading and appending data until a newline character (\n) is found or the end of the file is reached.
Once a full line is detected, the function extracts and returns it, while keeping the remaining data for the next call.

This approach allows efficient reading of files line by line while minimizing system calls and preserving unread data across multiple function calls.




## Resources:


### Technical references

Linux manual page for read() open()
GNU C Library documentation
42 subject PDF for Get Next Line


### AI usage

Artificial intelligence (ChatGPT) was used to:
Review and improve the README documentation
Help clarify explanations of the algorithm and resources sections


### Libraries used:

- stdlib.h
- unistd.h

