#include<stdio.h>
 void DFS(int);
 int G[10][10],visited[10],n;
 void DFS(int i){
     int j;
     visited[i]=1;
     for(j=0;j<n;j++)
        if(!visited[j]&&G[i][j]==1)
            DFS(j);
 }
 void main()
 {
     int i,j,vtx;
     printf("Enter Number of Vertices's: ");// 4
     scanf("%d",&n);
     printf("\nEnter Adjacency Matrix of The Graph:\n");    // 0 1 1 0
     for(i=0;i<n;i++){                                      // 1 0 1 0
         printf("Enter values of %d Row : ",i+1);           // 1 0 0 1
         for(j=0;j<n;j++)                                   // 1 1 1 0
            scanf("%d",&G[i][j]);
     }
     for(i=0;i<n;i++)
        visited[i]=0;

    printf("\nEnter the starting vertex:"); // 0
     scanf("%d", &vtx);
     DFS(vtx);
     printf("\nThe nodes which are reachable are:\n");
     for(i=0; i < n; i++) {
         if(visited[i])
            printf("%d\t", i);
         else {
             printf("\nNot all nodes are reachable So, DFS is not possible.");
             break;
         }
     }
     getch();
}

