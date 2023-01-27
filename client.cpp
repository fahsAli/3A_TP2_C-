#include "client.h"


std::string client::Client::firstName() const{
    return _fname;
}

std::string client::Client::lastName() const{
    return _lname;
}

std::string client::Client::clientId() const{
    return _id;
}

void client::Client::firstName(std::string fname){
    _fname = fname;
}

void client::Client::lastName(std::string lname){
    _lname = lname;
}

void client::Client::clientId(std::string id){
    _id = id;
}

client::Client::Client(std::string fname,std::string lname)
:_fname(fname),_lname(lname){
    _id = fname[0]+lname;
}

std::ostream& client::operator<<(std::ostream& os,const client::Client& client){
    os << client.firstName() + " " + client.lastName() + "\n";
    os << "id : " + client.clientId() + "\n\n";
    return os;
}


