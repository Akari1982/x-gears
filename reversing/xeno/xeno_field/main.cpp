////////////////////////////////
// func77518()

if( w[80010000] != -1 )
{
    [800c1b60] = w(0);
}
else
{
    [800c1b60] = w(1);
}

80077568	jal    func78fb0 [$80078fb0]

if( w[800c1b60] == 0 )
{
    A0 = 80076eac;
    8007758C	jal    func44350 [$80044350]
}

[80061bac] = w(w[80058bfc]);
[80061bb4] = w(w[80058c48]);



A0 = 8;
A1 = 0;
func322bc(); // set group for memory allocation



if( ( w[800c1b60] == 0 ) && ( w[8004ea14] == 0 ) )
{
    A0 = 4;
    A1 = 0;
    800775E8	jal    func28280 [$80028280]

    A0 = ad;
    A1 = 80280000;
    A2 = 0;
    A3 = 80;
    800775FC	jal    func293e8 [$800293e8]

    A0 = 0;
    80077604	jal    func28870 [$80028870]

    8007760C	jal    func78fb0 [$80078fb0]
}



if( w[8004e9b0] == 0 )
{
    [8006f14c] = w(ff);
    [8006f150] = w(ff);
    [8006f154] = w(ff);
}



A0 = 0;
80077640	jal    func84ea4 [$80084ea4]

S4 = 0;

80077648	jal    func77318 [$80077318]

80077658	addiu  v0, zero, $ffff (=-$1)
8007765C	lui    at, $800b
80077660	sw     v0, $d0c0(at)
80077664	lui    at, $800b
80077668	sw     v0, $d0bc(at)
8007766C	lui    at, $800b
80077670	sw     v0, $d0b8(at)
80077674	lui    at, $800b
80077678	sw     v0, $d0b4(at)
8007767C	lui    at, $800b
80077680	sw     v0, $d0b0(at)
80077684	ori    v0, zero, $0002
80077688	lui    at, $8005
8007768C	sw     zero, $e9fc(at)
80077690	lui    at, $8005
80077694	sw     zero, $e9f8(at)
80077698	lui    at, $800b
8007769C	sw     zero, $d0e8(at)
800776A0	lui    at, $800b
800776A4	sw     zero, $d038(at)
800776A8	lui    at, $800b
800776AC	sw     zero, $d00c(at)
800776B0	lui    at, $800b
800776B4	sw     zero, $d054(at)
800776B8	lui    at, $800b
800776BC	sw     v0, $d0dc(at)

if( w[800c1b60] == 0 )
{
    800776C8	0C0A0481	Ѓ...
}

800776D0	jal    func76c50 [$80076c50]
800776D4	nop
800776D8	lui    v1, $8007
800776DC	lhu    v1, $efde(v1)
800776E0	lui    a0, $8007
800776E4	lhu    a0, $efe4(a0)
V0 = 8006ccc4;
800776F0	lui    at, $8006
800776F4	sw     v0, $9a38(at)
800776F8	lui    v0, $8007
800776FC	lhu    v0, $efe0(v0)
80077700	lui    at, $8005
80077704	sw     v1, $e9f0(at)
80077708	lui    v1, $8005
8007770C	lw     v1, $e99c(v1)
80077710	srl    v0, v0, $09
80077714	lui    at, $8007
80077718	sh     a0, $e5f6(at)
8007771C	lui    at, $8007
80077720	sh     v0, $e5fc(at)



if( V1 == 0 )
{
    [80058b6c] = b(0);
    [8004e9c8] = w(ff);

}
else
{
    [8004e9c8] = w(hu[8006efe6]);
}



if( w[800c1b60] == 1 )
{
    V1 = w[80059a38];
    [V1 + 1980] = h(1);

    A0 = 50;
    A1 = 1;
    put_bytes_to_800C2F3C();
}

80077778	jal    func76cb0 [$80076cb0]

[8004e9c4] = w(0);

80077788	jal    func1aed8 [$8001aed8]

80077790	jal    func1b23c [$8001b23c]

A0 = 4;
A1 = 1;
system_memory_allocate();

800777A4	lui    v1, $800c
800777A8	lw     v1, $1b60(v1)
800777AC	lui    at, $800b
800777B0	sw     v0, $d008(at)
800777B4	bne    v1, zero, L777e8 [$800777e8]
800777B8	nop
800777BC	break   $00400
800777C0	lui    a0, $800b
800777C4	lw     a0, $1740(a0)
800777C8	jal    funca897c [$800a897c]
800777CC	nop
800777D0	ori    v0, zero, $0001
800777D4	lui    at, $800b
800777D8	sh     v0, $f7a0(at)
800777DC	ori    v0, zero, $0010
800777E0	lui    at, $800b
800777E4	sh     v0, $f7a6(at)

L777e8:	; 800777E8
S5 = 0;
// call script here
800777E8	jal    func78358 [$80078358]

800777F0	ori    v0, zero, $0001
800777F4	lui    at, $800b
800777F8	sb     v0, $cfdc(at)
800777FC	ori    s1, zero, $0001
80077800	addiu  s2, zero, $ffff (=-$1)
80077804	lui    s6, $800b
80077808	addiu  s6, s6, $1829
8007780C	ori    s3, zero, $00ff



L77810:	; 80077810
    if( hu[800c2dd4] & 0800 ) // start repeated
    {
        if( ( hu[800af370] & 0040 ) == 0 ) // cross currently not pressed
        {
            if( bu[800b182c] == 0 )
            {
                S0 = w[80058b24];

                8007785C	jal    func37d8c [$80037d8c]

                A0 = 88;
                A1 = (((w[800acfe0] + 1) & 1 ) << 8) | 64;
                8007787C	jal    func1f92c [$8001f92c]


                loop77884:	; 80077884
                    A0 = 0;
                    system_draw_sync();

                    80077890	ori    a0, zero, $0002
                    8007788C	jal    func4b3f4 [$8004b3f4]

                    func73d90(); // update buttons

                    8007789C	jal    func19d24 [$80019d24]

                    V0 = hu[800c2dd4] & 0800; // start repeated
                800778B4	beq    v0, zero, loop77884 [$80077884]

                800778BC	jal    func37d34 [$80037d34]

                800778C4	lui    at, $8006
                800778C8	sw     s0, $8b24(at)
            }
        }
    }



    if( w[800c1b60] == S1 )
    {
        A0 = 50;
        A1 = 1;
        put_bytes_to_800C2F3C();
    }



    800778E8	jal    func19d24 [$80019d24]
    800778EC	nop
    800778F0	jal    func7743c [$8007743c]
    800778F4	nop

    // move and update sprite and model here
    func74bdc();

    80077900	jal    funca4dfc [$800a4dfc]
    80077904	nop
    80077908	lui    v0, $800b
    8007790C	lw     v0, $cfe0(v0)
    80077910	nop
    80077914	bne    v0, s1, L77aa4 [$80077aa4]
    80077918	nop
    8007791C	lui    v0, $800b
    80077920	lw     v0, $d0b4(v0)
    80077924	nop
    80077928	bne    v0, zero, L77aa4 [$80077aa4]
    8007792C	nop
    80077930	jal    func781dc [$800781dc]
    80077934	nop
    80077938	bne    v0, zero, L77aa4 [$80077aa4]
    8007793C	nop
    80077940	jal    func774a0 [$800774a0]
    80077944	nop
    80077948	bne    v0, zero, L77aa4 [$80077aa4]
    8007794C	nop
    80077950	lui    v0, $8005
    80077954	lw     v0, $e9d8(v0)
    80077958	nop
    8007795C	beq    v0, s2, L77984 [$80077984]
    80077960	nop
    80077964	lui    a0, $8006
    80077968	lw     a0, $9b70(a0)
    8007796C	jal    func31edc [$80031edc]
    80077970	nop
    A0 = w[80059b70];
    system_memory_free();

    L77984:	; 80077984
    80077984	bne    s5, zero, L779a0 [$800779a0]
    80077988	nop
    8007798C	lui    v0, $8005
    80077990	lw     v0, $e9c8(v0)
    80077994	ori    s5, zero, $0001
    80077998	lui    at, $800b
    8007799C	sw     v0, $f14c(at)

    L779a0:	; 800779A0
    800779A0	jal    func7f5fc [$8007f5fc]
    800779A4	nop
    800779A8	lui    v0, $800b
    800779AC	lw     v0, $d0a8(v0)
    800779B0	nop
    800779B4	bne    v0, s1, L77a38 [$80077a38]
    800779B8	nop
    800779BC	lbu    v0, $0000(s6)
    800779C0	lui    v1, $8005
    800779C4	lw     v1, $e9c8(v1)
    800779C8	lh     a0, $ff3b(s6)
    800779CC	lui    a1, $8005
    800779D0	lw     a1, $e9dc(a1)
    800779D4	lui    at, $8006
    800779D8	sb     v0, $8be8(at)
    800779DC	lui    at, $800b
    800779E0	sw     v1, $f14c(at)
    800779E4	beq    a1, a0, L77a20 [$80077a20]
    800779E8	nop
    800779EC	beq    a1, s2, L779fc [$800779fc]
    800779F0	nop
    800779F4	lui    at, $8005
    800779F8	sw     s1, $e9ec(at)

    L779fc:	; 800779FC
    800779FC	jal    func1b500 [$8001b500]
    80077A00	nop
    80077A04	lh     a0, $ff3b(s6)
    80077A08	lui    at, $8005
    80077A0C	sw     s2, $e9ac(at)
    80077A10	lui    at, $8005
    80077A14	sw     a0, $e9c8(at)
    80077A18	jal    func85134 [$80085134]
    80077A1C	ori    a1, zero, $0001

    L77a20:	; 80077A20
    80077A20	lui    at, $800b
    80077A24	sw     zero, $d0a8(at)
    80077A28	lui    at, $800b
    80077A2C	sw     s1, $d0ac(at)
    80077A30	j      L77aa4 [$80077aa4]
    80077A34	nop

    L77a38:	; 80077A38
    80077A38	lui    v0, $800b
    80077A3C	lw     v0, $cff0(v0)
    80077A40	nop
    80077A44	bne    v0, zero, L77a6c [$80077a6c]
    80077A48	nop
    80077A4C	lui    v0, $8005
    80077A50	lw     v0, $e9b0(v0)
    80077A54	nop
    80077A58	addiu  v0, v0, $0001
    80077A5C	lui    at, $8005
    80077A60	sw     v0, $e9b0(at)
    80077A64	jal    funca345c [$800a345c]
    80077A68	nop

    L77a6c:	; 80077A6C
    80077A6C	lui    v0, $800b
    80077A70	lw     v0, $d0ac(v0)
    80077A74	nop
    80077A78	bne    v0, s1, L77a94 [$80077a94]
    80077A7C	addu   s0, zero, zero
    80077A80	lui    a0, $8006
    80077A84	lw     a0, $1bb8(a0)
    80077A88	ori    a1, zero, $007f
    80077A8C	jal    func3a744 [$8003a744]
    80077A90	addu   a2, zero, zero

    L77a94:	; 80077A94
    80077A94	lui    at, $800b
    80077A98	sw     zero, $d0ac(at)
    80077A9C	j      L780cc [$800780cc]
    80077AA0	nop

    L77aa4:	; 80077AA4



    // field load started
    if( ( w[800ad0c4] == 0 ) && ( w[8004e9ac] == 0 ) && ( w[800ad09c] == S3 ) && ( w[800ad068] == 0 ) )
    {
        // field to load
        A0 = (w[8004e9f0] & 00000fff) << 1;
        A1 = 0;
        func1b318(); // prepare cdrom for field load
        if( V0 == 0 )
        {
            func284dc(); // wait for command to finish
            if( V0 == 0 )
            {
                if( h[800b15ec] == 0 )
                {
                    [800acfdc] = b(0);

                    funca268c();

                    A0 = 0;
                    func28870(); // execute until command finished

                    funca5118(); // load field here

                    80077B58	jal    func35c84 [$80035c84]

                    [800acfdc] = b(S1);
                }
            }
        }
    }



    80077B68	lui    v0, $800b
    80077B6C	lw     v0, $cfe0(v0)
    80077B70	nop
    80077B74	bne    v0, s1, L77d04 [$80077d04]
    80077B78	nop
    80077B7C	lui    v0, $800b
    80077B80	lw     v0, $d0bc(v0)
    80077B84	nop
    80077B88	bne    v0, zero, L77be4 [$80077be4]
    80077B8C	nop
    80077B90	jal    func781dc [$800781dc]
    80077B94	nop
    80077B98	bne    v0, zero, L77be4 [$80077be4]
    80077B9C	nop
    80077BA0	jal    func28870 [$80028870]
    80077BA4	addu   a0, zero, zero
    80077BA8	lui    v0, $8005
    80077BAC	lw     v0, $e9d8(v0)
    80077BB0	nop
    80077BB4	beq    v0, s2, L780cc [$800780cc]
    80077BB8	ori    s0, zero, $0001
    80077BBC	lui    a0, $8006
    80077BC0	lw     a0, $9b70(a0)
    80077BC4	jal    func31edc [$80031edc]
    80077BC8	nop
    A0 = w[80059b70];
    system_memory_free();

    80077BDC	j      L780cc [$800780cc]


    L77be4:	; 80077BE4
    80077BE4	lui    v0, $800b
    80077BE8	lw     v0, $cfe0(v0)
    80077BEC	nop
    80077BF0	bne    v0, s1, L77d04 [$80077d04]
    80077BF4	nop
    80077BF8	lui    v0, $800b
    80077BFC	lw     v0, $d0c0(v0)
    80077C00	nop
    80077C04	bne    v0, zero, L77c80 [$80077c80]
    80077C08	nop
    80077C0C	jal    func781dc [$800781dc]
    80077C10	nop
    80077C14	bne    v0, zero, L77c80 [$80077c80]
    80077C18	nop
    80077C1C	jal    func28870 [$80028870]
    80077C20	addu   a0, zero, zero
    80077C24	lui    v0, $8005
    80077C28	lw     v0, $e9d8(v0)
    80077C2C	nop
    80077C30	beq    v0, s2, L77c58 [$80077c58]
    80077C34	nop
    80077C38	lui    a0, $8006
    80077C3C	lw     a0, $9b70(a0)
    80077C40	jal    func31edc [$80031edc]
    80077C44	nop
    A0 = w[80059b70];
    system_memory_free();

    L77c58:	; 80077C58
    80077C58	lui    v0, $8005
    80077C5C	lw     v0, $e9b4(v0)
    80077C60	nop
    80077C64	addiu  v0, v0, $0001
    80077C68	lui    at, $8005
    80077C6C	sw     v0, $e9b4(at)
    80077C70	jal    funca345c [$800a345c]
    80077C74	ori    s0, zero, $0002
    80077C78	j      L780cc [$800780cc]
    80077C7C	nop

    L77c80:	; 80077C80
    80077C80	lui    v0, $800b
    80077C84	lw     v0, $cfe0(v0)
    80077C88	nop
    80077C8C	bne    v0, s1, L77d04 [$80077d04]
    80077C90	nop
    80077C94	lui    v0, $800b
    80077C98	lw     v0, $d0b0(v0)
    80077C9C	nop
    80077CA0	bne    v0, zero, L77d04 [$80077d04]
    80077CA4	nop
    80077CA8	jal    func781dc [$800781dc]
    80077CAC	nop
    80077CB0	bne    v0, zero, L77d04 [$80077d04]
    80077CB4	nop
    80077CB8	jal    func28870 [$80028870]
    80077CBC	addu   a0, zero, zero
    80077CC0	lui    v0, $8005
    80077CC4	lw     v0, $e9d8(v0)
    80077CC8	nop
    80077CCC	beq    v0, s2, L77cf4 [$80077cf4]
    80077CD0	nop
    80077CD4	lui    a0, $8006
    80077CD8	lw     a0, $9b70(a0)
    80077CDC	jal    func31edc [$80031edc]
    80077CE0	nop
    A0 = w[80059b70];
    system_memory_free();

    L77cf4:	; 80077CF4
    80077CF4	jal    func1b500 [$8001b500]
    80077CF8	ori    s0, zero, $0003
    80077CFC	j      L780cc [$800780cc]
    80077D00	nop

    L77d04:	; 80077D04



    if( w[800c1b60] == 0 )
    {
        if( hu[800c2ddc] & 0040 ) // cross on second controller repeated
        {
            [8004ea1c] = w((w[8004ea1c] + 1) & 1);
        }

        if( hu[800c2ddc] & 0010 ) // triangle on second controller repeated
        {
            [8004ea20] = w((w[8004ea20] + 1) & 1);
        }

        if( hu[800c2ddc] & 0080 ) // square on second controller repeated
        {
            [8004ea24] = w((w[8004ea24] + 1) & 1);
        }

        if( hu[800af370] & 0040 ) // cross currently pressed
        {
            if( hu[800c2dd4] & 0100 ) // select repeated
            {
                if( w[800ad0c4] == S2 )
                {
                    if( w[8004e9ac] == 0 )
                    {
                        if( w[800ad00c] == 0 )
                        {
                            [8004e9f0] = w(0);
                            [800ad0c4] = w(0);

                            // set spawn spot to 0
                            A0 = 2;
                            A1 = 0;
                            put_bytes_to_800C2F3C();
                        }
                    }
                }
            }
        }
    }



    if( ( w[800ad0b0] == S2 ) && ( w[800ad0b4] == S2 ) && ( w[800ad0bc] == S2 ) )
    {
        80077E5C	jal    func781dc [$800781dc]

        if( ( V0 == 0 ) && ( w[800ad0c4] == S2 ) )
        {
            if( ( hu[800af370] & 0003 ) == 0 ) // R2 L2 currently pressed
            {
                S4 = 0;
            }
            if( ( hu[800af370] & 0001 ) && ( hu[800af370] & 0002 ) ) // R2 L2 currently pressed
            {
                if( w[800ad040] == S1 )
                {
                    if( S4 == 0 )
                    {
                        S4 = 1;
                        80077EC8	jal    func78ed0 [$80078ed0]

                        if( w[800ad03c] == S3 )
                        {
                            V1 = w[800b1740];
                            V0 = w[800aefe4];
                            V0 = w[V0 + V1 * 5c + 4c];
                            if( ( w[V0 + 0] & 00001800 ) == 0 )
                            {
                                if( bu[80058819] == 0 )
                                {
                                    80077F40	jal    funcac368 [$800ac368]
                                }
                            }
                        }
                    }
                }
            }



            if( hu[800c2dd4] & 0100 ) // select repeated
            {
                if( w[800ad0c4] == S2 )
                {
                    if( w[800ad040] == S1 )
                    {
                        80077F88	jal    funcaaf70 [$800aaf70]
                    }
                }
            }



            if( ( w[800ad048] != 0 ) && ( w[800acfe0] == S1 )
            {
                80077FB8	jal    funca7130 [$800a7130]

                [800ad048] = w(0);
            }



            if( ( w[800ad03c] != S3 ) && ( w[800acfe0] == 0 ) )
            {
                V0 = w[800aefe4] + w[800b1740] * 5c;
                V0 = w[V0 + 4c];
                V0 = w[V0 + 0];

                if( ( V0 & 00001800 ) == 0 )
                {
                    80078038	jal    func7f5fc [$8007f5fc]

                    // call script here
                    80078040	jal    func78fe8 [$80078fe8]

                    [800ad03c] = w(S3);
                }
            }



            if( hu[800c2dd4] & 0010 ) // triangle repeated
            {
                if( bu[800b16a4] == 0 )
                {
                    if( w[800ad03c] == S3 )
                    {
                        if( w[800ad040] == S1 )
                        {
                            [800ad03c] = w(80);
                            [80058811] = b(hu[800b1840]);
                        }
                    }
                }
            }
        }
    }



    800780BC	jal    func78170 [$80078170]



800780C4	j      L77810 [$80077810]



L780cc:	; 800780CC
800780CC	jal    func78ed0 [$80078ed0]

800780D4	jal    funca86c8 [$800a86c8]

800780DC	jal    funca2778 [$800a2778]

800780E4	jal    funca8938 [$800a8938]

800780EC	jal    func85b04 [$80085b04]

800780F4	jal    func7f5fc [$8007f5fc]

A0 = 0;
system_draw_sync();

A0 = 0;
80078104	jal    func4b3f4 [$8004b3f4]

8007810C	jal    func6f740 [$8006f740]

80078114	jal    func773bc [$800773bc]

8007811C	jal    func84f9c [$80084f9c]

[8004e9c0] = w(0);

A0 = w[800ad008];
system_memory_free();

A0 = S0;
8007813C	jal    func78b60 [$80078b60]
////////////////////////////////
