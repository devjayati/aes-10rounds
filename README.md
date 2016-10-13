Cryptographic Implementations in Modern Processors

AES Implementation Using C Intrinsics

Submitted By: Ishu Jaiswal, Jayati Dev
Project supervisor: Dr. Debrup Chakraborty
Duration: 16th May, 2016 – 15th July, 2016

This report describes the efficient implementation of cryptographic algorithms for Message Authentication Code (MAC) generation using polynomial multiplication over the Galois Field, GF (2x ). It also describes the extensive use of Advance Encryption Standard (AES) instructions introduced by Intel for implementation of such algorithms on modern Intel Core processor family based on the 32 nm Intel micro architecture codename ‘Westmere’. This report is divided into seven parts: (I) Introduction to Groups and Fields (II) Introduction to modern processors and Intel intrinsic instruction set (III) Implementation of Karatsuba algorithm (IV) Implementation of Reduction algorithm (V) Implementation of Horners’ rule for generation of hash function (VI) Implementation of AES Encryption and Decryption functions, ten rounds each and, (VII) MAC generation using (III), (IV), (V) and (VI). It also describes future premises of work involving these cryptographic algorithms. 

Future Scope of work- We have optimized some basic algorithms required for crytography and they can be used to implement most of the modes of operation of the AES block cipher. Also, CEASAR is a competition for Authenticated Encryption  (AE) schemes. We have attempted to implement eLMD, which is a second round candidate for CAESAR. 

Keywords- Cryptography, Karatsuba algorithm, Galois field, Intel SIMD, PCLMULQDQ, Horner’s rule, AES, Message Authentication Codes 

References- 
[1] http://www.sciencedirect.com/science/article/pii/S002001901000092X
[2]https://people.maths.ox.ac.uk/flynn/genus2/sheets0405/grfnotes1011.pdf
[3] http://csrc.nist.gov/publications/fips/fips197/fips-197.pdf
[4] https://software.intel.com/sites/landingpage/IntrinsicsGuide
[5] http://www.isical.ac.in/~pdslab/2014/slides/simd-debrup.pdf
[6] https://competitions.cr.yp.to/round2/elmdv20.pdf
[7] https://eprint.iacr.org/2014/627.pdf
