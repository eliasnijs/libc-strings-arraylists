//////////////////////////////////////////////////////////////////////////////////////
//// NOTE(Elias): String

/* IMPORTANT(Elias): End character token '\0' is considered part of 
 * the string. The length of string accounts for this too. */

typedef struct String String;
struct String
{
  S32 l;
  char *str;
};

#define EvalPrintStr(s) printf("%s = \"%s\"\n", #s, s.str)

/* NOTE(Elias): returns a string from a char array and it's size */
#define str_lit(c,a,s) str_init(c, ArrayCount(c), a, s)
internal void str_init(char *str, S32 l, Mem_Arena *a, String *s);

/* NOTE(Elias): destroys the string */
internal void str_die(String *string);

/* NOTE(Elias): returns a string literal from a string */
internal char *str_getchars(String *string);

/* NOTE(Elias): returns the length of a string */
internal S32 str_getlen(String *string);

/* NOTE(Elias): compare 2 strings */
internal S32 str_cmp(String *s1, String *s2);

/* NOTE(Elias): slice a string from i1 until i2 */
internal void str_slice(String *s_orig, S32 i1, S32 i2, Mem_Arena *a, String *s_dest);

/* NOTE(Elias): combine strings, append, prepend ... */
internal void str_append(String *s1, String *s2, Mem_Arena *a, String *s_dest);
#define str_prepend(s1, s2, a, s_dest) str_append(s2, s1, a, s_dest);

