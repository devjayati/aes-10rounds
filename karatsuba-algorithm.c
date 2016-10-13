#define KARATSUBA
__m128i karatsuba(__m128i a, __m128i b)
{__m128i a0b0 = _mm_clmulepi64_si128(a, b, 0x00);
  __m128i a1b1 = _mm_clmulepi64_si128(a, b, 0x11);
  __m128i a1 = _mm_srli_si128(a, 8);
  __m128i b1 = _mm_srli_si128(b, 8);
  __m128i qa = _mm_xor_si128(a, a1);
  __m128i qb = _mm_xor_si128(b, b1);
  __m128i h = _mm_clmulepi64_si128(qa, qb, 0x00);
  __m128i k = _mm_xor_si128(a0b0, a1b1);
  __m128i c = _mm_xor_si128(k, h);
  __m128i hc = _mm_srli_si128(c, 8);
  __m128i lc = _mm_slli_si128(c, 8);
  __m128i a1b1_hc = _mm_xor_si128(a1b1, hc);
  __m128i a0b0_lc = _mm_xor_si128(a0b0, lc);
}
#endif
