#pragma once
#ifndef CLIENT_HEADER
#define CLIENT_HAEDER
#include <string>

namespace client{
    class Client{
        public:
            Client(std::string fname="null",std::string lname="null");

            std::string firstName() const;
            std::string lastName() const;
            std::string clientId() const;

            void firstName(std::string fname);
            void lastName(std::string lname);
            void clientId(std::string id);

        private:
            std::string _id;
            std::string _fname;
            std::string _lname;
    };
    std::ostream& operator<<(std::ostream& os,const Client& client);
}


#endif