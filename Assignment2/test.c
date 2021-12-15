#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int binary_search(int arr[], int ele, int low, int high){
	if (low > high){
		return -1;
	}
	
	int mid = (high + low) / 2;
	
	if (arr[mid] == ele){
		return mid;
	}
	else if(arr[mid] < ele){
		binary_search(arr,ele,mid+1,high);
	}
	else {
		binary_search(arr,ele,low,mid-1);	
	}
}

int main(int argc, char *argv[]){
	printf("\nThis is new process. Process Id is: %d\n",getpid());
	int size = atoi(argv[1]);
	int arr[size];
	for(int i=2; i<size+2; i++){
		arr[i-2] = atoi(argv[i]);
	}
	
	int ele;
	
	printf("Enter the element to search: ");
	scanf("%d",&ele);
	
	int result = binary_search(arr,ele,0,size);
	if(result != -1){
		printf("\nElement found !!. It is present at index %d\n",result);
	}
	else{
		printf("\nElement no found !!\n");
	}

	printf("\nExiting from new process\n");
}
