

#define TIME_START  struct timeval start;\
        gettimeofday( &start, NULL );


#define TIME_END  struct timeval  end;\
 gettimeofday( &end, NULL );

#define TIME_IVAL (1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec)


//extern inline void inline_func(int* a, int* b) {
//    int c = b;
//    b = a;
//    a = c;
//}
