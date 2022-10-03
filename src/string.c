//////////////////////////////////////////////////////////////////////////////////////
//// NOTE(Elias): String

/* NOTE(Elias): returns a string from a string literal and it's size */
internal void 
str_init(char *str, S32 l, Mem_Arena *a, String *s)
{
  s->l = l;
  s->str = (char *)m_arena_alloc(a, l*sizeof(char));
  strcpy(s->str, str);
}

/* NOTE(Elias): destroys the string */
internal inline void
str_die(String *string)
{
  free(string->str);
}

/* NOTE(Elias): returns a string literal from a string */
internal inline char *
str_getchars(String *string)
{
  return string->str;
}

/* NOTE(Elias): returns the length of a string */
internal inline S32 
str_getlen(String *string)
{
  return string->l;
}

/* NOTE(Elias): compare 2 strings */
internal inline S32 
str_cmp(String *s1, String *s2)
{
  return memcmp(s1->str, s2->str, s1->l);
}

/* NOTE(Elias): slice a string from i1 until i2 */
internal void 
str_slice(String *s_orig, S32 i1, S32 i2, Mem_Arena *a, String *s_dest)
{
  Assert(i1 >= 0 && i1 < (s_orig->l - 1));
  Assert(i2 > 0 && i2 <= (s_orig->l - 1));
  Assert(i1 < i2);
  s_dest->l = i2 - i1 + 1;
  s_dest->str = m_arena_alloc(a, s_dest->l);
  if (s_dest->str != 0x0)
  {
    memcpy(s_dest->str, &s_orig->str[i1], s_dest->l);
    s_dest->str[s_dest->l-1] = 0;
  }
}

/* NOTE(Elias): combine strings: append, prepend, insert, ... */
internal void 
str_append(String *s1, String *s2, Mem_Arena *a, String *s_dest)
{
  s_dest->l = s1->l + s2->l - 1;
  s_dest->str = m_arena_alloc(a, s_dest->l);
  memcpy(s_dest->str, s1->str, s1->l - 1);
  memcpy(&s_dest->str[s1->l - 1], s2->str, s2->l);
}
#define str_prepend(s1, s2, a, s_dest) str_append(s2, s1, a, s_dest);
















