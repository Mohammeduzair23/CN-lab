#include <stdio.h>

int a[100], b[100], i, j, len;

/* Generator polynomial (17 bits → CRC-16) */
int gp[] = {1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};

void div();

int main()
{
    printf("\nEnter the length of the data frame: ");
    scanf("%d", &len);

    printf("Enter the message bits: ");
    for(i = 0; i < len; i++)
        scanf("%d", &a[i]);

    /* Append 16 zeros */
    for(i = 0; i < 16; i++)
        a[len + i] = 0;

    len = len + 16;

    /* Copy data to b[] */
    for(i = 0; i < len; i++)
        b[i] = a[i];

    /* Perform CRC division */
    div();

    /* XOR remainder with original data */
    for(i = 0; i < len; i++)
        b[i] = b[i] ^ a[i];

    printf("\nData to be transmitted: ");
    for(i = 0; i < len; i++)
        printf("%d ", b[i]);

    /* Receiver side */
    printf("\nEnter the received data: ");
    for(i = 0; i < len; i++)
        scanf("%d", &a[i]);

    div();

    /* Check for error */
    for(i = 0; i < len; i++)
    {
        if(a[i] != 0)
        {
            printf("\nError in received message\n");
            return 0;
        }
    }

    printf("\nNo error in received message\n");
    return 0;
}

/* CRC Division Function */
void div()
{
    for(i = 0; i <= len - 17; i++)
    {
        if(a[i] == 1)
        {
            for(j = 0; j < 17; j++)
            {
                a[i + j] = a[i + j] ^ gp[j];
            }
        }
    }
}
