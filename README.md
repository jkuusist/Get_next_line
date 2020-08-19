# Get_next_line
My solution for 42's get_next_line project: a function that reads characters from a file line by line.

The function takes as arguments a file descriptor and a pointer to a string. Then it reads characters from 
that file into the pointed string until it encounters a newline character or the end of the file. Thus,
calling get_net_line in a loop allows to read the entire contents of a file line by line. It can also handle
reading from multiple files in separate calls without losing track of where it was in each file.

The function returns 1 if a line was read succesfully, 0 if reading has been completed, or -1 if something
went wrong.
