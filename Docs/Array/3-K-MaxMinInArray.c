//Kth Max or min in array

#include <stdio.h>

int main()
{
    printf("Enter the size of array\n");
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nThe no stored are :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    for(int i =0 ; i<n ; i++)
    {
        for(int j =0 ; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("\n\nEnter the Kth term to print\n");
    int k ;
    scanf("%d",&k);
    printf("The kth minimum is : %d\nThe kth maximun is : %d",arr[k-1],arr[n-k]);

    return 0;
}
