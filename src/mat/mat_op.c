#include <stdlib.h>
#include <string.h>
#include "mat.h"

// multiplies matrix R on the right into L
// returns 0 if succesful, 1 if memory error
uint32_t mat_mul(Mat l, Mat r)
{
    uint32_t retval = 0;
    uint32_t * l_row = malloc(l.size * sizeof(MatElt));
    if(l_row == NULL) {
        retval = 1;
    }
    else {
        for(uint32_t i = 0; i < l.size; i++) {
            memcpy(l_row, l.contents[i], l.size * sizeof(MatElt));
            for(uint32_t j = 0; j < l.size; j++) {
                l.contents[i][j] = 0;
                for(uint32_t k = 0; k < l.size; k++) {
                    l.contents[i][j] += (l_row[k] * r.contents[k][j]);
                }
            }
        }
        free(l_row);
    }
    return retval;
}
