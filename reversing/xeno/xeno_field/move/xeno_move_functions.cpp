////////////////////////////////
// func84054()
//    A1 = S7;
//    A2 = leader_5c;
//    A4 = w[SP + 78];

entity_id = S6 = A0;
S7 = A1;

V1 = w[800aefe4];
S5 = w[V1 + entity_id * 5c + 4];

data_138 = S1 = A3;

if( entity_id == w[800b1740] ) // if entity is party leader
{
    [800acfd8] = h(ffff);
}

if( w[data_138 + 0] & 01000000 ) // skip movement flag
{
    return -1;
}
if( ( w[data_138 + 4] & 00200000 ) || ( w[data_138 + 0] & 00010000 ) ) // both flags removed in 0x19_SetPosition.
{
    return -1;
}

if( ( entity_id != w[800b1740] ) || ( bu[800b16a3] != 1 ) ) // if entity not party leader or 
{
    if( w[S5 + 10] == 0 )
    {
        A0 = data_138;
        func83f40();
        if( V0 == 0 )
        {
            if( h[S5 + 84] == h[data_138 + 26] )
            {
                return -1;
            }
        }
    }
}

[SP + 90] = w(w[data_138 + 20]); // cur x
[SP + 94] = w(w[data_138 + 24]); // cur y
[SP + 98] = w(w[data_138 + 28]); // cur z

walkmesh_id = FP = hu[data_138 + 10];

S0 = 0;
loop84180:	; 80084180
    [SP + a0 + S0 * 2] = h(hu[data_138 + 8 + S0 * 2]);
    S0 = S0 + 1;
    V0 = S0 < 4;
80084194	bne    v0, zero, loop84180 [$80084180]

S0 = 0;
loop841ac:	; 800841AC
    [SP + 18 + S0 * 4] = w(7fffffff);
    [SP + 28 + S0 * 4] = w(7fffffff);
    [SP + 38 + S0 * 4] = w(S0);

    S0 = S0 + 1;
    V0 = S0 < 4;
800841C0	bne    v0, zero, loop841ac [$800841ac]

walkmesh_blocks = h[800af028] - 1;
if( walkmesh_blocks > 0 )
{
    S4 = 0;
    loop841ec:	; 800841EC
        A0 = data_138;
        A1 = S4;
        A2 = SP + 18 + S4 * 4; // end y pos on triangle
        A3 = SP + 50 + S4 * 10; // normal to triangle
        A4 = SP + 48 + S4 * 2; // triangle id
        A5 = SP + 28 + S4 * 4; // end y pos on triangle + [d] data from triangle
        func7c9e8();
        if( V0 != 0 ) // -1 - triangle not found, 0 - triangle found
        {
            break;
        }
        S4 = S4 + 1;
        V0 = S4 < walkmesh_blocks;
    80084238	bne    v0, zero, loop841ec [$800841ec]
}

if( w[data_138 + 4] & 00000001 )
{
    [SP + 18] = w(7fffffff);
    [SP + 28] = w(7fffffff);
}

if( w[data_138 + 4] & 00000002 )
{
    [SP + 1c] = w(7fffffff);
    [SP + 2c] = w(7fffffff);
}

if( w[data_138 + 4] & 00000004 )
{
    [SP + 20] = w(7fffffff);
    [SP + 30] = w(7fffffff);
}

walkmesh_id = h[data_138 + 10];
T4 = w[SP + 18 + walkmesh_id * 4];



// sort found blocks and triangles from less to greatest Y pos
S0 = 0;
loop842c4:	; 800842C4
    T0 = 0;
    loop842d4:	; 800842D4
        A0 = w[SP + 18 + T0 * 4];
        A1 = w[SP + 1c + T0 * 4];
        // swap less to first
        if( A1 < A0 )
        {
            [SP + 1c + T0 * 4] = w(A0);
            [SP + 18 + T0 * 4] = w(A1);

            A0 = w[SP + 2c + T0 * 4];
            [SP + 2c + T0 * 4] = w(w[SP + 28 + T0 * 4]);
            [SP + 28 + T0 * 4] = w(A0);

            A0 = w[SP + 3c + T0 * 4];
            [SP + 3c + T0 * 4] = w(w[SP + 38 + T0 * 4]);
            [SP + 38 + T0 * 4] = w(A0);
        }

        T0 = T0 + 1;
        V0 = T0 < 2;
    80084324	bne    v0, zero, loop842d4 [$800842d4]

    S0 = S0 + 1;
    V0 = S0 < 2;
80084334	bne    v0, zero, loop842c4 [$800842c4]



A1 = 800af028;
V0 = h[A1];
V0 = V0 - 1;

80084350	bne    s4, v0, L845e0 [$800845e0]

if( S4 > 0 )
{
    S0 = 0;
    A0 = SP + 18;
    V1 = S1;

    loop84368:	; 80084368
        V0 = hu[A0 + 30];
        A0 = A0 + 2;
        S0 = S0 + 1;
        [V1 + 8] = h(V0);

        V1 = V1 + 2;

        V0 = h[A1 + 0];
        V0 = V0 - 1;
        V0 = S0 < V0;
    80084388	bne    v0, zero, loop84368 [$80084368]
}

80084390	lh     a0, $0026(s1)
80084394	nop
80084398	slt    v0, a0, t4
8008439C	bne    v0, zero, L843b8 [$800843b8]
800843A0	nop
800843A4	lw     v0, $0000(s1)
800843A8	nop
800843AC	andi   v0, v0, $1800
800843B0	beq    v0, zero, L84414 [$80084414]
800843B4	nop

L843b8:	; 800843B8
800843B8	lui    v0, $800b
800843BC	lh     v0, $f028(v0)
800843C0	nop
800843C4	addiu  v0, v0, $ffff (=-$1)
800843C8	blez   v0, L84458 [$80084458]
800843CC	addu   s0, zero, zero
800843D0	addu   a2, v0, zero
800843D4	addiu  a1, sp, $0018

loop843d8:	; 800843D8
800843D8	addu   v1, a1, zero
800843DC	lw     v0, $0000(v1)
800843E0	nop
800843E4	slt    v0, v0, a0
800843E8	beq    v0, zero, L84408 [$80084408]
800843EC	nop
800843F0	addiu  s0, s0, $0001
800843F4	slt    v0, s0, a2
800843F8	bne    v0, zero, loop843d8 [$800843d8]
800843FC	addiu  a1, v1, $0004
80084400	j      L84458 [$80084458]
80084404	nop

L84408:	; 80084408
80084408	lw     v0, $0020(a1)
8008440C	j      L84458 [$80084458]
80084410	sh     v0, $0010(s1)

L84414:	; 80084414
80084414	lui    v0, $800b
80084418	lh     v0, $f028(v0)
8008441C	nop
80084420	addiu  v0, v0, $ffff (=-$1)
80084424	blez   v0, L84458 [$80084458]
80084428	addu   s0, zero, zero
8008442C	lh     a1, $0010(s1)
80084430	addu   a0, v0, zero
80084434	addiu  v1, sp, $0018

loop84438:	; 80084438
    80084438	lw     v0, $0020(v1)
    8008443C	nop
    80084440	beq    a1, v0, L84458 [$80084458]
    80084444	nop
    80084448	addiu  s0, s0, $0001
    80084454	addiu  v1, v1, $0004
    8008444C	slt    v0, s0, a0
80084450	bne    v0, zero, loop84438 [$80084438]

L84458:	; 80084458
80084458	jal    get_current_triangle_material [$8007ff7c]
8008445C	addu   a0, s1, zero
80084460	andi   v0, v0, $0004
80084464	beq    v0, zero, L844a4 [$800844a4]
80084468	nop
8008446C	beq    s0, zero, L844a4 [$800844a4]
80084470	nop
80084474	lui    v0, $800b
80084478	lh     v0, $f028(v0)
8008447C	lh     v1, $0010(s1)
80084480	addiu  v0, v0, $ffff (=-$1)
80084484	slt    v0, v0, v1
80084488	bne    v0, zero, L844a4 [$800844a4]
8008448C	addiu  s0, s0, $ffff (=-$1)
80084490	sll    v0, s0, $02
80084494	addu   v0, sp, v0
80084498	lw     v0, $0038(v0)
8008449C	nop
800844A0	sh     v0, $0010(s1)

L844a4:	; 800844A4
A0 = data_138;
get_current_triangle_material();
material = V0;

if( ( ( w[data_138 + 0] >> 8 ) & 7 ) & ( material >> 5 ) ) // unpassable triangle for this entity
{
    // DEBUG TEXT
    if( w[800c1b60] == 0 )
    {
        A0 = 8006f2f0; // ERROR ID1 ACT=%d
        A1 = entity_id;
        func37870();
    }

    if( S6 == w[800b1470] )
    {
        [800acfd8] = h(0fff);
    }

    [S1 + 24] = w(w[S1 + 24] + w[S5 + 10]);
    8008454C	j      L849ac [$800849ac]

}
else if( ( material & 00800000 ) != 0 ) // unpassable material for walkmesh 0
{
    if( w[800c1b60] == 0 )
    {
        A0 = 8006f304; // ERROR ID0 ACT=%d
        A1 = entity_id;
        func37870();
    }

    if( S6 == w[800b1470] )
    {
        [800acfd8] = h(0fff);
    }

    [S1 + 24] = w(w[S1 + 24] + w[S5 + 10]);
    8008454C	j      L849ac [$800849ac]
}

80084560	lw     v0, $0020(s1)
80084564	lw     a0, $0030(s1)
80084568	lw     v1, $0028(s1)
8008456C	lw     a1, $0038(s1)
80084570	addu   v0, v0, a0
80084574	addu   v1, v1, a1
80084578	sw     v0, $0020(s1)
8008457C	sw     v1, $0028(s1)
80084580	lui    v0, $800b
80084584	lh     v0, $f028(v0)
80084588	nop
8008458C	addiu  v0, v0, $ffff (=-$1)
80084590	blez   v0, L845c0 [$800845c0]
80084594	addu   s0, zero, zero
80084598	lh     a1, $0010(s1)
8008459C	addu   a0, v0, zero
800845A0	addiu  v1, sp, $0018

loop845a4:	; 800845A4
800845A4	lw     v0, $0020(v1)
800845B0	addiu  s0, s0, $0001

if( A1 == V0 )
{
    80084554	lw     v0, $0000(v1)
    80084558	j      L845c0 [$800845c0]
    8008455C	sh     v0, $0084(s5)

}

800845B4	slt    v0, s0, a0
800845B8	bne    v0, zero, loop845a4 [$800845a4]
800845BC	addiu  v1, v1, $0004

L845c0:	; 800845C0
800845C0	addiu  a1, s1, $0050
800845C4	lh     a0, $0010(s1)
800845C8	addiu  v0, sp, $0050
800845CC	sll    a0, a0, $04
800845D0	jal    system_normalize_word_vector_T0_T1_T2_to_word [$80048c24]
800845D4	addu   a0, v0, a0
800845D8	j      L845e4 [$800845e4]
800845DC	nop

L845e0:	; 800845E0
800845E0	sw     zero, $00f0(s1)

L845e4:	; 800845E4
800845E4	lui    v0, $800b
800845E8	lw     v0, $d070(v0)
800845EC	nop
800845F0	beq    v0, zero, L84614 [$80084614]
800845F4	nop
800845F8	lw     t5, $0110(sp)
800845FC	nop
80084600	sltiu  v0, t5, $0002
80084604	beq    v0, zero, L84648 [$80084648]
80084608	nop
8008460C	j      L84648 [$80084648]
80084610	sh     s7, $0084(s5)

L84614:	; 80084614
80084614	lw     t5, $0110(sp)
80084618	nop
8008461C	beq    t5, zero, L84648 [$80084648]
80084620	addiu  v1, s7, $000a
80084624	lh     v0, $0084(s5)
80084628	nop
8008462C	slt    v0, v0, v1
80084630	beq    v0, zero, L8463c [$8008463c]
80084634	ori    v0, zero, $00ff
80084638	sb     v0, $0074(s1)

L8463c:	; 8008463C
8008463C	sll    v0, s7, $10
80084640	sh     s7, $0084(s5)
80084644	sw     v0, $0024(s1)

L84648:	; 80084648
80084648	lw     v0, $0000(s1)
8008464C	lui    v1, $0004
80084650	and    v0, v0, v1
80084654	beq    v0, zero, L84670 [$80084670]
80084658	nop
8008465C	lh     v0, $00ec(s1)
80084660	nop
80084664	sll    v0, v0, $10
80084668	sw     v0, $0024(s1)
8008466C	sw     zero, $0010(s5)

L84670:	; 80084670
80084670	lw     v0, $0024(s1)
80084674	lw     v1, $0010(s5)
80084678	addu   a0, s1, zero
8008467C	addu   v0, v0, v1
80084680	jal    get_current_triangle_material [$8007ff7c]
80084684	sw     v0, $0024(s1)
80084688	addu   a1, v0, zero
8008468C	sll    v0, fp, $10
80084690	lh     v1, $0010(s1)
80084694	sra    v0, v0, $10
80084698	beq    v1, v0, L846b0 [$800846b0]
8008469C	lui    v1, $fbff
800846A0	lw     v0, $0000(s1)
800846A4	ori    v1, v1, $ffff
800846A8	and    v0, v0, v1
800846AC	sw     v0, $0000(s1)

L846b0:	; 800846B0
800846B0	lw     v0, $0000(s1)
800846B4	lui    v1, $0400
800846B8	and    v0, v0, v1
800846BC	bne    v0, zero, L84718 [$80084718]
800846C0	lui    v0, $0042
800846C4	lh     a0, $0084(s5)
800846C8	lh     v1, $0026(s1)
800846CC	nop
800846D0	slt    v0, v1, a0
if (V0 != 0)
{
    if (A0 != V1)
    {
        800846E4	lw     v0, $0010(s5)
        800846E8	lw     v1, $001c(s5)
        800846EC	nop
        800846F0	addu   v0, v0, v1
        800846F4	sw     v0, $0010(s5)
    }

    800846F8	lw     v0, $0000(s1)
    800846FC	nop
    80084700	ori    v0, v0, $1000
    80084704	sw     v0, $0000(s1)
    80084708	lw     v0, $0010(s5)
    80084710	sw     v0, $00f0(s1)
}
else
{
    80084714	lui    v0, $0042

    L84718:	; 80084718
    80084718	and    v0, a1, v0
    8008471C	bne    v0, zero, L84728 [$80084728]
    80084720	nop
    80084724	sw     zero, $00f0(s1)

    L84728:	; 80084728
    80084728	lw     v0, $0010(s5)
    8008472C	nop
    if (V0 > 0)
    {
        [S5 + 10] = w(0);
    }

    [S1 + 0] = w(w[S1 + 0] & ffbfefff); // remove automove flag

    8008474C	lh     v0, $0084(s5)
    80084750	nop
    80084754	sll    v0, v0, $10
    80084758	sw     v0, $0024(s1)
}

[S1 + 0] = w(w[S1 + 0] & fbffffff);

80084770	lui    v0, $800b
80084774	lh     v0, $f028(v0)
80084778	nop
8008477C	addiu  v0, v0, $ffff (=-$1)
80084780	blez   v0, L847d8 [$800847d8]
80084784	addu   s0, zero, zero
80084788	lh     a2, $0026(s1)
8008478C	addu   a3, v0, zero
80084790	addiu  a0, sp, $0018

loop84794:	; 80084794
80084794	lw     a1, $0000(a0)
80084798	nop
8008479C	slt    v0, a1, a2
800847A0	beq    v0, zero, L847c8 [$800847c8]
800847A4	nop
800847A8	lhu    v0, $001a(s1)
800847AC	lw     v1, $0010(a0)
800847B0	subu   v0, a2, v0
800847B4	slt    v0, v0, v1
800847B8	beq    v0, zero, L847c8 [$800847c8]
800847BC	nop
800847C0	bne    a1, v1, L847d8 [$800847d8]
800847C4	nop

L847c8:	; 800847C8
800847C8	addiu  s0, s0, $0001
800847CC	slt    v0, s0, a3
800847D0	bne    v0, zero, loop84794 [$80084794]
800847D4	addiu  a0, a0, $0004

L847d8:	; 800847D8
800847D8	lui    a1, $800b
800847DC	addiu  a1, a1, $f028 (=-$fd8)
800847E0	lh     v0, $0000(a1)
800847E4	nop
800847E8	addiu  v0, v0, $ffff (=-$1)
800847EC	bne    s0, v0, L848d0 [$800848d0]
800847F0	nop
800847F4	lh     v0, $0010(s1)
800847F8	nop
800847FC	sll    v1, v0, $02
80084800	sll    v0, v0, $01
80084804	addu   v0, v0, s1
80084808	addu   v1, a1, v1
8008480C	lh     a0, $0008(v0)
80084810	lw     v1, $ffd0(v1)
80084814	sll    v0, a0, $03
80084818	subu   v0, v0, a0
8008481C	sll    v0, v0, $01
80084820	addu   v0, v0, v1
80084824	lb     v0, $000d(v0)
80084828	nop
8008482C	sll    a1, v0, $02
80084830	bgez   a1, L8485c [$8008485c]
80084834	addu   a0, s1, zero
80084838	lh     v0, $0026(s1)
8008483C	lhu    a0, $001a(s1)
80084840	lh     v1, $0084(s5)
80084844	subu   v0, v0, a0
80084848	addu   v1, a1, v1
8008484C	slt    v0, v0, v1
80084850	bne    v0, zero, L848d4 [$800848d4]
80084854	addu   s0, zero, zero
80084858	addu   a0, s1, zero

L8485c:	; 8008485C
8008485C	sll    v1, s6, $01
80084860	addu   v1, v1, s6
80084864	lw     v0, $0020(s1)
80084868	sll    v1, v1, $03
8008486C	sw     v0, $0000(s5)
80084870	lw     v0, $0024(s1)
80084874	subu   v1, v1, s6
80084878	sw     v0, $0004(s5)
8008487C	lw     v0, $0028(s1)
80084880	sll    v1, v1, $02
80084884	sw     v0, $0008(s5)
80084888	lui    v0, $800b
8008488C	lw     v0, $efe4(v0)
80084890	lh     a1, $0022(s1)
80084894	addu   v0, v1, v0
80084898	sw     a1, $0020(v0)
8008489C	lui    v0, $800b
800848A0	lw     v0, $efe4(v0)
800848A4	lh     a1, $0026(s1)
800848A8	addu   v0, v1, v0
800848AC	sw     a1, $0024(v0)
800848B0	lui    v0, $800b
800848B4	lw     v0, $efe4(v0)
800848B8	lh     a1, $002a(s1)
800848BC	addu   v1, v1, v0
800848C0	jal    get_current_triangle_material [$8007ff7c]
800848C4	sw     a1, $0028(v1)
800848C8	j      L849a4 [$800849a4]
800848CC	sw     v0, $0014(s1)

L848d0:	; 800848D0
800848D0	addu   s0, zero, zero

L848d4:	; 800848D4
800848D4	lw     v0, $0090(sp)
800848D8	addiu  a0, sp, $0018
800848DC	sw     v0, $0020(s1)
800848E0	lw     v0, $0098(sp)
800848E4	addu   v1, s1, zero
800848E8	sh     fp, $0010(s1)
800848EC	sw     zero, $00f0(s1)
800848F0	sw     v0, $0028(s1)

loop848f4:	; 800848F4
800848F4	lhu    v0, $0088(a0)

L848f8:	; 800848F8
800848F8	addiu  a0, a0, $0002
800848FC	addiu  s0, s0, $0001
80084900	sh     v0, $0008(v1)
80084904	slti   v0, s0, $0004
80084908	bne    v0, zero, loop848f4 [$800848f4]
8008490C	addiu  v1, v1, $0002
80084910	lh     v1, $0084(s5)
80084914	lh     v0, $0026(s1)
80084918	nop
8008491C	beq    v1, v0, L84938 [$80084938]
80084920	nop
80084924	lw     v0, $0010(s5)
80084928	lw     v1, $001c(s5)
8008492C	nop
80084930	addu   v0, v0, v1
80084934	sw     v0, $0010(s5)

L84938:	; 80084938
80084938	lw     v0, $0010(s5)
8008493C	nop
80084940	bgez   v0, L84958 [$80084958]
80084944	nop
80084948	sw     zero, $0010(s5)
8008494C	lw     v0, $0094(sp)
80084950	nop
80084954	sw     v0, $0024(s1)

L84958:	; 80084958
80084958	lw     v0, $0020(s1)
8008495C	nop
80084960	sw     v0, $0000(s5)
80084964	lw     v0, $0024(s1)
80084968	nop
8008496C	sw     v0, $0004(s5)
80084970	lw     v0, $0028(s1)
80084974	nop
80084978	sw     v0, $0008(s5)
8008497C	sll    v0, s6, $01
80084980	addu   v0, v0, s6
80084984	sll    v0, v0, $03
80084988	subu   v0, v0, s6
8008498C	sll    v0, v0, $02
80084990	lui    v1, $800b
80084994	lw     v1, $efe4(v1)
80084998	lh     a0, $0026(s1)
8008499C	addu   v0, v0, v1
800849A0	sw     a0, $0024(v0)

L849a4:	; 800849A4
800849A4	j      L84aa4 [$80084aa4]
800849A8	addu   a0, s6, zero

L849ac:	; 800849AC
800849AC	addu   s0, zero, zero
800849B0	lw     v0, $0090(sp)
800849B4	addiu  a0, sp, $0018
800849B8	sw     v0, $0020(s1)
800849BC	lw     v0, $0098(sp)
800849C0	addu   v1, s1, zero
800849C4	sh     fp, $0010(s1)
800849C8	sw     zero, $00f0(s1)
800849CC	sw     v0, $0028(s1)

loop849d0:	; 800849D0
800849D0	lhu    v0, $0088(a0)
800849D4	addiu  a0, a0, $0002
800849D8	addiu  s0, s0, $0001
800849DC	sh     v0, $0008(v1)
800849E0	slti   v0, s0, $0004
800849E4	bne    v0, zero, loop849d0 [$800849d0]
800849E8	addiu  v1, v1, $0002
800849EC	lh     a0, $0084(s5)
800849F0	lh     v1, $0026(s1)
800849F4	nop
800849F8	slt    v0, v1, a0
800849FC	beq    v0, zero, L84a24 [$80084a24]
80084A00	nop
80084A04	beq    a0, v1, L84a58 [$80084a58]
80084A08	nop
80084A0C	lw     v0, $0010(s5)
80084A10	lw     v1, $001c(s5)
80084A14	nop
80084A18	addu   v0, v0, v1
80084A1C	j      L84a58 [$80084a58]
80084A20	sw     v0, $0010(s5)

L84a24:	; 80084A24
80084A24	lw     v0, $0010(s5)
80084A28	nop
80084A2C	blez   v0, L84a38 [$80084a38]
80084A30	lui    v1, $ffbf
80084A34	sw     zero, $0010(s5)

L84a38:	; 80084A38
80084A38	lw     v0, $0000(s1)
80084A3C	ori    v1, v1, $efff
80084A40	and    v0, v0, v1
80084A44	sw     v0, $0000(s1)
80084A48	lh     v0, $0084(s5)
80084A4C	nop
80084A50	sll    v0, v0, $10
80084A54	sw     v0, $0024(s1)

L84a58:	; 80084A58
80084A58	lw     v0, $0020(s1)
80084A5C	nop
80084A60	sw     v0, $0000(s5)
80084A64	lw     v0, $0024(s1)
80084A68	nop
80084A6C	sw     v0, $0004(s5)
80084A70	lw     v0, $0028(s1)
80084A74	addu   a0, s6, zero
80084A78	sw     v0, $0008(s5)
80084A7C	sll    v0, a0, $01
80084A80	addu   v0, v0, a0
80084A84	sll    v0, v0, $03
80084A88	subu   v0, v0, a0
80084A8C	sll    v0, v0, $02
80084A90	lui    v1, $800b
80084A94	lw     v1, $efe4(v1)
80084A98	lh     a1, $0026(s1)
80084A9C	addu   v0, v0, v1
80084AA0	sw     a1, $0024(v0)

L84aa4:	; 80084AA4
80084AA4	jal    func81268 [$80081268]
80084AA8	nop
return 0;
////////////////////////////////



////////////////////////////////
// func7c9e8()
data_138 = A0;
block_id = A1;
pointer18 = A2;
pointer50 = A3;
pointer48 = A4;
pointer28 = A5;

triangle_id = h[data_138 + 8 + A1 * 2];
walkmesh_triangle_data = w[800aeff8 + A1 * 4];
walkmesh_material_data = w[800aeff4];

if( triangle_id == -1 )
{
    return -1;
}

walkmesh_vertex_data = w[800af008 + A1 * 4];

start_x = w[data_138 + 20];
start_z = w[data_138 + 28];
end_x = (start_x + w[data_138 + 30]) >> 10;
end_z = (start_z + w[data_138 + 38]) >> 10;
start_x_z = ((start_x >> 10) << 10) + (start_z >> 10);
ending_point_x_z = (end_x << 10) + end_z;

[SP + 18] = w(end_x);
[SP + 1a] = h(0);
[SP + 1c] = h(end_z);

[SP + 40] = w(0);
if( ( (w[data_138 + 4] >> (block_id + 3)) & 1 ) == 0 ) // ignore walkmeshes material flags. Set - ignore.
{
    [SP + 40] = w(0 - (bu[800b16a0] < 1));
}

triangle_check_count = 0;
L7caec:	; 8007CAEC
    V0 = h[walkmesh_triangle_data + triangle_id * e + 00];
    a_x_z = S4 = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

    V0 = h[walkmesh_triangle_data + triangle_id * e + 02];
    b_x_z = S3 = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

    V0 = h[walkmesh_triangle_data + triangle_id * e + 04];
    c_x_z = S2 = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

    A0 = a_x_z;
    A1 = b_x_z;
    A2 = ending_point_x_z;
    system_side_of_vector();
    if( V0 < 0 )
    {
        S0 = S0 | 1;
    }

    A0 = b_x_z;
    A1 = c_x_z;
    A2 = ending_point_x_z;
    system_side_of_vector();
    if( V0 < 0 )
    {
        S0 = S0 | 2;
    }

    A0 = c_x_z;
    A1 = a_x_z;
    A2 = ending_point_x_z;
    system_side_of_vector();
    if( V0 < 0 )
    {
        S0 = S0 | 4;
    }

    switch( S0 )
    {
        case 0: // we not cross anything
        {
            triangle_check_count = ff;
        }
        break;
        case 1:
        {
            triangle_id = h[walkmesh_triangle_data + triangle_id * e + 06];
        }
        case 2:
        {
            triangle_id = h[walkmesh_triangle_data + triangle_id * e + 08];
        }
        break;
        case 3:
        {
            A0 = b_x_z;
            A1 = ending_point_x_z;
            A2 = start_x_z;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 8];
            }
            else
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 6];
            }
        }
        break;
        case 4:
        {
            triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
        }
        break;
        case 5:
        {
            A0 = a_x_z;
            A1 = ending_point_x_z;
            A2 = start_x_z;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 6];
            }
            else
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
            }
        }
        break;
        case 6:
        {
            A0 = c_x_z;
            A1 = ending_point_x_z;
            A2 = start_x_z;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
            }
            else
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 8];
            }
        }
        break;
        case 7:
        {
            triangle_id = -1;
        }
        break;
    }

    if( triangle_id == -1 )
    {
        break;
    }

    triangle_check_count = triangle_check_count + 1;
    V0 = triangle_check_count < 20;
8007CC7C	bne    v0, zero, L7caec [$8007caec]

if( triangle_check_count == 20 )
{
    return -1;
}

A0 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 0] * 8;
A1 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 2] * 8;
A2 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 4] * 8;
A3 = SP + 18;
A4 = pointer50;
field_calculate_walkmesh_height();

[pointer48] = h(triangle_id);

material_id = bu[walkmesh_triangle_data + triangle_id * e + c];
if(  w[walkmesh_material_data + material_id * 4] & w[SP + 40] & 00800000 ) // if we cant pass this material
{
    [pointer18] = w(7fffffff);
    [pointer28] = w(7fffffff);
    return 0;
}

if( h[data_138 + 10] != block_id )
{
    V0 = h[SP + 1a]; // end y pos on triangle
}
else if( ( w[data_138 + 30] == 0 ) && ( w[data_138 + 34] == 0 ) && ( w[data_138 + 38] == 0 ) )
{
    V0 = h[SP + 1a]; // end y pos on triangle
}
else
{
    V0 = h[data_138 + 72];
}

A2 = b[walkmesh_triangle_data + triangle_id * e + d] * 4;
if( A2 < 0 )
{
    A2 = 0;
}

[pointer18] = w(V0);
[pointer28] = w(V0 + A2);
return 0;
////////////////////////////////



////////////////////////////////
// func7bc84()
V0 = w[A0];
if( A2 >= 0 )
{
    V0 = V0 + A2;
}
[A1] = w(V0);
////////////////////////////////



////////////////////////////////
// func827e4()
[A0 + 0] = h(h[A1 + 2]);
[A0 + 2] = h(h[A1 + 6]);
[A0 + 4] = h(h[A1 + a]);
////////////////////////////////



////////////////////////////////
// func7c374()
[800ad0e8] = w(w[800ad0e8] - A0);
////////////////////////////////



////////////////////////////////
// func7c350()
V0 = w[800ad0e8];
[800ad0e8] = w(V0 + A0);
return 1f800000 + V0 * 4;
////////////////////////////////



////////////////////////////////
// get_current_triangle_material()
walkmesh_id = h[A0 + 10];
if( ( ( w[A0 + 4] >> walkmesh_id + 3 ) & 1 ) == 0 )
{
    triangle_data = w[800aeff8 + walkmesh_id * 4];
    material_data = w[800aeff4];
    triangle_id = h[A0 + 8 + walkmesh_id * 2];
    V0 = bu[triangle_data + triangle_id * e + c];
    return w[material_data + V0 * 4];
}
return 0;
////////////////////////////////



////////////////////////////////
// func7ac28()
V0 = h[800b1660]; // base walking speed
res = A0;
rot = A2 & 0fff;

S0 = ((A1 << 4) * V0) >> c;

A0 = rot;
system_cos();
[res + 0] = w(V0 * S0);

A0 = rot;
system_sin();

[res + 4] = w(0);
[res + 8] = w(0 - V0 * S0);
////////////////////////////////



////////////////////////////////
// get_distance_between_entities()
entity_id1 = A0;
entity_id2 = A1;

struct_5c = w[800aefe4];
struct_138_1 = w[struct_5c + entity_id1 * 5c + 4c];
struct_138_2 = w[struct_5c + entity_id2 * 5c + 4c];

A0 = h[struct_138_2 + 22] - h[struct_138_1 + 22];
A1 = h[struct_138_2 + 2a] - h[struct_138_1 + 2a];
length_of_vector_by_x_y();
////////////////////////////////



////////////////////////////////////////////////////////
// length_of_vector_by_x_y()
[SP + 10] = w(A0);
[SP + 14] = w(A1);
[SP + 18] = w(0);

A0 = SP + 10;
A1 = SP + 20;
system_gte_square_of_vector;

V0 = w[SP + 20];
A0 = w[SP + 24];
A0 = V0 + A0;
system_square_root;

return V0;
////////////////////////////////////////////////////////



////////////////////////////////
// func83f40()
struct_138 = A0;

if( ( w[struct_138 + 14] & 00420000 ) == 0 && 
    w[800ad070] == 0 &&
    w[struct_138 + 30] == 0 && // X
    w[struct_138 + 34] == 0 && // Y
    w[struct_138 + 38] == 0 && // Z
    w[800ad0e4] == 1 &&
    bu[struct_138 + 74] == ff &&
    (w[struct_138 + 0] & 00401800) == 0 &&
    ((w[struct_138 + 4] & 00000001) == 0 || h[struct_138 + 10] != 0) &&
    ((w[struct_138 + 4] & 00000002) == 0 || h[struct_138 + 10] != 1))
{
    if ((w[struct_138 + 4] & 00000004) == 0)
    {
        return 0;
    }

    return (h[struct_138 + 10] ^ 0002) < 1; // -1 if bit 0x0002 set, 0 otherwise
}

return -1;
////////////////////////////////



////////////////////////////////
// func81594()
struct_164 = A0;
rotation = A1;
struct_5c = A2;

struct_138 = w[struct_5c + 4c];

if( rotation & 8000 )
{
    [struct_164 + c] = w(0);
    [struct_164 + 14] = w(0);
    return;
}

if( ( hu[struct_5c + 58] & 0040 ) == 0 ) // this is model
{
    S1 = ((40000 / hu[struct_138 + 76]) >> 8) << 5;

    A0 = rotation & 0fff;
    system_cos();
    [struct_164 + c] = w(((V0 * S1) >> c) * h[struct_138 + f4]);
    [struct_164 + c] = w(w[struct_164 + c] & fffff000);

    A0 = rotation & 0fff;
    system_sin();
    [struct_164 + 14] = w(((0 - (V0 * S1)) >> c) * h[struct_138 + f8]);
    [struct_164 + 14] = w(w[struct_164 + 14] & fffff000);
}
else if( ( w[struct_138 + 4] & 00002000 ) == 0 )
{
    if( ( w[struct_138 + 4] & 00080000 ) == 0 )
    {
        A0 = struct_164;
        A1 = rotation;
        func21e40();

        [struct_164 + c] = w(w[struct_164 + c] & fffff000);
        [struct_164 + 14] = w(w[struct_164 + 14] & fffff000);
    }
    else
    {
        S1 = ((40000 / hu[struct_138 + 76]) >> 8) << 5;

        A0 = rotation & 0fff;
        system_cos();
        [struct_164 + c] = w(((V0 * S1) >> c) * h[struct_138 + f4]);
        [struct_164 + c] = w(w[struct_164 + c] & fffff000);

        A0 = rotation & 0fff;
        system_sin();
        [struct_164 + 14] = w(((0 - (V0 * S1)) >> c) * h[struct_138 + f8]);
        [struct_164 + 14] = w(w[struct_164 + 14] & fffff000);

        [struct_164 + 18] = w(4000000 / hu[struct_138 + 76]);
    }
}
else if( ( w[struct_138 + 4] & 00020000 ) == 0 )
{
    S1 = ((80000 / hu[struct_138 + 76]) >> 8) << 5;

    A0 = rotation & 0fff;
    system_cos();
    [struct_164 + c] = w(((V0 * S1) >> c) * h[struct_138 + f4]);
    [struct_164 + c] = w(w[struct_164 + c] & fffff000);

    A0 = rotation & 0fff;
    system_sin();
    [struct_164 + 14] = w(((0 - (V0 * S1)) >> c) * h[struct_138 + f8]);
    [struct_164 + 14] = w(w[struct_164 + 14] & fffff000);
}
else
{
    V0 = w[801e8670 + ((w[struct_138 + 12c] >> b) & 1c)]; // 0x0000e000 flags
    [struct_164 + c] = w((0 - w[V0 + 128]) << 10);
    [struct_164 + c] = w(w[struct_164 + c] & fffff000);
    [struct_164 + 14] = w((0 - w[V0 + 130]) << 10);
    [struct_164 + 14] = w(w[struct_164 + 14] & fffff000);
}
////////////////////////////////



////////////////////////////////
// func81aa8()
move_vector = A0;
struct_138 = A1;

if( ( w[struct_138 + 12c] & 00001000 ) == 0 )
{
    return 0;
}

new_point = (((w[struct_138 + 20] + w[move_vector + 0]) >> 10) << 10) + ((w[struct_138 + 28] + w[move_vector + 8]) >> 10);

V1 = w[struct_138 + 114];
p1 = (h[V1 + 0] << 10) + h[V1 + 2];
p2 = (h[V1 + 4] << 10) + h[V1 + 6];
p3 = (h[V1 + 8] << 10) + h[V1 + a];
p4 = (h[V1 + c] << 10) + h[V1 + e];

A0 = p1;
A1 = p2;
A2 = new_point;
system_side_of_vector();
if( V0 >= 0 )
{
    A0 = p2;
    A1 = p3;
    A2 = new_point;
    system_side_of_vector();
    if( V0 >= 0 )
    {
        A0 = p3;
        A1 = p4;
        A2 = new_point;
        system_side_of_vector();
        if( V0 >= 0 )
        {
            A0 = p4;
            A1 = p1;
            A2 = new_point;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                return 0;
            }
        }
    }
}
return -1;
////////////////////////////////



////////////////////////////////
// field_check_walkmesh_triangle_and_calculate_height()
// return -1 if we can't move, 0 otherwise.
move_vector = A0;
current_pos = A1;
struct_138 = A2;
intersect_line = A3;
final_pos = A4;
flag = A5; // if -1 then we don't need to really calculate height of final point. If 00000080 then we can go only down. Simulate material 00400000.
material_ret = A6;

walkmesh_id = h[struct_138 + 10];
triangle_id = h[struct_138 + 08 + walkmesh_id * 2];

walkmesh_vertex_data = w[800af008 + walkmesh_id * 4];
walkmesh_triangle_data = w[800aeff8 + walkmesh_id * 4];
walkmesh_material_data = w[800aeff4];

if( triangle_id == -1 )
{
    return -1;
}

start_x = w[current_pos + 0];
start_y = w[current_pos + 4];
start_z = w[current_pos + 8];
end_x = (start_x + w[move_vector + 0]) >> 10;
end_z = (start_z + w[move_vector + 8]) >> 10;
start_x_z = ((start_x >> 10) << 10) + (start_z >> 10);
ending_point_x_z = (end_x << 10) + end_z;

[final_pos + 0] = h(end_x);
[final_pos + 2] = h(0);
[final_pos + 4] = h(end_z);

if( ( ( w[struct_138 + 4] >> ( walkmesh_id + 3 ) ) & 1 ) == 0 && bu[800b16a0] == 0 )
{
    material_mask = ffffffff;
}
else
{
    material_mask = 00000000;
}

material_id = bu[walkmesh_triangle_data + triangle_id * e + c];
material = w[walkmesh_material_data + material_id * 4];

if( ( material & material_mask & 00400000 ) || ( flag == 00000080 ) )
{
    material_go_only_down = 1;
}
else
{
    material_go_only_down = 0;
}



triangle_check_count = 0;
L7b68c:	; 8007B68C
    current_triangle_id = triangle_id;
    S2 = 0;

    V0 = h[walkmesh_triangle_data + triangle_id * e + 00];
    a_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

    V0 = h[walkmesh_triangle_data + triangle_id * e + 02];
    b_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

    V0 = h[walkmesh_triangle_data + triangle_id * e + 04];
    c_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

    A0 = a_x_z;
    A1 = b_x_z;
    A2 = ending_point_x_z;
    system_side_of_vector();
    if( V0 < 0 )
    {
        S2 = S2 | 1;
    }

    A0 = b_x_z;
    A1 = c_x_z;
    A2 = ending_point_x_z;
    system_side_of_vector();
    if( V0 < 0 )
    {
        S2 = S2 | 2;
    }

    A0 = c_x_z;
    A1 = a_x_z;
    A2 = ending_point_x_z;
    system_side_of_vector();
    if( V0 < 0 )
    {
        S2 = S2 | 4;
    }

    switch( S2 )
    {
        case 0: // we not cross anything
        {
            triangle_check_count = ff;
        }
        break;
        case 1:
        {
            triangle_id = h[walkmesh_triangle_data + triangle_id * e + 06];
        }
        case 2:
        {
            triangle_id = h[walkmesh_triangle_data + triangle_id * e + 08];
        }
        break;
        case 3:
        {
            A0 = b_x_z;
            A1 = ending_point_x_z;
            A2 = start_x_z;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 8];
                S2 = 2;
            }
            else
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 6];
                S2 = 1;
            }
        }
        break;
        case 4:
        {
            triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
        }
        break;
        case 5:
        {
            A0 = a_x_z;
            A1 = ending_point_x_z;
            A2 = start_x_z;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 6];
                S2 = 1;
            }
            else
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
                S2 = 4;
            }
        }
        break;
        case 6:
        {
            A0 = c_x_z;
            A1 = ending_point_x_z;
            A2 = start_x_z;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
                S2 = 4;
            }
            else
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 8];
                S2 = 2;
            }
        }
        break;
        case 7:
        {
            triangle_id = -1;
        }
        break;
    }

    if( triangle_id == -1 )
    {
        break;
    }

    material_id = bu[walkmesh_triangle_data + triangle_id * e + c];
    material = w[walkmesh_material_data + material_id * 4];

    [material_ret] = w(material & material_mask);
    type_of_unpassability = (w[material_ret] >> 5)

    type_of_entity = ((w[struct_138 + 0] & 00000700) >> 8);

    if( ( type_of_entity & type_of_unpassability ) || ( ( w[material_ret] & 10000000 ) && ( walkmesh_id == 0 ) ) )
    {
        triangle_id = -1;
    }
    else if( ( w[material_ret] & 00400000 ) && material_go_only_down == 0 ) // we check both triangles start and end.
    {
        A0 = h[walkmesh_triangle_data + triangle_id * e + 0];
        A1 = h[walkmesh_triangle_data + triangle_id * e + 2];
        A2 = h[walkmesh_triangle_data + triangle_id * e + 4];

        A0 = walkmesh_vertex_data + A0 * 8;
        A1 = walkmesh_vertex_data + A1 * 8;
        A2 = walkmesh_vertex_data + A2 * 8;
        A3 = final_pos;
        A4 = SP + 18; // address to store normal
        field_calculate_walkmesh_height();

        new_y = h[final_pos + 2];

        if( new_y < ( start_y >> 10 ) ) // Y is less on top
        {
            triangle_id = -1;
        }
    }

    if( triangle_id == -1 )
    {
        break;
    }

    triangle_check_count = triangle_check_count + 1;
    V0 = triangle_check_count < 20;
8007B970	bne    v0, zero, L7b68c [$8007b68c]



if( ( triangle_id != -1 ) && ( triangle_check_count != 20 ) )
{
    if( flag != -1 )
    {
        A0 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 0] * 8;
        A1 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 2] * 8;
        A2 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 4] * 8;
        A3 = final_pos;
        A4 = SP + 18; // address to store normal
        field_calculate_walkmesh_height();
    }
    return 0;
}



if( S2 == 1 )
{
    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 0];
    [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 2];
    [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
}
else if( S2 == 2 )
{
    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 2];
    [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 4];
    [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
}
else if( S2 == 4 )
{
    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 4];
    [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 0];
    [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
}

return -1;
////////////////////////////////



////////////////////////////////
// field_calculate_walkmesh_height()
A_vec = A0;
B_vec = A1;
C_vec = A2;
P_vec = A3;
S4 = A4; // address for normal

[SP + 30] = w(h[B_vec + 0] - h[A_vec + 0]);
[SP + 34] = w(h[B_vec + 2] - h[A_vec + 2]);
[SP + 38] = w(h[B_vec + 4] - h[A_vec + 4]);
A0 = SP + 30;
A1 = SP + 10;
system_normalize_word_vector_T0_T1_T2_to_word();

[SP + 30] = w(h[C_vec + 0] - h[A_vec + 0]);
[SP + 34] = w(h[C_vec + 2] - h[A_vec + 2]);
[SP + 38] = w(h[C_vec + 4] - h[A_vec + 4]);
A0 = SP + 30;
A1 = SP + 20;
system_normalize_word_vector_T0_T1_T2_to_word();

A0 = SP + 10;
A1 = SP + 20;
A2 = S4; // normal
system_outer_product2_A0_A1_to_A2();

if (w[S4 + 4] == 0)
{
    [P_vec + 2] = h(0);
}
else
{
    [P_vec + 2] = h(hu[A_vec + 2] - (w[S4 + 0] * (h[P_vec + 0] - h[A_vec + 0]) + w[S4 + 8] * (h[P_vec + 4] - h[A_vec + 4])) / w[S4 + 4]);
}
////////////////////////////////



////////////////////////////////
// field_get_move_vector_to_move_along_with_line()
rotation = A0;
intersect_line = A1;
move_vector = A2;

S1 = (c00 - rotation) & fff;

A0 = h[intersect_line + c] - h[intersect_line + 4];
A1 = h[intersect_line + 8] - h[intersect_line + 0];
system_get_rotation_based_on_vector_x_y();

A0 = (0 - V0) & fff; // rotation along line that we can't intersect 
S1 = (S1 + A0) & fff;

if( ( S1 - 80 ) >= f01)
{
    [move_vector + 0] = w(0);
    [move_vector + 4] = w(0);
    [move_vector + 8] = w(0);
    return A0;
}
else
{
    if( S1 < 800 )
    {
        [SP + 10] = w(h[intersect_line + 0] - h[intersect_line + 8]);
        [SP + 14] = w(0);
        [SP + 18] = w(h[intersect_line + 4] - h[intersect_line + c]);
        A0 = A0 + 800;
    }
    else
    {
        [SP + 10] = w(h[intersect_line + 8] - h[intersect_line + 0]);
        [SP + 14] = w(0);
        [SP + 18] = w(h[intersect_line + c] - h[intersect_line + 4]);
    }

    S3 = A0 & fff;

    A0 = SP + 10;
    A1 = SP + 20;
    system_normalize_word_vector_T0_T1_T2_to_word();

    A0 = w[move_vector + 0] >> c;
    A1 = w[move_vector + 8] >> c;
    length_of_vector_by_x_y();

    [move_vector + 0] = w(w[SP + 20] * V0);
    [move_vector + 4] = w(0);
    [move_vector + 8] = w(w[SP + 28] * V0);

    return S3;
}
////////////////////////////////



////////////////////////////////
// func7bca8()
// return -1 if we can't move, 0 otherwise.
move_vector = A0;
current_pos = A1;
struct_138 = A2;
intersect_line = A3;
final_pos = A4;
flag = A5; // if -1 then we don't need to really calculate height of final point. If 00000080 then we can go only down. Simulate material 00400000.
material_ret = A6;

walkmesh_id = h[struct_138 + 10];
triangle_id = h[struct_138 + 08 + walkmesh_id * 2];

walkmesh_vertex_data = w[800af008 + walkmesh_id * 4];
walkmesh_triangle_data = w[800aeff8 + walkmesh_id * 4];
walkmesh_material_data = w[800aeff4];

if( triangle_id == -1 )
{
    return -1;
}

start_x = w[current_pos + 0];
start_z = w[current_pos + 8];
end_x = (start_x + w[move_vector + 0]) >> 10;
end_z = (start_z + w[move_vector + 8]) >> 10;
start_x_z = ((start_x >> 10) << 10) + (start_z >> 10);
ending_point_x_z = (end_x << 10) + end_z;

[final_pos + 0] = h(end_x);
[final_pos + 2] = h(0);
[final_pos + 4] = h(end_z);

if( ( ( w[struct_138 + 4] >> ( walkmesh_id + 3 ) ) & 1 ) == 0 && bu[800b16a0] == 0 )
{
    material_mask = ffffffff;
}
else
{
    material_mask = 00000000;
}

triangle_check_count = 0;
L7bdc8:	; 8007BDC8
    current_triangle_id = triangle_id;
    S1 = 0;

    V0 = h[walkmesh_triangle_data + triangle_id * e + 00];
    a_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

    V0 = h[walkmesh_triangle_data + triangle_id * e + 02];
    b_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

    V0 = h[walkmesh_triangle_data + triangle_id * e + 04];
    c_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

    A0 = a_x_z;
    A1 = b_x_z;
    A2 = ending_point_x_z;
    system_side_of_vector();
    if( V0 < 0 )
    {
        S1 = S1 | 1;
    }

    A0 = b_x_z;
    A1 = c_x_z;
    A2 = ending_point_x_z;
    system_side_of_vector();
    if( V0 < 0 )
    {
        S1 = S1 | 2;
    }

    A0 = c_x_z;
    A1 = a_x_z;
    A2 = ending_point_x_z;
    system_side_of_vector();
    if( V0 < 0 )
    {
        S1 = S1 | 4;
    }

    switch( S1 )
    {
        case 0: // we not cross anything
        {
            triangle_check_count = ff;
        }
        break;
        case 1:
        {
            triangle_id = h[walkmesh_triangle_data + triangle_id * e + 06];
        }
        case 2:
        {
            triangle_id = h[walkmesh_triangle_data + triangle_id * e + 08];
        }
        break;
        case 3:
        {
            A0 = b_x_z;
            A1 = ending_point_x_z;
            A2 = start_x_z;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 8];
                S1 = 2;
            }
            else
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 6];
                S1 = 1;
            }
        }
        break;
        case 4:
        {
            triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
        }
        break;
        case 5:
        {
            A0 = a_x_z;
            A1 = ending_point_x_z;
            A2 = start_x_z;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 6];
                S1 = 1;
            }
            else
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
                S1= 4;
            }
        }
        break;
        case 6:
        {
            A0 = c_x_z;
            A1 = ending_point_x_z;
            A2 = start_x_z;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
                S1 = 4;
            }
            else
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 8];
                S1 = 2;
            }
        }
        break;
        case 7:
        {
            triangle_id = -1;
        }
        break;
    }

    material_id = bu[walkmesh_triangle_data + triangle_id * e + c];
    material = w[walkmesh_material_data + material_id * 4];

    A0 = material & material_mask;

    if( ((w[struct_138 + 0] >> 9) & 3) & (A0 >> 3) )
    {
        triangle_id = -1;
        break;
    }

    if( ((w[struct_138 + 0] >> 8) & 7) & (A0 >> 5) )
    {
        triangle_id = -1;
        break;
    }

    if( ( A0 & 00800000 ) && ( h[struct_138 + 10] == 0 ) )
    {
        triangle_id = -1;
        break;
    }

    if( triangle_id == -1 )
    {
        break;
    }

    triangle_check_count = triangle_check_count + 1;

    V0 = triangle_check_count < 20;
8007C03C	bne    v0, zero, L7bdc8 [$8007bdc8]



L7c044:	; 8007C044
if( ( triangle_id != -1 ) && ( triangle_check_count != 20 ) )
{
    if( flag != -1 )
    {
        A0 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 0] * 8;
        A1 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 2] * 8;
        A2 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 4] * 8;
        A3 = final_pos;
        A4 = SP + 18; // address to store normal
        field_calculate_walkmesh_height();
    }
    return 0;
}



if( S1 == 1 )
{
    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 0];
    [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 2];
    [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
}
else if( S1 == 2 )
{
    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 2];
    [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 4];
    [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
}
else if( S1 == 4 )
{
    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 4];
    [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 0];
    [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
}
return -1;
////////////////////////////////



////////////////////////////////
// func81808()
struct_164 = A0;
animation_id = A1;
struct_5c = A2;

struct_138 = w[struct_5c + 4c];

if( ( hu[struct_5c + 58] & 0040 ) == 0 )
{
    return;
}

if( ( animation_id != 3 ) && ( h[800b1818] == 0 ) )
{
    [struct_138 + 0] = w(w[struct_138 + 0] & fffff7ff); // remove 0x00000800
}

if( animation_id == ff )
{
    animation_id = 0;
}

if( animation_id != h[800b181a] )
{
    [struct_138 + 0] = w(w[struct_138 + 0] & fffff7ff);
}

if( ( w[struct_138 + 4] & 00002000 ) == 0 )
{
    if( ( w[struct_138 + 4] & 00000100 ) == 0 )
    {
        A0 = struct_164;
        A1 = animation_id;
        func243e4(); // sprite animation
    }
    return;
}

model_id = (w[struct_138 + 12c] >> d) & 7

if( animation_id < 10 )
{
    A0 = model_id;
    A1 = 0;
    A2 = bu[800ad490 + animation_id];
    func1e8330(); // model animation

    [800b16b8 + model_id * 2] = h(bu[800ad490 + animation_id]);
}
else
{
    animation_id = animation_id - 10;
    A0 = model_id;
    A1 = 0;
    A2 = animation_id;
    func1e8330(); // model animation

    [800b16b8 + model_id * 2] = h(animation_id);
}
////////////////////////////////
