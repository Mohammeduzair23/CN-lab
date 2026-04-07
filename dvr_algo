#include <stdio.h>
#include <stdlib.h>

#define NULL_VAL 999
#define NODES 10

int no;

struct node
{
    int a[NODES][4];   // [destination][1=dest,2=distance,3=next hop]
} router[NODES];

void init(int r)
{
    int i;
    for(i = 1; i <= no; i++)
    {
        router[r].a[i][1] = i;          // destination node
        router[r].a[i][2] = NULL_VAL;   // distance
        router[r].a[i][3] = -1;         // next hop
    }

    router[r].a[r][2] = 0;  // distance to itself is 0
    router[r].a[r][3] = r;  // next hop to itself
}

void inp(int r)
{
    int i;
    printf("\nEnter distance from node %d to other nodes\n", r);
    printf("Enter 999 if there is no direct route\n");

    for(i = 1; i <= no; i++)
    {
        if(i != r)
        {
            printf("Enter distance to node %d: ", i);
            scanf("%d", &router[r].a[i][2]);
            router[r].a[i][3] = i;   // next hop is direct node
        }
    }
}

void display(int r)
{
    int i;
    printf("\nRouting table for node %d:\n", r);
    printf("Dest\tDist\tNextHop\n");

    for(i = 1; i <= no; i++)
    {
        if(router[r].a[i][2] >= NULL_VAL)
            printf("%d\tINF\t-\n", router[r].a[i][1]);
        else
            printf("%d\t%d\t%d\n",
                   router[r].a[i][1],
                   router[r].a[i][2],
                   router[r].a[i][3]);
    }
}

void dv_algo(int r)
{
    int i, j, cost;

    for(i = 1; i <= no; i++)
    {
        if(router[r].a[i][2] != NULL_VAL && router[r].a[i][2] != 0)
        {
            for(j = 1; j <= no; j++)
            {
                cost = router[r].a[i][2] + router[i].a[j][2];

                if(cost < router[r].a[j][2])
                {
                    router[r].a[j][2] = cost;
                    router[r].a[j][3] = i;
                }
            }
        }
    }
}

int main()
{
    int i, x, y;
    char choice;

    printf("Enter number of nodes (less than 10): ");
    scanf("%d", &no);

    for(i = 1; i <= no; i++)
    {
        init(i);
        inp(i);
    }

    printf("\nInitial Routing Tables:\n");
    for(i = 1; i <= no; i++)
        display(i);

    for(i = 1; i <= no; i++)
        dv_algo(i);

    printf("\nRouting Tables After Distance Vector Algorithm:\n");
    for(i = 1; i <= no; i++)
        display(i);

    while(1)
    {
        printf("\nDo you want to find shortest path? (y/n): ");
        scanf(" %c", &choice);   // space before %c fixes input issue

        if(choice == 'n')
            break;

        printf("Enter source and destination nodes: ");
        scanf("%d %d", &x, &y);

        printf("Shortest path cost from %d to %d is: %d\n",
               x, y, router[x].a[y][2]);
    }

    return 0;
}
