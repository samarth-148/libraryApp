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
#include "Streamable.h"
namespace sdds
{
    
    std::ostream &operator<<(std::ostream &os, const Streamable &src)
    {
        if (src) src.write(os);
        return os;
    }
    std::istream &operator>>(std::istream &is, Streamable &src)
    {
        return src.read(is);
    }
     Streamable::~Streamable()
    {
        //empty virtual destuctor.
    }
}