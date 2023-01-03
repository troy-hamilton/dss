// printError("functionName", __FILE__, __LINE__);
void printError(const char *functionName, const char *fileName, int lineNumber)
{
    printf("********************************************************************************\nThere was a runtime error:\n{\n");
    if(functionName != NULL)
        printf("    Function Name: \"%s\"\n", functionName);
    if(fileName != NULL)
        printf("    File Name: \"%s\"\n", fileName);
    if(lineNumber > 0)
        printf("    Approximate Line Number: \"%d\"\n", lineNumber);
    printf("}\n********************************************************************************\n\n");
}
