#include "Time.h"
#include <iostream>
#include <iomanip>

Time::Time() {
  hour = 0;
  minute = 0;
  second = 0;
}

Time::Time(uintptr_t aHour, uintptr_t aMinute, uintptr_t aSecond){
  hour = aHour;
  minute = aMinute;
  second = aSecond;
}

uintptr_t Time::getHour() const{
  return hour;
}

uintptr_t Time::getMinute() const{
  return minute;
}

uintptr_t Time::getSecond() const{
  return second;
}

void Time::setHour(uintptr_t h){
  hour = h;
}

void Time::setMinute(uintptr_t m){
  minute = m;
}

void Time::setSecond(uintptr_t s){
  second = s;
}



void Time::PrintAmPm(){
  if(hour >= 12){
    if(hour > 12){
      hour = hour%12;
    }
    std::cout << hour << ':' << std::setw(2) << std::setfill('0') << minute << ':' << std::setw(2) << \
    second << " pm" << std::endl;
  }else if(hour != 0){
    std::cout << hour << ':' << std::setw(2) << std::setfill('0') << minute << ':' << std::setw(2) << \
    second << " am" << std::endl;
  }else{
    std::cout << 12 << ':' << std::setw(2) << std::setfill('0') << minute << ':' << std::setw(2) << \
    second << " am" << std::endl;
  }

}

bool isEarlierThan(const Time& t1, const Time& t2){
  if(t1.getHour() < t2.getHour()){
    return true;
  }else if(t1.getHour() < t2.getHour() && t1.getMinute() < t2.getMinute()){
    return true;
  }else if(t1.getHour() < t2.getHour() && t1.getMinute() < t2.getMinute() && t1.getSecond() < t2.getSecond()){
     return true;
  }else{
    return false;
  }
}
