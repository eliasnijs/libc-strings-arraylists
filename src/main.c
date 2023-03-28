#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define ENABLE_DEBUG_MESSAGES 1
#define ENABLE_ASSERT 1

#include "cbase/cbase.h"

#include "arraylist.h"
#include "arraylist.c"

#include "string.h"
#include "string.c"

#include "tests.c"

#include "cbase/newfile.c"

S32
main()
{
  Tu_RunMultiple(test_arenas);
  Tu_RunMultiple(test_strings);
  Tu_RunMultiple(test_arraylists);
  return 0;
}











