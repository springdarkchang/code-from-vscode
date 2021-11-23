#include<iostream>
#include<cstring>
using namespace std;
int k;
class CDate
{
public:
    int Year, Month, Day;
    CDate(const CDate &d):Year(d.Year),Month(d.Month),Day(d.Day){}
    CDate(int y = 0, int m = 0, int d = 0) : Year(y), Month(m), Day(d) {}
    inline void SetYear()
    {
        cin >> Year;
    }
    inline void SetMonth()
    {
        cin >> Day;
    }
    inline void SetDay()
    {
        cin >> Day;
    }
    inline int GetYear()
    {
        return Year;
    }
    inline int GetMonth()
    {
        return Month;
    }
    inline int GetDay()
    {
        return Day;
    }
    inline void ShowDate()
    {
        cout << Year << "-" << Month << "-" << Day << endl;
    }
    string GetWeekNameofDate();
    string GetMonthNameofDate();
    int DaynumofMonth();
    bool IsLeapYear();
    bool operator<=(const CDate &d) const;
    bool operator==(const CDate &d) const;
    bool operator!=(const CDate &d) const
    {
        return !(*this == d);
    }
    CDate operator+(const CDate &d);
};
class CTime
{
public:
    int Hour, Minute, Second;
    CTime(const CTime &d):Hour(d.Hour),Minute(d.Minute),Second(d.Second){}
    CTime(int h = 0, int m = 0, int s = 0) : Hour(h), Minute(m), Second(s){}
    inline void SetHour()
    {
        cin >> Hour;
    }
    inline void SetMinute(int m)
    {
        cin >> Minute;
    }
    inline void SetSecond(int s)
    {
        cin >> Second;
    }
    inline int GetHour()
    {
        return Hour;
    }
    inline int GetMinute()
    {
        return Minute;
    }
    inline int GetSecond()
    {
        return Second;
    }
    inline void ShowTime()
    {
        cout << Hour << ":" << Minute << ":" << Second << endl;
    }
    bool operator<=(const CTime &t) const;
    bool operator==(const CTime &t) const;
    bool operator!=(const CTime &t) const {
        return !(*this == t);
    }
    void operator++();
    void operator--();
    CTime operator+(const CTime &t);
};
class CDateTime:public CDate, public CTime
{
public:
    CDateTime(CDate d,CTime t):CDate(d),CTime(t){}
    CDateTime(int y=0,int mo=0,int d=0,int h=0,int mi=0,int s=0):CDate(y,mo,d),CTime(h,mi,s){}
    void Showdt();
    CDateTime operator+(const CDateTime &dt);
};
string CDate::GetWeekNameofDate()
{
    int w;
    if(Month==1||Month==2)
    {
        Year--;
        Month += 12;
    }
    w = (Day + 2 * Month + 3 * (Month + 1) / 5 + Year + Year / 4 - Year / 100 + Year / 400)%7;
    switch (w)
    {
    case 0:
        return "Monday";
    case 1:
        return "Tuesday";
    case 2:
        return "Wednesday";
    case 3:
        return "Thurday";
    case 4:
        return "Friday";
    case 5:
        return "Saturday";
    case 6:
        return "Sunday";
    default:
        exit(0);
        break;
    }
}
string CDate::GetMonthNameofDate()
{
    switch (Month)
    {
    case 1:
        return "Janurday";
    case 2:
        return "Feburday";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "Ocober";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        exit(0);
        break;
    }
}
bool CDate::IsLeapYear()
{
    if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
        return true;
    else
        return false;
}
bool CDate::operator==(const CDate &d) const
{
    if(Year==d.Year&&Month==d.Month&&Day==d.Day)
        return true;
    else
        return false;
}
bool CDate::operator<=(const CDate &d) const
{
    if(Year>d.Year)
        if(Month>d.Month)
            if(Day>d.Day)
                return false;
    return true;
}
CDate CDate::operator+(const CDate &d)
{
    int n;
    CDate i;
    i.Day = Day + d.Day + k;
    i.Month = Month + d.Month;
    i.Year = Year + d.Year;
    n = i.DaynumofMonth();
    while (i.Day > n)
    {
        i.Day -= n;
        i.Month++;
        if (i.Month > 12)
        {
            i.Month -= 12;
            i.Year++;
        }
        n = i.DaynumofMonth();
    }
    k = 0;
    return i;
}
bool CTime::operator<=(const CTime &t) const
{
    if(Hour>t.Hour)
        if(Minute>t.Minute)
            if(Second>t.Second)
                return false;
    return true;
}
bool CTime::operator==(const CTime &t) const
{
    if(Hour==t.Hour&&Minute==t.Minute&&Second==t.Second)
        return true;
    return false;
}
void CTime::operator++()
{
    Second++;
    if (Second >= 60)
    {
        Second -= 60;
        Minute++;
    }
    if (Minute >= 60)
    {
        Minute -= 60;
        Hour++;
    }
    if (Hour >= 24)
        Hour -= 24;
}
void CTime::operator--()
{
    Second--;
    if (Second < 0)
    {
        Second += 60;
        Minute--;
    }
    if (Minute < 0)
    {
        Minute += 60;
        Hour--;
    }
    if (Hour < 0)
        Hour += 24;
}
int CDate::DaynumofMonth()
{
    if ((Month % 12) == 1 || (Month % 12) == 3 || (Month % 12) == 5 || (Month % 12) == 7 || (Month % 12) == 8 || (Month % 12) == 10 || (Month % 12) == 12)
        return 31;
    if ((Month % 12) == 4 || (Month % 12) == 6 || (Month % 12) == 9 || (Month % 12) == 11)
        return 30;
    if((Month%12)==2)
    {
        if(IsLeapYear())
            return 29;
        else
            return 28;
    }
    return -1;
}
CTime CTime::operator+(const CTime &t)
{
    CTime i;
    k = 0;
    i.Second = Second + t.Second;
    i.Minute = Minute + t.Minute;
    i.Hour = Hour + t.Hour;
    if (i.Second >= 60)
    {
        i.Second -= 60;
        i.Minute++;
    }
    if (i.Minute >= 60)
    {
        i.Minute -= 60;
        i.Hour++;
    }
    if (i.Hour >= 24)
    {
        i.Hour -= 24;
        k++;
    }
    return i;
}
void CDateTime::Showdt()
{
    cout << "The date is ";
    ShowDate();
    cout << "The time is ";
    ShowTime();
}
CDateTime CDateTime::operator+(const CDateTime &dt)
{
    CDate d;
    CTime t;
    t = this->CTime::operator+(dt);
    d = this->CDate::operator+(dt);
    return CDateTime(d,t);
}
int main()
{
    int y, mo, d, h, mi, s;
    cout << "Please enter time1" << endl;
    cin >> y >> mo >> d >> h >> mi >> s;
    CDateTime r1(y,mo,d,h,mi,s);
    cout << "Please enter time2" << endl;
    cin >> y >> mo >> d >> h >> mi >> s;
    CDateTime r2(y, mo, d, h, mi, s);
    r1.Showdt();
    r2.Showdt();
    if(r1.IsLeapYear())
        cout << "This year is leap year." << endl;
    else
        cout << "This year is not leap year." << endl;
    cout << "This month is " << r1.GetMonthNameofDate() << " and this day is " << r1.GetWeekNameofDate() << endl;
    CDateTime r = r1 + r2;
    r.Showdt();
    system("pause");
    return 0;
}