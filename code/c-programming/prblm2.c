#include<stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

 void bfs(int v) {
     for(i = 1; i <= n; i++)
        if(a[v][i] && !visited[i])
            q[++r] = i;
            printf("r = %d",r);
     if(f <= r) {
         visited[q[f]] = 1;
         bfs(q[f++]);
     }
 }

 void main() {
     int vtx;
     printf("\nEnter the number of Vertices :"); //4
     scanf("%d", &n);

     for(i=1; i <= n; i++) {
         q[i] = 0;
         visited[i] = 0;
     }

     printf("\nEnter graph data in matrix form:\n"); // 0 1 1 0
     for(i=1; i<=n; i++) {                           // 1 0 1 0
            printf("Enter values of %d Row : ",i);   // 1 0 0 1
         for(j=1;j<=n;j++) {                         // 1 1 1 0
            scanf("%d", &a[i][j]);
         }
     }

     printf("\nEnter the starting vertex:"); // 1
     scanf("%d", &vtx);
     bfs(vtx);
     printf("\nThe nodes which are reachable are:\n");
     for(i=1; i <= n; i++) {
         if(visited[i])
            printf("%d\t", i);
         else {
             printf("\nNot all nodes are reachable So, BFS is not possible.");
             break;
         }
     }
     getch();
 }

