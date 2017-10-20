#include <stdio.h>
#include <string.h>
#include <emmintrin.h>

#define STACK_N 1000
#define SSE_N 4000000 // N % 4 == 0

void loop_sum(void) {

    int a[STACK_N];
    memset(a, -1, STACK_N * sizeof (int));
    long int sum = 0;
    for (int i = 0; i < STACK_N; i++) {
        sum += a[i];
    }
    printf("Loop sum: %i\n", sum);

}

void sse_arr_sum(void) {

    int a[4] = {1, 2, 3, 4};
    __m128i* sse_a = (__m128i*) a;

    int b[4] = {1, 2, 3, 4};
    __m128i* sse_b = (__m128i*) b;

    __m128i sum = _mm_add_epi32(*sse_a, *sse_b);

    int* res = (int*) &sum;
    for (int i = 0; i < 4; i++) {
        printf("a[%i] + b[%i] = %i\n", i, i, res[i]);
    }
}

void sse_fold_big_arr(void) {
//    int a[SSE_N];
//    memset(a, -1, SSE_N * sizeof (int));
//    __m128i* sse_a = (__m128i*) a;
//
//    const __m128i vk0 = _mm_set1_epi8(0); // constant vector of all 0s for use with _mm_unpacklo_epi8/_mm_unpackhi_epi8
//    const __m128i vk1 = _mm_set1_epi16(1); // constant vector of all 1s for use with _mm_madd_epi16
//    __m128i vsum = _mm_set1_epi32(0); // initialise vector of four partial 32 bit sums
//    uint32_t sum;
//    int i;
//
//    for (i = 0; i < n; i += 16) {
//        __m128i v = _mm_load_si128((__m128i *) & a[i]); // load vector of 8 bit values
//        __m128i vl = _mm_unpacklo_epi8(v, vk0); // unpack to two vectors of 16 bit values
//        __m128i vh = _mm_unpackhi_epi8(v, vk0);
//        vsum = _mm_add_epi32(vsum, _mm_madd_epi16(vl, vk1));
//        vsum = _mm_add_epi32(vsum, _mm_madd_epi16(vh, vk1));
//        // unpack and accumulate 16 bit values to
//        // 32 bit partial sum vector
//
//    }
//    // horizontal add of four 32 bit partial sums and return result
//    vsum = _mm_add_epi32(vsum, _mm_srli_si128(vsum, 8));
//    vsum = _mm_add_epi32(vsum, _mm_srli_si128(vsum, 4));
//    sum = _mm_cvtsi128_si32(vsum);
//    return (char) sum;
//
//
//
//    int a[4] = {1, 2, 3, 4};
//    __m128i* sse_a = (__m128i*) a;
//
//    int b[4] = {1, 2, 3, 4};
//    __m128i* sse_b = (__m128i*) b;
//
//    __m128i sum = _mm_add_epi32(*sse_a, *sse_b);
//
//    int* res = (int*) &sum;
//    for (int i = 0; i < 4; i++)
//        printf("%i\n", res[i]);
//
//
//    /*	
//            for(int i = 0; i < N; i++)
//            {
//                    sum +=a[i];
//            }
// 
//            printf("Suma: %i\n", sum);*/
    
}

int main(void) {
    loop_sum();
    sse_arr_sum();



    return 0;
}
