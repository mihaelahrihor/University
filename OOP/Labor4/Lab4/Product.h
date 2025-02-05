#include <string>

class Produckt{

private:
    std::string name;
    std::string origin;
    struct expirationDate{
        int day,month,year;
    } expDate;
    int quantity;
    float price;

public:

    //constructor
    Produckt(const std::string& name,const std::string& origin,int quantity,float price,int day,int month,int year );

    //motodele de obtinerrea sau modificarea atributelor produselor

    std::string getName()const;
    void setName(const std::string& name);

    std::string getOrigin()const;
    void setOrigin(const std::string& origin);

    Produckt::expirationDate getExpirationDate()const;
    void setExpirationDate(int day,int month,int year);

    int getQuantity()const;
    void setQuantity(int quantity);

    float getPrice()const;
    void setPrice(float price);
};