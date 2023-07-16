/* Delete element that equals key from array and return the array.
*/

#include <stdio.h>
#include <stdlib.h>

/*delete function takes in an input arry, size and key.*/
int* delete(int arr[], int size, int key){
    int index = -1;
    for(int i=0; i< size; i++){
        if(arr[i]== key){
            index = i;
	    break;	
        }
    }

//new size allocated
int return_size = size -1;
 int* new_arr = (int*)malloc(return_size * sizeof(int));

//copy elements to new array before the key.
for(int i=0; i< index; i++){
new_arr[i] = arr[i];
}

//copy elements after key.
for(int i = index+1; i<size; i++){
new_arr[i -1] = arr[i];
} 

return new_arr;
}

int main(){
    
// Take key and size of array input	
    int key, size;
    printf("Enter the number of elements to add to the array:");
    scanf("%d", &size);

// allocate size of array and add elements.
    int* array = (int*)malloc(size * sizeof(int));
    printf("Enter %d elements:", size);
    for(int i=0; i< size; i++){
        scanf("%d", &array[i]);
    }

//input key to delete
    printf("Enter key to delete: ");
    scanf("%d", &key);

//return new array after deleting key.
    int* new_arr = delete(array, size, key);
    printf("The new array is: " );
    for(int i=0; i<size - 1; i++){
        printf("%d", new_arr[i]);
    }
printf("\n"); 

//free allocated memory
    free(new_arr);
    free(array);
    return 0;
}
