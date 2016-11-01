#include "../mat/mat.h"
#include <stdio.h>

//TODO: move to headers
#define MIN_WORD_LEN 3
#define ERROR_COULD_NOT_ALLOC 2


// returns error code
int generate_successor_matrix(Mat * succ, FILE * fd_source_dict) {
    printf("Generating succ matrix.\n");    
    //TODO
    return 0;
}

void generate_store_matrix(Mat * succ, int word_len, char * target_dir)
{
    printf("Storing matrix for word len %u\n", word_len);    
    //TODO
}

// returns max word len
int generate_create_ordered_dicts(char * src_dict_filename, char * target_dir) {
    // TODO
    return 15;
}

int generate_main(char * src_dict_filename, char * target_dir) {
    uint32_t error_code = 0;
    printf("Creating ordered dirctionaries\n");
    uint32_t max_word_len = generate_create_ordered_dicts(src_dict_filename, target_dir);
    for (uint32_t word_len = MIN_WORD_LEN; word_len <= max_word_len && error_code == 0; word_len++) {
        printf("Working on word len %u\n", word_len);
        // TODO: open source dict into memory
        FILE * fd_source_dict = NULL;
        uint32_t word_count = 100; //TODO: get word count from source dict
        Mat succ = mat_alloc(word_count);
        error_code = (succ.size == word_count) ? 0 : ERROR_COULD_NOT_ALLOC;
        if(error_code == 0) {
            error_code = generate_successor_matrix(&succ, fd_source_dict);
        }
        if(error_code == 0) {
            generate_store_matrix(&succ, word_len, target_dir);
        }
        if(error_code != ERROR_COULD_NOT_ALLOC) {
            mat_free(succ);
        }
    } 
    printf("Complete!\n");
    return error_code;
}
