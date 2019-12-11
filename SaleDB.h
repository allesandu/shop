#ifndef SALEDB_H
#define SALEDB_H
#include <map>
#include "set"
#include "Category.h"

class SaleDB {
    private:
        std::map<int, Category*>* saleDB;
        std::set<Category*>* categoryList;
        
    public:
        SaleDB();
        
        ~SaleDB();
        
        void addRecord(int id = 0, Category* cat = new Category());
        void getSaleDB();
        
        Category* getCertainRecord(int key) const;
};

#endif // SALEDB_H
