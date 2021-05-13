#include <stdio.h>
// #include <string.h>   // REMOVE THIS LINE,   REQUIRED !!!! 
#include "p5 Pointers with C-strings.h"
#pragma warning(disable:4996)
/* Usage: program username, date, etc....

CS212 Program Assignment #5:  FIX project5.h

*/
int main()
{
    size_t x;
    char orgName[100] = "United Nations";
    char userText[20] = "UNICEF";
    char targetText[10]; // not good to not initialize, see next output for example
    printf("%s   %s   %s\n", orgName, userText, targetText);
    strcpy(targetText, userText); // Copies "UNICEF" + null char to targetText 
    //strcpy(targetText, orgName);// Error: "United Nations" has > 10 chars
    //targetText = orgName;       // Error: Strings can't be copied this way
                                  // (until next week when we learn to overload operators)
    printf("%s\n", targetText);
    strncpy(orgName, userText, 6); // orgName is "UNICEF Nations"
    printf("%s\n", orgName);
    strcat(orgName, userText); // orgName is "United NationsUNICEF"
    strcpy(targetText, "abc");           // targetText is "abc"
    strncat(targetText, "123456789", 3); // targetText is "abc123"
    if (strchr(orgName, 'U') != NULL) { // 'U' exists in orgName?
          // 'U' exists in "United Nations", branch taken
    }
    if (strchr(orgName, 'u') != NULL) { // 'u' exists in orgName?
          // 'u' doesn't exist (case matters), branch not taken
    }
    x = strlen(orgName);    // Assigns 14 to x 
	x = strlen(userText);   // Assigns 6 to x
    x = strlen(targetText); // Error: targetText may lack null char
    if (strcmp(orgName, "United Nations") == 0) {
        // Equal, branch taken
    }
    if (strcmp(orgName, userText) == 0) {
        // Not equal, branch not taken
    }
    printf("Later on, userText is %s\n", userText);

    // Iverson extras for CS212
    char hex[100] = "0123456789ABCDEF";
    char binary[400] = "00001111";
    strhex(hex, userText); // char 'X' is all we get now, should be HEX of userText
    printf("%s\n", hex);
    //strbinary(binary, userText); 
    printf("%s\n", binary); // output should be binary (see CS212 Assignment page)
}