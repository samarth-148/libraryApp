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

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include "LibApp.h"
#include "Utils.h"
#include "PublicationSelector.h"
#include "Book.h"
using namespace std;
namespace sdds
{

    LibApp::LibApp(const char *File, const char *Title, const char *outputTitle, const char *SelectionTitle) : pubNum(0), refNum(0), change(false), mMenu(Title), outMenu(outputTitle), selectMenu(SelectionTitle)
    {
        strcpy(file_name, File);
        load();
        mMenu << string2 << string3 << string4 << string5;
        outMenu << string7 << string8;
        selectMenu << string10 << string11;
    }
    LibApp::~LibApp()
    {
        int i = 0;
        while (i < pubNum)
        {
            delete pubArray[i];
            pubArray[i] = nullptr;
            i++;
        }
    }

    void LibApp::run()
    {
        bool val = true;
        do
        {
            switch (mMenu.run())
            {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                val = exitMode();
                break;
            }
        } while (val);
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
    bool LibApp::exitMode() const
    {
        bool val = false;
        if (change)
        {
            switch (outMenu.run())
            {
            case 1:
                save();
                break;
            case 2:
                val = true;
                break;
            case 0:
                val = !confirm("This will discard all the changes are you sure?");
                break;
            }
        }
        cout << endl;
        return val;
    }
    void LibApp::load()
    {
        cout << "Loading Data" << endl;
        ifstream fistr(file_name);
        char valid;

        for (int i = 0; fistr; i++)
        {
            fistr >> valid;
            Utils::getChar(fistr, '\t');
            if (fistr)
            {
                if (valid == 'P')
                    pubArray[i] = new Publication;
                else if (valid == 'B')
                    pubArray[i] = new Book;
                if (pubArray[i])
                {
                    fistr >> *pubArray[i];
                    pubNum++;
                }
            }
        }
        refNum = pubArray[pubNum - 1]->getRef();
    }
    void LibApp::save() const
    {
        cout << "Saving Data" << endl;
        ofstream fostr(file_name);
        int i = 0;
        while (i < pubNum)
        {
            if (pubArray[i]->getRef() != 0)
                fostr << *pubArray[i] << endl;
            i++;
        }
    }
    int LibApp::search(int selection) const
    {

        PublicationSelector selector("Select one of the following found matches:");
        char title[256]{};
        int reference = 0;
        char type{};
        bool exit = false;

        switch (selectMenu.run())
        {
        case 1:
            type = 'B';
            break;
        case 2:
            type = 'P';
            break;
        case 0:
            exit = true;
            cout << "Aborted!" << endl
                 << endl;
            break;
        }
        if (!exit)
        {

            cout << "Publication Title: ";
            cin.getline(title, 256, '\n');

            if (selection == searchAll)
            {

                int i = 0;
                while (i < pubNum)
                {
                    (pubArray[i]->getRef() != 0 && pubArray[i]->type() == type &&
                     *pubArray[i] == title) &&
                        selector << pubArray[i];
                    i++;
                }
            }
            else if (selection == searchCheckout)
            {
                int i = 0;
                while (i < pubNum)
                {
                    (pubArray[i]->onLoan() && pubArray[i]->getRef() != 0 &&
                     pubArray[i]->type() == type && *pubArray[i] == title) &&
                        selector << pubArray[i];
                    i++;
                }
            }
            else if (selection == searchAvailable)
            {
                int j = 0;
                while (j < pubNum)
                {
                    (!pubArray[j]->onLoan() && pubArray[j]->getRef() != 0 &&
                     pubArray[j]->type() == type && *pubArray[j] == title) &&
                        selector << pubArray[j];
                    j++;
                }
            }
            if (selector)
            {
                selector.sort();
                reference = selector.run();
                if (reference != 0)
                    cout << *getPub(reference) << endl;
                else
                    cout << "Aborted!" << endl
                         << endl;
            }
            else
                cout << "No matches found!" << endl
                     << endl;
        }
        return reference;
    }

    Publication *LibApp::getPub(int libRef) const
    {
        Publication *ptr{};
        for (int i = 0; i < pubNum && !ptr; i++)
        {
            if (pubArray[i]->getRef() == libRef)
                ptr = pubArray[i];
        }
        return ptr;
    }
    bool LibApp::confirm(const char *message) const
    {
        Menu confirmMenu(message);
        confirmMenu << "Yes";
    
        return confirmMenu.run() == 1;
    }

    void LibApp::returnPub()
    {
        Date now;
        cout << "Return publication to the library" << endl;
        int reference = search(searchCheckout);
        if (reference != 0)
        {
            if (confirm("Return Publication?"))
            {
                int lateDays = now - getPub(reference)->checkoutDate();
                if (lateDays > SDDS_MAX_LOAN_DAYS)
                {
                    cout.setf(ios::fixed);
                    cout.precision(2);
                    cout << "Please pay $" << ((double)lateDays - (double)SDDS_MAX_LOAN_DAYS) * 0.5
                         << " penalty for being " << (lateDays - SDDS_MAX_LOAN_DAYS) << " days late!" << endl;
                }
                getPub(reference)->set(0);
                change = true;
                cout << "Publication returned" << endl
                     << endl;
            }
            else
            {
                cout << "Aborted!" << endl
                     << endl;
            }
        }
    }

    void LibApp::removePublication()
    {
        cout << "Removing publication from the library" << endl;
        int reference = search(searchAll);
        if (reference != 0)
        {
            if (confirm("Remove this publication from the library?"))
            {
                getPub(reference)->setRef(0);
                change = true;
                cout << "Publication removed" << endl
                     << endl;
            }
            else
            {
                cout << "Aborted!" << endl
                     << endl;
            }
        }
    }
    void LibApp::checkOutPub()
    {
        int membership = 0;
        cout << "Checkout publication from the library" << endl;
        int reference = search(searchAvailable);
        if (reference != 0)
        {
            if (confirm("Check out publication?"))
            {
                cout << "Enter Membership number: ";
                membership = Utils::getInt(cin, 10000, 99999, "Invalid membership number, try again: ");
                getPub(reference)->set(membership);
                change = true;
                cout << "Publication checked out" << endl
                     << endl;
            }
            else
            {
                cout << "Aborted!" << endl
                     << endl;
            }
        }
    }
    void LibApp::newPublication()
    {
        if (pubNum == SDDS_LIBRARY_CAPACITY)
        {
            cout << "Library is at its maximum capacity!" << endl
                 << endl;
        }
        else
        {
            cout << "Adding new publication to the library" << endl;
            Publication *newPub{};
            switch (selectMenu.run())
            {
            case 1:
                newPub = new Book;
                break;
            case 2:
                newPub = new Publication;
                break;
            case 0:
                cout << "Aborted!" << endl
                     << endl;
                newPub = nullptr;
                break;
            }

            if (newPub)
            {
                cin >> *newPub;
                if (cin)
                {
                    if (confirm("Add this publication to the library?"))
                    {
                        if ((*newPub))
                        {
                            pubArray[pubNum] = newPub;
                            pubArray[pubNum]->setRef(++refNum);
                            pubNum++;
                            change = true;
                            cout << "Publication added" << endl
                                 << endl;
                        }
                        else
                        {
                            cout << "Failed to add publication!" << endl
                                 << endl;
                            delete newPub;
                        }
                    }
                    else
                    {
                        delete newPub;
                        cout << "Aborted!" << endl
                             << endl;
                    }
                }
                else
                {
                    delete newPub;
                    cin.ignore(1000, '\n');
                    cout << "Aborted!" << endl
                         << endl;
                }
            }
        }
    }
}
