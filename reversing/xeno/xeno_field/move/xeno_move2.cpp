////////////////////////////////
// func84054
80084054	addiu  sp, sp, $ff00 (=-$100)
80084058	sw     s6, $00f0(sp)
8008405C	addu   s6, a0, zero
80084060	sw     s7, $00f4(sp)
80084064	addu   s7, a1, zero
80084068	sw     s1, $00dc(sp)
8008406C	sll    v0, s6, $01
80084070	addu   v0, v0, s6
80084074	sll    v0, v0, $03
80084078	subu   v0, v0, s6
8008407C	lui    v1, $800b
80084080	lw     v1, $efe4(v1)
80084084	lui    a1, $800b
80084088	lw     a1, $1740(a1)
8008408C	sll    v0, v0, $02
80084090	sw     ra, $00fc(sp)
80084094	sw     fp, $00f8(sp)
80084098	sw     s5, $00ec(sp)
8008409C	sw     s4, $00e8(sp)
800840A0	sw     s3, $00e4(sp)
800840A4	sw     s2, $00e0(sp)
800840A8	sw     s0, $00d8(sp)
800840AC	addu   v0, v0, v1
800840B0	lw     s5, $0004(v0)
800840B4	bne    s6, a1, L840c8 [$800840c8]
800840B8	addu   s1, a3, zero
800840BC	ori    v0, zero, $ffff
800840C0	lui    at, $800b
800840C4	sh     v0, $cfd8(at)

L840c8:	; 800840C8
800840C8	lw     a0, $0000(s1)
800840CC	lui    v0, $0100
800840D0	and    v0, a0, v0
800840D4	bne    v0, zero, L84ab0 [$80084ab0]
800840D8	addiu  v0, zero, $ffff (=-$1)
800840DC	lw     v0, $0004(s1)
800840E0	lui    v1, $0020
800840E4	and    v0, v0, v1
800840E8	bne    v0, zero, L84ab0 [$80084ab0]
800840EC	addiu  v0, zero, $ffff (=-$1)
800840F0	lui    v0, $0001
800840F4	and    v0, a0, v0
800840F8	bne    v0, zero, L84150 [$80084150]
800840FC	nop
80084100	bne    s6, a1, L8411c [$8008411c]
80084104	ori    v0, zero, $0001
80084108	lui    v1, $800b
8008410C	lbu    v1, $16a3(v1)
80084110	nop
80084114	beq    v1, v0, L84158 [$80084158]
80084118	nop

L8411c:	; 8008411C
8008411C	lw     v0, $0010(s5)
80084120	nop
80084124	bne    v0, zero, L84158 [$80084158]
80084128	nop
A0 = S1;
func83f40;

80084134	bne    v0, zero, L84158 [$80084158]
80084138	nop
8008413C	lh     v1, $0084(s5)
80084140	lh     v0, $0026(s1)
80084144	nop
80084148	bne    v1, v0, L84158 [$80084158]
8008414C	nop

L84150:	; 80084150
80084150	j      L84ab0 [$80084ab0]
80084154	addiu  v0, zero, $ffff (=-$1)

L84158:	; 80084158
80084158	lw     v0, $0020(s1)
8008415C	addu   s0, zero, zero
80084160	sw     v0, $0090(sp)
80084164	lw     v0, $0024(s1)
80084168	addu   a0, s1, zero
8008416C	sw     v0, $0094(sp)
80084170	lw     v0, $0028(s1)
80084174	addiu  v1, sp, $0018
80084178	sw     v0, $0098(sp)
8008417C	lhu    fp, $0010(s1)

loop84180:	; 80084180
80084180	lhu    v0, $0008(a0)
80084184	addiu  a0, a0, $0002
80084188	addiu  s0, s0, $0001
8008418C	sh     v0, $0088(v1)
80084190	slti   v0, s0, $0004
80084194	bne    v0, zero, loop84180 [$80084180]
80084198	addiu  v1, v1, $0002
8008419C	addu   s0, zero, zero
800841A0	lui    a0, $7fff
800841A4	ori    a0, a0, $ffff
800841A8	addiu  v1, sp, $0018

loop841ac:	; 800841AC
800841AC	sw     s0, $0020(v1)
800841B0	sw     a0, $0000(v1)
800841B4	sw     a0, $0010(v1)
800841B8	addiu  s0, s0, $0001
800841BC	slti   v0, s0, $0004
800841C0	bne    v0, zero, loop841ac [$800841ac]
800841C4	addiu  v1, v1, $0004
800841C8	lui    v0, $800b
800841CC	lh     v0, $f028(v0)
800841D0	nop
800841D4	addiu  v0, v0, $ffff (=-$1)
800841D8	blez   v0, L84240 [$80084240]
800841DC	addu   s4, zero, zero
800841E0	addiu  s3, sp, $0048
800841E4	addiu  s2, sp, $0050
800841E8	addiu  s0, sp, $0018

loop841ec:	; 800841EC
800841EC	addu   a0, s1, zero
800841F0	addu   a1, s4, zero
800841F4	sll    v1, s4, $02
800841F8	addiu  v0, sp, $0028
800841FC	addu   v0, v0, v1
80084200	addu   a2, s0, zero
80084204	addu   a3, s2, zero
80084208	sw     s3, $0010(sp)
8008420C	jal    func7c9e8 [$8007c9e8]
80084210	sw     v0, $0014(sp)
80084214	bne    v0, zero, L84240 [$80084240]
80084218	nop
8008421C	addiu  s3, s3, $0002
80084220	addiu  s2, s2, $0010
80084224	lui    v0, $800b
80084228	lh     v0, $f028(v0)
8008422C	addiu  s4, s4, $0001
80084230	addiu  v0, v0, $ffff (=-$1)
80084234	slt    v0, s4, v0
80084238	bne    v0, zero, loop841ec [$800841ec]
8008423C	addiu  s0, s0, $0004

L84240:	; 80084240
80084240	lw     v0, $0004(s1)
80084244	nop
80084248	andi   v0, v0, $0001
8008424C	beq    v0, zero, L84260 [$80084260]
80084250	lui    v0, $7fff
80084254	ori    v0, v0, $ffff
80084258	sw     v0, $0018(sp)
8008425C	sw     v0, $0028(sp)

L84260:	; 80084260
80084260	lw     v0, $0004(s1)
80084264	nop
80084268	andi   v0, v0, $0002
8008426C	beq    v0, zero, L84280 [$80084280]
80084270	lui    v0, $7fff
80084274	ori    v0, v0, $ffff
80084278	sw     v0, $001c(sp)
8008427C	sw     v0, $002c(sp)

L84280:	; 80084280
80084280	lw     v0, $0004(s1)
80084284	nop
80084288	andi   v0, v0, $0004
8008428C	beq    v0, zero, L842a0 [$800842a0]
80084290	lui    v0, $7fff
80084294	ori    v0, v0, $ffff
80084298	sw     v0, $0020(sp)
8008429C	sw     v0, $0030(sp)

L842a0:	; 800842A0
800842A0	addu   s0, zero, zero
800842A4	addiu  v0, sp, $0018
800842A8	addu   t1, v0, zero
800842AC	addiu  t3, sp, $002c
800842B0	lh     v0, $0010(s1)
800842B4	addiu  t2, sp, $003c
800842B8	sll    v0, v0, $02
800842BC	addu   v0, v0, t1
800842C0	lw     t4, $0000(v0)

loop842c4:	; 800842C4
800842C4	addu   t0, zero, zero
800842C8	addu   a3, t2, zero
800842CC	addu   a2, t3, zero
800842D0	addu   v1, t1, zero

loop842d4:	; 800842D4
800842D4	lw     a0, $0000(v1)
800842D8	lw     a1, $0004(v1)
800842DC	nop
800842E0	slt    v0, a1, a0
800842E4	beq    v0, zero, L84314 [$80084314]
800842E8	nop
800842EC	lw     v0, $0010(v1)
800842F0	sw     a0, $0004(v1)
800842F4	sw     a1, $0000(v1)
800842F8	lw     a0, $0000(a2)
800842FC	sw     v0, $0000(a2)
80084300	lw     v0, $0020(v1)
80084304	sw     a0, $0010(v1)
80084308	lw     a0, $0000(a3)
8008430C	sw     v0, $0000(a3)
80084310	sw     a0, $0020(v1)

L84314:	; 80084314
A3 = A3 + 4;
A2 = A2 + 4;
T0 = T0 + 1;
V0 = T0 < 2;
80084324	bne    v0, zero, loop842d4 [$800842d4]
80084328	addiu  v1, v1, $0004
8008432C	addiu  s0, s0, $0001
80084330	slti   v0, s0, $0002
80084334	bne    v0, zero, loop842c4 [$800842c4]
80084338	nop

A1 = 800af028;
V0 = h[A1];
V0 = V0 - 1;

80084350	bne    s4, v0, L845e0 [$800845e0]
80084354	nop
if (S4 > 0)
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
8008444C	slt    v0, s0, a0
80084450	bne    v0, zero, loop84438 [$80084438]
80084454	addiu  v1, v1, $0004

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
800844A4	jal    get_current_triangle_material [$8007ff7c]
800844A8	addu   a0, s1, zero
800844AC	lw     v1, $0000(s1)
800844B0	addu   a1, v0, zero
800844B4	srl    v0, a1, $05
800844B8	srl    v1, v1, $08
800844BC	andi   v1, v1, $0007
800844C0	and    v1, v1, v0
800844C4	beq    v1, zero, L844f0 [$800844f0]
800844C8	lui    v0, $0080
// DEBUG TEXT
800844CC	lui    v0, $800c
800844D0	lw     v0, $1b60(v0)
800844D4	nop
800844D8	bne    v0, zero, L84520 [$80084520]
800844DC	nop
A0 = 8006f2f0; // ERROR ID1 ACT=%d
800844E8	j      L84518 [$80084518]
800844EC	nop

L844f0:	; 800844F0
800844F0	and    v0, a1, v0
800844F4	beq    v0, zero, L84560 [$80084560]
800844F8	nop
800844FC	lui    v0, $800c
80084500	lw     v0, $1b60(v0)
80084504	nop
80084508	bne    v0, zero, L84520 [$80084520]
8008450C	nop
A0 = 8006f304; // ERROR ID0 ACT=%d

L84518:	; 80084518
A1 = S6;
80084518	jal    func37870 [$80037870]

L84520:	; 80084520
80084520	lui    v0, $800b
80084524	lw     v0, $1740(v0)
80084528	nop
8008452C	bne    s6, v0, L8453c [$8008453c]
80084530	ori    v0, zero, $0fff
80084534	lui    at, $800b
80084538	sh     v0, $cfd8(at)

L8453c:	; 8008453C
8008453C	lw     v0, $0024(s1)
80084540	lw     v1, $0010(s5)
80084544	nop
80084548	addu   v0, v0, v1
8008454C	j      L849ac [$800849ac]
80084550	sw     v0, $0024(s1)

loop84554:	; 80084554
80084554	lw     v0, $0000(v1)
80084558	j      L845c0 [$800845c0]
8008455C	sh     v0, $0084(s5)

L84560:	; 80084560
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
800845A8	nop
800845AC	beq    a1, v0, loop84554 [$80084554]
800845B0	addiu  s0, s0, $0001
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
80084AAC	addu   v0, zero, zero

L84ab0:	; 80084AB0
80084AB0	lw     ra, $00fc(sp)
80084AB4	lw     fp, $00f8(sp)
80084AB8	lw     s7, $00f4(sp)
80084ABC	lw     s6, $00f0(sp)
80084AC0	lw     s5, $00ec(sp)
80084AC4	lw     s4, $00e8(sp)
80084AC8	lw     s3, $00e4(sp)
80084ACC	lw     s2, $00e0(sp)
80084AD0	lw     s1, $00dc(sp)
80084AD4	lw     s0, $00d8(sp)
80084AD8	addiu  sp, sp, $0100
80084ADC	jr     ra 
80084AE0	nop
////////////////////////////////



////////////////////////////////
// func82fb0
// seems like this function run scripts based on entity conditions
FP = A2;
S7 = 0;
script_priority = 7;
80082FE8	sw     a0, $0050(sp)
80082FEC	sw     a1, $0058(sp)

[SP + 60] = w(hu[FP + 1e] + 8);
[SP + 68] = w(hu[FP + 1e] + 20);
[SP + 70] = w(h[FP + 26]); // Y
[SP + 78] = w(h[FP + 26] - hu[FP + 1a]);


S6 = h[FP + 22]; // X
V0 = w[800ad0d4]; // number of entity
S5 = h[FP + 2a]; // Z

if (V0 >= 0)
{
    return;
}

S3 = 0;
[SP + 90] = w(SP + 10);
[SP + 80] = w(hu[FP + 106] & fff);
[SP + 88] = w(SP + 20);

L83054:	; 80083054
    script_to_call = ff;

    V1 = w[800aefe4];
    S1 = w[V1 + S3 * 5c + 4c];
    A1 = w[S1 + 0];

    if (((A1 & 1) == 0) || (bu[FP + 74] == S3))
    {
        V1 = h[S1 + 26];
        V0 = h[S1 + 62];
        A0 = w[S1 + 4];
        S0 = V1 + V0;
        V0 = A0 & 0180;

        800830B0	beq    v0, zero, L83214 [$80083214]
        800830B4	andi   v0, a0, $0100
        800830B8	beq    v0, zero, L8320c [$8008320c]
        800830BC	nop
        V0 = hu[800c1b68] & 0020; // if we want to talk

        800830D0	beq    v0, zero, L83164 [$80083164]
        800830D4	nop
        800830D8	bne    s7, zero, L83164 [$80083164]
        800830DC	lui    v0, $0400
        800830E0	and    v0, a0, v0
        800830E4	bne    v0, zero, L83164 [$80083164]
        800830E8	lui    v0, $0022
        800830EC	and    v0, a1, v0
        800830F0	bne    v0, zero, L83214 [$80083214]
        800830F4	nop
        800830F8	lui    v0, $800b
        800830FC	lh     v0, $1648(v0)
        80083100	nop
        80083104	bne    v0, zero, L83214 [$80083214]
        80083108	nop
        8008310C	ori    s7, zero, $0001
        script_to_call = 2;
        script_priority = 3;
        80083118	lh     a1, $0022(s1)
        8008311C	lh     v0, $0060(s1)
        80083120	subu   a1, a1, s6
        80083124	addu   a1, a1, v0
        80083128	sw     a1, $0010(sp)
        8008312C	lh     a0, $002a(s1)
        80083130	lh     v0, $0064(s1)
        80083134	subu   a0, a0, s5
        80083138	addu   a0, a0, v0
        8008313C	jal    system_get_rotation_based_on_vector_x_y [$8004b1d4]
        80083140	sw     a0, $0018(sp)
        80083144	subu   a0, zero, v0
        80083148	addiu  t0, zero, $f1ff (=-$e01)
        8008314C	lw     v1, $012c(s1)
        80083150	andi   v0, a0, $0e00
        80083154	and    v1, v1, t0
        80083158	or     v1, v1, v0
        8008315C	j      L83214 [$80083214]
        80083160	sw     v1, $012c(s1)

        L83164:	; 80083164
        80083164	lw     v0, $0000(s1)
        80083168	lui    v1, $00a2
        8008316C	and    v0, v0, v1
        80083170	bne    v0, zero, L83214 [$80083214]
        80083174	nop
        script_to_call = 3;
        script_priority = 4;
        80083180	lh     a1, $0022(s1)
        80083184	lh     v0, $0060(s1)
        80083188	subu   a1, a1, s6
        8008318C	addu   a1, a1, v0
        80083190	sw     a1, $0010(sp)
        80083194	lh     a0, $002a(s1)
        80083198	lh     v0, $0064(s1)
        8008319C	subu   a0, a0, s5
        800831A0	addu   a0, a0, v0
        800831A4	jal    system_get_rotation_based_on_vector_x_y [$8004b1d4]
        800831A8	sw     a0, $0018(sp)
        800831AC	sra    v0, v0, $09
        800831B0	subu   v0, zero, v0
        800831B4	andi   a1, v0, $0007
        800831B8	addiu  t0, zero, $f1ff (=-$e01)
        800831BC	sll    v0, a1, $09
        800831C0	lw     v1, $012c(s1)
        800831C4	lui    a0, $800b
        800831C8	lw     a0, $d43c(a0)
        800831CC	and    v1, v1, t0
        800831D0	or     v1, v1, v0
        800831D4	bne    a0, zero, L83214 [$80083214]
        800831D8	sw     v1, $012c(s1)
        800831DC	lw     v0, $0000(s1)
        800831E0	lui    v1, $0800
        800831E4	and    v0, v0, v1
        800831E8	beq    v0, zero, L83214 [$80083214]
        800831EC	ori    v0, zero, $0001
        800831F0	lw     t0, $0058(sp)
        800831F4	nop
        800831F8	lw     v1, $0004(t0)
        800831FC	lui    at, $800b
        80083200	sw     v0, $d43c(at)
        80083204	j      L83214 [$80083214]
        80083208	sw     zero, $0010(v1)

        L8320c:	; 8008320C
        [800ad43c] = w(0);

        L83214:	; 80083214
        80083214	lw     v0, $0000(s1)
        80083218	nop
        8008321C	andi   v0, v0, $2000
        80083220	beq    v0, zero, L8340c [$8008340c]
        80083224	nop
        80083228	lw     t0, $0078(sp)
        8008322C	nop
        80083230	slt    v0, s0, t0
        80083234	bne    v0, zero, L836a4 [$800836a4]
        80083238	ori    v0, zero, $00ff
        8008323C	lhu    v0, $001a(s1)
        80083240	lw     t0, $0070(sp)
        80083244	subu   v0, s0, v0
        80083248	slt    v0, t0, v0
        8008324C	bne    v0, zero, L836a0 [$800836a0]
        80083250	nop
        80083254	lw     t0, $0050(sp)
        80083258	nop
        8008325C	beq    s3, t0, L836a0 [$800836a0]
        80083260	addu   a0, s6, zero
        80083264	addu   a1, s5, zero
        80083268	addu   a2, s1, zero
        8008326C	jal    func81990 [$80081990]
        80083270	ori    a3, zero, $0010
        80083274	bne    v0, zero, L836a4 [$800836a4]
        80083278	ori    v0, zero, $00ff
        8008327C	lui    v0, $800c
        80083280	lhu    v0, $1b68(v0)
        80083284	nop
        80083288	andi   v0, v0, $0020
        8008328C	beq    v0, zero, L83380 [$80083380]
        80083290	nop
        80083294	bne    s7, zero, L83380 [$80083380]
        80083298	lui    v1, $0400
        8008329C	lw     v0, $0004(s1)
        800832A0	nop
        800832A4	and    v0, v0, v1
        800832A8	bne    v0, zero, L83380 [$80083380]
        800832AC	lui    v1, $0022
        800832B0	lw     v0, $0000(s1)
        800832B4	nop
        800832B8	and    v0, v0, v1
        800832BC	bne    v0, zero, L836a4 [$800836a4]
        800832C0	ori    v0, zero, $00ff
        800832C4	lui    v0, $800b
        800832C8	lh     v0, $1648(v0)
        800832CC	nop
        800832D0	bne    v0, zero, L836a4 [$800836a4]
        800832D4	ori    v0, zero, $00ff
        800832D8	lh     a1, $0022(s1)
        800832DC	lh     v0, $0060(s1)
        800832E0	subu   a1, a1, s6
        800832E4	addu   a1, a1, v0
        800832E8	sw     a1, $0010(sp)
        800832EC	lh     a0, $002a(s1)
        800832F0	lh     v0, $0064(s1)
        800832F4	subu   a0, a0, s5
        800832F8	addu   a0, a0, v0
        800832FC	jal    system_get_rotation_based_on_vector_x_y [$8004b1d4]
        80083300	sw     a0, $0018(sp)
        80083304	subu   a0, zero, v0
        80083308	sra    v0, a0, $09
        8008330C	andi   a1, v0, $0007
        80083310	lw     t0, $0080(sp)
        80083314	andi   v0, a0, $0fff
        80083318	subu   v0, t0, v0
        8008331C	andi   a0, v0, $0fff
        80083320	lw     v0, $0004(s1)
        80083324	lui    v1, $0004
        80083328	and    v0, v0, v1
        8008332C	beq    v0, zero, L83340 [$80083340]
        80083330	addiu  v0, a0, $fd44 (=-$2bc)
        80083334	sltiu  v0, v0, $0a89
        80083338	bne    v0, zero, L836a4 [$800836a4]
        8008333C	ori    v0, zero, $00ff

        L83340:	; 80083340
        80083340	ori    s7, zero, $0001
        script_to_call = 2;
        script_priority = 3;
        8008334C	addiu  t0, zero, $f1ff (=-$e01)
        80083350	sll    v1, a1, $09
        80083354	lw     v0, $012c(s1)
        80083358	lui    a0, $800c
        8008335C	lw     a0, $1b60(a0)
        80083360	and    v0, v0, t0
        80083364	or     v0, v0, v1
        80083368	bne    a0, zero, L836a0 [$800836a0]
        8008336C	sw     v0, $012c(s1)
        80083370	lui    at, $8028
        80083374	sw     s7, $59dc(at)
        80083378	j      L836a4 [$800836a4]
        8008337C	ori    v0, zero, $00ff

        L83380:	; 80083380
        80083380	lw     v0, $0000(s1)
        80083384	lui    v1, $00a2
        80083388	and    v0, v0, v1
        8008338C	bne    v0, zero, L836a4 [$800836a4]
        80083390	ori    v0, zero, $00ff
        script_to_call = 3;
        script_priority = 4;
        8008339C	lh     a1, $0022(s1)
        800833A0	lh     v0, $0060(s1)
        800833A4	subu   a1, a1, s6
        800833A8	addu   a1, a1, v0
        800833AC	sw     a1, $0010(sp)
        800833B0	lh     a0, $002a(s1)
        800833B4	lh     v0, $0064(s1)
        800833B8	subu   a0, a0, s5
        800833BC	addu   a0, a0, v0
        800833C0	jal    system_get_rotation_based_on_vector_x_y [$8004b1d4]
        800833C4	sw     a0, $0018(sp)
        800833C8	sra    v0, v0, $09
        800833CC	subu   v0, zero, v0
        800833D0	andi   a1, v0, $0007
        800833D4	addiu  t0, zero, $f1ff (=-$e01)
        800833D8	sll    v0, a1, $09
        800833DC	lw     v1, $012c(s1)
        800833E0	lui    a0, $800c
        800833E4	lw     a0, $1b60(a0)
        800833E8	and    v1, v1, t0
        800833EC	or     v1, v1, v0
        800833F0	bne    a0, zero, L836a0 [$800836a0]
        800833F4	sw     v1, $012c(s1)
        800833F8	ori    v0, zero, $0001
        800833FC	lui    at, $8028
        80083400	sw     v0, $59dc(at)
        80083404	j      L836a4 [$800836a4]
        80083408	ori    v0, zero, $00ff

        L8340c:	; 8008340C
        [SP + 10] = w(h[S1 + 22] + h[S1 + 60] - S6);
        [SP + 14] = w(hu[S1 + 1e] + w[SP + 68]); // solid
        [SP + 18] = w(h[S1 + 2a] + h[S1 + 64] - S5);

        IR1 = w[SP + 10];
        IR2 = w[SP + 14];
        IR3 = w[SP + 18];
        gte_SQR; // Square of vector.

        [SP + 20] = w(MAC1);
        [SP + 24] = w(MAC2);
        [SP + 28] = w(MAC3);

        if (w[SP + 20] + w[SP + 28] < w[SP + 24])
        {
            if (S0 >= w[SP + 78])
            {
                if (w[SP + 70] >= S0 - hu[S1 + 1a])
                {
                    T0 = w[SP + 50];
                    if (S3 != T0)
                    {
                        A0 = w[SP + 90];
                        A1 = w[SP + 88];
                        [SP + 10] = w(h[S1 + 22] - S6 + h[S1 + 60]);
                        [SP + 18] = w(h[S1 + 2a] - S5 + h[S1 + 64]);
                        system_gte_square_of_vector;

                        S0 = w[SP + 20] + w[SP + 28];

                        [SP + 30] = w(w[SP + 60] + hu[S1 + 1e]);
                        [SP + 38] = w(w[SP + 68] + hu[S1 + 1e]);

                        A0 = SP + 30;
                        A1 = SP + 40;
                        A2 = w[SP + 20];
                        system_gte_square_of_vector;

                        if ((S0 < w[SP + 48]) && (hu[800c1b68] & 0020) && (S7 == 0) && ((w[S1 + 4] & 04000000) == 0))
                        {
                            if ((w[S1] & 00220000) == 0)
                            {
                                A0 = w[SP + 18];
                                A1 = w[SP + 10];
                                system_get_rotation_based_on_vector_x_y;

                                A0 = 0 - V0;
                                V0 = A0 >> 9;
                                A1 = V0 & 7;
                                T0 = w[SP + 80];
                                V0 = A0 & fff;
                                V0 = T0 - V0;
                                A0 = V0 & fff;
                                if (A0 - 2bc >= a89)
                                {
                                    if (h[800b1648] == 0)
                                    {
                                        S7 = 1;

                                        script_to_call = 2;
                                        script_priority = 3;

                                        [S1 + 12c] = w((w[S1 + 12c] & fffff1ff) | (A1 << 9));
                                    }
                                }
                            }
                        }
                        else
                        {
                            if ((w[S1] & 00a20000) == 0)
                            {
                                if (S0 < w[SP + 40])
                                {
                                    script_to_call = 3;
                                    script_priority = 4;

                                    A0 = w[SP + 18];
                                    A1 = w[SP + 10];
                                    system_get_rotation_based_on_vector_x_y;

                                    V0 = V0 >> 9;
                                    V0 = 0 - V0;
                                    A1 = V0 & 7;
                                    [S1 + 12c] = w((w[S1 + 12c] & fffff1ff) | (A1 << 9));
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    L836a0:	; 800836A0
    L836a4:	; 800836A4
    if (script_to_call != ff)
    {
        A0 = 0;
        loop836b4:	; 800836B4
            if( bu[S1 + 8c + A0 * 8 + 3] == script_to_call ) // script id
            {
                break;
            }
            A0 = A0 + 1;
            V0 = A0 < 8;
        800836CC	bne    v0, zero, loop836b4 [$800836b4]

        if (A0 == 8)
        {
            A0 = 0;
            loop836ec:	; 800836EC
                V1 = w[S1 + 8c + A0 * 8 + 4];
                if (((V1 >> 12) & f) == f)
                {
                    if (((V1 >> 16) & 1) == 0)
                    {
                        A0 = S3;
                        A1 = script_to_call;
                        get_script_offset;
                        [S1 + 8c + A0 * 8 + 0] = h(V0);
                        [S1 + 8c + A0 * 8 + 3] = b(script_to_call);
                        [S1 + 8c + A0 * 8 + 4] = w((w[S1 + 8c + A0 * 8 + 4] & ffc3ffff) | (script_priority << 12));

                        [S1 + 104] = h(hu[S1 + 106] | 8000);
                        [S1 + 106] = h(hu[S1 + 106] | 8000);

                        break;
                    }
                }

                A0 = A0 + 1;
                V0 = A0 < 8;
            80083718	bne    v0, zero, loop836ec [$800836ec]
        }
    }

    V0 = w[800ad0d4];
    S3 = S3 + 1;
    V0 = S3 < V0;
80083730	bne    v0, zero, L83054 [$80083054]

L83738:	; 80083738
////////////////////////////////



////////////////////////////////
// func8376c
80083774	addu   fp, a0, zero
S1 = A2;

80083780	ori    a0, zero, $0020
800837A8	sw     a1, $0048(sp)
800837A4	jal    func7c350 [$8007c350]

800837AC	lw     a2, $0020(s1)
800837B0	nop
800837B4	sw     a2, $0018(sp)
800837B8	lw     a3, $0024(s1)
800837BC	nop
800837C0	sw     a3, $001c(sp)
800837C4	lw     t0, $0028(s1)
800837C8	nop
800837CC	sw     t0, $0020(sp)
800837D0	lw     v1, $0030(s1)
800837D4	addiu  a0, sp, $0028
800837D8	addu   a2, a2, v1
800837DC	sw     a2, $0018(sp)
800837E0	lw     v1, $0034(s1)
800837E4	addiu  a1, sp, $0018
800837E8	sw     zero, $0070(sp)
800837EC	addu   a3, a3, v1
800837F0	sw     a3, $001c(sp)
800837F4	lw     v1, $0038(s1)
800837F8	addu   s3, v0, zero
800837FC	addu   t0, t0, v1
80083800	jal    func827e4 [$800827e4]
80083804	sw     t0, $0020(sp)
80083808	lh     t1, $0028(sp)
8008380C	lh     s6, $0026(s1)
80083810	lhu    v0, $001a(s1)
80083814	sw     t1, $0050(sp)
80083818	lh     t1, $002c(sp)
8008381C	subu   v0, s6, v0
80083820	sw     v0, $0060(sp)
80083824	lui    v0, $800b
80083828	lw     v0, $d0d4(v0)
8008382C	lui    s7, $7fff
80083830	sw     zero, $0078(sp)
80083834	sw     t1, $0058(sp)
80083838	lw     t1, $0000(s1)
8008383C	ori    s7, s7, $ffff
80083840	sw     t1, $0068(sp)
80083844	lbu    t1, $0074(s1)
80083850	sw     t1, $0080(sp)
S2 = 0;
if (V0 > 0)
{
    80083854	lui    t1, $ff3f
    80083858	ori    t1, t1, $ffff
    8008385C	lui    v0, $0004
    80083860	ori    v0, v0, $0800
    80083864	sw     t1, $0088(sp)
    80083868	lw     t1, $0068(sp)
    8008386C	addu   s5, zero, zero
    80083870	and    v0, t1, v0
    80083874	sw     v0, $0090(sp)

    L83878:	; 80083878
        80083878	beq    s2, fp, L83ccc [$80083ccc]
        8008387C	nop
        80083880	lui    v0, $800b
        80083884	lw     v0, $efe4(v0)
        80083888	nop
        8008388C	addu   v0, s5, v0
        A2 = w[V0 + 4c];
        A0 = w[A2 + 0];
        800838A0	andi   v0, a0, $0001
        800838A4	bne    v0, zero, L83ccc [$80083ccc]
        800838A8	lui    v1, $ffff
        S0 = A2;

        800838B0	ori    v1, v1, $3eff
        800838B4	lw     v0, $0004(s0)
        S4 = A0;
        800838BC	and    v1, v0, v1
        800838C0	andi   v0, v0, $0080
        800838C4	beq    v0, zero, L83998 [$80083998]
        800838C8	sw     v1, $0004(s0)
        800838CC	lui    v0, $800b
        800838D0	lw     v0, $efe4(v0)
        800838D4	lw     a2, $0050(sp)
        800838D8	lw     a3, $0058(sp)
        800838DC	addu   v0, s5, v0
        800838E0	lw     v1, $0000(v0)
        800838E4	addiu  v0, sp, $0040
        800838E8	sw     v0, $0010(sp)
        800838EC	addiu  v0, sp, $0030
        800838F0	sw     v0, $0014(sp)
        800838F4	lw     a1, $0004(v1)
        800838F8	jal    func8289c [$8008289c]
        800838FC	addu   a0, s2, zero
        80083900	beq    v0, zero, L83918 [$80083918]
        80083904	nop
        80083908	lw     v0, $0004(s0)
        8008390C	lw     t1, $0088(sp)
        80083910	j      L83cc8 [$80083cc8]
        80083914	and    v0, v0, t1

        L83918:	; 80083918
        // DEBUG TEXT
        if( w[800c1b60] == 0 )
        {
            A0 = 8006f2d8; // POLYCHECK %d
            A1 = S2;
            func37870;
        }

        8008393C	lw     v0, $0004(s0)
        80083940	lhu    a0, $001a(s0)
        80083944	ori    v0, v0, $0100
        80083948	sw     v0, $0004(s0)
        8008394C	lw     v0, $0040(sp)
        80083950	lbu    v1, $0074(s1)
        80083954	nop
        80083958	bne    v1, s2, L83aec [$80083aec]
        8008395C	addu   a0, v0, a0
        80083960	lw     v0, $0030(sp)
        80083964	nop
        80083968	sw     v0, $0050(s1)
        8008396C	lw     v0, $0034(sp)
        80083970	nop
        80083974	sw     v0, $0054(s1)
        80083978	lw     v0, $0038(sp)
        8008397C	nop
        80083980	sw     v0, $0058(s1)
        80083984	lw     v0, $0004(s0)
        80083988	nop
        8008398C	ori    v0, v0, $4000
        80083990	j      L83acc [$80083acc]
        80083994	sw     v0, $0004(s0)

        L83998:	; 80083998
        if ((S4 & 00002000) == 0)
        {
            [S3 + 0] = w(((w[S0 + 20] + w[S0 + 30]) >> 10) - w[SP + 50]);
            [S3 + 4] = w(hu[S1 + 1e] + hu[S0 + 1e]); // solid range
            [S3 + 8] = w(((w[S0 + 28] + w[S0 + 38]) >> 10) - w[SP + 58]);

            A0 = S3 + 0;
            A1 = S3 + 10;
            system_gte_square_of_vector;

            V0 = (w[S3 + 10] + w[S3 + 18]) < w[S3 + 14];
        }
        else
        {
            A0 = w[SP + 50];
            A1 = w[SP + 58];
            A2 = S0;
            A3 = 0;
            800839AC	jal    func81990 [$80081990]
        }

        if (V0 != 0)
        {
            [S0 + 4] = w(w[S0 + 4] & w[SP + 88]);
        }
        else
        {
            if( w[S1 + 14] & 00400000 )
            {
                // DEBUG TEXT
                if( w[800c1b60] == 0 )
                {
                    A0 = 8006f2e8; // HITOFF
                    func37870;
                }
            }
            else
            {
                T1 = w[SP + 68];
                80083A94	or     v0, s4, t1
                80083A98	andi   v0, v0, $0080
                80083A9C	bne    v0, zero, L83ccc [$80083ccc]
                80083AA0	nop
                80083AA4	lui    v0, $800b
                80083AA8	lbu    v0, $16a0(v0)
                80083AAC	nop
                80083AB0	bne    v0, zero, L83ccc [$80083ccc]
                80083AB4	nop
                80083AB8	lh     a0, $0026(s0)
                80083ABC	lhu    v0, $001a(s0)
                80083AC0	nop
                80083AC4	subu   v0, a0, v0
                80083AC8	sw     v0, $0040(sp)

                L83acc:	; 80083ACC
                80083ACC	lbu    v0, $0074(s1)
                80083AD0	nop
                80083AD4	bne    v0, s2, L83aec [$80083aec]
                80083AD8	nop
                80083ADC	lw     t1, $0090(sp)
                80083AE0	nop
                80083AE4	beq    t1, zero, L83b34 [$80083b34]
                80083AE8	lui    v1, $0080

                L83aec:	; 80083AEC
                80083AEC	lw     t1, $0060(sp)
                80083AF0	nop
                80083AF4	slt    v0, a0, t1
                80083AF8	bne    v0, zero, L83c74 [$80083c74]
                80083AFC	addiu  v1, zero, $feff (=-$101)
                80083B00	lw     v1, $0040(sp)
                80083B04	nop
                80083B08	slt    v0, s6, v1
                80083B0C	bne    v0, zero, L83c70 [$80083c70]
                80083B10	addiu  v0, v1, $0010
                80083B14	slt    v0, s6, v0
                80083B18	bne    v0, zero, L83b34 [$80083b34]
                80083B1C	lui    v1, $0080
                80083B20	lw     v0, $0004(s0)
                80083B24	nop
                80083B28	and    v0, v0, v1
                80083B2C	beq    v0, zero, L83b84 [$80083b84]
                80083B30	andi   v0, s4, $0010

                L83b34:	; 80083B34
                80083B34	lw     s7, $0040(sp)
                80083B38	lw     v0, $0004(s0)
                80083B3C	lw     a0, $0030(s0)
                80083B40	or     v0, v0, v1
                80083B44	sw     v0, $0004(s0)
                80083B48	sw     a0, $0040(s1)
                80083B4C	lw     v0, $0034(s0)
                80083B50	nop
                80083B54	sw     v0, $0044(s1)
                80083B58	lw     v0, $0038(s0)
                80083B5C	ori    t1, zero, $0002
                80083B60	sw     t1, $0078(sp)
                80083B64	sw     v0, $0048(s1)
                80083B68	lw     t1, $0090(sp)
                80083B6C	nop
                80083B70	bne    t1, zero, L83cbc [$80083cbc]
                80083B74	ori    t1, zero, $0001
                80083B78	sb     s2, $0074(s1)
                80083B7C	j      L83cbc [$80083cbc]
                80083B80	sw     t1, $0070(sp)

                L83b84:	; 80083B84
                80083B84	bne    v0, zero, L83c3c [$80083c3c]
                80083B88	nop
                80083B8C	lbu    v1, $00e3(s0)
                80083B90	nop
                80083B94	sltiu  v0, v1, $0030
                80083B98	beq    v0, zero, L83ba4 [$80083ba4]
                80083B9C	addiu  v0, v1, $0002
                80083BA0	sb     v0, $00e3(s0)

                L83ba4:	; 80083BA4
                80083BA4	lbu    v0, $00e3(s0)
                80083BA8	nop
                80083BAC	sltiu  v0, v0, $0021
                80083BB0	bne    v0, zero, L83c3c [$80083c3c]
                80083BB4	nop
                80083BB8	lw     v1, $0030(s1)
                80083BBC	nop
                80083BC0	bgez   v1, L83bcc [$80083bcc]
                80083BC4	nop
                80083BC8	addiu  v1, v1, $0003

                L83bcc:	; 80083BCC
                80083BCC	lw     v0, $0040(s0)
                80083BD0	sra    v1, v1, $02
                80083BD4	addu   v0, v0, v1
                80083BD8	sw     v0, $0040(s0)
                80083BDC	lw     v1, $0038(s1)
                80083BE0	nop
                80083BE4	bgez   v1, L83bf0 [$80083bf0]
                80083BE8	nop
                80083BEC	addiu  v1, v1, $0003

                L83bf0:	; 80083BF0
                80083BF0	lw     v0, $0048(s0)
                80083BF4	sra    v1, v1, $02
                80083BF8	addu   v0, v0, v1
                80083BFC	sw     v0, $0048(s0)
                80083C00	sw     zero, $0030(s1)
                80083C04	lw     v0, $0030(s1)
                80083C08	sw     zero, $0034(s1)
                80083C0C	bgez   v0, L83c18 [$80083c18]
                80083C10	sw     zero, $0038(s1)
                80083C14	addiu  v0, v0, $0003

                L83c18:	; 80083C18
                80083C18	lw     v1, $0038(s1)
                80083C1C	sra    v0, v0, $02
                80083C20	sw     v0, $0040(s1)
                80083C24	bgez   v1, L83c30 [$80083c30]
                80083C28	sw     zero, $0044(s1)
                80083C2C	addiu  v1, v1, $0003

                L83c30:	; 80083C30
                80083C30	sra    v0, v1, $02
                80083C34	j      L83cbc [$80083cbc]
                80083C38	sw     v0, $0048(s1)

                L83c3c:	; 80083C3C
                80083C3C	sw     zero, $0040(s0)
                80083C40	sw     zero, $0044(s0)
                80083C44	sw     zero, $0048(s0)
                80083C48	sw     zero, $0030(s0)
                80083C4C	sw     zero, $0034(s0)
                80083C50	sw     zero, $0038(s0)
                80083C54	sw     zero, $0030(s1)
                80083C58	sw     zero, $0034(s1)
                80083C5C	sw     zero, $0038(s1)
                80083C60	sw     zero, $0040(s1)
                80083C64	sw     zero, $0044(s1)
                80083C68	j      L83cbc [$80083cbc]
                80083C6C	sw     zero, $0048(s1)

                L83c70:	; 80083C70
                80083C70	addiu  v1, zero, $feff (=-$101)

                L83c74:	; 80083C74
                80083C74	lw     v0, $0004(s0)
                80083C78	lw     a0, $0040(sp)
                80083C7C	and    v1, v0, v1
                80083C80	slt    v0, s6, a0
                80083C84	beq    v0, zero, L83cac [$80083cac]
                80083C88	sw     v1, $0004(s0)
                80083C8C	lui    v0, $0080
                80083C90	or     v0, v1, v0
                80083C94	sw     v0, $0004(s0)
                80083C98	slt    v0, a0, s7
                80083C9C	beq    v0, zero, L83cbc [$80083cbc]
                80083CA0	nop
                80083CA4	j      L83cbc [$80083cbc]
                80083CA8	addu   s7, a0, zero

                L83cac:	; 80083CAC
                80083CAC	lui    v0, $ff7f
                80083CB0	ori    v0, v0, $ffff
                80083CB4	and    v0, v1, v0
                80083CB8	sw     v0, $0004(s0)

                L83cbc:	; 80083CBC
                80083CBC	lw     v0, $0004(s0)
                80083CC0	lui    v1, $0040
                80083CC4	or     v0, v0, v1
                [S0 + 4] = w(V0);
            }
        }

        L83ccc:	; 80083CCC
        S5 = S5 + 5c;
        S2 = S2 + 1;
        V0 = S2 < w[800ad0d4];
    80083CE0	bne    v0, zero, L83878 [$80083878]
}

80083CE8	lui    v0, $800b
80083CEC	lw     v0, $d070(v0)
80083CF0	nop
80083CF4	beq    v0, zero, L83d14 [$80083d14]
80083CF8	nop
80083CFC	lui    s7, $800b
80083D00	lw     s7, $d06c(s7)
80083D04	lw     t1, $0078(sp)
80083D08	sw     zero, $0070(sp)
80083D0C	addiu  t1, t1, $0001
80083D10	sw     t1, $0078(sp)

L83d14:	; 80083D14
80083D14	lw     t1, $0070(sp)
80083D18	nop
80083D1C	bne    t1, zero, L83d2c [$80083d2c]
80083D20	ori    v0, zero, $00ff
80083D24	j      L83e68 [$80083e68]
80083D28	sb     v0, $0074(s1)

L83d2c:	; 80083D2C
80083D2C	lbu    v1, $0074(s1)
80083D30	nop
80083D34	sll    v0, v1, $01
80083D38	addu   v0, v0, v1
80083D3C	sll    v0, v0, $03
80083D40	subu   v0, v0, v1
80083D44	lui    v1, $800b
80083D48	lw     v1, $efe4(v1)
80083D4C	sll    v0, v0, $02
80083D50	addu   v0, v0, v1
80083D54	lw     v1, $004c(v0)
80083D58	nop
80083D5C	lw     v0, $0004(v1)
80083D60	nop
80083D64	ori    v0, v0, $8000
80083D68	sw     v0, $0004(v1)
80083D6C	lw     t1, $0080(sp)
80083D70	ori    v0, zero, $00ff
80083D74	bne    t1, v0, L83e68 [$80083e68]
80083D78	nop
80083D7C	lw     v0, $0134(s1)
80083D80	nop
80083D84	andi   v0, v0, $0080
80083D88	bne    v0, zero, L83da8 [$80083da8]
80083D8C	ori    a0, zero, $000c
80083D90	jal    system_memory_allocate [$800319ec]
80083D94	addu   a1, zero, zero
80083D98	lw     v1, $0134(s1)
80083D9C	sw     v0, $0110(s1)
80083DA0	ori    v1, v1, $0080
80083DA4	sw     v1, $0134(s1)

L83da8:	; 80083DA8
80083DA8	lbu    v1, $0074(s1)
80083DAC	nop
80083DB0	sll    v0, v1, $01
80083DB4	addu   v0, v0, v1
80083DB8	sll    v0, v0, $03
80083DBC	subu   v0, v0, v1
80083DC0	lui    v1, $800b
80083DC4	lw     v1, $efe4(v1)
80083DC8	sll    v0, v0, $02
80083DCC	addu   v0, v0, v1
80083DD0	lw     v1, $0110(s1)
80083DD4	lhu    v0, $0050(v0)
80083DD8	nop
80083DDC	sh     v0, $0000(v1)
80083DE0	lbu    v1, $0074(s1)
80083DE4	nop
80083DE8	sll    v0, v1, $01
80083DEC	addu   v0, v0, v1
80083DF0	sll    v0, v0, $03
80083DF4	subu   v0, v0, v1
80083DF8	lui    v1, $800b
80083DFC	lw     v1, $efe4(v1)
80083E00	sll    v0, v0, $02
80083E04	addu   v0, v0, v1
80083E08	lw     v1, $0110(s1)
80083E0C	lhu    v0, $0052(v0)
80083E10	nop
80083E14	sh     v0, $0002(v1)
80083E18	lbu    v1, $0074(s1)
80083E1C	nop
80083E20	sll    v0, v1, $01
80083E24	addu   v0, v0, v1
80083E28	sll    v0, v0, $03
80083E2C	subu   v0, v0, v1
80083E30	lui    v1, $800b
80083E34	lw     v1, $efe4(v1)
80083E38	sll    v0, v0, $02
80083E3C	addu   v0, v0, v1
80083E40	lw     v1, $0110(s1)
80083E44	lhu    v0, $0054(v0)
80083E48	nop
80083E4C	sh     v0, $0004(v1)
80083E50	lbu    a1, $0074(s1)
80083E54	jal    get_distance_between_entities [$80081bc0]
80083E58	addu   a0, fp, zero
80083E5C	lw     v1, $0110(s1)
80083E60	nop
80083E64	sh     v0, $0008(v1)

L83e68:	; 80083E68
80083E68	lw     v0, $0000(s1)
80083E6C	lui    v1, $0001
80083E70	and    v0, v0, v1
80083E74	bne    v0, zero, L83eb0 [$80083eb0]
80083E78	sll    v0, fp, $01
80083E7C	lw     v0, $0004(s1)
80083E80	lui    v1, $0020
80083E84	and    v0, v0, v1
80083E88	bne    v0, zero, L83eb0 [$80083eb0]
80083E8C	sll    v0, fp, $01
80083E90	lw     t1, $0078(sp)
80083E94	addu   a0, fp, zero
80083E98	addu   a1, s7, zero
80083E9C	lw     a2, $0048(sp)
80083EA0	addu   a3, s1, zero
80083EA4	jal    func84054 [$80084054]
80083EA8	sw     t1, $0010(sp)
80083EAC	sll    v0, fp, $01

L83eb0:	; 80083EB0
80083EB0	addu   v0, v0, fp
80083EB4	sll    v0, v0, $03
80083EB8	subu   v0, v0, fp
80083EBC	lui    v1, $800b
80083EC0	lw     v1, $efe4(v1)
80083EC4	sll    v0, v0, $02
80083EC8	addu   v0, v0, v1
80083ECC	lw     v0, $0004(v0)
80083ED0	nop
80083ED4	lw     v0, $007c(v0)
80083ED8	nop
80083EDC	lhu    v1, $000c(v0)
80083EE0	ori    v0, zero, $0001
80083EE4	bne    v1, v0, L83f04 [$80083f04]
80083EE8	nop
80083EEC	jal    func35c84 [$80035c84]
80083EF0	nop
80083EF4	lw     v0, $0000(s1)
80083EF8	addiu  v1, zero, $f7ff (=-$801)
80083EFC	and    v0, v0, v1
80083F00	sw     v0, $0000(s1)

L83f04:	; 80083F04
80083F04	jal    func7c374 [$8007c374]
80083F08	ori    a0, zero, $0020
////////////////////////////////
