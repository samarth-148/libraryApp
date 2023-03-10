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

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds
{
   const int MAX_MENU_ITEMS = 20;
   class Menu;
   //// MenuItem Class:
   class MenuItem
   {
      char *m_item{};

   private:
      friend class Menu;
      MenuItem(const char *item = nullptr);
      ~MenuItem();
      // disable copy constructor and assignment
      MenuItem(const MenuItem &src) = delete;
      MenuItem &operator=(const MenuItem &src) = delete;
      void setName(const char *item);
      operator bool() const;
      operator const char *() const;
      std::ostream &display(std::ostream &ostr) const;
   };
   //// Menu Class:
   class Menu
   {
      MenuItem m_title;
      int m_numberOfItems;
      MenuItem *m_itemList[MAX_MENU_ITEMS]{};

   public:
      Menu(const char *title = nullptr);
      ~Menu();
      // disable copy constructor and assignment
      Menu(const Menu &src) = delete;
      Menu &operator=(const Menu &src) = delete;
      unsigned int run() const;
      int operator~() const;
      Menu &operator<<(const char *menuItem);
      operator int() const;
      operator unsigned int() const;
      operator bool() const;
      char *operator[](int index) const;
      std::ostream &displayTitle(std::ostream &ostr) const;
      std::ostream &displayMenu(std::ostream &ostr) const;
   };
   std::ostream &operator<<(std::ostream &ostr, const Menu &ro);
}
#endif // !SDDS_MENU_H_
