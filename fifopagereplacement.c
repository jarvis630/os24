#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, j, count = 0, pf = 0;
    int rs[25], m[10];

    int n = atoi(argv[1]);  
    int f = atoi(argv[2]);   

    printf("Enter the reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    
    for(i = 0; i < f; i++)
        m[i] = -1;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < f; j++)
        {
            if(m[j] == rs[i])
                break;
        }

      
        if(j == f)
        {
            m[count] = rs[i];
            count++;
            pf++;

            if(count == f)
                count = 0;
        }

        for(j = 0; j < f; j++)
            printf("%d\t", m[j]);

        if(j == f)
            printf("PF No: %d", pf);

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pf);

    return 0;
}
