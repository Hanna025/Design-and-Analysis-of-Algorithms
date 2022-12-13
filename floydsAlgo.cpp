head.h
#include<iostream>
using namespace std;
#define V 4
#define INF 99999
void floyd(int[][V]);
void display(int[][V]);


fimp.cpp
#include"head.h"
#define V 4
#define INF 99999
#include<iostream>
using namespace std;
void floyd(int graph[][V])
{
    int dist[V][V], i, j, k;
     for (i = 0; i < V; i++)
     {
      for (j = 0; j < V; j++)
      {
            dist[i][j] = graph[i][j];
      }
    }
    for (k = 0; k < V; k++)
    {
       for (i = 0; i < V; i++)
        {
          for (j = 0; j < V; j++)
            {
               if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

cout<<"The following matrix shows the shortest distances between every pair of vertices \n";
display(dist);
}

void display(int dist[][V])
{
  for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF"<<"\t";
            else
                cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
}

app.cpp
#include"head.h"
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
        int n;
        int graph[V][V];
        cout<<"Enter the weight matrix\n";
        for(int i=0;i<4;i++)
         {
          for(int j=0;j<4;j++)
           {
             cin>>graph[i][j];
           }
         }
         cout<<"The weighted graph\n";
         display(graph);
         floyd(graph);
         return 0;
}

