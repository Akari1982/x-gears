////////////////////////////////
// func1e130
S0 = A0;
S1 = A1;

8001E144	jal    func1dfe8 [$8001dfe8]

A0 = S0;
A1 = S1;
func1e264;

if( w[S0 + 3c] & 4 )
{
    A0 = S0;
    A1 = S1;
    func1e834;
}
////////////////////////////////



////////////////////////////////
// func1e264
struct = A0;
packet_addr = A1;
addr = w[struct + 20];
addr2 = w[addr + 34];
sprite_data = w[addr + 30];
scale = (w[struct + 40] >> 8) & 1f;
number_of_tiles = (w[struct + 40] >> 2) & 3f;



// offset for sprite
offset_x = b[addr + 3c] << scale;
offset_y = b[addr + 3d] << scale;
if( w[struct + ac] & 00000010 )
{
    offset_x = 0 - offset_x;
}



if( w[80058c1c] + number_of_tiles * 28 >= w[80058bd0] || number_of_tiles == 0 )
{
    return;
}



tile = 0;
add_id = -1;

L1e324:	; 8001E324
    V0 = w[sprite_data + 14] & 00000007;
    if( add_id != V0 )
    {
        add_id = V0;
        [SP + 78] = b((hu[8004f19c + add_id * 2] & bu[struct + 3d]) < 1);

        if( ( addr2 != 0 && ( ( hu[addr2 + add_id * 8 + 0] == 0 ) || ( h[addr2 + add_id * 8 + 6] != 0 ) )
        {
            S0 = b[addr2 + add_id * 8 + 0] << scale;
            S1 = b[addr2 + add_id * 8 + 1] << scale;
            if( w[struct + 3c] & 00000008 )
            {
                S0 = 0 - b[addr2 + add_id * 8 + 0] << scale;
            }

            S1 = (S1 * h[struct + 2c]) >> c;
            S0 = (S0 * h[struct + 2c]) >> c;

            [SP + 48] = h(hu[addr2 + add_id * 8 + 2]); // rotation x
            [SP + 4a] = h(hu[addr2 + add_id * 8 + 4]); // rotation y
            [SP + 4c] = h(hu[addr2 + add_id * 8 + 6]); // rotation z
            if( w[struct + 3c] & 00000008 )
            {
                [SP + 4c] = h(0 - hu[addr2 + add_id * 8 + 6]);
            }

            A0 = SP + 48;
            A1 = SP + 28;
            func3f5e0; // rotaion matrix from rotation angles

            // translation vector
            [SP + 3c] = w(w[addr + 20] + S0);
            [SP + 40] = w(w[addr + 24] + S1);
            [SP + 44] = w(w[addr + 28]);

            A0 = addr + c;
            A1 = SP + 28;
            func49724;  // multiply 2 matrix and set result as rotation matrix

            A0 = SP + 28;
            system_gte_set_translation_vector;
        }
        else
        {
            A0 = addr + c;
            system_gte_set_rotation_matrix;

            A0 = addr + c;
            system_gte_set_translation_vector;
        }
    }



    if( bu[SP + 78] != 0 )
    {
        S0 = w[80058c1c];
        [80058c1c] = w(S0 + 28);

        [S0 + 3] = b(09);
        [S0 + 4] = w(w[sprite_data + 10]); // 2c808080 - Command + Color Vertex 0
        [S0 + e] = h(h[sprite_data + c]); // clut id
        [S0 + 16] = h(h[sprite_data + a]); // tpage

        x0 = h[sprite_data + 0] << scale;
        y0 = h[sprite_data + 2] << scale;
        width = (bu[sprite_data + 6] + b[sprite_data + 8]) << scale;
        height = (bu[sprite_data + 7] + b[sprite_data + 9]) << scale;

        if( w[struct + 3c] & 00000008 )
        {
            x0 = 0 - x0;
            width = 0 - width;
        }
        if( w[struct + 3c] & 00000010 )
        {
            y0 = 0 - y0;
            height = 0 - height;
        }

        if( ( w[sprite_data + 14] & 00000010 ) == 0 ) // flip horizontal <>
        {
            [8004f23c + 00] = h(x0);
            [8004f23c + 08] = h(x0 + width);
            [8004f23c + 10] = h(x0 + width);
            [8004f23c + 18] = h(x0);
        }
        else
        {
            [8004f23c + 00] = h(x0 + width);
            [8004f23c + 08] = h(x0);
            [8004f23c + 10] = h(x0);
            [8004f23c + 18] = h(x0 + width);
        }

        if( ( w[sprite_data + 14] & 00000020 ) == 0 ) // flip vertical
        {
            [8004f23c + 02] = h(y0);
            [8004f23c + 0a] = h(y0);
            [8004f23c + 12] = h(y0 + height);
            [8004f23c + 1a] = h(y0 + height);
        }
        else
        {
            [8004f23c + 02] = h(y0 + height);
            [8004f23c + 0a] = h(y0 + height);
            [8004f23c + 12] = h(y0);
            [8004f23c + 1a] = h(y0);
        }

        [8004f23c + 00] = h(hu[8004f23c + 00] - offset_x);
        [8004f23c + 08] = h(hu[8004f23c + 08] - offset_x);
        [8004f23c + 10] = h(hu[8004f23c + 10] - offset_x);
        [8004f23c + 18] = h(hu[8004f23c + 18] - offset_x);
        [8004f23c + 02] = h(hu[8004f23c + 02] - offset_y);
        [8004f23c + 0a] = h(hu[8004f23c + 0a] - offset_y);
        [8004f23c + 12] = h(hu[8004f23c + 12] - offset_y);
        [8004f23c + 1a] = h(hu[8004f23c + 1a] - offset_y);

        A0 = 8004f23c + 00; // xyz0
        A1 = 8004f23c + 08; // xyz1
        A2 = 8004f23c + 10; // xyz3
        A3 = 8004f23c + 18; // xyz2
        A4 = S0 + 08; // xy0
        A5 = S0 + 10; // xy1
        A6 = S0 + 20; // xy3
        A7 = S0 + 18; // xy2
        A8 = SP + 5c; // Interpolation value for depth queing. (not used)
        A9 = SP + 60; // return flags (not used)
        func4a5e4; // transform 4 points by rotation matrix



        // set up texture coordinates
        u0 = bu[sprite_data + 4];
        v0 = bu[sprite_data + 5];
        width = bu[sprite_data + 6] - 1;
        height = bu[sprite_data + 7] - 1;
        if( h[S0 + 20] < h[S0 + 8] ) // x3 < x0
        {
            u0 = u0 - 1;
            if( u0 < 0 )
            {
                u0 = 0;
                width = width - 1;
            }
        }
        [S0 + 0c] = b(u0); // u0
        [S0 + 0d] = b(v0); // v0
        [S0 + 14] = b(u0 + width); // u1
        [S0 + 15] = b(v0); // v1
        [S0 + 1c] = b(u0); // u2
        [S0 + 1d] = b(v0 + height); // v2
        [S0 + 24] = b(u0 + width); // u3
        [S0 + 25] = b(v0 + height); // v3



        if( w[struct + 3c] & 00000800 )
        {
            [S0 + 0] = w((w[S0] & ff000000) | (w[packet_addr - add_id * 4] & 00ffffff));
            [packet_addr - add_id * 4] = w((w[packet_addr - add_id * 4] & ff000000) | (S0 & 00ffffff));
        }
        else
        {
            [S0 + 0] = w((w[S0] & ff000000) | (w[packet_addr] & 00ffffff));
            [packet_addr] = w((w[packet_addr] & ff000000) | (S0 & 00ffffff));
        }
    }



    sprite_data = sprite_data + 18;
    tile = tile + 1;
8001E7F8	bne    tile, number_of_tiles, L1e324 [$8001e324]
////////////////////////////////
