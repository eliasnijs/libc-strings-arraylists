//////////////////////////////////////////////////////////////////////////////////////
//// ArrayList

internal void
al_init(S32 bpe, ArrayList *al)
{
  al->bpe = bpe;
  al->l = 0;
  al->s = 8;
  al->a = (U8 *)calloc(al->s*al->bpe, 4);
}

/* destroys an arraylist */
internal void
al_die(ArrayList *al)
{
  free(al->a);
}

/* get the element at position i */
internal void *
al_get(ArrayList *al, S32 i)
{
  Assert(0 <= i && i < al->l);
  return &al->a[al->bpe*i];
}

/* get the length */
internal S32
al_getlen(ArrayList *al)
{
  return al->l;
}

/* set the element at position i */
internal void
al_set(ArrayList *al, void *a_i, S32 i)
{
  Assert(a_i != 0);
  Assert(0 <= i && i < al->l);

  memcpy(&al->a[i*al->bpe], a_i, al->bpe);
}

/* add element at the end */
internal void
al_add(ArrayList *al, void *a_n)
{
  Assert(a_n != 0);

  if (al->l >= al->s)
  {
    al->s = 2*al->s;
    al->a = (U8 *)realloc(al->a, al->bpe*al->s);
  }
  memcpy(&al->a[al->l*al->bpe], a_n, al->bpe);
  ++al->l;
}

/* add element at position i */
internal void
al_insert(ArrayList *al, void *a_i, S32 i)
{
  Assert(a_i != 0);
  Assert(0 <= i && i <= al->l);

  if (al->l >= al->s)
  {
    al->s = 2*al->s;
    al->a = (U8 *)realloc(al->a, al->bpe*al->s);
  }
  memmove(&al->a[(i+1)*al->bpe], &al->a[i*al->bpe], (al->l - i)*al->bpe);
  memcpy(&al->a[i*al->bpe], a_i, al->bpe);
  ++al->l;
}

/* remove element at position i */
internal void
al_remove(ArrayList *al, S32 i)
{
  Assert(i < al->l);
  memmove(&al->a[i*al->bpe], &al->a[(i+1)*al->bpe], (al->l - i - 1)*al->bpe);
  --al->l;
  if (al->l <= (al->s/2 - REMOVE_SHIFT) && al->s > 8)
  {
    al->s = al->s/2;
    al->a = (U8 *)realloc(al->a, al->bpe*al->s);
  }
}

