#ifndef KEYSCH
 #define KEYSCH
__m128i wrap_and_s_box(__m128i temp1, __m128i temp2)//Intel Intrinsic Code
    {
    __m128i temp3;
    temp2 = _mm_shuffle_epi32 (temp2 ,0xff);
    temp3 = _mm_slli_si128 (temp1, 0x4);
    temp1 = _mm_xor_si128 (temp1, temp3);
    temp3 = _mm_slli_si128 (temp3, 0x4);
    temp1 = _mm_xor_si128 (temp1, temp3);
    temp3 = _mm_slli_si128 (temp3, 0x4);
    temp1 = _mm_xor_si128 (temp1, temp3);
    temp1 = _mm_xor_si128 (temp1, temp2);
    return temp1;
}
__m128i *keyschedule(__m128i k)
{
    __m128i keygen; 
   __m128i *key=(__m128i *)malloc(sizeof(__m128i)*20);
key[0]=k;
 keygen= _mm_aeskeygenassist_si128 (k, 0x1);
    k=wrap_and_s_box(k,keygen);
    key[1]=k;
    keygen= _mm_aeskeygenassist_si128 (k, 0x2);
    k=wrap_and_s_box(k,keygen);
    key[2]=k;
    keygen= _mm_aeskeygenassist_si128 (k, 0x4);
    k=wrap_and_s_box(k,keygen);
    key[3]=k;
    keygen= _mm_aeskeygenassist_si128 (k, 0x8);
    k=wrap_and_s_box(k,keygen);
    key[4]=k;
    keygen= _mm_aeskeygenassist_si128 (k, 0x10);
    k=wrap_and_s_box(k,keygen);
    key[5]=k;
    keygen= _mm_aeskeygenassist_si128 (k, 0x20);
    k=wrap_and_s_box(k,keygen);
    key[6]=k;
    keygen= _mm_aeskeygenassist_si128 (k, 0x40);
    k=wrap_and_s_box(k,keygen);
    key[7]=k;
    keygen= _mm_aeskeygenassist_si128 (k, 0x80);
    k=wrap_and_s_box(k,keygen);
    key[8]=k;
    keygen= _mm_aeskeygenassist_si128 (k, 0x1b);
    k=wrap_and_s_box(k,keygen);
    key[9]=k;
    keygen= _mm_aeskeygenassist_si128 (k, 0x36);
k=wrap_and_s_box(k,keygen);
//----------Key Schedule for decryption//
    key[10]=k;
	key[11] = _mm_aesimc_si128(key[9]);
    key[12] = _mm_aesimc_si128(key[8]);
    key[13] = _mm_aesimc_si128(key[7]);
    key[14] = _mm_aesimc_si128(key[6]);
    key[15] = _mm_aesimc_si128(key[5]);
    key[16] = _mm_aesimc_si128(key[4]);
    key[17] = _mm_aesimc_si128(key[3]);
    key[18] = _mm_aesimc_si128(key[2]);
    key[19] = _mm_aesimc_si128(key[1]);
    return key;
}
#endif
