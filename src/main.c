#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define ENABLE_DEBUG_MESSAGES 1
#define ENABLE_ASSERT 1

#include "cbase/cbase.h"

#include "s32arraylist.c"
#include "arraylist.h"
#include "arraylist.c"

#include "string.h"
#include "string.c"

#include "benchmark.c"

#include "tests.c"

S32
main()
{
  Tu_RunMultiple(test_arenas);
  Tu_RunMultiple(test_strings);
  return 0;
}











