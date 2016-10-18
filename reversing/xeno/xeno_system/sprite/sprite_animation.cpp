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
            func21e60();
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
    func224f0(); // opcode run for frame set (don't do other things)

    [struct_164 + 9e] = h(S0);
}

V1 = w[struct_164 + ac];
V0 = ((V1 >> 5) & 1) XOR ((V1 >> 4) & 1);
[struct_164 + 3c] = w((w[struct_164 + 3c] & fffffff7) | (V0 << 3));
////////////////////////////////



////////////////////////////////
// func224f0()
struct_164 = A0;
S4 = A1; // pointer to start of sprite sequence data.
S5 = A2; // +a8 0x0fc00000 flags

loop2251c:	; 8002251C
    A2 = w[struct_164 + 64];

    if( ( A2 == S4 ) && ( ( ( w[struct_164 + a8] >> 16 ) & 3f ) == S5 ) )
    {
        return;
    }

    opcode = bu[A2];

    if( opcode > 80 )
    {
        if( opcode == 87 || opcode == 86 || opcode == 97 )
        {
            if( A2 == S4 )
            {
                return;
            }
        }
        else if( opcode == b3 )
        {
            [struct_164 + a8] = w((w[struct_164 + a8] & fffe07ff) | ((b[A2 + 1] & 3f) << b)));
        }
        else if( opcode == be )
        {
            A0 = (w[struct_164 + ac] & ffffffdf) | ((hu[A2 + 1] >> 4) & 0020); // set invert y flag
            [struct_164 + 3c] = w((w[struct_164 + 3c] & fffffff7) | ((((A0 >> 5) & 1) XOR ((A0 >> 4) & 1)) << 3));
            [struct_164 + ac] = w(A0);

            frame_id = hu[A2 + 1] & 1ff;
            if( hu[struct_164 + 34] != frame_id )
            {
                A0 = struct_164;
                A1 = frame_id;
                system_set_sprite_frame();
            }

            [struct_164 + 9e] = h(hu[struct_164 + 9e] + 1 + (hu[A2 + 1] >> b) & f); // wait
        }
        else if( opcode == e2 )
        {
            [struct_164 + 8c] = b(b[struct_164 + 8c] - 3);

            V0 = b[struct_164 + 8c];
            [struct_164 + 8e + V0 + 0] = b((A2 + 3) >> 0);
            [struct_164 + 8e + V0 + 1] = b((A2 + 3) >> 8);
            [struct_164 + 8e + V0 + 2] = b((A2 + 3) >> 10);

            [struct_164 + 64] = w(w[struct_164 + 64] + h[A2 + 1]);
            8002277C	j      loop2251c [$8002251c]
        }
        else if( opcode >= 80 && opcode < 83 )
        {
            return;
        }

        // opcode size 8004f2e4 + 80
        // 80 01010101010101010101010101010101
        // 90 01010101010101010101010101010101
        // a0 02020202020202020202020202020202
        // b0 02020202020202020202020202020202
        // c0 02020202020202020303030303030303
        // d0 03030303030303030303030303030303
        // e0 03030303030303030303030303030303
        // f0 03040404040404040404040404040404
        [struct_164 + 64] = w(w[struct_164 + 64] + bu[8004f2e4 + opcode]); // move pointer by opcode size
    }
    else
    {
        if( opcode < 10 )
        {
            A0 = struct_164;
            A1 = hu[struct_164 + 34] + 1;
            system_set_sprite_frame();
        }
        else if( opcode < 20 )
        {
            frame_data_id = (w[struct_164 + a8] >> b) & 3f;
            [struct_164 + a8] = w((w[struct_164 + a8] & fffe07ff) | (((frame_data_id + 1) & 3f) << b));

            A0 = struct_164;
            system_set_rotated_sprite_frame();
        }
        else if( opcode < 30 )
        {
            A1 = hu[struct_164 + 34] - 1;
            A0 = struct_164;
            system_set_sprite_frame();
        }

        if( opcode < 40 )
        {
            wait = (opcode & f) + 1;
        }
        [struct_164 + 9e] = h(hu[struct_164 + 9e] + wait;

        // increment unknown clamp 0x3f
        V0 = (((w[struct_164 + a8] >> 16) & 3f) + 1) & 3f; // 0x0fc00000
        if( V0 != 0 )
        {
            [struct_164 + a8] = w((w[struct_164 + a8] & f03fffff) | (V0 << 16));
        }

        [struct_164 + 64] = w(A2 + 1);
    }
80022648	j      loop2251c [$8002251c]
////////////////////////////////



////////////////////////////////
// system_set_rotated_sprite_frame()
struct_164 = A0;

V1 = (w[struct_164 + a8] >> b) & 3f;
V0 = w[struct_164 + 54];
frame_id = hu[V0 + V1 * 2];

// invert offset y
if( frame_id & 0200 )
{
    [struct_164 + ac] = w(w[struct_164 + ac] | 00000020);
}
else
{
    [struct_164 + ac] = w(w[struct_164 + ac] & ffffffdf);
}

V1 = w[struct_164 + ac];
[struct_164 + 3c] = w((w[struct_164 + 3c] & fffffff7) | ((((V1 >> 5) & 1) XOR ((V1 >> 4) & 1)) << 3));

A0 = struct_164;
A1 = frame_id & 01ff;
system_set_sprite_frame();
////////////////////////////////



////////////////////////////////
// system_set_sprite_frame()
struct_164 = A0;
frame_id = A1;

datab4 = w[struct_164 + 20];

if( ( w[struct_164 + 3c] & 00000003 ) != 00000001 )
{
    [struct_164 + 34] = h(0); // reset frame id
    return;
}

// if we will use additional translation and rotation - init them
if( w[struct_164 + 40] & 00100000 )
{
    [struct_164 + 40] = w(w[struct_164 + 40] & ffefffff);
    if( w[datab4 + 34] != 0 )
    {
        A0 = struct_164;
        func2332c(); // init 0x8 items in +124 with 0
    }
}

last_struct = w[GP + 20];
if( ( w[struct_164 + 40] & 00020000 ) && ( last_struct != 0 ) )
{
    loop1d1d4:	; 8001D1D4
        if( last_struct == struct_164 )
        {
            data110 = w[struct_164 + 24];
            if( data110 != 80059b04 && data110 != 8006b4a0 ) // some predefine texture data for sprite
            {
                if( ( w[struct_164 + 40] & 00080000 ) == 0 )
                {
                    A0 = struct_164;
                    A1 = hu[struct_164 + 34]; // prev frame
                    A2 = data110;
                    func1f764(); // init sprite data124 with data for short and long tile data.
                }
            }

            [struct_164 + 34] = h(frame_id);
            return;
        }

        V0 = w[last_struct + 20];
        last_struct = w[V0 + 38];
    8001D22C	bne    last_struct, zero, loop1d1d4 [$8001d1d4]
}

[struct_164 + 34] = h(frame_id);

// link sprite struct list
A1 = w[GP + 20];
[GP + 20] = w(struct_164);
[datab4 + 38] = w(A1);
[struct_164 + 40] = w(w[struct_164 + 40] | 00020000);
////////////////////////////////



////////////////////////////////
// func1f764()
struct_164 = A0;
frame_id = A1;
data110 = A2;

sprite_file_1 = w[data110 + 0];

if( frame_id >= ((hu[sprite_file_1 + 0] & 01ff) + 1) )
{
    return;
}

if( hu[sprite_file_1 + 0] & 8000 )
{
    A0 = struct_164;
    A1 = frame_id;
    A2 = data110;
    func1f5d0(); // init sprite data124 with data for short tile data.

    return;
}

frame_data = sprite_file_1 + hu[sprite_file_1 + frame_id * 2];
V0 = bu[frame_data + 0];
bytes2 = V0 & 80; // two bytes tile position
number_of_tiles = V0 & 3f;

if( number_of_tiles != 0 )
{
    S0 = frame_data + 6 + number_of_tiles * 4;

    tile_id = 0;
    L1f7f4:	; 8001F7F4
        control = bu[S0];
        if( bytes2 & 80 )
        {
            S0 = S0 + 1;

            if( control & 40 )
            {
                // if pointer to additional tile data not exist
                // allocate place and create pointer
                datab4 = w[struct_164 + 20];
                if( w[datab4 + 34] == 0 )
                {
                    A0 = 40;
                    A1 = 0;
                    system_memory_allocate();
                    [datab4 + 34] = w(V0);

                    A0 = struct_164;
                    func2332c(); // init 0x8 items in +124 with 0
                }

                A1 = S1 & 7;
                if( S1 & 20 ) // additional offset
                {
                    V0 = w[datab4 + 34];
                    [V0 + A1 * 8 + 0] = b(bu[S0 + 0]);
                    [V0 + A1 * 8 + 1] = b(bu[S0 + 1]);
                    S0 = S0 + 2;
                }
                if( S1 & 10 )
                {
                    V0 = w[datab4 + 34];
                    [V0 + A1 * 8 + 6] = h(bu[S0] << 4);
                    S0 = S0 + 1;
                }
                else
                {
                    V0 = w[datab4 + 34];
                    [V0 + A1 * 8 + 6] = h(0);
                }
            }
            else
            {
                if( S1 & 01 )
                {
                    S0 = S0 + 1;
                }
                if( S1 & 02 )
                {
                    S0 = S0 + 1;
                }
            }

            8001F8E8	j      L1f7f4 [$8001f7f4]
        }

        S0 = S0 + 3;
        if( bytes2 != 0 )
        {
            S0 = S0 + 2;
        }
        tile_id = tile_id + 1;
    8001F8FC	bne    tile_id, number_of_tiles, L1f7f4 [$8001f7f4]
}
////////////////////////////////



////////////////////////////////
// func1f5d0()
struct_164 = A0;
frame_id = A1;
data110 = A2;

sprite_file_1 = w[data110 + 0];

frame_data = sprite_file_1 + hu[sprite_file_1 + frame_id * 2];
V0 = bu[frame_data + 0];
bytes2 = V0 & 80;
number_of_tiles = V0 & 3f;

if( number_of_tiles != 0 )
{
    S0 = frame_data + 4 + number_of_tiles * 2;

    tile_id = 0;
    L1f62c:	; 8001F62C
        S1 = bu[S0];
        if( S1 & 80 )
        {
            S0 = S0 + 1;

            if( S1 & 40 )
            {
                // if pointer to additional tile data not exist
                // allocate place and create pointer
                datab4 = w[struct_164 + 20];
                if( w[datab4 + 34] == 0 )
                {
                    A0 = 40;
                    A1 = 0;
                    system_memory_allocate();
                    [datab4 + 34] = w(V0);

                    A0 = struct_164;
                    func2332c(); // init 0x8 items in +124 with 0
               }

                A1 = S1 & 7;
                if( S1 & 20 ) // additional offset
                {
                    V0 = w[datab4 + 34];
                    [V0 + A1 * 8 + 0] = b(bu[S0 + 0]);
                    [V0 + A1 * 8 + 1] = b(bu[S0 + 1]);
                    S0 = S0 + 2;
                }
                if( S1 & 10 )
                {
                    V0 = w[datab4 + 34];
                    [V0 + A1 * 8 + 6] = h(bu[S0] << 4);
                    S0 = S0 + 1;
                }
                else
                {
                    V0 = w[datab4 + 34];
                    [V0 + A1 * 8 + 6] = h(0);
                }
            }
            else
            {
                if( S1 & 01 )
                {
                    S0 = S0 + 1;
                }
                if( S1 & 02 )
                {
                    S0 = S0 + 1;
                }
            }

            8001F71C	j      L1f62c [$8001f62c]
        }

        S0 = S0 + 3;
        if( bytes2 != 0 )
        {
            S0 = S0 + 2;
        }
        tile_id = tile_id + 1;
    8001F730	bne    tile_id, number_of_tiles, L1f62c [$8001f62c]
}
////////////////////////////////
