#include "application.h"
#include <stdio.h>

int main(void) {
    if (!application_init()) {
        printf("Failed to initialize application!");
        return -1;
    }

    application_run();

    application_shutdown();
    return 0;
}
