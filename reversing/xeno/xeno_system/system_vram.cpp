////////////////////////////////
// func4b780
8004B780	addiu  sp, sp, $ffe8 (=-$18)
8004B784	sw     s0, $0010(sp)
8004B788	lui    s0, $8005
8004B78C	addiu  s0, s0, $6f44
8004B790	sw     ra, $0014(sp)
8004B794	lhu    v0, $0000(s0)
8004B798	nop
8004B79C	bne    v0, zero, L4b848 [$8004b848]
8004B7A0	addu   v0, zero, zero
8004B7A4	lui    v1, $8005
8004B7A8	lw     v1, $7fd0(v1)
8004B7AC	lui    v0, $8005
8004B7B0	lw     v0, $7fd4(v0)
8004B7B4	lui    a1, $3333
8004B7B8	sh     zero, $0000(v0)
8004B7BC	lhu    v0, $0000(v0)
8004B7C0	ori    a1, a1, $3333
8004B7C4	sh     v0, $0000(v1)
8004B7C8	lui    v0, $8005
8004B7CC	lw     v0, $7fd8(v0)
8004B7D0	addu   a0, s0, zero
8004B7D4	sw     a1, $0000(v0)
8004B7D8	jal    func4bccc [$8004bccc]
8004B7DC	addiu  a1, zero, $041a
8004B7E0	jal    func4bcf8 [$8004bcf8]
8004B7E4	addiu  a0, s0, $0038
if( V0 != 0 )
{
    // here we load sound from cd and texture to vram
    func4b85c;
}

8004B7F8	lui    s0, $8005
8004B7FC	addiu  s0, s0, $6f80
8004B800	addiu  a0, s0, $fffc (=-$4)
8004B804	addiu  v0, s0, $0fdc
8004B80C	sw     v0, $0000(s0)

// syscall
SetCustomExitFromException(addr);


8004B810	addiu  v0, zero, $0001
8004B814	jal    func4bdc8 [$8004bdc8]
8004B818	sh     v0, $ffc4(s0)
8004B81C	lui    v1, $8005
8004B820	lw     v1, $7fcc(v1)
8004B824	jal    func4bef0 [$8004bef0]
8004B828	sw     v0, $0014(v1)
8004B82C	lui    a0, $8005
8004B830	lw     a0, $7fcc(a0)
8004B838	sw     v0, $0004(a0)

// syscall
CdRemove() // does NOT work due to SysDeqIntRP bug

8004B840	addiu  s0, s0, $ffc4 (=-$3c)

// syscall
ExitCriticalSection();

8004B844	addu   v0, s0, zero

L4b848:	; 8004B848
////////////////////////////////



////////////////////////////////
// func4b85c
if( hu[80056ff4] == 0 )
{
    ReturnFromException();
}

8004B8B8	lui    a0, $8005
8004B8BC	lw     a0, $7fd0(a0)
8004B8C0	lui    v1, $8005
8004B8C4	lhu    v1, $6f74(v1)
8004B8C8	addiu  v0, zero, $0001
8004B8CC	lui    at, $8005
8004B8D0	sh     v0, $6f46(at)
8004B8D4	lui    v0, $8005
8004B8D8	lw     v0, $7fd4(v0)
8004B8DC	lhu    a0, $0000(a0)
8004B8E0	lhu    v0, $0000(v0)
8004B8E4	and    v1, v1, a0
8004B8E8	and    v0, v0, v1
S0 = V0;

if( V0 != 0 )
{
    S3 = 1;
    loop4b8fc:	; 8004B8FC
        if( S0 != 0 )
        {
            S1 = 0;
            loop4b908:	; 8004B908
                if( S1 >= b )
                {
                    break;
                }

                if( S0 & 1 )
                {
                    V1 = w[80057fd0];
                    [V1] = h(0 NOR (S3 << S1));

                    V0 = w[80056ff8 + S1 * 4];
                    if( V0 != 0 )
                    {
                        8004B93C	jalr   v0 ra
                    }
                }

                S1 = S1 + 1;
                S0 = S0 >> 1;
                V0 = S0 & ffff;
            8004B950	bne    v0, zero, loop4b908 [$8004b908]
        }

        L4b958:	; 8004B958
        8004B958	lui    a0, $8005
        8004B95C	lw     a0, $7fd0(a0)
        8004B960	lui    v1, $8005
        8004B964	lhu    v1, $6f74(v1)
        8004B968	lui    v0, $8005
        8004B96C	lw     v0, $7fd4(v0)
        8004B970	lhu    a0, $0000(a0)
        8004B974	lhu    v0, $0000(v0)
        8004B978	and    v1, v1, a0
        8004B97C	and    v0, v0, v1
        8004B984	addu   s0, v0, zero
    8004B980	bne    v0, zero, loop4b8fc [$8004b8fc]
}

8004B988	lui    a1, $8005
8004B98C	lw     a1, $7fd0(a1)
8004B990	lui    a2, $8005
8004B994	lw     a2, $7fd4(a2)
8004B998	lhu    v1, $0000(a1)
8004B99C	lhu    v0, $0000(a2)
8004B9A0	nop
8004B9A4	and    v0, v0, v1
8004B9A8	beq    v0, zero, L4ba08 [$8004ba08]
8004B9AC	nop
8004B9B0	lui    v0, $8005
8004B9B4	lw     v0, $7fdc(v0)
8004B9B8	nop
8004B9BC	addiu  v1, v0, $0001
8004B9C0	slti   v0, v0, $0801
8004B9C4	lui    at, $8005
8004B9C8	sw     v1, $7fdc(at)
8004B9CC	bne    v0, zero, L4ba10 [$8004ba10]
8004B9D0	nop
8004B9D4	lui    a0, $8002
8004B9D8	addiu  a0, a0, $94b8 (=-$6b48)
8004B9DC	lhu    a1, $0000(a1)
8004B9E0	lhu    a2, $0000(a2)
8004B9E4	jal    func199e8 [$800199e8]
8004B9E8	nop
8004B9EC	lui    v0, $8005
8004B9F0	lw     v0, $7fd0(v0)
8004B9F4	lui    at, $8005
8004B9F8	sw     zero, $7fdc(at)
8004B9FC	sh     zero, $0000(v0)
8004BA00	j      L4ba10 [$8004ba10]
8004BA04	nop

L4ba08:	; 8004BA08
8004BA08	lui    at, $8005
8004BA0C	sw     zero, $7fdc(at)

L4ba10:	; 8004BA10
8004BA10	lui    at, $8005
8004BA14	sh     zero, $6f46(at)

// syscall
ReturnFromException();
////////////////////////////////



////////////////////////////////
// func24e3c
V0 = w[GP + 188];
S0 = w[80058b60 + V0 * 4];
if( S0 != 0 )
{
    loop24e68:	; 80024E68
        A1 = w[S0 + 8]; // start address
        if( A1 != 0 )
        {
            A0 = S0; // struct with size
            func4470c;
        }
        else
        {
            A0 = S0;
            A1 = 0;
            A2 = 0;
            A3 = 0;
            80024E90	jal    func445dc [$800445dc]
        }

        S0 = w[S0 + c];
    80024EA0	bne    s0, zero, loop24e68 [$80024e68]
}
V0 = w[GP + 188];
[80058b60 + V0 * 4] = w(0);
////////////////////////////////



////////////////////////////////
// func4bf40
8004BF40	lui    v0, $8006
8004BF44	lw     v0, $8008(v0)
8004BF68	lw     v0, $0000(v0)
8004BF6C	nop
8004BF70	srl    v0, v0, $18
8004BF74	andi   s1, v0, $007f
8004BF78	beq    s1, zero, L4c01c [$8004c01c]
8004BF7C	nop
8004BF80	addiu  s4, zero, $0001
8004BF84	lui    s3, $00ff
8004BF88	ori    s3, s3, $ffff
8004BF8C	lui    s5, $8006
8004BF90	addiu  s5, s5, $800c (=-$7ff4)

loop4bf94:	; 8004BF94
8004BF94	beq    s1, zero, L4bff8 [$8004bff8]
8004BF98	addu   s0, zero, zero
8004BF9C	addu   s2, s5, zero

loop4bfa0:	; 8004BFA0
8004BFA0	slti   v0, s0, $0007
8004BFA4	beq    v0, zero, L4bff8 [$8004bff8]
8004BFA8	andi   v0, s1, $0001
8004BFAC	beq    v0, zero, L4bfe8 [$8004bfe8]
8004BFB0	addiu  v0, s0, $0018
8004BFB4	lui    a0, $8006
8004BFB8	lw     a0, $8008(a0)
8004BFBC	sllv   v0, v0, s4
8004BFC0	lw     v1, $0000(a0)
8004BFC4	or     v0, v0, s3
8004BFC8	and    v1, v1, v0
8004BFCC	sw     v1, $0000(a0)
8004BFD0	lw     v0, $0000(s2)
8004BFD4	nop
8004BFD8	beq    v0, zero, L4bfe8 [$8004bfe8]
8004BFDC	nop
8004BFE0	jalr   v0 ra
8004BFE4	nop

L4bfe8:	; 8004BFE8
8004BFE8	addiu  s2, s2, $0004
8004BFEC	srl    s1, s1, $01
8004BFF0	bne    s1, zero, loop4bfa0 [$8004bfa0]
8004BFF4	addiu  s0, s0, $0001

L4bff8:	; 8004BFF8
8004BFF8	lui    v0, $8006
8004BFFC	lw     v0, $8008(v0)
8004C000	nop
8004C004	lw     v0, $0000(v0)
8004C008	nop
8004C00C	srl    v0, v0, $18
8004C010	andi   s1, v0, $007f
8004C014	bne    s1, zero, loop4bf94 [$8004bf94]
8004C018	nop

L4c01c:	; 8004C01C
8004C01C	lui    a1, $8006
8004C020	lw     a1, $8008(a1)
8004C024	nop
8004C028	lw     v0, $0000(a1)
8004C02C	lui    v1, $ff00
8004C030	and    v0, v0, v1
8004C034	lui    v1, $8000
8004C038	beq    v0, v1, L4c054 [$8004c054]
8004C03C	nop
8004C040	lw     v0, $0000(a1)
8004C044	nop
8004C048	andi   v0, v0, $8000
8004C04C	beq    v0, zero, L4c09c [$8004c09c]
8004C050	nop

L4c054:	; 8004C054
8004C054	lui    a0, $8002
8004C058	addiu  a0, a0, $94d4 (=-$6b2c)
8004C05C	lw     a1, $0000(a1)
8004C060	jal    func199e8 [$800199e8]
8004C064	addu   s0, zero, zero

loop4c068:	; 8004C068
8004C068	lui    a0, $8002
8004C06C	addiu  a0, a0, $94f0 (=-$6b10)
8004C070	addu   a1, s0, zero
8004C074	lui    v0, $8006
8004C078	lw     v0, $802c(v0)
8004C07C	sll    v1, s0, $04
8004C080	addu   v1, v1, v0
8004C084	lw     a2, $0000(v1)
8004C088	jal    func199e8 [$800199e8]
8004C08C	addiu  s0, s0, $0001
8004C090	slti   v0, s0, $0007
8004C094	bne    v0, zero, loop4c068 [$8004c068]
8004C098	nop

L4c09c:	; 8004C09C
////////////////////////////////



////////////////////////////////
// func2b960
V0 = w[8004f4e4];
S0 = w[8004f4d0];

A0 = 0;

if( V0 > 0 )
{
    A1 = hu[8004f4cc];
    V1 = V0;

    loop2b994:	; 8002B994
        V0 = hu[S0];
        if( V0 == 1 )
        {
            V0 = hu[S0 + 2];
            8002B9AC	beq    v0, a1, L2b9cc [$8002b9cc]
        }

        8002B9A0	addiu  v0, a0, $0001
        8002B9B4	addu   a0, v0, zero
        8002B9B8	sll    v0, v0, $10
        8002B9BC	sra    v0, v0, $10
        8002B9C8	addiu  s0, s0, $0008
        8002B9C0	slt    v0, v0, v1
    8002B9C4	bne    v0, zero, loop2b994 [$8002b994]
}

L2b9cc:	; 8002B9CC
8002B9CC	sll    v0, a0, $10
V1 = w[8004f4e4];
8002B9D8	sra    a0, v0, $10
if( A0 == V1 )
{
    return;
}

A0 = A0 * 800;

[S0] = h(2);

if( w[800595ec] == 0 ) // if texture not started
{
    A2 = w[8004f4ac] + A0;
    T0 = w[A2];
    A2 = A2 + 4;
    V0 = T0 - 1200;
    if( V0 >= 2 )
    {
        [8004f49c] = w(0);

        V0 = w[80057fcc];
        V0 = w[V0 + 4];
        A0 = 3;
        A1 = 0;
        8004B660	jalr   v0 ra

        A0 = w[8004f4dc];
        8002BD00	jal    func2a1a4 [$8002a1a4]

        [8004f4a0] = w(0);
        return;
    }

    if( T0 == 1200 )
    {
        if( h[800595c0] == 1 )
        {
            [800595dc] = h(hu[800595c4] + hu[A2 + 4]); // x
            [800595e0] = h(hu[800595c8] + hu[A2 + 6]); // y
        }
        else if( h[800595c0] == 2 )
        {
            [800595dc] = h(hu[800595c4] + hu[A2 + 0] + hu[A2 + 4]); // x
            [800595e0] = h(hu[800595c8] + hu[A2 + 2] + hu[A2 + 6]); // y
        }
        else
        {
            [800595dc] = h(hu[A2 + 0] + hu[A2 + 4]); // x
            [800595e0] = h(hu[A2 + 2] + hu[A2 + 6]); // y
        }
    }

    if( T0 == 1201 )
    {
        if( h[800595cc] == 1 )
        {
            [800595dc] = h(hu[800595d0] + hu[A2 + 4]); // x
            [800595e0] = h(hu[800595d4] + hu[A2 + 6]); // y
        }
        else if( h[800595cc] == 2 )
        {
            [800595dc] = h(hu[800595d0] + hu[A2 + 0] + hu[A2 + 4]);
            [800595e0] = h(hu[800595d4] + hu[A2 + 2] + hu[A2 + 6]);
        }
        else
        {
            [800595dc] = h(hu[A2 + 0] + hu[A2 + 4]); // x
            [800595e0] = h(hu[A2 + 2] + hu[A2 + 6]); // y
        }
    }

    A2 = A2 + 8;
    [800595e4] = h(hu[A2]); // width
    A2 = A2 + 8;

    if( w[800595d8] == 0 )
    {
        [800595d8] = w(w[A2]);
    }
    A2 = A2 + 4;
    [800595ec] = w(w[A2]); // number_of_chunk
    A2 = A2 + 4;
    [800595e8] = w(A2);
}
else
{
    A1 = w[800595e8];
    [SP + 10] = h(hu[800595dc]); // x
    [SP + 12] = h(hu[800595e0]); // y
    [SP + 14] = h(hu[800595e4]); // width
    [SP + 16] = h(hu[A1]); // height

    A0 = SP + 10; // struct with size (0 x, 2 y, 4 width, 6 height)
    A1 = A2; // start address
    func4470c;

    A0 = w[800595e8];
    V1 = hu[800595e0];
    [800595e8] = w(A0 + 2);
    A0 = hu[A0];
    V1 = V1 + A0;
    [800595ec] = w(w[800595ec] - 1); // descrease number of chank by 1
    [800595e0] = h(V1);
    if( w[800595ec] <= 0 )
    {
        8002BC74	lui    v0, $8006
        8002BC78	lw     v0, $95d8(v0)
        8002BC7C	lui    a1, $8005
        8002BC80	lw     a1, $f4e4(a1)
        8002BC84	lui    at, $8006
        8002BC88	sw     zero, $95ec(at)
        8002BC8C	addiu  v0, v0, $ffff (=-$1)
        8002BC90	lui    at, $8006
        8002BC94	sw     v0, $95d8(at)
        8002BC9C	addu   a0, zero, zero
        if( A1 < 0 )
        {
            8002BCA0	lui    a2, $8005
            8002BCA4	lw     a2, $f4d0(a2)

            loop2bca8:	; 8002BCA8
                8002BCA8	sll    v1, a0, $10
                8002BCAC	addiu  v0, a0, $0001
                8002BCB0	addu   a0, v0, zero
                8002BCB4	sra    v1, v1, $0d
                8002BCB8	addu   v1, v1, a2
                8002BCBC	sll    v0, v0, $10
                8002BCC0	sra    v0, v0, $10
                8002BCC4	slt    v0, v0, a1
                8002BCC8	sh     zero, $0000(v1)
                8002BCD0	sh     zero, $0002(v1)
            8002BCCC	bne    v0, zero, loop2bca8 [$8002bca8]
        }

        V0 = w[800595d8];
        if( V0 <= 0 )
        {
            [8004f49c] = w(0);

            V0 = w[80057fcc];
            V0 = w[V0 + 4];
            A0 = 3;
            A1 = 0;
            8004B660	jalr   v0 ra

            A0 = w[8004f4dc];
            8002BD00	jal    func2a1a4 [$8002a1a4]

            [8004f4a0] = w(0);
            return;
        }
    }

    8002BD18	sh     zero, $0000(s0)
}
[8004f4cc] = h(hu[8004f4cc] + 1);
////////////////////////////////



////////////////////////////////
// func4470c
S0 = A0; // struct with size
S1 = A1; // start address

A0 = 80019220;
A1 = S0;
8004472C	jal    func444b4 [$800444b4]

V0 = w[80055f68];
A0 = w[V0 + 20]; // func
A1 = S0; // struct with size (0 x, 2 y, 4 width, 6 height)
A2 = 8;
A3 = S1; // start address
// called here func46504
V0 = w[V0 + 8];
80044750	jalr   v0 ra
////////////////////////////////



////////////////////////////////
// func46504
S3 = A0; // func
S0 = A1; // struct with size;
S1 = A2;
S2 = A3; // start address


80046528	jal    func46d74 [$80046d74]

80046530	j      L46550 [$80046550]
80046534	nop

loop46538:	; 80046538
80046538	jal    func46da8 [$80046da8]
8004653C	nop
80046540	bne    v0, zero, L467c4 [$800467c4]
80046544	addiu  v0, zero, $ffff (=-$1)
80046548	jal    func467e4 [$800467e4]
8004654C	nop

L46550:	; 80046550
80046550	lui    v0, $8005
80046554	lw     v0, $6074(v0)
80046558	lui    v1, $8005
8004655C	lw     v1, $6078(v1)
80046560	addiu  v0, v0, $0001
80046564	andi   v0, v0, $003f
80046568	beq    v0, v1, loop46538 [$80046538]
8004656C	nop
80046570	jal    func4b764 [$8004b764]
80046574	addu   a0, zero, zero
80046578	lui    v1, $8005
8004657C	lbu    v1, $5f71(v1)
80046580	lui    at, $8005
80046584	sw     v0, $607c(at)
80046588	addiu  v0, zero, $0001
8004658C	lui    at, $8005
80046590	sw     v0, $5f78(at)
80046594	beq    v1, zero, L465ec [$800465ec]
80046598	nop
8004659C	lui    v1, $8005
800465A0	lw     v1, $6074(v1)
800465A4	lui    v0, $8005
800465A8	lw     v0, $6078(v0)
800465AC	nop
800465B0	bne    v1, v0, L4664c [$8004664c]
800465B4	nop
800465B8	lui    v0, $8005
800465BC	lw     v0, $6050(v0)
800465C0	nop
800465C4	lw     v0, $0000(v0)
800465C8	lui    v1, $0100
800465CC	and    v0, v0, v1
800465D0	bne    v0, zero, L4664c [$8004664c]
800465D4	nop
800465D8	lui    v0, $8005
800465DC	lw     v0, $5f7c(v0)
800465E0	nop
800465E4	bne    v0, zero, L4664c [$8004664c]
800465E8	nop

L465ec:	; 800465EC
800465EC	lui    v1, $8005
800465F0	lw     v1, $6044(v1)
800465F4	lui    a0, $0400

loop465f8:	; 800465F8
800465F8	lw     v0, $0000(v1)
800465FC	nop
80046600	and    v0, v0, a0
80046604	beq    v0, zero, loop465f8 [$800465f8]

// called here func45f18
A0 = S0; // struct with size
A1 = S2;
80046610	jalr   s3 ra

80046618	lui    a0, $8005
8004661C	lw     a0, $607c(a0)
80046620	lui    v0, $8005
80046624	addiu  v0, v0, $6064
80046628	sw     s3, $0000(v0)
8004662C	lui    at, $8005
80046630	sw     s0, $6068(at)
80046634	lui    at, $8005
80046638	sw     s2, $606c(at)
8004663C	jal    func4b764 [$8004b764]
80046640	nop
80046644	j      L467c4 [$800467c4]
80046648	addu   v0, zero, zero

L4664c:	; 8004664C
8004664C	lui    a1, $8004
80046650	addiu  a1, a1, $67e4
80046654	jal    func4b648 [$8004b648]
80046658	addiu  a0, zero, $0002
8004665C	beq    s1, zero, L4670c [$8004670c]
80046660	addu   a2, zero, zero
80046664	lui    t0, $8007
80046668	addiu  t0, t0, $b4d0 (=-$4b30)
8004666C	addu   a3, s0, zero
80046670	addu   v0, s1, zero

L46674:	; 80046674
80046674	bgez   v0, L46680 [$80046680]
80046678	nop
8004667C	addiu  v0, v0, $0003

L46680:	; 80046680
80046680	sra    v0, v0, $02
80046684	slt    v0, a2, v0
80046688	beq    v0, zero, L466c4 [$800466c4]
8004668C	sll    a0, a2, $02
80046690	lw     a1, $0000(a3)
80046694	addiu  a3, a3, $0004
80046698	lui    v1, $8005
8004669C	lw     v1, $6074(v1)
800466A0	addiu  a2, a2, $0001
800466A4	sll    v0, v1, $01
800466A8	addu   v0, v0, v1
800466AC	sll    v0, v0, $05
800466B0	addu   v0, v0, t0
800466B4	addu   a0, a0, v0
800466B8	sw     a1, $0000(a0)
800466BC	j      L46674 [$80046674]
800466C0	addu   v0, s1, zero

L466c4:	; 800466C4
800466C4	lui    v0, $8005
800466C8	lw     v0, $6074(v0)
800466CC	lui    v1, $8005
800466D0	lw     v1, $6074(v1)
800466D4	sll    a0, v0, $01
800466D8	addu   a0, a0, v0
800466DC	sll    a0, a0, $05
800466E0	sll    v0, v1, $01
800466E4	addu   v0, v0, v1
800466E8	sll    v0, v0, $05
800466EC	lui    v1, $8007
800466F0	addiu  v1, v1, $b4d0 (=-$4b30)
800466F4	addu   v0, v0, v1
800466F8	lui    at, $8007
800466FC	addu   at, at, a0
80046700	sw     v0, $b4c8(at)
80046704	j      L46730 [$80046730]
80046708	nop

L4670c:	; 8004670C
8004670C	lui    v1, $8005
80046710	lw     v1, $6074(v1)
80046714	nop
80046718	sll    v0, v1, $01
8004671C	addu   v0, v0, v1
80046720	sll    v0, v0, $05
80046724	lui    at, $8007
80046728	addu   at, at, v0
8004672C	sw     s0, $b4c8(at)

L46730:	; 80046730
80046730	lui    v1, $8005
80046734	lw     v1, $6074(v1)
80046738	nop
8004673C	sll    v0, v1, $01
80046740	addu   v0, v0, v1
80046744	sll    v0, v0, $05
80046748	lui    at, $8007
8004674C	addu   at, at, v0
80046750	sw     s2, $b4cc(at)
80046754	lui    v1, $8005
80046758	lw     v1, $6074(v1)
8004675C	nop
80046760	sll    v0, v1, $01
80046764	addu   v0, v0, v1
80046768	sll    v0, v0, $05
8004676C	lui    at, $8007
80046770	addu   at, at, v0
80046774	sw     s3, $b4c4(at)
80046778	lui    v0, $8005
8004677C	lw     v0, $6074(v0)
80046780	lui    a0, $8005
80046784	lw     a0, $607c(a0)
80046788	addiu  v0, v0, $0001
8004678C	andi   v0, v0, $003f
80046790	lui    at, $8005
80046794	sw     v0, $6074(at)
80046798	jal    func4b764 [$8004b764]
8004679C	nop
800467A0	jal    func467e4 [$800467e4]
800467A4	nop
800467A8	lui    v0, $8005
800467AC	lw     v0, $6074(v0)
800467B0	lui    v1, $8005
800467B4	lw     v1, $6078(v1)
800467B8	nop
800467BC	subu   v0, v0, v1
800467C0	andi   v0, v0, $003f

L467c4:	; 800467C4
////////////////////////////////



////////////////////////////////
// func45f18
// transfer to vram

S1 = A0; // struct with size (0 x, 2 y, 4 width, 6 height)
S2 = A1; // start address

80045F3C	jal    func46d74 [$80046d74]

V1 = h[S1 + 4];
if( V1 < 0 )
{
    V1 = 0;
}
else if( V1 > h[80055f74] )
{
    V1 = h[80055f74];
}
[S1 + 4] = h(V1);

A0 = h[S1 + 6];
if( A0 < 0 )
{
    A0 = 0;
}
else if( h[80055f76] < A0 )
{
    A0 = h[80055f76];
}
[S1 + 6] = h(A0);

A2 = h[S1 + 4] * h[S1 + 6];
A0 = A2 / 2;

S0 = A2 >> 5;
if( A0 <= 0 )
{
    return -1;
}

S4 = S0;
S0 = A0 - (S0 << 4);

V0 = w[80056044];
V0 = w[V0] & 04000000;
if( V0 == 0 )
{
    loop4601c:	; 8004601C
        8004601C	jal    func46da8 [$80046da8]

        if( V0 != 0 )
        {
            return -1;
        }

        V0 = w[80056044];
        V0 = w[V0] & 04000000;
    80046044	beq    v0, zero, loop4601c [$8004601c]
}

V1 = w[80056044];    // 1f801814
[V1] = w(04000000);  // DMA Direction 0=Off
V1 = w[80056040];    // 1f801810
[V1] = w(01000000);  //  Clear Cache
[V1] = w(a0000000);  // Copy Rectangle (CPU to VRAM)
[V1] = w(w[S1 + 0]); // Destination Coord (YyyyXxxxh)
[V1] = w(w[S1 + 4]); // Width+Height      (YsizXsizh)

S0 = S0 - 1;
if( S0 != -1 )
{
    loop460bc:	; 800460BC
        V0 = w[80056040]; // 1f801810
        [V0] = w(w[S2]);
        S2 = S2 + 4;
        S0 = S0 - 1;
    800460D4	bne    s0, -1, loop460bc [$800460bc]
}

if( S4 != 0 )
{
    V0 = w[80056044]; // 1f801814 GP1 Send GP1 Commands (Display Control)
    [V0] = w(04000002); // DMA Direction 2=CPUtoGP0

    V0 = w[80056048]; // 1f8010a0 vram gpu dma transfer
    [V0] = w(S2); // src address

    V1 = w[8005604c];
    [V1] = w((S4 << 10) | 0010); // size

    // 0000 0001 0000 0000 0000 0010 0000 0001
    // 00 Transfer Direction 1=From Main RAM
    // 09-10    SyncMode, Transfer Synchronisation/Mode (0-3): 1 Sync blocks to DMA requests (used for MDEC, SPU, and GPU-data)
    // 24 Start/Busy 1=Start/Enable/Busy
    V0 = w[80056050]; // 1f8010a8 DMA Channel Control
    [V0] = w(01000201); //
}

return 0;
////////////////////////////////
