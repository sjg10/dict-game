#ifndef MAT_H
#define MAT_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

/* Matrix elements defined as min int containing word identifiers */
typedef uint16_t MatElt;

typedef struct {
    uint32_t size;
    MatElt ** contents;
} Mat;

// returns matrix with size 0 if cannot alloc memory
static inline Mat mat_alloc(int size)
{
    Mat ret;
    ret.size = 0;
    // Allocate an array to keep pointer to rows in
    MatElt ** row_ptr_array = (MatElt **) malloc(size * sizeof(MatElt *));
    if (row_ptr_array == NULL) {
        return ret;
    }
    // Allocate the rows
    for(uint32_t row = 0; row < size; row++) {
        row_ptr_array[row] = (MatElt *) malloc(size * sizeof(MatElt));
        if(row_ptr_array[row] == NULL)
        {
            // We couldmn't allocate a row, free previous mallocs and return
            for(uint32_t row_dealloc = 0; row_dealloc < row - 1; row_dealloc++) {
                free(row_ptr_array[row]);
            }
            free(row_ptr_array);
            return ret;
        }
    }
    // We could alloc everything, so fill in the size, and return complete!
    ret.contents = row_ptr_array;
    ret.size=size;
    return ret;
}


static inline void mat_free(Mat mat) {
    for(uint32_t row = 0; row < mat.size; row++) {
        free(mat.contents[row]);
    }
    free(mat.contents);
}

#endif //MAT_Hret
