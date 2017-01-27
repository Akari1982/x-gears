////////////////////////////////
// func1c884()
V0 = w[GP + 420];
[GP + 41c] = w(V0);
if( V0 != 0 )
{
    loop1c89c:	; 8001C89C
        A0 = w[GP + 41c];
        [GP + 34c] = w(A0);
        [GP + 41c] = w(w[A0 + 18]);
        if( w[A0 + 8] != 0 )
        {
            8001C8BC	jalr   w[A0 + 8] ra
        }
        V0 = w[GP + 41c];
    8001C8CC	bne    v0, zero, loop1c89c [$8001c89c]
}
////////////////////////////////



////////////////////////////////
// func1c7f0()
if( w[80058ac4] != 0 )
{
    [80058ac4] = w(w[80058ac4] - 1);
    if( w[80058ac4] == 0 )
    {
        [80058b30] = h(0);
    }
}
else
{
    V0 = w[GP + 418];
    [GP + 41c] = w(V0);
    if( V0 != 0 )
    {
        loop1c83c:	; 8001C83C
            A0 = w[GP + 41c];
            [GP + 34c] = w(A0);
            [GP + 41c] = w(w[A0 + 18]);
            if( w[A0 + 8] != 0 )
            {
                8001C85C	jalr   w[A0 + 8] ra
            }
            V0 = w[GP + 41c];
        8001C86C	bne    v0, zero, loop1c83c [$8001c83c]
    }
}
////////////////////////////////



////////////////////////////////
// func228fc()
tex_pack = A0;
S5 = A1;
S0 = w[tex_pack + 0];

if( S0 > 0 )
{
    S2 = 0;
    S0 = S0 - 1;
    loop22948:	; 80022948
        V0 = w[tex_pack + 4 + S2 * 4];
        [SP + 10] = h(S5 + S2 * 40); // x
        [SP + 12] = h(A2); // y
        [SP + 14] = h(hu[tex_pack + V0 + 0]); // width
        [SP + 16] = h(hu[tex_pack + V0 + 2]); // height

        [GP + 180] = w(SP + 10); // rect
        [GP + 184] = w(tex_pack + V0 + 4); // data ptr

        func22898();

        S2 = S2 + 1;
        S0 = S0 - 1;
    80022988	bgtz   S0, loop22948 [$80022948]
}
////////////////////////////////



////////////////////////////////
// func22898()
A0 = 2000;
A1 = 1;
system_memory_allocate();
S0 = V0;

T0 = S0 + 1f00;
[T0] = w(SP);
SP = T0 - 4;

A0 = w[GP + 180];
A1 = w[GP + 184];
system_load_image();

SP = w[T0];

A0 = S0;
system_memory_free();
////////////////////////////////



////////////////////////////////
// func231cc()
struct_164 = A0;
struct_b4 = w[struct_164 + 20];
S0 = A1;

A0 = w[struct_b4 + 2c];
system_memory_free();

A0 = S0 * 18;
A1 = 0;
system_memory_allocate();
[struct_b4 + 2c] = w(V0);
[struct_b4 + 30] = w(V0);
////////////////////////////////



////////////////////////////////
// func1f434()
struct_164 = A0;
struct_110 = w[struct_164 + 24];
sprite_data_0 = w[struct_110 + 10];
anim_data = sprite_data_0 + hu[sprite_data_0 + 2]; // pointer to first animation
direction_data = anim_data + hu[anim_data + 4];
sprite_dir = bu[direction_data + 4];
if( sprite_dir != 0 )
{
    sprite_dir = sprite_dir - 1;
}
sprite_data_1 = w[struct_110 + 0];
if( hu[sprite_data_1 + sprite_dir * 2] < sprite_dir )
{
    sprite_dir = 0;
}
frame_data = sprite_data_1 + hu[sprite_data_1 + sprite_dir * 2 + 2];

[A3] = w((bu[frame_data + 3] * h[struct_164 + 2c]) >> c);
[A4] = w((bu[frame_data + 1] * h[struct_164 + 2c]) >> c);
[A2] = w((bu[frame_data + 2] * h[struct_164 + 2c]) >> c);
////////////////////////////////



////////////////////////////////
// func21a48()
[A0 + 40] = w((w[A0 + 40] & ffffe0ff) | ((A1 & 1f) << 8));
////////////////////////////////



////////////////////////////////
// system_field_sprite_memory_free()
struct_164 = A0;

if( w[struct_164 + a8] & 00000001 )
{
    V0 = w[struct_164 + 7c];
    A0 = w[V0 + 18];
    if( A0 != 0 )
    {
        system_memory_free();
    }
}

A0 = struct_164;
func1d270()

V0 = w[struct_164 + 20];
A0 = w[V0 + 2c];
system_memory_free();

A0 = struct_164;
system_memory_free();
////////////////////////////////



////////////////////////////////
// func1d270()
struct_164 = A0;

sprite_list = w[GP + 20];
if( sprite_list != 0 )
{
    A2 = 0;
    loop1d280:	; 8001D280
        if( sprite_list != struct_164 )
        {
            A2 = sprite_list;
        }
        else if( A2 != 0 )
        {
            V0 = w[sprite_list + 20];
            V1 = w[A2 + 20];
            [V1 + 38] = w(w[V0 + 38]);
        }
        else
        {
            V0 = w[sprite_list + 20];
            V0 = w[V0 + 38];
            [GP + 20] = w(V0);
        }
        V0 = w[sprite_list + 20];
        sprite_list = w[V0 + 38];
    8001D2D4	bne    sprite_list, zero, loop1d280 [$8001d280]
}
////////////////////////////////



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
// func21a68()
struct_164 = A0;
V1 = bu[struct_164 + 8c];
V0 = bu[struct_164 + V1 + 8e];
[struct_164 + 8c] = b(V1 + 1);
return V0;
////////////////////////////////



////////////////////////////////
// func2332c()
struct_164 = A0;

A1 = 0;
loop23334:	; 80023334
    V0 = w[struct_164 + 20];
    V0 = w[V0 + 34];
    [V0 + A1 * 8 + 0] = b(0);
    [V0 + A1 * 8 + 1] = b(0);
    [V0 + A1 * 8 + 2] = h(0);
    [V0 + A1 * 8 + 4] = h(0);
    [V0 + A1 * 8 + 6] = h(0);
    A1 = A1 + 1;
800233A8	bne    a1, 8, loop23334 [$80023334]
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
// func21ac4()
struct_164 = A0;

A1 = b[struct_164 + 8c];
[A0 + 8c] = b(A1 + 3);
return (bu[struct_164 + A1 + 90] << 10) + (bu[struct_164 + A1 + 8f] << 8) +  bu[struct_164 + A1 + 8e];
////////////////////////////////





////////////////////////////////
// func1fa1c()
struct_164 = A0;

if( b[A1] & 80 )
{
    return w[struct_164 + 88] + b[A1] & 7f;
}
else
{
    return struct_164 + b[struct_164 + 8c] + b[A1] + 8e;
}
////////////////////////////////



////////////////////////////////
// func21b58()
struct_164 = A0;

[struct_164 + 8c] = b(b[struct_164 + 8c] - 3);

V0 = b[struct_164 + 8c];
[struct_164 + V0 + 8e] = b(A1 >> 0);
[struct_164 + V0 + 8f] = b(A1 >> 8);
[struct_164 + V0 + 90] = b(A1 >> 10);
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
