#ifndef MH_ASSERT
#define MH_ASSERT

#define mh_assert_static(isTrue) void mh_assert_static(char x[1 - (!(isTrue))])

#endif /* end of include guard */
