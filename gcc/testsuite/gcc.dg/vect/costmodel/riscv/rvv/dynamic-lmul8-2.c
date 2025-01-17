/* { dg-do compile } */
/* { dg-options "-march=rv32gcv -mabi=ilp32 --param riscv-autovec-preference=scalable -fdump-tree-vect-details" } */

#include <stdint-gcc.h>

void
foo (int32_t *__restrict a, int16_t *__restrict b, int n)
{
  for (int i = 0; i < n; i++)
    a[i] = a[i] + b[i];
}

/* { dg-final { scan-assembler {e16,m4} } } */
/* { dg-final { scan-assembler-not {csrr} } } */
/* { dg-final { scan-tree-dump-times "Maximum lmul = 8" 1 "vect" } } */
/* { dg-final { scan-tree-dump-not "Maximum lmul = 4" "vect" } } */
/* { dg-final { scan-tree-dump-not "Maximum lmul = 2" "vect" } } */
/* { dg-final { scan-tree-dump-not "Maximum lmul = 1" "vect" } } */
