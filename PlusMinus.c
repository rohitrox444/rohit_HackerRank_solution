#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the plusMinus function below.
void plusMinus(int arr_count, int* arr) {
    // variable for array element

    int i;

    //Now, variables for storing fraction values of 
    //postive , negetive , zero values

    float postive_val=0, negetive_val=0, zero_val=0;

    for(i=0;i<arr_count;i++){
        //if we found a positive value in array then we increase 
        //'postive_val' counter variable
        if(arr[i]>0)
        {
            postive_val++;
        }
        //if we found a negetive value in array then we increase 
        //'negetive_val' counter variable
        else if(arr[i]<0){
            negetive_val++;
        }
        //if we found a ZERO value in array then we increase 
        //'zero_val' counter variable
        else if(arr[i]==0){
            zero_val++;
        }
    }

    //NOW, here we are calculating the fraction for each type of values
    float postive_frac = postive_val/arr_count;
    float negetive_frac = negetive_val/arr_count;
    float zero_frac = zero_val/arr_count;

    printf("%f\n",postive_frac);
    printf("%f\n",negetive_frac);
    printf("%f",zero_frac);

}

int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** arr_temp = split_string(readline());

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* arr_item_endptr;
        char* arr_item_str = *(arr_temp + i);
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(arr + i) = arr_item;
    }

    int arr_count = n;

    plusMinus(arr_count, arr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
