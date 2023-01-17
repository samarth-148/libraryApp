/**************************************************

Name : Samarth Shaileshkumar Patel
Email: sspatel74@myseneca.ca
student ID:143147213
section:NKK
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my project milestones.
-----------------------------------------------------------

***********************************************/

#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include "Publication.h"
namespace sdds
{
    class Book : public Publication
    {

        char *authorBk{};
    public:
        Book();
        Book(const Book &src);
        Book &operator=(const Book &src);
        virtual ~Book();
          char type() const;
        void set(int memberId);
         operator bool() const;
        bool consoleIO(std::ios &io) const;
        void deleteAll();
        std::ostream &write(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);
    };
}
#endif //!SDDS_BOOK_H_