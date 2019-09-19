/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements  
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int findMissing(int arr[], int tamano){
    int lowest =2;


    for(int i=0; i< tamano; i++){
        if(arr[i]==lowest){
            lowest += 2;
        }else if(arr[i]>lowest){
            arr[i]=lowest;
            lowest +=2;
        }


    }
    cout<<endl;
    cout<<"El multiplo de 2 mas bajo y faltante en el arreglo es: "<<lowest<<endl;
    return lowest;
}

int main()
{
    int cases=0,cases2;
    cout<<"Ingrese el numero de casos a evaluar (entre 1 y 10):";
    cin>>cases2;
    if(cases<1 || cases >10){
        cout<<"Debe ingresar el numero de casos a evaluar entre 1 y 10 ";
        exit(0);
    }


    while(cases!=cases2) {
        int size, i;
        cout<<"Ingrese el tamaño del arreglo : ";
        cin>>size;
        int arr[size];
        for (i = 0; i < size; i++) {
            cout<<"Ingrese elemento del arreglo  : ";
            cin >> arr[i];

        }

        int n = sizeof(arr) / sizeof(arr[0]);
        quickSort(arr, 0, n - 1);



        findMissing(arr,n);

        cases++;
    }

    return 0;
}  