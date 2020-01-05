#ifndef PARENTCLASS_H
#define PARENTCLASS_H
#include <iostream>
#include <set>

class ParentClass {
    protected:
        int ID;
        std::string Name;
        
    public:
        ParentClass(const std::string& name = "emptyTitle");
        
        virtual ~ParentClass();
        
        virtual int getID() const;
        virtual const std::string& getName() const;
        
        virtual int getUnicID() const;
        
        static int globalID;
        static int getGlobalID();
        static std::set<ParentClass*> objList;
        static void getObjList();
};

std::ostream& operator<<(std::ostream& out, const ParentClass& obj);

#endif // PARENTCLASS_H
