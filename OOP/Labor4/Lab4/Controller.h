#include "Repo.h"

class Controller{

private:
    Repo repo;

public:

    void AddOrUpdate(const std::string& name, const std::string& origin,int quantity,float price,int day,int month,int year);

    void removeProd(const std::string& name,const std::string& origin);

    std::vector<Produckt>searchProd(const std::string& search_string);

    std::vector<Produckt>findProdRunningLow(int input_quantity);

    std::vector<Produckt>sortProdByExpDay();
};
