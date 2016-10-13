__m128i mac_gen(__m128i k1, __m128i k)
{
//k=key for AES and k1=key for Horner’s Rule
 	 __m128i h=filehorners(k1);
     __m128i *ke = keyschedule(k);
	__m128i mac=aesencrypt(ke,h);
	return mac;
}
