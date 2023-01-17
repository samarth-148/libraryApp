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

#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_
#include <iostream>
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"
namespace sdds
{
    class Publication : public Streamable
    {
        char *m_title{};                         // holds dynamic title for publications.
        char m_shelfId[SDDS_SHELF_ID_LEN + 1]{}; // holds the location of publication in library.
        int m_membership;                        // holds 5-digit membeship number
        int m_libRef;                            // holds serial num
        Date m_date;                             // this date is used for the publish date of the item.

    public:
        Publication();
        Publication(const Publication &src);
        virtual ~Publication();

        virtual void set(int member_id);
        // Sets the membership attribute to either zero or a five-digit integer.
        void setRef(int value);
        // Sets the **libRef** attribute value
        void resetDate();
        // Sets the date to the current date of the system.

        operator bool() const;
        virtual char type() const;
        // Returns the character 'P' to identify this object as a "Publication object"
        bool onLoan() const;
        // Returns true is the publication is checkout (membership is non-zero)
        Date checkoutDate() const;
        // Returns the date attribute
        bool operator==(const char *title) const;
        // Returns true if the argument title appears anywhere in the title of the
        // publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        operator const char *() const;
        // Returns the title attribute
        int getRef() const;
        // Returns the libRef attirbute.
        bool conIO(std::ios &io) const;

        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &istr);

        virtual void deleteAll();
        Publication &operator=(const Publication &src);
    };
}
#endif // !SDDS_PUBLICATION_H
