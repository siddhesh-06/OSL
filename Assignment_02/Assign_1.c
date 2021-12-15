#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

void sortArray(int arr[], int size){
    for(int i=0; i<n-1){
        for(int j=0;j<n-1-i;j++){
            int temp = arr[j+1];
            arr[j]=arr[j+1];
            arr[j]=temp;
        }
    }
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d", arr[i]);
    }
}

int main(){
    int arr ={ 4,1,6,2}
    int size=4;

    printArray(arr,size);
}