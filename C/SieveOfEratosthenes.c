// LIST PRIME NUMBERS SMALLER THAN OR EQUAL TO 'n' USING SIEVE OF ERATOSTHENES.

#include<stdio.h>
#include<math.h>

int main()
{
    int arr[10000];
    int i, j, n;
    printf ("\nEnter the end limit of the list of prime numbers : ");
    scanf ("%d", &n);

    if (n <= 0)                                                             // Checking boundary conditions.
    {
        printf ("--------------WARNING!---------------\n");
        printf ("Please enter a positive integer only!\n");
    }

    else if (n >= 2)
    {
        for (i = 2; i < n+1; i++)
            arr[i] = 0;                                                     // Initially all indices are unmarked.

        for (i = 2; i <= sqrt(n); i++)
        {
            for (j = 2; j <= n; j++)
                arr[j*i] = 1;                                               // Marking composite indices.
        }

        printf ("\nFollowing are the prime numbers smaller than or equal to %d :\n", n);

        for (i = 2; i <= n; i++)
        {
            if (arr[i] == 0)
                printf ("%d\n", i);                                          // Printing unmarked ie prime indices.
        }
    }

    else
    {
        printf ("\nNo prime numbers in the chosen range.\n");
    }

    return 0;
}
