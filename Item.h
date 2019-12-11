#ifndef ITEM_H
#define ITEM_H
#include "Category.h"
#include "ParentClass.h"

class Category;

class Item : public ParentClass {
    private:
        Category* cat;// maybe not necessary 
        std::set<std::string> usedOrders;
        
    public:
        Item(Category* category, const std::string& itemName);
        virtual ~Item();
        
        virtual const std::string& getName() const;
        
        virtual int getUnicID() const;
        
        void linkToOrder(const std::string& ordName);
        void getUsedOrders();
        
        static int gItemID;
        static std::set<ParentClass*> itemList;
        static void getItemList();
        static const int classUnicID = 200;
};

#endif // ITEM_H
