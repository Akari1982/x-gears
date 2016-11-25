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
