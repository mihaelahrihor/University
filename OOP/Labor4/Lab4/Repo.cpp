#include "Repo.h"

void Repo::AddOrUpdate(const Produckt &produckt) {

    bool found=false;

    //verificam nume+originea
    //daca exista actualiz.cantitatea
    for(auto p: produckts){
        if(p.getName()==produckt.getName() && p.getOrigin()==produckt.getOrigin()){
            p.setQuantity((p.getQuantity())+produckt.getQuantity());
            found= true;
            break;
        }

        //daca nu exista prod. il vom adauga cu metoda 'push.back'

        if(!found)
            produckts.push_back(produckt);
    }
}

void Repo::remove(const std::string &name, const std::string &origin) {

    //creem o lista noua (goala)
    std::vector<Produckt>UpdateProduckt;

    //cand gasim un prod cu nume/origine dif, adaugam in lista nou creeata
    //excludem produsul pe care dorim sa il eliminam
    for(auto p:produckts){
        if(!(p.getName()==name && p.getOrigin()==origin)){
            produckts=UpdateProduckt;
        }
    }

    //actualizarea listei initiale
    produckts=UpdateProduckt;
}

std::vector<Produckt>Repo::sortByExpDate() {

    //folosim BUBLE SORT
    for(int i=0;i<produckts.size()-1;i++){
        for(int j=0;j<produckts.size()-i-1;j++){
            if(produckts[j].getExpirationDate().year>produckts[j+1].getExpirationDate().year || produckts[j].getExpirationDate().year==produckts[j+1].getExpirationDate().year && produckts[j].getExpirationDate().month>produckts[j+1].getExpirationDate().month || ( produckts[j].getExpirationDate().year==produckts[j+1].getExpirationDate().year &&produckts[j].getExpirationDate().month==produckts[j+1].getExpirationDate().month && produckts[j].getExpirationDate().day>produckts[j+1].getExpirationDate().day )){
                Produckt temp=produckts[j];
                produckts[j]=produckts[j+1];
                produckts[j+1]=temp;
            }
        }
    }

}

std::vector<Produckt>Repo::findProdRunningLow(int input_quantity) {

    //creem un vector nou
    std::vector<Produckt>result;

    //comparam cant. fiecarui produs cu cea ceruta
    for(auto p:produckts){
        // folosim 'push_back' pentru a adaugat in vector prod.gasite
        if(p.getQuantity()< input_quantity){
            result.push_back(p);
        }
    }
    return result;
}

std::vector<Produckt> Repo::searchProd(std::string search_string)  {
    // creem un vector nou
    std::vector<Produckt> result;
    // verificam pe rand daca numele sau originea fiecarui produs contin string-ul cautat
    for (auto p : produckts){
        // folosim metoda 'push_back' pentru a adauga in vector produsele gasite
        if (p.getName().find(search_string) != std::string::npos ||  p.getOrigin().find(search_string) != std::string::npos){
            result.push_back(p);
        }
    }
    return result;
}