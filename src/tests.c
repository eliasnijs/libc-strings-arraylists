/* NOTE(Elias: test initialisation of arenas */
internal S32 
t_arena_init()
{
  U8        *backing_buffer; 
  U16       backing_buffer_length;
  Mem_Arena a;

  backing_buffer_length = 2 << 7;
  backing_buffer = (U8 *)malloc(backing_buffer_length);
  m_arena_init(&a, backing_buffer, backing_buffer_length);
 
  free(backing_buffer);

  return 0;
}

/* NOTE(Elias): checks arena alignment */
internal S32
t_arena_alignment()
{
  U8          *backbuffer;
  Mem_Arena   a;

  S32 *i1, *i2, *i3;
 
  backbuffer = (U8 *)malloc(128);
  m_arena_init(&a, backbuffer, 128);

  Tu_Assert(MEM_DEFAULT_ALIGNMENT > sizeof(S32) );
 
  Tu_Assert(a.offset_curr == 0);
  Tu_Assert(a.offset_prev == 0);

  i1 = (S32 *)m_arena_alloc(&a, sizeof(S32));
  Tu_Assert( a.offset_curr == MEM_DEFAULT_ALIGNMENT*0 + sizeof(S32));
  Tu_Assert( a.offset_prev == MEM_DEFAULT_ALIGNMENT*0);

  i2 = (S32 *)m_arena_alloc(&a, sizeof(S32));
  Tu_Assert( a.offset_curr == MEM_DEFAULT_ALIGNMENT*1 + sizeof(S32));
  Tu_Assert( a.offset_prev == MEM_DEFAULT_ALIGNMENT*1 );
  
  i3 = (S32 *)m_arena_alloc(&a, sizeof(S32));
  Tu_Assert( a.offset_curr == MEM_DEFAULT_ALIGNMENT*2 + sizeof(S32));
  Tu_Assert( a.offset_prev == MEM_DEFAULT_ALIGNMENT*2);
  
  Tu_Assert(i1 != 0x0);
  Tu_Assert(i2 != 0x0);
  Tu_Assert(i3 != 0x0);

  free(backbuffer);

  return 0;
}

/* NOTE(Elias: test initialisation of strings */
internal S32 
t_str_basic()
{
  U8         backbuffer[128];
  Mem_Arena  a;
  String     s;

  m_arena_init(&a, backbuffer, ArrayCount(backbuffer));
  
  str_lit("Hello World!", &a, &s);
  
  return 0;
}


internal S32
t_arraylist_init()
{
  ArrayList a;
  al_init(sizeof(S32), &a);
 
  Tu_Assert(a.l == 0);
  
  al_die(&a);
  return 0;
}

internal S32
t_arraylist_add()
{
  ArrayList a;
  al_init(sizeof(S32), &a);
 
  Tu_Assert(a.l == 0);

  S32 e1 = 0;
  al_add(&a, &e1);
  al_add(&a, &e1);
  al_add(&a, &e1);
  al_add(&a, &e1);

  Tu_Assert(a.l == 4);
  
  al_die(&a);
  return 0;
}

internal S32
t_arraylist_overview()
{
  ArrayList a;
  al_init(sizeof(S32), &a);
 
  Tu_Assert(a.l == 0);

  S32 e1 = 7, e2 = 8;
  al_add(&a, &e1);
  al_add(&a, &e2);

  Tu_Assert(a.l == 2);
  Tu_Assert( *(S32 *)al_get(&a, 0) == 7 );
  Tu_Assert( *(S32 *)al_get(&a, 1) == 8 );

  al_remove(&a, 0);

  Tu_Assert(a.l == 1);
  Tu_Assert( *(S32 *)al_get(&a, 0) == 8 );


  al_die(&a);
  return 0;
}

global_variable Tu_Test test_arenas[] = {
  Tu_TestInit(t_arena_init),
  Tu_TestInit(t_arena_alignment),
};

global_variable Tu_Test test_strings[] = {
  Tu_TestInit(t_str_basic),
};

global_variable Tu_Test test_arraylists[] = {
  Tu_TestInit(t_arraylist_init),
  Tu_TestInit(t_arraylist_add),
  Tu_TestInit(t_arraylist_overview),
};

