#include <stdio.h>

int main()
{
    int i,j,n,m,k,y;
    int alloc[10][10],max[10][10],avail[10];
    int work[10],finish[10],need[10][10],safeseq[10];
    int ind=0,flag;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resources: ");
    scanf("%d",&m);

    printf("Enter allocation matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter max matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }

    printf("Enter available resources:\n");
    for(i=0;i<m;i++)
        scanf("%d",&avail[i]);

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    printf("Need Matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }


    for(i=0;i<m;i++)
        work[i]=avail[i];

    for(i=0;i<n;i++)
        finish[i]=0;


    for(k=0;k<n;k++){
        for(i=0;i<n;i++){

            if(finish[i]==0){

                flag=0;

                for(j=0;j<m;j++){
                    if(need[i][j]>work[j]){
                        flag=1;
                        break;
                    }
                }

                if(flag==0){

                    safeseq[ind++]=i;

                    for(y=0;y<m;y++){
                        work[y]+=alloc[i][y];
                    }

                    finish[i]=1;
                }
            }
        }
    }

    if(ind==n){
        printf("\nSystem is in safe state\n");
        printf("Safe Sequence:\n");

        for(i=0;i<n;i++)
            printf("P%d ",safeseq[i]);
    }
    else{
        printf("\nSystem is not in safe state");
    }

    return 0;
}
