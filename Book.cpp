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

#include <iostream>
#include <cstring>
#include "Book.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
    Book::Book()
    {
    }

    Book::Book(const Book &src)
    {
        operator=(src);
    }

    Book &Book::operator=(const Book &src)
    {
        if (this != &src && src)
        {
            Publication::operator=(src);
            Utils::copyStr(authorBk, src.authorBk);
        }
        return *this;
    }

    Book::~Book()
    {
        delete[] authorBk;
        authorBk = nullptr;
    }

    void Book::set(int memberId)
    {
        Publication::set(memberId);
        Publication::resetDate();
    }

    char Book::type() const
    {
        return 'B';
    }

    void Book::deleteAll()
    {
        delete[] authorBk;
        authorBk = nullptr;
        Publication::deleteAll();
    }

    istream &Book::read(istream &istr)
    {
        char author[1000 + 1];
        deleteAll();
        Publication::read(istr);
        if (consoleIO(istr))
        {
            Utils::getChar(istr, '\n');
            cout << "Author: ";
            istr.getline(author, 1000 + 1);
        }
        else
        {
            Utils::getChar(istr, '\t');
            istr.get(author, 1000 + 1);
        }

        if (istr)
        {
            Utils::copyStr(authorBk, author);
        }
        else
        {
            deleteAll();
        }
        return istr;
    }

    ostream &Book::write(ostream &ostr) const
    {

        Publication::write(ostr);
        if (consoleIO(ostr))
        {
            ostr << " ";
            ostr.setf(ios::left);
            if (strlen(authorBk) > SDDS_AUTHOR_WIDTH)
            {
                int i = 0;
                while (i < SDDS_AUTHOR_WIDTH)
                {
                    ostr << authorBk[i];
                    i++;
                }
            }
            else
            {
                ostr.width(SDDS_AUTHOR_WIDTH);
                ostr << authorBk;
            }
            ostr << " |";
            ostr.unsetf(ios::left);
        }
        else
        {
            ostr << '\t' << authorBk;
        }
        return ostr;
    }

    bool Book::consoleIO(std::ios &io) const
    {
        return Publication::conIO(io);
    }

    Book::operator bool() const
    {
        return (authorBk && authorBk[0] && Publication::operator bool());
    }
}