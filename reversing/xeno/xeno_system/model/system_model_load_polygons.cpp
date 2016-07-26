                A0 = texture_data_offset;
                A1 = mesh_data_offset;
                A2 = S5;

8004f4f4 data for load 3d data.
// load_poly functions
//                                                         18       1c       20       24
//00 48DE0280 30EB0280 80E20280 ECE60280 48DE0280 48DE0280 DCCB0280 08000000 04000000 14000000
//01 5CDE0280 F0F00280 94E20280 00E70280 1CED0280 F4EE0280 24D60280 08000000 08000000 20000000 textured monochrome triangle (with lighting calculation)
//02 34DE0280 C4F40280 6CE20280 D8E60280 34DE0280 34DE0280 BCD40280 08000000 04000000 1C000000
//03 20DE0280 C4F20280 58E20280 C4E60280 20DE0280 20DE0280 24D80280 08000000 08000000 28000000 textured gourad triangle (with lighting calculation)
//04 48DE0280 48DE0280 80E20280 ECE60280 48DE0280 48DE0280 44CD0280 08000000 04000000 14000000 monochrome triangle
//05 5CDE0280 5CDE0280 94E20280 00E70280 1CED0280 F4EE0280 94D70280 08000000 08000000 20000000 textured monochrome triangle
//06 34DE0280 34DE0280 6CE20280 D8E60280 34DE0280 34DE0280 8CD50280 08000000 04000000 1C000000
//07 20DE0280 20DE0280 58E20280 C4E60280 20DE0280 20DE0280 24D80280 08000000 08000000 28000000
//08 64E00280 E0F60280 84E40280 F0E80280 64E00280 64E00280 68CD0280 08000000 04000000 18000000
//09 78E00280 F8F80280 98E40280 04E90280 0CFB0280 1CFD0280 40D30280 08000000 0C000000 28000000 textured monochrome quad (with lighting calculation)
//0a 50E00280 50E00280 70E40280 DCE80280 50E00280 50E00280 90CF0280 08000000 04000000 24000000
//0b 3CE00280 3CE00280 5CE40280 C8E80280 3CE00280 3CE00280 54D00280 08000000 0C000000 34000000
//0c 64E00280 64E00280 84E40280 F0E80280 64E00280 64E00280 D0CE0280 08000000 04000000 18000000 monochrome quad
//0d 78E00280 78E00280 98E40280 04E90280 0CFB0280 1CFD0280 F4CE0280 08000000 0C000000 28000000 textured monochrome quad
//0e 50E00280 50E00280 70E40280 DCE80280 50E00280 50E00280 90CF0280 08000000 04000000 24000000
//0f 3CE00280 3CE00280 5CE40280 C8E80280 3CE00280 3CE00280 54D00280 08000000 0C000000 34000000
+18 - function to fill the packet.
+1c - size of polygon data.
+20 - size of tex data.
+24 - size of packets data.



////////////////////////////////
// load_poly_00_18
// A0 = texture_data_offset;
// A1 = mesh_data_offset;
// A2 = S5;
// S5 = 0; // not calculate light
// S5 = 1; // calculate light but not store it
// S5 = 3; // calculate light and store it
// S5 = 4; // use calculated stored light

texture_data_offset = S0 = A0;
S1 = w[80068ac0];
8002CBF4	ori    v0, zero, $0004
8002CBFC	sb     v0, $0003(s1)
8002CC00	andi   v0, a2, $0001
8002CC04	beq    v0, zero, L2cccc [$8002cccc]
8002CC08	addu   t0, a1, zero
8002CC0C	andi   v0, a2, $0002
8002CC10	beq    v0, zero, L2cc84 [$8002cc84]
8002CC14	addiu  a3, sp, $0010
8002CC18	lui    v1, $8006
8002CC1C	lw     v1, $8b34(v1)
8002CC20	lw     v0, $0000(s0)
8002CC24	nop
8002CC28	sw     v0, $0000(v1)
8002CC2C	lh     a0, $0000(t0)
8002CC30	lui    v0, $8006
8002CC34	lw     v0, $8bd8(v0)
8002CC38	lh     a1, $0002(t0)
8002CC3C	lh     a2, $0004(t0)
8002CC40	lui    a3, $8006
8002CC44	lw     a3, $8b34(a3)
8002CC48	sll    a0, a0, $03
8002CC4C	addu   a0, v0, a0
8002CC50	sll    a1, a1, $03
8002CC54	addu   a1, v0, a1
8002CC58	sll    a2, a2, $03
8002CC5C	addiu  a3, a3, $0004
8002CC60	lui    at, $8006
8002CC64	sw     a3, $8b34(at)
8002CC6C	addu   a2, v0, a2
8002CC68	jal    system_calculate_normal_for_lighting [$8002d994]

8002CC70	addu   a1, s0, zero
8002CC74	lui    a0, $8006
8002CC78	lw     a0, $8b34(a0)
8002CC7C	j      L2ccf0 [$8002ccf0]
8002CC80	addiu  a2, s1, $0004

L2cc84:	; 8002CC84
8002CC84	lh     a0, $0000(t0)
8002CC88	lui    v0, $8006
8002CC8C	lw     v0, $8bd8(v0)
8002CC90	lh     a1, $0002(t0)
8002CC94	lh     a2, $0004(t0)
8002CC98	sll    a0, a0, $03
8002CC9C	addu   a0, v0, a0
8002CCA0	sll    a1, a1, $03
8002CCA4	addu   a1, v0, a1
8002CCA8	sll    a2, a2, $03
8002CCAC	jal    system_calculate_normal_for_lighting [$8002d994]
8002CCB0	addu   a2, v0, a2
8002CCB4	addiu  a0, sp, $0010
8002CCB8	addu   a1, s0, zero
8002CCBC	jal    func4a108 [$8004a108]
8002CCC0	addiu  a2, s1, $0004
8002CCC4	j      L2cd10 [$8002cd10]
8002CCC8	nop

L2cccc:	; 8002CCCC
8002CCCC	andi   v0, a2, $0004
8002CCD0	beq    v0, zero, L2cd1c [$8002cd1c]
8002CCD4	addu   a1, s0, zero
8002CCD8	lui    a0, $8006
8002CCDC	lw     a0, $8b34(a0)
8002CCE0	addiu  a2, s1, $0004
8002CCE4	addiu  a0, a0, $0004
8002CCE8	lui    at, $8006
8002CCEC	sw     a0, $8b34(at)

L2ccf0:	; 8002CCF0
8002CCF0	jal    func4a108 [$8004a108]
8002CCF4	nop
8002CCF8	lui    v0, $8006
8002CCFC	lw     v0, $8b34(v0)
8002CD00	nop
8002CD04	addiu  v0, v0, $0008
8002CD08	lui    at, $8006
8002CD0C	sw     v0, $8b34(at)

L2cd10:	; 8002CD10
8002CD10	lbu    v0, $0003(s0)
8002CD14	j      L2cd28 [$8002cd28]
8002CD18	sb     v0, $0007(s1)

L2cd1c:	; 8002CD1C
8002CD1C	lw     v0, $0000(s0)
8002CD20	nop
8002CD24	sw     v0, $0004(s1)

L2cd28:	; 8002CD28
return 1;
////////////////////////////////






////////////////////////////////
L2de68:	; 8002DE68
// A0 - must be offset ot mesh block.
// A1 - number of polygons
S0 = w[80058bd8];
S2 = w[80058c14];
S3 = w[80058ac0]; // offset to place for packets
S4 = w[80058c04];
V0 = w[8004f7a0];
V1 = w[8004f79c];
T7 = w[8004f7a4];
vertex1 = hu[A0 + 0];
vertex2 = hu[A0 + 2];
vertex3 = hu[A0 + 4];

VXY0 = w[S0 + vertex1 * 8 + 0];
VZ0 = w[S0 + vertex1 * 8 + 4];
VXY1 = w[S0 + vertex2 * 8 + 0];
VZ1 = w[S0 + vertex2 * 8 + 4];
VXY2 = w[S0 + vertex3 * 8 + 0];
VZ2 = w[S0 + vertex3 * 8 + 4];

S3 = S3 - A3;
S6 = 00ffffff;

while (true)
{
    loop2df0c:	; 8002DF0C
    gte_RTPT;

    if (A1 == 0)
    {
        break;
    }

    A1 = A1 - 1;
    A0 = A0 + 8;
    T4 = w[A0 + 0];
    T5 = hu[A0 + 4];
    S3 = S3 + A3;
    8002DF28	andi   t0, t4, $ffff
    8002DF2C	sll    t0, t0, $03
    8002DF30	addu   t0, t0, s0
    8002DF34	lwc2   zero, $0000(t0)
    8002DF38	lwc2   at, $0004(t0)
    8002DF3C	srl    t0, t4, $0d
    8002DF40	andi   t0, t0, $fff8
    8002DF44	addu   t0, t0, s0
    VXY1 = w[T0 + 0];
    VZ1 = w[T0 + 4];

    8002DF50	sll    t0, t5, $03
    8002DF54	addu   t0, t0, s0
    8002DF58	lwc2   a0, $0000(t0)
    8002DF5C	lwc2   a1, $0004(t0)
    T0 = LZCR;
    if (T0 < 0)
    {
        continue;
    }

    T1 = SXY0;
    T2 = SXY1;
    T3 = SXY2;

    gte_NCLIP;

    if (T1 >= V0 && T2 >= V0 && T3 >= V0)
    {
        continue;
    }

    T0 = T1 & ffff;

    8002DF94	sltu   t0, t0, v1
    8002DF98	bne    t0, zero, L2dfb4 [$8002dfb4]
    8002DF9C	andi   t0, t2, $ffff
    8002DFA0	sltu   t0, t0, v1
    8002DFA4	bne    t0, zero, L2dfb4 [$8002dfb4]
    8002DFA8	andi   t0, t3, $ffff
    8002DFAC	sltu   t0, t0, v1
    8002DFB0	beq    t0, zero, loop2df0c [$8002df0c]

    L2dfb4:	; 8002DFB4
    8002DFB4	mfc2   t4,ofx
    8002DFB8	gte_func26t8,r11r12
    8002DFBC	blez   t4, loop2df0c [$8002df0c]
    8002DFC0	and    s3, s3, s6
    [S3 + 8] = w(T1);
    T0 = S3 + T9;
    [T0 + 8] = w(T2);
    T0 = T0 + T9;
    [T0 + 8] = w(T3);

    8002DFD8	mfc2   t5,trz
    8002DFDC	addiu  s2, s2, $0001
    8002DFE0	beq    t5, zero, loop2df0c [$8002df0c]
    8002DFE4	srav   t5, t7, t5
    8002DFE8	sll    t5, t5, $02
    8002DFEC	addu   t5, t5, s4
    8002DFF0	lw     t1, $0000(t5)
    [T5] = w(S3);
    8002DFF8	or     t1, t1, t8
    [S3 + 0] = w(T1);
}

S3 = S3 + A3;
[80058c14] = w(S2);
[80058ac0] = w(S3);
////////////////////////////////



////////////////////////////////
// load_poly_01_14
T9 = 8;
T8 = 07000000;
A3 = 20;

S0 = w[80058bd8];
S2 = w[80058c14];
S3 = w[80058ac0]; // offset to place for packets
S4 = w[80058c04];
V0 = w[8004f7a0];
V1 = w[8004f79c];
T7 = w[8004f7a4];
T7 = T7 + 2;

vertex1 = hu[A0 + 0];
vertex2 = hu[A0 + 2];
vertex3 = hu[A0 + 4];

VXY0 = w[S0 + vertex1 * 8 + 0];
VZ0 = w[S0 + vertex1 * 8 + 4];
VXY1 = w[S0 + vertex2 * 8 + 0];
VZ1 = w[S0 + vertex2 * 8 + 4];
VXY2 = w[S0 + vertex3 * 8 + 0];
VZ2 = w[S0 + vertex3 * 8 + 4];

S3 = S3 - A3;
S6 = 00ffffff;
RGB = w[80058c34]; 

while (true)
{
    8002EFB4	gte_func1t0,r11r12

    if (A1 == 0)
    {
        break;
    }

    8002EFBC	addiu  a1, a1, $ffff (=-$1)
    8002EFC0	addiu  a0, a0, $0008
    8002EFC4	lw     t4, $0000(a0)
    8002EFC8	lhu    t5, $0004(a0)
    8002EFCC	addu   s3, s3, a3
    8002EFD0	andi   t0, t4, $ffff
    8002EFD4	sll    t0, t0, $03
    8002EFD8	addu   t0, t0, s0
    8002EFDC	lwc2   zero, $0000(t0)
    8002EFE0	lwc2   at, $0004(t0)
    8002EFE4	srl    t0, t4, $0d
    8002EFE8	andi   t0, t0, $fff8
    8002EFEC	addu   t0, t0, s0
    8002EFF0	lwc2   v0, $0000(t0)
    8002EFF4	lwc2   v1, $0004(t0)
    8002EFF8	sll    t0, t5, $03
    8002EFFC	addu   t0, t0, s0
    8002F000	lwc2   a0, $0000(t0)
    8002F004	lwc2   a1, $0004(t0)
    8002F008	mfc2   t0,flag
    8002F00C	mfc2   t1,l33
    8002F010	bltz   t0, loop2efb4 [$8002efb4]
    8002F014	sltu   t0, t1, v0
    8002F018	mfc2   t2,rbk
    8002F01C	mfc2   t3,gbk
    8002F020	gte_func26zero,r11r12
    8002F024	bne    t0, zero, L2f038 [$8002f038]
    8002F028	sltu   t0, t2, v0
    8002F02C	bne    t0, zero, L2f038 [$8002f038]
    8002F030	sltu   t0, t3, v0
    8002F034	beq    t0, zero, loop2efb4 [$8002efb4]

    L2f038:	; 8002F038
    8002F038	gte_func3t8,r11r12
    8002F03C	andi   t0, t1, $ffff
    8002F040	sltu   t0, t0, v1
    8002F044	bne    t0, zero, L2f060 [$8002f060]
    8002F048	andi   t0, t2, $ffff
    8002F04C	sltu   t0, t0, v1
    8002F050	bne    t0, zero, L2f060 [$8002f060]
    8002F054	andi   t0, t3, $ffff
    8002F058	sltu   t0, t0, v1
    8002F05C	beq    t0, zero, loop2efb4 [$8002efb4]

    L2f060:	; 8002F060
    8002F060	mfc2   t4,ofx
    8002F064	mfc2   t5,lg2lg3
    8002F068	blez   t4, loop2efb4 [$8002efb4]
    8002F06C	and    s3, s3, s6
    8002F070	sw     t1, $0008(s3)
    8002F074	addu   t0, s3, t9
    8002F078	sw     t2, $0008(t0)
    8002F07C	mfc2   t2,lb1lb2
    8002F080	addu   t0, t0, t9
    8002F084	sw     t3, $0008(t0)
    8002F088	mfc2   t0,lr3lg1
    8002F08C	nop
    8002F090	slt    t3, t5, t0
    8002F094	bne    t3, zero, L2f0a0 [$8002f0a0]
    8002F098	lbu    t1, $0007(s3)
    8002F09C	addu   t0, t5, zero

    L2f0a0:	; 8002F0A0
    8002F0A0	slt    t3, t2, t0
    8002F0A4	bne    t3, zero, L2f0b0 [$8002f0b0]
    8002F0A8	addiu  s2, s2, $0001
    8002F0AC	addu   t0, t2, zero

    L2f0b0:	; 8002F0B0
    8002F0B0	mfc2   t2,gfc
    8002F0B4	beq    t0, zero, loop2efb4 [$8002efb4]
    8002F0B8	srav   t0, t7, t0
    8002F0BC	sll    t0, t0, $02
    8002F0C0	addu   t0, t0, s4
    8002F0C4	sll    t1, t1, $18
    8002F0C8	lui    at, $fe00
    8002F0CC	and    t1, t1, at
    8002F0D0	and    t2, t2, s6
    8002F0D4	or     t1, t1, t2
    8002F0D8	sw     t1, $0004(s3)
    8002F0DC	lw     t1, $0000(t0)
    8002F0E0	sw     s3, $0000(t0)
    8002F0E4	or     t1, t1, t8
    8002F0EC	sw     t1, $0000(s3)
8002F0E8	j      loop2efb4 [$8002efb4]

L2e004:	; 8002E004
S3 = S3 + A3;
[80058c14] = w(S2);
[80058ac0] = w(S3);
////////////////////////////////









L2e004:	; 8002E004
S3 = S3 + A3;
[80058c14] = w(S2);
[80058ac0] = w(S3);
