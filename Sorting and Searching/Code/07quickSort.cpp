#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int sizeOfArray(int*arr){
  return sizeof(arr) / sizeof(arr[0]);
}

void printArray(int arr[], int size);
int partition(int *a, int left, int right)
{
    /*
    Eg
    |15  20  30  40  7  8  5  50  10
  i  j                             p-> p!>15 
    |15  20  30  40  7  8  5  50  10
  i      j                         p-> p!>20
    |15  20  30  40  7  8  5  50  10
  i          j                     p-> p!>30
    |15  20  30  40  7  8  5  50  10
  i               j                p-> p!>40
    |15  20  30  40  7  8  5  50  10
  i                  j            p-> p>7 i++ then swap(j and i) 
    7 |20  30  40  15  8  5  50  10
    i                  j          p-> p>8 i++ then swap(j and i)
    7  8 | 30  40  15  20  5  50  10
       i                   j       p->  p>5 i++ then swap(j and i)
    7  8  5 | 40  15  20  30  50  10
          i                   j   p-> p!>50
    7  8  5  10 | 15  20  30  50  40//After Loop
          i                   j   p-> swap(i+1 and pi)
    Now left to 10 array will be send in the first recursion and the right array in second recursion while 10 is sorted
    */
    int pi = a[right];
    int i = left - 1;                       //i is at -1 index
    for (int j = left; j <= right - 1; j++) //j is at the left or first index and the loop will end before pivot
    {
        if (a[j] < pi) //if jth element is less than pivot then only i and j will be swapped
        {
            i++; //we add 1 in i as the --i is already less than pivot
            swap(&a[i], &a[j]);
        }
        printArray(a, 6);//👈Change the size of array here after, if you have change the orignal array.
    }
    //Now the pivot is still at the left and i is at the element i.e. nearest smallest to pivot
    //Now we will swap i + 1 and the pivot
    swap(&a[i + 1], &a[right]);
    printArray(a, 6);//👈Change the size of array here after, if you have change the orignal array.
    cout << "\n";
    //We return i + 1 as it is the index of pivot 
    return i + 1;
}

/*
Quick Sort on array - 15  20  30  40  7  8  5  50  10
    15 20 30 40 7 8 5 50 10 
    15 20 30 40 7 8 5 50 10 
    15 20 30 40 7 8 5 50 10 
    15 20 30 40 7 8 5 50 10 
    7 20 30 40 15 8 5 50 10 
    7 8 30 40 15 20 5 50 10 
    7 8 5 40 15 20 30 50 10 
    7 8 5 40 15 20 30 50 10 
    7 8 5 10 15 20 30 50 40 

    7 8 5 10 15 20 30 50 40
    7 8 5 10 15 20 30 50 40
    5 8 7 10 15 20 30 50 40

    5 8 7 10 15 20 30 50 40
    5 7 8 10 15 20 30 50 40

    5 7 8 10 15 20 30 50 40
    5 7 8 10 15 20 30 50 40 
    5 7 8 10 15 20 30 50 40
    5 7 8 10 15 20 30 50 40
    5 7 8 10 15 20 30 40 50

    5 7 8 10 15 20 30 40 50
    5 7 8 10 15 20 30 40 50
    5 7 8 10 15 20 30 40 50

    5 7 8 10 15 20 30 40 50
    5 7 8 10 15 20 30 40 50

    Sorted array:
    5 7 8 10 15 20 30 40 50
*/

void quickSort(int *a, int left, int right)
{
    //left->first element , right->last element in the array
    //left < right as after recursion the index of left and right should not meet at the pivot or anywhere
    //Almost everytime left<right it's just for surety
    if (left < right)
    {
        //First time sort
        int pi = partition(a, left, right);
        //after the pivot is in its currect position all the items to it's left of pivot are send
        //As in return of partition we get index of pivot as i + 1
        quickSort(a, left, pi - 1);
        //All the element left to the pivot
        //As in return of partition we get index of pivot as i + 1
        quickSort(a, pi + 1, right);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20 ,15};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}