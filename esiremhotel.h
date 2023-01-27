#pragma once
#ifndef ESIREM_HOTEL_HEADER
#define ESIREM_HOTEL_HAEDER
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "client.h"
#include "date.h"
#include "room.h"
#include "hotel.h"
#include "reservation.h"



namespace esirem{
    class EsiremHotel{
        public:
            EsiremHotel();

            void init();
            void launch();

            void addRoom();
            void allReservation();
            void roomDetails();
            void hotelDetails();
            void clientProfile();
            void reservationDetails();
            bool checkroom();
            void createProfile();
            void showReservationWithName();
            void showReservationWithId();
            void editReservation();

            void removeReservation();

        private:
            hotel::Hotel _esirem_hotel;
            std::vector <client::Client> _clients;
            std::vector <reservation::Reservation> _reservations;
    };

}


#endif