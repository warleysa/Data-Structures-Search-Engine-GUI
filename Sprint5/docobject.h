#ifndef DOCOBJECT_H
#define DOCOBJECT_H
#include <string>

class docObject {

public:
    int id;
    std::string date;
    std::string title;
    std::string body;
    std::string code;

    docObject() {
        id = -1;
    }

    docObject(int iid, std::string idate,
                   std::string ititle, std::string ibody, std::string icode) {
        id = iid;
        date = idate;
        title = ititle;
        body = ibody;
        code = icode;
    }


};

#endif // DOCOBJECT_H
