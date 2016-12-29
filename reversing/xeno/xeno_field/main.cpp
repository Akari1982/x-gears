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
8007756C	nop
80077570	lui    v0, $800c
80077574	lw     v0, $1b60(v0)
80077578	nop
if( V0 == 0 )
{
    A0 = 80076eac;
    8007758C	jal    func44350 [$80044350]
}
A0 = 8;
80077598	lui    v0, $8006
8007759C	lw     v0, $8bfc(v0)
800775A0	lui    v1, $8006
800775A4	lw     v1, $8c48(v1)
800775A8	lui    at, $8006
800775AC	sw     v0, $1bac(at)
800775B0	lui    at, $8006
800775B4	sw     v1, $1bb4(at)
800775B8	jal    func322bc [$800322bc]
800775BC	addu   a1, zero, zero
800775C0	lui    v0, $800c
800775C4	lw     v0, $1b60(v0)
800775C8	nop
800775CC	bne    v0, zero, L77614 [$80077614]
800775D0	nop
800775D4	lui    v0, $8005
800775D8	lw     v0, $ea14(v0)
800775DC	nop
800775E0	bne    v0, zero, L77614 [$80077614]
800775E4	ori    a0, zero, $0004
800775E8	jal    func28280 [$80028280]
800775EC	addu   a1, zero, zero
800775F0	ori    a0, zero, $00ad
800775F4	lui    a1, $8028
800775F8	addu   a2, zero, zero
800775FC	jal    func293e8 [$800293e8]
80077600	ori    a3, zero, $0080
80077604	jal    func28870 [$80028870]
80077608	addu   a0, zero, zero
8007760C	jal    func78fb0 [$80078fb0]
80077610	nop

L77614:	; 80077614
80077614	lui    v0, $8005
80077618	lw     v0, $e9b0(v0)
8007761C	nop
80077620	bne    v0, zero, L77640 [$80077640]
80077624	ori    v0, zero, $00ff
80077628	lui    at, $8007
8007762C	sw     v0, $f154(at)
80077630	lui    at, $8007
80077634	sw     v0, $f150(at)
80077638	lui    at, $8007
8007763C	sw     v0, $f14c(at)

L77640:	; 80077640
80077640	jal    func84ea4 [$80084ea4]
80077644	addu   a0, zero, zero
80077648	jal    func77318 [$80077318]
8007764C	addu   s4, zero, zero
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
800776E8	lui    v0, $8007
800776EC	addiu  v0, v0, $ccc4 (=-$333c)
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
80077724	bne    v1, zero, L7773c [$8007773c]
80077728	ori    v0, zero, $00ff
8007772C	lui    at, $8006
80077730	sb     zero, $8b6c(at)
80077734	j      L77744 [$80077744]
80077738	nop

L7773c:	; 8007773C
8007773C	lui    v0, $8007
80077740	lhu    v0, $efe6(v0)

L77744:	; 80077744
80077744	lui    at, $8005
80077748	sw     v0, $e9c8(at)
8007774C	lui    v1, $800c
80077750	lw     v1, $1b60(v1)
80077754	ori    v0, zero, $0001
80077758	bne    v1, v0, L77778 [$80077778]
8007775C	ori    a0, zero, $0050
80077760	ori    a1, zero, $0001
80077764	lui    v1, $8006
80077768	lw     v1, $9a38(v1)
8007776C	ori    v0, zero, $0001
80077770	jal    put_bytes_to_800C2F3C [$800a2604]
80077774	sh     v0, $1980(v1)

L77778:	; 80077778
80077778	jal    func76cb0 [$80076cb0]
8007777C	nop
80077780	lui    at, $8005
80077784	sw     zero, $e9c4(at)
80077788	jal    func1aed8 [$8001aed8]
8007778C	nop
80077790	jal    func1b23c [$8001b23c]
80077794	nop
80077798	ori    a0, zero, $0004
8007779C	jal    system_memory_allocate [$800319ec]
800777A0	ori    a1, zero, $0001
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
                80077888	addu   a0, zero, zero
                80077884	jal    func44448 [$80044448]

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

800778CC	lui    v0, $800c
800778D0	lw     v0, $1b60(v0)
800778D4	nop
800778D8	bne    v0, s1, L778e8 [$800778e8]
800778DC	ori    a0, zero, $0050
800778E0	jal    put_bytes_to_800C2F3C [$800a2604]
800778E4	ori    a1, zero, $0001

L778e8:	; 800778E8
800778E8	jal    func19d24 [$80019d24]
800778EC	nop
800778F0	jal    func7743c [$8007743c]
800778F4	nop
800778F8	jal    func74bdc [$80074bdc]
800778FC	nop
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
80077974	lui    a0, $8006
80077978	lw     a0, $9b70(a0)
8007797C	jal    func31f0c [$80031f0c]
80077980	nop

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
    func1b318();

    if( V0 == 0 )
    {
        func284dc();

        if( V0 == 0 )
        {
            if( h[800b15ec] == 0 )
            {
                [800acfdc] = b(0);

                80077B40	jal    funca268c [$800a268c]

                A0 = 0;
                80077B48	jal    func28870 [$80028870]

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
80077BCC	lui    a0, $8006
80077BD0	lw     a0, $9b70(a0)
80077BD4	jal    func31f0c [$80031f0c]
80077BD8	nop
80077BDC	j      L780cc [$800780cc]
80077BE0	nop

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
80077C48	lui    a0, $8006
80077C4C	lw     a0, $9b70(a0)
80077C50	jal    func31f0c [$80031f0c]
80077C54	nop

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
80077CE4	lui    a0, $8006
80077CE8	lw     a0, $9b70(a0)
80077CEC	jal    func31f0c [$80031f0c]
80077CF0	nop

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

                        A0 = 2;
                        A1 = 0;
                        put_bytes_to_800C2F3C();
                    }
                }
            }
        }
    }
}

80077E20	lui    v0, $800b
80077E24	lw     v0, $d0b0(v0)
80077E28	nop
80077E2C	bne    v0, s2, L780bc [$800780bc]
80077E30	nop
80077E34	lui    v0, $800b
80077E38	lw     v0, $d0b4(v0)
80077E3C	nop
80077E40	bne    v0, s2, L780bc [$800780bc]
80077E44	nop
80077E48	lui    v0, $800b
80077E4C	lw     v0, $d0bc(v0)
80077E50	nop
80077E54	bne    v0, s2, L780bc [$800780bc]
80077E58	nop
80077E5C	jal    func781dc [$800781dc]
80077E60	nop
80077E64	bne    v0, zero, L780bc [$800780bc]
80077E68	nop
80077E6C	lui    v0, $800b
80077E70	lw     v0, $d0c4(v0)
80077E74	nop
80077E78	bne    v0, s2, L780bc [$800780bc]
80077E7C	nop

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

80077F90	lui    v0, $800b
80077F94	lw     v0, $d048(v0)
80077F98	nop
80077F9C	beq    v0, zero, L77fc8 [$80077fc8]
80077FA0	nop
80077FA4	lui    v0, $800b
80077FA8	lw     v0, $cfe0(v0)
80077FAC	nop
80077FB0	bne    v0, s1, L77fc8 [$80077fc8]
80077FB4	nop
80077FB8	jal    funca7130 [$800a7130]
80077FBC	nop
80077FC0	lui    at, $800b
80077FC4	sw     zero, $d048(at)

L77fc8:	; 80077FC8
80077FC8	lui    v0, $800b
80077FCC	lw     v0, $d03c(v0)
80077FD0	nop
80077FD4	beq    v0, s3, L78050 [$80078050]
80077FD8	nop
80077FDC	lui    v0, $800b
80077FE0	lw     v0, $cfe0(v0)
80077FE4	nop
80077FE8	bne    v0, zero, L78050 [$80078050]
80077FEC	nop
80077FF0	lui    v1, $800b
80077FF4	lw     v1, $1740(v1)
80077FF8	nop
80077FFC	sll    v0, v1, $01
80078000	addu   v0, v0, v1
80078004	sll    v0, v0, $03
80078008	subu   v0, v0, v1
8007800C	lui    v1, $800b
80078010	lw     v1, $efe4(v1)
80078014	sll    v0, v0, $02
80078018	addu   v0, v0, v1
8007801C	lw     v0, $004c(v0)
80078020	nop
80078024	lw     v0, $0000(v0)
80078028	nop
8007802C	andi   v0, v0, $1800

if( V0 == 0 )
{
    80078038	jal    func7f5fc [$8007f5fc]

    // call script here
    80078040	jal    func78fe8 [$80078fe8]

    80078048	lui    at, $800b
    8007804C	sw     s3, $d03c(at)
}

L78050:	; 80078050
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

L780bc:	; 800780BC
800780BC	jal    func78170 [$80078170]
800780C0	nop
800780C4	j      L77810 [$80077810]
800780C8	nop

L780cc:	; 800780CC
800780CC	jal    func78ed0 [$80078ed0]
800780D0	nop
800780D4	jal    funca86c8 [$800a86c8]
800780D8	nop
800780DC	jal    funca2778 [$800a2778]
800780E0	nop
800780E4	jal    funca8938 [$800a8938]
800780E8	nop
800780EC	jal    func85b04 [$80085b04]
800780F0	nop
800780F4	jal    func7f5fc [$8007f5fc]
800780F8	nop
800780FC	jal    func44448 [$80044448]
80078100	addu   a0, zero, zero
80078104	jal    func4b3f4 [$8004b3f4]
80078108	addu   a0, zero, zero
8007810C	jal    func6f740 [$8006f740]
80078110	nop
80078114	jal    func773bc [$800773bc]
80078118	nop
8007811C	jal    func84f9c [$80084f9c]
80078120	nop
80078124	lui    a0, $800b
80078128	lw     a0, $d008(a0)
8007812C	lui    at, $8005
80078130	sw     zero, $e9c0(at)
80078134	jal    func31f0c [$80031f0c]
80078138	nop
8007813C	jal    func78b60 [$80078b60]
80078140	addu   a0, s0, zero
////////////////////////////////



////////////////////////////////
// func74bdc
A0 = 1;
80074BEC	jal    func4b3f4 [$8004b3f4]

[800ad074] = w(0);

A0 = -1;
80074BFC	jal    func4b3f4 [$8004b3f4]

S1 = V0;

func73050(); // move here

80074C0C	jal    func85f1c [$80085f1c]

S0 = 80d4;

if( w[800c1b60] == 0 )
{
    A0 = 8006f1c4; // SEFFECT
    80074C30	0C0A06C6	Ж...
}

80074C38	lui    a0, $800c
80074C3C	lw     a0, $3740(a0)
80074C40	lui    a1, $800b
80074C44	lw     a1, $cfe0(a1)
80074C48	jal    func71344 [$80071344]
80074C4C	addu   a0, a0, s0

if( w[800c1b60] == 0 )
{
    A0 = 8006f1d0; // MESSAGE
    80074C6C	0C0A06C6	Ж...
}

80074C74	jal    func73798 [$80073798]
80074C78	nop
80074C7C	lui    t1, $1f80
80074C80	ori    t1, t1, $03fc
80074C84	addu   t0, t1, zero
80074C88	sw     sp, $0000(t0)
80074C8C	addiu  t0, t0, $fffc (=-$4)
80074C90	addu   sp, t0, zero
80074C94	jal    func73f78 [$80073f78]
80074C98	nop
80074C9C	jal    func74958 [$80074958]

funca8b60(); // model anim read

if( w[800c1b60] == 0 )
{
    80074CC0	0C0A051A	....
}

80074CC8	jal    funca4284 [$800a4284]
80074CCC	nop
80074CD0	addiu  sp, sp, $0004
80074CD4	lw     sp, $0000(sp)
80074CD8	jal    funca7998 [$800a7998]
80074CDC	nop
80074CE0	jal    func74b14 [$80074b14]
80074CE4	nop
80074CE8	jal    func7489c [$8007489c]
80074CEC	nop
80074CF0	jal    funcab3a0 [$800ab3a0]
80074CF4	nop

if( w[800c1b60] == 0 )
{
    80074D0C	0C0A0506	....

    A0 = 8006f1dc; // FntPrint
    80074D1C	0C0A06C6	Ж...
}

80074D24	jal    func4b3f4 [$8004b3f4]
80074D28	ori    a0, zero, $0001
80074D2C	lui    at, $800b
80074D30	sw     v0, $d078(at)
80074D34	jal    func44448 [$80044448]
80074D38	addu   a0, zero, zero
80074D3C	jal    func7fc08 [$8007fc08]

A0 = w[800c3740] + S0;
A1 = w[800acfe0];
func7f660(); // dialog function

80074D5C	jal    func4b3f4 [$8004b3f4]
80074D60	addu   a0, zero, zero
80074D64	jal    func32adc [$80032adc]
80074D68	nop
80074D6C	lui    v0, $800b
80074D70	lw     v0, $d0f0(v0)
80074D74	nop
80074D78	bne    v0, zero, L74da8 [$80074da8]
80074D7C	ori    v0, zero, $0003
80074D80	lui    a1, $800b
80074D84	lbu    a1, $1670(a1)
80074D88	lui    a2, $800b
80074D8C	lbu    a2, $1671(a2)
80074D90	lui    a0, $800c
80074D94	lw     a0, $3740(a0)
80074D98	lui    a3, $800b
80074D9C	lbu    a3, $1672(a3)
80074DA0	j      L74e08 [$80074e08]
80074DA4	nop

L74da8:	; 80074DA8
80074DA8	lui    v1, $800b
80074DAC	lw     v1, $f51c(v1)
80074DB0	nop
80074DB4	bne    v1, v0, L74df8 [$80074df8]
80074DB8	addu   a1, zero, zero
80074DBC	addiu  a0, sp, $0010
80074DC0	lui    a2, $800b
80074DC4	lw     a2, $cfe0(a2)
80074DC8	ori    v0, zero, $02c0
80074DCC	sh     v0, $0010(sp)
80074DD0	ori    v0, zero, $0100
80074DD4	sh     v0, $0012(sp)
80074DD8	ori    v0, zero, $0140
80074DDC	sh     v0, $0014(sp)
80074DE0	ori    v0, zero, $00e0
80074DE4	sh     v0, $0016(sp)
80074DE8	jal    func447d4 [$800447d4]
80074DEC	sll    a2, a2, $08
80074DF0	j      L74e10 [$80074e10]
80074DF4	nop

L74df8:	; 80074DF8
80074DF8	addu   a2, zero, zero
80074DFC	lui    a0, $800c
80074E00	lw     a0, $3740(a0)
80074E04	addu   a3, zero, zero

L74e08:	; 80074E08
80074E08	jal    func445dc [$800445dc]
80074E0C	addiu  a0, a0, $005c

L74e10:	; 80074E10
80074E10	lui    a0, $800c
80074E14	lw     a0, $3740(a0)
80074E18	jal    func44d14 [$80044d14]
80074E1C	addiu  a0, a0, $00b8
80074E20	lui    a0, $800c
80074E24	lw     a0, $3740(a0)
80074E28	jal    func44abc [$80044abc]
80074E2C	nop
80074E30	lui    v0, $800c
80074E34	lw     v0, $1b60(v0)
80074E38	nop
80074E3C	bne    v0, zero, L74e54 [$80074e54]
80074E40	nop
80074E44	jal    func4b3f4 [$8004b3f4]
80074E48	ori    a0, zero, $0001
80074E4C	lui    at, $800b
80074E50	sw     v0, $d074(at)

L74e54:	; 80074E54
func24e3c();

if( w[800c1b60] == 0 )
{
    A0 = 8006f1e8; // ShapeTrans
    80074E78	0C0A06C6	Ж...
}

80074E80	jal    func916ac [$800916ac]

80074E88	lui    v0, $800b
80074E8C	lw     v0, $d08c(v0)
80074E90	nop
80074E94	beq    v0, zero, L74ebc [$80074ebc]
80074E98	nop
80074E9C	lui    a1, $800b
80074EA0	lw     a1, $ed50(a1)
80074EA4	lui    a0, $800b
80074EA8	addiu  a0, a0, $f12c (=-$ed4)
80074EAC	jal    func4470c [$8004470c]
80074EB0	nop
80074EB4	lui    at, $800b
80074EB8	sw     zero, $d08c(at)

L74ebc:	; 80074EBC
if( w[800c1b60] == 0 )
{
    A0 = 8006f1f4; // LineScroll
    80074ED8	0C0A06C6	Ж...
}

80074EE0	lui    v0, $800b
80074EE4	lw     v0, $d0f0(v0)
80074EE8	nop
80074EEC	bne    v0, zero, L74f4c [$80074f4c]
80074EF0	nop
80074EF4	lui    v0, $800b
80074EF8	lw     v0, $d024(v0)
80074EFC	nop
80074F00	beq    v0, zero, L74f2c [$80074f2c]
80074F04	nop
80074F08	lui    a2, $800b
80074F0C	lh     a2, $16a8(a2)
80074F10	lui    a1, $800c
80074F14	lw     a1, $3740(a1)
80074F18	sll    a0, a2, $02
80074F1C	addiu  a0, a0, $00cc
80074F20	addu   a0, a1, a0
80074F24	jal    func74ae8 [$80074ae8]
80074F28	addiu  a1, a1, $40d0

L74f2c:	; 80074F2C
80074F2C	ori    a0, zero, $80f0
80074F30	lui    a1, $800c
80074F34	lw     a1, $3740(a1)
80074F38	lui    a2, $800b
80074F3C	lh     a2, $16a8(a2)
80074F40	addu   a0, a1, a0
80074F44	jal    func74ae8 [$80074ae8]
80074F48	addiu  a1, a1, $00cc

L74f4c:	; 80074F4C
80074F4C	lui    v0, $800c
80074F50	lw     v0, $3740(v0)
80074F54	ori    a0, zero, $80f0
80074F58	jal    func44a48 [$80044a48]
80074F5C	addu   a0, v0, a0

loop74f60:	; 80074F60
80074F60	jal    func4b3f4 [$8004b3f4]
80074F64	addiu  a0, zero, $ffff (=-$1)
80074F68	lui    v1, $800b
80074F6C	lw     v1, $1650(v1)
80074F70	nop
80074F74	addiu  v1, v1, $0002
80074F78	addu   v1, s1, v1
80074F7C	slt    v0, v0, v1
80074F80	bne    v0, zero, loop74f60 [$80074f60]
80074F84	nop
80074F88	lw     ra, $0020(sp)
80074F8C	lw     s1, $001c(sp)
80074F90	lw     s0, $0018(sp)
80074F94	addiu  sp, sp, $0028
80074F98	jr     ra 
80074F9C	nop
////////////////////////////////



////////////////////////////////
// func73050()

func80720(); // move routine

A0 = 800b1658;
A1 = 800af104;
system_calculate_rotation_matrix();

80073080	lui    s0, $800b
80073084	addiu  s0, s0, $ed6c (=-$1294)
80073088	lui    at, $800b
8007308C	sw     zero, $f120(at)
80073090	lui    at, $800b
80073094	sw     zero, $f11c(at)
80073098	lui    at, $800b
8007309C	sw     zero, $f118(at)
800730A0	lw     v1, $0000(s0)
800730A4	lui    a0, $800b
800730A8	lw     a0, $ed5c(a0)
800730AC	lui    v0, $800b
800730B0	lw     v0, $ed64(v0)
800730B4	lw     a1, $ffe8(s0)
800730B8	subu   a0, v1, a0
800730C0	subu   a1, v0, a1
system_get_rotation_based_on_vector_x_y();

800730C4	lui    v1, $800b
800730C8	lw     v1, $ed9c(v1)
800730CC	lui    a0, $800b
800730D0	lw     a0, $ed8c(a0)
800730D4	addiu  v0, v0, $fc00 (=-$400)
800730D8	lui    at, $800b
800730DC	sh     v0, $ee62(at)
800730E0	lui    v0, $800b
800730E4	lw     v0, $ed94(v0)
800730E8	lui    a1, $800b
800730EC	lw     a1, $ed84(a1)
800730F0	subu   a0, v1, a0
800730F4	jal    system_get_rotation_based_on_vector_x_y [$8004b1d4]
800730F8	subu   a1, v0, a1
800730FC	lui    a0, $800b
80073100	lw     a0, $ed64(a0)
80073104	lw     v1, $ffe8(s0)
80073108	addiu  v0, v0, $fc00 (=-$400)
8007310C	lui    at, $800b
80073110	sh     v0, $ee60(at)
80073114	lw     a1, $0000(s0)
80073118	lui    v0, $800b
8007311C	lw     v0, $ed5c(v0)
80073120	subu   a0, a0, v1
80073124	sra    a0, a0, $10
80073128	subu   a1, a1, v0
8007312C	jal    length_of_vector_by_x_y [$80099020]
80073130	sra    a1, a1, $10
80073134	lui    a1, $800b
80073138	lw     a1, $ed68(a1)
8007313C	lui    v1, $800b
80073140	lw     v1, $ed58(v1)
80073144	addu   a0, v0, zero
80073148	subu   a1, a1, v1
8007314C	jal    system_get_rotation_based_on_vector_x_y [$8004b1d4]
80073150	sra    a1, a1, $10
80073154	lui    t1, $1f80
80073158	ori    t1, t1, $03fc
8007315C	lui    at, $800b
80073160	sw     v0, $f588(at)
80073164	addu   t0, t1, zero
80073168	sw     sp, $0000(t0)
8007316C	addiu  t0, t0, $fffc (=-$4)
80073170	addu   sp, t0, zero
80073174	jal    func728c0 [$800728c0]
80073178	nop
8007317C	addiu  sp, sp, $0004
80073180	lw     sp, $0000(sp)
80073184	lw     v0, $ffe8(s0)
80073188	lui    v1, $800b
8007318C	lw     v1, $ed58(v1)
80073190	lui    a1, $800b
80073194	lw     a1, $ed5c(a1)
80073198	lui    a3, $800b
8007319C	lw     a3, $edb4(a3)
800731A0	lui    t0, $800b
800731A4	lw     t0, $edb8(t0)
800731A8	lui    a2, $800b
800731AC	lw     a2, $edbc(a2)
800731B0	sw     v0, $0010(sp)
800731B4	addu   v0, v0, a3
800731B8	sw     v0, $0010(sp)
800731BC	lui    v0, $800b
800731C0	lw     v0, $ed64(v0)
800731C4	sw     v1, $0014(sp)
800731C8	addu   v1, v1, t0
800731CC	sw     v1, $0014(sp)
800731D0	lui    v1, $800b
800731D4	lw     v1, $ed68(v1)
800731D8	sw     a1, $0018(sp)
800731DC	lw     a0, $0000(s0)
800731E0	sw     v0, $0020(sp)
800731E4	addu   v0, v0, a3
800731E8	sw     v0, $0020(sp)
800731EC	lui    v0, $800b
800731F0	lw     v0, $d0f0(v0)
800731F4	addu   a1, a1, a2
800731F8	sw     a1, $0018(sp)
800731FC	sw     v1, $0024(sp)
80073200	addu   v1, v1, t0
80073204	sw     a0, $0028(sp)
80073208	addu   a0, a0, a2
8007320C	sw     v1, $0024(sp)
80073210	beq    v0, zero, L7327c [$8007327c]
80073214	sw     a0, $0028(sp)
80073218	addiu  a0, s0, $00f8
8007321C	addiu  a1, sp, $0010
80073220	addiu  a2, sp, $0020
80073224	jal    func72de0 [$80072de0]
80073228	addiu  a3, s0, $0008
8007322C	lui    a1, $800b
80073230	addiu  a1, a1, $ed30 (=-$12d0)
80073234	lw     v0, $00f8(s0)
80073238	lw     v1, $00fc(s0)
8007323C	lw     a0, $0100(s0)
80073240	sw     v0, $0000(a1)
80073244	sw     v1, $0004(a1)
80073248	sw     a0, $0008(a1)
8007324C	lw     v0, $0104(s0)
80073250	lw     v1, $0108(s0)
80073254	lw     a0, $010c(s0)
80073258	sw     v0, $000c(a1)
8007325C	sw     v1, $0010(a1)
80073260	sw     a0, $0014(a1)
80073264	lw     v0, $0110(s0)
80073268	lw     v1, $0114(s0)
8007326C	sw     v0, $0018(a1)
80073270	sw     v1, $001c(a1)
80073274	j      L732d8 [$800732d8]
80073278	lui    t1, $1f80

L7327c:	; 8007327C
8007327C	lui    a0, $800b
80073280	addiu  a0, a0, $ed30 (=-$12d0)
80073284	lw     v0, $0000(a0)
80073288	lw     v1, $0004(a0)
8007328C	lw     a1, $0008(a0)
80073290	lw     a2, $000c(a0)
80073294	sw     v0, $00f8(s0)
80073298	sw     v1, $00fc(s0)
8007329C	sw     a1, $0100(s0)
800732A0	sw     a2, $0104(s0)
800732A4	lw     v0, $0010(a0)
800732A8	lw     v1, $0014(a0)
800732AC	lw     a1, $0018(a0)
800732B0	lw     a2, $001c(a0)
800732B4	sw     v0, $0108(s0)
800732B8	sw     v1, $010c(s0)
800732BC	sw     a1, $0110(s0)
800732C0	sw     a2, $0114(s0)
800732C4	addiu  a1, sp, $0010
800732C8	addiu  a2, sp, $0020
800732CC	jal    func72de0 [$80072de0]
800732D0	addiu  a3, s0, $0008
800732D4	lui    t1, $1f80

L732d8:	; 800732D8
800732D8	ori    t1, t1, $03fc
800732DC	addu   t0, t1, zero
800732E0	sw     sp, $0000(t0)
800732E4	addiu  t0, t0, $fffc (=-$4)
800732E8	addu   sp, t0, zero
800732EC	jal    func71984 [$80071984]
800732F0	addu   s2, zero, zero
800732F4	addiu  sp, sp, $0004
800732F8	lw     sp, $0000(sp)
800732FC	lui    v0, $800b
80073300	lw     v0, $d0d4(v0)
80073304	nop
80073308	blez   v0, L73488 [$80073488]
8007330C	nop
80073310	addu   s1, zero, zero

loop73314:	; 80073314
80073314	lui    v0, $800b
80073318	lw     v0, $efe4(v0)
8007331C	nop
80073320	addu   a0, s1, v0
80073324	lhu    v1, $0058(a0)
80073328	nop
8007332C	andi   v0, v1, $0f40
80073330	beq    v0, zero, L73470 [$80073470]
80073334	andi   v0, v1, $0020
80073338	bne    v0, zero, L73470 [$80073470]
8007333C	lui    v0, $0010
80073340	lw     s0, $004c(a0)
80073344	nop
80073348	lw     a0, $0004(s0)
8007334C	nop
80073350	and    v0, a0, v0
80073354	bne    v0, zero, L73470 [$80073470]
80073358	andi   v1, a0, $0600
8007335C	ori    v0, zero, $0200
80073360	beq    v1, v0, L73470 [$80073470]
80073364	nop
80073368	lw     v1, $0000(s0)
8007336C	nop
80073370	andi   v0, v1, $8000
80073374	bne    v0, zero, L733e8 [$800733e8]
80073378	lui    v0, $0020
8007337C	lw     a1, $0014(s0)
80073380	nop
80073384	and    v0, a1, v0
80073388	beq    v0, zero, L73398 [$80073398]
8007338C	andi   v0, v1, $1800
80073390	beq    v0, zero, L733c8 [$800733c8]
80073394	ori    a2, zero, $0200

L73398:	; 80073398
80073398	andi   v0, a0, $2000
8007339C	bne    v0, zero, L733b0 [$800733b0]
800733A0	nop
800733A4	lh     a2, $011e(s0)
800733A8	j      L733b8 [$800733b8]
800733AC	nop

L733b0:	; 800733B0
800733B0	lui    a2, $800b
800733B4	lh     a2, $1688(a2)

L733b8:	; 800733B8
800733B8	lh     a0, $0108(s0)
800733BC	lh     a1, $0106(s0)
800733C0	j      L733dc [$800733dc]
800733C4	nop

L733c8:	; 800733C8
800733C8	srl    a1, a1, $0b
800733CC	addiu  a1, a1, $fffe (=-$2)
800733D0	andi   a1, a1, $0007
800733D4	sll    a1, a1, $09
800733D8	lh     a0, $0108(s0)

L733dc:	; 800733DC
800733DC	jal    func73018 [$80073018]
800733E0	nop
800733E4	sh     v0, $0108(s0)

L733e8:	; 800733E8
800733E8	lui    v0, $800b
800733EC	lbu    v0, $cfdd(v0)
800733F0	nop
800733F4	bne    v0, zero, L73470 [$80073470]
800733F8	lui    v1, $0100
800733FC	lw     v0, $0004(s0)
80073400	nop
80073404	and    v0, v0, v1
80073408	bne    v0, zero, L7344c [$8007344c]
8007340C	nop
80073410	lui    v0, $800b
80073414	lw     v0, $efe4(v0)
80073418	nop
8007341C	addu   v0, s1, v0
80073420	lw     v1, $004c(v0)
80073424	lui    a1, $800b
80073428	lhu    a1, $ee62(a1)
8007342C	lhu    v1, $0108(v1)
80073430	lw     a0, $0004(v0)
80073434	addu   a1, a1, v1
80073438	sll    a1, a1, $10
8007343C	jal    func22218 [$80022218]
80073440	sra    a1, a1, $10
80073444	j      L73470 [$80073470]
80073448	nop

L7344c:	; 8007344C
8007344C	lui    v0, $800b
80073450	lw     v0, $efe4(v0)
80073454	nop
80073458	addu   v0, s1, v0
8007345C	lw     v1, $004c(v0)
80073460	lw     a0, $0004(v0)
80073464	lh     a1, $0108(v1)
80073468	jal    func21e40 [$80021e40]
8007346C	nop

L73470:	; 80073470
80073470	lui    v0, $800b
80073474	lw     v0, $d0d4(v0)
80073478	addiu  s2, s2, $0001
8007347C	slt    v0, s2, v0
80073480	bne    v0, zero, loop73314 [$80073314]
80073484	addiu  s1, s1, $005c

L73488:	; 80073488
if( w[800c1b60] == 0 )
{
    A0 = 8006f194; // MATRIX
    800734A4	0C0A06C6	Ж...
}
////////////////////////////////
