#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#ifndef PATH_MAX
# define PATH_MAX 256
#endif
#define UNAME_MAX 33  /* 32 is the max username length (+ \0) */

// Windows drive letters
#ifndef DRIVE_LETTERS
# define DRIVE_LETTERS "c"
#endif

int main(int argc, const char **argv) {
  char cwd[PATH_MAX] = {0};
  char mnt_buf[7] = "/mnt/X\0";
  char home[UNAME_MAX + 6] = "/home/\0";
  char *uname;
  if (getcwd(cwd, PATH_MAX) == NULL) {
    fputs("wslcwd: could not get working directory\n", stderr);
    return 1;
  }
  /* Replace /mnt/<drive> with <drive>:/ */
  for (int i = 0; i < strlen(DRIVE_LETTERS); i++) {
    sprintf(mnt_buf, "/mnt/%c", tolower(DRIVE_LETTERS[i]));
    if (!strncmp(cwd, mnt_buf, 6)) {
      printf("%c:/%s", toupper(DRIVE_LETTERS[i]), cwd + 7);
      return 0;
    }
  }
  /* Replace /home/<uname> with ~ */
  /* If we can't get the username, just the print the path */
  uname = getenv("USER");
  if (uname != NULL) {
    (void)strcat(home, uname);
    if (!strncmp(cwd, home, strlen(home))) {
      printf("~%s", cwd + strlen(home));
      return 0;
    }
  }
  fputs(cwd, stdout);
  return 0;
}

