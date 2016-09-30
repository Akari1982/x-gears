////////////////////////////////
// func24330()
// called from script during initing
S5 = A0;
S3 = A1; // clut x
S4 = A2; // clut y
S0 = A3; // tx
S1 = A4; // ty
S2 = A5;

A0 = 164;
A1 = 0;
system_memory_allocate();
[V0 + 86] = h(164);

A0 = V0;
A1 = S5; // offset 2dsprite_1 block in field data
A2 = S3; // clut x
A3 = S4; // clut y
A4 = S0; // tx
A5 = S1; // ty
A6 = S2;
func24168();

return V0;
////////////////////////////////



////////////////////////////////
// func24168()
struct_164 = A0;
sprite_pack = A1;
S5 = A2; // clut x
S6 = A3; // clut y
S3 = A4; // tx
S4 = A5; // ty

A0 = struct_164;
func23680(); // init default

A0 = struct_164;
func23814();

A0 = struct_164;
A1 = 1000;
func21e60();

[struct_164 + 3c] = w((w[struct_164 + 3c] & fffffffc) | 00000001);
[struct_164 + 40] = w(w[struct_164 + 40] & fffe1fff); // doesn't affect anything because it was inited with 0.
[struct_164 + 48] = w(sprite_pack);

if( bu[80058810 + 3d] != 0 )
{
    [struct_164 + a8] = w(w[struct_164 + a8] & fffffffe);
    A0 = w[struct_164 + 7c];
    [A0 + 8] = w(0);
    [A0 + c] = h(0);
}
else
{
    [struct_164 + a8] = w(w[struct_164 + a8] | 00000001);
    A0 = w[struct_164 + 7c];
    [A0 + 18] = w(0);
}

[struct_164 + 6c] = w(struct_164);

V1 = w[GP + 48] & 000f;
[struct_164 + 3c] = w((((w[struct_164 + 3c] & ff0fffff) | (V1 << 14)) & fff0ffff) | (V1 << 10));

sprite_part_1 = sprite_pack + w[sprite_pack + 8];
A0 = ((hu[sprite_part_1 + 0] >> 9) & 3f) * 18;
A1 = 0;
system_memory_allocate();
V1 = w[struct_164 + 20];
[V1 + 2c] = w(V0);
[V1 + 30] = w(V0);

V0 = w[struct_164 + 24];
[V0 + 4] = h(S3); // tx
[V0 + 6] = h(S4); // ty
[V0 + 8] = h(S5); // clut x
[V0 + a] = h(S6); // clut y

A0 = struct_164;
A1 = sprite_pack;
func22124();

V0 = w[struct_164 + 24];
V1 = w[V0 + 10]; // pointer to sprite data 0.
[struct_164 + 60] = w(V1 + 2 + (hu[V1 + 0] & 3f) * 2); // pointer to 1st animation

A0 = struct_164;
A1 = 0; // animation id
func243e4();

return struct_164;
////////////////////////////////



////////////////////////////////
// func23680()
struct_164 = A0;

V0 = w[80058810 + 28] + 1;
V1 = V0 << e;
[struct_164 + 1c] = w((V0 * V1 * h[struct_164 + 82]) >> c);

[struct_164 + 2b] = b(2d);
[struct_164 + 30] = h(0000);
[struct_164 + 32] = h(0000);
[struct_164 + 34] = h(0000);
[struct_164 + 3a] = h(0000);
[struct_164 + 3c] = w(00000000);
[struct_164 + 40] = w(00000000);
[struct_164 + 44] = w(00000000);
[struct_164 + 50] = w(00000000);
[struct_164 + 64] = w(00000000);
[struct_164 + 68] = w(00000000);
[struct_164 + 6c] = w(00000000);
[struct_164 + 70] = w(00000000);
[struct_164 + 80] = h(0000);
[struct_164 + 84] = h(0000);
[struct_164 + 8c] = b(10);
[struct_164 + a8] = w(00000000);
[struct_164 + ac] = w(00020000);
[struct_164 + b0] = w(00000000);
////////////////////////////////



////////////////////////////////
// func23814()
struct_164 = A0;

[struct_164 + 20] = w(struct_164 + b4);
[struct_164 + 24] = w(struct_164 + 110);
[struct_164 + 7c] = w(struct_164 + f4);

V1 = w[struct_164 + 20];
[V1 + 0] = h(0);
[V1 + 2] = h(0);
[V1 + 4] = h(0);
[V1 + 2c] = w(0);
[V1 + 34] = w(struct_164 + 124);
[V1 + 38] = w(0);
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
// func22124()
struct_164 = A0;
sprite_pack = A1;

if( sprite_pack != 0 )
{
    data110 = w[struct_164 + 24];

    if( sprite_pack != w[struct_164 + 44] )
    {
        A0 = data110;
        A1 = sprite_pack;
        A2 = (hu[data110 + 6] << 10) | hu[data110 + 4]; // tx ty
        A3 = (hu[data110 + a] << 10) | hu[data110 + 8]; // clut x clut y
        func22084();

        [struct_164 + 44] = w(sprite_pack);
        [struct_164 + 3c] = w(w[struct_164 + 3c] | 40000000);
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
            V0 = w[struct_164 + 7c];
            [data110 + 4] = w(w[V0 + e]); // tx
        }
    }
}
////////////////////////////////



////////////////////////////////
// func22084()
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
// func243e4()
struct_164 = A0;
animation_id = A1;

data110 = w[struct_164 + 24];

if( w[struct_164 + 48] == 0 ) // sprite pack dont exist
{
    [struct_164 + 64] = w(0);
    return;
}

if( w[struct_164 + 44] == w[struct_164 + 48] )
{
    [struct_164 + b0] = w(w[struct_164 + b0] & fffffbff);
}
else
{
    [struct_164 + b0] = w(w[struct_164 + b0] | 00000400);
}

if( animation_id < 0 )
{
    A0 = struct_164;
    A1 = w[struct_164 + 4c];
    func22124();

    if( bu[80058810 + 3d] != 0 )
    {
        A0 = w[data110 + 0];
        // set some default texture x and y
        if( (hu[A0 + 0] >> f) == 0 )
        {
            [data110 + 4] = h(0300);
            [data110 + 6] = h(0100);
        }
    }
}
else
{
    A0 = struct_164;
    A1 = w[struct_164 + 48];
    func22124();

    if( bu[80058810 + 3d] != 0 )
    {
        dataf4 = w[struct_164 + 7c];
        [data110 + 4] = w(w[dataf4 + e]);
    }
}

[struct_164 + af] = b(animation_id);

if( animation_id < 0 )
{
    animation_id = 0 NOR animation_id; // invert bits
}

[struct_164 + 40] = w(w[struct_164 + 40] | 00100000);


sprite_data_0 = w[data110 + 10];

A0 = struct_164;
A1 = sprite_data_0 + hu[sprite_data_0 + 2 + animation_id * 2];
[struct_164 + 58] = w(A1);
func233b8();

A0 = struct_164;
A1 = h[struct_164 + 80];
func22218();
////////////////////////////////



////////////////////////////////
// func233b8()
struct_164 = A0;
animation_data = A1;

[struct_164 + 54] = w(animation_data + 4 + hu[animation_data + 4]);
[struct_164 + 58] = w(animation_data);
[struct_164 + 64] = w(animation_data + 2 + hu[animation_data + 2]);
[struct_164 + a8] = w((w[struct_164 + a8] & ffcfffff) | ((hu[animation_data + 0] & 0003) << 14));

A0 = bu[animation_data + 0] >> 2;
if( A0 & 20 )
{
    A0 = A0 | ffffffc0;
}
V1 = A0 << a;
V0 = w[80058810 + 28] + 1;
A0 = ((V0 * V0 * h[struct_164 + 82]) >> c) * V1;
V0 = 10000 / ((w[struct_164 + ac] >> 9) & fff);
[struct_164 + 1c] = w((((V0 * V0) >> 8) * A0) >> 8);

if( ((hu[animation_data + 0] >> b) & 0001) == 0 )
{
    [struct_164 + c] = w(0);
    [struct_164 + 10] = w(0);
    [struct_164 + 14] = w(0);
    [struct_164 + 18] = w(0);
}

datab4 = w[struct_164 + 20];
if( datab4 != 0 )
{
    if( ( ( hu[animation_data + 0] >> c ) & 0001 ) == 0 )
    {
        [datab4 + 0] = h(0);
        [datab4 + 2] = h(0);
        [datab4 + 4] = h(0);

        A0 = struct_164;
        func21eec(); // calculate matrix
    }

    if( bu[80058810 + 3d] != 0 )
    {
        if( ( ( hu[animation_data + 0] >> d ) & 0001 ) == 0 )
        {
            A0 = struct_164;
            A1 = w[80058810 + 38];
            func21e60;
        }

        A0 = struct_164;
        func21eec(); // calculate matrix
    }

    if( ( w[struct_164 + 3c] & 00000003 ) == 00000001 )
    {
        [datab4 + 3c] = b(0);
        [datab4 + 3d] = b(0);

        if( ( w[struct_164 + 40] & 00100000 ) == 0 )
        {
            if( w[datab4 + 34] != 0 )
            {
                A0 = struct_164;
                func2332c(); // init 0x8 items in +124 with 0
            }
        }
    }
}

[struct_164 + 30] = h(0);
[struct_164 + 8c] = b(10);
[struct_164 + 9e] = h(0001);
[struct_164 + a8] = w(w[struct_164 + a8] & fffff801);
[struct_164 + a8] = w((w[struct_164 + a8] & cfffffff & f03fffff) | 0001f800 | 20000000);

V1 = w[struct_164 + 7c];
if( V1 != 0 )
{
    if( w[struct_164 + a8] & 00000001 )
    {
        [V1 + 0] = w(0);
        [V1 + 4] = w(0);
        [V1 + c] = h(0)
    }
}
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
// func21eec()
struct_164 = A0;

if( ( w[struct_164 + 40] & 00000001 ) == 0 )
{
    A0 = w[struct_164 + 20]; // rot data
    A1 = A0 + c;
    func3f5e0(); // calculate rotation matrix

    V0 = w[struct_164 + 20];
    [SP + 20] = w(h[V0 + 6]);
    [SP + 24] = w(h[V0 + 8]);
    [SP + 28] = w(h[V0 + a]);

    A0 = w[struct_164 + 20] + c; // rot matrix
    A1 = SP + 20;
    func495f4(); // scaled matrix (column)
}
else
{
    A1 = 80018614; // identity matrix
    [SP + 60] = w(w[A1 + 0]);
    [SP + 64] = w(w[A1 + 4]);
    [SP + 68] = w(w[A1 + 8]);
    [SP + 6с] = w(w[A1 + с]);
    [SP + 70] = w(w[A1 + 10]);
    [SP + 74] = w(w[A1 + 14]);
    [SP + 78] = w(w[A1 + 18]);
    [SP + 7c] = w(w[A1 + 1c]);

    V0 = w[struct_164 + 20];
    [SP + 30] = w(h[V0 + 6]);
    [SP + 34] = w(h[V0 + 8]);
    [SP + 38] = w(h[V0 + a]);

    A0 = SP + 60;
    A1 = SP + 30;
    func495f4(); // scaled matrix (column)

    A0 = w[struct_164 + 20];
    A1 = SP + 40;
    func3f5e0(); // calculate rotation matrix

    A0 = SP + 40;
    A1 = SP + 60;
    A2 = w[struct_164 + 20] + c;
    system_gte_matrix_multiplication();
}

if( hu[struct_164 + 3a] != 0 )
{
    [SP + 20] = w(hu[struct_164 + 3a] >> 1);
    [SP + 24] = w(hu[struct_164 + 3a] >> 1);
    [SP + 28] = w(hu[struct_164 + 3a] >> 1);

    A0 = w[struct_164 + 20] + c;
    A1 = SP + 20;
    func49c74(); // scaled matrix (row)
}
////////////////////////////////



////////////////////////////////
// func3f5e0()
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
// func495f4()
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
// func49c74()
[A0 + 0] = h((h[A0 + 0] * w[A1 + 0]) >> c);
[A0 + 2] = h((h[A0 + 2] * w[A1 + 4]) >> c);
[A0 + 4] = h((h[A0 + 4] * w[A1 + 8]) >> c);
[A0 + 6] = h((h[A0 + 6] * w[A1 + 0]) >> c);
[A0 + 8] = h((h[A0 + 8] * w[A1 + 4]) >> c);
[A0 + a] = h((h[A0 + a] * w[A1 + 8]) >> c);
[A0 + c] = h((h[A0 + c] * w[A1 + 0]) >> c);
[A0 + e] = h((h[A0 + e] * w[A1 + 4]) >> c);
[A0 + 10] = h((h[A0 + 10] * w[A1 + 8]) >> c);

return A0;
////////////////////////////////



////////////////////////////////
// func22218()
struct_164 = A0;
data80 = A1;

[struct_164 + 80] = h(data80);

animation_data = w[struct_164 + 58];

T0 = (w[struct_164 + a8] >> 11) & 7;

if( ( data80 + 0400 ) & 1 )
{
    [struct_164 + ac] = w(w[struct_164 + ac] | 00000010); // invert offset x
}
else
{
    [struct_164 + ac] = w(w[struct_164 + ac] & ffffffef);
}

if( w[struct_164 + 48] == 0 ) // sprite pack pointer
{
    return;
}

V1 = (w[struct_164 + a8] >> 14) & 3;
if( V1 == 0 ) // sprite with two directions (left right)
{
    if( ( ( data80 + 400 ) & fff ) < 801 )
    {
        [struct_164 + ac] = w(w[struct_164 + ac] & ffffffef);
    }
    else
    {
        [struct_164 + ac] = w(w[struct_164 + ac] | 00000010); // invert offset x
    }

    [struct_164 + 54] = w(animation_data + 4 + hu[animation_data + 4]);
    [struct_164 + 5c] = w(animation_data + 6);
    [struct_164 + a8] = w(w[struct_164 + a8] & fff1ffff);
}
else if( V1 == 1 )
{
    A3 = ( ( data80 + 600 ) >> a ) & 3;
    if( A3 >= 3 )
    {
        [struct_164 + 54] = w[animation_data + 6 + hu[animation_data + 6]];
        [struct_164 + ac] = w(w[struct_164 + ac] | 00000010); // invert offset x
    }
    else
    {
        [struct_164 + 54] = w(animation_data + 4 + A3 * 2 + hu[animation_data + 4 + A3 * 2]);
        [struct_164 + ac] = w(w[struct_164 + ac] & ffffffef);
    }
    [struct_164 + a8] = w((w[struct_164 + a8] & fff1ffff) | ((A3 & 7) << 11));
}
else if( V1 == 2 )
{
    A3 = ((data80 + 500) >> 9) & 7;
    if( A3 < 5 )
    {
        [struct_164 + 54] = w(animation_data + 4 + A3 * 2 + hu[animation_data + 4 + A3 * 2]);
        [struct_164 + ac] = w(w[struct_164 + ac] & ffffffef);
    }
    else
    {
        A3 = (A3 - 5) XOR 3;
        [struct_164 + 54] = w(animation_data + 4 + A3 * 2 + hu[animation_data + 4 + A3 * 2]);
        [struct_164 + ac] = w(w[struct_164 + ac] | 00000010); // invert offset x
    }
    [struct_164 + a8] = w((w[struct_164 + a8] & fff1ffff) | ((A3 & 7) << 11));
}

// if direction animation id changed
if( T0 != ( ( w[struct_164 + a8] >> 11 ) & 7 ) )
{
    S0 = h[struct_164 + 9e];

    [struct_164 + a8] = w((w[struct_164 + a8] | 0001f800) & f03fffff);

    A0 = struct_164;
    A1 = w[struct_164 + 64];
    [struct_164 + 64] = w(animation_data + 2 + hu[animation_data + 2]);
    A2 = (w[struct_164 + a8] >> 16) & 3f; // 0x0fc00000
    func224f0();

    [struct_164 + 9e] = h(S0);
}

V1 = w[struct_164 + ac];
V0 = ((V1 >> 5) & 1) XOR ((V1 >> 4) & 1);
[struct_164 + 3c] = w((w[struct_164 + 3c] & fffffff7) | (V0 << 3));
////////////////////////////////



////////////////////////////////
// func224f0()
struct_164 = S1 = A0;
S4 = A1; // pointer to start of sprite sequence data.
S5 = A2; // +a8 0x0fc00000 flags

loop2251c:	; 8002251C
    A2 = w[struct_164 + 64];
    A0 = A2 + 1;
    if( ( A2 == S4 ) && ( ( ( w[struct_164 + a8] >> 16 ) & 3f ) == S5 ) )
    {
        return;
    }

    S2 = bu[A2];

    // opcode size 8004f2e4 + 80
    // 80 01010101010101010101010101010101
    // 90 01010101010101010101010101010101
    // a0 02020202020202020202020202020202
    // b0 02020202020202020202020202020202
    // c0 02020202020202020303030303030303
    // d0 03030303030303030303030303030303
    // e0 03030303030303030303030303030303
    // f0 03040404040404040404040404040404

    V1 = S2;
    if( V1 > 80 )
    {
        if( V1 == 87 || V1 == 86 )
        {
            if( A2 == S4 )
            {
                return;
            }

            [struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + S2]); // move pointer by opcode size
            800227D0	j      loop2251c [$8002251c]
        }
        if( V1 == b3 ) // set frame
        {
            [struct_164 + a8] = w((w[struct_164 + a8] & fffe07ff) | ((b[A2 + 1] & 3f) << b)));

            [struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + S2]); // move pointer by opcode size
            800227D0	j      loop2251c [$8002251c]
        }
        if( V1 == be )
        {
            A0 = (w[struct_164 + ac] & ffffffdf) | ((hu[A2 + 1] >> 4) & 0020);
            [struct_164 + 3c] = w((w[struct_164 + 3c] & fffffff7) | ((((A0 >> 5) & 1) XOR ((A0 >> 4) & 1)) << 3));
            [struct_164 + ac] = w(A0);

            frame_id = hu[A2 + 1] & 1ff;
            if( hu[struct_164 + 34] != frame_id )
            {
                A0 = struct_164;
                A1 = frame_id;
                func1d134;
            }

            [struct_164 + 9e] = h(hu[struct_164 + 9e] + 1 + (hu[A2 + 1] >> b) & f);

            [struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + S2]); // move pointer by opcode size
            800227D0	j      loop2251c [$8002251c]
        }

        if( V1 >= 88 )
        {
            V0 == V1 < b4;
            if( V0 == 0 )
            {
                if( V1 == e2 )
                {
                    A0 = struct_164;
                    A1 = A2 + 3;
                    func21b58;

                    [struct_164 + 64] = w(w[struct_164 + 64] + h[A2 + 1]);
                    8002277C	j      loop2251c [$8002251c]
                }

                800226C0	j      L227b8 [$800227b8]
            }

            if( V1 == 97 )
            {
                if( A2 == S4 )
                {
                    return;
                }

                [struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + S2]); // move pointer by opcode size
                800227D0	j      loop2251c [$8002251c]
            }

            800226A4	j      L227b8 [$800227b8]
            800226A8	nop
        }

        80022660	slti   v0, v1, $0080
        80022664	bne    v0, zero, L227b8 [$800227b8]

        8002266C	slti   v0, v1, $0083
        80022670	bne    v0, zero, L227d8 [$800227d8]

        80022680	j      L227b8 [$800227b8]
        80022684	nop
    }

    [struct_164 + 64] = w(A0);
    if( V1 >= 10 )
    {
        V0 = V1 < 20;
        80022578	beq    v0, zero, L225b8 [$800225b8]


        frame_data_id = (w[struct_164 + a8] >> b) & 3f;
        [struct_164 + a8] = w((w[struct_164 + a8] & fffe07ff) | (((frame_data_id + 1) & 3f) << b));

        A0 = struct_164;
        func22bcc;

        800225B0	j      L225dc [$800225dc]
    }

A1 = hu[struct_164 + 34] + 1;
8002256C	j      L225d0 [$800225d0]

L225b8:	; 800225B8
800225B8	sltiu  v0, v1, $0030
800225BC	beq    v0, zero, L225e0 [$800225e0]

A1 = hu[struct_164 + 34] - 1;


L225d0:	; 800225D0
A0 = struct_164;
func1d134;

L225dc:	; 800225DC
800225D8	andi   v0, s2, $000f
800225DC	addiu  s3, v0, $0001

L225e0:	; 800225E0
800225E0	sltiu  v0, s2, $0040
800225E8	lui    a2, $f03f
if( V0 != 0 )
{
    800225EC	andi   v0, s2, $000f
    800225F0	addiu  s3, v0, $0001
}

800225F4	ori    a2, a2, $ffff
800225F8	lw     v0, $00a8(struct_164)
800225FC	lhu    v1, $009e(struct_164)
80022600	and    a1, v0, a2
80022604	srl    v0, v0, $16
80022608	andi   v0, v0, $003f
8002260C	addiu  v0, v0, $0001
80022610	andi   v0, v0, $003f
80022614	sll    a0, v0, $16
80022618	or     a1, a1, a0
8002261C	addu   v1, v1, s3
80022620	sh     v1, $009e(struct_164)
80022624	bne    v0, zero, loop2251c [$8002251c]
80022628	sw     a1, $00a8(struct_164)
8002262C	and    v1, a1, a2
80022630	srl    v0, a1, $16
80022634	andi   v0, v0, $003f
80022638	addiu  v0, v0, $ffff (=-$1)
8002263C	andi   v0, v0, $003f
80022640	sll    v0, v0, $16
80022644	or     v1, v1, v0
80022648	j      loop2251c [$8002251c]
8002264C	sw     v1, $00a8(struct_164)

L227b8:	; 800227B8
[struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + S2]); // move pointer by opcode size
800227D0	j      loop2251c [$8002251c]

L227d8:	; 800227D8
////////////////////////////////



////////////////////////////////
// func22bcc
struct = A0;

V1 = (w[struct + a8] >> b) & 3f;
V0 = w[struct + 54];
frame_id = hu[V0 + V1 * 2];

if( frame_id & 0200 )
{
    [struct + ac] = w(w[struct + ac] | 00000020);
}
else
{
    [struct + ac] = w(w[struct + ac] & ffffffdf);
}

V1 = w[struct + ac];
[struct + 3c] = w((w[struct + 3c] & fffffff7) | ((((V1 >> 5) & 1) XOR ((V1 >> 4) & 1)) << 3));

A0 = struct;
A1 = frame_id & 01ff;
func1d134;
////////////////////////////////



////////////////////////////////
// func1d134
S0 = A0;
frame_id = A1;

8001D148	lw     v0, $003c(s0)
8001D14C	ori    v1, zero, $0001
8001D150	andi   v0, v0, $0003
8001D154	beq    v0, v1, L1d164 [$8001d164]

8001D160	sh     zero, $0034(s0)
return;

L1d164:	; 8001D164
8001D164	lw     a0, $0040(s0)
8001D168	lui    v0, $0010
8001D16C	and    v0, a0, v0
8001D170	beq    v0, zero, L1d1a0 [$8001d1a0]
8001D174	lui    v0, $ffef
8001D178	ori    v0, v0, $ffff
8001D17C	lw     v1, $0020(s0)
8001D180	and    v0, a0, v0
8001D184	sw     v0, $0040(s0)
8001D188	lw     v0, $0034(v1)
8001D18C	nop
8001D190	beq    v0, zero, L1d1a0 [$8001d1a0]
8001D194	nop
8001D19C	addu   a0, s0, zero
func2332c;


L1d1a0:	; 8001D1A0
8001D1A0	lw     v0, $0040(s0)
8001D1A4	lui    v1, $0002
8001D1A8	and    v0, v0, v1
8001D1AC	beq    v0, zero, L1d234 [$8001d234]
8001D1B0	nop
8001D1B4	lw     v0, $0020(gp)
8001D1B8	nop
8001D1BC	beq    v0, zero, L1d234 [$8001d234]
8001D1C0	lui    a1, $0008
8001D1C4	lui    v1, $8006
8001D1C8	addiu  v1, v1, $9b04 (=-$64fc)
8001D1CC	lui    a0, $8007
8001D1D0	addiu  a0, a0, $b4a0 (=-$4b60)

loop1d1d4:	; 8001D1D4
    8001D1D4	bne    v0, s0, L1d21c [$8001d21c]
    8001D1D8	nop
    8001D1DC	lw     a2, $0024(s0)
    8001D1E0	nop
    8001D1E4	beq    a2, v1, L1d214 [$8001d214]
    8001D1E8	nop
    8001D1EC	beq    a2, a0, L1d214 [$8001d214]
    8001D1F0	nop
    8001D1F4	lw     v0, $0040(s0)
    8001D1F8	nop
    8001D1FC	and    v0, v0, a1
    8001D200	bne    v0, zero, L1d214 [$8001d214]
    8001D204	nop
    8001D208	lhu    a1, $0034(s0)
    8001D210	addu   a0, s0, zero
    func1f764;


    L1d214:	; 8001D214
    [S0 + 34] = h(frame_id);
    return;

    L1d21c:	; 8001D21C
    8001D21C	lw     v0, $0020(v0)
    8001D220	nop
    8001D224	lw     v0, $0038(v0)
    8001D228	nop
8001D22C	bne    v0, zero, loop1d1d4 [$8001d1d4]

L1d234:	; 8001D234
8001D234	lw     a1, $0020(gp)
8001D23C	lw     a0, $0020(s0)
// we set frame id here!!!!!!!!!!!
// 8001d244 : SH      00000025 (s1), 0034 (8012f354 (s0)) [8012f388]
[S0 + 34] = h(frame_id);
8001D248	sw     s0, $0020(gp)
[S0 + 40] = w(w[S0 + 40] | 00020000);
8001D254	sw     a1, $0038(a0)

L1d258:	; 8001D258
////////////////////////////////



////////////////////////////////
// func21b58
V0 = b[A0 + 8c] - 3;
[A0 + 8c] = b(V0);
[A0 + V0 + 8e] = b(A1);
V0 = A0 + b[A0 + 8c];
[V0 + 8f] = b(A1 >> 8);
V0 = b[A0 + 8c];
[A0 + V0 + 90] = b(A1 >> 10);
////////////////////////////////



////////////////////////////////
// func1f764
8001F76C	addu   s2, a0, zero
8001F788	lw     a0, $0000(a2)
8001F78C	nop
8001F790	lhu    v1, $0000(a0)
8001F794	nop
8001F798	andi   v0, v1, $01ff
8001F79C	addiu  v0, v0, $0001
8001F7A0	slt    v0, a1, v0
8001F7A4	beq    v0, zero, L1f904 [$8001f904]
8001F7A8	andi   v0, v1, $8000
8001F7AC	beq    v0, zero, L1f7c4 [$8001f7c4]
8001F7B0	sll    v0, a1, $01
8001F7B8	addu   a0, s2, zero
func1f5d0;

8001F7BC	j      L1f904 [$8001f904]
8001F7C0	nop

L1f7c4:	; 8001F7C4
8001F7C4	addu   v0, v0, a0
8001F7C8	lhu    v1, $0000(v0)
8001F7CC	nop
8001F7D0	addu   v1, v1, a0
8001F7D4	lbu    v0, $0000(v1)
8001F7D8	addu   s3, zero, zero
8001F7DC	andi   s5, v0, $0080
8001F7E0	andi   s4, v0, $003f
8001F7E4	sll    v0, s4, $02
8001F7E8	addiu  v0, v0, $0006
8001F7EC	beq    s4, zero, L1f904 [$8001f904]

L1f7f0:	; 8001F7F0
8001F7F0	addu   s0, v1, v0

L1f7f4:	; 8001F7F4
8001F7F4	lbu    s1, $0000(s0)
8001F7F8	nop
8001F7FC	andi   v0, s1, $0080
8001F800	beq    v0, zero, L1f8f0 [$8001f8f0]
8001F804	andi   v0, s1, $0040
8001F808	beq    v0, zero, L1f8d0 [$8001f8d0]
8001F80C	addiu  s0, s0, $0001
8001F810	lw     v0, $0020(s2)
8001F814	nop
8001F818	lw     v0, $0034(v0)
8001F81C	nop
8001F820	bne    v0, zero, L1f848 [$8001f848]
8001F824	andi   v0, s1, $0020
8001F828	ori    a0, zero, $0040
8001F830	addu   a1, zero, zero
system_memory_allocate;

8001F834	lw     v1, $0020(s2)
8001F838	addu   a0, s2, zero
8001F840	sw     v0, $0034(v1)
func2332c;

8001F844	andi   v0, s1, $0020

L1f848:	; 8001F848
8001F848	beq    v0, zero, L1f884 [$8001f884]
8001F84C	andi   a1, s1, $0007
8001F850	sll    a0, a1, $03
8001F854	lw     v0, $0020(s2)
8001F858	lbu    v1, $0000(s0)
8001F85C	lw     v0, $0034(v0)
8001F860	addiu  s0, s0, $0001
8001F864	addu   v0, a0, v0
8001F868	sb     v1, $0000(v0)
8001F86C	lw     v0, $0020(s2)
8001F870	lbu    v1, $0000(s0)
8001F874	lw     v0, $0034(v0)
8001F878	addiu  s0, s0, $0001
8001F87C	addu   a0, a0, v0
8001F880	sb     v1, $0001(a0)

L1f884:	; 8001F884
8001F884	andi   v0, s1, $0010
8001F888	beq    v0, zero, L1f8b4 [$8001f8b4]
8001F88C	nop
8001F890	lbu    a0, $0000(s0)
8001F894	addiu  s0, s0, $0001
8001F898	lw     v0, $0020(s2)
8001F89C	sll    a0, a0, $04
8001F8A0	lw     v1, $0034(v0)
8001F8A4	sll    v0, a1, $03
8001F8A8	addu   v0, v0, v1
8001F8AC	j      L1f7f4 [$8001f7f4]
8001F8B0	sh     a0, $0006(v0)

L1f8b4:	; 8001F8B4
8001F8B4	lw     v0, $0020(s2)
8001F8B8	nop
8001F8BC	lw     v1, $0034(v0)
8001F8C0	sll    v0, a1, $03
8001F8C4	addu   v0, v0, v1
8001F8C8	j      L1f7f4 [$8001f7f4]
8001F8CC	sh     zero, $0006(v0)

L1f8d0:	; 8001F8D0
8001F8D0	andi   v0, s1, $0001
8001F8D4	beq    v0, zero, L1f8e0 [$8001f8e0]
8001F8D8	andi   v0, s1, $0002
8001F8DC	addiu  s0, s0, $0001

L1f8e0:	; 8001F8E0
8001F8E0	beq    v0, zero, L1f7f4 [$8001f7f4]
8001F8E4	nop
8001F8E8	j      L1f7f4 [$8001f7f4]
8001F8EC	addiu  s0, s0, $0001

L1f8f0:	; 8001F8F0
8001F8F0	beq    s5, zero, L1f8fc [$8001f8fc]
8001F8F4	addiu  s3, s3, $0001
8001F8F8	addiu  s0, s0, $0002

L1f8fc:	; 8001F8FC
8001F8FC	bne    s3, s4, L1f7f4 [$8001f7f4]
8001F900	addiu  s0, s0, $0003

L1f904:	; 8001F904
////////////////////////////////



////////////////////////////////
// func1f5d0
8001F5D0	addiu  sp, sp, $ffd0 (=-$30)
8001F5D4	sw     ra, $002c(sp)
8001F5D8	sw     s6, $0028(sp)
8001F5DC	sw     s5, $0024(sp)
8001F5E0	sw     s4, $0020(sp)
8001F5E4	sw     s3, $001c(sp)
8001F5E8	sw     s2, $0018(sp)
8001F5EC	sw     s1, $0014(sp)
8001F5F0	sw     s0, $0010(sp)
8001F5F4	lw     v0, $0000(a2)
8001F5F8	sll    a1, a1, $01
8001F5FC	addu   a1, a1, v0
8001F600	lhu    v1, $0000(a1)
8001F604	addu   s3, a0, zero

L1f608:	; 8001F608
8001F608	addu   v1, v1, v0
8001F60C	lbu    v0, $0000(v1)
8001F610	addu   s4, zero, zero
8001F614	andi   s6, v0, $0080
8001F618	andi   s5, v0, $003f
8001F61C	sll    v0, s5, $01
8001F620	addiu  v0, v0, $0004
8001F624	beq    s5, zero, L1f738 [$8001f738]
8001F628	addu   s0, v1, v0

L1f62c:	; 8001F62C
8001F62C	lbu    s1, $0000(s0)
8001F630	nop
8001F634	andi   v0, s1, $0080
8001F638	beq    v0, zero, L1f724 [$8001f724]
8001F63C	andi   v0, s1, $0040
8001F640	beq    v0, zero, L1f704 [$8001f704]
8001F644	addiu  s0, s0, $0001
8001F648	lw     v0, $0020(s3)
8001F64C	nop
8001F650	lw     v0, $0034(v0)
8001F654	nop
8001F658	bne    v0, zero, L1f67c [$8001f67c]
8001F65C	andi   s2, s1, $0007
8001F660	ori    a0, zero, $0040
8001F664	jal    system_memory_allocate [$800319ec]
8001F668	addu   a1, zero, zero
8001F66C	lw     v1, $0020(s3)
8001F670	addu   a0, s3, zero
8001F678	sw     v0, $0034(v1)
func2332c;


L1f67c:	; 8001F67C
8001F67C	andi   v0, s1, $0020
8001F680	beq    v0, zero, L1f6b8 [$8001f6b8]
8001F684	sll    a0, s2, $03
8001F688	lw     v0, $0020(s3)
8001F68C	lbu    v1, $0000(s0)
8001F690	lw     v0, $0034(v0)
8001F694	addiu  s0, s0, $0001
8001F698	addu   v0, a0, v0
8001F69C	sb     v1, $0000(v0)
8001F6A0	lw     v0, $0020(s3)
8001F6A4	lbu    v1, $0000(s0)
8001F6A8	lw     v0, $0034(v0)
8001F6AC	addiu  s0, s0, $0001
8001F6B0	addu   a0, a0, v0
8001F6B4	sb     v1, $0001(a0)

L1f6b8:	; 8001F6B8
8001F6B8	andi   v0, s1, $0010
8001F6BC	beq    v0, zero, L1f6e8 [$8001f6e8]
8001F6C0	nop
8001F6C4	lbu    a0, $0000(s0)
8001F6C8	addiu  s0, s0, $0001
8001F6CC	lw     v0, $0020(s3)
8001F6D0	sll    a0, a0, $04
8001F6D4	lw     v1, $0034(v0)
8001F6D8	sll    v0, s2, $03
8001F6DC	addu   v0, v0, v1
8001F6E0	j      L1f62c [$8001f62c]
8001F6E4	sh     a0, $0006(v0)

L1f6e8:	; 8001F6E8
8001F6E8	lw     v0, $0020(s3)
8001F6EC	nop
8001F6F0	lw     v1, $0034(v0)
8001F6F4	sll    v0, s2, $03
8001F6F8	addu   v0, v0, v1
8001F6FC	j      L1f62c [$8001f62c]
8001F700	sh     zero, $0006(v0)

L1f704:	; 8001F704
8001F704	andi   v0, s1, $0001
8001F708	beq    v0, zero, L1f714 [$8001f714]
8001F70C	andi   v0, s1, $0002
8001F710	addiu  s0, s0, $0001

L1f714:	; 8001F714
8001F714	beq    v0, zero, L1f62c [$8001f62c]
8001F718	nop
8001F71C	j      L1f62c [$8001f62c]
8001F720	addiu  s0, s0, $0001

L1f724:	; 8001F724
8001F724	beq    s6, zero, L1f730 [$8001f730]
8001F728	addiu  s4, s4, $0001
8001F72C	addiu  s0, s0, $0002

L1f730:	; 8001F730
8001F730	bne    s4, s5, L1f62c [$8001f62c]
8001F734	addiu  s0, s0, $0003

L1f738:	; 8001F738
8001F738	lw     ra, $002c(sp)
8001F73C	lw     s6, $0028(sp)
8001F740	lw     s5, $0024(sp)
8001F744	lw     s4, $0020(sp)
8001F748	lw     s3, $001c(sp)
8001F74C	lw     s2, $0018(sp)
8001F750	lw     s1, $0014(sp)
8001F754	lw     s0, $0010(sp)
8001F758	addiu  sp, sp, $0030
8001F75C	jr     ra 
8001F760	nop
////////////////////////////////
