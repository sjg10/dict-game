#include "main.h"
#include <stdio.h>

int main(int argc, char ** argv) {
    MAIN_INTRODUCTION;
    // TODO get from argv
    generate_main("src.dict", "target_dir");
    return 0;
}
