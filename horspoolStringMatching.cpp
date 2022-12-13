head.h
#include<string.h>
#include<iostream>
using namespace std;

void shiftTable(string);
int horspool(string,string);


imp.cpp
#include"head.h"
#include<string>
#include<string.h>

int t[500];
void shiftTable(string p)
{
        int i,j,m;
        m = p.length();
        for(i=0;i<500;i++){
        t[i] = m;
         }
        for(j=0;j<m-1;j++){
        t[p[j]] = m - 1 -j;
         }

}


int horspool(string txt,string pt)
{
        int i,j,k,l,m,n;
        n = txt.length();
        m = pt.length();
        cout<<"Length of thr string "<<n<<"\n";
        cout<<"Length of pattern "<<m<<"\n";
        i = m - 1;
        while( i < n)
        {
          k = 0;
          while((k<m) && (pt[m-1-k] == txt[i-k]))
          k++;
          if( k == m)
          return(i-m+1);
          else
          i+=t[txt[i]];
        }
   return -1;
}

main.cpp
#include"head.h"

#include<iostream>
using namespace std;


int main()
{
        string text,pattern;
        int pos;
        cout<<"Enter the text\n";
        cin>>text;
        cout<<"Enter the pattern\n";
        cin>>pattern;
        shiftTable(pattern);
        pos = horspool(text,pattern);
        if(pos >= 0)
        {
          cout<<"Pattern is found at: "<<pos+1<<"\n";
        }
        else
        cout<<"Pattern not found\n";
}
