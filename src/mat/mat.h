#ifndef MAT_H
#define MAT_H

#include <stdint.h>

/* Matrix elements defined as min int containing word identifiers */
typedef uint16_t MatElt;

typedef struct {
    uint32_t size;
    MatElt ** contents;
} Mat;

// returns matrix with size 0 if cannot alloc memory
Mat mat_alloc(int size);

void mat_free(Mat mat);

// multiplies matrix R on the right into L
// returns 0 if succesful, 1 if memory error
uint32_t mat_mul(Mat l, Mat r);

#endif //MAT_H

