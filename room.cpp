#include "room.h"

int room::Room::roomNumber() const{
    return _room_num;
}

std::string room::Room::type() const{
    return _type;
}

float room::Room::pricePerNight() const{
    return _price_per_night;
}

bool room::Room::status() const{
    return _status;
}

void room::Room::roomNumber(int num){
    _room_num = num;
}

void room::Room::type(std::string type){
    _type = type;
}

void room::Room::pricePerNight(float ppn){
    _price_per_night = ppn;
}

void room::Room::status(bool status){
    _status = status;
}

room::Room::Room(int room_num,std::string type,float ppn)
:_room_num(room_num),_type(type),_price_per_night(ppn){
    _status = true;
}


void room::changeRoomPrice(room::Room& room,float newprice){
    room.pricePerNight(newprice);
}


std::ostream& room::operator<<(std::ostream& os,const room::Room& r){
    std::string str;
    str = "-----------------------\n";
    str = str + "| Room number : " + std::to_string(r.roomNumber()) + "\n";
    str = str + "| Type        : " + r.type() + "\n";
    str = str + "| Price       : " + std::to_string(r.pricePerNight()) + "\n";
    str = str + "| status      : " + ((r.status())?"available":"reserved") + "\n";
    str = str + "-----------------------\n";
    os << str;
    return os;
}

bool room::operator==(room::Room r1,room::Room r2){
    return ((r1.roomNumber()==r2.roomNumber())&&(r1.type()==r2.type()));
}