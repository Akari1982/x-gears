////////////////////////////////
// func1d3b8
S4 = A0;
frame_id = A1;
S6 = A2;

sprite_1_address = w[S6];
frame_id_offset = sprite_1_address + frame_id * 2;
frame_id_address = sprite_1_address + hu[frame_id_offset];
tile_offsets = frame_id_address + 4;
number_of_tiles = bu[frame_id_address + 0] & 3f;
tile_position_setting = frame_id_address + 4 + number_of_tiles * 2;

[SP + 48] = w(S4);

[S4 + 36] = h((bu[frame_id_address + 3] * h[S4 + 2c]) >> c);
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
        S1 = bu[tile_position_setting];
        if( S1 & 80 )
        {
            tile_position_setting = tile_position_setting + 1;

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
                    [sprite_data + 8] = b(bu[tile_position_setting]);
                    tile_position_setting = tile_position_setting + 1;
                }
                if( S1 & 02 ) // height increase
                {
                    [sprite_data + 9] = b(bu[tile_position_setting]);
                    tile_position_setting = tile_position_setting + 1;
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



        A2 = bu[tile_position_setting] >> 4 & 03; // abr - Semi transparency mode

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

            x = ((h[S6 + 8] + ((bu[tile_position_setting] & 0f) << 4)) >> 4) & 3f;
            y = hu[S6 + a] << 6;
            [sprite_data + c] = h(y | x);
        }



        [sprite_data + 4] = b(bu[tile_address + 1] + tex_x_off);
        [sprite_data + 5] = b(bu[tile_address + 2] + tex_y_off);
        [sprite_data + 6] = b(bu[tile_address + 3]);
        [sprite_data + 7] = b(bu[tile_address + 4]);

        [sprite_data + 14] = w((w[sprite_data + 14] & fffffff8) | S7 );
        [sprite_data + 14] = w((w[sprite_data + 14] & ffffffef) | ((bu[tile_position_setting + 0] >> 2) & 10)); // flip horizontal if set

        if( bu[frame_id_address + 0] & 80 ) // double presision
        {
            [sprite_data + 0] = h(hu[tile_position_setting + 1]);
            [sprite_data + 2] = h(hu[tile_position_setting + 3]);
            tile_position_setting = tile_position_setting + 2;
        }
        else
        {
            [sprite_data + 0] = h(b[tile_position_setting + 1]);
            [sprite_data + 2] = h(b[tile_position_setting + 2]);
        }



        sprite_data = sprite_data + 18;
        tile = tile + 1;
        tile_position_setting = tile_position_setting + 3;
    8001D910	bne    tile, number_of_tiles, L1d4bc [$8001d4bc]
}

[S4 + 40] = w((w[S4 + 40] & ffffff03) | ((tile & 3f) << 2));
////////////////////////////////



////////////////////////////////
// func4a5e4
VXY0 = w[A0 + 0];
VZ0  = w[A0 + 4];
VXY1 = w[A1 + 0];
VZ1  = w[A1 + 4];
VXY2 = w[A2 + 0];
VZ2  = w[A2 + 4];
gte_RTPT; // Perspective transform on 3 points.
V1 = FLAG;

[A4] = w(SXY0);
[A5] = w(SXY1);
[A6] = w(SXY2);

VXY0 = w[A3 + 0];
VZ0 = w[A3 + 4];
gte_RTPS; // Perspective transform
V0 = FLAG;

[A7] = w(SXY2);
[A8] = w(IR0); // Interpolation value for depth queing.
[A9] = w(V0 | V1);

return SZ3 >> 2;
////////////////////////////////



////////////////////////////////
// func49724
R11R12 = w[A0 + 0];
R13R21 = w[A0 + 4];
R22R23 = w[A0 + 8];
R31R32 = w[A0 + c];
R33 = w[A0 + 10];

VXY0 = (w[A1 + 4] & ffff0000) | hu[A1 + 0];
VZ0 = w[A1 + c];
gte_rtv0; // v0 * rotmatrix
T3 = IR1;
T4 = IR2;
T5 = IR3;

VXY0 = (w[A1 + 8] << 10) | hu[A1 + 2];
VZ0 = h[A1 + e];
gte_rtv0; // v0 * rotmatrix
T6 = IR1;
T7 = IR2;
T8 = IR3;

VXY0 = (w[A1 + 8] & ffff0000) | hu[A1 + 4];
VZ0 = w[A1 + 10];
gte_rtv0; // v0 * rotmatrix

R11R12 = (T6 << 10) | (T3 & ffff);
R13R21 = (T4 << 10) | (IR1 & ffff);
R22R23 = (IR2 << 10) | (T7 & ffff);
R31R32 = (T8 << 10) | (T5 & ffff);
R33 = IR3;

return A0;
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
// func1d968
S0 = A1;
S3 = A0;
S7 = A2;
A0 = fffdffff;
V1 = fff7ffff;

8001D9A8	lw     v0, $0040(s3)
8001D9B0	and    v0, v0, a0
8001D9B4	and    v0, v0, v1
8001D9B8	sw     v0, $0040(s3)
8001D9CC	lw     v1, $0020(s3)

T1 = w[S7 + 0];
[SP + 28] = w(T1);

if( S0 >= ( hu[T1] & 01ff ) + 1 )
{
    return;
}

8001D9DC	lw     s1, $0030(v1)
8001D9E4	lui    v0, $4000
8001D9E8	lw     v1, $003c(s3)
8001D9EC	nop
8001D9F0	and    v0, v1, v0
if( V0 != 0 )
{
    [S3] = w(V1 & bfffffff);
    T0 = w[S7 + c];

    if( hu[T0] != 0 )
    {
        [SP + 20] = h(hu[S7 + 8]);
        [SP + 22] = h(hu[S7 + a]);
        [SP + 26] = h(1);
        [SP + 24] = h(hu[T0] << 4);

        A0 = hu[T0] * (hu[S3 + 3e] & 00f0);
        A0 = T0 + 4 + A0 * 2; // address to load
        A1 = h[S7 + 8]; // x
        A2 = h[S7 + a]; // y
        A3 = (hu[T0] << 14) >> 10; // width
        A4 = 1; // height
        func24fac;
    }
}

8001DA84	lw     t1, $0028(sp)
8001DA88	nop
8001DA8C	lhu    v0, $0000(t1)
8001DA90	nop
8001DA94	andi   v0, v0, $8000

if( V0 != 0 )
{
    A0 = S3;
    A1 = S0; // frame id
    A2 = S7;
    func1d3b8; // fill packet data

    return;
}

8001DAB4	lui    a1, $0001
8001DAB8	ori    a1, a1, $e000
8001DABC	lui    a0, $0001
8001DAC0	sll    v0, s0, $01
8001DAC4	lw     t1, $0028(sp)
8001DAC8	lw     v1, $0024(s3)
8001DACC	addu   v0, v0, t1
8001DAD0	lhu    v0, $0000(v0)
8001DAD4	lwl    a2, $0007(v1)
8001DAD8	lwr    a2, $0004(v1)
8001DADC	nop
8001DAE0	swl    a2, $001b(sp)
8001DAE4	swr    a2, $0018(sp)
8001DAE8	lw     t1, $0028(sp)
8001DAEC	ori    a0, a0, $c000
8001DAF0	addu   v0, v0, t1
8001DAF4	sw     v0, $0030(sp)
8001DAF8	lw     v0, $0040(s3)
8001DAFC	nop
8001DB00	and    v0, v0, a1
V1 = SP + 18;

8001DB04	bne    v0, a0, L1db20 [$8001db20]

8001DB0C	lw     t1, $0030(sp)
8001DB10	nop
8001DB14	lbu    a1, $0004(t1)

A0 = V1;
8001DB18	jal    func1f3a8 [$8001f3a8]


L1db20:	; 8001DB20
8001DB20	lw     t1, $0030(sp)
8001DB24	lh     v0, $002c(s3)
8001DB28	lbu    v1, $0003(t1)
8001DB2C	nop
8001DB30	mult   v1, v0
8001DB34	lbu    v0, $0000(t1)
8001DB38	addiu  s6, t1, $0006
8001DB3C	andi   t1, v0, $0080
8001DB40	andi   v0, v0, $003f
8001DB44	sw     v0, $0060(sp)
8001DB48	sll    v0, v0, $02
8001DB4C	sb     t1, $0068(sp)
8001DB50	lw     t1, $0030(sp)
8001DB54	addiu  v0, v0, $0006
8001DB58	addu   s2, t1, v0
8001DB5C	mflo   v0
8001DB60	bgez   v0, L1db6c [$8001db6c]
8001DB64	nop
8001DB68	addiu  v0, v0, $0fff

L1db6c:	; 8001DB6C
8001DB6C	sra    v0, v0, $0c
8001DB70	sh     v0, $0036(s3)
8001DB74	lw     t1, $0030(sp)
8001DB78	lh     v0, $002c(s3)
8001DB7C	lbu    v1, $0001(t1)
8001DB80	nop
8001DB84	mult   v1, v0
8001DB88	mflo   v0
8001DB8C	bgez   v0, L1db98 [$8001db98]
8001DB90	ori    s5, zero, $0004
8001DB94	addiu  v0, v0, $0fff

L1db98:	; 8001DB98
8001DB98	lw     v1, $003c(s3)
8001DB9C	sra    v0, v0, $0c
8001DBA0	sh     v0, $0038(s3)
V0 = hu[SP + 18];
8001DBA8	srl    v1, v1, $05
8001DBAC	addu   t1, v1, zero
8001DBB0	andi   t1, t1, $0007
8001DBB4	andi   v0, v0, $003f
8001DBB8	sw     v1, $0038(sp)
8001DBBC	sw     t1, $0038(sp)
8001DBC0	sll    t1, v0, $02
8001DBC4	sw     t1, $0048(sp)
8001DBC8	lbu    t1, $001a(sp)
8001DBCC	sll    v0, v0, $01
8001DBD0	sw     v0, $0050(sp)
8001DBD4	sw     t1, $0058(sp)
8001DBD8	lw     t1, $0028(s3)
8001DBDC	nop
8001DBE0	sw     t1, $0040(sp)
8001DBE4	lw     t1, $0060(sp)
8001DBE8	nop
8001DBEC	beq    t1, zero, L1df78 [$8001df78]
8001DBF0	addu   fp, zero, zero

L1dbf4:	; 8001DBF4
8001DBF4	lw     v0, $0014(s1)
8001DBF8	addiu  v1, zero, $ffdf (=-$21)
8001DBFC	sb     zero, $0009(s1)
8001DC00	sb     zero, $0008(s1)
8001DC04	and    v0, v0, v1
8001DC08	sw     v0, $0014(s1)

L1dc0c:	; 8001DC0C
8001DC0C	lbu    s0, $0000(s2)
8001DC10	nop
8001DC14	andi   v0, s0, $0080
8001DC18	beq    v0, zero, L1dd34 [$8001dd34]
8001DC1C	andi   v0, s0, $0040
8001DC20	beq    v0, zero, L1dce4 [$8001dce4]
8001DC24	addiu  s2, s2, $0001
8001DC28	lw     v0, $0020(s3)
8001DC2C	nop
8001DC30	lw     v0, $0034(v0)
8001DC34	nop
8001DC38	bne    v0, zero, L1dc5c [$8001dc5c]
8001DC3C	andi   s5, s0, $0007
8001DC40	ori    a0, zero, $0040
8001DC44	jal    system_memory_allocate [$800319ec]
8001DC48	addu   a1, zero, zero
8001DC4C	lw     v1, $0020(s3)
8001DC50	addu   a0, s3, zero
8001DC54	jal    func2332c [$8002332c]
8001DC58	sw     v0, $0034(v1)

L1dc5c:	; 8001DC5C
8001DC5C	andi   v0, s0, $0020
8001DC60	beq    v0, zero, L1dc98 [$8001dc98]
8001DC64	sll    a0, s5, $03
8001DC68	lw     v0, $0020(s3)
8001DC6C	lbu    v1, $0000(s2)
8001DC70	lw     v0, $0034(v0)
8001DC74	addiu  s2, s2, $0001
8001DC78	addu   v0, a0, v0
8001DC7C	sb     v1, $0000(v0)
8001DC80	lw     v0, $0020(s3)
8001DC84	lbu    v1, $0000(s2)
8001DC88	lw     v0, $0034(v0)

L1dc8c:	; 8001DC8C
8001DC8C	addiu  s2, s2, $0001
8001DC90	addu   a0, a0, v0
8001DC94	sb     v1, $0001(a0)

L1dc98:	; 8001DC98
8001DC98	andi   v0, s0, $0010
8001DC9C	beq    v0, zero, L1dcc8 [$8001dcc8]
8001DCA0	nop
8001DCA4	lbu    a0, $0000(s2)
8001DCA8	addiu  s2, s2, $0001
8001DCAC	lw     v0, $0020(s3)
8001DCB0	sll    a0, a0, $04
8001DCB4	lw     v1, $0034(v0)
8001DCB8	sll    v0, s5, $03
8001DCBC	addu   v0, v0, v1
8001DCC0	j      L1dc0c [$8001dc0c]
8001DCC4	sh     a0, $0006(v0)

L1dcc8:	; 8001DCC8
8001DCC8	lw     v0, $0020(s3)
8001DCCC	nop
8001DCD0	lw     v1, $0034(v0)
8001DCD4	sll    v0, s5, $03
8001DCD8	addu   v0, v0, v1
8001DCDC	j      L1dc0c [$8001dc0c]
8001DCE0	sh     zero, $0006(v0)

L1dce4:	; 8001DCE4
8001DCE4	andi   v0, s0, $0004
8001DCE8	beq    v0, zero, L1dd04 [$8001dd04]
8001DCEC	andi   v0, s0, $0001
8001DCF0	lw     v0, $0014(s1)
8001DCF4	nop
8001DCF8	ori    v0, v0, $0020
8001DCFC	sw     v0, $0014(s1)
8001DD00	andi   v0, s0, $0001

L1dd04:	; 8001DD04
8001DD04	beq    v0, zero, L1dd1c [$8001dd1c]
8001DD08	andi   v0, s0, $0002
8001DD0C	lbu    v0, $0000(s2)
8001DD10	addiu  s2, s2, $0001
8001DD14	sb     v0, $0008(s1)
8001DD18	andi   v0, s0, $0002

L1dd1c:	; 8001DD1C
8001DD1C	beq    v0, zero, L1dc0c [$8001dc0c]
8001DD20	nop
8001DD24	lbu    v0, $0000(s2)
8001DD28	addiu  s2, s2, $0001
8001DD2C	j      L1dc0c [$8001dc0c]
8001DD30	sb     v0, $0009(s1)

L1dd34:	; 8001DD34
8001DD34	lhu    v0, $0002(s6)
8001DD38	lhu    v1, $0000(s6)
T1 = w[SP + 28];
8001DD40	andi   a0, v0, $001f
8001DD44	sll    v1, v1, $02
8001DD48	sh     a0, $0020(sp)
8001DD4C	lhu    v0, $0002(s6)
S0 = T1 + V1;
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
8001DE14	lbu    v1, $0000(s2)
8001DE18	lbu    v0, $0000(s2)
8001DE1C	lw     t1, $0040(sp)
8001DE20	srl    v0, v0, $04
8001DE24	andi   a1, v0, $0003
8001DE28	andi   a2, v1, $000f
8001DE2C	bne    a1, zero, L1de48 [$8001de48]
8001DE30	sw     t1, $0010(s1)
8001DE34	lw     t1, $0038(sp)
8001DE38	lhu    a1, $0038(sp)
8001DE3C	sll    v0, t1, $10
8001DE40	beq    v0, zero, L1de58 [$8001de58]
8001DE44	nop

L1de48:	; 8001DE48
8001DE48	lbu    v0, $0013(s1)
8001DE4C	addiu  a1, a1, $ffff (=-$1)
8001DE50	ori    v0, v0, $0002
8001DE54	sb     v0, $0013(s1)

L1de58:	; 8001DE58
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
8001DE88	or     a0, a0, v0
8001DE8C	andi   a1, a1, $0200
8001DE90	sll    a1, a1, $02
8001DE94	or     a0, a0, a1
8001DE98	sh     a0, $000a(s1)
8001DE9C	sll    a0, a2, $04
8001DEA0	lh     v0, $0008(s7)
8001DEA4	lh     a1, $000a(s7)
8001DEAC	addu   a0, v0, a0
8001DEA8	jal    func438d0 [$800438d0]

// called many tines on pc sprite change

[S1 + c] = h(V0);

A0 = S0 + 4;
A1 = ((hu[SP + 18] + hu[SP + 20]) << 10) >> 10;
A2 = ((hu[SP + 1a] + hu[SP + 22]) << 10) >> 10;
A3 = S4;
A4 = bu[S0 + 1];
func24fac;

8001DEF0	lbu    t1, $0068(sp)
8001DEF4	nop
8001DEF8	beq    t1, zero, L1df38 [$8001df38]
8001DEFC	nop
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
8001DF30	j      L1df60 [$8001df60]
8001DF34	sh     v1, $0002(s1)

L1df38:	; 8001DF38
8001DF38	lbu    v0, $0001(s2)
8001DF3C	nop
8001DF40	sll    v0, v0, $18
8001DF44	sra    v0, v0, $18
8001DF48	sh     v0, $0000(s1)
8001DF4C	lbu    v0, $0002(s2)
8001DF50	nop
8001DF54	sll    v0, v0, $18
8001DF58	sra    v0, v0, $18
8001DF5C	sh     v0, $0002(s1)

L1df60:	; 8001DF60
8001DF60	addiu  s1, s1, $0018
8001DF64	addiu  fp, fp, $0001
8001DF68	lw     t1, $0060(sp)
8001DF6C	nop
8001DF70	bne    fp, t1, L1dbf4 [$8001dbf4]
8001DF74	addiu  s2, s2, $0003

L1df78:	; 8001DF78
8001DF78	lw     v1, $0040(s3)
8001DF7C	addiu  v0, zero, $ff03 (=-$fd)
8001DF80	and    v1, v1, v0
8001DF84	andi   v0, fp, $003f
8001DF88	sll    v0, v0, $02
8001DF8C	or     v1, v1, v0
8001DF90	sw     v1, $0040(s3)

// called on change direction of pc sprite

T1 = w[SP + 30];

A0 = 0;
A1 = h[SP + 18];
A2 = h[SP + 1a];
A3 = bu[T1 + 4];
A4 = bu[T1 + 5];
func24fac;

L1dfb4:	; 8001DFB4
////////////////////////////////



////////////////////////////////
// func24fac
T0 = w[GP + 40c];
V0 = w[GP + 3c0];

T1 = T0 + 10;
if( T1 < V0 )
{
    [T0 + 0] = h(A1); // x
    [T0 + 2] = h(A2); // y
    [T0 + 4] = h(A3); // width
    [T0 + 6] = h(A4); // height
    [T0 + 8] = w(A0); // address to load

    V0 = w[GP + 188];
    V1 = w[80058b60 + V0 * 4];
    [T0 + c] = w(V1);

    [GP + 40c] = w(T1);
    [80058b60 + V0 * 4] = w(T0);
}
////////////////////////////////



////////////////////////////////
// func22bcc
V1 = (w[A0 + a8] >> b) & 3f;

if( V1 < 0 )
{
    V1 = 0;
}

V0 = w[A0 + 54];
var = hu[V0 + V1 * 2];

if( var & 0200 )
{
    [A0 + ac] = w(V0 = w[A0 + ac] | 00000020);
}
else
{
    [A0 + ac] = w(w[A0 + ac] & ffffffdf);
}

V1 = w[A0 + ac];
[A0 + 3c] = w((w[A0 + 3c] & fffffff7) | ((((V1 >> 5) & 1) XOR ((V1 >> 4) & 1)) << 3));

A0 = A0;
A1 = var & 01ff;
func1d134;
////////////////////////////////



////////////////////////////////
// func1d2e4
S0 = w[GP + 20];
if( S0 != 0 )
{
    loop1d300:	; 8001D300
        A1 = hu[S0 + 34];
        if( A1 == 0 )
        {
            [S0 + 40] = w(w[S0 + 40] & ffffff03);
        }
        else
        {
            A0 = S0;
            A1 = A1;
            A2 = w[S0 + 24];
            func1d968;
        }

        V0 = w[S0 + 20];
        S0 = w[V0 + 38];
    8001D340	bne    s0, zero, loop1d300 [$8001d300]
}
[GP + 20] = w(0);
////////////////////////////////



////////////////////////////////
// func1d134
S0 = A0;
8001D148	lw     v0, $003c(s0)
8001D14C	ori    v1, zero, $0001
8001D150	andi   v0, v0, $0003
S1 = A1;
8001D154	beq    v0, v1, L1d164 [$8001d164]

8001D15C	j      L1d258 [$8001d258]
8001D160	sh     zero, $0034(s0)

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
8001D198	jal    func2332c [$8002332c]
8001D19C	addu   a0, s0, zero

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
8001D20C	jal    func1f764 [$8001f764]
8001D210	addu   a0, s0, zero

L1d214:	; 8001D214
[S0 + 34] = h(S1);
8001D214	j      L1d258 [$8001d258]

L1d21c:	; 8001D21C
8001D21C	lw     v0, $0020(v0)
8001D220	nop
8001D224	lw     v0, $0038(v0)
8001D228	nop
8001D22C	bne    v0, zero, loop1d1d4 [$8001d1d4]
8001D230	nop

L1d234:	; 8001D234
8001D234	lw     a1, $0020(gp)
8001D238	lw     v0, $0040(s0)
8001D23C	lw     a0, $0020(s0)
8001D240	lui    v1, $0002
[S0 + 34] = h(S1);
8001D248	sw     s0, $0020(gp)
8001D24C	or     v0, v0, v1
8001D250	sw     v0, $0040(s0)
8001D254	sw     a1, $0038(a0)

L1d258:	; 8001D258
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



////////////////////////////////
// func2332c
A1 = 0;
A2 = 8;

loop23334:	; 80023334
    V0 = w[A0 + 20];
    V0 = w[V0 + 34];
    [V0 + A1 * 8 + 0] = b(0);
    [V0 + A1 * 8 + 1] = b(0);
    [V0 + A1 * 8 + 2] = h(0);
    [V0 + A1 * 8 + 4] = h(0);
    [V0 + A1 * 8 + 6] = h(0);
    A1 = A1 + 1;
800233A8	bne    a1, a2, loop23334 [$80023334]
////////////////////////////////
