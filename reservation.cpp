#include "reservation.h"

date::Date reservation::Reservation::reservationDate() const{
    return _reservation_date;
}

int reservation::Reservation::daysNumber() const{
    return _days_num;
}

std::string reservation::Reservation::hotelId() const{
    return _hotel_id;
}

client::Client reservation::Reservation::client() const{
    return _client;
}

float reservation::Reservation::totalFees() const{
    return _total_fees;
}

room::Room reservation::Reservation::room() const{
    return _room;
}

int reservation::Reservation::reservationId() const{
    return _reservation_id;
}

void reservation::Reservation::reservationDate(date::Date date){
    _reservation_date = date;
}


bool reservation::Reservation::daysNumber(int days_num){
    if(days_num >= 1){
        _days_num = days_num;
        return true;
    }
    return false;
}

void reservation::Reservation::hotelId(std::string id){
    _hotel_id=id;
}

void  reservation::Reservation::client(client::Client client){
    _client = client;
}

void reservation::Reservation::changeReservationDays(int days){
    while(!this->daysNumber(days)){
        std::cout << "invalide days number please enter again : ";
        std::cin >> days;
    }
}

void reservation::Reservation::changeReservationDate(date::Date date){
    this->reservationDate(date);
}


bool reservation::Reservation::canReserveRoom(date::Date d2,int days){
    return ((_room.status())||((d2+days)<_reservation_date)||(d2>(_reservation_date+_days_num)));
}

reservation::Reservation::Reservation(room::Room room,client::Client& client,std::string hid,int days,date::Date resdate)
:_room(room),_client(client),_hotel_id(hid),_days_num(days),_reservation_date(resdate){
    while(!this->daysNumber(days)){
        std::cout << "invalide days number please enter again : ";
        std::cin >> days;
    }
    _room.status(false);
    _total_fees = _room.pricePerNight() * _days_num;
    _reservation_id = 1000+ std::rand()%9000;
}

std::ostream& reservation::operator<<(std::ostream& os,const reservation::Reservation r){
    std::string str;
    str = "\n--------------------\n";
    str = str + "reservation id : " + std::to_string(r.reservationId()) + "\n";
    str = str + "client : " + r.client().firstName() + " " + r.client().lastName() + "\n";
    str = str + "hotel : " + r.hotelId() + "\n";
    str = str + "room : " + std::to_string(r.room().roomNumber()) + "\n";
    str = str + "total fees : " + std::to_string(r.totalFees()) + "\n";
    str = str + "days number : " + std::to_string(r.daysNumber()) + "\n";
    str = str + "from : " + std::to_string(r.reservationDate().day()) + "/" + std::to_string(r.reservationDate().month()) + "/" + std::to_string(r.reservationDate().year()) + "\n";
    str = str + "until : " + std::to_string((r.reservationDate()+r.daysNumber()).day()) + "/" + std::to_string((r.reservationDate()+r.daysNumber()).month()) + "/" + std::to_string((r.reservationDate()+r.daysNumber()).year());
    str = str + "\n--------------------\n";
    os << str;
    return os;
}

bool reservation::operator==(reservation::Reservation r1,reservation::Reservation r2){

    return (r1.reservationId()==r2.reservationId());

}