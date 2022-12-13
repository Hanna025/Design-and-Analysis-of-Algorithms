head.h

#include<math.h>
#include<float.h>
#include<iostream>
using namespace std;

class Points
{
   int x;
   int y;
public:
    Points();
    Points(int,int);
    ~Points();
    Points(const Points&);
    int get_x();
    int get_y();
    void set_x(int);
    void set_y(int);
    float distance(Points,Points);
    float bruteForce(Points[],int);

    friend istream& operator>>(istream&,Points&);
    friend ostream& operator<<(ostream&,Points&);

};

imp.cpp
#include"head.h"
Points::Points()
{
  x = 0;
  y = 0;
}

Points::~Points(){}

Points::Points(int a,int b)
{
  x = a;
  y = b;
}

Points::Points(const Points& p)
{
  x = p.x;
  y = p.y;
}

int Points::get_x()
{
  return x;
}

int Points::get_y()
{
  return y;
}

void Points::set_x(int s)
{
  x = s;
}

void Points::set_y(int t)
{
  y = t;
}

float Points::distance(Points i,Points j)
{
  return sqrt(((i.x-j.x)*(i.x-j.x)) + ((i.y-j.y)*(i.y-j.y)));
}

float Points::bruteForce(Points pt[30],int n)
{
  float d = 10000.00;
  Points q,r;
  for(int i=0;i<=n;i++)
   {
    for(int j=i+1;j<=n;j++)
     {
      if(distance(pt[i],pt[j])<d)
       {
         d = distance(pt[i],pt[j]);
         q = pt[i];
         r = pt[j];
       }
     }
   }
 cout<<"The closest pair is:"<<"["<<"("<<q.x<<","<<q.y<<")"<<","<<"("<<r.x<<","<<r.y<<")"<<"]"<<"\n";
 cout<<"Distance between the points:";
 return d;
}

istream& operator>>(istream& myin,Points& p)
{
  cout<<"Enter the x & y cordinates of the point\n";
  cin>>p.x>>p.y;
  return myin;
}

ostream& operator<<(ostream& myout,Points& p)
{
  cout<<"The required coordinates\n";
  cout<<"("<<p.x<<","<<p.y<<")";
  return myout;
}

app.cpp
#include"head.h"

#include<iostream>
using namespace std;

int main()
{
 	Points* pt;
 	int i,point;
 	cout<<"**Brute Force Techinque to Find Closest Pair**\n";
 	cout<<"Number of Co-ordinates\n";
 	cin>>point;
 	pt = new Points[point];
 	cout<<"Enter the Pair of Points\n";
 	for(i=1;i<=point;i++)
 	{
  		cin>>pt[i];
 	}
 	cout<<pt[30].bruteForce(pt,point);
 	cout<<"\n";
}
