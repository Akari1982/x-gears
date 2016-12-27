////////////////////////////////
// func31f0c()
A1 = A0;
if( A1 == 0 )
{
    if( w[GP + 1c0] != 0 )
    {
        return 1;
    }

    [SP + 10] = w(RA);
    [GP + 1cc] = w(0);
    [GP + 1d0] = w(w[SP + 10] - 8);

    A0 = 83;
    func19b50();
}

A0 = w[A1 - 4];
if( ( A0 & 02000000 ) == 0 )
{
    [A1 - 4] = w((((A0 & 03ffffff) | 84000000) & fe1fffff) & ffe00000);
    [GP + 1bc] = w(1);
    return 0;
}
else
{
    return -1;
}
////////////////////////////////



////////////////////////////////
// func19b50()
if( A0 != 0 )
{
    V0 = SP + 10;
    80019B68	addu   t7, v0, zero
    80019B6C	sw     ra, $0000(t7)

    A1 = w[SP + 10];
    func19dcc();
}

80019B7C	ori    a0, zero, $0001
80019B80	lui    v0, $8002
80019B84	lw     v0, $8088(v0)
80019B88	lui    v1, $8002
80019B8C	addiu  v1, v1, $808c (=-$7f74)
80019B90	sll    v0, v0, $04
80019B94	jal    func43f88 [$80043f88]
80019B98	addu   s1, v0, v1
80019B9C	jal    func44350 [$80044350]
80019BA0	addu   a0, zero, zero
80019BA4	jal    func36298 [$80036298]
80019BA8	addu   a0, zero, zero
80019BAC	jal    func44448 [$80044448]
80019BB0	addu   a0, zero, zero
80019BB4	jal    func4b3f4 [$8004b3f4]
80019BB8	ori    a0, zero, $0002
80019BBC	lw     a0, $0008(s1)
80019BC0	jal    func31920 [$80031920]
80019BC4	addiu  a0, a0, $0800
80019BC8	jal    func19d00 [$80019d00]

if( w[S1 + c] != 0 )
{
    80019BE0	lw     a0, $0004(s1)
    80019BE4	lw     a1, $0008(s1)
    80019BE8	jal    func195f4 [$800195f4]
    80019BEC	nop

    A0 = w[80018088];
    func19a50();
    S0 = V0;

    A0 = 0;
    80019C04	jal    func28870 [$80028870]

    A0 = S0; // from
    A1 = w[80018084]; // where
    system_extract_archive();

    A0 = 0;
    80019C1C	jal    func44448 [$80044448]

    80019C28	addu   a0, zero, zero
    80019C24	jal    func4b3f4 [$8004b3f4]

    80019C2C	jal    func4034c [$8004034c]

    80019C38	addu   a0, zero, zero
    80019C34	jal    func44448 [$80044448]

    80019C40	addu   a0, zero, zero
    80019C3C	jal    func4b3f4 [$8004b3f4]

    80019C44	jal    func402cc [$800402cc]

    80019C4C	jal    func4035c [$8004035c]
}

80019C54	jal    func195dc [$800195dc]
80019C58	nop
80019C5C	lw     a0, $0008(s1)
80019C60	jal    func31920 [$80031920]
80019C64	addiu  a0, a0, $0004
80019C68	jal    func31840 [$80031840]
80019C6C	nop
80019C70	jal    func35c84 [$80035c84]
80019C74	nop
80019C78	jal    func199f0 [$800199f0]
80019C7C	addu   a0, zero, zero
80019C80	lw     v0, $0000(s1)

80019C88	jalr   v0 ra

A0 = 0;
80019C90	jal    func19b50 [$80019b50]
////////////////////////////////



////////////////////////////////
// func19dcc()
S2 = A0; // file?
S3 = A1;
S1 = 0;

if( ( w[80010000] + 1 ) >= 2 )
{
    A0 = 80018198; // filename "c:\lserrmem.txt"
    func32c28(); // write debug file

    80019E14	j      L19e50 [$80019e50]
}

80019E1C	addiu  a0, sp, $0110
80019E20	ori    a1, zero, $00ff
80019E24	addu   a2, zero, zero
80019E28	addu   a3, zero, zero
80019E2C	ori    v0, zero, $0280
80019E30	sh     v0, $0114(sp)
80019E34	ori    v0, zero, $01e0
80019E38	sh     zero, $0110(sp)
80019E3C	sh     zero, $0112(sp)
80019E40	jal    func445dc [$800445dc]
80019E44	sh     v0, $0116(sp)

L19e48:	; 80019E48
80019E48	j      L19e48 [$80019e48]
80019E4C	nop

L19e50:	; 80019E50
80019E50	jal    func320d8 [$800320d8]
80019E54	ori    s0, zero, $00f0
80019E58	addiu  a0, sp, $0030
80019E5C	addu   a1, zero, zero
80019E60	addu   a2, zero, zero
80019E64	ori    a3, zero, $0180
80019E68	jal    func437a0 [$800437a0]
80019E6C	sw     s0, $0010(sp)
80019E70	addiu  a0, sp, $00e8
80019E74	addu   a1, zero, zero
80019E78	ori    a2, zero, $00f0
80019E7C	ori    a3, zero, $0180
80019E80	jal    func43858 [$80043858]
80019E84	sw     s0, $0010(sp)
80019E88	addiu  a0, sp, $008c
80019E8C	addu   a1, zero, zero
80019E90	ori    a2, zero, $00f0
80019E94	ori    a3, zero, $0180
80019E98	jal    func437a0 [$800437a0]
80019E9C	sw     s0, $0010(sp)
80019EA0	addiu  a0, sp, $00fc
80019EA4	addu   a1, zero, zero
80019EA8	addu   a2, zero, zero
80019EAC	ori    a3, zero, $0180
80019EB0	jal    func43858 [$80043858]
80019EB4	sw     s0, $0010(sp)
80019EB8	jal    func44350 [$80044350]
80019EBC	addu   a0, zero, zero
80019EC0	jal    func36298 [$80036298]
80019EC4	addu   a0, zero, zero
80019EC8	ori    a0, zero, $0010
80019ECC	ori    a1, zero, $0010
80019ED0	ori    a2, zero, $0120
80019ED4	ori    a3, zero, $00f0
80019ED8	ori    v0, zero, $01f4
80019EDC	ori    v1, zero, $03c0
80019EE0	sw     v0, $0010(sp)
80019EE4	ori    v0, zero, $0100
80019EE8	sw     v0, $001c(sp)
80019EEC	ori    v0, zero, $01ff
80019EF0	sw     zero, $0014(sp)
80019EF4	sw     v1, $0018(sp)
80019EF8	sw     v1, $0020(sp)
80019EFC	sw     v0, $0024(sp)
80019F00	jal    func37390 [$80037390]
80019F04	sw     zero, $0028(sp)
80019F08	lui    v1, $8005
80019F0C	lw     v1, $e964(v1)
80019F10	ori    v0, zero, $0001
80019F14	sb     v0, $00a4(sp)
80019F18	sb     v0, $0048(sp)
80019F1C	sb     zero, $0049(sp)
80019F20	sb     zero, $004a(sp)
80019F24	sb     zero, $004b(sp)
80019F28	sb     zero, $00a5(sp)
80019F2C	sb     zero, $00a6(sp)
80019F30	sb     zero, $00a7(sp)
80019F34	addiu  v1, v1, $0001
80019F38	lui    at, $8005
80019F3C	sw     v1, $e964(at)
80019F40	jal    func443ac [$800443ac]
80019F44	ori    a0, zero, $0001

L19f48:	; 80019F48
80019F48	andi   s0, s1, $0001
80019F4C	bne    s0, zero, L19f58 [$80019f58]
80019F50	addiu  a0, sp, $0030
80019F54	addiu  a0, sp, $008c

L19f58:	; 80019F58
80019F58	jal    func44abc [$80044abc]
80019F5C	nop
80019F60	bne    s0, zero, L19f6c [$80019f6c]
80019F64	addiu  a0, sp, $00e8
80019F68	addiu  a0, sp, $00fc

L19f6c:	; 80019F6C
80019F6C	jal    func44d14 [$80044d14]
80019F70	nop
80019F74	jal    func371cc [$800371cc]
80019F78	addu   a0, zero, zero

A0 = 800181a8;
A1 = S2;
80019F84	jal    func36eb4 [$80036eb4]

80019F8C	lui    a0, $8002
80019F90	addiu  a0, a0, $81bc (=-$7e44)
80019F94	jal    func36eb4 [$80036eb4]
80019F98	addu   a1, s3, zero
80019F9C	lui    a1, $8005
80019FA0	lw     a1, $e964(a1)
80019FA4	lui    a0, $8002
80019FA8	addiu  a0, a0, $81c8 (=-$7e38)
80019FAC	jal    func36eb4 [$80036eb4]
80019FB0	nop
80019FB4	lui    a0, $8002
80019FB8	addiu  a0, a0, $81d4 (=-$7e2c)
80019FBC	jal    func36eb4 [$80036eb4]
80019FC0	addu   a1, s1, zero
80019FC4	lui    a0, $8002
80019FC8	addiu  a0, a0, $81e0 (=-$7e20)
80019FCC	jal    func36eb4 [$80036eb4]
80019FD0	nop
80019FD4	lui    a0, $8002
80019FD8	addiu  a0, a0, $8200 (=-$7e00)
80019FDC	jal    func36eb4 [$80036eb4]
80019FE0	nop
80019FE4	andi   v0, s2, $0080
80019FE8	beq    v0, zero, L1a048 [$8001a048]
80019FEC	sll    v0, s2, $02
80019FF0	lui    at, $8005
80019FF4	addu   at, at, v0
80019FF8	lw     a1, $e768(at)
80019FFC	lui    a0, $8002
8001A000	addiu  a0, a0, $8204 (=-$7dfc)
8001A004	jal    func36eb4 [$80036eb4]
8001A008	nop
8001A00C	ori    v0, zero, $0082
8001A010	bne    s2, v0, L1a048 [$8001a048]
8001A014	addiu  a0, sp, $0120
8001A018	jal    func319d4 [$800319d4]
8001A01C	addiu  a1, sp, $0124
8001A020	lw     a1, $0120(sp)
8001A024	lui    a0, $8002
8001A028	addiu  a0, a0, $8208 (=-$7df8)
8001A02C	jal    func36eb4 [$80036eb4]
8001A030	nop
8001A034	lw     a1, $0124(sp)
8001A038	lui    a0, $8002
8001A03C	addiu  a0, a0, $821c (=-$7de4)
8001A040	jal    func36eb4 [$80036eb4]
8001A044	addu   a2, a1, zero

L1a048:	; 8001A048
8001A048	jal    func4b3f4 [$8004b3f4]
8001A04C	addu   a0, zero, zero
8001A050	j      L19f48 [$80019f48]
8001A054	addiu  s1, s1, $0001
////////////////////////////////



////////////////////////////////
// func19a50
S0 = A0;
if( w[8005895c] != S0 )
{
    [8005895c] = w(S0);

    S2 = hu[GP + 1ac];

    A0 = SP + 10;
    A1 = SP + 14;
    80019A8C	jal    func282c4 [$800282c4]

    A0 = 6;
    80019A94	jal    func319b8 [$800319b8]

    A0 = 0;
    A1 = 1;
    80019AA0	jal    func28280 [$80028280]

    A0 = 1;
    80019AA8	jal    func319c4 [$800319c4]

    S1 = V0;

    A0 = w[8004e948 + S0 * 4]; // 00000000 0E000000 10000000 0F000000 0D000000 11000000 12000000 00000000
    func28548();

    A0 = V0;
    A1 = 1;
    system_memory_allocate();
    [80058958] = w(V0);

    if( V0 != 0 )
    {
        A0 = w[8004e948 + S0 * 4];
        A1 = V0;
        A2 = 0;
        A3 = 0;
        80019AF0	jal    func293e8 [$800293e8]
    }
    else
    {
        [8005895c] = w(-1);
    }

    A0 = S1;
    80019B0C	jal    func319c4 [$800319c4]

    A0 = w[SP + 10];
    A1 = w[SP + 14];
    80019B1C	jal    func28280 [$80028280]

    A0 = S2;
    80019B24	jal    func319b8 [$800319b8]
}

return w[80058958];
////////////////////////////////



////////////////////////////////
// func28548()
S2 = A0;

if( w[8004f4ec] != 0 )
{
    A0 = S2;
    func287a8();

    A0 = V0; // filename
    A1 = 0; // accessmode
    A2 = 0;
    system_devkit_pc_open();
    S0 = V0;

    A0 = S0; // filehandle
    A1 = 0; // file_offset
    A2 = 2; // seekmode  2 = end of file.
    system_devkit_pc_seek();
    S1 = V0; // file pointer

    A0 = S0; // filehandle
    system_devkit_pc_close();

    if( S1 > 0 )
    {
        return S1;
    }
}

A0 = w[8004f494]; // pointer to 0x80010004
V0 = w[8004f4b8] + S2 - 1; // 0x01a7 + S2 - 1
// some files stored here at offset 0x1a7 * 7
// D5D101FEFFFFFF STRIPCD1\7 dir
// D5D101DC110200 STRIPCD1\7\0424
// 18D201D4EA0000 STRIPCD1\7\0425
// 36D201DFFFFFFF STRIPCD1\8 dir
// 36D20138DD0000 STRIPCD1\8\0427
// and so on up to
// 11D30114D70000 STRIPCD1\8\0436
// 2CD30120D60000 STRIPCD1\8\0437 S2 = 0D
// 47D301309E0000 STRIPCD1\8\0438 S2 = 0E
// 5BD30138DD0000 STRIPCD1\8\0439 S2 = 0F
// 77D30138DD0000 STRIPCD1\8\0440 S2 = 10
// 93D30138DD0000 STRIPCD1\8\0441 S2 = 11
// AFD30138DD0000 STRIPCD1\8\0442 S2 = 12
// and so on up to
// 42D5019CAA0000 STRIPCD1\8\0459
return w[A0 + V0 * 7 + 3];
////////////////////////////////



////////////////////////////////
// func287a8()
if( w[8004f4ec] != 0 )
{
    V0 = w[8004f4b8] + A0 - 1;
    return w[8004f4ec] + V0 * 40;
}
return 0;
////////////////////////////////



////////////////////////////////
// func445dc()
800445E4	addu   s3, a0, zero
800445E8	lui    a0, $8002
800445EC	addiu  a0, a0, $9214 (=-$6dec)
800445F4	addu   s2, a1, zero
800445F8	addu   a1, s3, zero
80044600	addu   s1, a2, zero
8004460C	jal    func444b4 [$800444b4]
80044610	addu   s0, a3, zero

80044614	addu   a1, s3, zero
80044618	andi   s0, s0, $00ff
8004461C	sll    s0, s0, $10
80044620	andi   s1, s1, $00ff
80044624	sll    s1, s1, $08
80044628	or     s0, s0, s1
8004462C	andi   s2, s2, $00ff
80044630	lui    v0, $8005
80044634	lw     v0, $5f68(v0)
80044638	addiu  a2, zero, $0008
8004463C	lw     a0, $000c(v0)
80044640	lw     v0, $0008(v0)
80044644	nop
80044648	jalr   v0 ra
8004464C	or     a3, s0, s2
////////////////////////////////



////////////////////////////////
// func444b4()
T0 = A0;
S0 = A1;

V1 = [80055f72] = 0;
V0 = 1;

if (V1 != V0)
{
    V0 = 2

    800444DC	beq    v1, v0, L44584 [$80044584]
    800444F8	nop
}
else
{
    A1 = [S0 + 4]

    800444F0	lui    v1, $8005
    800444F4	lh     v1, $5f74(v1)
    800444F8	nop
    800444FC	slt    v0, v1, a1

    if (V0 == 0)
    {
        80044508	lh     a3, $0000(s0)
        8004450C	nop
        80044510	addu   v0, a1, a3
        80044514	slt    v0, v1, v0

        if (V0 == 0)
        {
            80044520	lh     v1, $0002(s0)
            80044524	lui    a0, $8005
            80044528	lh     a0, $5f76(a0)
            8004452C	nop
            80044530	slt    v0, a0, v1

            if (V0 == 0)
            {
                8004453C	lh     a2, $0006(s0)
                80044540	nop
                80044544	addu   v0, v1, a2
                80044548	slt    v0, a0, v0

                if (V0 == 0)
                {
                    80044554	blez   a1, L44574 [$80044574]
                    80044558	nop
                    8004455C	bltz   a3, L44574 [$80044574]
                    80044560	nop
                    80044564	bltz   v1, L44574 [$80044574]
                    80044568	nop
                    8004456C	bgtz   a2, L445c8 [$800445c8]
                    80044570	nop
                }
            }
        }
    }

    80044574	lui    a0, $8002
    80044578	addiu  a0, a0, $91f0 (=-$6e10)
    8004457C	j      L4458c [$8004458c]
    80044580	nop

    L44584:	; 80044584
    80044584	lui    a0, $8002
    80044588	addiu  a0, a0, $9210 (=-$6df0)

    L4458c:	; 8004458C
    8004458C	lui    v0, $8005
    80044590	lw     v0, $5f6c(v0)
    80044594	nop
    80044598	jalr   v0 ra
    8004459C	addu   a1, t0, zero
    800445A0	lh     a1, $0000(s0)
    800445A4	lh     a2, $0002(s0)
    800445A8	lh     a3, $0004(s0)
    800445AC	lh     v0, $0006(s0)
    800445B0	lui    v1, $8005
    800445B4	lw     v1, $5f6c(v1)
    800445B8	lui    a0, $8002
    800445BC	addiu  a0, a0, $91fc (=-$6e04)
    800445C0	jalr   v1 ra
    800445C4	sw     v0, $0010(sp)
}
////////////////////////////////
