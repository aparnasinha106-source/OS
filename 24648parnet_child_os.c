#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    pid_t pid;
    FILE *fp;
    char buffer[100];

    // Get input before forking
    printf("Enter text to write into file: ");
    fgets(buffer, sizeof(buffer), stdin);

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } 
    else if (pid == 0) { 
        // CHILD PROCESS: Wait and then Read
        sleep(2); 
        printf("\n Child: Reading from file...\n");
        fp = fopen("data.text", "r");
        if (fp == NULL) {
            perror("Child: Error opening file");
            exit(1);
        }
        char ch;
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
        }
        fclose(fp);
        printf("\n Child: Done.\n");
    } 
    else { 
        // PARENT PROCESS: Write to file
        printf("Parent: Writing to file...\n");
        fp = fopen("data.text", "w");
        if (fp == NULL) {
            perror("Parent: Error opening file");
            exit(1);
        }
        fprintf(fp, "%s", buffer);
        fclose(fp);
        printf("Parent: Write complete. Waiting for child...\n");
        wait(NULL); // Wait for child to finish reading
    }

    return 0;
}
