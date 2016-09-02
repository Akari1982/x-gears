////////////////////////////////
// func80720
80080724	addiu  v0, zero, $ffff (=-$1)
80080740	lui    at, $800c
80080744	sw     v0, $2de4(at)
80080748	jal    funca15c0 [$800a15c0]
8008074C	addu   s2, zero, zero
80080750	lui    a1, $800b
80080754	lw     a1, $d0d4(a1)
80080758	nop
8008075C	blez   a1, L807e0 [$800807e0]
80080760	nop
80080764	addu   a0, zero, zero

loop80768:	; 80080768
80080768	lui    v0, $800b
8008076C	lw     v0, $efe4(v0)
80080770	nop
80080774	addu   v0, a0, v0
80080778	lw     v1, $004c(v0)
8008077C	nop
80080780	lh     v0, $0022(v1)
80080784	nop
80080788	sh     v0, $0068(v1)
8008078C	lui    v0, $800b
80080790	lw     v0, $efe4(v0)
80080794	nop
80080798	addu   v0, a0, v0
8008079C	lw     v1, $004c(v0)
800807A0	nop
800807A4	lh     v0, $0026(v1)
800807A8	nop
800807AC	sh     v0, $006a(v1)
800807B0	lui    v0, $800b
800807B4	lw     v0, $efe4(v0)
800807B8	nop
800807BC	addu   v0, a0, v0
800807C0	lw     v1, $004c(v0)
800807C4	addiu  s2, s2, $0001
800807C8	lh     v0, $002a(v1)
800807CC	nop
800807D0	sh     v0, $006c(v1)
800807D4	slt    v0, s2, a1
800807D8	bne    v0, zero, loop80768 [$80080768]
800807DC	addiu  a0, a0, $005c

L807e0:	; 800807E0
800807E0	lui    v0, $800c
800807E4	lw     v0, $1b60(v0)
800807E8	nop
800807EC	bne    v0, zero, L80804 [$80080804]
800807F0	nop
800807F4	lui    a0, $8007
800807F8	addiu  a0, a0, $f29c (=-$d64)
800807FC	0C0A06C6	Ж...
80080800	nop

L80804:	; 80080804
80080804	lui    v0, $800b
80080808	lw     v0, $d0d4(v0)
8008080C	lui    at, $800b
80080810	sw     zero, $ed2c(at)
80080814	blez   v0, L809a8 [$800809a8]
80080818	addu   s2, zero, zero
8008081C	addu   s3, zero, zero

loop80820:	; 80080820
80080820	lui    v0, $800b
80080824	lw     v0, $efe4(v0)
80080828	nop
8008082C	addu   s1, v0, s3
80080830	lhu    v0, $0058(s1)
80080834	lw     s0, $004c(s1)
80080838	andi   v1, v0, $0f80
8008083C	ori    v0, zero, $0200
80080840	bne    v1, v0, L8098c [$8008098c]
80080828	nop
A0 = w[S0 + 0];
if( ( A0 & 00010001 ) == 0 )
{
    8008085C	lw     v0, $0004(s0)
    80080860	nop
    80080864	andi   v0, v0, $0600
    80080868	beq    v0, v1, L8098c [$8008098c]
    8008086C	nop

    A0 = S0;
    func7ff7c; // get current triangle material

    [S0 + 14] = w(V0);

    A0 = S2; // entity id
    A1 = S1; // struct_5c
    A2 = S0; // struct_138
    func81c34; // calculate move vector

    A0 = S2;
    A1 = S1; // struct_5c
    A2 = S0; // struct_138
    func821cc; // perform move

    8008089C	j      L80990 [$80080990]
    800808A0	addiu  s3, s3, $005c
}

L808a4:	; 800808A4
800808A4	lw     v0, $0004(s0)
800808A8	lui    v1, $0100
800808AC	and    v0, v0, v1
800808B0	beq    v0, zero, L80924 [$80080924]
800808B4	lui    v0, $0001
800808B8	and    v0, a0, v0
800808BC	bne    v0, zero, L80924 [$80080924]
800808C0	nop
800808C4	lh     v1, $00e8(s0)
800808C8	lh     v0, $00ea(s0)
800808CC	nop
800808D0	beq    v1, v0, L8098c [$8008098c]
800808D4	ori    v0, zero, $0002
800808D8	sh     v0, $00ea(s0)
800808DC	lui    v0, $800b
800808E0	lw     v0, $efe4(v0)
800808E4	nop
800808E8	addu   v0, s3, v0
800808EC	lw     v1, $004c(v0)
800808F0	nop
800808F4	lhu    v0, $00ea(v1)
800808F8	nop
800808FC	sh     v0, $00e8(v1)
80080900	lui    v0, $800b
80080904	lw     v0, $efe4(v0)
80080908	lh     a1, $00ea(s0)
8008090C	addu   v0, s3, v0
80080910	lw     a0, $0004(v0)
80080914	jal    func243e4 [$800243e4]
80080918	addiu  s3, s3, $005c
8008091C	j      L80990 [$80080990]
80080920	nop

L80924:	; 80080924
80080924	lw     v0, $0004(s0)
80080928	lui    v1, $0020
8008092C	and    v0, v0, v1
80080930	beq    v0, zero, L8098c [$8008098c]
80080934	nop
80080938	lui    v0, $800b
8008093C	lw     v0, $efe4(v0)
80080940	nop
80080944	addu   v0, s3, v0
80080948	lw     a1, $004c(v0)
8008094C	nop
80080950	lh     v1, $00ea(a1)
80080954	lh     v0, $00e8(a1)
80080958	nop
8008095C	beq    v0, v1, L8098c [$8008098c]
80080960	addu   a0, v1, zero
80080964	sh     a0, $00e8(a1)
80080968	lui    a2, $800b
8008096C	lw     a2, $efe4(a2)
80080970	nop
80080974	addu   a2, s3, a2
80080978	lw     v0, $004c(a2)
8008097C	lw     a0, $0004(a2)
80080980	lh     a1, $00ea(v0)
80080984	jal    func81808 [$80081808]
80080988	nop

L8098c:	; 8008098C
8008098C	addiu  s3, s3, $005c

L80990:	; 80080990
80080990	lui    v0, $800b
80080994	lw     v0, $d0d4(v0)
80080998	addiu  s2, s2, $0001
8008099C	slt    v0, s2, v0
800809A0	bne    v0, zero, loop80820 [$80080820]
800809A4	nop

L809a8:	; 800809A8
800809A8	lui    v0, $800c
800809AC	lw     v0, $1b60(v0)
800809B0	nop
800809B4	bne    v0, zero, L809cc [$800809cc]
800809B8	nop
800809BC	lui    a0, $8007
800809C0	addiu  a0, a0, $f2a8 (=-$d58)
800809C4	0C0A06C6	Ж...
800809C8	nop

L809cc:	; 800809CC
800809CC	lui    a0, $800b
800809D0	lw     a0, $1740(a0)
800809D4	lui    v1, $800b
800809D8	lw     v1, $efe4(v1)
800809DC	sll    v0, a0, $01
800809E0	addu   v0, v0, a0
800809E4	sll    v0, v0, $03
800809E8	subu   v0, v0, a0
800809EC	sll    v0, v0, $02
800809F0	addu   s1, v1, v0
800809F4	lw     a2, $004c(s1)
800809F8	jal    func8376c [$8008376c]
800809FC	addu   a1, s1, zero
80080A00	lui    v0, $800c
80080A04	lw     v0, $1b60(v0)
80080A08	nop
80080A0C	bne    v0, zero, L80a24 [$80080a24]
80080A10	nop
80080A14	lui    a0, $8007
80080A18	addiu  a0, a0, $f2b4 (=-$d4c)
80080A1C	0C0A06C6	Ж...
80080A20	nop

L80a24:	; 80080A24
80080A24	lui    v0, $800b
80080A28	lw     v0, $d0d4(v0)
80080A2C	nop
80080A30	blez   v0, L80b20 [$80080b20]
80080A34	addu   s2, zero, zero
80080A38	ori    s4, zero, $0200
80080A3C	addu   s3, zero, zero

loop80a40:	; 80080A40
80080A40	lui    v0, $800b
80080A44	lw     v0, $efe4(v0)
80080A48	nop
80080A4C	addu   a1, s3, v0
80080A50	lhu    v1, $0058(a1)
80080A54	nop
80080A58	andi   v0, v1, $0f00
80080A5C	beq    v0, zero, L80b08 [$80080b08]
80080A60	addu   s1, a1, zero
80080A64	lw     s0, $004c(s1)
80080A68	nop
80080A6C	lw     v0, $0004(s0)
80080A70	nop
80080A74	andi   v0, v0, $0600
80080A78	beq    v0, s4, L80b08 [$80080b08]
80080A7C	andi   v0, v1, $0f80
80080A80	bne    v0, s4, L80b08 [$80080b08]
80080A84	lui    v1, $0001
80080A88	lw     v0, $0000(s0)
80080A8C	ori    v1, v1, $0001
80080A90	and    v0, v0, v1
80080A94	bne    v0, zero, L80b08 [$80080b08]
80080A98	nop
80080A9C	lui    v0, $800b
80080AA0	lw     v0, $1740(v0)
80080AA4	nop
80080AA8	beq    s2, v0, L80b08 [$80080b08]
80080AAC	addu   a0, s2, zero
80080AB0	lui    a1, $7fff
80080AB4	ori    a1, a1, $ffff
80080AB8	addu   a2, s1, zero
80080ABC	addu   a3, s0, zero
80080AC0	jal    func84054 [$80084054]
80080AC4	sw     zero, $0010(sp)
80080AC8	lui    v0, $800b
80080ACC	lw     v0, $efe4(v0)
80080AD0	nop
80080AD4	addu   v0, s3, v0
80080AD8	lw     v0, $0004(v0)
80080ADC	nop
80080AE0	lw     v0, $007c(v0)
80080AE4	nop
80080AE8	lhu    v1, $000c(v0)
80080AEC	ori    v0, zero, $0001
80080AF0	bne    v1, v0, L80b08 [$80080b08]
80080AF4	addiu  v1, zero, $f7ff (=-$801)
80080AF8	lw     v0, $0000(s0)
80080AFC	nop
80080B00	and    v0, v0, v1
80080B04	sw     v0, $0000(s0)

L80b08:	; 80080B08
80080B08	lui    v0, $800b
80080B0C	lw     v0, $d0d4(v0)
80080B10	addiu  s2, s2, $0001
80080B14	slt    v0, s2, v0
80080B18	bne    v0, zero, loop80a40 [$80080a40]
80080B1C	addiu  s3, s3, $005c

L80b20:	; 80080B20
80080B20	lui    v0, $800c
80080B24	lw     v0, $1b60(v0)
80080B28	nop
80080B2C	bne    v0, zero, L80b44 [$80080b44]
80080B30	nop
80080B34	lui    a0, $8007
80080B38	addiu  a0, a0, $f2c0 (=-$d40)
80080B3C	0C0A06C6	Ж...
80080B40	nop

L80b44:	; 80080B44
80080B44	lui    v0, $800b
80080B48	lh     v0, $164a(v0)
80080B4C	nop
80080B50	bne    v0, zero, L80bac [$80080bac]
80080B54	ori    v0, zero, $0001
80080B58	lui    v0, $800b
80080B5C	lbu    v0, $16a0(v0)
80080B60	nop
80080B64	bne    v0, zero, L80bac [$80080bac]
80080B68	ori    v0, zero, $0001
80080B6C	lui    a0, $800b
80080B70	lw     a0, $1740(a0)
80080B74	lui    v1, $800b
80080B78	lw     v1, $efe4(v1)
80080B7C	lui    a1, $800b
80080B80	lw     a1, $efe4(a1)
80080B84	sll    v0, a0, $01
80080B88	addu   v0, v0, a0
80080B8C	sll    v0, v0, $03
80080B90	subu   v0, v0, a0
80080B94	sll    v0, v0, $02
80080B98	addu   v1, v0, v1
80080B9C	lw     a2, $004c(v1)
80080BA0	jal    func82fb0 [$80082fb0]
80080BA4	addu   a1, a1, v0
80080BA8	ori    v0, zero, $0001

L80bac:	; 80080BAC
80080BAC	lui    at, $800b
80080BB0	sw     v0, $d0e4(at)
80080BB4	jal    func80c04 [$80080c04]
80080BB8	nop
80080BBC	lui    v0, $800c
80080BC0	lw     v0, $1b60(v0)
80080BC4	nop
80080BC8	bne    v0, zero, L80be0 [$80080be0]
80080BCC	nop
80080BD0	lui    a0, $8007
80080BD4	addiu  a0, a0, $f2cc (=-$d34)
80080BD8	0C0A06C6	Ж...
80080BDC	nop

L80be0:	; 80080BE0
////////////////////////////////



////////////////////////////////
// func81c34
entity_id = A0;
struct_5c = A1;
struct_138 = A2;



// get currecnt walkmesh triangle material
material = 0;
V1 = h[struct_138 + 10] + 3; // walkmesh id
if( ( ( w[struct_138 + 4] >> V1 ) & 1 ) == 0 ) // use walkmesh material
{
    if( bu[800b16a0] == 0 )
    {
        material = w[struct_138 + 14];
    }
}



A0 = SP + 10; // material self move vector
speed_id = (material >> 9) & 3;
A1 = h[800ad49c + speed_id * 2]; // walking speed
dir_id = (material >> b) & 7;
A2 = hu[800ad480 + dir_id * 2];
A2 = (hu[800b164c] + A2) & 0fff; // default + rot
func7ac28;



if( ( w[struct_138 + 0] & 00041800 ) == 0 )
{
    S0 = 0;
    S3 = 0;

    // calculate sliding down
    if( material & 00420000 ) // cant go up and something else
    {
        [SP + 20] = w((0 - (w[struct_138 + 50] * w[struct_138 + 54])) >> f);
        [SP + 24] = w(1);
        [SP + 28] = w((0 - (w[struct_138 + 58] * w[struct_138 + 54])) >> f);

        if( w[SP + 20] == 0 )
        {
            [SP + 20] = w(1);
        }
        if( w[SP + 28] == 0 )
        {
            [SP + 28] = w(1);
        }

        A0 = SP + 20;
        A1 = SP + 30;
        system_normalize_word_vector_T0_T1_T2_to_word;

        if( w[SP + 30] == 0 )
        {
            [SP + 30] = w(1);
        }
        if( w[SP + 34] == 0 )
        {
            [SP + 34] = w(1);
        }
        if( w[SP + 38] == 0 )
        {
            [SP + 38] = w(1);
        }

        V1 = w[struct_138 + f0] >> 11;
        slide_x = (w[SP + 30] * V1) << 4;
        slide_z = (w[SP + 38] * V1) << 4;

        V1 = c;
        if( material & 00400000 ) // 00400000 - we can go down on this material but can't go up.
        {
            V1 = 18;
        }
        V0 = V1 << 10;

        S5 = w[struct_5c + 4];
        if( ( w[struct_138 + f0] >> 10 ) < V1 )
        {
            V0 = w[struct_138 + f0] + w[S5 + 1c];
        }
        [struct_138 + f0] = w(V0);

        [S5 + 10] = w(w[struct_138 + f0] >> 1);
    }

    if( material & 00400000 )
    {
        [struct_138 + 40] = w(w[struct_138 + 40] + slide_x);
        [struct_138 + 48] = w(w[struct_138 + 48] + slide_z);
        [struct_138 + 104] = h(hu[struct_138 + 104] | 8000); // change rotation
    }


    if( bu[struct_138 + 74] == ff )
    {
        if( material & 00020000 )
        {
            [struct_138 + 40] = w(w[struct_138 + 40] + slide_x);
            [struct_138 + 48] = w(w[struct_138 + 48] + slide_z);
        }

        if( material & 00008000 )
        {
            [struct_138 + 40] = w(w[struct_138 + 40] + w[SP + 10]);
            [struct_138 + 44] = w(w[struct_138 + 44] + w[SP + 14]);
            [struct_138 + 48] = w(w[struct_138 + 48] + w[SP + 18]);
        }
    }
}
else
{
    if( material & 00004000 )
    {
        [struct_138 + 40] = w(w[struct_138 + 40] + w[SP + 10]);
        [struct_138 + 44] = w(w[struct_138 + 44] + w[SP + 14]);
        [struct_138 + 48] = w(w[struct_138 + 48] + w[SP + 18]);
    }
}



V1 = bu[struct_138 + 74];
if( V1 != ff )
{
    A0 = w[800aefe4];
    V0 = w[A0 + V1 * 5c + 4c];
    if( ( w[V0 + 4] & 000000c0 ) == 000000c0 )
    {
        if( ( w[struct_138 + 134] & 00000080 ) == 0 )
        {
            A0 = c;
            A1 = 0;
            system_memory_allocate;
            [struct_138 + 110] = w(V0);

            [struct_138 + 138] = w(w[struct_138 + 138] | 00000080);
        }

        A2 = w[800aefe4];
        A1 = bu[struct_138 + 74];
        V1 = w[struct_138 + 110];

        [SP + 50] = h(hu[A2 + A1 * 5c + 50] - hu[V1 + 0]);
        [SP + 52] = h(hu[A2 + A1 * 5c + 52] - hu[V1 + 2]);
        [SP + 54] = h(hu[A2 + A1 * 5c + 54] - hu[V1 + 4]);

        [V1 + 2] = h(hu[A2 + A1 * 5c + 52]);

        V0 = w[A2 + A1 * 5c + 4c];
        S3 = w[V0 + 20];
        S5 = w[V0 + 28];
        S0 = (A0 << 10) >> 10;

        S4 = w[struct_138 + 20];
        S6 = w[struct_138 + 28];

        if( ( h[struct_138 + 104] & 00008000 ) == 0 )
        {
            A0 = entity_id;
            8008207C	jal    func81bc0 [$80081bc0]

            V1 = w[struct_138 + 110];
            [V1 + 8] = h(V0);
        }

        A0 = S5 - S6;
        V0 = w[struct_138 + 110];
        S1 = h[V0 + 8];
        A1 = S3 - S4;
        system_get_rotation_based_on_vector_x_y;
        V0 = ((V0 << 10) >> 10) - S0;

        S0 = V0 - 800;

        A0 = S0;
        func3f774; // cos
        [struct_138 + 40] = w(w[struct_138 + 40] + (S3 + ((V0 * S1) << 4) - S4))

        A0 = S0;
        func3f758; // sin
        [struct_138 + 48] = w(w[struct_138 + 48] + (S5 + ((V0 * S1) << 4) - S6))
    }
}

if( (w[struct_138 + 4] & 00022000) == 00022000 )
{
    A1 = w[800aed2c];
    V0 = w[801e8670 + A1 * 4];
    [struct_138 + 40] = w(w[struct_138 + 40] - (((w[V0 + 128] << 10) / hu[struct_138 + 76]) << 8));
    [struct_138 + 48] = w(w[struct_138 + 48] - (((w[V0 + 130] << 10) / hu[struct_138 + 76]) << 8));
    [800aed2c] = w(w[800aed2c] + 1);
}
////////////////////////////////



////////////////////////////////
// func821cc
entity_id = A0;
struct_5c = A1;
struct_138 = A2;

S2 = h[struct_138 + 104];
S3 = w[struct_5c + 4];
[80065198] = w(entity_id);

if( w[struct_138 + 0] & 01000000 )
{
    return;
}

animation_id = 1;

if( ( w[struct_138 + 0] & 00004000 ) && ( hu[800af370] & 0040 ) && ( w[800ad040] == 1 ) )
{
    animation_id = 2;
}

V1 = h[struct_138 + e8]
if( ( w[struct_138 + 0] & 00001800 ) && ( V1 != animation_id ) )
{
    if( V1 == 1 || V1 == 2 )
    {
        animation_id = V1;
    }
}

if( bu[struct_138 + e3] >= 9 )
{
    [struct_138 + e3] = b(bu[struct_138 + e3] - 1);
}

S1 = w[struct_138 + 40] | w[struct_138 + 44] | w[struct_138 + 48];

A0 = struct_138;
func83f40;

if( V0 == -1 )
{
    S1 = 1;
}

if( ( S2 & 8000 ) == 0 || S1 != 0 || ( w[struct_138 + 0] & 00040800 ) != 0 )
{
    if( ( S2 & 8000 ) == 0 )
    {
        A0 = S3;
        A1 = S2 & ffff;
        A2 = struct_5c;
        func81594;

        [SP + 10] = w(w[S3 + c] + w[struct_138 + 40]);
        [SP + 14] = w(w[S3 + 10] + w[struct_138 + 44]);
        [SP + 18] = w(w[S3 + 14] + w[struct_138 + 48]);

        [struct_138 + 106] = h(S2);
    }
    else
    {
        [SP + 10] = w(w[struct_138 + 40]);
        [SP + 14] = w(w[struct_138 + 44]);
        [SP + 18] = w(w[struct_138 + 48]);

        S2 = hu[struct_138 + 106] & 0fff;
    }

    A0 = SP + 10;
    A1 = struct_138;
    func81aa8; // check if we in some triangle

    if (V0 == 0) 
    {
        if (w[SP + 10] != 0 || w[SP + 18] != 0)
        {
            A0 = w[SP + 18];
            A1 = w[SP + 10];
            system_get_rotation_based_on_vector_x_y;

            V0 = 0 - V0;
            S2 = V0 & 0fff;
        }

        A0 = -1;

        V0 = h[struct_138 + 10]; // walkmesh_id
        if( h[struct_138 + 8 + V0 * 2] != -1 ) // if triangle id exist
        {
            S1 = w[struct_138 + 0];
            if( entity_id == w[800b1740] ) // if current entity - party leader
            {
                if( w[80059ad8] != ff || w[80059adc] != ff )
                {
                    V1 = w[800aefe4];
                    V0 = w[V1 + V0 * 5c + 4c];
                    [struct_138 + 0] = w(w[struct_138 + 0] | (w[V0 + 0] & 00000600));
                }
            }

            A0 = SP + 10; // move vector
            A1 = struct_138; // entity structure
            A2 = SP + 20; // address to store line that we can't intersect
            A3 = S2 & ffff;

            if ((w[struct_138 + 0] & 00041800) == 0 && bu[struct_138 + 74] == ff && w[800ad070] == 0)
            {
                // we move here
                func7b0d4;
            }
            else
            {
                func7ae28;
            }

            A0 = V0;
            [struct_138 + 0] = w((w[struct_138 + 0] & fffff9ff) | (S1 & 00000600));
        }

        if (A0 == -1) // if we can't move
        {
            [struct_138 + f0] = w(00010000);
            [struct_138 + 40] = w(0);
            [struct_138 + 44] = w(0);
            [struct_138 + 48] = w(0);
            [SP + 10] = w(0);
            [SP + 14] = w(0);
            [SP + 18] = w(0);
            [S3 + c] = w(0);
            [S3 + 14] = w(0);
            [struct_138 + 106] = h(hu[struct_138 + 106] | 8000);
        }
    }
    else
    {
        [struct_138 + f0] = w(00010000);
        [struct_138 + 40] = w(0);
        [struct_138 + 44] = w(0);
        [struct_138 + 48] = w(0);
        [SP + 10] = w(0);
        [SP + 14] = w(0);
        [SP + 18] = w(0);
        [S3 + c] = w(0);
        [S3 + 14] = w(0);
        [struct_138 + 106] = h(hu[struct_138 + 106] | 8000);
    }
}
else
{
    animation_id = hu[struct_138 + e6];

    [struct_138 + 40] = w(0);
    [struct_138 + 44] = w(0);
    [struct_138 + 48] = w(0);
    [struct_138 + f0] = w(00010000);
    [struct_138 + 104] = h(hu[struct_138 + 104] | 8000);
    [struct_138 + 106] = h(hu[struct_138 + 106] | 8000);

    [SP + 10] = w(0);
    [SP + 14] = w(0);
    [SP + 18] = w(0);

    [S3 + c] = w(0);
    [S3 + 14] = w(0);
}

[struct_138 + 4] = w(w[struct_138 + 4] & ffffefff);

if (w[struct_138 + 0] & 00000800)
{
    if (h[800b1818] == 0)
    {
        if (h[S3 + 6] != h[S3 + 84])
        {
            if (animation_id == 2)
            {
                [S3 + 18] = w(h[S3 + 82] * 60);
            }
            else
            {
                [S3 + 18] = w(h[S3 + 82] * 30);
            }
        }
        else
        {
            [S3 + 18] = w(0);
        }
    }

    animation_id = hu[800b181a];
}
else
{
    if (h[struct_138 + 104] & 8000)
    {
        [struct_138 + e6] = hu(animation_id);
    }

    A0 = struct_138;
    func7ff7c;

    if (V0 & 00200000)
    {
        V0 = h[struct_138 + 104];
        if (V0 & 8000)
        {
            V1 = h[struct_138 + e8];
            if (V1 == 6)
            {
                [struct_138 + 4] = w(w[struct_138 + 4] | 00001000)
            }
        }

        animation_id = 6;
    }
}

V1 = h[struct_138 + ea]; // animation related
if (V1 != ff)
{
    animation_id = V1;
}

if (h[struct_138 + e8] != animation_id)
{
    if ((w[struct_138 + 0] & 02000000) == 0)
    {
        [struct_138 + e8] = h(animation_id);
        A0 = S3;
        A1 = animation_id;
        A2 = struct_5c;
        func81808;
    }
}

if (w[struct_138 + 14] & 00000100)
{
    [SP + 10] = w(w[SP + 10] / 2);
    [SP + 18] = w(w[SP + 18] / 2);
}

[struct_138 + 30] = w(w[SP + 10]);
[struct_138 + 34] = w(w[SP + 14]);
[struct_138 + 38] = w(w[SP + 18]);

[struct_138 + 40] = w(0);
[struct_138 + 44] = w(0);
[struct_138 + 48] = w(0);
////////////////////////////////



////////////////////////////////
// func83f40
struct_138 = A0;

if( ( w[struct_138 + 14] & 00420000 ) == 0 && 
    w[800ad070] == 0 &&
    w[struct_138 + 30] == 0 && // X
    w[struct_138 + 34] == 0 && // Y
    w[struct_138 + 38] == 0 && // Z
    w[800ad0e4] == 1 &&
    bu[struct_138 + 74] == ff &&
    (w[struct_138 + 0] & 00401800) == 0 &&
    ((w[struct_138 + 4] & 00000001) == 0 || h[A0 + 10] != 0) &&
    ((w[struct_138 + 4] & 00000002) == 0 || h[A0 + 10] != 1))
{
    if ((w[struct_138 + 4] & 00000004) == 0)
    {
        return 0;
    }

    return (h[struct_138 + 10] ^ 0002) < 1; // -1 if but 0x0002 set, 0 otherwise
}

return -1;
////////////////////////////////



////////////////////////////////
// func7b0d4
// main move ???

// SP = SP - a8
// A0 - some address (SP + 10) // vector to which we rotated if it not 0
// A1 - entity structure
// A2 - address to store line that we can't intersect
// A3 - rotation 0x0XXX
// return -1 if we can't move, 0 otherwise.

move_vector = A0;
entity_structure = A1;
intersect_line = A2;
rotation = A3;



// check first rotation
angle1 = (rotation - 100) & 0fff;

A0 = angle1;
func3f774; // cos
[SP + 20] = w(w[move_vector + 0] + (V0 << 6));

A0 = angle1;
func3f758; // sin
[SP + 28] = w(w[move_vector + 8] - (V0 << 6));

A0 = SP + 20; // move vector
A1 = entity_structure + 20; // current pos
A2 = entity_structure;
A3 = intersect_line; // address to store line that we can't intersect
A4 = SP + 40; // address of final point
A5 = -1; // we don't need to calculate height of final point
A6 = SP + 70; // we store material here
field_check_walkmesh_triangle_and_calculate_height; // 0 - can move, -1 - can't move

if (V0 != -1)
{
    // check second rotation
    angle2 = (rotation + 100) & 0fff;

    A0 = angle2;
    func3f774; // cos
    [SP + 20] = w(w[move_vector + 0] + (V0 << 6));

    A0 = angle2;
    func3f758; // sin
    [SP + 28] = w(w[move_vector + 8] - (V0 << 6));

    A0 = SP + 20;
    A1 = entity_structure + 20;
    A2 = entity_structure;
    A3 = intersect_line;
    A4 = SP + 40;
    A5 = -1;
    A6 = SP + 70;
    field_check_walkmesh_triangle_and_calculate_height; // 0 - can move, -1 - can't move

    if (V0 != -1)
    {
        // check straight
        A0 = rotation & 0fff;
        func3f774; // cos
        [SP + 20] = w(w[move_vector + 0] + (V0 << 6));

        A0 = rotation & 0fff;
        func3f758; // sin
        [SP + 28] = w(w[move_vector + 8] - (V0 << 6));

        A0 = SP + 20;
        A1 = entity_structure + 20;
        A2 = entity_structure;
        A3 = intersect_line;
        A4 = SP + 40;
        A5 = -1;
        A6 = SP + 70;
        field_check_walkmesh_triangle_and_calculate_height; // 0 - can move, -1 - can't move

        if (V0 != -1)
        {
            [SP + 20] = w(w[move_vector + 0]);
            [SP + 24] = w(w[move_vector + 4]);
            [SP + 28] = w(w[move_vector + 8]);
            8007B274	j      L7b2a0 [$8007b2a0]
        }
    }
}

[SP + 20] = w(w[move_vector + 0]);
[SP + 24] = w(w[move_vector + 4]);
[SP + 28] = w(w[move_vector + 8]);

A0 = rotation;
A1 = intersect_line;
A2 = SP + 20;
field_get_move_vector_to_move_along_with_line;

L7b2a0:	; 8007B2A0
A0 = SP + 20;
A1 = entity_structure + 20;
A2 = entity_structure;
A3 = intersect_line;
A4 = SP + 40;
A5 = 0;
A6 = SP + 70;
field_check_walkmesh_triangle_and_calculate_height; // check triangle

if (V0 != -1)
{
    // store move vector
    [SP + 30] = w(w[SP + 20]);
    [SP + 34] = w(w[SP + 24]);
    [SP + 38] = w(w[SP + 28]);

    // store new position
    [SP + 48] = h(hu[SP + 40]);
    [SP + 4a] = h(hu[SP + 42]);
    [SP + 4c] = h(hu[SP + 44]);

    start_y = h[entity_structure + 26]; // y current
    end_y = h[SP + 42]; // y calculated

    // if we do something that can bother movement
    if ((end_y < start_y) ||
        (w[SP + 70] & 00200000) ||
        ((w[SP + 70] & 00420000) && (w[entity_structure + 14] & 00420000)) ||
        (((w[SP + 70] & 00420000) == 0) && (end_y < start_y + 40)))
    {
        V0 = w[SP + 20];
        V0 = -V0;
        V0 = V0 >> 8;
        [SP + 50] = w(V0);

        V1 = w[SP + 28];
        V1 = -V1;
        V1 = V1 >> 8;
        [SP + 58] = w(V1);

        V0 = h[SP + 42];
        A2 = w[entity_structure + 24];
        V0 = V0 << 10;
        V0 = V0 - A2;
        V0 = V0 >> 8;
        [SP + 54] = w(V0);

        A0 = SP + 50;
        A1 = SP + 60;
        system_normalize_word_vector_T0_T1_T2_to_word;

        A0 = w[SP + 20] >> 8;
        A1 = w[SP + 28] >> 8;
        length_of_vector_by_x_y;

        T2 = V0 * w[SP + 60];
        V0 = V0 * w[SP + 64];
        V1 = V0 * w[SP + 68];
        V0 = -T2;
        [SP + 20] = w(V0 >> 4);
        [SP + 24] = w(T0 >> 4);
        V0 = -V1;
        [SP + 28] = w(V0 >> 4);

        A0 = SP + 20;
        A1 = entity_structure + 20;
        A2 = entity_structure;
        A3 = intersect_line;
        [SP + 10] = w(SP + 40);
        [SP + 14] = w(0);
        [SP + 18] = w(SP + 70);
        field_check_walkmesh_triangle_and_calculate_height; // check triangle

        if (V0 == -1)
        {
            return -1;
        }

        [entity_structure + 0] = w(w[entity_structure + 0] | 04000000);
    }
    else
    {
        // restore previous position
        [SP + 20] = w(w[SP + 30]);
        [SP + 24] = w(w[SP + 34]);
        [SP + 28] = w(w[SP + 38]);

        [SP + 40] = h(hu[SP + 48]);
        [SP + 42] = h(hu[SP + 4a]);
        [SP + 44] = h(hu[SP + 4c]);
    }

    [SP + 24] = w((h[SP + 42] << 10) - w[entity_structure + 24]);
    [move_vector + 0] = w(w[SP + 20]);
    [move_vector + 4] = w(w[SP + 24]);
    [move_vector + 8] = w(w[SP + 28]);
    [entity_structure + 72] = h((w[entity_structure + 24] + w[move_vector + 4]) >> 10);

    return 0;
}

return -1;
////////////////////////////////



////////////////////////////////
// field_check_walkmesh_triangle_and_calculate_height
// A0 - move vector
// A1 - current pos
// A2 - entity structure
// A3 - address to store line that we can't intersect
// A4 - address of final point
// A5 - if -1 then we don't need to really calculate height of final point
//      if 00000080 then we can go only down. Simulate material 00400000.
// A6 - pointer to store material
// return -1 if we can't move, 0 otherwise.

move_vector             = A0;
current_pos             = A1;
entity_structure        = A2;
intersect_line          = A3;

walkmesh_id             = h[entity_structure + 10];
triangle_id             = h[entity_structure + 08 + walkmesh_id * 2];

walkmesh_vertex_data    = w[800af008 + walkmesh_id * 4];
walkmesh_triangle_data  = w[800aeff8 + walkmesh_id * 4];
walkmesh_material_data  = w[800aeff4];

if( triangle_id != -1 )
{
    move_x              = w[move_vector + 0];
    move_z              = w[move_vector + 8];
    start_x             = w[current_pos + 0];
    start_y             = w[current_pos + 4];
    start_z             = w[current_pos + 8];
    end_x               = (start_x + move_x) >> 10;
    end_z               = (start_z + move_z) >> 10;
    start_x_z           = ((start_x >> 10) << 10) + (start_z >> 10);
    ending_point_x_z    = (end_x << 10) + end_z;

    [A4 + 0] = h(end_x);
    [A4 + 2] = h(0);
    [A4 + 4] = h(end_z);

    if( ( ( w[entity_structure + 4] >> ( walkmesh_id + 3 ) ) & 1 ) == 0 && bu[800b16a0] == 0 )
    {
        material_mask = ffffffff;
    }
    else
    {
        material_mask = 00000000;
    }

    material_id = bu[walkmesh_triangle_data + triangle_id * e + c];
    material = w[walkmesh_material_data + material_id * 4];

    if( ( material & material_mask & 00400000 ) || ( A5 == 00000080 ) )
    {
        material_go_only_down = 1;
    }
    else
    {
        material_go_only_down = 0;
    }



    triangle_check_count = 0;

    L7b68c:	; 8007B68C
        current_triangle_id = triangle_id;

        V0 = h[walkmesh_triangle_data + triangle_id * e + 00];
        a_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

        V0 = h[walkmesh_triangle_data + triangle_id * e + 02];
        b_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

        V0 = h[walkmesh_triangle_data + triangle_id * e + 04];
        c_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

        A0 = a_x_z;
        A1 = b_x_z;
        A2 = ending_point_x_z;
        system_side_of_vector;
        if( V0 < 0 )
        {
            S2 = S2 | 1;
        }

        A0 = b_x_z;
        A1 = c_x_z;
        A2 = ending_point_x_z;
        system_side_of_vector;
        if( V0 < 0 )
        {
            S2 = S2 | 2;
        }

        A0 = c_x_z;
        A1 = a_x_z;
        A2 = ending_point_x_z;
        system_side_of_vector;
        if( V0 < 0 )
        {
            S2 = S2 | 4;
        }

        switch( S2 )
        {
            case 0: // we not cross anything
            {
                triangle_check_count = ff;
            }
            break;

            case 1:
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 06];
            }

            case 2:
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 08];
            }
            break;

            case 3:
            {
                A0 = b_x_z;
                A1 = ending_point_x_z;
                A2 = start_x_z;
                system_side_of_vector;

                if( V0 >= 0 )
                {
                    triangle_id = h[walkmesh_triangle_data + triangle_id * e + 8];
                    S2 = 2;
                }
                else
                {
                    triangle_id = h[walkmesh_triangle_data + triangle_id * e + 6];
                    S2 = 1;
                }
            }
            break;

            case 4:
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
            }
            break;

            case 5:
            {
                A0 = a_x_z;
                A1 = ending_point_x_z;
                A2 = start_x_z;
                system_side_of_vector;

                if( V0 >= 0 )
                {
                    triangle_id = h[walkmesh_triangle_data + triangle_id * e + 6];
                    S2 = 1;
                }
                else
                {
                    triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
                    S2 = 4;
                }
            }
            break;

            case 6:
            {
                A0 = c_x_z;
                A1 = ending_point_x_z;
                A2 = start_x_z;
                system_side_of_vector;

                if( V0 >= 0 )
                {
                    triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
                    S2 = 4;
                }
                else
                {
                    triangle_id = h[walkmesh_triangle_data + triangle_id * e + 8];
                    S2 = 2;
                }
            }
            break;

            case 7:
            {
                triangle_id = -1;
            }
            break;
        }

        if( triangle_id == -1 )
        {
            break;
        }

        material_id = bu[walkmesh_triangle_data + triangle_id * e + c];
        material = w[walkmesh_material_data + material_id * 4];

        [A6] = w(material & material_mask);
        type_of_unpassability = (w[A6] >> 5)

        type_of_entity = ((w[entity_structure + 0] & 00000700) >> 8);

        if( ( type_of_entity & type_of_unpassability ) || ( ( w[A6] & 10000000 ) && ( walkmesh_id == 0 ) ) )
        {
            triangle_id = -1;
        }
        else if( ( w[A6] & 00400000 ) && material_go_only_down == 0 ) // we check both triangles start and end.
        {
            A0 = h[walkmesh_triangle_data + triangle_id * e + 0];
            A1 = h[walkmesh_triangle_data + triangle_id * e + 2];
            A2 = h[walkmesh_triangle_data + triangle_id * e + 4];

            A0 = walkmesh_vertex_data + A0 * 8;
            A1 = walkmesh_vertex_data + A1 * 8;
            A2 = walkmesh_vertex_data + A2 * 8;
            A3 = A4;
            A4 = SP + 18; // address to store normal
            field_calculate_walkmesh_height;

            new_y = h[A4 + 2];

            if (new_y < (start_y >> 10)) // Y is less on top
            {
                triangle_id = -1;
            }
        }

        if (triangle_id == -1)
        {
            break;
        }

        triangle_check_count = triangle_check_count + 1;
        V0 = triangle_check_count < 20;
    8007B970	bne    v0, zero, L7b68c [$8007b68c]



    if (triangle_id != -1 && triangle_check_count != 20)
    {
        if (A5 != -1)
        {
            A0 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 0] * 8;
            A1 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 2] * 8;
            A2 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 4] * 8;
            A3 = A4; // pos
            A4 = SP + 18; // address to store normal
            field_calculate_walkmesh_height;
        }
        return 0;
    }



    if (S2 == 1)
    {
        V0 = h[walkmesh_triangle_data + current_triangle_id * e + 0];
        [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
        [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
        [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

        V0 = h[walkmesh_triangle_data + current_triangle_id * e + 2];
        [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
        [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
        [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
    }
    else if (S2 == 2)
    {
        V0 = h[walkmesh_triangle_data + current_triangle_id * e + 2];
        [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
        [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
        [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

        V0 = h[walkmesh_triangle_data + current_triangle_id * e + 4];
        [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
        [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
        [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
    }
    else if (S2 == 4)
    {
        V0 = h[walkmesh_triangle_data + current_triangle_id * e + 4];
        [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
        [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
        [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

        V0 = h[walkmesh_triangle_data + current_triangle_id * e + 0];
        [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
        [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
        [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
    }
}

return -1;
////////////////////////////////



////////////////////////////////
// field_calculate_walkmesh_height
// SP = SP - 58;
A_vec = A0;
B_vec = A1;
C_vec = A2;
P_vec = A3;
S4 = A4; // address for normal

[SP + 30] = w(h[B_vec + 0] - h[A_vec + 0]);
[SP + 34] = w(h[B_vec + 2] - h[A_vec + 2]);
[SP + 38] = w(h[B_vec + 4] - h[A_vec + 4]);
A0 = SP + 30;
A1 = SP + 10;
system_normalize_word_vector_T0_T1_T2_to_word;

[SP + 30] = w(h[C_vec + 0] - h[A_vec + 0]);
[SP + 34] = w(h[C_vec + 2] - h[A_vec + 2]);
[SP + 38] = w(h[C_vec + 4] - h[A_vec + 4]);
A0 = SP + 30;
A1 = SP + 20;
system_normalize_word_vector_T0_T1_T2_to_word;

A0 = SP + 10;
A1 = SP + 20;
A2 = S4; // normal
system_outer_product2_A0_A1_to_A2;

if (w[S4 + 4] == 0)
{
    [P_vec + 2] = h(0);
}
else
{
    [P_vec + 2] = h(hu[A_vec + 2] - (w[S4 + 0] * (h[P_vec + 0] - h[A_vec + 0]) + w[S4 + 8] * (h[P_vec + 4] - h[A_vec + 4])) / w[S4 + 4]);
}
////////////////////////////////



////////////////////////////////
// field_get_move_vector_to_move_along_with_line
// A0 - rotation;
// A1 - intersect_line;
// A2 - move_vector

intersect_line = A1;
move_vector = A2;

S1 = (c00 - A0) & fff;

A0 = h[intersect_line + c] - h[intersect_line + 4];
A1 = h[intersect_line + 8] - h[intersect_line + 0];
system_get_rotation_based_on_vector_x_y;

A0 = (0 - V0) & fff; // rotation along line that we can't intersect 

S1 = (S1 + A0) & fff;

if ((S1 - 80) >= f01)
{
    [move_vector + 0] = w(0);
    [move_vector + 4] = w(0);
    [move_vector + 8] = w(0);

    return A0;
}
else
{
    if (S1 < 800)
    {
        [SP + 10] = w(h[intersect_line + 0] - h[intersect_line + 8]);
        [SP + 14] = w(0);
        [SP + 18] = w(h[intersect_line + 4] - h[intersect_line + c]);

        A0 = A0 + 800;
    }
    else
    {
        [SP + 10] = w(h[intersect_line + 8] - h[intersect_line + 0]);
        [SP + 14] = w(0);
        [SP + 18] = w(h[intersect_line + c] - h[intersect_line + 4]);
    }

    S3 = A0 & fff;

    A0 = SP + 10;
    A1 = SP + 20;
    system_normalize_word_vector_T0_T1_T2_to_word;

    A0 = w[move_vector + 0] >> c;
    A1 = w[move_vector + 8] >> c;
    length_of_vector_by_x_y;

    [move_vector + 0] = w(w[SP + 20] * V0);
    [move_vector + 4] = w(0);
    [move_vector + 8] = w(w[SP + 28] * V0);

    return S3;
}
////////////////////////////////



////////////////////////////////
// func84054
80084054	addiu  sp, sp, $ff00 (=-$100)
80084058	sw     s6, $00f0(sp)
8008405C	addu   s6, a0, zero
80084060	sw     s7, $00f4(sp)
80084064	addu   s7, a1, zero
80084068	sw     s1, $00dc(sp)
8008406C	sll    v0, s6, $01
80084070	addu   v0, v0, s6
80084074	sll    v0, v0, $03
80084078	subu   v0, v0, s6
8008407C	lui    v1, $800b
80084080	lw     v1, $efe4(v1)
80084084	lui    a1, $800b
80084088	lw     a1, $1740(a1)
8008408C	sll    v0, v0, $02
80084090	sw     ra, $00fc(sp)
80084094	sw     fp, $00f8(sp)
80084098	sw     s5, $00ec(sp)
8008409C	sw     s4, $00e8(sp)
800840A0	sw     s3, $00e4(sp)
800840A4	sw     s2, $00e0(sp)
800840A8	sw     s0, $00d8(sp)
800840AC	addu   v0, v0, v1
800840B0	lw     s5, $0004(v0)
800840B4	bne    s6, a1, L840c8 [$800840c8]
800840B8	addu   s1, a3, zero
800840BC	ori    v0, zero, $ffff
800840C0	lui    at, $800b
800840C4	sh     v0, $cfd8(at)

L840c8:	; 800840C8
800840C8	lw     a0, $0000(s1)
800840CC	lui    v0, $0100
800840D0	and    v0, a0, v0
800840D4	bne    v0, zero, L84ab0 [$80084ab0]
800840D8	addiu  v0, zero, $ffff (=-$1)
800840DC	lw     v0, $0004(s1)
800840E0	lui    v1, $0020
800840E4	and    v0, v0, v1
800840E8	bne    v0, zero, L84ab0 [$80084ab0]
800840EC	addiu  v0, zero, $ffff (=-$1)
800840F0	lui    v0, $0001
800840F4	and    v0, a0, v0
800840F8	bne    v0, zero, L84150 [$80084150]
800840FC	nop
80084100	bne    s6, a1, L8411c [$8008411c]
80084104	ori    v0, zero, $0001
80084108	lui    v1, $800b
8008410C	lbu    v1, $16a3(v1)
80084110	nop
80084114	beq    v1, v0, L84158 [$80084158]
80084118	nop

L8411c:	; 8008411C
8008411C	lw     v0, $0010(s5)
80084120	nop
80084124	bne    v0, zero, L84158 [$80084158]
80084128	nop
A0 = S1;
func83f40;

80084134	bne    v0, zero, L84158 [$80084158]
80084138	nop
8008413C	lh     v1, $0084(s5)
80084140	lh     v0, $0026(s1)
80084144	nop
80084148	bne    v1, v0, L84158 [$80084158]
8008414C	nop

L84150:	; 80084150
80084150	j      L84ab0 [$80084ab0]
80084154	addiu  v0, zero, $ffff (=-$1)

L84158:	; 80084158
80084158	lw     v0, $0020(s1)
8008415C	addu   s0, zero, zero
80084160	sw     v0, $0090(sp)
80084164	lw     v0, $0024(s1)
80084168	addu   a0, s1, zero
8008416C	sw     v0, $0094(sp)
80084170	lw     v0, $0028(s1)
80084174	addiu  v1, sp, $0018
80084178	sw     v0, $0098(sp)
8008417C	lhu    fp, $0010(s1)

loop84180:	; 80084180
80084180	lhu    v0, $0008(a0)
80084184	addiu  a0, a0, $0002
80084188	addiu  s0, s0, $0001
8008418C	sh     v0, $0088(v1)
80084190	slti   v0, s0, $0004
80084194	bne    v0, zero, loop84180 [$80084180]
80084198	addiu  v1, v1, $0002
8008419C	addu   s0, zero, zero
800841A0	lui    a0, $7fff
800841A4	ori    a0, a0, $ffff
800841A8	addiu  v1, sp, $0018

loop841ac:	; 800841AC
800841AC	sw     s0, $0020(v1)
800841B0	sw     a0, $0000(v1)
800841B4	sw     a0, $0010(v1)
800841B8	addiu  s0, s0, $0001
800841BC	slti   v0, s0, $0004
800841C0	bne    v0, zero, loop841ac [$800841ac]
800841C4	addiu  v1, v1, $0004
800841C8	lui    v0, $800b
800841CC	lh     v0, $f028(v0)
800841D0	nop
800841D4	addiu  v0, v0, $ffff (=-$1)
800841D8	blez   v0, L84240 [$80084240]
800841DC	addu   s4, zero, zero
800841E0	addiu  s3, sp, $0048
800841E4	addiu  s2, sp, $0050
800841E8	addiu  s0, sp, $0018

loop841ec:	; 800841EC
800841EC	addu   a0, s1, zero
800841F0	addu   a1, s4, zero
800841F4	sll    v1, s4, $02
800841F8	addiu  v0, sp, $0028
800841FC	addu   v0, v0, v1
80084200	addu   a2, s0, zero
80084204	addu   a3, s2, zero
80084208	sw     s3, $0010(sp)
8008420C	jal    func7c9e8 [$8007c9e8]
80084210	sw     v0, $0014(sp)
80084214	bne    v0, zero, L84240 [$80084240]
80084218	nop
8008421C	addiu  s3, s3, $0002
80084220	addiu  s2, s2, $0010
80084224	lui    v0, $800b
80084228	lh     v0, $f028(v0)
8008422C	addiu  s4, s4, $0001
80084230	addiu  v0, v0, $ffff (=-$1)
80084234	slt    v0, s4, v0
80084238	bne    v0, zero, loop841ec [$800841ec]
8008423C	addiu  s0, s0, $0004

L84240:	; 80084240
80084240	lw     v0, $0004(s1)
80084244	nop
80084248	andi   v0, v0, $0001
8008424C	beq    v0, zero, L84260 [$80084260]
80084250	lui    v0, $7fff
80084254	ori    v0, v0, $ffff
80084258	sw     v0, $0018(sp)
8008425C	sw     v0, $0028(sp)

L84260:	; 80084260
80084260	lw     v0, $0004(s1)
80084264	nop
80084268	andi   v0, v0, $0002
8008426C	beq    v0, zero, L84280 [$80084280]
80084270	lui    v0, $7fff
80084274	ori    v0, v0, $ffff
80084278	sw     v0, $001c(sp)
8008427C	sw     v0, $002c(sp)

L84280:	; 80084280
80084280	lw     v0, $0004(s1)
80084284	nop
80084288	andi   v0, v0, $0004
8008428C	beq    v0, zero, L842a0 [$800842a0]
80084290	lui    v0, $7fff
80084294	ori    v0, v0, $ffff
80084298	sw     v0, $0020(sp)
8008429C	sw     v0, $0030(sp)

L842a0:	; 800842A0
800842A0	addu   s0, zero, zero
800842A4	addiu  v0, sp, $0018
800842A8	addu   t1, v0, zero
800842AC	addiu  t3, sp, $002c
800842B0	lh     v0, $0010(s1)
800842B4	addiu  t2, sp, $003c
800842B8	sll    v0, v0, $02
800842BC	addu   v0, v0, t1
800842C0	lw     t4, $0000(v0)

loop842c4:	; 800842C4
800842C4	addu   t0, zero, zero
800842C8	addu   a3, t2, zero
800842CC	addu   a2, t3, zero
800842D0	addu   v1, t1, zero

loop842d4:	; 800842D4
800842D4	lw     a0, $0000(v1)
800842D8	lw     a1, $0004(v1)
800842DC	nop
800842E0	slt    v0, a1, a0
800842E4	beq    v0, zero, L84314 [$80084314]
800842E8	nop
800842EC	lw     v0, $0010(v1)
800842F0	sw     a0, $0004(v1)
800842F4	sw     a1, $0000(v1)
800842F8	lw     a0, $0000(a2)
800842FC	sw     v0, $0000(a2)
80084300	lw     v0, $0020(v1)
80084304	sw     a0, $0010(v1)
80084308	lw     a0, $0000(a3)
8008430C	sw     v0, $0000(a3)
80084310	sw     a0, $0020(v1)

L84314:	; 80084314
A3 = A3 + 4;
A2 = A2 + 4;
T0 = T0 + 1;
V0 = T0 < 2;
80084324	bne    v0, zero, loop842d4 [$800842d4]
80084328	addiu  v1, v1, $0004
8008432C	addiu  s0, s0, $0001
80084330	slti   v0, s0, $0002
80084334	bne    v0, zero, loop842c4 [$800842c4]
80084338	nop

A1 = 800af028;
V0 = h[A1];
V0 = V0 - 1;

80084350	bne    s4, v0, L845e0 [$800845e0]
80084354	nop
if (S4 > 0)
{
    S0 = 0;
    A0 = SP + 18;
    V1 = S1;

    loop84368:	; 80084368
        V0 = hu[A0 + 30];
        A0 = A0 + 2;
        S0 = S0 + 1;
        [V1 + 8] = h(V0);

        V1 = V1 + 2;

        V0 = h[A1 + 0];
        V0 = V0 - 1;
        V0 = S0 < V0;
    80084388	bne    v0, zero, loop84368 [$80084368]
}

80084390	lh     a0, $0026(s1)
80084394	nop
80084398	slt    v0, a0, t4
8008439C	bne    v0, zero, L843b8 [$800843b8]
800843A0	nop
800843A4	lw     v0, $0000(s1)
800843A8	nop
800843AC	andi   v0, v0, $1800
800843B0	beq    v0, zero, L84414 [$80084414]
800843B4	nop

L843b8:	; 800843B8
800843B8	lui    v0, $800b
800843BC	lh     v0, $f028(v0)
800843C0	nop
800843C4	addiu  v0, v0, $ffff (=-$1)
800843C8	blez   v0, L84458 [$80084458]
800843CC	addu   s0, zero, zero
800843D0	addu   a2, v0, zero
800843D4	addiu  a1, sp, $0018

loop843d8:	; 800843D8
800843D8	addu   v1, a1, zero
800843DC	lw     v0, $0000(v1)
800843E0	nop
800843E4	slt    v0, v0, a0
800843E8	beq    v0, zero, L84408 [$80084408]
800843EC	nop
800843F0	addiu  s0, s0, $0001
800843F4	slt    v0, s0, a2
800843F8	bne    v0, zero, loop843d8 [$800843d8]
800843FC	addiu  a1, v1, $0004
80084400	j      L84458 [$80084458]
80084404	nop

L84408:	; 80084408
80084408	lw     v0, $0020(a1)
8008440C	j      L84458 [$80084458]
80084410	sh     v0, $0010(s1)

L84414:	; 80084414
80084414	lui    v0, $800b
80084418	lh     v0, $f028(v0)
8008441C	nop
80084420	addiu  v0, v0, $ffff (=-$1)
80084424	blez   v0, L84458 [$80084458]
80084428	addu   s0, zero, zero
8008442C	lh     a1, $0010(s1)
80084430	addu   a0, v0, zero
80084434	addiu  v1, sp, $0018

loop84438:	; 80084438
80084438	lw     v0, $0020(v1)
8008443C	nop
80084440	beq    a1, v0, L84458 [$80084458]
80084444	nop
80084448	addiu  s0, s0, $0001
8008444C	slt    v0, s0, a0
80084450	bne    v0, zero, loop84438 [$80084438]
80084454	addiu  v1, v1, $0004

L84458:	; 80084458
80084458	jal    func7ff7c [$8007ff7c]
8008445C	addu   a0, s1, zero
80084460	andi   v0, v0, $0004
80084464	beq    v0, zero, L844a4 [$800844a4]
80084468	nop
8008446C	beq    s0, zero, L844a4 [$800844a4]
80084470	nop
80084474	lui    v0, $800b
80084478	lh     v0, $f028(v0)
8008447C	lh     v1, $0010(s1)
80084480	addiu  v0, v0, $ffff (=-$1)
80084484	slt    v0, v0, v1
80084488	bne    v0, zero, L844a4 [$800844a4]
8008448C	addiu  s0, s0, $ffff (=-$1)
80084490	sll    v0, s0, $02
80084494	addu   v0, sp, v0
80084498	lw     v0, $0038(v0)
8008449C	nop
800844A0	sh     v0, $0010(s1)

L844a4:	; 800844A4
800844A4	jal    func7ff7c [$8007ff7c]
800844A8	addu   a0, s1, zero
800844AC	lw     v1, $0000(s1)
800844B0	addu   a1, v0, zero
800844B4	srl    v0, a1, $05
800844B8	srl    v1, v1, $08
800844BC	andi   v1, v1, $0007
800844C0	and    v1, v1, v0
800844C4	beq    v1, zero, L844f0 [$800844f0]
800844C8	lui    v0, $0080
800844CC	lui    v0, $800c
800844D0	lw     v0, $1b60(v0)
800844D4	nop
800844D8	bne    v0, zero, L84520 [$80084520]
800844DC	nop
800844E0	lui    a0, $8007
800844E4	addiu  a0, a0, $f2f0 (=-$d10)
800844E8	j      L84518 [$80084518]
800844EC	nop

L844f0:	; 800844F0
800844F0	and    v0, a1, v0
800844F4	beq    v0, zero, L84560 [$80084560]
800844F8	nop
800844FC	lui    v0, $800c
80084500	lw     v0, $1b60(v0)
80084504	nop
80084508	bne    v0, zero, L84520 [$80084520]
8008450C	nop
80084510	lui    a0, $8007
80084514	addiu  a0, a0, $f304 (=-$cfc)

L84518:	; 80084518
80084518	jal    func37870 [$80037870]
8008451C	addu   a1, s6, zero

L84520:	; 80084520
80084520	lui    v0, $800b
80084524	lw     v0, $1740(v0)
80084528	nop
8008452C	bne    s6, v0, L8453c [$8008453c]
80084530	ori    v0, zero, $0fff
80084534	lui    at, $800b
80084538	sh     v0, $cfd8(at)

L8453c:	; 8008453C
8008453C	lw     v0, $0024(s1)
80084540	lw     v1, $0010(s5)
80084544	nop
80084548	addu   v0, v0, v1
8008454C	j      L849ac [$800849ac]
80084550	sw     v0, $0024(s1)

loop84554:	; 80084554
80084554	lw     v0, $0000(v1)
80084558	j      L845c0 [$800845c0]
8008455C	sh     v0, $0084(s5)

L84560:	; 80084560
80084560	lw     v0, $0020(s1)
80084564	lw     a0, $0030(s1)
80084568	lw     v1, $0028(s1)
8008456C	lw     a1, $0038(s1)
80084570	addu   v0, v0, a0
80084574	addu   v1, v1, a1
80084578	sw     v0, $0020(s1)
8008457C	sw     v1, $0028(s1)
80084580	lui    v0, $800b
80084584	lh     v0, $f028(v0)
80084588	nop
8008458C	addiu  v0, v0, $ffff (=-$1)
80084590	blez   v0, L845c0 [$800845c0]
80084594	addu   s0, zero, zero
80084598	lh     a1, $0010(s1)
8008459C	addu   a0, v0, zero
800845A0	addiu  v1, sp, $0018

loop845a4:	; 800845A4
800845A4	lw     v0, $0020(v1)
800845A8	nop
800845AC	beq    a1, v0, loop84554 [$80084554]
800845B0	addiu  s0, s0, $0001
800845B4	slt    v0, s0, a0
800845B8	bne    v0, zero, loop845a4 [$800845a4]
800845BC	addiu  v1, v1, $0004

L845c0:	; 800845C0
800845C0	addiu  a1, s1, $0050
800845C4	lh     a0, $0010(s1)
800845C8	addiu  v0, sp, $0050
800845CC	sll    a0, a0, $04
800845D0	jal    system_normalize_word_vector_T0_T1_T2_to_word [$80048c24]
800845D4	addu   a0, v0, a0
800845D8	j      L845e4 [$800845e4]
800845DC	nop

L845e0:	; 800845E0
800845E0	sw     zero, $00f0(s1)

L845e4:	; 800845E4
800845E4	lui    v0, $800b
800845E8	lw     v0, $d070(v0)
800845EC	nop
800845F0	beq    v0, zero, L84614 [$80084614]
800845F4	nop
800845F8	lw     t5, $0110(sp)
800845FC	nop
80084600	sltiu  v0, t5, $0002
80084604	beq    v0, zero, L84648 [$80084648]
80084608	nop
8008460C	j      L84648 [$80084648]
80084610	sh     s7, $0084(s5)

L84614:	; 80084614
80084614	lw     t5, $0110(sp)
80084618	nop
8008461C	beq    t5, zero, L84648 [$80084648]
80084620	addiu  v1, s7, $000a
80084624	lh     v0, $0084(s5)
80084628	nop
8008462C	slt    v0, v0, v1
80084630	beq    v0, zero, L8463c [$8008463c]
80084634	ori    v0, zero, $00ff
80084638	sb     v0, $0074(s1)

L8463c:	; 8008463C
8008463C	sll    v0, s7, $10
80084640	sh     s7, $0084(s5)
80084644	sw     v0, $0024(s1)

L84648:	; 80084648
80084648	lw     v0, $0000(s1)
8008464C	lui    v1, $0004
80084650	and    v0, v0, v1
80084654	beq    v0, zero, L84670 [$80084670]
80084658	nop
8008465C	lh     v0, $00ec(s1)
80084660	nop
80084664	sll    v0, v0, $10
80084668	sw     v0, $0024(s1)
8008466C	sw     zero, $0010(s5)

L84670:	; 80084670
80084670	lw     v0, $0024(s1)
80084674	lw     v1, $0010(s5)
80084678	addu   a0, s1, zero
8008467C	addu   v0, v0, v1
80084680	jal    func7ff7c [$8007ff7c]
80084684	sw     v0, $0024(s1)
80084688	addu   a1, v0, zero
8008468C	sll    v0, fp, $10
80084690	lh     v1, $0010(s1)
80084694	sra    v0, v0, $10
80084698	beq    v1, v0, L846b0 [$800846b0]
8008469C	lui    v1, $fbff
800846A0	lw     v0, $0000(s1)
800846A4	ori    v1, v1, $ffff
800846A8	and    v0, v0, v1
800846AC	sw     v0, $0000(s1)

L846b0:	; 800846B0
800846B0	lw     v0, $0000(s1)
800846B4	lui    v1, $0400
800846B8	and    v0, v0, v1
800846BC	bne    v0, zero, L84718 [$80084718]
800846C0	lui    v0, $0042
800846C4	lh     a0, $0084(s5)
800846C8	lh     v1, $0026(s1)
800846CC	nop
800846D0	slt    v0, v1, a0
if (V0 != 0)
{
    if (A0 != V1)
    {
        800846E4	lw     v0, $0010(s5)
        800846E8	lw     v1, $001c(s5)
        800846EC	nop
        800846F0	addu   v0, v0, v1
        800846F4	sw     v0, $0010(s5)
    }

    800846F8	lw     v0, $0000(s1)
    800846FC	nop
    80084700	ori    v0, v0, $1000
    80084704	sw     v0, $0000(s1)
    80084708	lw     v0, $0010(s5)
    80084710	sw     v0, $00f0(s1)
}
else
{
    80084714	lui    v0, $0042

    L84718:	; 80084718
    80084718	and    v0, a1, v0
    8008471C	bne    v0, zero, L84728 [$80084728]
    80084720	nop
    80084724	sw     zero, $00f0(s1)

    L84728:	; 80084728
    80084728	lw     v0, $0010(s5)
    8008472C	nop
    if (V0 > 0)
    {
        [S5 + 10] = w(0);
    }

    [S1 + 0] = w(w[S1 + 0] & ffbfefff); // remove automove flag

    8008474C	lh     v0, $0084(s5)
    80084750	nop
    80084754	sll    v0, v0, $10
    80084758	sw     v0, $0024(s1)
}

[S1 + 0] = w(w[S1 + 0] & fbffffff);

80084770	lui    v0, $800b
80084774	lh     v0, $f028(v0)
80084778	nop
8008477C	addiu  v0, v0, $ffff (=-$1)
80084780	blez   v0, L847d8 [$800847d8]
80084784	addu   s0, zero, zero
80084788	lh     a2, $0026(s1)
8008478C	addu   a3, v0, zero
80084790	addiu  a0, sp, $0018

loop84794:	; 80084794
80084794	lw     a1, $0000(a0)
80084798	nop
8008479C	slt    v0, a1, a2
800847A0	beq    v0, zero, L847c8 [$800847c8]
800847A4	nop
800847A8	lhu    v0, $001a(s1)
800847AC	lw     v1, $0010(a0)
800847B0	subu   v0, a2, v0
800847B4	slt    v0, v0, v1
800847B8	beq    v0, zero, L847c8 [$800847c8]
800847BC	nop
800847C0	bne    a1, v1, L847d8 [$800847d8]
800847C4	nop

L847c8:	; 800847C8
800847C8	addiu  s0, s0, $0001
800847CC	slt    v0, s0, a3
800847D0	bne    v0, zero, loop84794 [$80084794]
800847D4	addiu  a0, a0, $0004

L847d8:	; 800847D8
800847D8	lui    a1, $800b
800847DC	addiu  a1, a1, $f028 (=-$fd8)
800847E0	lh     v0, $0000(a1)
800847E4	nop
800847E8	addiu  v0, v0, $ffff (=-$1)
800847EC	bne    s0, v0, L848d0 [$800848d0]
800847F0	nop
800847F4	lh     v0, $0010(s1)
800847F8	nop
800847FC	sll    v1, v0, $02
80084800	sll    v0, v0, $01
80084804	addu   v0, v0, s1
80084808	addu   v1, a1, v1
8008480C	lh     a0, $0008(v0)
80084810	lw     v1, $ffd0(v1)
80084814	sll    v0, a0, $03
80084818	subu   v0, v0, a0
8008481C	sll    v0, v0, $01
80084820	addu   v0, v0, v1
80084824	lb     v0, $000d(v0)
80084828	nop
8008482C	sll    a1, v0, $02
80084830	bgez   a1, L8485c [$8008485c]
80084834	addu   a0, s1, zero
80084838	lh     v0, $0026(s1)
8008483C	lhu    a0, $001a(s1)
80084840	lh     v1, $0084(s5)
80084844	subu   v0, v0, a0
80084848	addu   v1, a1, v1
8008484C	slt    v0, v0, v1
80084850	bne    v0, zero, L848d4 [$800848d4]
80084854	addu   s0, zero, zero
80084858	addu   a0, s1, zero

L8485c:	; 8008485C
8008485C	sll    v1, s6, $01
80084860	addu   v1, v1, s6
80084864	lw     v0, $0020(s1)
80084868	sll    v1, v1, $03
8008486C	sw     v0, $0000(s5)
80084870	lw     v0, $0024(s1)
80084874	subu   v1, v1, s6
80084878	sw     v0, $0004(s5)
8008487C	lw     v0, $0028(s1)
80084880	sll    v1, v1, $02
80084884	sw     v0, $0008(s5)
80084888	lui    v0, $800b
8008488C	lw     v0, $efe4(v0)
80084890	lh     a1, $0022(s1)
80084894	addu   v0, v1, v0
80084898	sw     a1, $0020(v0)
8008489C	lui    v0, $800b
800848A0	lw     v0, $efe4(v0)
800848A4	lh     a1, $0026(s1)
800848A8	addu   v0, v1, v0
800848AC	sw     a1, $0024(v0)
800848B0	lui    v0, $800b
800848B4	lw     v0, $efe4(v0)
800848B8	lh     a1, $002a(s1)
800848BC	addu   v1, v1, v0
800848C0	jal    func7ff7c [$8007ff7c]
800848C4	sw     a1, $0028(v1)
800848C8	j      L849a4 [$800849a4]
800848CC	sw     v0, $0014(s1)

L848d0:	; 800848D0
800848D0	addu   s0, zero, zero

L848d4:	; 800848D4
800848D4	lw     v0, $0090(sp)
800848D8	addiu  a0, sp, $0018
800848DC	sw     v0, $0020(s1)
800848E0	lw     v0, $0098(sp)
800848E4	addu   v1, s1, zero
800848E8	sh     fp, $0010(s1)
800848EC	sw     zero, $00f0(s1)
800848F0	sw     v0, $0028(s1)

loop848f4:	; 800848F4
800848F4	lhu    v0, $0088(a0)

L848f8:	; 800848F8
800848F8	addiu  a0, a0, $0002
800848FC	addiu  s0, s0, $0001
80084900	sh     v0, $0008(v1)
80084904	slti   v0, s0, $0004
80084908	bne    v0, zero, loop848f4 [$800848f4]
8008490C	addiu  v1, v1, $0002
80084910	lh     v1, $0084(s5)
80084914	lh     v0, $0026(s1)
80084918	nop
8008491C	beq    v1, v0, L84938 [$80084938]
80084920	nop
80084924	lw     v0, $0010(s5)
80084928	lw     v1, $001c(s5)
8008492C	nop
80084930	addu   v0, v0, v1
80084934	sw     v0, $0010(s5)

L84938:	; 80084938
80084938	lw     v0, $0010(s5)
8008493C	nop
80084940	bgez   v0, L84958 [$80084958]
80084944	nop
80084948	sw     zero, $0010(s5)
8008494C	lw     v0, $0094(sp)
80084950	nop
80084954	sw     v0, $0024(s1)

L84958:	; 80084958
80084958	lw     v0, $0020(s1)
8008495C	nop
80084960	sw     v0, $0000(s5)
80084964	lw     v0, $0024(s1)
80084968	nop
8008496C	sw     v0, $0004(s5)
80084970	lw     v0, $0028(s1)
80084974	nop
80084978	sw     v0, $0008(s5)
8008497C	sll    v0, s6, $01
80084980	addu   v0, v0, s6
80084984	sll    v0, v0, $03
80084988	subu   v0, v0, s6
8008498C	sll    v0, v0, $02
80084990	lui    v1, $800b
80084994	lw     v1, $efe4(v1)
80084998	lh     a0, $0026(s1)
8008499C	addu   v0, v0, v1
800849A0	sw     a0, $0024(v0)

L849a4:	; 800849A4
800849A4	j      L84aa4 [$80084aa4]
800849A8	addu   a0, s6, zero

L849ac:	; 800849AC
800849AC	addu   s0, zero, zero
800849B0	lw     v0, $0090(sp)
800849B4	addiu  a0, sp, $0018
800849B8	sw     v0, $0020(s1)
800849BC	lw     v0, $0098(sp)
800849C0	addu   v1, s1, zero
800849C4	sh     fp, $0010(s1)
800849C8	sw     zero, $00f0(s1)
800849CC	sw     v0, $0028(s1)

loop849d0:	; 800849D0
800849D0	lhu    v0, $0088(a0)
800849D4	addiu  a0, a0, $0002
800849D8	addiu  s0, s0, $0001
800849DC	sh     v0, $0008(v1)
800849E0	slti   v0, s0, $0004
800849E4	bne    v0, zero, loop849d0 [$800849d0]
800849E8	addiu  v1, v1, $0002
800849EC	lh     a0, $0084(s5)
800849F0	lh     v1, $0026(s1)
800849F4	nop
800849F8	slt    v0, v1, a0
800849FC	beq    v0, zero, L84a24 [$80084a24]
80084A00	nop
80084A04	beq    a0, v1, L84a58 [$80084a58]
80084A08	nop
80084A0C	lw     v0, $0010(s5)
80084A10	lw     v1, $001c(s5)
80084A14	nop
80084A18	addu   v0, v0, v1
80084A1C	j      L84a58 [$80084a58]
80084A20	sw     v0, $0010(s5)

L84a24:	; 80084A24
80084A24	lw     v0, $0010(s5)
80084A28	nop
80084A2C	blez   v0, L84a38 [$80084a38]
80084A30	lui    v1, $ffbf
80084A34	sw     zero, $0010(s5)

L84a38:	; 80084A38
80084A38	lw     v0, $0000(s1)
80084A3C	ori    v1, v1, $efff
80084A40	and    v0, v0, v1
80084A44	sw     v0, $0000(s1)
80084A48	lh     v0, $0084(s5)
80084A4C	nop
80084A50	sll    v0, v0, $10
80084A54	sw     v0, $0024(s1)

L84a58:	; 80084A58
80084A58	lw     v0, $0020(s1)
80084A5C	nop
80084A60	sw     v0, $0000(s5)
80084A64	lw     v0, $0024(s1)
80084A68	nop
80084A6C	sw     v0, $0004(s5)
80084A70	lw     v0, $0028(s1)
80084A74	addu   a0, s6, zero
80084A78	sw     v0, $0008(s5)
80084A7C	sll    v0, a0, $01
80084A80	addu   v0, v0, a0
80084A84	sll    v0, v0, $03
80084A88	subu   v0, v0, a0
80084A8C	sll    v0, v0, $02
80084A90	lui    v1, $800b
80084A94	lw     v1, $efe4(v1)
80084A98	lh     a1, $0026(s1)
80084A9C	addu   v0, v0, v1
80084AA0	sw     a1, $0024(v0)

L84aa4:	; 80084AA4
80084AA4	jal    func81268 [$80081268]
80084AA8	nop
80084AAC	addu   v0, zero, zero

L84ab0:	; 80084AB0
80084AB0	lw     ra, $00fc(sp)
80084AB4	lw     fp, $00f8(sp)
80084AB8	lw     s7, $00f4(sp)
80084ABC	lw     s6, $00f0(sp)
80084AC0	lw     s5, $00ec(sp)
80084AC4	lw     s4, $00e8(sp)
80084AC8	lw     s3, $00e4(sp)
80084ACC	lw     s2, $00e0(sp)
80084AD0	lw     s1, $00dc(sp)
80084AD4	lw     s0, $00d8(sp)
80084AD8	addiu  sp, sp, $0100
80084ADC	jr     ra 
80084AE0	nop
////////////////////////////////



////////////////////////////////
// func81aa8
if( (w[A1 + 12c] & 00001000) == 0 )
{
    return 0;
}

S0 = (((w[A1 + 20] + w[A0 + 0]) >> 10) << 10) + ((w[A1 + 28] + w[A0 + 8]) >> 10);

V1 = w[A1 + 114];
S4 = (h[V1 + 0] << 10) + h[V1 + 2];
S1 = (h[V1 + 4] << 10) + h[V1 + 6];
S2 = (h[V1 + 8] << 10) + h[V1 + a];
S3 = (h[V1 + c] << 10) + h[V1 + e];

A0 = S4;
A1 = S1;
A2 = S0;
system_side_of_vector;
if( V0 < 0 )
{
    return -1;
}

A0 = S1;
A1 = S2;
A2 = S0;
system_side_of_vector;
if( V0 < 0 )
{
    return -1;
}

A0 = S2;
A1 = S3;
A2 = S0;
system_side_of_vector;
if( V0 < 0 )
{
    return -1;
}

A0 = S3;
A1 = S4;
A2 = S0;
system_side_of_vector;
V0 = V0 >> 1f;
////////////////////////////////



////////////////////////////////
// func81594
//        A0 = S3;
//        A1 = S2 & ffff;

struct_5c = S3 = A2;

V0 = hu[S3 + 58];

800815B8	andi   v0, v0, $0040
800815BC	bne    v0, zero, L815fc [$800815fc]
800815C0	addu   s2, a0, zero
800815C4	lw     v0, $004c(s3)
800815C8	nop
800815CC	lhu    v1, $0076(v0)
800815D0	lui    v0, $0004
800815D4	div    v0, v1
800815D8	mflo   v0
800815DC	nop
800815E0	sra    v0, v0, $08
800815E4	sll    s1, v0, $05
800815E8	andi   v0, a1, $8000
800815EC	bne    v0, zero, L817c4 [$800817c4]
800815F0	andi   s0, a1, $0fff
800815F4	j      L81710 [$80081710]
800815F8	addu   a0, s0, zero

L815fc:	; 800815FC
800815FC	sll    v0, a1, $10
80081600	sra    a2, v0, $10
80081604	andi   v0, a2, $8000
80081608	bne    v0, zero, L817c4 [$800817c4]
8008160C	nop
80081610	lw     a0, $004c(s3)
80081614	nop
80081618	lw     v1, $0004(a0)
8008161C	nop
80081620	andi   v0, v1, $2000
80081624	bne    v0, zero, L816e4 [$800816e4]
80081628	lui    v0, $0002
8008162C	lui    v0, $0008
80081630	and    v0, v1, v0
80081634	bne    v0, zero, L81650 [$80081650]
80081638	lui    v0, $0004
8008163C	addu   a0, s2, zero
80081640	jal    func21e40 [$80021e40]
80081644	addu   a1, a2, zero
80081648	j      L817d0 [$800817d0]
8008164C	addiu  v0, zero, $f000 (=-$1000)

L81650:	; 80081650
80081650	lhu    v1, $0076(a0)
80081654	nop
80081658	div    v0, v1
8008165C	mflo   v0
80081660	andi   s0, a1, $0fff
80081664	addu   a0, s0, zero
80081668	sra    v0, v0, $08
80081670	sll    s1, v0, $05
func3f774; // cos

80081674	mult   v0, s1
80081678	lw     v0, $004c(s3)
8008167C	mflo   a3
80081680	lh     v1, $00f4(v0)
80081684	sra    v0, a3, $0c
80081688	mult   v0, v1
8008168C	addu   a0, s0, zero
80081690	mflo   a3
80081698	sw     a3, $000c(s2)
func3f758; // sin

8008169C	mult   v0, s1
800816A0	lw     v1, $004c(s3)
800816A4	nop
800816A8	lh     v1, $00f8(v1)
800816AC	mflo   a3
800816B0	subu   v0, zero, a3
800816B4	sra    v0, v0, $0c
800816B8	mult   v0, v1
800816BC	mflo   a3
800816C0	sw     a3, $0014(s2)
800816C4	lw     v0, $004c(s3)
800816C8	nop
800816CC	lhu    v1, $0076(v0)
800816D0	lui    v0, $0400
800816D4	div    v0, v1
800816D8	mflo   v0
800816DC	j      L817cc [$800817cc]
800816E0	sw     v0, $0018(s2)

L816e4:	; 800816E4
800816E4	and    v0, v1, v0
800816E8	bne    v0, zero, L8176c [$8008176c]
800816EC	lui    v0, $0008
800816F0	lhu    v1, $0076(a0)
800816F4	nop
800816F8	div    v0, v1
800816FC	mflo   v0
80081700	andi   s0, a1, $0fff
80081704	addu   a0, s0, zero
80081708	sra    v0, v0, $08
8008170C	sll    s1, v0, $05

L81710:	; 80081710
func3f774; // cos

80081718	mult   v0, s1
8008171C	lw     v0, $004c(s3)
80081720	mflo   a3
80081724	lh     v1, $00f4(v0)
80081728	sra    v0, a3, $0c
8008172C	mult   v0, v1
80081730	addu   a0, s0, zero
80081734	mflo   a3
8008173C	sw     a3, $000c(s2)
func3f758; // sin

80081740	mult   v0, s1
80081744	lw     v1, $004c(s3)
80081748	nop
8008174C	lh     v1, $00f8(v1)
80081750	mflo   a3
80081754	subu   v0, zero, a3
80081758	sra    v0, v0, $0c
8008175C	mult   v0, v1
80081760	mflo   a3
80081764	j      L817cc [$800817cc]
80081768	sw     a3, $0014(s2)

L8176c:	; 8008176C
8008176C	lw     v0, $012c(a0)
80081770	nop
80081774	srl    v1, v0, $0b
80081778	lui    v0, $801f
8008177C	addiu  v0, v0, $8670 (=-$7990)
80081780	andi   v1, v1, $001c
80081784	addu   v1, v1, v0
80081788	lw     v0, $0000(v1)
8008178C	nop
80081790	lw     v0, $0128(v0)
80081794	nop
80081798	subu   v0, zero, v0
8008179C	sll    v0, v0, $10
800817A0	sw     v0, $000c(s2)
800817A4	lw     v0, $0000(v1)
800817A8	nop
800817AC	lw     v0, $0130(v0)
800817B0	nop
800817B4	subu   v0, zero, v0
800817B8	sll    v0, v0, $10
800817BC	j      L817cc [$800817cc]
800817C0	sw     v0, $0014(s2)

L817c4:	; 800817C4
800817C4	sw     zero, $000c(s2)
800817C8	sw     zero, $0014(s2)

L817cc:	; 800817CC
800817CC	addiu  v0, zero, $f000 (=-$1000)

L817d0:	; 800817D0
800817D0	lw     v1, $000c(s2)
800817D4	lw     a0, $0014(s2)
800817D8	and    v1, v1, v0
800817DC	and    a0, a0, v0
800817E0	sw     v1, $000c(s2)
800817E4	sw     a0, $0014(s2)
////////////////////////////////



////////////////////////////////
// func7ac28
V0 = h[800b1660]; // base walking speed
res = A0;
rot = A2 & 0fff;

S0 = ((A1 << 4) * V0) >> c;

A0 = rot;
func3f774; // cos
[res + 0] = w(V0 * S0);

A0 = rot;
func3f758; // sin

[res + 4] = w(0);
[res + 8] = w(0 - V0 * S0);
////////////////////////////////
