
////////////////////////////////
// func293e8()
S0 = A0;
S1 = A1;
S2 = A2;
S3 = A3;
if( S0 > 0 )
{
    A0 = A0;
    func28548(); // get filesize by global file id
    if( V0 > 0 )
    {
        if( S1 != 0 )
        {
            A0 = 0;
            func28870(); // system_psyq_CdDataSync

            [8004f4bc] = w(w[8004f4b8]);

            A0 = S0;
            func287e0(); // get file sector by global file id
            [8004f4a8] = w(V0);

            A0 = S0;
            func286fc(); // get filesize by global field id
            [8004f49c] = w(V0);

            A0 = S0;
            A1 = S1;
            A2 = S2;
            A3 = S3;
            func294a0();

            return V0;
        }
    }
}
return -3;
////////////////////////////////



////////////////////////////////
// func294a0()
global_file_id = A0;
allocated_memory = A1;
flags = A3;

param_ptr = 800595ac;

[8004f4a0] = w(1);
[8004f4ac] = w(allocated_memory);
[8004f4b0] = w(0);
[8004f4b4] = w(0);
[8004f4d8] = w(0);
[8004f4dc] = w(A2 & ffff);
[80059594] = w(0);
[80059598] = w(0);
[8005959c] = w(0);
[800595a8] = w(global_file_id);
[80059b6c] = w(0);

S0 = 1;

A0 = w[8004f4a8]; // file sector to load.
A1 = param_ptr;
system_psyq_CdIntToPos();



if( flags & 100 )
{
    [8004f4d4] = w(allocated_memory);

    80029558	lui    v1, $8005
    8002955C	lw     v1, $f4d4(v1)
    80029560	nop
    80029564	lw     a0, $0000(v1)
    80029568	nop
    if( A0 == 0 )
    {
        return -4;
    }

    80029570	sll    v0, a0, $03
    80029574	addu   v0, v1, v0
    80029578	addiu  v0, v0, $0024
    8002957C	lui    at, $8005
    80029580	sw     v0, $f4ac(at)
    80029584	addiu  v0, v1, $0004
    80029588	lui    at, $8005
    8002958C	sw     v0, $f4d0(at)
    80029590	lui    at, $8005
    80029594	sw     a0, $f4e4(at)
    80029598	lui    at, $8005
    8002959C	sh     zero, $f4ca(at)
    800295A0	lui    at, $8005
    800295A4	sh     zero, $f4cc(at)
    800295A8	lui    at, $8005
    800295AC	sh     zero, $f4c8(at)
    800295B0	jal    func288bc [$800288bc]
    800295B4	nop
    800295B8	lui    v0, $8005
    800295BC	lw     v0, $f4ec(v0)
    800295C0	nop
    if( V0 != 0 )
    {
        A0 = global_file_id;
        800295CC	jal    func287a8 [$800287a8]

        800295D4	addu   s1, v0, zero
        800295D8	addu   s0, zero, zero
        800295DC	addiu  s2, zero, $ffff (=-$1)

        loop295e4:	; 800295E4
            A0 = S1;
            A1 = 0;
            A2 = 0;
            system_devkit_pc_open();

            800295F0	lui    at, $8005
            800295F4	sw     v0, $f4f0(at)
            800295F8	bne    v0, s2, L29760 [$80029760]
            800295FC	addu   a0, s0, zero
            80029600	ori    a1, zero, $00ff
            80029604	addu   a2, zero, zero
            80029608	jal    func27e5c [$80027e5c]
            8002960C	addu   a3, zero, zero
            80029610	addiu  s0, s0, $0001
            80029614	slti   v0, s0, $0004
        80029618	bne    v0, zero, loop295e4 [$800295e4]

        80029620	j      L29760 [$80029760]
    }

    [8004f4c0] = w(1);

    A0 = 8002b868;
    func41264();

    A0 = 8002a49c;
    func40e2c(); // set cd load callback 80055b48

    A0 = 8002b100;
    func40e44(); // set cd load callback 80055b4c

    [80059b18] = w(w[80059b18] + 1);

    A0 = 2; // CdlSetloc
    A1 = param_ptr;
    func40f94();

    return 0;
}
else if( flags & 0200 )
{
    A0 = allocated_memory;
    80029668	jal    func288a4 [$800288a4]

    80029670	lui    v1, $8005
    80029674	lw     v1, $f4d4(v1)
    80029678	nop
    8002967C	lw     a0, $0000(v1)

    if( A0 == 0 )
    {
        return -4;
    }
    80029688	sll    v0, a0, $03
    8002968C	addu   v0, v1, v0
    80029690	addiu  v0, v0, $0024
    80029694	lui    at, $8005
    80029698	sw     v0, $f4ac(at)
    8002969C	addiu  v0, v1, $0004
    800296A0	lui    at, $8005
    800296A4	sw     v0, $f4d0(at)
    800296A8	lui    at, $8005
    800296AC	sw     a0, $f4e4(at)
    800296B0	lui    at, $8006
    800296B4	sh     zero, $95fc(at)
    800296B8	lui    at, $8005
    800296BC	sh     zero, $f4ca(at)
    800296C0	lui    at, $8005
    800296C4	sh     zero, $f4cc(at)
    800296C8	lui    at, $8005
    800296CC	sh     zero, $f4c8(at)
    800296D0	jal    func288bc [$800288bc]
    800296D4	ori    s0, zero, $0003
    800296D8	lui    v0, $8006
    800296DC	addiu  v0, v0, $95b7 (=-$6a49)

    loop296e0:	; 800296E0
        800296E0	sb     zero, $0000(v0)
        800296E4	addiu  s0, s0, $ffff (=-$1)
        800296EC	addiu  v0, v0, $ffff (=-$1)
    800296E8	bgez   s0, loop296e0 [$800296e0]

    800296F0	lui    v1, $8005
    800296F4	lw     v1, $f4ec(v1)
    V0 = flags | a0;
    800296FC	lui    at, $8006
    80029700	sb     v0, $95b4(at)
    if( V1 == 0 )
    {
        return 0;
    }

    A0 = global_file_id;
    8002970C	jal    func287a8 [$800287a8]

    80029714	addu   s1, v0, zero
    80029718	addu   s0, zero, zero
    8002971C	addiu  s2, zero, $ffff (=-$1)

    loop29724:	; 80029724
        A0 = S1;
        A1 = 0;
        A2 = 0;
        system_devkit_pc_open();

        80029730	lui    at, $8005
        80029734	sw     v0, $f4f0(at)
        80029738	bne    v0, s2, L29760 [$80029760]
        8002973C	addu   a0, s0, zero
        80029740	ori    a1, zero, $00ff
        80029744	addu   a2, zero, zero
        80029748	jal    func27e5c [$80027e5c]
        8002974C	addu   a3, zero, zero
        80029750	addiu  s0, s0, $0001
        80029754	slti   v0, s0, $0004
    80029758	bne    v0, zero, loop29724 [$80029724]

    L29760:	; 80029760
    V0 = w[8004f4f0];
    V0 = 0 NOR V0;
    V0 = V1 < 1;
    V0 = 0 - V0;
    return V0 & fffffffd;
}
else
{
    if( w[8004f4ec] != 0 )
    {
        A0 = global_file_id;
        80029794	jal    func287a8 [$800287a8]

        8002979C	addu   s3, v0, zero
        800297A0	addu   s0, zero, zero
        800297A4	addiu  s4, zero, $ffff (=-$1)

        loop297ac:	; 800297AC
            A0 = S3;
            A1 = 0;
            A2 = 0;
            system_devkit_pc_open();

            800297B8	addu   s1, v0, zero
            800297BC	bne    s1, s4, L297f8 [$800297f8]
            800297C0	addu   a0, s0, zero
            800297C4	ori    a1, zero, $00ff
            800297C8	addu   a2, zero, zero
            800297CC	jal    func27e5c [$80027e5c]
            800297D0	addu   a3, zero, zero
            800297D4	addiu  s0, s0, $0001
            800297D8	slti   v0, s0, $0004
        800297DC	bne    v0, zero, loop297ac [$800297ac]

        800297E4	addiu  v0, zero, $ffff (=-$1)
        800297E8	bne    s1, v0, L297f8 [$800297f8]
        800297EC	nop

        return -4;

        L297f8:	; 800297F8
        if( allocated_memory != 0 )
        {
            800297FC	addu   s0, zero, zero

            loop29804:	; 80029804
                A0 = S1;
                80029804	lui    a2, $8005
                80029808	lw     a2, $f49c(a2)
                A1 = allocated_memory;
                8002980C	jal    func4c240 [$8004c240]

                80029814	bne    v0, zero, L2983c [$8002983c]
                80029818	addu   a0, s0, zero
                8002981C	addu   a1, zero, zero
                80029820	ori    a2, zero, $00ff
                80029824	jal    func27e5c [$80027e5c]
                80029828	addu   a3, zero, zero
                8002982C	addiu  s0, s0, $0001
                80029830	slti   v0, s0, $0004
            80029834	bne    v0, zero, loop29804 [$80029804]
        }

        L2983c:	; 8002983C
        S0 = 0;
        loop29840:	; 80029840
            A0 = S1;
            system_devkit_pc_close();
            if( V0 == 0 )
            {
                [8004f49c] = w(0); // filesize to load
                [8004f4a0] = w(0);
                return 0;
            }

            8002984C	addu   a0, s0, zero
            80029850	addu   a1, zero, zero
            80029854	addu   a2, zero, zero
            80029858	jal    func27e5c [$80027e5c]
            8002985C	ori    a3, zero, $00ff
            80029860	addiu  s0, s0, $0001
            80029864	slti   v0, s0, $0004
        80029868	bne    v0, zero, loop29840 [$80029840]

        return -6;
    }

    [8004f4c0] = w(1);

    A0 = 0;
    func41264();

    A0 = 8002a49c;
    func40e2c(); // set cd load callback 80055b48

    A0 = 8002ae94;
    func40e44(); // set cd load callback 80055b4c

    [80059b18] = w(w[80059b18] + 1);

    A0 = 2; // CdlSetloc
    A1 = param_ptr;
    func40f94();

    return 0;
}
////////////////////////////////



////////////////////////////////
// func286fc()
A0 = A0;
func28548(); // get filesize by global file id

return (V1 / 4) * 4; // make it aligned
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

S1 = 8001808c + w[80018088] * 10;

A0 = 1; // cancels the current drawing and flushes the command buffer.
system_reset_graph();

80019B9C	jal    func44350 [$80044350]
80019BA0	addu   a0, zero, zero
80019BA4	jal    func36298 [$80036298]
80019BA8	addu   a0, zero, zero

A0 = 0;
system_draw_sync();

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
    func28870();

    A0 = S0; // from
    A1 = w[80018084]; // where
    system_extract_archive();

    A0 = 0;
    system_draw_sync();

    80019C28	addu   a0, zero, zero
    80019C24	jal    func4b3f4 [$8004b3f4]

    80019C2C	jal    func4034c [$8004034c]

    A0 = 0;
    system_draw_sync();

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
func19b50();
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
80019E40	jal    system_clear_image [$800445dc]
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
// func19a50()
S0 = A0;
if( w[8005895c] != S0 )
{
    [8005895c] = w(S0);

    S2 = hu[GP + 1ac];

    A0 = SP + 10;
    A1 = SP + 14;
    func282c4(); // get directory

    [GP + 1ac] = h(6);

    A0 = 0;
    A1 = 1;
    func28280(); // set directory

    S1 = w[GP + 1c0];
    [GP + 1c0] = w(1);

    A0 = w[8004e948 + S0 * 4]; // 00000000 0E000000 10000000 0F000000 0D000000 11000000 12000000 00000000
    func28548(); // get filesize by global file id

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
        func293e8();
    }
    else
    {
        [8005895c] = w(-1);
    }

    [GP + 1c0] = w(S1);

    A0 = w[SP + 10];
    A1 = w[SP + 14];
    func28280(); // restore directory

    [GP + 1ac] = h(S2);
}

return w[80058958];
////////////////////////////////



////////////////////////////////
// func282c4()
A3 = w[8004f498];

A2 = 0;
loop282d0:	; 800282D0
    // if ??? == id of first file in dir 7
    if( hu[A3 + A2 * 2] == ( w[8004f4b8] + 1 ) )
    {
        [A0] = w((A2 >> 2) << 2);
        [A1] = w(A2 % 4);
        break;
    }
    A2 = A2 + 1;
    V0 = A2 < 40;
80028314	bne    v0, zero, loop282d0 [$800282d0]

if( A2 == 40 )
{
    [A0] = w(0);
    [A1] = w(0);
}

return w[8004f4b8];
////////////////////////////////



////////////////////////////////
// func28280()
V0 = w[8004f498];
// 16001800FFFFFFFF
// A801FFFFFFFFFFFF
// FFFFFFFFFFFFFFFF
// 350A3A0A350DD30A
// 220A2E0A2F0AFFFF
// FFFFFFFFFFFFFFFF
// 140001001300FFFF
// 7500FFFFFFFFFFFF
// 100C140C150C190C
// 520FFFFFFFFFFFFF
// 4C0F6E0B4D0C3710
// 090CAD0BFFFFFFFF
// 2E003400FFFFFFFF
// FFFFFFFFFFFFFFFF
// FFFFFFFFFFFFFFFF
V0 = hu[V0 + (A0 + A1) * 2] - 1;
[8004f4b8] = w(V0);
if( V0 < 0 )
{
    [8004f4b8] = w(0);
    return -1;
}
return V0;
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
// func287e0()
V0 = w[8004f494]; // pointer to 0x80010004
A0 = w[8004f4b8] + A0 - 1; // 0x01a7 + A0 - 1
return (bu[V0 + A0 * 7 + 2] << 10) | (bu[V0 + A0 * 7 + 1] << 8) | bu[V0 + A0 * 7 + 0];
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
