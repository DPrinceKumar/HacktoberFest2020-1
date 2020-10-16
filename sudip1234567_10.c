/*       
          Name: sudipta kumar sahoo
          Program Name : reverse an array    (as per list)                           
*/

/*###########################Program start################################## */

#include <stdio.h>
int main()
{
  int n, c, d, a[100], b[100];

  printf("Enter the number of elements in array\n");
  scanf("%d", &n);

  printf("Enter array elements\n");

  for (c = 0; c < n ; c++)
    scanf("%d", &a[c]);


  for (c = n - 1, d = 0; c >= 0; c--, d++)
    b[d] = a[c];


  for (c = 0; c < n; c++)
    a[c] = b[c];

  printf("The array after reversal:\n");

  for (c = 0; c < n; c++)
    printf("%d\n", a[c]);

  return 0;
}