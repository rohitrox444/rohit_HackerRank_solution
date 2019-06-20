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

// Complete the staircase function below.
void staircase(int n) {

    // for(int i =1;i<=n;i++){
    //     printf("\t");
        
    //     for(int j =0;j<i;j++)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }

    int i,j,k;
// printf("Enter the no of lines: ");
// scanf("%d",&n);


for(i=1;i<=n;i++){
//this loop is used for printing the spaces    
for(j=0;j<n-i;j++){
printf(" ");
}
//this is used for printing the '#'
for(k=0;k<i;k++){
printf("#");
}
//to move to next line
printf("\n");
}
// getch();
// return 0;

}

int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    staircase(n);

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
