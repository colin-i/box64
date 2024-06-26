#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#if defined(__x86_64__)
uint64_t _ucomiss_(float a, float b)
{
    uint64_t ret;
    asm volatile (
    "ucomiss %%xmm0, %%xmm1\n"
    "pushf\n"
    "pop %%rax"
    :"=a" (ret)::"xmm0","xmm1","cc");
    return ret;
}
uint64_t _ucomisd_(double a, double b)
{
    uint64_t ret;
    asm volatile (
    "ucomisd %%xmm0, %%xmm1\n"
    "pushf\n"
    "pop %%rax"
    :"=a" (ret)::"xmm0","xmm1","cc");
    return ret;
}
#define GO(n) \
uint64_t _cmpsd_##n##_(double a, double b) \
{ \
    uint64_t ret; \
    asm volatile ( \
    "cmpsd $" #n ", %%xmm1, %%xmm0\n" \
    "movq %%xmm0, %%rax" \
    :"=a" (ret)::"xmm0","xmm1","cc"); \
    return ret; \
}
GO(0)
GO(1)
GO(2)
GO(3)
GO(4)
GO(5)
GO(6)
GO(7)
#undef GO
#else
uint64_t _ucomiss_(float a, float b)
{
    uint32_t ret;
    asm volatile (
    "movss %1, %%xmm0\n"
    "movss %2, %%xmm1\n"
    "ucomiss %%xmm0, %%xmm1\n"
    "pushf\n"
    "pop %%eax"
    :"=a" (ret):"m"(a), "m"(b):"xmm0", "xmm1", "cc");
    return ret;
}
uint64_t _ucomisd_(double a, double b)
{
    uint32_t ret;
    asm volatile (
    "movsd %1, %%xmm0\n"
    "movsd %2, %%xmm1\n"
    "ucomisd %%xmm0, %%xmm1\n"
    "pushf\n"
    "pop %%eax"
    :"=a" (ret):"m"(a), "m"(b):"xmm0", "xmm1", "cc");
    return ret;
}
#endif

void test_ucomiss()
{
 float a, b;
 uint64_t flags;
 a = 1.0f; b = 2.0f;
 flags = _ucomiss_(a, b);
 printf("ucomiss %f, %f => 0x%lx\n", a, b, flags);
 flags = _ucomiss_(b, a);
 printf("ucomiss %f, %f => 0x%lx\n", b, a, flags);
 b = INFINITY;
 flags = _ucomiss_(a, b);
 printf("ucomiss %f, %f => 0x%lx\n", a, b, flags);
 flags = _ucomiss_(b, a);
 printf("ucomiss %f, %f => 0x%lx\n", b, a, flags);
 b = -INFINITY;
 flags = _ucomiss_(a, b);
 printf("ucomiss %f, %f => 0x%lx\n", a, b, flags);
 flags = _ucomiss_(b, a);
 printf("ucomiss %f, %f => 0x%lx\n", b, a, flags);
 b = NAN;
 flags = _ucomiss_(a, b);
 printf("ucomiss %f, %f => 0x%lx\n", a, b, flags);
 flags = _ucomiss_(b, a);
 printf("ucomiss %f, %f => 0x%lx\n", b, a, flags);
 b = a;
 flags = _ucomiss_(a, b);
 printf("ucomiss %f, %f => 0x%lx\n", a, b, flags);
 a = b = INFINITY;
 flags = _ucomiss_(a, b);
 printf("ucomiss %f, %f => 0x%lx\n", a, b, flags);
 a = b = NAN;
 flags = _ucomiss_(a, b);
 printf("ucomiss %f, %f => 0x%lx\n", a, b, flags);
}

void test_ucomisd()
{
 double a, b;
 uint64_t flags;
 a = 1.0; b = 2.0;
 flags = _ucomisd_(a, b);
 printf("ucomisd %f, %f => 0x%lx\n", a, b, flags);
 flags = _ucomisd_(b, a);
 printf("ucomisd %f, %f => 0x%lx\n", b, a, flags);
 b = INFINITY;
 flags = _ucomisd_(a, b);
 printf("ucomisd %f, %f => 0x%lx\n", a, b, flags);
 flags = _ucomisd_(b, a);
 printf("ucomisd %f, %f => 0x%lx\n", b, a, flags);
 b = -INFINITY;
 flags = _ucomisd_(a, b);
 printf("ucomisd %f, %f => 0x%lx\n", a, b, flags);
 flags = _ucomisd_(b, a);
 printf("ucomisd %f, %f => 0x%lx\n", b, a, flags);
 b = NAN;
 flags = _ucomisd_(a, b);
 printf("ucomisd %f, %f => 0x%lx\n", a, b, flags);
 flags = _ucomisd_(b, a);
 printf("ucomisd %f, %f => 0x%lx\n", b, a, flags);
 b = a;
 flags = _ucomisd_(a, b);
 printf("ucomisd %f, %f => 0x%lx\n", a, b, flags);
 a = b = INFINITY;
 flags = _ucomisd_(a, b);
 printf("ucomisd %f, %f => 0x%lx\n", a, b, flags);
 a = b = NAN;
 flags = _ucomisd_(a, b);
 printf("ucomisd %f, %f => 0x%lx\n", a, b, flags);
}
#if defined(__x86_64__)
#define GO(n) \
void test_cmpsd_##n() \
{ \
 double a, b; \
 uint64_t flags; \
 a = 1.0; b = 2.0; \
 flags = _cmpsd_##n##_(a, b); \
 printf("cmpsd %f, %f, " #n " => 0x%lx\n", a, b, flags); \
 flags = _cmpsd_##n##_(b, a); \
 printf("cmpsd %f, %f, " #n " => 0x%lx\n", b, a, flags); \
 b = INFINITY; \
 flags = _cmpsd_##n##_(a, b); \
 printf("cmpsd %f, %f, " #n " => 0x%lx\n", a, b, flags); \
 flags = _cmpsd_##n##_(b, a); \
 printf("cmpsd %f, %f, " #n " => 0x%lx\n", b, a, flags); \
 b = -INFINITY; \
 flags = _cmpsd_##n##_(a, b); \
 printf("cmpsd %f, %f, " #n " => 0x%lx\n", a, b, flags); \
 flags = _cmpsd_##n##_(b, a); \
 printf("cmpsd %f, %f, " #n " => 0x%lx\n", b, a, flags); \
 b = NAN; \
 flags = _cmpsd_##n##_(a, b); \
 printf("cmpsd %f, %f, " #n " => 0x%lx\n", a, b, flags); \
 flags = _cmpsd_##n##_(b, a); \
 printf("cmpsd %f, %f, " #n " => 0x%lx\n", b, a, flags); \
 b = a; \
 flags = _cmpsd_##n##_(a, b); \
 printf("cmpsd %f, %f, " #n " => 0x%lx\n", a, b, flags); \
 a = b = INFINITY; \
 flags = _cmpsd_##n##_(a, b); \
 printf("cmpsd %f, %f, " #n " => 0x%lx\n", a, b, flags); \
 a = b = NAN; \
 flags = _cmpsd_##n##_(a, b); \
 printf("cmpsd %f, %f, " #n " => 0x%lx\n", a, b, flags); \
}
GO(0)
GO(1)
GO(2)
GO(3)
GO(4)
GO(5)
GO(6)
GO(7)
#endif
int main(int argc, const char** argv)
{
 test_ucomiss();
 test_ucomisd();
 #if defined(__x86_64__)
 test_cmpsd_0();
 test_cmpsd_1();
 test_cmpsd_2();
 test_cmpsd_3();
 test_cmpsd_4();
 test_cmpsd_5();
 test_cmpsd_6();
 test_cmpsd_7();
 #endif

 return 0;
}
