#include "config.h"

#ifdef MACIM /* macim.c: core routines */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int MacIM;
char *IMLocalKey;
char *IMASCIIKey;

void SetIMState(int);
int GetIMState(void);
static void IMSetKey(char *);

void
SetIMState(int state) {
  if (!MacIM || !IMASCIIKey || !IMLocalKey)
    return;

  if (state)
    IMSetKey(IMLocalKey);
  else
    IMSetKey(IMASCIIKey);
}

int
GetIMState(void) {
  FILE *fp;
  char buf[1024];

  if (!MacIM || !IMASCIIKey || !IMLocalKey)
    return 0;

  fp = popen("im-select", "r");
  if (fp == NULL)
    return 0;
  (void)fread(buf, 1, sizeof(buf), fp);
  (void)pclose(fp);

  return strncmp(buf, IMLocalKey, strlen(IMLocalKey)) == 0;
}

static void
IMSetKey(char *key) {
  char buf[1024];

  if (snprintf(buf, sizeof(buf), "im-select %s", key) < sizeof(buf))
    system(buf);
}

#endif
