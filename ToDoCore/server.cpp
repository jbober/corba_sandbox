
#include <time.h>
#include <iostream>
using namespace std;
#include "timeS.h"
class Time_impl : public virtual POA_Time {
public:
virtual TimeOfDay get_gmt() throw(CORBA::SystemException);
};
TimeOfDay
Time_impl::
get_gmt() throw(CORBA::SystemException)
{ 
 time_t time_now = time(0);
struct tm * time_p = gmtime(&time_now);
TimeOfDay tod;
tod.hour = time_p->tm_hour;
tod.minute = time_p->tm_min;
tod.second = time_p->tm_sec;
return tod; 
} 
int main()
{
    cout << "this is server executable" << endl;
	return 0;
}




