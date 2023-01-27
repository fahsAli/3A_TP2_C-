#include "hotel.h"

std::string hotel::Hotel::hotelId() const{
    return _id;
}

std::string hotel::Hotel::hotelName() const{
    return _hname;
}

std::string hotel::Hotel::city() const{
    return _city;
}

std::vector <room::Room> hotel::Hotel::roomsList() const{
    return _rooms_list;
}

void hotel::Hotel::hotelId(std::string id){
    _id = id;
}

void hotel::Hotel::hotelName(std::string name){
    _hname = name;
}

void hotel::Hotel::city(std::string city){
    _city = city;
}

void hotel::Hotel::addRoom(room::Room room){
    _rooms_list.push_back(room);
}

void hotel::Hotel::removeRoom(room::Room room){
    auto it_end = std::remove(_rooms_list.begin(),_rooms_list.end(), room);
    _rooms_list.erase(it_end, _rooms_list.end());
}

int hotel::Hotel::emptyRooms() const{
    int cpt=0;
    for(auto it=_rooms_list.begin();it!=_rooms_list.end();++it){
        if(it->status()){
            cpt++;
        }
    }
    return cpt;
}

int hotel::Hotel::availableRooms(std::string type){
    int n=0;
    for(auto it=_rooms_list.begin();it!=_rooms_list.end();++it){
        if(it->type()==type){
            n++;
        }
    }
    return n;
}


hotel::Hotel::Hotel(std::string id,std::string name,std::string city)
:_id(id),_hname(name),_city(city){
    
}

void hotel::Hotel::changeStatus(int room_num,bool status){
    for(auto it=_rooms_list.begin();it!=_rooms_list.end();++it){
        if(it->roomNumber()==room_num){
            it->status(status);
            break;
        }
    }
}

std::ostream& hotel::operator<<(std::ostream& os,const hotel::Hotel& h){
    os << ">> hotel name : " + h.hotelName() + "  " + h.hotelId() + "\n";
    os << ">> city : " + h.city() + "\n";
    os << ">> available rooms : " + std::to_string(h.emptyRooms()) + "\n\n";
    return os;
}