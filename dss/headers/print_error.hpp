void printError(const char *functionName, const char *fileName, int lineNumber);
/*
    printError() prints an error message to stdio given a function name,
    a file name, and a line number.

    Meant to be used as:
    
    if(condition == error)
        printError("functionName", __FILE__, __LINE__);

    Where __FILE__ and __LINE__ are the gcc and g++ macros
    that indicate file name and line number of code within
    a source code file.
*/
