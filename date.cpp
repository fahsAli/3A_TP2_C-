#include "date.h"


bool date::isLeap(int year){
    return (((year & 3) == 0) &&(((year % 100) != 0)||((year % 400)==0)));
}


bool date::isDate(int day,int month,int year){
    if ((day < 1) || (day>31)) return false;
    if ((month <1) || (month>12)) return false;

    if ((month == 2) && (day > 28) && (!isLeap(year))) return false;
    if ((month == 2) && (day > 29) && isLeap(year)) return false;
    if (((month == 4) || (month == 6) ||
        (month == 9) || (month == 11)) && (day > 30)) return false;
    return true;
}

int date::Date::day() const{
    return _day;
}

int date::Date::month() const{
    return _month;
}

int date::Date::year() const{
    return _year;
}

void date::Date::day(int day){
    if(isDate(day,_month,_year)){
        _day = day;
    }
}

void date::Date::month(int month){
    if(isDate(_month,month,_year)){
        _month = month;
    }
}

void date::Date::year(int year){
    if(isDate(_day,_month,year)){
        _year = year;
    }
}

date::Date::Date(int day,int month,int year)
:_day(day),_month(month),_year(year){
    bool status = isDate(day,month,year);
    assert(status && "Date is not valid");
}

int date::getDaysInMonth(int month,int year){
    switch (month)
    {
    case 1: case 3: case 5:
    case 7: case 8: case 10:
    case 12:
        return 31;
        break;
    case 4: case 6: 
    case 9: case 11:
        return 30;
        break;
    default:
        return ((isLeap(year))?29:28);
        break;
    }
}

date::Date date::next(date::Date d){
    int day=d.day(),month=d.month(),year=d.year();
    if((d.month()==12)&&(d.day()==31)){
        day=1;
        month=1;
        year+=1;
    }else if(day==getDaysInMonth(month,year)){
        day=1;
        month+=1;
    }else{
        day+=1;
    }
    return date::Date(day,month,year);
}

std::ostream& date::operator<<(std::ostream& os, const date::Date& dt){
    os << std::to_string(dt.day()) << "/" << std::to_string(dt.month()) << "/" << std::to_string(dt.year()) << "\n";
    return os;
}

bool date::operator>(const date::Date& d1,const date::Date& d2){
    return ((d1.year()>=d2.year())&&(d1.month()>=d2.month())&&(d1.day()>d2.day()));
}

bool date::operator<(const date::Date& d1,const date::Date& d2){
    return !(d1>d2);
}

bool date::operator==(const date::Date& d1,const date::Date& d2){
    return ((d1.day()==d2.day())&&(d1.month()==d2.month())&&(d1.year()==d2.year()));
}

date::Date date::operator+(const date::Date d,int num){
    date::Date d2 = d;
    for(int i=0;i<num;i++){
        d2 = date::next(d2);
    }
    return d2;
}


