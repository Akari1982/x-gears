////////////////////////////////
// func1cd00
8001CD08	lw     s0, $0420(gp)
8001CD10	addu   s2, a0, zero
8001CD18	addu   s1, zero, zero
8001CD20	beq    s0, zero, L1cdd8 [$8001cdd8]

8001CD28	lui    s3, $1fff
8001CD2C	ori    s3, s3, $ffff

loop1cd30:	; 8001CD30
8001CD30	lw     v0, $0000(s0)
8001CD34	nop
8001CD38	bne    v0, s2, L1cdc4 [$8001cdc4]
8001CD3C	lui    v0, $4000
8001CD40	lw     v1, $0014(s0)
8001CD44	nop
8001CD48	and    v0, v1, v0
8001CD4C	bne    v0, zero, L1cdc4 [$8001cdc4]
8001CD50	and    v1, v1, s3
8001CD54	lw     v0, $0010(s2)
8001CD58	nop
8001CD5C	and    v0, v0, s3
8001CD60	bne    v1, v0, L1cdc4 [$8001cdc4]
8001CD64	nop
8001CD68	beq    s1, zero, L1cd7c [$8001cd7c]
8001CD6C	nop
8001CD70	lw     v0, $0018(s0)
8001CD74	j      L1cd88 [$8001cd88]
8001CD78	sw     v0, $0018(s1)

L1cd7c:	; 8001CD7C
8001CD7C	lw     v0, $0018(s0)
8001CD80	nop
8001CD84	sw     v0, $0420(gp)

L1cd88:	; 8001CD88
8001CD88	lw     v0, $041c(gp)
8001CD8C	nop
8001CD90	bne    v0, s0, L1cda4 [$8001cda4]
8001CD94	nop
8001CD98	lw     v0, $0018(s0)
8001CD9C	nop
8001CDA0	sw     v0, $041c(gp)

L1cda4:	; 8001CDA4
8001CDA4	lw     v0, $000c(s0)
8001CDA8	nop
8001CDAC	beq    v0, zero, L1cdc8 [$8001cdc8]
8001CDB0	nop
8001CDB4	jalr   v0 ra
8001CDB8	addu   a0, s0, zero
8001CDBC	j      L1cdc8 [$8001cdc8]
8001CDC0	nop

L1cdc4:	; 8001CDC4
8001CDC4	addu   s1, s0, zero

L1cdc8:	; 8001CDC8
8001CDC8	lw     s0, $0018(s0)
8001CDCC	nop
8001CDD0	bne    s0, zero, loop1cd30 [$8001cd30]
8001CDD4	nop

L1cdd8:	; 8001CDD8
8001CDD8	lw     s0, $0418(gp)
8001CDDC	nop
8001CDE0	beq    s0, zero, L1ce98 [$8001ce98]
8001CDE4	addu   s1, zero, zero
8001CDE8	lui    s3, $1fff
8001CDEC	ori    s3, s3, $ffff

loop1cdf0:	; 8001CDF0
8001CDF0	lw     v0, $0000(s0)
8001CDF4	nop
8001CDF8	bne    v0, s2, L1ce84 [$8001ce84]
8001CDFC	lui    v0, $4000
8001CE00	lw     v1, $0014(s0)
8001CE04	nop
8001CE08	and    v0, v1, v0
8001CE0C	bne    v0, zero, L1ce84 [$8001ce84]
8001CE10	and    v1, v1, s3
8001CE14	lw     v0, $0010(s2)
8001CE18	nop
8001CE1C	and    v0, v0, s3
8001CE20	bne    v1, v0, L1ce84 [$8001ce84]
8001CE24	nop
8001CE28	beq    s1, zero, L1ce3c [$8001ce3c]
8001CE2C	nop
8001CE30	lw     v0, $0018(s0)
8001CE34	j      L1ce48 [$8001ce48]
8001CE38	sw     v0, $0018(s1)

L1ce3c:	; 8001CE3C
8001CE3C	lw     v0, $0018(s0)
8001CE40	nop
8001CE44	sw     v0, $0418(gp)

L1ce48:	; 8001CE48
8001CE48	lw     v0, $041c(gp)
8001CE4C	nop
8001CE50	bne    v0, s0, L1ce64 [$8001ce64]
8001CE54	nop
8001CE58	lw     v0, $0018(s0)
8001CE5C	nop
8001CE60	sw     v0, $041c(gp)

L1ce64:	; 8001CE64
8001CE64	lw     v0, $000c(s0)
8001CE68	nop
8001CE6C	beq    v0, zero, L1ce88 [$8001ce88]
8001CE70	nop
8001CE74	jalr   v0 ra
8001CE78	addu   a0, s0, zero
8001CE7C	j      L1ce88 [$8001ce88]
8001CE80	nop

L1ce84:	; 8001CE84
8001CE84	addu   s1, s0, zero

L1ce88:	; 8001CE88
8001CE88	lw     s0, $0018(s0)
8001CE8C	nop
8001CE90	bne    s0, zero, loop1cdf0 [$8001cdf0]
8001CE94	nop

L1ce98:	; 8001CE98
////////////////////////////////



////////////////////////////////
// func21b00()
struct_164 = A0;
V0 = bu[struct_164 + 8c] - 1;
[struct_164 + 8c] = b(V0);
[struct_164 + 8e + V0] = b(A1);
////////////////////////////////



////////////////////////////////
// func21a68
struct_164 = A0;
V1 = bu[struct_164 + 8c];
V0 = bu[struct_164 + 8e + V1];
[struct_164 + 8c] = b(V1 + 1);
return V0;
////////////////////////////////



////////////////////////////////
// func2332c()
struct_164 = A0;
A1 = 0;
A2 = 8;

loop23334:	; 80023334
    V0 = w[struct_164 + 20];
    V0 = w[V0 + 34];
    [V0 + A1 * 8 + 0] = b(0);
    [V0 + A1 * 8 + 1] = b(0);
    [V0 + A1 * 8 + 2] = h(0);
    [V0 + A1 * 8 + 4] = h(0);
    [V0 + A1 * 8 + 6] = h(0);
    A1 = A1 + 1;
800233A8	bne    a1, a2, loop23334 [$80023334]
////////////////////////////////



////////////////////////////////
// func21e60()
struct_164 = A0;

V1 = w[struct_164 + 20];
if( V1 != 0 )
{
    [V1 + 6] = h(A1);
    [V1 + 8] = h(A1);
    [V1 + a] = h(A1);

    [struct_164 + 2c] = h(A1);
    [struct_164 + 3c] = w(w[struct_164 + 3c] | 10000000);
}
////////////////////////////////



////////////////////////////////
// func21b58
[A0 + 8c] = b(b[A0 + 8c] - 3);

V0 = b[A0 + 8c];
[A0 + V0 + 8e] = b(A1 >> 0);
[A0 + V0 + 8f] = b(A1 >> 8);
[A0 + V0 + 90] = b(A1 >> 10);
////////////////////////////////



////////////////////////////////
// func21e40()
struct_164 = A0;
rotation = A1;

[struct_164 + 32] = h(rotation);

func22800();
////////////////////////////////



////////////////////////////////
// func22800
struct_164 = A0;

S0 = ((w[struct_164 + 18] >> 4) << 8) / ((w[struct_164 + ac] >> 9) & fff);

A0 = h[struct_164 + 32];
system_cos();
[struct_164 + c] = w((S0 * (V0 >> 2)) >> 6);

A0 = h[struct_164 + 32];
system_sin();
[struct_164 + 14] = w((0 - (S0 * (V0 >> 2))) >> 6);
////////////////////////////////
