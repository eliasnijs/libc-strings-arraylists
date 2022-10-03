
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

internal S32
t_arena_alignment()
{
  U8        *backbuffer;
  Mem_Arena a;

  S32 *i1, *i2, *i3;
 
  backbuffer = (U8 *)malloc(128);
  m_arena_init(&a, backbuffer, 128);
 
  Tu_Assert( a.offset_curr == 0 );
  Tu_Assert( a.offset_prev == 0 );

  i1 = (S32 *)m_arena_alloc(&a, sizeof(S32));
  Tu_Assert( a.offset_curr == 4 );
  Tu_Assert( a.offset_prev == 0 );

  i2 = (S32 *)m_arena_alloc(&a, sizeof(S32));
  Tu_Assert( a.offset_curr == 20 );
  Tu_Assert( a.offset_prev == 16 );
  
  i3 = (S32 *)m_arena_alloc(&a, sizeof(S32));
  Tu_Assert( a.offset_curr == 36 );
  Tu_Assert( a.offset_prev == 32 );
  
  Tu_Assert(i1 == 0x0);
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
  EvalPrintStr(s);

  return 0;
}

global_variable Tu_Test test_arenas[] = {
  Tu_TestInit(t_arena_init),
  Tu_TestInit(t_arena_alignment),
};

global_variable Tu_Test test_strings[] = {
  Tu_TestInit(t_str_basic),
};

