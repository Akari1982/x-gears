////////////////////////////////
// func1d3b8
S4 = A0;
frame = A1;
S6 = A2;

sprite_1_address = w[S6];
frame_offset = sprite_1_address + frame * 2;
frame_address = sprite_1_address + hu[frame_offset];
tile_offsets = frame_address + 4;
number_of_tiles = bu[frame_address + 0] & 3f;
S2 = frame_address + 4 + number_of_tiles * 2;

[SP + 48] = w(S4);

[S4 + 36] = h((bu[frame_address + 3] * h[S4 + 2c]) >> c);
[S4 + 38] = h((bu[A0 + 1] * h[S4 + 2c]) >> c);

tex_y_off = bu[S6 + 6];
g_abr = bu[S4 + 3c] >> 5;

packet_header = w[S4 + 28]; // 2C808080

S7 = 4;

tile = 0;

if( number_of_tiles != 0 )
{
    V0 = w[S4 + 20];
    sprite_data = w[V0 + 30];

    L1d4bc:	; 8001D4BC
        [sprite_data + 8] = b(0);
        [sprite_data + 9] = b(0);
        [sprite_data + 14] = w(w[sprite_data + 14] & ffffffdf); // remove flip vertical flag

        L1d4d4:	; 8001D4D4
        S1 = bu[S2];
        if( S1 & 80 )
        {
            S2 = S2 + 1;

            if( S1 & 40 )
            {
                V0 = w[S4 + 20];
                if( w[V0 + 34] == 0 ) // if memory not allocated
                {
                    A0 = 40; // allocate 40 byte
                    A1 = 0;
                    system_memory_allocate;
                    V1 = w[S4 + 20];
                    [V1 + 34] = w(V0);

                    A0 = S4;
                    func2332c; // set all fields to zero
                }

                S7 = S1 & 7;
                V0 = w[S4 + 20];
                V0 = w[V0 + 34];

                if( S1 & 20 )
                {
                    [V0 + S7 * 8 + 0] = b(bu[S2 + 0]);
                    [V0 + S7 * 8 + 1] = b(bu[S2 + 1]);
                    S2 = S2 + 2;
                }

                if( S1 & 10 )
                {
                    [V0 + S7 * 8 + 6] = h(bu[S2] << 4);
                    S2 = S2 + 1;
                }
                else
                {
                    [V0 + S7 * 8 + 6] = h(0);
                }
            }
            else
            {
                if( S1 & 01 ) // width increase
                {
                    [sprite_data + 8] = b(bu[S2]);
                    S2 = S2 + 1;
                }
                if( S1 & 02 ) // height inscease
                {
                    [sprite_data + 9] = b(bu[S2]);
                    S2 = S2 + 1;
                }
                if( S1 & 04 ) // flip vertical
                {
                    [sprite_data + 14] = w(w[sprite_data + 14] | 00000020);
                }
            }
            8001D588	j      L1d4d4 [$8001d4d4]
        }



        tile_address = sprite_1_address + hu[tile_offsets];
        tile_offsets = tile_offsets + 2;

        S1 = bu[tile_address + 0];

        if( S1 & 01 )
        {
            [sprite_data + 14] = w(w[sprite_data + 14] | 00000008);
            tex_x_off = (hu[S6 + 4] & 3f) >> 1;
        }
        else
        {
            [sprite_data + 14] = w(w[sprite_data + 14] & fffffff7);
            tex_x_off = (hu[S6 + 4] & 3f) >> 2;
        }



        [sprite_data + 10] = w(packet_header);



        A2 = bu[S2] >> 4 & 03; // abr - Semi transparency mode

        if( A2 != 0 )
        {
            [sprite_data + 13] = b(bu[sprite_data + 13] | 02); // semi-transparency on
            A2 = A2 - 1;
        }
        else // 0.5xB+0.5 x F
        {
            A2 = g_abr;
            if( A2 != 0 )
            {
                [sprite_data + 13] = b(bu[sprite_data + 13] | 02); // semi-transparency on
                A2 = A2 - 1;
            }
        }

        if( S1 & 10 )
        {
            tile_address = tile_address + 1;
            S1 = (bu[tile_address] << 8) | S1;

            A0 = S1 & 0001; // tp
            A1 = A2; // abr
            V0 = (S1 << 1) & 1c;
            A2 = h[8004f15c + V0]; // tx
            A3 = h[8004f15e + V0]; // ty and tr
            func43894; // ((A0 & 3) << 7) | ((A1 & 3) << 5) | ((A3 & 0100) >> 4) | ((A2 & 03ff) >> 6) | ((A3 & 0200) << 2);
            [sprite_data + a] = h(V0);

            A0 = (S1 >> 1) + f0; // x
            A1 = ((S1 >> 9) & f) + 1cc; // y
            func438d0; // ((A1 << 6) | ((A0 >> 4) & 3f)) & ffff;
            [sprite_data + c] = h(V0);
        }
        else
        {
            T0 = w[SP + 48];
            V0 = w[T0 + 7c];
            V1 = w[V0 + 18];
            if( ( w[T0 + a8] & 0001 ) && ( V1 != 0 ) )
            {
                V0 = ((S1 << 1) & 1c) + V1;

                tex_x_off = (hu[V0 + 0] & 3f) >> 2;
                tex_y_off = hu[V0 + 2] & ff;

                tx = (hu[V0 + 0] & 3ff) >> 6;
                ty = (hu[V0 + 2] >> 4) & 0010;
                abr = (A2 & 03) << 5;
                tp = (S1 & 01) << 7;
                tr = (hu[V0 + 2] & 0200) << 2;
                [sprite_data + a] = h( tr | tp | abr | ty | tx);
            }
            else
            {
                tx = ((h[S6 + 4] + ((S1 << 5) & 01c0)) & 3ff) >> 6;
                ty = (hu[S6 + 6] >> 4) & 0010;
                abr = (A2 & 03) << 5;
                tp = (S1 & 01) << 7;
                tr = (hu[S6 + 6] & 0200) << 2; // Textured Rectangle X-Flip, Y-Flip
                [sprite_data + a] = h( tr | tp | abr | ty | tx);
            }

            x = ((h[S6 + 8] + ((bu[S2] & 0f) << 4)) >> 4) & 3f;
            y = hu[S6 + a] << 6;
            [sprite_data + c] = h(y | x);
        }



        [sprite_data + 4] = b(bu[tile_address + 1] + tex_x_off);
        [sprite_data + 5] = b(bu[tile_address + 2] + tex_y_off);
        [sprite_data + 6] = b(bu[tile_address + 3]);
        [sprite_data + 7] = b(bu[tile_address + 4]);

        [sprite_data + 14] = w((w[sprite_data + 14] & fffffff8) | S7 );
        [sprite_data + 14] = w((w[sprite_data + 14] & ffffffef) | ((bu[S2 + 0] >> 2) & 10)); // flip horizontal if set

        if( bu[frame_address + 0] & 80 ) // double presision
        {
            [sprite_data + 0] = h(hu[S2 + 1]);
            [sprite_data + 2] = h(hu[S2 + 3]);
            S2 = S2 + 2;
        }
        else
        {
            [sprite_data + 0] = h(b[S2 + 1]);
            [sprite_data + 2] = h(b[S2 + 2]);
        }



        sprite_data = sprite_data + 18;
        tile = tile + 1;
        S2 = S2 + 3;
    8001D910	bne    tile, number_of_tiles, L1d4bc [$8001d4bc]
}

[S4 + 40] = w((w[S4 + 40] & ffffff03) | ((tile & 3f) << 2));
////////////////////////////////
