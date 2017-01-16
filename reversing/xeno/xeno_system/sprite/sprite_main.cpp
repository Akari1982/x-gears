////////////////////////////////
// func1d2e4()
struct_164 = w[GP + 20];
if( struct_164 != 0 )
{
    loop1d300:	; 8001D300
        frame_id = hu[struct_164 + 34];
        if( frame_id == 0 )
        {
            [struct_164 + 40] = w(w[struct_164 + 40] & ffffff03); // set number of tiles to 0
        }
        else
        {
            A0 = struct_164;
            A1 = frame_id;
            A2 = w[struct_164 + 24];
            func1d968();
        }

        V0 = w[struct_164 + 20];
        struct_164 = w[V0 + 38];
    8001D340	bne    struct_164, zero, loop1d300 [$8001d300]
}
[GP + 20] = w(0);
////////////////////////////////



////////////////////////////////
// func1d968()
struct_164 = A0;
frame_id = A1;
struct_110 = A2;

struct_b4 = w[struct_164 + 20];
struct_30 = S1 = w[struct_b4 + 30];
sprite_file_1 = w[struct_110 + 0];
sprite_file_2 = w[struct_110 + c];
frame_data = sprite_file_1 + hu[sprite_file_1 + frame_id * 2];



[struct_164 + 40] = w(w[struct_164 + 40] & fff7ffff); // remove 0x00080000
[struct_164 + 40] = w(w[struct_164 + 40] & fffdffff); // remove 0x00020000



// if render frame greater than numbers of frames
if( frame_id >= ( hu[sprite_file_1 + 0] & 01ff ) + 1 )
{
    return;
}



// load palettes if needed
if( w[struct_164 + 3c] & 40000000 )
{
    [struct_164 + 3c] = w(w[struct_164 + 3c] & bfffffff);

    if( hu[sprite_file_2 + 0] != 0 )
    {
        [SP + 20] = h(hu[struct_110 + 8]);
        [SP + 22] = h(hu[struct_110 + a]);
        [SP + 24] = h(hu[sprite_file_2 + 0] * 10);
        [SP + 26] = h(1);

        A0 = hu[sprite_file_2 + 0] * (hu[struct_164 + 3e] & 00f0);
        A0 = sprite_file_2 + 4 + A0 * 2; // address to load
        A1 = h[struct_110 + 8]; // x
        A2 = h[struct_110 + a]; // y
        A3 = h[sprite_file_2 + 0] * 10; // width
        A4 = 1; // height
        func24fac(); // add texture lo load to vram queue (loaded via func24e3c())
    }
}



// set up tile packets
if( hu[sprite_file_1 + 0] & 8000 )
{
    A0 = struct_164;
    A1 = frame_id; // frame id
    A2 = struct_110;
    func1d3b8(); // set up tile data to render

    return;
}



[SP + 18] = w(w[struct_110 + 4]);



if( ( w[struct_164 + 40] & 0001e000 ) == 0001c000 )
{
    A0 = SP + 18;
    A1 = bu[frame_data + 4];
    func1f3a8();
}



[struct_164 + 36] = h((b[frame_data + 3] * h[struct_164 + 2c]) >> c);
[struct_164 + 38] = h((bu[frame_data + 1] * h[struct_164 + 2c]) >> c);



number_of_tiles = bu[frame_data + 0] & 3f;
two_bytes = bu[frame_data + 0] & 80;



[SP + 38] = w((w[struct_164 + 3c] >> 5) & 7);
[SP + 48] = w((hu[SP + 18] & 3f) << 2);
[SP + 50] = w((hu[SP + 18] & 3f) << 1);
[SP + 58] = w(bu[SP + 1a]);
[SP + 40] = w(w[struct_164 + 28]);



S5 = 4;
S2 = frame_data + 6 + number_of_tiles * 4;
S6 = frame_data + 6;

if( number_of_tiles != 0 )
{
    FP = 0;

    L1dbf4:	; 8001DBF4
        [S1 + 9] = b(0);
        [S1 + 8] = b(0);
        [S1 + 14] = w(w[struct_30 + 14] & ffffffdf);

        L1dc0c:	; 8001DC0C
        8001DC0C	lbu    s0, $0000(s2)
        8001DC10	nop
        8001DC14	andi   v0, s0, $0080
        8001DC18	beq    v0, zero, L1dd34 [$8001dd34]
        8001DC1C	andi   v0, s0, $0040
        8001DC20	beq    v0, zero, L1dce4 [$8001dce4]
        8001DC24	addiu  s2, s2, $0001
        8001DC34	nop
        8001DC3C	andi   s5, s0, $0007

        if( w[struct_b4 + 34] == 0 )
        {
            A0 = 40;
            A1 = 0;
            system_memory_allocate();
            [struct_b4 + 34] = w(V0);

            A0 = struct_164;
            8001DC54	jal    func2332c [$8002332c]
        }

        8001DC5C	andi   v0, s0, $0020
        8001DC60	beq    v0, zero, L1dc98 [$8001dc98]
        8001DC64	sll    a0, s5, $03
        8001DC6C	lbu    v1, $0000(s2)
        V0 = w[struct_b4 + 34];
        8001DC74	addiu  s2, s2, $0001
        8001DC78	addu   v0, a0, v0
        8001DC7C	sb     v1, $0000(v0)
        8001DC84	lbu    v1, $0000(s2)
        V0 = w[struct_b4 + 34];
        8001DC8C	addiu  s2, s2, $0001
        8001DC90	addu   a0, a0, v0
        8001DC94	sb     v1, $0001(a0)

        L1dc98:	; 8001DC98
        8001DC98	andi   v0, s0, $0010
        8001DC9C	beq    v0, zero, L1dcc8 [$8001dcc8]
        8001DCA0	nop
        8001DCA4	lbu    a0, $0000(s2)
        8001DCA8	addiu  s2, s2, $0001
        8001DCB0	sll    a0, a0, $04
        V1 = w[struct_b4 + 34];
        8001DCB8	sll    v0, s5, $03
        8001DCBC	addu   v0, v0, v1
        8001DCC0	j      L1dc0c [$8001dc0c]
        8001DCC4	sh     a0, $0006(v0)

        L1dcc8:	; 8001DCC8
        V1 = w[struct_b4 + 34];
        8001DCD4	sll    v0, s5, $03
        8001DCD8	addu   v0, v0, v1
        8001DCDC	j      L1dc0c [$8001dc0c]
        8001DCE0	sh     zero, $0006(v0)

        L1dce4:	; 8001DCE4
        if( S0 & 4 )
        {
            [S1 + 14] = w(w[S1 + 14] | 00000020);
        }
        if( S0 & 1 )
        {
            [S1 + 8] = b(bu[S2 + 0]);
            S2 = S2 + 1;
        }
        if( S0 & 2 )
        {
            [S1 + 9] = b(bu[S2 + 0]);
            S2 = S2 + 1;
        }
        8001DD2C	j      L1dc0c [$8001dc0c]

        L1dd34:	; 8001DD34
        8001DD34	lhu    v0, $0002(s6)
        8001DD38	lhu    v1, $0000(s6)
        8001DD40	andi   a0, v0, $001f
        8001DD44	sll    v1, v1, $02
        8001DD48	sh     a0, $0020(sp)
        8001DD4C	lhu    v0, $0002(s6)
        S0 = sprite_file_1 + V1;
        8001DD54	srl    v0, v0, $05
        8001DD58	andi   v0, v0, $003f
        8001DD5C	sh     v0, $0022(sp)
        8001DD60	lhu    a3, $0002(s0)
        8001DD64	nop
        8001DD68	andi   v0, a3, $0001
        8001DD6C	beq    v0, zero, L1dd94 [$8001dd94]
        8001DD70	addiu  s6, s6, $0004
        8001DD74	sll    v0, a0, $01
        8001DD78	lw     t1, $0050(sp)
        8001DD7C	lbu    v1, $0000(s0)
        8001DD80	addu   a0, t1, v0
        8001DD84	lw     v0, $0014(s1)
        8001DD88	srl    s4, v1, $01
        8001DD8C	j      L1ddb4 [$8001ddb4]
        8001DD90	ori    v0, v0, $0008

        L1dd94:	; 8001DD94
        8001DD94	sll    v0, a0, $02
        8001DD98	lw     t1, $0048(sp)
        8001DD9C	lbu    v1, $0000(s0)
        8001DDA0	addu   a0, t1, v0
        8001DDA4	srl    s4, v1, $02
        8001DDA8	lw     v0, $0014(s1)
        8001DDAC	addiu  v1, zero, $fff7 (=-$9)
        8001DDB0	and    v0, v0, v1

        L1ddb4:	; 8001DDB4
        8001DDB4	sw     v0, $0014(s1)
        8001DDB8	lw     v0, $0014(s1)
        8001DDBC	addiu  v1, zero, $fff8 (=-$8)
        8001DDC0	sb     a0, $0004(s1)
        8001DDC4	and    v0, v0, v1
        8001DDC8	or     v0, v0, s5
        8001DDCC	sw     v0, $0014(s1)
        8001DDD0	lbu    v0, $0022(sp)
        8001DDD4	lw     t1, $0058(sp)
        8001DDD8	lw     v1, $0014(s1)
        8001DDDC	addu   v0, t1, v0
        8001DDE0	sb     v0, $0005(s1)
        8001DDE4	lbu    v0, $0000(s0)
        8001DDE8	nop
        8001DDEC	sb     v0, $0006(s1)
        8001DDF0	lbu    v0, $0001(s0)
        8001DDF4	addiu  a0, zero, $ffef (=-$11)
        8001DDF8	sb     v0, $0007(s1)
        8001DDFC	lbu    v0, $0000(s2)
        8001DE00	and    v1, v1, a0
        8001DE04	srl    v0, v0, $02
        8001DE08	andi   v0, v0, $0010
        8001DE0C	or     v1, v1, v0
        8001DE10	sw     v1, $0014(s1)
        8001DE18	lbu    v0, $0000(s2)
        8001DE1C	lw     t1, $0040(sp)
        8001DE20	srl    v0, v0, $04
        A1 = V0 & 3;
        A2 = bu[S2 + 0] & f;
        8001DE30	sw     t1, $0010(s1)


        8001DE2C	bne    a1, zero, L1de48 [$8001de48]

        A1 = hu[SP + 38];
        if( ( w[SP + 38] << 10 ) != 0 )
        {
            L1de48:	; 8001DE48
            A1 = A1 - 1;
            [S1 + 13] = b(bu[S1 + 13] | 02);
        }

        8001DE58	andi   a0, a3, $0001
        8001DE5C	sll    a0, a0, $07
        8001DE60	andi   v0, a1, $0003
        8001DE64	sll    v0, v0, $05
        8001DE68	or     a0, a0, v0
        8001DE6C	lhu    a1, $001a(sp)
        V0 = hu[SP + 18];
        8001DE74	srl    v1, a1, $04
        8001DE78	andi   v1, v1, $0010
        8001DE7C	or     a0, a0, v1
        8001DE80	andi   v0, v0, $03ff
        8001DE84	srl    v0, v0, $06
        [S1 + a] = h(A0 | V0 | ((A1 & 200) << 2));

        A0 = A2 << 4;
        A0 = h[struct_110 + 8] + A0; // clut x
        A1 = h[struct_110 + a]; // clut y
        8001DEA8	jal    func438d0 [$800438d0]

        // called many times on pc sprite change

        [S1 + c] = h(V0);

        A0 = S0 + 4;
        A1 = ((hu[SP + 18] + hu[SP + 20]) << 10) >> 10;
        A2 = ((hu[SP + 1a] + hu[SP + 22]) << 10) >> 10;
        A3 = S4;
        A4 = bu[S0 + 1];
        func24fac();

        if( two_bytes != 0 )
        {
            8001DF00	lbu    v0, $0002(s2)
            8001DF04	lbu    v1, $0001(s2)
            8001DF08	sll    v0, v0, $18
            8001DF0C	sra    v0, v0, $10
            8001DF10	or     v1, v1, v0
            8001DF14	sh     v1, $0000(s1)
            8001DF18	lbu    v1, $0003(s2)
            8001DF1C	lbu    v0, $0004(s2)
            8001DF20	addiu  s2, s2, $0002
            8001DF24	sll    v0, v0, $18
            8001DF28	sra    v0, v0, $10
            8001DF2C	or     v1, v1, v0
            8001DF34	sh     v1, $0002(s1)
        }
        else
        {
            [S1 + 0] = h(b[S2 + 1]);
            [S1 + 2] = h(b[S2 + 2]);
        }

        S1 = S1 + 18;
        S2 = S2 + 3;
        FP = FP + 1;
    8001DF70	bne    fp, number_of_tiles, L1dbf4 [$8001dbf4]
}



V1 = w[struct_164 + 40];
8001DF7C	addiu  v0, zero, $ff03 (=-$fd)
8001DF80	and    v1, v1, v0
8001DF84	andi   v0, fp, $003f
8001DF88	sll    v0, v0, $02
8001DF8C	or     v1, v1, v0
[struct_164 + 40] = w(V1);



// called on change direction of pc sprite
A0 = 0;
A1 = h[SP + 18];
A2 = h[SP + 1a];
A3 = bu[frame_data + 4];
A4 = bu[frame_data + 5];
func24fac();
////////////////////////////////



////////////////////////////////
// func1f3a8()
ret = A0;
if( ( h[GP + 26] + A1 ) >= 41 )
{
    [GP + 26] = h(0);

    [GP + 24] = h(hu[GP + 24] + 1);
    if( hu[GP + 24] >= 3 )
    {
        [GP + 24] = h(0);
    }
}
[ret + 0] = w((((h[GP + 24] << 6) + 140) << 10) | (hu[GP + 26] + 300));
[GP + 26] = h(hu[GP + 26] + A1);
return ret;
////////////////////////////////



////////////////////////////////
// func1d3b8()
// set up tile data to render
struct_164 = A0;
frame_id = A1;
struct_110 = A2;

sprite_file_1 = w[struct_110 + 0];
frame_data = sprite_file_1 + hu[sprite_file_1 + frame_id * 2];
tile_offsets = frame_data + 4;
number_of_tiles = bu[frame_data + 0] & 3f;
tile_position_setting = frame_data + 4 + number_of_tiles * 2;

[struct_164 + 36] = h((bu[frame_data + 3] * h[struct_164 + 2c]) >> c);
[struct_164 + 38] = h((bu[frame_data + 1] * h[struct_164 + 2c]) >> c);

tex_y_off = bu[struct_110 + 6];
g_abr = bu[struct_164 + 3c] >> 5;

packet_header = w[struct_164 + 28]; // 2C808080

S7 = 4;

tile = 0;

if( number_of_tiles != 0 )
{
    V0 = w[struct_164 + 20];
    tile_data = w[V0 + 30];

    L1d4bc:	; 8001D4BC
        [tile_data + 8] = b(0);
        [tile_data + 9] = b(0);
        [tile_data + 14] = w(w[tile_data + 14] & ffffffdf); // remove flip vertical flag

        L1d4d4:	; 8001D4D4
        S1 = bu[tile_position_setting];
        if( S1 & 80 )
        {
            tile_position_setting = tile_position_setting + 1;

            if( S1 & 40 )
            {
                V0 = w[struct_164 + 20];
                if( w[V0 + 34] == 0 ) // if memory not allocated
                {
                    A0 = 40; // allocate 40 byte
                    A1 = 0;
                    system_memory_allocate;
                    V1 = w[struct_164 + 20];
                    [V1 + 34] = w(V0);

                    A0 = struct_164;
                    func2332c; // set all fields to zero
                }

                S7 = S1 & 7;
                V0 = w[struct_164 + 20];
                V0 = w[V0 + 34];

                if( S1 & 20 )
                {
                    [V0 + S7 * 8 + 0] = b(bu[tile_position_setting + 0]);
                    [V0 + S7 * 8 + 1] = b(bu[tile_position_setting + 1]);
                    tile_position_setting = tile_position_setting + 2;
                }

                if( S1 & 10 )
                {
                    [V0 + S7 * 8 + 6] = h(bu[tile_position_setting] << 4);
                    tile_position_setting = tile_position_setting + 1;
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
                    [tile_data + 8] = b(bu[tile_position_setting]);
                    tile_position_setting = tile_position_setting + 1;
                }
                if( S1 & 02 ) // height increase
                {
                    [tile_data + 9] = b(bu[tile_position_setting]);
                    tile_position_setting = tile_position_setting + 1;
                }
                if( S1 & 04 ) // flip vertical
                {
                    [tile_data + 14] = w(w[tile_data + 14] | 00000020);
                }
            }
            8001D588	j      L1d4d4 [$8001d4d4]
        }



        tile_address = sprite_file_1 + hu[tile_offsets];
        tile_offsets = tile_offsets + 2;

        S1 = bu[tile_address + 0];

        if( S1 & 01 )
        {
            [tile_data + 14] = w(w[tile_data + 14] | 00000008);
            tex_x_off = (hu[struct_110 + 4] & 3f) >> 1;
        }
        else
        {
            [tile_data + 14] = w(w[tile_data + 14] & fffffff7);
            tex_x_off = (hu[struct_110 + 4] & 3f) >> 2;
        }



        [tile_data + 10] = w(packet_header);



        A2 = bu[tile_position_setting] >> 4 & 03; // abr - Semi transparency mode

        if( A2 != 0 )
        {
            [tile_data + 13] = b(bu[tile_data + 13] | 02); // semi-transparency on
            A2 = A2 - 1;
        }
        else // 0.5xB+0.5 x F
        {
            A2 = g_abr;
            if( A2 != 0 )
            {
                [tile_data + 13] = b(bu[tile_data + 13] | 02); // semi-transparency on
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
            [tile_data + a] = h(V0);

            A0 = (S1 >> 1) + f0; // x
            A1 = ((S1 >> 9) & f) + 1cc; // y
            func438d0; // ((A1 << 6) | ((A0 >> 4) & 3f)) & ffff;
            [tile_data + c] = h(V0);
        }
        else
        {
            V0 = w[struct_164 + 7c];
            V1 = w[V0 + 18];
            if( ( w[struct_164 + a8] & 00000001 ) && ( V1 != 0 ) )
            {
                V0 = V1 + ((S1 << 1) & 1c);

                tex_x_off = (hu[V0 + 0] & 3f) >> 2;
                tex_y_off = hu[V0 + 2] & ff;

                tx = (hu[V0 + 0] & 3ff) >> 6;
                ty = (hu[V0 + 2] >> 4) & 0010;
                abr = (A2 & 03) << 5;
                tp = (S1 & 01) << 7;
                tr = (hu[V0 + 2] & 0200) << 2;
                [tile_data + a] = h( tr | tp | abr | ty | tx);
            }
            else
            {
                tx = ((h[struct_110 + 4] + ((S1 << 5) & 01c0)) & 3ff) >> 6;
                ty = (hu[struct_110 + 6] >> 4) & 0010;
                abr = (A2 & 03) << 5;
                tp = (S1 & 01) << 7;
                tr = (hu[struct_110 + 6] & 0200) << 2; // Textured Rectangle X-Flip, Y-Flip
                [tile_data + a] = h( tr | tp | abr | ty | tx);
            }

            x = ((h[struct_110 + 8] + ((bu[tile_position_setting] & 0f) << 4)) >> 4) & 3f;
            y = hu[struct_110 + a] << 6;
            [tile_data + c] = h(y | x);
        }



        [tile_data + 4] = b(bu[tile_address + 1] + tex_x_off);
        [tile_data + 5] = b(bu[tile_address + 2] + tex_y_off);
        [tile_data + 6] = b(bu[tile_address + 3]);
        [tile_data + 7] = b(bu[tile_address + 4]);

        [tile_data + 14] = w((w[tile_data + 14] & fffffff8) | S7 );
        [tile_data + 14] = w((w[tile_data + 14] & ffffffef) | ((bu[tile_position_setting + 0] >> 2) & 10)); // flip horizontal if set

        if( bu[frame_data + 0] & 80 ) // double presision
        {
            [tile_data + 0] = h(hu[tile_position_setting + 1]);
            [tile_data + 2] = h(hu[tile_position_setting + 3]);
            tile_position_setting = tile_position_setting + 2;
        }
        else
        {
            [tile_data + 0] = h(b[tile_position_setting + 1]);
            [tile_data + 2] = h(b[tile_position_setting + 2]);
        }



        tile_data = tile_data + 18;
        tile = tile + 1;
        tile_position_setting = tile_position_setting + 3;
    8001D910	bne    tile, number_of_tiles, L1d4bc [$8001d4bc]
}

// store number of tiles to render
[struct_164 + 40] = w((w[struct_164 + 40] & ffffff03) | ((tile & 3f) << 2));
////////////////////////////////
