//////////////////////////////////////////////////////////////////////////////////////
//// ArrayList

/* TODO(Elias): Account for memory alignment! */

/* Perhaps we might want to have a certain function like an inverse tan with  
 * controllable parameters for the increase instead of a exponantial increase. */

/* Compare the performance to a linked list for different operations. */

/* Do some experimentation with comparing this to linked list with a predefined type
 * in the code. */

#define REMOVE_SHIFT 2

typedef struct ArrayList {
  S32 bpe;  /* bytes per element */
  S32 l;    /* amount of elements */
  U8 *a;    /* place of the elements */
  S32 s;    /* current amount of reserved space */
} ArrayList;

/* initializes a new arraylist */
internal void al_init(S32 bpe, ArrayList *al);

/* destroys an arraylist */
internal void al_die(ArrayList *al);

/* get the address of the element at position i */
internal void * al_get(ArrayList *al, S32 i);

/* get the length */
internal S32 al_getlen(ArrayList *al);

/* set the element at position i */
internal void al_set(ArrayList *al, void *a_i, S32 i);

/* add element at the end (by copy) */
internal void al_add(ArrayList *al,  void *a_n);

/* add element at position i (by copy) */
internal void al_insert(ArrayList *al,  void *a_i,  S32 i);

/* remove element at position i */
internal void al_remove_(ArrayList *al,  void *a_i);
