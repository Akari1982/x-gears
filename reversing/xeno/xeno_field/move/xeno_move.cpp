////////////////////////////////
// func80720()
struct_5c_p = w[800aefe4];

[800c2de4] = w(ffffffff);

funca15c0(); // run 8 opcodes for non-party entities

number_of_entity = w[800ad0d4];
if( number_of_entity > 0 )
{
    entity_id = 0;
    A0 = 0;
    loop80768:	; 80080768
        struct_138 = w[struct_5c_p + entity_id * 5c + 4c];
        [struct_138 + 68] = h(h(struct_138 + 22));
        [struct_138 + 6a] = h(h(struct_138 + 26));
        [struct_138 + 6c] = h(h(struct_138 + 2a));
        entity_id = entity_id + 1;
        V0 = entity_id < number_of_entity;
    800807D8	bne    v0, zero, loop80768 [$80080768]
}

// DEBUG TEXT
if( w[800c1b60] == 0 )
{
    A0 = 8006f29c; // "EVENT CODE"
    func281b18();
}

[800aed2c] = w(0);



entity_id = 0;
number_of_entity = w[800ad0d4];
if( number_of_entity > 0 )
{
    loop80820:	; 80080820
        struct_138 = w[struct_5c_p; + entity_id * 5c + 4c];

        if( ( hu[struct_5c_p + entity_id * 5c + 58] & 0f80 ) == 0200 )
        {
            if( ( w[struct_138 + 0] & 00010001 ) == 0 )
            {
                if( ( w[struct_138 + 4] & 00000600 ) != 00000200 )
                {
                    A0 = struct_138;
                    get_current_triangle_material();
                    [struct_138 + 14] = w(V0);

                    A0 = entity_id;
                    A1 = struct_5c_p + entity_id * 5c;
                    A2 = struct_138;
                    func81c34(); // calculate move vector

                    A0 = entity_id;
                    A1 = struct_5c_p + entity_id * 5c;
                    A2 = struct_138;
                    func821cc(); // perform move
                }
            }
            else if( w[struct_138 + 4] & 01000000 )
            {
                if( ( w[struct_138 + 0] & 00010000 ) == 0 )
                {
                    if( h[struct_138 + ea] != h[struct_138 + e8] )
                    {
                        [struct_138 + ea] = h(2);
                        [struct_138 + e8] = h(2);
                        A0 = [struct_5c_p + entity_id * 5c + 4];
                        A1 = h[struct_138 + ea]; // animation id
                        func243e4(); // maybe play anim
                    }
                }
            }
            else if( w[struct_138 + 4] & 00200000 )
            {
                if( h[struct_138 + ea] != h[struct_138 + e8] )
                {
                    [struct_138 + e8] = h(h[struct_138 + ea]);
                    A0 = w[struct_5c_p + entity_id * 5c + 4];
                    A1 = h[struct_138 + ea];
                    80080984	jal    func81808 [$80081808]
                }
            }
        }

        entity_id = entity_id + 1;
        V0 = entity_id < number_of_entity;
    800809A0	bne    v0, zero, loop80820 [$80080820]
}

// DEBUG TEXT
if( w[800c1b60] == 0 )
{
    A0 = 8006f2a8; // MOV CHECK0
    func281b18;
}

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

// DEBUG TEXT
if( w[800c1b60] == 0 )
{
    A0 = 8006f2b4; // MOV CHECK1
    func281b18;
}

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
// DEBUG TEXT
if( w[800c1b60] == 0 )
{
    A0 = 8006f2c0; // MOV CHECK2
    func281b18;
}

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

// DEBUG TEXT
if( w[800c1b60] == 0 )
{
    A0 = 8006f2cc; // MOV CHECK3
    func281b18;
}
////////////////////////////////



////////////////////////////////
// func81c34()
entity_id = A0;
struct_5c = A1;
struct_138 = A2;

struct_5c_p = w[800aefe4];



// get current walkmesh triangle material
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
func7ac28();



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
        system_normalize_word_vector_T0_T1_T2_to_word();

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



follow_entity_id = bu[struct_138 + 74];
if( follow_entity_id != ff )
{
    follow_struct_138 = w[struct_5c_p + follow_entity_id * 5c + 4c];
    if( ( w[follow_struct_138 + 4] & 000000c0 ) == 000000c0 )
    {
        if( ( w[struct_138 + 134] & 00000080 ) == 0 )
        {
            A0 = c;
            A1 = 0;
            system_memory_allocate();
            [struct_138 + 110] = w(V0);
            [struct_138 + 138] = w(w[struct_138 + 138] | 00000080);
        }

        V1 = w[struct_138 + 110];
        [SP + 50] = h(hu[struct_5c_p + follow_entity_id * 5c + 50] - hu[V1 + 0]); // x rot
        [SP + 52] = h(hu[struct_5c_p + follow_entity_id * 5c + 52] - hu[V1 + 2]); // y rot
        [SP + 54] = h(hu[struct_5c_p + follow_entity_id * 5c + 54] - hu[V1 + 4]); // z rot

        [V1 + 2] = h(hu[struct_5c_p + follow_entity_id * 5c + 52]); // y rot

        S3 = w[follow_struct_138 + 20];
        S5 = w[follow_struct_138 + 28];
        S0 = h[V1 + 2]; // y rot

        S4 = w[struct_138 + 20];
        S6 = w[struct_138 + 28];

        if( ( h[struct_138 + 104] & 00008000 ) == 0 )
        {
            A0 = entity_id;
            A1 = follow_entity_id;
            get_distance_between_entities();

            V1 = w[struct_138 + 110];
            [V1 + 8] = h(V0);
        }

        A0 = S5 - S6;
        V0 = w[struct_138 + 110];
        S1 = h[V0 + 8];
        A1 = S3 - S4;
        system_get_rotation_based_on_vector_x_y();
        V0 = ((V0 << 10) >> 10) - S0;

        S0 = V0 - 800;

        A0 = S0;
        system_cos();
        [struct_138 + 40] = w(w[struct_138 + 40] + (S3 + ((V0 * S1) << 4) - S4))

        A0 = S0;
        system_sin();
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
// func821cc()
entity_id = A0;
struct_5c = A1;
struct_138 = A2;

rotation = h[struct_138 + 104];

S3 = w[struct_5c + 4];

[80065198] = w(entity_id);

if( w[struct_138 + 0] & 01000000 )
{
    return;
}



// deside if we play run or walk animation
animation_id = 1; // walk
if( ( w[struct_138 + 0] & 00004000 ) && ( hu[800af370] & 0040 ) && ( w[800ad040] == 1 ) )
{
    animation_id = 2; // run
}

// check current animation id
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



is_move = w[struct_138 + 40] | w[struct_138 + 44] | w[struct_138 + 48];

A0 = struct_138;
func83f40(); // some check
if( V0 == -1 )
{
    is_move = 1;
}

if( ( rotation & 8000 ) == 0 || is_move != 0 || ( w[struct_138 + 0] & 00040800 ) != 0 )
{
    if( ( rotation & 8000 ) == 0 )
    {
        A0 = S3;
        A1 = rotation & ffff;
        A2 = struct_5c;
        func81594();

        [SP + 10] = w(w[S3 + c] + w[struct_138 + 40]);
        [SP + 14] = w(w[S3 + 10] + w[struct_138 + 44]);
        [SP + 18] = w(w[S3 + 14] + w[struct_138 + 48]);

        [struct_138 + 106] = h(rotation);
    }
    else
    {
        [SP + 10] = w(w[struct_138 + 40]);
        [SP + 14] = w(w[struct_138 + 44]);
        [SP + 18] = w(w[struct_138 + 48]);

        rotation = hu[struct_138 + 106] & 0fff;
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
            rotation = V0 & 0fff;
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
            A3 = rotation & ffff;

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
    get_current_triangle_material;

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
