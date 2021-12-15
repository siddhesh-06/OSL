#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

void merge(int arr[], int low, int mid, int high){
    int temp[high-low+1];
    int count=0;
    int i=low, j=mid+1;
    while(i<=mid && j<=high){
        if(arr[i] < arr[j]){
            temp[count] = arr[i];
            i++;
        }
        else{
            temp[count] = arr[j];
            j++;
        }
        count++;
    }
    
    while(i<=mid){
        temp[count] = arr[i];
        count++;
        i++;
    }
    
    while(j<=high){
        temp[count] = arr[j];
        j++;
        count++;
    }
    
    count = 0;
    for(int k=low; k<=high; k++){
        arr[k] = temp[count];
        count++;
    }
}


void mergesort(int arr[], int low, int high){
    if(low >= high){
        return;
    }
    else {
        int mid = (high + low) / 2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}



int main(int argc, int *argv[]){
	printf("\nHello, learning execv function");
	printf("\nThis is old process. Process Id is: %d\n",getpid());
	
	int n;
	printf("Enter size of an array: ");
	scanf("%d",&n);
	
	int arr[n];
	
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	
	mergesort(arr,0,n-1);
	
	printf("\n");
	printf("Sorted array is: ");
	
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
	
	printf("\n");

	char *buffer [n+3];
	
	buffer[0] = "./test";
	buffer[1] = malloc(sizeof(int));
	snprintf(buffer[1],(sizeof(int)),"%d",n);
	for(int i=2; i<n+2; i++){
		buffer[i] = malloc(sizeof(int));
		snprintf(buffer[i],(sizeof(int)),"%d",arr[i-2]);
	}
	buffer[n+2] = NULL;

	execv(buffer[0],buffer);
	
	printf("\nThis is the line after execv call");
}
	
