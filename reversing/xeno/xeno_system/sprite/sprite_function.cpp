////////////////////////////////
// func1f524()
8001F524	addu   t0, a0, zero
8001F528	lw     a0, $003c(t0)
8001F530	andi   v1, a0, $0003
if( V1 == 1 )
{
    8001F53C	srl    a3, a0, $05
    8001F540	andi   a3, a3, $0007
    if( A3 != 0 )
    {
        A3 = A3 - 1;
    }

    8001F550	lw     v0, $0024(t0)
    8001F558	lwl    v1, $0007(v0)
    8001F55C	lwr    v1, $0004(v0)
    8001F564	swl    v1, $0003(sp)
    8001F568	swr    v1, $0000(sp)
    8001F56C	lw     v0, $0040(t0)
    8001F570	lw     v1, $0020(t0)
    8001F574	lw     t1, $0028(t0)
    8001F578	srl    v0, v0, $02
    8001F57C	andi   v0, v0, $003f
    8001F580	lw     v1, $0030(v1)
    if( V0 != 0 )
    {
        8001F588	addu   a1, zero, zero
        8001F58C	sll    a2, a3, $05
        8001F590	addu   a0, v1, zero

        loop1f594:	; 8001F594
            8001F594	lhu    v0, $000a(a0)
            8001F598	addiu  a1, a1, $0001
            8001F59C	sw     t1, $0010(a0)
            8001F5A0	andi   v0, v0, $ff9f
            8001F5A4	or     v0, v0, a2
            8001F5A8	sh     v0, $000a(a0)
            8001F5AC	lw     v0, $0040(t0)
            8001F5C0	addiu  a0, a0, $0018
            8001F5B4	srl    v0, v0, $02
            8001F5B8	andi   v0, v0, $003f
        8001F5BC	bne    a1, v0, loop1f594 [$8001f594]
    }
}
////////////////////////////////



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
// func1cd00()
struct_164 = A0;

S0 = w[GP + 420];
if( S0 != 0 )
{
    S1 = 0;
    loop1cd30:	; 8001CD30
        if( ( w[S0 + 0] == struct_164 ) && ( ( w[S0 + 14] & 40000000 ) == 0 ) && ( ( w[S0 + 14] & 1fffffff ) == ( w[struct_164 + 10] & 1fffffff ) ) )
        {
            if( S1 != 0 )
            {
                [S1 + 18] = w(w[S0 + 18]);
            }
            else
            {
                [GP + 420] = w(w[S0 + 18]);
            }

            if( w[GP + 41c] == S0 )
            {
                [GP + 41c] = w(w[S0 + 18]);
            }

            if( w[S0 + c] != 0 )
            {
                A0 = S0;
                8001CDB4	jalr   w[S0 + c] ra
            }
        }
        else
        {
            S1 = S0;
        }
        S0 = w[S0 + 18];
    8001CDD0	bne    s0, zero, loop1cd30 [$8001cd30]
}

S0 = w[GP + 418];
if( S0 != 0 )
{
    S1 = 0;
    loop1cdf0:	; 8001CDF0
        if( ( w[S0] == struct_164 ) && ( ( w[S0 + 14] & 40000000 ) == 0 ) && ( ( w[S0 + 14] & 1fffffff ) == ( w[struct_164 + 10] & 1fffffff ) ) )
        {
            if( S1 != 0 )
            {
                [S1 + 18] = w(w[S0 + 18]);
            }
            else
            {
                [GP + 418] = w(w[S0 + 18]);
            }

            if( w[GP + 41c] == S0 )
            {
                [GP + 41c] = w(w[S0 + 18]);
            }

            if( w[S0 + c] != 0 )
            {
                A0 = S0;
                8001CE74	jalr   w[S0 + c] ra
            }
        }
        else
        {
            S1 = S0;
        }
        S0 = w[S0 + 18];
    8001CE90	bne    s0, zero, loop1cdf0 [$8001cdf0]
}
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
// func22800()
struct_164 = A0;

S0 = ((w[struct_164 + 18] >> 4) << 8) / ((w[struct_164 + ac] >> 9) & fff);

A0 = h[struct_164 + 32];
system_cos();
[struct_164 + c] = w((S0 * (V0 >> 2)) >> 6);

A0 = h[struct_164 + 32];
system_sin();
[struct_164 + 14] = w((0 - (S0 * (V0 >> 2))) >> 6);
////////////////////////////////
