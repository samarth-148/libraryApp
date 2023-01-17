/**************************************************

Name : Samarth Shaileshkumar Patel
Email: sspatel74@myseneca.ca

***********************************************/

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
namespace sdds {

class Utils
    {
    public:
        Utils() = delete;
        static void getChar(std::istream &is, char ch);                                                                         // extract a given char
        static void getChar(std::istream &is);                                                                                  // if next char is digit set
        static int getInt(std::istream &is, int min, int max, const char *message = nullptr); // get a int with validation and error message
        static void copyStr(char *&des, const char *src);                                                                       // copy a string of
        static char *readInput(std::istream &is, char delimeter = '\n');                                         // read
    };

}
#endif // !SDDS_UTILS_H__
