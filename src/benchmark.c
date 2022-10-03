/* #define Time(a,r) {\ */
/*   S64 start = nanos();\ */
/*   a;\ */
/*   S64 end = nanos();\ */
/*   (*r) = (F64)(end - start)*10e-9;\ */
/* } */
/*  */
/* internal S64 */
/* nanos()  */
/* {  */
/*   struct timespec start; */
/*   clock_gettime(CLOCK_MONOTONIC_RAW, &start); */
/*   return (S64)start.tv_sec*1000000000 + (S64)start.tv_nsec; */
/* } */
