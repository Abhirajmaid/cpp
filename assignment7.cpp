/*
Represent any real world graph using adjacency list /adjacency matrix. Find minimum spanning tree
using Kruskal’s algorithm.
*/
#define infinity 9999
#define MAX 20
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct edge
{
    int s,d,w;
}edg;
class graph
{ int G[MAX][MAX];
  int n;
  
  int set[20][20],cnt[20];
  int noe;
  public:
      graph()
    { n=0; }
      void readgraph();
      void printgraph();
      
      void edgelist();
      edg e[100];
      void selection_sort(edg e[100],int n);
      
      int kruskal(graph &);
      int findset(int);
      
};
void graph::readgraph()
{
    int i,j,vi,vj,weight;
    cout<<"\nEnter no. of vertices :\t";                    //accepting vertices and edges
    cin>>n;
    cout<<"\nEnter no. of edges :\t";
    cin>>noe;
    for(i=0;i<n;i++) 
        for(j=0;j<n;j++)                
            G[i][j]=0;                      //initialising the array
    
    for(i=0;i<noe;i++)
    {
        
        cout<<"Enter the value of src dest and weight :\t";
        cin>>vi;
        
        cin>>vj;
        
        cin>>weight;
        G[vi][vj]=G[vj][vi]=weight;                 //declaring matrix
    }
    
    
}
void  graph:: printgraph()
 {
    int i,j;
    cout<<"\nList of edges in the mst:\t";
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(G[i][j]!=0)                          //printing shortest path 
            cout<<"\n(u,v,wight)= ("<<i<<","<<j<<","<<G[i][j]<<")";
 }

void graph::edgelist()
{
    int i,j;
    int k=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
            {
                if(G[i][j]!=0)
                {
                e[k].s=i;
                e[k].d=j;
                e[k].w=G[i][j];
                k++;
                }
            }
    }
    cout<<"src\tdes\twgt\n";
    for(i=0;i<k;i++)
    {
        
        cout<<e[i].s<<"\t";
        cout<<e[i].d<<"\t";
        cout<<e[i].w<<"\n";
    }
    selection_sort(e,k);
}
void graph::selection_sort(edg e[100],int n)
{
    int temp=0,min=0,j,pos=0,k,i,mins=0,mind=0,temps=0,tempd=0;
    edg tempe, mine;
    for(i=0;i<n;i++)
    {
        mine=e[i];pos=i;
        for(j=i+1;j<n;j++)
        {
            if(e[j].w<mine.w)
            {
            
            mine=e[j];
            pos=j;
            }
        }
    //swap e[pos] and e[i]
    tempe=e[i];
    e[i]=mine;
    e[pos]=tempe;

    }
    cout<<"\nelemnts sorted are";
    for(k=0;k<n;k++)
    cout<<"\n"<<e[k].s<<"\t"<<e[k].d<<"\t"<<e[k].w;
}

int graph::findset(int x)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<cnt[i];j++)
        {
            if(x==set[i][j])
            return i;
        }
    }
    return -1;
}

int graph::kruskal(graph &mst)
{
    int i,j,min_cost=0;
    edgelist();  //create and sort edgelist
    
    for(i=0;i<n;i++)
    {
        set[i][0]=i;
        cnt[i]=1;
    }
    cout<<"\nLIST OF NEW EDGES IS:\n";
    for(i=0;i<noe;i++)
    {
        int p1=findset(e[i].s);
        int p2=findset(e[i].d);
        
        if(p1!=p2)//if source and destination vertex are in different sets
        {
            mst.G[e[i].s][e[i].d]=e[i].w;   // add in MST
            mst.G[e[i].d][e[i].s]=e[i].w;
            min_cost=min_cost+e[i].w;
            cout<<e[i].s<<"\t"<<e[i].d<<"\t"<<e[i].w<<"\n";
            
        
            for(j=0;j<cnt[p2];j++)//merge sets i.e. same component
            {
            set[p1][cnt[p1]]=set[p2][j];
            cnt[p1]++;                              
            }
        cnt[p2]=0;
        }
    }
    return min_cost;
}

int main()
{
    int opt,total_cost;
    graph g,mst;
    
    do
    {
        cout<<"\n\n1.read\n2.kruskal";
        cin>>opt;
        switch(opt)
        {
            case 1:g.readgraph();
                break;
            case 2:total_cost=g.kruskal(mst);
                //cout<<"\nMST matrix : \n";
                //mst.printgraph();
                cout<<"\n****MINCOST IS:"<<total_cost<<"****";
                break;
                
            
        }
    }while(opt!=0);
    return 0;
}

/*1.read
2.kruskal1

Enter no. of vertices : 6

Enter no. of edges :    5
Enter the value of src dest and weight :        0 1 10
Enter the value of src dest and weight :        0 2 3
Enter the value of src dest and weight :        1 2 13
Enter the value of src dest and weight :        3 4 5
Enter the value of src dest and weight :        4 2 7


1.read
2.kruskal2
src     des     wgt
0       1       10
0       2       3
1       2       13
2       4       7
3       4       5

elemnts sorted are
0       2       3
3       4       5
2       4       7
0       1       10
1       2       13
LIST OF NEW EDGES IS:
0       2       3
3       4       5
2       4       7
0       1       10

****MINCOST IS:25****

1.read
2.kruskal */
