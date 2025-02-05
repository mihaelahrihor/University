#include <vector>
#include "Product.h"

class Repo{
private:

    //vectorul 'produckts' care va contine obiecte de tipul Produckt
    std::vector<Produckt>produckts;

public:

    //add || update un produckt
    void AddOrUpdate(const Produckt& produckt);

    //remove
    void remove(const std::string& name,const std::string& origin);

    //sort(crescator)-expDate
    std::vector<Produckt>sortByExpDate();

    //search by string
    std::vector<Produckt>searchProd(std::string search_string);

    //search by quantity(cantitatea <val. dat de utilizator)
    std::vector<Produckt>findProdRunningLow(int input_quantity);


};