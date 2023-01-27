#pragma once
#ifndef ROOM_HEADER
#define ROOM_HAEDER
#include <string>

namespace room {
    
    class Room{
        public:
            Room(int room_num=-1,std::string type="null",float ppn=0);

            int roomNumber() const;
            std::string type() const;
            float pricePerNight() const;
            bool status() const;

            void roomNumber(int num);
            void type(std::string type);
            void pricePerNight(float ppn);
            void status(bool status);

        private:
            int _room_num;
            std::string _type;
            float _price_per_night;
            bool _status;
    };
    void changeRoomPrice(Room& room,float newprice);
    std::ostream& operator<<(std::ostream& os,const Room& r);
    bool operator==(Room r1,Room r2);
}

#endif