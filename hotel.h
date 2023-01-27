#pragma once
#ifndef HOTEL_HEADER
#define HOTEL_HAEDER
#include <string>
#include "room.h"
#include "date.h"
#include <vector>
#include <algorithm>

namespace hotel{
    class Hotel{
        public:
            Hotel(std::string id="null",std::string name="null",std::string city="null");

            std::string hotelId() const;
            std::string hotelName() const;
            std::string city() const;
            std::vector <room::Room> roomsList() const;

            void hotelId(std::string id);
            void hotelName(std::string name);
            void city(std::string city);

            void addRoom(room::Room room);
            void removeRoom(room::Room room);

            int emptyRooms() const;

            int availableRooms(std::string type);

            void changeStatus(int room_num,bool stat);


        private:
            std::string _id;
            std::string _hname;
            std::string _city;
            std::vector <room::Room> _rooms_list;            
    };
    std::ostream& operator<<(std::ostream& os,const Hotel& h);

}

#endif