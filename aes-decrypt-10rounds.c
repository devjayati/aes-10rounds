#ifndef AESD
 #define AESD
//---------------------AES DECRYPT 10 rounds--------------//
  __m128i aesdecrypt(__m128i* key, __m128i mux)
{
        mux = _mm_xor_si128       (mux, *(key+10+0)); 
        mux = _mm_aesdec_si128    (mux, *(key+10+1)); 
        mux = _mm_aesdec_si128    (mux, *(key+10+2)); 
        mux = _mm_aesdec_si128    (mux, *(key+10+3)); 
        mux = _mm_aesdec_si128    (mux, *(key+10+4)); 
        mux = _mm_aesdec_si128    (mux, *(key+10+5));
        mux = _mm_aesdec_si128    (mux, *(key+10+6)); 
        mux = _mm_aesdec_si128    (mux, *(key+10+7)); 
        mux = _mm_aesdec_si128    (mux, *(key+10+8)); 
        mux = _mm_aesdec_si128    (mux, *(key+10+9)); 
        mux = _mm_aesdeclast_si128(mux, *key);

    return mux;
 }
 #endif
