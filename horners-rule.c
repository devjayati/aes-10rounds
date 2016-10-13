#ifndef FILEHORNERS
  #define FILEHORNERS     
__m128i filehorners(__m128i k1, __m128i* mtemp, int m)
{
    int i=0,c=0;
    __m128i mux1,mux2,mux;
    __m128i res1=_mm_set_epi32 (0 , 0, 0, 0);
    __m128i res2=_mm_set_epi32 (0 , 0, 0, 0);
    __m128i ksq=reduction(k1,k1);
    mux1=mtemp[m-1];
    mux2=mtemp[m-2];
    if(m%2!=0) 
    {    
        for(i=m-1;i>0;i-=2)
        {
            res1=reduction(mux1,ksq);
            mux1=_mm_xor_si128(res1,mtemp[i-2]);
        }
        res1=_mm_set_epi32 (0 , 0, 0, 0);
        for(i=m-2;i>0;i-=2)
        {
            if(i!=1)
            {
                res1=reduction(mux2,ksq);
                mux2=_mm_xor_si128(res1,mtemp[i-2]);
            }
            else
                res1=reduction(mux2,k1);

        }
        mux=_mm_xor_si128(mux1,res1);
        //printBytesM(&mux);    
    }
    else
    {
        for(i=m-1;i>0;i-=2)
        {
            if(i!=1)
            {
                res1=reduction(mux1,ksq);
                mux1=_mm_xor_si128(res1,mtemp[i-2]);
            }
            else
                res1=reduction(mux1,k1);
        }
        for(i=m-2;i>0;i-=2)
        {
            res2=reduction(mux2,ksq);
            mux2=_mm_xor_si128(res2,mtemp[i-2]);
        }
        mux=_mm_xor_si128(res1,mux2);
    }
return mux;
}
#endif
