#ifndef PARENTCLASS_H
#define PARENTCLASS_H
#include <iostream>
#include <set>

class ParentClass {
    protected:
        int ID;
        std::string Name;
        
    public:
        ParentClass(const std::string& name = "whom");
        
        virtual ~ParentClass();
        
        virtual int getID() const;
        virtual const std::string& getName() const;
        
        virtual int getUnicID() const;
        
        static int globalID;
        static int getGlobalID();
        static std::set<ParentClass*> objList;// overal LIST work (1 out of 3)
        static void getObjList();// overal LIST work (2 out of 3)
};

std::ostream& operator<<(std::ostream& out, const ParentClass& obj);

#endif // PARENTCLASS_H
