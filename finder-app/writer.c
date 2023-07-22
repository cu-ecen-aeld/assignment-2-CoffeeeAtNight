#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

#define DEFAULT_PROGNAME "writer_utility" 

int main (int argc, char *argv[]) {
  FILE *fileCheck;

  if(argc != 3) {
    syslog(LOG_INFO, "Writer Utility: Error occurred two arguments expected.\n");
    printf("Writer Utility: Error occurred two arguments expected.\n");
    return 1;
  }

  openlog(DEFAULT_PROGNAME, LOG_PID, LOG_USER);

  for (int i = 0; i < argc; i++) {
    FILE *fp;

    if(i == 1) {
      fp = fopen(argv[i], "w+");
    }

    if(i == 2) {
      if(fp == NULL) {
        syslog(LOG_ERR, "File Pointer is NULL, cannot write to file.");
        printf("File Pointer is NULL, cannot write to file. \n");
        return 1;
      }

      fprintf(fp, "%s", argv[i]);
      fclose(fp);
      printf("Wrote to file, now exiting... \n");
    }
  }

  if((fileCheck = fopen(argv[1], "r")) != NULL) {
    fclose(fileCheck);
  } else {
    syslog(LOG_ERR, "File not found after creation...");
    printf("File not found after creation...");
    return 1;
  }

  closelog();

  return 0;
}
