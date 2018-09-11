//dated:11/09/2018
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 9
//finding the minimum distance
int mindis(int dis[],bool spt[]){
	int min=INT_MAX,min_index;
	int i;
	for(i=0;i<V;i++){
		if(spt[i]==false&&dis[i]<=min)
			min=dis[i];min_index=i;
	}
	return min_index;
}

//printing of the solution to the problem
int print(int dis[],int n){
    int i;
	printf("vertex distance from source");
	for(i=0;i<V;i++)
		printf("%d tt %d\n",i,dis[i]);
}

//implementation of the algorithm
void dijkstra(int graph[V][V],int src){
	int dis[V];//will hold the distance from the source src to ith value
	int spt[V];//return true if the selected path is the shortest path
    int i,k,v;
	//initializing the value of distance and spt with infinity and false
	for(i=0;i<V;i++){
		dis[i]=INT_MAX;spt[i]=false;
	}
	dis[src]=0;

	//finding the shortest path for all vertices
	for(k=0;k<V-1;k++){
		int u=mindis(dis,spt);
		spt[u]=true;
		for(v=0;v<V;v++){
			if(!spt[v]&&graph[u][v]&&dis[u]!=INT_MAX&&dis[u]+graph[u][v]<dis[v])
				dis[v]=dis[u]+graph[u][v];
		}
	}
	print(dis,V);
}
// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}
