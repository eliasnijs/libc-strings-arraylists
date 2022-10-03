//////////////////////////////////////////////////////////////////////////////////////

typedef struct S32LL_Node
{
  S32 a;                 /* value of the node */
  struct S32LL_Node *p;  /* pntr to the previous node */
  struct S32LL_Node *n;  /* pntr to the next node */
} S32LL_Node;

typedef struct S32LL
{
  struct S32LL_Node *s;
  struct S32LL_Node *e;
} S32LL;

/* initialise a linked list */
internal void s32ll_init(S32LL *ll);

/* destory a linked list */
internal void s32ll_die(S32LL *ll);

/* add element to a linked list */
internal void s32ll_add(S32LL *ll, S32 a);

//////////////////////////////////////////////////////////////////////////////////////

/* initialise a linked list */
internal void 
s32ll_init(S32LL *ll)
{
  ll->s = 0x0; 
  ll->e = 0x0; 
}

/* destroy a linked list */
internal void 
s32ll_die(S32LL *ll)
{
  S32LL_Node *n, *t;
  n = ll->s;
  while (n && n->n) 
  {
    n = n->n;
    free(n->p);
  }
  if (n)
    free(n);
}

/* add element to a linked list */
internal void 
s32ll_add(S32LL *ll, S32 a)
{
  /* n = (S32LL_Node *)calloc(1, sizeof(S32LL_Node)); */
  Node n;

  n = ll->s;
  while (n->n)
    n = n

}

//////////////////////////////////////////////////////////////////////////////////////
