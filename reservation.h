#pragma once
#ifndef RESERVATION_HEADER
#define RESERVATION_HAEDER
#include "client.h"
#include "date.h"
#include "room.h"
#include <iostream>

namespace reservation{
    class Reservation{
        public:
            Reservation(room::Room room,client::Client& client,std::string hid="null",int days=0,date::Date resdate=date::Date());

            date::Date reservationDate() const;
            int daysNumber() const;
            std::string hotelId() const;
            client::Client client() const;
            float totalFees() const;
            room::Room room() const;
            int reservationId() const;

            void reservationDate(date::Date date);
            bool daysNumber(int days_num);
            void hotelId(std::string id);
            void client(client::Client client);

            void changeReservationDays(int days);
            void changeReservationDate(date::Date date);

            bool canReserveRoom(date::Date d2,int days);


        private:
            int _reservation_id;
            date::Date _reservation_date;
            int _days_num;
            std::string _hotel_id;
            client::Client _client;
            float _total_fees;
            room::Room _room;
    };
    std::ostream& operator<<(std::ostream& os,const Reservation r);
    bool operator==(Reservation r1,Reservation r2);
}

#endif