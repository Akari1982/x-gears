////////////////////////////////
// func24330
// called from script during initing
S5 = A0;
S3 = A1; // clut x
S4 = A2; // clut y
S0 = A3; // tx
S1 = A4; // ty
S2 = A5;

A0 = 164;
A1 = 0;
system_memory_allocate;
[V0 + 86] = h(164);

A0 = V0;
A1 = S5; // offset 2dsprite_1 block in field data
A2 = S3; // clut x
A3 = S4; // clut y
A4 = S0; // tx
A5 = S1; // ty
A6 = S2;
func24168;
////////////////////////////////



////////////////////////////////
// func24168
struct = A0;
sprite_pack = A1;
S5 = A2; // clut x
S6 = A3; // clut y
S3 = A4; // tx
S4 = A5; // ty

A0 = struct;
func23680; // init default

A0 = struct;
func23814;

A0 = struct;
A1 = 1000;
func21e60;

[struct + 3c] = w((w[struct + 3c] & fffffffc) | 00000001);
[struct + 40] = w(w[struct + 40] & fffe1fff); // doesn't affect anything because it was inited with 0.
[struct + 48] = w(sprite_pack);

if( bu[80058810 + 3d] != 0 )
{
    [struct + a8] = w(w[struct + a8] & fffffffe);
    A0 = w[struct + 7c];
    [A0 + 8] = w(0);
    [A0 + c] = h(0);
}
else
{
    [struct + a8] = w(w[struct + a8] | 00000001);
    A0 = w[struct + 7c];
    [A0 + 18] = w(0);
}

[struct + 6c] = w(struct);

V1 = w[GP + 48] & 000f;
[struct + 3c] = w((((w[struct + 3c] & ff0fffff) | (V1 << 14)) & fff0ffff) | (V1 << 10));

sprite_part_1 = sprite_pack + w[sprite_pack + 8];
A0 = ((hu[sprite_part_1 + 0] >> 9) & 3f) * 18;
A1 = 0;
system_memory_allocate;
V1 = w[struct + 20];
[V1 + 2c] = w(V0);
[V1 + 30] = w(V0);

V0 = w[struct + 24];
[V0 + 4] = h(S3); // tx
[V0 + 6] = h(S4); // ty
[V0 + 8] = h(S5); // clut x
[V0 + a] = h(S6); // clut y

A0 = struct;
A1 = sprite_pack;
func22124;

V0 = w[struct + 24];
V1 = w[V0 + 10]; // pointer to sprite data 0.
[struct + 60] = w(V1 + 2 + (hu[V1 + 0] & 3f) * 2); // pointer to 1st animation

A0 = struct;
A1 = 0; // animation id
func243e4;

return struct;
////////////////////////////////



////////////////////////////////
// func23680
struct = A0; // struct

V0 = w[80058810 + 28] + 1;
V1 = V0 << e;
[struct + 1c] = w((V0 * V1 * h[struct + 82]) >> c);

[struct + 2b] = b(2d);
[struct + 30] = h(0000);
[struct + 32] = h(0000);
[struct + 34] = h(0000);
[struct + 3a] = h(0000);
[struct + 3c] = w(00000000);
[struct + 40] = w(00000000);
[struct + 44] = w(00000000);
[struct + 50] = w(00000000);
[struct + 64] = w(00000000);
[struct + 68] = w(00000000);
[struct + 6c] = w(00000000);
[struct + 70] = w(00000000);
[struct + 80] = h(0000);
[struct + 84] = h(0000);
[struct + 8c] = b(10);
[struct + a8] = w(00000000);
[struct + ac] = w(00020000);
[struct + b0] = w(00000000);
////////////////////////////////



////////////////////////////////
// func23814
struct = A0;

[struct + 20] = w(struct + b4);
[struct + 24] = w(struct + 110);
[struct + 7c] = w(struct + f4);

V1 = w[struct + 20];
[V1 + 0] = h(0);
[V1 + 2] = h(0);
[V1 + 4] = h(0);
[V1 + 2c] = w(0);
[V1 + 34] = w(struct + 124);
[V1 + 38] = w(0);
////////////////////////////////



////////////////////////////////
// func21e60
struct = A0;

V1 = w[struct + 20];
if( V1 != 0 )
{
    [V1 + 6] = h(A1);
    [V1 + 8] = h(A1);
    [V1 + a] = h(A1);

    [struct + 2c] = h(A1);
    [struct + 3c] = w(w[struct + 3c] | 10000000);
}
////////////////////////////////



////////////////////////////////
// func22124
struct = A0;
sprite_pack = A1;

if( sprite_pack != 0 )
{
    data110 = w[struct + 24];

    if( sprite_pack != w[struct + 44] )
    {
        A0 = data110;
        A1 = sprite_pack;
        A2 = (hu[data110 + 6] << 10) | hu[data110 + 4]; // tx ty
        A3 = (hu[data110 + a] << 10) | hu[data110 + 8]; // clut x clut y
        func22084;

        [struct + 44] = w(sprite_pack);
        [struct + 3c] = w(w[struct + 3c] | 40000000);
    }

    if( bu[80058810 + 3d] != 0 )
    {
        A0 = w[data110 + 0];
        V0 = hu[A0 + 0] >> f;

        if( V0 == 0 )
        {
            [data110 + 4] = h(0300); // tx
            [data110 + 6] = h(0100); // ty
        }
        else
        {
            V0 = w[struct + 7c];
            [data110 + 4] = w(w[V0 + e]); // tx
        }
    }
}
////////////////////////////////



////////////////////////////////
// func22084
data110 = A0;
sprite_pack = A1;

[data110 + 0] = w(sprite_pack + w[sprite_pack + 8]);
[data110 + 4] = w(A2);
[data110 + 8] = w(A3);
[data110 + c] = w(sprite_pack + w[sprite_pack + c]);
[data110 + 10] = w(sprite_pack + w[sprite_pack + 4]);

[80058810 + 40] = b(0);

if( bu[80058810 + 3d] != 0 )
{
    V0 = w[data110 + 10];
    V0 = (hu[V0 + 0] >> 6) & 3f;

    if( V0 != 0 )
    {
        [80058810 + 43] = b(V0);
    }
}
////////////////////////////////



////////////////////////////////
// func243e4
struct = A0;
animation_id = A1;

if( w[struct + 48] == 0 ) // sprite pack dont exist
{
    [struct + 64] = w(0);
    return;
}

if( w[struct + 44] == w[struct + 48] )
{
    [struct + b0] = w(w[struct + b0] & fffffbff);
}
else
{
    [struct + b0] = w(w[struct + b0] | 00000400);
}

if( animation_id < 0 )
{
    A0 = struct;
    A1 = w[struct + 4c];
    func22124;

    if( bu[80058810 + 3d] != 0 )
    {
        V0 = w[struct + 24];
        A0 = w[V0];
        if( (hu[A0] >> f) == 0 )
        {
            V1 = w[struct + 24];
            [V1 + 4] = h(0300);
            [V1 + 6] = h(0100);
        }
    }
}
else
{
    A0 = struct;
    A1 = w[struct + 48];
    func22124;

    if( bu[80058810 + 3d] != 0 )
    {
        V1 = w[struct + 24];
        V0 = w[struct + 7c];
        [V1 + 4] = w(w[V0 + e]);
    }
}

[struct + af] = b(animation_id);
if( animation_id < 0 )
{
    animation_id = 0 NOR animation_id;
}

[struct + 40] = w(w[struct + 40] | 00100000);


V0 = w[struct + 24];
sprite_data_0 = w[V0 + 10];

A0 = struct;
A1 = sprite_data_0 + hu[sprite_data_0 + 2 + animation_id * 2];
[struct + 58] = w(A1);
func233b8;

A0 = struct;
A1 = h[struct + 80];
func22218;
////////////////////////////////



////////////////////////////////
// func233b8
struct = A0;
animation_data = A1;

[struct + 54] = w(animation_data + 4 + hu[animation_data + 4]);
[struct + 58] = w(animation_data);
[struct + 64] = w(animation_data + 2 + hu[animation_data + 2]);
[struct + a8] = w((w[struct + a8] & ffcfffff) | ((hu[animation_data + 0] & 0003) << 14));

A0 = bu[animation_data + 0] >> 2;
if( A0 & 0020 )
{
    A0 = A0 | ffffffc0;
}
V1 = A0 << a;
V0 = w[80058838] + 1;
A0 = ((V0 * V0 * h[struct + 82]) >> c) * V1;
V0 = 10000 / ((w[struct + ac] >> 9) & fff);
[struct + 1c] = w((((V0 * V0) >> 8) * A0) >> 8);

if( ((hu[animation_data + 0] >> b) & 0001) == 0 )
{
    [struct + c] = w(0);
    [struct + 10] = w(0);
    [struct + 14] = w(0);
    [struct + 18] = w(0);
}

V1 = w[struct + 20];
if( V1 != 0 )
{
    V0 = (hu[animation_data + 0] >> c) & 0001;
    if( V0 == 0 )
    {
        [V1 + 0] = h(0);
        [V1 + 2] = h(0);
        [V1 + 4] = h(0);

        A0 = struct;
        func21eec;
    }

    if( bu[8005884d] != 0 )
    {
        if( ( (hu[animation_data + 0] >> d) & 0001 ) == 0 )
        {
            A0 = struct;
            A1 = w[80058848];
            80023564	jal    func21e60 [$80021e60]
        }

        A0 = struct;
        func21eec;
    }

    if( (w[struct + 3c] & 00000003) == 00000001 )
    {
        V0 = w[struct + 20];
        [V0 + 3c] = b(0);
        [V0 + 3d] = b(0);

        if( (w[struct + 40] & 00100000) == 0 )
        {
            V0 = w[struct + 20];
            if( w[V0 + 34] != 0 )
            {
                A0 = struct;
                800235D8	jal    func2332c [$8002332c]
            }
        }
    }
}

[struct + 30] = h(0);
[struct + 8c] = b(10);
[struct + 9e] = h(0001);
[struct + a8] = w(w[struct + a0] & fffff801);
[struct + a8] = w((w[struct + a8] & cfffffff & f03fffff) | 0001f800 | 20000000);

V1 = w[struct + 7c];
if( V1 != 0 )
{
    if( w[struct + a8] & 00000001 )
    {
        [V1 + 0] = w(0);
        [V1 + 4] = w(0);
        V0 = w[struct + 7c];
        [V0 + c] = h(0)
    }
}
////////////////////////////////



////////////////////////////////
// func21eec
struct = S2 = A0;
S1 = SP + 60;
if( (w[S2 + 40] & 1) == 0 )
{
    A0 = w[S2 + 20]; // rot data
    A1 = A0 + c;
    func3f5e0; // calculate rotation matrix

    V0 = w[S2 + 20];
    [SP + 20] = w(h[V0 + 6]);
    [SP + 24] = w(h[V0 + 8]);
    [SP + 28] = w(h[V0 + a]);

    A0 = w[S2 + 20] + c; // rot matrix
    A1 = SP + 20;
    func495f4; // multiply matrix with vector
}
else
{
    80021F78	lui    a1, $8002
    80021F7C	addiu  a1, a1, $8614 (=-$79ec)
    80021F80	lw     v0, $0000(a1)
    80021F84	lw     v1, $0004(a1)
    80021F88	lw     a0, $0008(a1)
    80021F8C	sw     v0, $0060(sp)
    80021F90	sw     v1, $0064(sp)
    80021F94	sw     a0, $0068(sp)
    80021F98	lw     v0, $000c(a1)
    80021F9C	lw     v1, $0010(a1)
    80021FA0	lw     a0, $0014(a1)
    80021FA4	sw     v0, $006c(sp)
    80021FA8	sw     v1, $0070(sp)
    80021FAC	sw     a0, $0074(sp)
    80021FB0	lw     v0, $0018(a1)
    80021FB4	lw     v1, $001c(a1)
    80021FB8	sw     v0, $0078(sp)
    80021FBC	sw     v1, $007c(sp)
    80021FC0	lw     v0, $0020(s2)
    80021FC4	nop
    80021FC8	lh     v0, $0006(v0)
    80021FCC	nop
    80021FD0	sw     v0, $0030(sp)
    80021FD4	lw     v0, $0020(s2)
    80021FD8	nop
    80021FDC	lh     v0, $0008(v0)
    80021FE0	nop
    80021FE4	sw     v0, $0034(sp)
    80021FE8	lw     v0, $0020(s2)
    80021FEC	addu   a0, s1, zero
    80021FF0	lh     v0, $000a(v0)
    80021FF4	addiu  a1, sp, $0030
    80021FFC	sw     v0, $0038(sp)
    func495f4; // multiply matrix with vector

    S0 = SP + 40;

    A0 = w[S2 + 20];
    A1 = S0;
    func3f5e0; // calculate rotation matrix

    80022010	addu   a0, s0, zero
    80022014	lw     a2, $0020(s2)
    80022018	addu   a1, s1, zero
    8002201C	jal    func490b4 [$800490b4]
    80022020	addiu  a2, a2, $000c
}

80022024	lhu    v0, $003a(s2)
if( V0 != 0 )
{
    80022030	srl    v0, v0, $01
    80022034	sw     v0, $0020(sp)
    80022038	lhu    v0, $003a(s2)
    8002203C	nop
    80022040	srl    v0, v0, $01
    80022044	sw     v0, $0024(sp)
    80022048	lhu    v0, $003a(s2)
    8002204C	nop
    80022050	srl    v0, v0, $01
    80022054	sw     v0, $0028(sp)
    80022058	lw     a0, $0020(s2)
    80022064	addiu  a0, a0, $000c
    8002205C	addiu  a1, sp, $0020
    80022060	jal    func49c74 [$80049c74]
}
////////////////////////////////



////////////////////////////////
// func3f5e0
rot_x = h[A0 + 0] & 0fff;
cos_x = h[80051a90 + rot_x * 4 + 0];
sin_x = h[80051a90 + rot_x * 4 + 2];

rot_y = h[A0 + 2] & 0fff;
cos_y = h[80051a90 + rot_y * 4 + 0];
sin_y = h[80051a90 + rot_y * 4 + 2];

rot_z = h[A0 + 4] & 0fff;
cos_z = h[80051a90 + rot_z * 4 + 0];
sin_z = h[80051a90 + rot_z * 4 + 2];

[A1 + 0] = h((sin_z * sin_y) >> c);
[A1 + 2] = h((0 - (cos_z * sin_y)) >> c);
[A1 + 4] = h(cos_y);
[A1 + 6] = h(((cos_z * sin_x) >> c) - ((((sin_z * (0 - cos_y)) >> c) * cos_x) >> c));
[A1 + 8] = h(((sin_z * sin_x) >> c) + ((((cos_z * (0 - cos_y)) >> c) * cos_x) >> c));
[A1 + a] = h((0 - (sin_y * cos_x)) >> c);
[A1 + c] = h(((cos_z * sin_y * sin_x) >> c) + ((cos_z * cos_x) >> c));
[A1 + e] = h(((sin_z * cos_x) >> c) - ((((cos_z * (0 - cos_y)) >> c) * sin_x) >> c));
[A1 + 10] = h((sin_y * sin_x) >> c);
return A1;
////////////////////////////////



////////////////////////////////
// func495f4
[A0 + 0] = h((h[A0 + 0] * w[A1 + 0]) >> c);
[A0 + 2] = h((h[A0 + 2] * w[A1 + 0]) >> c);
[A0 + 4] = h((h[A0 + 4] * w[A1 + 0]) >> c);
[A0 + 6] = h((h[A0 + 6] * w[A1 + 4]) >> c);
[A0 + 8] = h((h[A0 + 8] * w[A1 + 4]) >> c);
[A0 + a] = h((h[A0 + a] * w[A1 + 4]) >> c);
[A0 + c] = h((h[A0 + c] * w[A1 + 8]) >> c);
[A0 + e] = h((h[A0 + e] * w[A1 + 8]) >> c);
[A0 + 10] = h((h[A0 + 10] * w[A1 + 8]) >> c);

return A0;
////////////////////////////////



////////////////////////////////
// func22218
80022220	addu   s1, a0, zero
80022224	addu   a3, a1, zero
80022228	sll    a1, a1, $10
8002222C	sra    a1, a1, $10
80022230	addiu  a1, a1, $0400
8002223C	lw     v0, $00a8(s1)
80022240	andi   a1, a1, $0001
80022244	sh     a3, $0080(s1)
80022248	srl    t0, v0, $11
8002224C	beq    a1, zero, L22260 [$80022260]
80022250	andi   t0, t0, $0007
80022254	lw     v0, $00ac(s1)
80022258	j      L2226c [$8002226c]
8002225C	ori    v0, v0, $0010

L22260:	; 80022260
80022260	lw     v0, $00ac(s1)
80022264	addiu  v1, zero, $ffef (=-$11)
80022268	and    v0, v0, v1

L2226c:	; 8002226C
8002226C	sw     v0, $00ac(s1)
80022270	lw     v0, $0048(s1)
80022274	nop
80022278	beq    v0, zero, L224d8 [$800224d8]
8002227C	nop
80022280	lw     v0, $00a8(s1)
80022284	nop
80022288	srl    v0, v0, $14
8002228C	andi   v1, v0, $0003
80022290	ori    v0, zero, $0001
80022294	beq    v1, v0, L2232c [$8002232c]
80022298	slti   v0, v1, $0002
8002229C	beq    v0, zero, L222b4 [$800222b4]
800222A0	nop
800222A4	beq    v1, zero, L222c8 [$800222c8]
800222A8	addiu  v0, a3, $0400
800222AC	j      L22444 [$80022444]
800222B0	nop

L222b4:	; 800222B4
800222B4	ori    v0, zero, $0002
800222B8	beq    v1, v0, L2239c [$8002239c]
800222BC	sll    v0, a3, $10
800222C0	j      L22444 [$80022444]
800222C4	nop

L222c8:	; 800222C8
800222C8	andi   v0, v0, $0fff
800222CC	slti   v0, v0, $0801
800222D0	bne    v0, zero, L222e4 [$800222e4]
800222D4	addiu  v1, zero, $ffef (=-$11)
800222D8	lw     v0, $00ac(s1)
800222DC	j      L222f0 [$800222f0]
800222E0	ori    v0, v0, $0010

L222e4:	; 800222E4
800222E4	lw     v0, $00ac(s1)
800222E8	nop
800222EC	and    v0, v0, v1

L222f0:	; 800222F0
800222F0	sw     v0, $00ac(s1)
800222F4	lui    a1, $fff1
800222F8	ori    a1, a1, $ffff
800222FC	lw     a2, $0058(s1)
80022300	lw     v0, $00a8(s1)
80022304	lw     v1, $0058(s1)
80022308	and    v0, v0, a1
8002230C	lhu    a0, $0004(a2)
80022310	addiu  v1, v1, $0006
80022314	sw     v0, $00a8(s1)
80022318	sw     v1, $005c(s1)
8002231C	addiu  a0, a0, $0004
80022320	addu   a0, a0, a2
80022324	j      L22444 [$80022444]
80022328	sw     a0, $0054(s1)

L2232c:	; 8002232C
8002232C	sll    v0, a3, $10
80022330	sra    v0, v0, $10
80022334	addiu  v0, v0, $0600
80022338	sra    v0, v0, $0a
8002233C	andi   v0, v0, $0003
80022340	addu   a3, v0, zero
80022344	addu   v1, v0, zero
80022348	slti   v0, v1, $0003
8002234C	beq    v0, zero, L22380 [$80022380]
80022350	sll    v1, v1, $01
80022354	addiu  a1, zero, $ffef (=-$11)
80022358	lw     a2, $0058(s1)
8002235C	lw     v0, $00ac(s1)
80022360	addu   a0, v1, a2
80022364	and    v0, v0, a1
80022368	addiu  v1, v1, $0004
8002236C	lhu    a0, $0004(a0)
80022370	addu   v1, v1, a2
80022374	sw     v0, $00ac(s1)
8002237C	addu   a0, a0, v1
[S1 + 54] = w[A0];
80022378	j      L22420 [$80022420]


L22380:	; 80022380
80022380	lw     v0, $0058(s1)
80022384	lw     v1, $00ac(s1)
80022388	lhu    a0, $0006(v0)
8002238C	ori    v1, v1, $0010
80022390	sw     v1, $00ac(s1)
80022398	addiu  a0, a0, $0006
8002241C	addu   a0, a0, v0
[S1 + 54] = w[A0];
80022394	j      L22420 [$8002241c]


L2239c:	; 8002239C
8002239C	sra    v0, v0, $10
800223A0	addiu  v0, v0, $0500
800223A4	sra    v0, v0, $09
800223A8	andi   v1, v0, $0007
A0 = V0;
A3 = V1;

if( A0 < 5 )
{
    A2 = w[S1 + 58];
    // 800223d8 : LHU     8011282c (a0), 0004 (8011282c (a0)) [80112830]
    var = hu[A2 + 4 + A0 * 2];
    [S1 + 54] = w[A2 + 4 + A0 * 2 + var];

    [S1 + ac] = w(w[S1 + ac] & ffffffef);
}
else
{
    800223EC	addiu  v0, v1, $fffb (=-$5)
    800223F0	xori   v0, v0, $0003
    800223F4	addu   a3, v0, zero
    800223F8	sll    v0, v0, $01
    800223FC	lw     a1, $0058(s1)
    80022400	lw     v1, $00ac(s1)
    80022404	addu   a0, v0, a1
    80022408	ori    v1, v1, $0010
    8002240C	addiu  v0, v0, $0004
    80022410	lhu    a0, $0004(a0)
    80022414	addu   v0, v0, a1
    80022418	sw     v1, $00ac(s1)
    8002241C	addu   a0, a0, v0
    [S1 + 54] = w[A0];
}

L22420:	; 80022420
80022424	lui    v0, $fff1
80022428	lw     v1, $00a8(s1)
8002242C	ori    v0, v0, $ffff
80022430	and    v1, v1, v0
80022434	andi   v0, a3, $0007
80022438	sll    v0, v0, $11
8002243C	or     v1, v1, v0
80022440	sw     v1, $00a8(s1)

L22444:	; 80022444
80022444	lw     a2, $00a8(s1)
80022448	nop
8002244C	srl    v0, a2, $11
80022450	andi   v0, v0, $0007
80022454	beq    t0, v0, L224a8 [$800224a8]
80022458	srl    a2, a2, $16
8002245C	lui    v1, $0001
80022460	ori    v1, v1, $f800
80022464	lui    a1, $f03f
80022468	ori    a1, a1, $ffff
8002246C	lw     v0, $00a8(s1)
80022470	lw     a0, $0058(s1)
80022474	lh     s0, $009e(s1)
80022478	or     v0, v0, v1
8002247C	and    v0, v0, a1

// 80022480 : LHU     0001f800 (v1), 0002 (80112828 (a0)) [8011282a]
80022480	lhu    v1, $0002(a0)
80022484	lw     a1, $0064(s1)
80022488	andi   a2, a2, $003f
8002248C	sw     v0, $00a8(s1)
80022490	addiu  v1, v1, $0002
80022494	addu   v1, v1, a0
80022498	addu   a0, s1, zero
8002249C	jal    func224f0 [$800224f0]
800224A0	sw     v1, $0064(s1)
800224A4	sh     s0, $009e(s1)

L224a8:	; 800224A8
800224A8	addiu  v0, zero, $fff7 (=-$9)
800224AC	lw     a0, $003c(s1)
800224B0	lw     v1, $00ac(s1)
800224B4	and    a0, a0, v0
800224B8	srl    v0, v1, $05
800224BC	andi   v0, v0, $0001
800224C0	srl    v1, v1, $04
800224C4	andi   v1, v1, $0001
800224C8	xor    v0, v0, v1
800224CC	sll    v0, v0, $03
800224D0	or     a0, a0, v0
800224D4	sw     a0, $003c(s1)

L224d8:	; 800224D8
////////////////////////////////
