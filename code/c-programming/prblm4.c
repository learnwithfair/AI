 #include<stdio.h>
 int ary[10][10],completed[10],n,cost=0;
 void mincost(int city){
     int i,ncity;
     completed[city]=1;
     printf("%d--->>",city+1);
     ncity=least(city);
     if(ncity==999){
         ncity=0;
         printf("%d",ncity+1);
         cost+=ary[city][ncity];
         return;
    }
    mincost(ncity);
 }
 int least(int c) {
     int i,nc=999;
     int min=999,kmin;
     for(i=0;i < n;i++){
         if((ary[c][i]!=0)&&(completed[i]==0))
             if(ary[c][i]+ary[i][c] < min){
                 min=ary[i][0]+ary[c][i];
                 kmin=ary[c][i];
                 nc=i;
             }
     }
     if(min!=999){
         printf("%d--->>",nc);
         cost+=kmin;
     }

     return nc;
 }

 int main(){
     int i,j,vtx;
     printf("Enter the number of nodes: ");
     scanf("%d",&n);
     printf("\nEnter the Cost Matrix\n");
     for(i=0;i < n;i++){                            // 0 3 4 6
         printf("Enter values of %d Row : ",i+1);   // 1 0 3 3
         for( j=0;j < n;j++)                        // 4 1 0 4
            scanf("%d",&ary[i][j]);                 // 2 4 3 0
         completed[i]=0;
     }
     printf("\nEnter the starting vertex:"); // 1
     scanf("%d", &vtx);
     printf("\n\nThe Path is:\n");
     mincost(vtx);
     printf("\n\nMinimum cost is %d  ",cost);
     return 0;
 }
