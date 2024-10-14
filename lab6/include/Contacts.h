#ifndef CONTACTS_H
#define CONTACTS_H
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/bind.hpp>
#include <set>
#include "Contact.h"

using namespace std;
using namespace boost::multi_index;


typedef multi_index_container<
    Contact,
    indexed_by<
        hashed_unique<member<Contact, std::string, &Contact::phone>>,
        hashed_non_unique<member<Contact, std::string, &Contact::street>>,
        hashed_non_unique<member<Contact, std::string, &Contact::surname>>,
        ordered_non_unique<member<Contact, int, &Contact::age>>>>
    contact_multi;
typedef contact_multi::nth_index<0>::type cc_phone_type;
typedef contact_multi::nth_index<1>::type cc_street_type;
typedef contact_multi::nth_index<2>::type cc_surname_type;
typedef contact_multi::nth_index<3>::type cc_age_type;


class Contacts
{
private:
    contact_multi addressBook;

public:
    virtual ~Contacts();

    bool addContact(Contact contact);
    bool rmvContact(const string phone);

    cc_phone_type::iterator findByPhone(const string phone);
    int findAllByStreet(const string street, bool print=true);
    int findAllByAgeRange(int startAge, int endAge, bool print=true);
    int countAllAgedFull(bool print=false);
    int countUniqueSurnamed();

    int changeStreet(const string streetPrev, const string streetNew);

    void show();
};

#endif // CONTACTS_H
