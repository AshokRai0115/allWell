#include <stdio.h>
#include <stdbool.h>

int arrayLength = 100;
int mergedArray[1000];

void insert(int[], int *);
void delete(int[], int *);
void merge(int[], int[], int, int);
void traverse(int[], int);

int main()
{
    int i, n, arr1[10], arr2[10], len1, len2;
    char operation, raw;
    int arr[arrayLength];
    for (i = 0; i < arrayLength; i++)
    {
        arr[i] = 0;
    }
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter I or i for insert operation:\n");
    printf("Enter D or d for delete operation:\n");
    printf("Enter M or m for merging arrays:\n");
    printf("Enter E or e to exit\n");
    printf("Enter S or s to show array elements:\n");
    do{
    scanf("%c", &raw);
    printf("Enter your choice\n");
    scanf("%c", &operation);
    
    switch (operation)
    {
        case 'I':
        case 'i':
            insert(arr, &n);
            break;

        case 'D':
        case 'd':
            delete (arr, &n);
            break;

        case 's':
        case 'S':
            traverse(arr,n);
            break;
        case 'M':
        case 'm':
            
            printf("Enter the number of elements in first array: \n");
            scanf("%d", &len1);
            arr1[len1];
            printf("Enter %d elements for first array:\n", len1);
            for (i = 0; i < len1; i++)
            {
                scanf("%d", &arr1[i]);
            }
            printf("Enter the number of elements in second array: \n");
            scanf("%d", &len2);
            arr2[len2];
            printf("Enter %d elements for second array:\n", len2);
            for (i = 0; i < len2; i++)
            {
                scanf("%d", &arr2[i]);
            }
            merge(arr1, arr2, len1, len2);
            break;

        default:
            printf("Please Enter valid character.");
    }
}while(operation != 'E' || operation != 'e');
}

void insert(int arr[], int *n)
{
    int value, index;
    char modify, raw;
    bool status = true;
    if (*n == arrayLength)
    {
        printf("The array is full. Cannot perform insertion.");
        return;
    }
    do
    {
        printf("Enter the index of array to be inserted in: ");
        scanf("%d", &index);
        scanf("%c", &raw);
        if (index < *n)
        { // check if the index is already occupied
            printf("You are going to modify data..\n");
            printf("Press y if you want to continue else press n: ");
            scanf("%c", &modify);
            if (modify == 'y')
            { // check if the user want to modify the data in the index
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                arr[index] = value;
                status = false;
            }
        }
        else
        {
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            arr[index] = value;
            *n = index + 1;
            status = false;
        }
    } while (status);
    // traverse(arr, *n);
}

// Delete element in given index
void delete(int arr[], int *n)
{
    int index, i;
    do
    {
        printf("Enter the index of element to be deleted: ");
        scanf("%d", &index);
        if (index > *n)
        { // check if the index is empty
            printf("\nThe index does not have any data.\n");
        }
    } while (index > *n);
    printf("Deleted: %d\n", arr[index]);
    for (i = index; i < (*n - 1); i++)
    {
        arr[i] = arr[i + 1];
    }

    *n = *n - 1;
    // traverse(arr, *n);
}

// merge two arrays and store the result in global var mergedArray
void merge(int arr1[], int arr2[], int len1, int len2)
{
    int i, j, k, n;
    n = len1 + len2;
    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            for (j = 0; j < len1; j++)
            {
                mergedArray[j] = arr1[j];
            }
        }
        else
        {
            for (k = 0; k < len2; k++)
            {
                mergedArray[j] = arr2[k];
                j++;
            }
        }
    }

    traverse(mergedArray, n);
}

void traverse(int arr[], int n)
{
	int i;
    printf("\nThe elements in the array are:\n");
    for (i = 0; i < n; i++)
    {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
}
