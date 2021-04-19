#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);
int maximo(int vector[], int n);
int comparar(int vector1[], int n1, int vector2[], int n2);
void seleccion(int vector[], int n);

void swap(int* x, int* y){
    /* Swap values stored between memory address one called x and memory addres 2 called y. */
    int aux = *x;
    *x = *y;
    *y = aux;
}

int maximo(int vector[], int n){
    /* Return the index of the max value in an array. */
    if (!n){
        return -1;
    }
    int maxValueIndex = 0;
    for (int i=1;i<n;i++){
        maxValueIndex = vector[maxValueIndex] < vector[i] ? i : maxValueIndex;
    }
    return maxValueIndex;
}

int comparar(int vector1[], int n1, int vector2[], int n2){
    /* Compare two arrays.
    Rules:
     - Return -1 if vector2[i] is greater than vector1[i] or Vector 1 is an orded subset of vector 2.
     - Return 1 if vector1[i] is greater than vector2[i] or Vector 3 is an orded subset of vector 1.
     - Return 0 if the are equal in every element and both array have the same size.
     */
    int i = 0;
    int j = 0;
    int value1 =vector1[i];
    int value2 =vector2[j];
    while(1){
        if (i<n1){ // Still have elements left from vector 1
            value1 = vector1[i];
        } else if (j<n2){ // Dont have elements left in vector 1 but It does in vector 2
            return -1;
        }
        if (j<n2){
            value2 = vector2[j];
        } else { // Dont have elements left in vector 2 but It does in vector 1
            return 1;
        }
        if (value1 < value2){ // I have eleemnts left in vector2 or value2 is bigger than value1
            return -1;
        } else if (value1 > value2){
            return 1;
        }
        // If they are value1 equals to value2 continue
        i++;
        j++;
        if (!(i<n1) && !(j<n2)){ // Both have reached the limit and no differences so far, means they are equal
            return 0;
        }
    }
}

void printArray(int vector[], int n){
    for (int i=0; i<n;i++){
        printf("%d", vector[i]);
    }
}

void seleccion(int vector[], int n){
    /* Sort an array using selection sort algorithm. */
    /* Sort an array using selection sort algorithm. */
    for (int i=0; i<n;i++){
        int maxValueIndex = maximo(&vector[i], n-i);
        // Max from position i with top of elements length - i
        swap(&vector[i], &vector[maxValueIndex+i]);
        // Swap between vector i position and the max value 
        // Max value index + i because maximo returns a relative position + i it is absolute position
    }
    printArray(vector, n);
}



int main(){
    const int SIZE0 = 5;
    int vector1[] = {1,9,5,0,0};
    const int SIZE = 5;
    int vector2[] = {1,9,5,0,0};
    
    printf("%d\n",  comparar(vector1, SIZE0, vector2, SIZE) );
    seleccion(vector2,SIZE);
    return(0);

}