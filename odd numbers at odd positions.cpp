#include <stdio.h>    
     int main()    
{    
    int arr[] = {1, 2, 3, 4, 5};        
    int length = sizeof(arr)/sizeof(arr[0]);    
        
    printf("Elements of given array present on odd position: \n");       
    for (int i = 0; i < length; i = i+2) {     
        printf("%d\n", arr[i]);     
    }     
    return 0;    
}    
