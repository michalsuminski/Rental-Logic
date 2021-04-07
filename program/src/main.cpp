#include<iostream>
#include <boost/date_time.hpp>
using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

int main()
{
    pt::ptime empty = pt::not_a_date_time;
    cout << empty << endl;
    pt::ptime now = pt::second_clock::local_time();
    cout << now << endl;
    pt::ptime then = pt::ptime(gr::date(2015,5,13),pt::hours(9)+pt::minutes(25));
    cout << then << endl;
    pt::time_period period(then, now);
    cout << period << endl;
    cout << period.length() << endl;
    cout << period.length().hours() << endl;
    cout << period.length().minutes() << endl;
    cout << (then>now) << endl;
    cout << (then<=now) << endl;
    return 0;
}