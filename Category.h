#ifndef CATEGORY_H
#define CATEGORY_H
#include <set>
#include "ParentClass.h"
#include "Item.h"

class Item;

class Category : public ParentClass {
    private:
        std::set<Item*>* itemList;
        
    public:
        Category(const std::string& cName = "Empty_Cat");
        virtual ~Category();
        
        virtual const std::string& getName() const;
        
        void addItem(Item* item);
        void deleteItem(Item* item);
        void getItemList();
        
        virtual int getUnicID() const;
        
        static int gCatlID;
        static std::set<ParentClass*> catList;
        static void getCatList();
        static const int classUnicID = 100;
};

#endif // CATEGORY_H
