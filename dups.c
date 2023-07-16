// sort array and remove duplicates
#include <stdio.h>

//swap elements in array
void swap(int*a, int*b){
	int temp = *a;
	*a= *b;
	*b= temp;
}

//remove duplicates from array
int delete(int arr[], int n){
if(n==0){
return 0;
}

int index = 1;
for(int i =0; i< n; i++){
	if(arr[i] != arr[i -1]){ //check if current element is different than the previous one
		arr[index] = arr[i];// if different move to next position in array
		index++;
}
}
return index;// return new lwngth of array after removing duplicates.
}


//sort array in ascending order
void sort(int arr[], int n){
for(int i =0; i< n-1; i++){
	for(int j = i + 1; j< n; j++){
		if(arr[j] < arr[i]){ 	//swap if current element smaller than previous
			swap(&arr[j], &arr[i]);
}
}
}
}

int main(){
int n;

printf("Enter the number of elements in array: ");
scanf("%d", &n);

int arr[n];
printf("Enter %d elements in array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

// sort and remove duplicates
    sort(arr, n);
    int new_length = delete(arr, n);

    printf("Array with duplicates removed and sorted: ");
    for (int i = 0; i < new_length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;


} 
