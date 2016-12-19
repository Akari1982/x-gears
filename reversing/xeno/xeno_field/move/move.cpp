////////////////////////////////
// func80720()
struct_5c_p = w[800aefe4];
number_of_entity = w[800ad0d4];



[800c2de4] = w(ffffffff);

call_run_script_8(); // run 8 opcodes for non-party entities



// store previous position
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



if( number_of_entity > 0 )
{
    entity_id = 0;
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
                    func821cc(); // check move
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
                        A0 = w[struct_5c_p + entity_id * 5c + 4];
                        A1 = h[struct_138 + ea]; // animation id
                        func243e4(); // init animation
                    }
                }
            }
            else if( w[struct_138 + 4] & 00200000 )
            {
                if( h[struct_138 + ea] != h[struct_138 + e8] )
                {
                    [struct_138 + e8] = h(h[struct_138 + ea]);
                    A0 = w[struct_5c_p + entity_id * 5c + 4];
                    A1 = h[struct_138 + ea]; // animation id
                    func81808();
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



A0 = w[800b1740];
A1 = struct_5c_p + leader_id * 5c;
A2 = w[A1 + 4c];
func8376c(); // move player



// DEBUG TEXT
if( w[800c1b60] == 0 )
{
    A0 = 8006f2b4; // MOV CHECK1
    func281b18;
}



if( number_of_entity > 0 )
{
    entity_id = 0;
    loop80a40:	; 80080A40
        if( hu[struct_5c_p + entity_id * 5c + 58] & 0f00 )
        {
            struct_138 = w[struct_5c_p + entity_id * 5c + 4c];
            if( ( w[struct_138 + 4] & 00000600 ) != 200 )
            {
                if( ( hu[struct_5c_p + entity_id * 5c + 58] & 00000f80 ) == 200 )
                {
                    if( ( w[struct_138 + 0] & 00010001 ) == 0 )
                    {
                        // if not party leader
                        if( entity_id != w[800b1740] )
                        {
                            A0 = entity_id;
                            A1 = 7fffffff;
                            A2 = struct_5c_p + entity_id * 5c;
                            A3 = struct_138;
                            A4 = 0;
                            func84054(); // perform move for all nonplayer

                            V0 = w[struct_5c_p + entity_id * 5c + 4];
                            V0 = w[V0 + 7c]; // +f4
                            if( hu[V0 + c] == 1 )
                            {
                                [struct_138 + 0] = w(w[struct_138 + 0] & f7ffffff);
                            }
                        }
                    }
                }
            }
        }

        entity_id = entity_id + 1;
        V0 = entity_id < number_of_entity;
    80080B18	bne    v0, zero, loop80a40 [$80080a40]
}



// DEBUG TEXT
if( w[800c1b60] == 0 )
{
    A0 = 8006f2c0; // MOV CHECK2
    func281b18;
}



if( ( h[800b164a] == 0 ) && ( bu[800b16a0] == 0 ) )
{
    A0 = w[800b1740]; // party leader id
    A1 = struct_5c_p + A0 * 5c;
    A2 = w[A1 + 4c];
    func82fb0(); // check collision with entity and run scripts 2 and 3 based on conditions
}



[800ad0e4] = w(1);



func80c04();



// DEBUG TEXT
if( w[800c1b60] == 0 )
{
    A0 = 8006f2cc; // MOV CHECK3
    func281b18();
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
        if( material & 00400000 ) // 00400000 - auto slide down
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

    if( material & 00400000 ) // 00400000 - auto slide down
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

if( ( w[struct_138 + 4] & 00022000 ) == 00022000 )
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

struct_164 = w[struct_5c + 4];

[80065198] = w(entity_id);

if( w[struct_138 + 0] & 01000000 )
{
    return;
}



// deside if we play run or walk animation
animation_id = 1; // walk
// something and cross button currently pressed and something.
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
        A0 = struct_164;
        A1 = rotation & ffff;
        A2 = struct_5c;
        func81594(); // calculate struct_164 + c, struct_164 + 14 (and struct_164 + 18 in one case)

        [SP + 10] = w(w[struct_164 + c] + w[struct_138 + 40]);
        [SP + 14] = w(w[struct_164 + 10] + w[struct_138 + 44]);
        [SP + 18] = w(w[struct_164 + 14] + w[struct_138 + 48]);

        [struct_138 + 106] = h(rotation);
    }
    else
    {
        [SP + 10] = w(w[struct_138 + 40]);
        [SP + 14] = w(w[struct_138 + 44]);
        [SP + 18] = w(w[struct_138 + 48]);

        rotation = hu[struct_138 + 106] & 0fff;
    }

    A0 = SP + 10; // move vector
    A1 = struct_138;
    func81aa8; // check if we in some quad

    if( V0 == 0 ) // we inside some quad
    {
        // get rotation based on movement direction
        if( w[SP + 10] != 0 || w[SP + 18] != 0 )
        {
            A0 = w[SP + 18];
            A1 = w[SP + 10];
            system_get_rotation_based_on_vector_x_y();
            rotation = (0 - V0) & 0fff;
        }

        A0 = -1; // can't move (will be changed if we move)

        walkmesh_id = h[struct_138 + 10];
        if( h[struct_138 + 8 + walkmesh_id * 2] != -1 ) // if triangle id exist
        {
            // store initial flags
            S1 = w[struct_138 + 0];
            // add passable flags from followers
            if( entity_id == w[800b1740] ) // if current entity - party leader
            {
                party_2 = w[80059ad8];
                if( party_2 != ff )
                {
                    struct_5c_p = w[800aefe4];
                    V0 = w[struct_5c_p + party_2 * 5c + 4c];
                    [struct_138 + 0] = w(w[struct_138 + 0] | (w[V0 + 0] & 00000600));
                }
                party_3 = w[80059adc];
                if( party_3 != ff )
                {
                    struct_5c_p = w[800aefe4];
                    V0 = w[struct_5c_p + party_3 * 5c + 4c];
                    [struct_138 + 0] = w(w[struct_138 + 0] | (w[V0 + 0] & 00000600));
                }
            }

            if ((w[struct_138 + 0] & 00041800) == 0 && bu[struct_138 + 74] == ff && w[800ad070] == 0)
            {
                A0 = SP + 10; // move vector
                A1 = struct_138;
                A2 = SP + 20; // address to store line that we can't intersect
                A3 = rotation & ffff;
                func7b0d4(); // modify move vector according to materials and walkmesh
                A0 = V0;
            }
            else
            {
                A0 = SP + 10; // move vector
                A1 = struct_138;
                A2 = SP + 20; // address to store line that we can't intersect
                A3 = rotation & ffff;
                func7ae28();
                A0 = V0;
            }

            // restore initial passable flags (femove any addition from followers)
            [struct_138 + 0] = w((w[struct_138 + 0] & fffff9ff) | (S1 & 00000600));
        }

        if( A0 == -1 ) // if we can't move
        {
            [struct_138 + f0] = w(00010000);
            [struct_138 + 40] = w(0);
            [struct_138 + 44] = w(0);
            [struct_138 + 48] = w(0);
            [SP + 10] = w(0);
            [SP + 14] = w(0);
            [SP + 18] = w(0);
            [struct_164 + c] = w(0);
            [struct_164 + 14] = w(0);
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
        [struct_164 + c] = w(0);
        [struct_164 + 14] = w(0);
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

    [struct_164 + c] = w(0);
    [struct_164 + 14] = w(0);
}



[struct_138 + 4] = w(w[struct_138 + 4] & ffffefff);

if( w[struct_138 + 0] & 00000800 )
{
    if( h[800b1818] == 0 )
    {
        if( h[struct_164 + 6] != h[struct_164 + 84] )
        {
            if( animation_id == 2 )
            {
                [struct_164 + 18] = w(h[struct_164 + 82] * 60);
            }
            else
            {
                [struct_164 + 18] = w(h[struct_164 + 82] * 30);
            }
        }
        else
        {
            [struct_164 + 18] = w(0);
        }
    }

    animation_id = hu[800b181a];
}
else
{
    if( h[struct_138 + 104] & 8000 )
    {
        [struct_138 + e6] = hu(animation_id);
    }

    A0 = struct_138;
    get_current_triangle_material();

    if( V0 & 00200000 )
    {
        if( ( h[struct_138 + 104] & 8000 ) && ( h[struct_138 + e8] == 6 ) )
        {
            [struct_138 + 4] = w(w[struct_138 + 4] | 00001000)
        }

        animation_id = 6;
    }
}

V1 = h[struct_138 + ea]; // animation to play with opcode
if( V1 != ff )
{
    animation_id = V1;
}

// we need to start new animation
if( h[struct_138 + e8] != animation_id )
{
    if( ( w[struct_138 + 0] & 02000000 ) == 0 )
    {
        [struct_138 + e8] = h(animation_id);

        A0 = struct_164;
        A1 = animation_id;
        A2 = struct_5c;
        func81808();
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
// func7b0d4()
// return -1 if we can't move, 0 if we move
move_vector = A0;
struct_138 = A1;
intersect_line = A2;
rotation = A3;



// check first rotation
angle1 = (rotation - 100) & 0fff;

A0 = angle1;
system_cos();
[SP + 20] = w(w[move_vector + 0] + (V0 << 6));

A0 = angle1;
system_sin();
[SP + 28] = w(w[move_vector + 8] - (V0 << 6));

A0 = SP + 20; // move vector
A1 = struct_138 + 20; // current pos
A2 = struct_138;
A3 = intersect_line; // address to store line that we can't intersect
A4 = SP + 40; // address of final point
A5 = -1; // we don't need to calculate height of final point
A6 = SP + 70; // we store material here
field_check_walkmesh_triangle_and_calculate_height();

if( V0 != -1 ) // we can move
{
    // check second rotation
    angle2 = (rotation + 100) & 0fff;

    A0 = angle2;
    system_cos();
    [SP + 20] = w(w[move_vector + 0] + (V0 << 6));

    A0 = angle2;
    system_sin();
    [SP + 28] = w(w[move_vector + 8] - (V0 << 6));

    A0 = SP + 20;
    A1 = struct_138 + 20;
    A2 = struct_138;
    A3 = intersect_line;
    A4 = SP + 40;
    A5 = -1;
    A6 = SP + 70;
    field_check_walkmesh_triangle_and_calculate_height();

    if( V0 != -1 ) // can move
    {
        // check straight
        A0 = rotation & 0fff;
        system_cos; // cos
        [SP + 20] = w(w[move_vector + 0] + (V0 << 6));

        A0 = rotation & 0fff;
        system_sin; // sin
        [SP + 28] = w(w[move_vector + 8] - (V0 << 6));

        A0 = SP + 20;
        A1 = struct_138 + 20;
        A2 = struct_138;
        A3 = intersect_line;
        A4 = SP + 40;
        A5 = -1;
        A6 = SP + 70;
        field_check_walkmesh_triangle_and_calculate_height();

        if( V0 != -1 ) // can move
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
field_get_move_vector_to_move_along_with_line();

L7b2a0:	; 8007B2A0
A0 = SP + 20;
A1 = struct_138 + 20;
A2 = struct_138;
A3 = intersect_line;
A4 = SP + 40;
A5 = 0;
A6 = SP + 70;
field_check_walkmesh_triangle_and_calculate_height();

if( V0 != -1 ) // can move
{
    // store move vector
    [SP + 30] = w(w[SP + 20]);
    [SP + 34] = w(w[SP + 24]);
    [SP + 38] = w(w[SP + 28]);

    // store new position
    [SP + 48] = h(hu[SP + 40]);
    [SP + 4a] = h(hu[SP + 42]);
    [SP + 4c] = h(hu[SP + 44]);

    start_y = h[struct_138 + 26]; // y current
    end_y = h[SP + 42]; // y calculated

    // if we do something that can bother movement
    if( ( end_y < start_y ) || ( w[SP + 70] & 00200000 ) || ( ( w[SP + 70] & 00420000 ) && ( w[struct_138 + 14] & 00420000 ) ) ||
        ( ( ( w[SP + 70] & 00420000 ) == 0 ) && ( end_y < start_y + 40 ) ) )
    {
        [SP + 50] = w((0 - w[SP + 20]) >> 8);
        [SP + 54] = w(((h[SP + 42] << 10) - w[struct_138 + 24]) >> 8);
        [SP + 58] = w((0 - w[SP + 28]) >> 8);

        A0 = SP + 50;
        A1 = SP + 60;
        system_normalize_word_vector_T0_T1_T2_to_word();

        A0 = w[SP + 20] >> 8;
        A1 = w[SP + 28] >> 8;
        length_of_vector_by_x_y();
        [SP + 20] = w((0 - V0 * w[SP + 60]) >> 4);
        [SP + 24] = w(V0 * w[SP + 64] >> 4);
        [SP + 28] = w((0 - (V0 * w[SP + 68])) >> 4);

        A0 = SP + 20;
        A1 = struct_138 + 20;
        A2 = struct_138;
        A3 = intersect_line;
        A4 = SP + 40;
        A5 = 0;
        A6 = SP + 70;
        field_check_walkmesh_triangle_and_calculate_height();

        if( V0 == -1 ) // we can't move
        {
            return -1;
        }

        [struct_138 + 0] = w(w[struct_138 + 0] | 04000000);
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

    [move_vector + 0] = w(w[SP + 20]);
    [move_vector + 4] = w((h[SP + 42] << 10) - w[struct_138 + 24]);
    [move_vector + 8] = w(w[SP + 28]);
    [struct_138 + 72] = h((w[struct_138 + 24] + w[move_vector + 4]) >> 10);

    return 0;
}

return -1;
////////////////////////////////



////////////////////////////////
// func7ae28()
// return -1 if we can't move, 0 if we move
move_vector = A0;
struct_138 = A1;
intersect_line = A2;
rotation = A3;



// check straight
A0 = rotation & 0fff;
system_cos();
[SP + 18] = w(w[move_vector + 0] + (V0 << 6));

A0 = rotation & 0fff;
system_sin();
[SP + 20] = w(w[move_vector + 8] - (V0 << 6));

A0 = SP + 18;
A1 = struct_138 + 20;
A2 = struct_138;
A3 = intersect_line;
A4 = SP + 28;
A5 = -1;
func7bca8();

if( V0 != -1 )
{
    // check first rotation
    angle1 = (rotation - 100) & 0fff;

    A0 = angle1;
    system_cos();
    [SP + 18] = w(w[move_vector + 0] + (V0 << 6));

    A0 = angle1;
    system_sin();
    [SP + 20] = w(w[move_vector + 8] - (V0 << 6));

    A0 = SP + 18;
    A1 = struct_138 + 20;
    A2 = struct_138;
    A3 = intersect_line;
    A4 = SP + 28;
    A5 = -1;
    func7bca8();

    if( V0 != 0 )
    {
        // check second rotation
        angle2 = (rotation + 100) & 0fff;

        A0 = angle2
        system_cos();
        [SP + 18] = w(w[move_vector + 0] + (V0 << 6));

        A0 = angle2;
        system_sin();
        [SP + 20] = w(w[move_vector + 8] - (V0 << 6));

        A0 = SP + 18;
        A1 = struct_138 + 20;
        A2 = struct_138;
        A3 = intersect_line;
        A4 = SP + 28;
        A5 = -1;
        func7bca8();

        if( V0 != -1 )
        {
            [SP + 18] = w(w[move_vector + 0]);
            [SP + 1c] = w(w[move_vector + 4]);
            [SP + 20] = w(w[move_vector + 8]);
            8007B274	j      L7afe0 [$8007AFE0]
        }
    }
}

[SP + 18] = w(w[move_vector + 0]);
[SP + 1c] = w(w[move_vector + 4]);
[SP + 20] = w(w[move_vector + 8]);

A0 = rotation;
A1 = intersect_line;
A2 = SP + 18;
field_get_move_vector_to_move_along_with_line();

L7afe0:	; 8007AFE0
A0 = SP + 18;
A1 = struct_138 + 20;
A2 = struct_138;
A3 = intersect_line;
A4 = SP + 28;
A5 = 0;
func7bca8();

if( V0 != -1 )
{
    if( ( w[struct_138 + 0] & 00040000 ) == 0 )
    {
        [SP + 2a] = h(hu[struct_138 + ec]);
    }
    else
    {
        if( ( h[SP + 2a] << 10 ) < w[struct_138 + 24] )
        {
            if( w[800ad070] == 0 )
            {
                return -1;
            }
        }
    }

    [move_vector + 0] = w(w[SP + 18]);
    [move_vector + 4] = w((h[SP + 2a] << 10) - w[struct_138 + 24]);
    [move_vector + 8] = w(w[SP + 20]);

    [struct_138 + 72] = h((w[struct_138 + 24] + w[move_vector + 4]) >> 10);

    return 0;
}

return -1;
////////////////////////////////



////////////////////////////////
// func8376c()
leader_id = A0;
leader_5c = A1;
leader_138 = A2;

data_ptr = w[800aefe4];

A0 = 20;
func7c350(); // get pointer to temporary memory.
S3 = V0;

leader_fin_x = (w[leader_138 + 20] + w[leader_138 + 30]) >> 10;
leader_fin_z = (w[leader_138 + 28] + w[leader_138 + 38]) >> 10;

leader_cur_y = h[leader_138 + 26];
leader_top_y = leader_cur_y - hu[leader_138 + 1a];

leader_flags0 = w[leader_138 + 0];
leader_follow_id = bu[leader_138 + 74];

[SP + 70] = w(0);
[SP + 78] = w(0);

S7 = 7fffffff;

number_of_entities = w[800ad0d4];
if( number_of_entities > 0 )
{
    entity_id = 0;

    L83878:	; 80083878
        if( entity_id != leader_id ) // don't collide with itself
        {
            data_138 = w[data_ptr + entity_id * 5c + 4c];

            if( ( w[data_138 + 0] & 00000001 ) == 0 ) // entity not disabled
            {
                [data_138 + 4] = w(w[data_138 + 4] & ffff3eff);

                if( w[data_138 + 4] & 00000080 )
                {
                    A0 = entity_id;
                    V1 = w[data_ptr + entity_id * 5c + 0];
                    A1 = w[V1 + 4]; // model parts header
                    A2 = leader_fin_x;
                    A3 = leader_fin_z;
                    A4 = SP + 40;
                    A5 = SP + 30; // normal
                    func8289c();
                    if( V0 != 0 )
                    {
                        [data_138 + 4] = w(w[data_138 + 4] & ff3fffff);
                    }

                    // DEBUG TEXT
                    if( w[800c1b60] == 0 )
                    {
                        A0 = 8006f2d8; // POLYCHECK %d
                        A1 = entity_id;
                        func37870();
                    }

                    A0 = w[SP + 40] + hu[data_138 + 1a];
                    [data_138 + 4] = w(w[data_138 + 4] | 00000100);
                    V1 = bu[leader_138 + 74];
                    80083958	bne    v1, entity_id, L83aec [$80083aec]

                    [leader_138 + 50] = w(w[SP + 30]);
                    [leader_138 + 54] = w(w[SP + 34]);
                    [leader_138 + 58] = w(w[SP + 38]);

                    [data_138 + 4] = w(w[data_138 + 4] | 00004000);
                    80083990	j      L83acc [$80083acc]
                }
                else
                {
                    if( ( w[data_138 + 0] & 00002000 ) == 0 )
                    {
                        [S3 + 0] = w(((w[data_138 + 20] + w[data_138 + 30]) >> 10) - leader_fin_x);
                        [S3 + 4] = w(hu[leader_138 + 1e] + hu[data_138 + 1e]); // solid range
                        [S3 + 8] = w(((w[data_138 + 28] + w[data_138 + 38]) >> 10) - leader_fin_z);

                        A0 = S3 + 0;
                        A1 = S3 + 10;
                        system_gte_square_of_vector();

                        V0 = (w[S3 + 10] + w[S3 + 18]) < w[S3 + 14];
                    }
                    else
                    {
                        A0 = leader_fin_x;
                        A1 = leader_fin_z;
                        A2 = data_138;
                        A3 = 0;
                        field_in_entity_quad();
                    }

                    if( V0 != 0 )
                    {
                        [data_138 + 4] = w(w[data_138 + 4] & ff3fffff);
                    }
                    else
                    {
                        if( w[leader_138 + 14] & 00400000 ) // auto slide down
                        {
                            // DEBUG TEXT
                            if( w[800c1b60] == 0 )
                            {
                                A0 = 8006f2e8; // HITOFF
                                func37870();
                            }
                        }
                        else if( ( ( w[data_138 + 0] | leader_flags0 ) & 00000080 ) == 0 ) // both entity solid
                        {
                            if( bu[800b16a0] == 0 ) // looks like this flag stops all movement
                            {
                                A0 = h[data_138 + 26];
                                [SP + 40] = w(h[data_138 + 26] - hu[data_138 + 1a]);

                                L83acc:	; 80083ACC
                                if( bu[leader_138 + 74] == entity_id )
                                {
                                    T1 = leader_flags0 & 00040800;
                                    80083AE4	beq    t1, zero, L83b34 [$80083b34]
                                }

                                L83aec:	; 80083AEC
                                if( A0 >= leader_top_y )
                                {
                                    if( leader_cur_y >= w[SP + 40] )
                                    {
                                        if( ( leader_cur_y < w[SP + 40] ) || ( w[data_138 + 4] & 00800000 ) )
                                        {
                                            L83b34:	; 80083B34
                                            S7 = w[SP + 40];

                                            [leader_138 + 40] = w(w[data_138 + 30]);
                                            [leader_138 + 44] = w(w[data_138 + 34]);
                                            [leader_138 + 48] = w(w[data_138 + 38]);
                                            [SP + 78] = w(2);

                                            if( ( leader_flags0 & 00040800 ) == 0 )
                                            {
                                                [leader_138 + 74] = b(entity_id);
                                                [SP + 70] = w(1);
                                            }

                                            [data_138 + 4] = w(w[data_138 + 4] | 00800000);

                                            [data_138 + 4] = w(w[data_138 + 4] | 00400000);
                                            80083B7C	j      L83ccc [$80083ccc]
                                        }
                                        if( ( w[data_138 + 0] & 00000010 ) == 0 ) // entity pushable
                                        {
                                            if( bu[data_138 + e3] < 30 ) // if entity stand we wait first
                                            {
                                                [data_138 + e3] = b(bu[data_138 + e3] + 2);
                                            }
                                            if( bu[data_138 + e3] >= 21 ) // and then push
                                            {
                                                // push entity but stop leader movement
                                                [data_138 + 40] = w(w[data_138 + 40] + (w[leader_138 + 30] / 4))
                                                [data_138 + 48] = w(w[data_138 + 48] + (w[leader_138 + 38] / 4))
                                                [leader_138 + 30] = w(0);
                                                [leader_138 + 34] = w(0);
                                                [leader_138 + 38] = w(0);
                                                [leader_138 + 40] = w(0);
                                                [leader_138 + 44] = w(0);
                                                [leader_138 + 48] = w(0);

                                                [data_138 + 4] = w(w[data_138 + 4] | 00400000);
                                                80083C34	j      L83ccc [$80083ccc]
                                            }
                                        }

                                        // stops movement in both entities
                                        [data_138 + 30] = w(0);
                                        [data_138 + 34] = w(0);
                                        [data_138 + 38] = w(0);
                                        [data_138 + 40] = w(0);
                                        [data_138 + 44] = w(0);
                                        [data_138 + 48] = w(0);
                                        [leader_138 + 30] = w(0);
                                        [leader_138 + 34] = w(0);
                                        [leader_138 + 38] = w(0);
                                        [leader_138 + 40] = w(0);
                                        [leader_138 + 44] = w(0);
                                        [leader_138 + 48] = w(0);
                                        [data_138 + 4] = w(w[data_138 + 4] | 00400000);
                                        80083C68	j      L83ccc [$80083ccc]
                                    }
                                }

                                A0 = w[SP + 40];
                                [data_138 + 4] = w(w[data_138 + 4] & feffffff);

                                if( leader_cur_y < A0 )
                                {
                                    [data_138 + 4] = w(w[data_138 + 4] | 00800000);

                                    if( A0 < S7 )
                                    {
                                        S7 = A0;
                                    }
                                }
                                else
                                {
                                    [data_138 + 4] = w(w[data_138 + 4] & ff7fffff);
                                }

                                L83cbc:	; 80083CBC
                                [data_138 + 4] = w(w[data_138 + 4] | 00400000);
                            }
                        }
                    }
                }
            }
        }

        L83ccc:	; 80083CCC
        entity_id = entity_id + 1;
        V0 = entity_id < number_of_entities;
    80083CE0	bne    v0, zero, L83878 [$80083878]
}

if( w[800ad070] != 0 )
{
    S7 = w[800ad06c];
    [SP + 78] = w(w[SP + 78] + 1);
    [SP + 70] = w(0);
}

if( w[SP + 70] == 0 )
{
    [leader_138 + 74] = b(ff);
}
else
{
    V1 = bu[leader_138 + 74];
    V1 = w[data_ptr + V1 * 5c + 4c];
    [V1 + 4] = w(w[V1 + 4] | 80000000 );

    if( leader_follow_id == ff )
    {
        if( ( w[leader_138 + 134] & 00000080 ) == 0 )
        {
            A0 = c;
            A1 = 0;
            system_memory_allocate();
            [leader_138 + 110] = w(V0);
            [leader_138 + 134] = w(w[leader_138 + 134] | 00000080);
        }

        V1 = bu[leader_138 + 74];
        V0 = w[leader_138 + 110];
        [V0 + 0] = h(hu[data_ptr + V1 * 5c + 50]);
        [V0 + 2] = h(hu[data_ptr + V1 * 5c + 52]);
        [V0 + 4] = h(hu[data_ptr + V1 * 5c + 54]);

        A0 = leader_id;
        A1 = bu[leader_138 + 74];
        get_distance_between_entities();

        V1 = w[leader_138 + 110];
        [V1 + 8] = h(V0);
    }
}

if( ( ( w[leader_138 + 0] & 00010000 ) == 0 ) && ( ( w[leader_138 + 4] & 00200000 ) == 0 ) ) // both flags removed in 0x19_SetPosition.
{
    A0 = leader_id;
    A1 = S7;
    A2 = leader_5c;
    A3 = leader_138;
    A4 = w[SP + 78];
    func84054();
}

V0 = w[data_ptr + leader_id * 5c + 4];
V0 = w[data_ptr + leader_id * 5c + 7c];

if( hu[V0 + c] == 1 )
{
    80083EEC	jal    func35c84 [$80035c84]

    [leader_138 + 0] = w(w[leader_138 + 0] & f7ffffff);
}

A0 = 20;
func7c374(); // return temporary memory
////////////////////////////////



////////////////////////////////
// func82fb0()
// run scripts based on leader entity/other entities interaction
leader_id = A0;
leader_5c = A1;
leader_138 = A2;

struct_5c_p = w[800aefe4];

solid_radius_8 = hu[leader_138 + 1e] + 8;
solid_radius_20 = hu[leader_138 + 1e] + 20;
leader_x = h[leader_138 + 22];
leader_y = h[leader_138 + 26];
leader_z = h[leader_138 + 2a]; // Z
leader_top_y = h[leader_138 + 26] - hu[leader_138 + 1a];
leader_rot = hu[leader_138 + 106] & 0fff;

number_of_entity = w[800ad0d4];
if( number_of_entity > 0 )
{
    entity_id = 0;
    already_talk = 0; // we call only one talk script at time
    script_priority = 7;

    L83054:	; 80083054
        script_to_call = ff;
        data_138 = w[struct_5c_p + entity_id * 5c + 4c];

        if( ( ( w[data_138 + 0] & 00000001 ) == 0 ) && ( bu[leader_138 + 74] != entity_id ) )
        {
            if( w[data_138 + 4] & 00000180 )
            {
                if( ( w[data_138 + 4] & 00000100 ) == 0 )
                {
                    [800ad43c] = w(0);
                }
                else if( ( ( hu[800c1b68] & 0020 ) == 0 ) || ( already_talk != 0 ) || ( w[data_138 + 4] & 04000000 ) )
                {
                    if( ( w[data_138 + 0] & 00a20000 ) == 0 )
                    {
                        script_to_call = 3;
                        script_priority = 4;

                        A0 = h[data_138 + 2a] - leader_z + h[data_138 + 64];
                        A1 = h[data_138 + 22] - leader_x + h[data_138 + 60];
                        [SP + 10] = w(A1);
                        [SP + 18] = w(A0);
                        system_get_rotation_based_on_vector_x_y();

                        [data_138 + 12c] = w((w[data_138 + 12c] & fffff1ff) | ((0 - V0) & 0e00));

                        if( w[800ad43c] == 0 )
                        {
                            if( w[data_138 + 0] & 08000000 )
                            {
                                [800ad43c] = w(1);

                                V1 = w[leader_5c + 4];
                                [V1 + 10] = w(0);
                            }
                        }
                    }
                }
                else if( ( w[data_138 + 0] & 00220000 ) == 0 )
                {
                    // dialogs not opened
                    if( h[800b1648] == 0 )
                    {
                        already_talk = 1;
                        script_to_call = 2; // talk script
                        script_priority = 3;

                        A0 = h[data_138 + 2a] - leader_z + h[data_138 + 64];
                        A1 = h[data_138 + 22] - leader_x + h[data_138 + 60];
                        [SP + 10] = w(A1);
                        [SP + 18] = w(A0);
                        system_get_rotation_based_on_vector_x_y();

                        [data_138 + 12c] = w((w[data_138 + 12c] & fffff1ff) | ((0 - V0) & 0e00));
                    }
                }
                else
                {
                    [800ad43c] = w(0);
                }
            }

            if( w[data_138 + 0] & 00002000 )
            {
                // y pos between top and low part of leader and entity intersect
                if( ( ( h[data_138 + 26] + h[data_138 + 62] ) >= leader_top_y ) && ( leader_y >= ( h[data_138 + 26] + h[data_138 + 62] - hu[data_138 + 1a]) ) )
                {
                    if( entity_id != leader_id )
                    {
                        A0 = leader_x;
                        A1 = leader_z;
                        A2 = data_138;
                        A3 = 10; // additional radius
                        field_in_entity_quad();
                        if( V0 == 0 )
                        {
                            if( ( ( hu[800c1b68] & 0020 ) == 0 ) || ( already_talk != 0 ) || ( w[data_138 + 4] & 04000000 ) )
                            {
                                if( ( w[data_138 + 0] & 00a20000 ) == 0 )
                                {
                                    script_to_call = 3;
                                    script_priority = 4;

                                    A0 = h[data_138 + 2a] + h[data_138 + 64] - leader_z;
                                    A1 = h[data_138 + 22] + h[data_138 + 60] - leader_x;
                                    [SP + 10] = w(A1);
                                    [SP + 18] = w(A0);
                                    system_get_rotation_based_on_vector_x_y();

                                    [data_138 + 12c] = w((w[data_138 + 12c] & fffff1ff) | ((0 - V0) & 0e00));

                                    // some debug
                                    if( w[800c1b60] == 0 )
                                    {
                                        [802859dc] = w(1);
                                    }
                                }
                            }
                            else if( ( w[data_138 + 0] & 00220000 ) == 0 )
                            {
                                // dialogs not opened
                                if( h[800b1648] == 0 )
                                {
                                    // direction to entity
                                    A0 = h[data_138 + 2a] + h[data_138 + 64] - leader_z;
                                    A1 = h[data_138 + 22] + h[data_138 + 60] - leader_x;
                                    [SP + 10] = w(A1);
                                    [SP + 18] = w(A0);
                                    system_get_rotation_based_on_vector_x_y();
                                    A0 = 0 - V0;
                                    // if direction is to this entity
                                    if( ( ( w[data_138 + 4] & 00040000 ) == 0 ) || ( ( (leader_rot - (A0 & fff)) & fff - 2bc ) >= a89 ) )
                                    {
                                        already_talk = 1;
                                        script_to_call = 2; // talk script
                                        script_priority = 3;
                                        [data_138 + 12c] = w((w[data_138 + 12c] & fffff1ff) | (((A0 >> 9) & 7) << 9));

                                        // some debug
                                        if( w[800c1b60] == 0 )
                                        {
                                            [802859dc] = w(already_talk);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                [SP + 10] = w(h[data_138 + 22] + h[data_138 + 60] - leader_x); // x vector
                [SP + 14] = w(hu[data_138 + 1e] + solid_radius_20); // solid
                [SP + 18] = w(h[data_138 + 2a] + h[data_138 + 64] - leader_z); // z vector
                A0 = SP + 10;
                A1 = SP + 20;
                system_gte_square_of_vector();

                // if square of 2d distance less than square of sum of solid and talk radius distance
                if( ( w[SP + 20] + w[SP + 28] ) < w[SP + 24] )
                {
                    // y pos between top and low part of leader and entity intersect
                    if( ( ( h[data_138 + 26] + h[data_138 + 62] ) >= leader_y_top ) && ( leader_y >= ( h[data_138 + 26] + h[data_138 + 62] - hu[data_138 + 1a] ) ) )
                    {
                        if( entity_id != leader_id )
                        {
                            // if button is pressed, no other dialogs started and ???
                            if( ( hu[800c1b68] & 0020 ) && ( already_talk == 0 ) && ( ( w[data_138 + 4] & 04000000 ) == 0 ) )
                            {
                                if( ( w[data_138 + 0] & 00220000 ) == 0 )
                                {
                                    A0 = w[SP + 18];
                                    A1 = w[SP + 10];
                                    system_get_rotation_based_on_vector_x_y();
                                    A0 = 0 - V0;
                                    // if direction is to this entity
                                    if( ( ( ( leader_rot - ( A0 & fff ) ) & fff ) - 2bc ) >= a89 )
                                    {
                                        // dialogs not opened
                                        if( h[800b1648] == 0 )
                                        {
                                            already_talk = 1;
                                            script_to_call = 2;
                                            script_priority = 3;
                                            // set rotation to this entity
                                            [data_138 + 12c] = w((w[data_138 + 12c] & fffff1ff) | (((A0 >> 9) & 7) << 9));
                                        }
                                    }
                                }
                            }
                            else if( ( w[data_138 + 0] & 00a20000 ) == 0 )
                            {
                                solid_dist8 = solid_radius_8 + hu[data_138 + 1e];
                                // if square distanse less than square solid + 8.
                                if( ( w[SP + 20] + w[SP + 28] ) < ( solid_dist8 * solid_dist8 ) )
                                {
                                    script_to_call = 3;
                                    script_priority = 4;

                                    A0 = w[SP + 18];
                                    A1 = w[SP + 10];
                                    system_get_rotation_based_on_vector_x_y();
                                    [data_138 + 12c] = w((w[data_138 + 12c] & fffff1ff) | ((0 - V0) & 0e00));
                                }
                            }
                        }
                    }
                }
            }
        }

        if( script_to_call != ff )
        {
            A0 = 0;
            loop836b4:	; 800836B4
                if( bu[data_138 + 8c + A0 * 8 + 3] == script_to_call ) // script id
                {
                    break;
                }
                A0 = A0 + 1;
                V0 = A0 < 8;
            800836CC	bne    v0, zero, loop836b4 [$800836b4]

            // if script not found
            if( A0 == 8 )
            {
                slot_id = 0;
                loop836ec:	; 800836EC
                    V1 = w[data_138 + 8c + slot_id * 8 + 4];
                    // if some script has lowest priority
                    if( ( ( V1 >> 12 ) & f ) == f )
                    {
                        if( ( ( V1 >> 16) & 1 ) == 0 )
                        {
                            A0 = entity_id;
                            A1 = script_to_call;
                            get_script_offset();
                            [data_138 + 8c + slot_id * 8 + 0] = h(V0);
                            [data_138 + 8c + slot_id * 8 + 3] = b(script_to_call);
                            [data_138 + 8c + slot_id * 8 + 4] = w((w[data_138 + 8c + slot_id * 8 + 4] & ffc3ffff) | (script_priority << 12));
                            [data_138 + 104] = h(hu[data_138 + 106] | 8000);
                            [data_138 + 106] = h(hu[data_138 + 106] | 8000);
                            break;
                        }
                    }
                    slot_id = slot_id + 1;
                    V0 = slot_id < 8;
                80083718	bne    v0, zero, loop836ec [$800836ec]
            }
        }

        entity_id = entity_id + 1;
        V0 = entity_id < number_of_entity;
    80083730	bne    v0, zero, L83054 [$80083054]
}
////////////////////////////////



////////////////////////////////
// func80c04
V1 = 800b1822;
80080C38	lh     v0, $0000(v1)
80080C3C	nop
80080C40	beq    v0, zero, L80d0c [$80080d0c]
80080C44	nop
80080C48	lui    v0, $800b
80080C4C	lw     v0, $d0d4(v0)
80080C50	nop
80080C54	blez   v0, L81234 [$80081234]
80080C58	addu   s5, zero, zero
80080C5C	addu   s1, zero, zero

loop80c60:	; 80080C60
80080C60	lui    v0, $800b
80080C64	lw     v0, $efe4(v0)
80080C68	nop
80080C6C	addu   a2, s1, v0
80080C70	lw     a0, $004c(a2)
80080C74	nop
80080C78	lw     v0, $0000(a0)
80080C7C	lui    v1, $0100
80080C80	and    v0, v0, v1
80080C84	beq    v0, zero, L80cec [$80080cec]
80080C88	nop
80080C8C	lui    v0, $800b
80080C90	lw     v0, $1740(v0)
80080C94	nop
80080C98	beq    s5, v0, L80cec [$80080cec]
80080C9C	nop
80080CA0	lhu    v0, $0058(a2)
80080CA4	nop
80080CA8	andi   v0, v0, $0020
80080CAC	bne    v0, zero, L80cec [$80080cec]
80080CB0	addu   s0, a0, zero
80080CB4	addu   s4, a2, zero
80080CB8	lw     s3, $0004(s4)
80080CBC	lh     a0, $00e6(s0)
80080CC0	lh     v0, $00e8(s0)
80080CC4	nop
80080CC8	beq    v0, a0, L80cec [$80080cec]
80080CCC	addu   v1, a0, zero
80080CD0	bgez   a0, L80cdc [$80080cdc]
80080CD4	sh     v1, $00e8(s0)
80080CD8	sh     zero, $00e8(s0)

L80cdc:	; 80080CDC
80080CDC	addu   a0, s3, zero
80080CE0	lh     a1, $00e8(s0)
80080CE4	jal    func81808 [$80081808]
80080CE8	addu   a2, s4, zero

L80cec:	; 80080CEC
80080CEC	lui    v0, $800b
80080CF0	lw     v0, $d0d4(v0)
80080CF4	addiu  s5, s5, $0001
80080CF8	slt    v0, s5, v0
80080CFC	bne    v0, zero, loop80c60 [$80080c60]
80080D00	addiu  s1, s1, $005c
80080D04	j      L81234 [$80081234]
80080D08	nop

L80d0c:	; 80080D0C
80080D0C	lui    v0, $800b
80080D10	lw     v0, $d0d4(v0)
80080D14	nop
80080D18	blez   v0, L81234 [$80081234]
80080D1C	addu   s5, zero, zero
80080D20	lui    s6, $800b
80080D24	addiu  s6, s6, $1834
80080D28	lui    fp, $800b
80080D2C	addiu  fp, fp, $09f4
80080D30	addu   s7, zero, zero

L80d34:	; 80080D34
80080D34	lui    v0, $800b
80080D38	lw     v0, $efe4(v0)
80080D3C	nop
80080D40	addu   a2, s7, v0
80080D44	lw     a0, $004c(a2)
80080D48	nop
80080D4C	lw     v0, $0000(a0)
80080D50	lui    v1, $0100
80080D54	and    v0, v0, v1
80080D58	beq    v0, zero, L8121c [$8008121c]
80080D5C	nop
80080D60	lui    v0, $800b
80080D64	lw     v0, $1740(v0)
80080D68	nop
80080D6C	beq    s5, v0, L8121c [$8008121c]
80080D70	nop
80080D74	lhu    v0, $0058(a2)
80080D78	nop
80080D7C	andi   v0, v0, $0020
80080D80	bne    v0, zero, L8121c [$8008121c]
80080D84	addu   s4, a2, zero
80080D88	addu   s0, a0, zero
80080D8C	lh     a0, $00e4(s0)
80080D90	lw     s3, $0004(s4)
80080D94	jal    get_party_slot_id [$8009ef90]
80080D98	nop
80080D9C	addu   s2, v0, zero
80080DA0	addiu  t1, zero, $ffff (=-$1)
80080DA4	beq    s2, t1, L8121c [$8008121c]
80080DA8	sll    v0, s2, $02
80080DAC	addu   s1, v0, s6
80080DB0	lw     v1, $0000(s1)
80080DB4	addu   a0, s3, zero
80080DB8	sll    v0, v1, $03
80080DBC	addu   v0, v0, v1
80080DC0	sll    v0, v0, $03
80080DC4	lui    at, $800b
80080DC8	addu   at, at, v0
80080DCC	lh     a1, $09d8(at)
80080DD0	jal    func81594 [$80081594]
80080DD4	addu   a2, s4, zero
80080DD8	lw     v1, $0000(s1)
80080DDC	ori    t1, zero, $0001
80080DE0	sll    v0, v1, $03
80080DE4	addu   v0, v0, v1
80080DE8	sll    v0, v0, $03
80080DEC	lui    at, $800b
80080DF0	addu   at, at, v0
80080DF4	lw     a2, $09c4(at)
80080DF8	lui    v0, $800b
80080DFC	lbu    v0, $16a3(v0)
80080E00	lw     a0, $0014(s0)
80080E04	bne    v0, t1, L80e24 [$80080e24]
80080E08	andi   v0, a2, $0800
80080E0C	lw     v0, $0000(s6)
80080E10	nop
80080E14	addiu  v0, v0, $0001
80080E18	andi   v0, v0, $001f
80080E1C	j      L80f30 [$80080f30]
80080E20	sw     v0, $0000(s1)

L80e24:	; 80080E24
80080E24	bne    v0, zero, L80edc [$80080edc]
80080E28	sll    v0, s2, $02
80080E2C	lw     v1, $0004(s0)
80080E30	addiu  v0, zero, $efff (=-$1001)
80080E34	and    a1, v1, v0
80080E38	lui    v0, $0042
80080E3C	and    v0, a0, v0
80080E40	bne    v0, zero, L80ed8 [$80080ed8]
80080E44	sw     a1, $0004(s0)
80080E48	lui    v0, $800c
80080E4C	lw     v0, $2de4(v0)
80080E50	addiu  t1, zero, $ffff (=-$1)
80080E54	bne    v0, t1, L80eac [$80080eac]
80080E58	nop
80080E5C	lh     v1, $0084(s3)
80080E60	lh     v0, $0026(s0)
80080E64	nop
80080E68	bne    v1, v0, L80edc [$80080edc]
80080E6C	sll    v0, s2, $02
80080E70	lh     a0, $00e8(s0)
80080E74	ori    v0, zero, $0006
80080E78	beq    a0, v0, L80ea0 [$80080ea0]
80080E7C	nop
80080E80	lh     v1, $00e6(s0)
80080E84	nop
80080E88	beq    a0, v1, L8121c [$8008121c]
80080E8C	addu   v0, v1, zero
80080E90	bgez   v1, L80f18 [$80080f18]

L80e94:	; 80080E94
80080E94	sh     v0, $00e8(s0)
80080E98	j      L80f18 [$80080f18]
80080E9C	sh     zero, $00e8(s0)

L80ea0:	; 80080EA0
80080EA0	ori    v0, a1, $1000
80080EA4	j      L8121c [$8008121c]
80080EA8	sw     v0, $0004(s0)

L80eac:	; 80080EAC
80080EAC	ori    t1, zero, $0001
80080EB0	bne    s2, t1, L80ebc [$80080ebc]
80080EB4	ori    v1, zero, $0014
80080EB8	ori    v1, zero, $000a

L80ebc:	; 80080EBC
80080EBC	lw     v0, $0000(s6)
80080EC0	nop
80080EC4	addu   v0, v0, v1
80080EC8	lw     v1, $0000(s1)
80080ECC	andi   v0, v0, $001f
80080ED0	bne    v0, v1, L8121c [$8008121c]
80080ED4	nop

L80ed8:	; 80080ED8
80080ED8	sll    v0, s2, $02

L80edc:	; 80080EDC
80080EDC	addu   v0, v0, s6
80080EE0	lw     v1, $0000(v0)
80080EE4	lw     v0, $0000(s6)
80080EE8	nop
80080EEC	bne    v1, v0, L80f34 [$80080f34]
80080EF0	andi   v0, a2, $0800
80080EF4	addiu  v0, zero, $f7ff (=-$801)
80080EF8	lw     v1, $0000(s0)
80080EFC	lhu    a0, $00e6(s0)
80080F00	and    v1, v1, v0
80080F04	sh     a0, $00e8(s0)
80080F08	sll    a0, a0, $10
80080F0C	bgez   a0, L80f18 [$80080f18]
80080F10	sw     v1, $0000(s0)
80080F14	sh     zero, $00e8(s0)

L80f18:	; 80080F18
80080F18	addu   a0, s3, zero
80080F1C	lh     a1, $00e8(s0)
80080F20	jal    func81808 [$80081808]
80080F24	addu   a2, s4, zero
80080F28	j      L8121c [$8008121c]
80080F2C	nop

L80f30:	; 80080F30
80080F30	andi   v0, a2, $0800

L80f34:	; 80080F34
80080F34	beq    v0, zero, L80f48 [$80080f48]
80080F38	nop
80080F3C	lw     v0, $0000(s0)
80080F40	j      L80f54 [$80080f54]
80080F44	ori    v0, v0, $0800

L80f48:	; 80080F48
80080F48	lw     v0, $0000(s0)
80080F4C	addiu  v1, zero, $f7ff (=-$801)
80080F50	and    v0, v0, v1

L80f54:	; 80080F54
80080F54	sw     v0, $0000(s0)
80080F58	sll    v0, s2, $02
80080F5C	addu   v0, v0, s6
80080F60	lw     v1, $0000(v0)
80080F64	nop
80080F68	sll    v0, v1, $03
80080F6C	addu   v0, v0, v1
80080F70	sll    v0, v0, $03
80080F74	lui    at, $800b
80080F78	addu   at, at, v0
80080F7C	lh     a0, $09d6(at)
80080F80	lh     v0, $00e8(s0)
80080F84	nop
80080F88	beq    v0, a0, L80fac [$80080fac]
80080F8C	addu   v1, a0, zero
80080F90	bgez   a0, L80f9c [$80080f9c]
80080F94	sh     v1, $00e8(s0)
80080F98	sh     zero, $00e8(s0)

L80f9c:	; 80080F9C
80080F9C	addu   a0, s3, zero
80080FA0	lh     a1, $00e8(s0)
80080FA4	jal    func81808 [$80081808]
80080FA8	addu   a2, s4, zero

L80fac:	; 80080FAC
80080FAC	addu   a2, zero, zero
80080FB0	sll    v0, s2, $02
80080FB4	addu   a3, v0, s6
80080FB8	lui    t0, $800b
80080FBC	addiu  t0, t0, $09da
80080FC0	addu   a1, s0, zero

loop80fc4:	; 80080FC4
80080FC4	lw     v1, $0000(a3)
80080FC8	sll    a0, a2, $01
80080FCC	sll    v0, v1, $03
80080FD0	addu   v0, v0, v1
80080FD4	sll    v0, v0, $03
80080FD8	addu   v0, v0, t0
80080FDC	addu   a0, a0, v0
80080FE0	lhu    v0, $0000(a0)
80080FE4	addiu  a2, a2, $0001
80080FE8	sh     v0, $0008(a1)
80080FEC	slti   v0, a2, $0004
80080FF0	bne    v0, zero, loop80fc4 [$80080fc4]
80080FF4	addiu  a1, a1, $0002
80080FF8	sll    a0, s2, $02
80080FFC	addu   a0, a0, s6
80081000	lw     v1, $0000(a0)
80081004	nop
80081008	sll    v0, v1, $03
8008100C	addu   v0, v0, v1
80081010	sll    v0, v0, $03
80081014	lui    at, $800b
80081018	addu   at, at, v0
8008101C	lbu    v0, $0a08(at)
80081020	nop
80081024	sh     v0, $0010(s0)
80081028	lw     v1, $0000(a0)
8008102C	nop
80081030	sll    v0, v1, $03
80081034	addu   v0, v0, v1
80081038	sll    v0, v0, $03
8008103C	addu   v0, v0, fp
80081040	lw     v0, $0000(v0)
80081044	nop
80081048	sw     v0, $0050(s0)
8008104C	lw     v1, $0000(a0)
80081050	nop
80081054	sll    v0, v1, $03
80081058	addu   v0, v0, v1
8008105C	sll    v0, v0, $03
80081060	addu   v0, v0, fp
80081064	lw     v0, $0004(v0)
80081068	nop
8008106C	sw     v0, $0054(s0)
80081070	lw     v1, $0000(a0)
80081074	nop
80081078	sll    v0, v1, $03
8008107C	addu   v0, v0, v1
80081080	sll    v0, v0, $03
80081084	addu   v0, v0, fp
80081088	lw     v0, $0008(v0)
8008108C	nop
80081090	sw     v0, $0058(s0)
80081094	lw     v1, $0000(a0)
80081098	lui    t1, $800b
8008109C	addiu  t1, t1, $09e4
800810A0	sll    v0, v1, $03
800810A4	addu   v0, v0, v1
800810A8	sll    v0, v0, $03
800810AC	addu   v0, v0, t1
800810B0	lw     v0, $0000(v0)
800810B4	nop
800810B8	sw     v0, $000c(s3)
800810BC	lw     v1, $0000(a0)
800810C0	nop
800810C4	sll    v0, v1, $03
800810C8	addu   v0, v0, v1
800810CC	sll    v0, v0, $03
800810D0	addu   v0, v0, t1
800810D4	lw     v0, $0004(v0)
800810D8	nop
800810DC	sw     v0, $0010(s3)
800810E0	lw     v1, $0000(a0)
800810E4	nop
800810E8	sll    v0, v1, $03
800810EC	addu   v0, v0, v1
800810F0	sll    v0, v0, $03
800810F4	addu   v0, v0, t1
800810F8	lw     v0, $0008(v0)
800810FC	nop
80081100	sw     v0, $0014(s3)
80081104	lw     v1, $0000(a0)
80081108	nop
8008110C	sll    v0, v1, $03
80081110	addu   v0, v0, v1
80081114	sll    v0, v0, $03
80081118	lui    at, $800b
8008111C	addu   at, at, v0
80081120	lh     v0, $09cc(at)
80081124	nop
80081128	sw     v0, $0020(s4)
8008112C	lw     v1, $0000(a0)
80081130	nop
80081134	sll    v0, v1, $03
80081138	addu   v0, v0, v1
8008113C	sll    v0, v0, $03
80081140	lui    at, $800b
80081144	addu   at, at, v0
80081148	lh     v0, $09ce(at)
8008114C	nop
80081150	sw     v0, $0024(s4)
80081154	lw     v1, $0000(a0)
80081158	nop
8008115C	sll    v0, v1, $03
80081160	addu   v0, v0, v1
80081164	sll    v0, v0, $03
80081168	lui    at, $800b
8008116C	addu   at, at, v0
80081170	lh     v1, $09d0(at)
80081174	lw     v0, $0020(s4)
80081178	nop
8008117C	sll    v0, v0, $10
80081180	sw     v1, $0028(s4)
80081184	sw     v0, $0000(s3)
80081188	sw     v0, $0020(s0)
8008118C	lw     v0, $0024(s4)
80081190	nop
80081194	sll    v0, v0, $10
80081198	sw     v0, $0004(s3)
8008119C	sw     v0, $0024(s0)
800811A0	lw     v0, $0028(s4)
800811A4	nop
800811A8	sll    v0, v0, $10
800811AC	sw     v0, $0008(s3)
800811B0	sw     v0, $0028(s0)
800811B4	lw     v1, $0000(a0)
800811B8	nop
800811BC	sll    v0, v1, $03
800811C0	addu   v0, v0, v1
800811C4	sll    v0, v0, $03
800811C8	lui    at, $800b
800811CC	addu   at, at, v0
800811D0	lhu    v0, $09d4(at)
800811D4	nop
800811D8	sh     v0, $0084(s3)
800811DC	lw     v1, $0000(a0)
800811E0	nop
800811E4	sll    v0, v1, $03
800811E8	addu   v0, v0, v1
800811EC	sll    v0, v0, $03
800811F0	lui    at, $800b
800811F4	addu   at, at, v0
800811F8	lhu    v0, $09d8(at)
800811FC	nop
80081200	sh     v0, $0106(s0)
80081204	sh     v0, $0104(s0)
80081208	lw     v0, $0000(a0)
8008120C	nop
80081210	addiu  v0, v0, $ffff (=-$1)
80081214	andi   v0, v0, $001f
80081218	sw     v0, $0000(a0)

L8121c:	; 8008121C
8008121C	lui    v0, $800b
80081220	lw     v0, $d0d4(v0)
80081224	addiu  s5, s5, $0001
80081228	slt    v0, s5, v0
8008122C	bne    v0, zero, L80d34 [$80080d34]
80081230	addiu  s7, s7, $005c

L81234:	; 80081234
////////////////////////////////
