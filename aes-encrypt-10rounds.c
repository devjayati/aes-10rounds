#ifndef AES
 #define AES
  __m128i aesencrypt(__m128i* key,__m128i mux)
{

	mux=_mm_xor_si128(mux,*key);
	mux=_mm_aesenc_si128(mux,*(key+1));
	mux=_mm_aesenc_si128(mux,*(key+2));
	mux=_mm_aesenc_si128(mux,*(key+3));
	mux=_mm_aesenc_si128(mux,*(key+4));
	mux=_mm_aesenc_si128(mux,*(key+5));
	mux=_mm_aesenc_si128(mux,*(key+6));
	mux=_mm_aesenc_si128(mux,*(key+7));
	mux=_mm_aesenc_si128(mux,*(key+8));
	mux=_mm_aesenc_si128(mux,*(key+9));
	mux=_mm_aesenclast_si128(mux,*(key+10));
	return mux;
 }
 #endif
