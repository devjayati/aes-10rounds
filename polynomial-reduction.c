#ifndef REDUCTION
 #define REDUCTION
__m128i reduction(__m128i p0, __m128i p1){
    __m128i gstar = _mm_set_epi32(0,0,0,135); //G*
    __m128i temp2 = _mm_clmulepi64_si128( p1, gstar, 0x01 );
    __m128i  nn = _mm_srli_si128 (temp2, 8);
    __m128i temp5 = _mm_xor_si128(nn,p1);
    __m128i temp6 =_mm_clmulepi64_si128( temp5, gstar, 0x00 );
    __m128i temp7 = _mm_clmulepi64_si128( temp5, gstar, 0x01 );
    __m128i temp8 = _mm_clmulepi64_si128( temp5, gstar, 0x10 );
    nn = _mm_slli_si128 (temp7, 8);
    __m128i dd = _mm_xor_si128(temp6,nn);
    dd = _mm_xor_si128(dd,p0);
    return dd;
}
#endif
