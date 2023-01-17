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


#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Publication.h"
#include "Menu.h"
namespace sdds
{
    const int searchAll = 1, searchCheckout = 2, searchAvailable = 3;
    const char string1[] = "Seneca Library Application";
    const char string2[] = "Add New Publication";
    const char string3[] = "Remove Publication";
    const char string4[] = "Checkout publication from library";
    const char string5[] = "Return publication to library";
    const char string6[] = "Changes have been made to the data, what would you like to do?";
    const char string7[] = "Save changes and exit";
    const char string8[] = "Cancel and go back to the main menu";
    const char string9[] = "Choose the type of publication:";
    const char string10[] = "Book";
    const char string11[] = "Publication";

    class LibApp
    {

        char file_name[256]{};
        Publication *pubArray[SDDS_LIBRARY_CAPACITY]{};
        int pubNum, refNum;
        bool change;
        Menu mMenu;
        Menu outMenu;
        Menu selectMenu;

    private:
        void returnPub();
        bool confirm(const char *message) const;
        void load();
        void save() const;
        void newPublication();
        void removePublication();
        int search(int selection = searchAll) const;
        Publication *getPub(int libRef) const;
        void checkOutPub();
        bool exitMode() const;

    public:
        LibApp(const char *File, const char *Title = string1, const char *outputTitle = string6, const char *SelectionTitle = string9);
        void run();
        LibApp(const LibApp &src) = delete;
        LibApp &operator=(const LibApp &src) = delete;
        virtual ~LibApp();
    };
}
#endif