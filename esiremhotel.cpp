#include "esiremhotel.h"


void esirem::EsiremHotel::init(){

    std::srand(time(0));

    _esirem_hotel = hotel::Hotel("esirem","Esirem Hotel","Dijon");

    room::Room r1(100,"single",100);
    room::Room r2(101,"single",100);
    room::Room r3(102,"single",100);

    room::Room r4(200,"double",125);
    room::Room r5(201,"double",125);
    room::Room r6(202,"double",125);
    room::Room r7(203,"double",125);
    room::Room r8(204,"double",125);

    room::Room r9(300,"suite",210);
    room::Room r10(301,"suite",210);

    _esirem_hotel.addRoom(r1);
    _esirem_hotel.addRoom(r2);
    _esirem_hotel.addRoom(r3);
    _esirem_hotel.addRoom(r4);
    _esirem_hotel.addRoom(r5);
    _esirem_hotel.addRoom(r6);
    _esirem_hotel.addRoom(r7);
    _esirem_hotel.addRoom(r8);
    _esirem_hotel.addRoom(r9);
    _esirem_hotel.addRoom(r10);

    client::Client c1("Ali","Fahs");
    client::Client c2("Tom","Lantelme");

    _clients.push_back(c1);
    _clients.push_back(c2);
}

void esirem::EsiremHotel::roomDetails(){
    int option=0,sin=0,d=0,s=0;

    std::cout << "\nim in \n";
    
    sin = _esirem_hotel.availableRooms("single");
    d = _esirem_hotel.availableRooms("double");
    s = _esirem_hotel.availableRooms("suite");

    std::cout << "\n> please select the room type : " << std::endl;
    std::cout << "\n--------------------\n" << std::endl;
    std::cout << "1) single :" << std::endl;
    std::cout << "  " << sin << " rooms available" << std::endl;
    std::cout << "\n--------------------\n" << std::endl;
    std::cout << "2) double :" << std::endl;
    std::cout << "  " << d << " rooms available" << std::endl;
    std::cout << "\n--------------------\n" << std::endl;
    std::cout << "3) suite :" << std::endl;
    std::cout << "  " << s << " rooms available" << std::endl;
    std::cout << "\n--------------------\n" << std::endl;
    std::cout << "enter your choice : ";
    std::cin >> option;

    while((option < 1)||(option>3)){
        std::cout << "please choose again : "<< std::endl;
        std::cin >> option;
    }

    for(int i=0;i<_esirem_hotel.roomsList().size();i++){
        if((_esirem_hotel.roomsList().at(i).type()=="single")&&(option == 1)&&(_esirem_hotel.roomsList().at(i).status())){
            std::cout << _esirem_hotel.roomsList().at(i) << std::endl;
            break;
        }
        else if((_esirem_hotel.roomsList().at(i).type()=="double")&&(option == 2)&&(_esirem_hotel.roomsList().at(i).status())){
            std::cout << _esirem_hotel.roomsList().at(i) << std::endl;
            break;   
        }
        else if((_esirem_hotel.roomsList().at(i).type()=="suite")&&(option == 3)&&(_esirem_hotel.roomsList().at(i).status())){
            std::cout << _esirem_hotel.roomsList().at(i) << std::endl;
            break;   
        }else if( _esirem_hotel.roomsList().at(i) == (_esirem_hotel.roomsList().at(_esirem_hotel.roomsList().size()-1))){
            std::cout << "\nno " << ((option==1)?"single":(option==2)?"double":"suite") << " available \n";
        }
    }

}

void esirem::EsiremHotel::hotelDetails(){
    std::cout << "\n" << _esirem_hotel << "\n";
}

void esirem::EsiremHotel::clientProfile(){
    std::string lname="";
    bool found = false;
    std::cout << "enter your last name : " << std::endl;
    std::cin >> lname;
    
    while(!found){
        for(auto it=_clients.begin();it!=_clients.end();++it){
            if(it->lastName()==lname){
                std::cout << *it;
                found = true;
                break;
            }
        }

        if(!found){
            std::cout << "client not found please enter again or type 'cancel' : " << std::endl;
            std::cin >> lname;
            if(lname == "cancel"){
                found = true;
            }
        }
    }

}

void esirem::EsiremHotel::reservationDetails(){
    
    int days=0,day=0,month=0,year=0;
    bool found=false;

    while(!found){
        std::cout << "reservation details : " << std::endl;
        std::cout << "enter the number of days : ";
        std::cin >> days;

        while((days<1)){
            std::cout << "invalid days number please enter again : " << std::endl;
            std::cin >> days;
        }   

        std::cout << "now please fill the reservation date :"<< std::endl;
        std::cout << "starting with the day : ";
        std::cin >> day;
        std::cout << "now the month : ";
        std::cin >> month;
        std::cout << "now the year : ";
        std::cin >> year;

        for(int i=0;i<_reservations.size();i++){
            if((_reservations.at(i).reservationDate()==date::Date(day,month,year))&&(_reservations.at(i).daysNumber()==days)){
                std::cout << _reservations.at(i);
                found = true;
                break;
            }
        }

        if(!found){
            std::cout << "info not found please try again (enter 1) or cancel (enter 0) : ";
            std::cin >> found;
            found = !found;
        }

    }

}


void esirem::EsiremHotel::createProfile(){
    std::string fname="",lname="";
    std::cout << "create profile : " << std::endl;
    std::cout << "enter your first name : ";
    std::cin >> fname;
    std::cout << "enter your last name : ";
    std::cin >> lname;
    _clients.push_back(client::Client(fname,lname));
}

bool esirem::EsiremHotel::checkroom(){

    int option=0,dnum=0,day=0,month=0,year=0,room_num=0;
    bool choose=false,found=false;
    std::string str;

    std::cout << "enter room type (single,double,suite) : ";
    std::cin >> str;

    while(!choose){
        if(str=="single"){
            option = 1;
            choose = true;
        }else if(str=="double"){
            option = 2;
            choose = true;
        }else if(str=="single") {
            option = 3;
            choose = false;
        }else{
            std::cout << "please choose again : ";
            std::cin >> str;
        }   
    }

    choose = false;
    std::cout << "now please fill the reservation date : " << std::endl;
        std::cout << "enter day : ";
        std::cin >> day;
        std::cout << "enter month : ";
        std::cin >> month;
        std::cout << "enter year : ";
        std::cin >> year;
        std::cout << "enter days number : ";
        std::cin >> dnum;



    for(int i=0;i<_esirem_hotel.roomsList().size();i++){
        if((_esirem_hotel.roomsList().at(i).type()=="single")&&(option == 1)&&(_esirem_hotel.roomsList().at(i).status())){
            std::cout << _esirem_hotel.roomsList().at(i) << std::endl;
            found = true;
            break;
        }
        else if((_esirem_hotel.roomsList().at(i).type()=="double")&&(option == 2)&&(_esirem_hotel.roomsList().at(i).status())){
            std::cout << _esirem_hotel.roomsList().at(i) << std::endl;
            found = true;
            break;   
        }
        else if((_esirem_hotel.roomsList().at(i).type()=="suite")&&(option == 3)&&(_esirem_hotel.roomsList().at(i).status())){
            std::cout << _esirem_hotel.roomsList().at(i) << std::endl;
            found = true;
            break;   
        }else if(_esirem_hotel.roomsList().at(i) == (_esirem_hotel.roomsList().at(_esirem_hotel.roomsList().size()-1))){
            std::cout << "\nno " << ((option==1)?"single":(option==2)?"double":"suite") << " available \n";
        }
        room_num++;
    }

    if(found){

        std::cout << "now please select your profile : " << std::endl;
        int i=1;
        for(auto it=_clients.begin();it!=_clients.end();++it){
            std::cout << i <<") " << *it;
            i++;
        }
        std::cout << i << ") create a profile" << std::endl;
        std::cout << "enter your choice : ";
        std::cin >> i;

        while((i<1)||(i>_clients.size())){
            std::cout << "please enter again : ";
            std::cin >> i;
        }

        if(i ==(_clients.size()+1)){
            this->createProfile();
            reservation::Reservation r(_esirem_hotel.roomsList().at(room_num),*(_clients.end()-1),"esirem Hotel",dnum,date::Date(day,month,year));
            _reservations.push_back(r);
            _esirem_hotel.changeStatus(_esirem_hotel.roomsList().at(room_num).roomNumber(),false);
            std::cout << *(_reservations.end()-1);
        }else{
            reservation::Reservation r(_esirem_hotel.roomsList().at(room_num),_clients.at(i-1),"esirem Hotel",dnum,date::Date(day,month,year));
            _reservations.push_back(r);
            _esirem_hotel.changeStatus(_esirem_hotel.roomsList().at(room_num).roomNumber(),false);
            std::cout << *(_reservations.end()-1);
        }
        return true;
    }

    return false;

}

void esirem::EsiremHotel::addRoom(){
    std::string type="";
    float ppn=0;
    int num=0;
    std::cout << "enter room type : ";
    std::cin >> type;

    std::cout << "enter the price : ";
    std::cin >> ppn;

    std::cout << "enter room number : ";
    std::cin >> num;

    _esirem_hotel.addRoom(room::Room(num,type,ppn));
}



void esirem::EsiremHotel::allReservation(){
    std::cout << ">> all reservation : " << std::endl;
    for(auto it=_reservations.begin();it!=_reservations.end();++it){
        std::cout << *it;
    }
}


void esirem::EsiremHotel::showReservationWithName(){

    std::string lname="";
    bool found=false;
    std::cout << "enter your last name or your id : ";
    std::cin >> lname;
    for(int i=0;i<_reservations.size();i++){
        if((lname == _reservations.at(i).client().lastName())||(lname == _reservations.at(i).client().clientId())){
            std::cout << _reservations.at(i) << std::endl;
            found = true;
        }
    }
    if(!found){
        std::cout << ">> reservstion not found \n" << std::endl;
    }
}

void esirem::EsiremHotel::showReservationWithId(){

    int id;
    bool found=false;
    std::cout << "enter your reservation id : ";
    std::cin >> id;
    for(int i=0;i<_reservations.size();i++){
        if(id == _reservations.at(i).reservationId()){
            std::cout << _reservations.at(i) << std::endl;
            found = true;
            break;
        }
    }
    if(!found){
        std::cout << ">> reservstion not found \n" << std::endl;
    }
}


void esirem::EsiremHotel::removeReservation(){

    int id;
    bool found=false;
    std::cout << "enter your reservation id : ";
    std::cin >> id;
    for(int i=0;i<_reservations.size();i++){
        if(id == _reservations.at(i).reservationId()){
            found = true;
            auto it_end = std::remove(_reservations.begin(),_reservations.end(), _reservations.at(i));
            _reservations.erase(it_end, _reservations.end());
            break;
        }
    }
    if(!found){
        std::cout << ">> reservstion not found \n" << std::endl;
    }

}

void esirem::EsiremHotel::editReservation(){
    int id,option=0,days=0,day=0,month=0,year=0;
    bool found=false;
    std::cout << "enter your reservation id : ";
    std::cin >> id;
    for(int i=0;i<_reservations.size();i++){
        if(id == _reservations.at(i).reservationId()){
            found = true;

            std::cout << "what do you want to change : " << std::endl;
            std::cout << "1) days number" << std::endl;
            std::cout << "2) date" << std::endl;
            std::cout << "3) room" << std::endl;
            std::cout << "4) cancel" << std::endl;
            std::cin >> option;
            
            while((option < 1)||(option>4)){
                std::cout << "please choose again : "<< std::endl;
                std::cin >> option;
            }

            if(option==4){
                break;
            }

            switch (option)
            {
            case 1:
                while(days<=0){
                std::cout << "enter days number :";
                std::cin >> days;}
                _reservations.at(i).daysNumber(days);
                break;
            case 2:
                std::cout << "now please fill the new reservation date :"<< std::endl;
                std::cout << "starting with the day : ";
                std::cin >> day;
                std::cout << "now the month : ";
                std::cin >> month;
                std::cout << "now the year : ";
                std::cin >> year;
                _reservations.at(i).reservationDate(date::Date(day,month,year));
                break;
            case 3:
                if(this->checkroom()){
                        int id= _reservations.at(i).reservationId();
                        bool found=false;
                           for(int i=0;i<_reservations.size();i++){
                                if(id == _reservations.at(i).reservationId()){
                                    found = true;
                                    auto it_end = std::remove(_reservations.begin(),_reservations.end(), _reservations.at(i));
                                    _reservations.erase(it_end, _reservations.end());
                                    break;
                                }
                            }
                }
                break;
            }
            break;
        }
    }
    if(!found){
        std::cout << ">> reservstion not found \n" << std::endl;
    }
}

void esirem::EsiremHotel::launch(){
    
    this->init();

    int option = 0;
    bool end = false;

    std::cout << "=============================================" << std::endl;
    std::cout << "           welcome to ESIREM Hotel           " << std::endl;
    std::cout << "=============================================" << std::endl;

    while(!end){
        std::cout << "how can i help you ?" << std::endl;
        std::cout << "1)  add a room" << std::endl; 
        std::cout << "2)  add a client" << std::endl;   
        std::cout << "3)  room details" << std::endl;
        std::cout << "4)  reserve a room" << std::endl; 
        std::cout << "5)  all reservation" << std::endl;
        std::cout << "6)  hotel details" << std::endl;
        std::cout << "7)  reservation details with date" << std::endl;
        std::cout << "8)  reservation details with Name ou id" << std::endl;
        std::cout << "9)  reservation details with ID" << std::endl;
        std::cout << "10) cancel reservation" << std::endl;
        std::cout << "11) edit reservation " << std::endl;
        std::cout << "12) quit" << std::endl;        
        
        std::cout << "enter your choice : ";
        std::cin >> option; std::cout << std::endl;

        while((option < 1)||(option>12)){
            std::cout << "please choose again : "<< std::endl;
            std::cin >> option;
        }

        switch (option)
        {
            case 1:
                this->addRoom();
                break;
            case 2:
                this->createProfile();
                break;
            case 3:
                this->roomDetails();
                break;
            case 4:
                this->checkroom();
                break;
            case 5:
                this->allReservation();
                break;
            case 6:
                this->hotelDetails();
                break;
            case 7:
                this->reservationDetails();
                break;
            case 8:
                this->showReservationWithName();
                break;
            case 9:
                this->showReservationWithId();
                break;
            case 10:
                this->removeReservation();
                break;
            case 11:
                this->editReservation();
                break;
            case 12:
                end=true;
                break;
        }

    }


}

esirem::EsiremHotel::EsiremHotel(){}
