#include "Contacts.h"


Contacts::~Contacts()
{
}


bool Contacts::addContact(Contact contact)
{
    auto res = addressBook.insert(contact);
    return res.second;
}

bool Contacts::rmvContact(const string phone)
{
    cc_phone_type& phIndexes = addressBook.get<0>();   
    auto res = phIndexes.find(phone);
    if(res == phIndexes.end()) return false;
    else{
        phIndexes.erase(res);
        return true;
    }
}


cc_phone_type::iterator Contacts::findByPhone(const string phone)
{
    return addressBook.get<0>().find(phone);
}

int Contacts::findAllByStreet(const string street, bool print)
{
    int fCount = 0;

    cc_street_type& stIndexes = addressBook.get<1>();
    auto stRange = stIndexes.equal_range(street);

    for(auto it = stRange.first; it != stRange.second; ++it){
        if(print) cout << "Contact{phone:"<<it->phone
        <<"|street:"<<it->street
        <<"|surname:"<<it->surname
        <<"|name:"<<it->name
        <<"|age:"<<it->age
        <<"}" << endl;
        fCount++;
    }

    return fCount;
}

int Contacts::findAllByAgeRange(int startAge, int endAge, bool print)
{
    int fCount = 0;

    cc_age_type& agIndexes = addressBook.get<3>();
    cc_age_type::iterator agUpper = agIndexes.end();
    if(endAge > startAge) agUpper = agIndexes.upper_bound(endAge);

    for(auto it = agIndexes.lower_bound(startAge); it != agUpper; ++it){
        if(print) cout << "Contact{phone:"<<it->phone
        <<"|street:"<<it->street
        <<"|surname:"<<it->surname
        <<"|name:"<<it->name
        <<"|age:"<<it->age
        <<"}" << endl;
        fCount++;
    }

    return fCount;
}
int Contacts::countAllAgedFull(bool print)
{
    return findAllByAgeRange(18, -1, print);
}

int Contacts::countUniqueSurnamed()
{
    set<string> uqSurnames;

    cc_surname_type& snIndexes = addressBook.get<2>();
    for(const auto& c : snIndexes){
        uqSurnames.insert(c.surname);
    }

    return uqSurnames.size();
}


int Contacts::changeStreet(const string streetPrev, const string streetNew)
{
    if(streetNew == streetPrev) return -1;
    int dCount = 0;

    cc_street_type& stIndexes = addressBook.get<1>();
    auto stRange = stIndexes.equal_range(streetPrev);

    for(auto it = stRange.first; it != stRange.second; ++it){
        //stIndexes.modify(it, boost::bind(rnmStreet,_1,streetNew));
        //it->street = streetNew;
        Contact& c = const_cast<Contact&>(*it);
        c.updateStreet(streetNew);
        dCount++;
    }

    return dCount;
}


void Contacts::show()
{
    cc_phone_type& phIndexes = addressBook.get<0>();
    for(cc_phone_type::iterator it = phIndexes.begin(); it != phIndexes.end(); ++it){
        cout << "Contact{phone:"<<it->phone
        <<"|street:"<<it->street
        <<"|surname:"<<it->surname
        <<"|name:"<<it->name
        <<"|age:"<<it->age
        <<"}" << endl;
    }
}
