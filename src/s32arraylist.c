//////////////////////////////////////////////////////////////////////////////////////

// Perhaps we might want to have a certain function like a inverse tan with 
// controllable parameters control the increase instead of a exponantial increase.

// Also compare the performance to a linked list for different operations.

#define S32ALMEMMARG 2

struct S32AL
{
  S32 l;
  S32 s;
  S32 *a;
};

/* initializes a new s32 arraylist */
internal struct S32AL s32al();

/* destroys an s32 arraylist */
internal void s32al_die(struct S32AL *al);

/* get the element at position i */
internal S32 s32al_get(struct S32AL *al, S32 i);

/* get the length */
internal S32 s32al_getlen(struct S32AL *al);

/* set the length */
internal void s32al_set(struct S32AL *al, S32 a_i, S32 i);

/* add element at the end */
internal void s32al_add(struct S32AL *al, S32 a_n);

/* add element at position i */
internal void s32al_insert(struct S32AL *al, S32 a_i, S32 i);

/* remove element at position i */
internal void s32al_remove(struct S32AL *al, S32 a_i);

/* print the list */
internal void s32al_print(FILE *stream, struct S32AL *al);

//////////////////////////////////////////////////////////////////////////////////////

internal struct S32AL 
s32al()
{
  struct S32AL al;
  al.l = 0;
  al.s = 8;
  al.a = (S32 *)calloc(al.s, sizeof(S32));
  return al;
}

/* destroys an s32 arraylist */
internal void 
s32al_die(struct S32AL *al)
{
  free(al->a);
}

/* get the element at position i */
internal S32 
s32al_get(struct S32AL *al, S32 i)
{
  return al->a[i];
}

/* set the element at position i */
internal void 
s32al_set(struct S32AL *al, S32 a_i, S32 i)
{
  al->a[i] = a_i;
}

internal S32 
s32al_getlen(struct S32AL *al)
{
  return al->l;
}

internal void 
s32al_add(struct S32AL *al, S32 a_n)
{
  if (al->l >= al->s)
  {
    al->s = 2*al->s;
    al->a = (S32 *)realloc(al->a, al->s*sizeof(S32));
  }
  al->a[al->l] = a_n;
  ++al->l;
}

internal void 
s32al_insert(struct S32AL *al, S32 a_i, S32 i)
{
  if (al->l >= al->s)
  {
    al->s = 2*al->s;
    al->a = (S32 *)realloc(al->a, al->s*sizeof(S32));
  }
  memmove(&al->a[i+1], &al->a[i], (al->l - i)*sizeof(S32));
  al->a[i] = a_i;
  ++al->l;
}

internal void 
s32al_remove(struct S32AL *al, S32 i)
{
  memmove(&al->a[i], &al->a[i+1], (al->l - i - 1)*sizeof(S32));
  --al->l;
  if (al->l <= (al->s/2 - S32ALMEMMARG) && al->s > 8)
  {
    al->s = al->s/2;
    al->a = (S32 *)realloc(al->a, al->s*sizeof(S32));
  }
}

/* print the list */
internal void 
s32al_print(FILE *stream, struct S32AL *al)
{
  S32  i;
  fprintf(stream, "[ ");
  for (i = 0; i < (al->l - 1); ++i)
    fprintf(stream, "%d, ", al->a[i]);
  fprintf(stream, "%d ", al->a[al->l - 1]);
  fprintf(stream, "]");
}

//////////////////////////////////////////////////////////////////////////////////////
