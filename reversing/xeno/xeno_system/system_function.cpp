////////////////////////////////
// func36eb4()
[SP + 18] = w(A0);
[SP + 1c] = w(A1);
[SP + 20] = w(A2);
[SP + 24] = w(A3);

if( w[80058a30] != 0 )
{
    A0 = 0;
    A1 = A0;
    A2 = SP + 1c;
    80036EE8	jal    func365c0 [$800365c0]
}
////////////////////////////////



////////////////////////////////
// func31edc
[A0 - 4] = w(w[A0 - 4] & fdffffff);
////////////////////////////////



////////////////////////////////
// func444b4
a0 -
a1 -

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



////////////////////////////////
// func447d4
a0 -
a1 -
a2 -

S0 = A0;
S2 = A1;
S1 = A2;

A0 = 80019238;
A1 = S0;
func444b4

V0 = [S0 + 4] = [800aeae8];

if (V0 != 0)
{
    V0 = [S0 + 6]

    if (V0 != 0)
    {
        V0 = S1 << 0x10;
        V1 = S2 & 0xFFFF
        V0 = V0 | V1;
        A1 = 80056020;
        A0 = [S0] = 25C;
        V1 = [80055f68] = 80055F28
        A2 = 0x14
        [80056024] = V0;
        [A1] = A0;
        V0 = [S0 + 4] = 26001C;
        A3 = 0;
        [80056028] = V0;
        A0 = [V1 + 0x18] = 80046464;
        V0 = [V1 + 0x08] = 80046504;
        A1 = A1 - 8;
        80044874	jalr   v0 ra
    }
}

V0 = -1;
////////////////////////////////



////////////////////////////////
// func445dc
800445DC	addiu  sp, sp, $ffd8 (=-$28)
800445E0	sw     s3, $001c(sp)
800445E4	addu   s3, a0, zero
800445E8	lui    a0, $8002
800445EC	addiu  a0, a0, $9214 (=-$6dec)
800445F0	sw     s2, $0018(sp)
800445F4	addu   s2, a1, zero
800445F8	addu   a1, s3, zero
800445FC	sw     s1, $0014(sp)
80044600	addu   s1, a2, zero
80044604	sw     s0, $0010(sp)
80044608	sw     ra, $0020(sp)
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
80044650	lw     ra, $0020(sp)
80044654	lw     s3, $001c(sp)
80044658	lw     s2, $0018(sp)
8004465C	lw     s1, $0014(sp)
80044660	lw     s0, $0010(sp)
80044664	addiu  sp, sp, $0028
80044668	jr     ra 
8004466C	nop
////////////////////////////////



////////////////////////////////
// system_extract_archive
comp_position = A0;
decomp_length = w[comp_position];
comp_position = comp_position + 4;
T7 = A1 + decomp_length;

80032CE4	addu   t6, a1, zero
T8 = bu[comp_position];

L32cec:	; 80032CEC
    if( A1 == T7 )
    {
        return T6;
    }

    comp_position = comp_position + 1;
    80032CF4	andi   t1, t8, $0001
    80032CF8	ori    t9, zero, $0008

    loop32cfc:	; 80032CFC
        T0 = bu[A0];

        80032D00	srl    t8, t8, $01
        80032D04	addiu  t9, t9, $ffff (=-$1)
        comp_position = comp_position + 1;
        80032D08	bne    t1, zero, L32d28 [$80032d28]

        80032D10	sb     t0, $0000(a1)
        80032D14	addiu  a1, a1, $0001
        80032D1C	andi   t1, t8, $0001
    80032D18	bne    t9, zero, loop32cfc [$80032cfc]

    T8 = bu[comp_position];
    80032D20	j      L32cec [$80032cec]

    L32d28:	; 80032D28
    T4 = bu[comp_position];
    comp_position = comp_position + 1;

    80032D30	andi   t1, t4, $000f
    80032D34	sll    t1, t1, $08
    80032D38	or     t0, t0, t1
    80032D3C	subu   t1, a1, t0
    80032D40	srl    t3, t4, $04
    80032D44	addiu  t3, t3, $0003
    80032D48	addu   t3, t3, t1

    loop32d4c:	; 80032D4C
        T0 = b[T1];
        [A1] = b(T0);
        T1 = T1 + 1;
        A1 = A1 + 1;
    80032D58	bne    t1, t3, loop32d4c [$80032d4c]

    80032D60	bne    t9, zero, loop32cfc [$80032cfc]
    80032D64	andi   t1, t8, $0001
    T8 = bu[comp_position];
80032D68	j      L32cec [$80032cec]
////////////////////////////////



////////////////////////////////
// system_memory_allocate
// A0 - size of memory to allocate
S1 = A0;
S0 = A1;

80031A00	addiu  v0, sp, $0010
80031A08	addu   t7, v0, zero
80031A0C	sw     ra, $0000(t7)
80031A10	lw     v0, $0010(sp)
V1 = w[GP + 1bc];

80031A18	addiu  v0, v0, $fff8 (=-$8)
80031A1C	sw     v0, $0010(sp)
80031A20	sw     v0, $01d0(gp)
80031A24	sll    v0, v0, $07
80031A28	srl    v0, v0, $09
80031A30	sw     v0, $0010(sp)
if( V1 != 0 )
{
    func31e1c;
}

A2 = 1;

[GP + 1cc] = w(S1);

S1 = (S1 + 3) & fffffffc; // align to size of word

T5 = 0; // allocated memory pointer
A3 = 800000;
T4 = 0;
A0 = w[GP + 1b0];
T0 = 0;
T2 = A0 - 8;

func31a68:	; 80031A68
    V0 = w[T2 + 4];
    if (V0 & 01e00000)
    {
        loop31a7c:	; 80031A7C
            if ((w[T2 + 4] & 01e00000) == 00200000)
            {
                V0 = w[GP + 1c0];
                80031BC0	beq    v0, zero, L31bd8 [$80031bd8]

                80031BC8	beq    a2, zero, L31be8 [$80031be8]

                return 0;
            }

            A0 = w[T2 + 0];
            T2 = A0 - 8;
            V0 = w[A0 - 4] & 01e00000;
        80031AA4	bne    v0, zero, loop31a7c [$80031a7c]

    }

    A1 = w[T2 + 0] - T2 - 10;
    V1 = A1 - S1;

    if (V1 == 4 || V1 == 0)
    {
        if (S0 != 1)
        {
            80031AE8	lui    a3, $fe1f
            80031AEC	ori    a3, a3, $ffff
            80031AF0	lui    a1, $03ff
            80031AF4	ori    a1, a1, $ffff
            80031AF8	lui    t0, $fdff
            80031AFC	ori    t0, t0, $ffff
            80031B00	lui    t1, $001f
            80031B04	ori    t1, t1, $ffff
            80031B08	addiu  v0, t2, $0008
            80031B0C	lw     a2, $0004(t2)
            80031B10	lhu    a0, $01a8(gp)
            80031B14	ori    v1, zero, $0020
            80031B18	sh     v1, $01a8(gp)
            80031B1C	lhu    v1, $01ac(gp)
            80031B20	and    a2, a2, a3
            80031B24	andi   v1, v1, $000f
            80031B28	sll    v1, v1, $15
            80031B2C	or     a2, a2, v1
            80031B30	and    a1, a2, a1
            80031B34	sll    a0, a0, $1a
            80031B38	or     a1, a1, a0
            80031B3C	and    a1, a1, t0
            80031B40	lui    a0, $ffe0
            80031B44	lw     v1, $0010(sp)
            80031B48	and    a0, a1, a0
            80031B4C	sw     a2, $0004(t2)
            80031B50	sw     a1, $0004(t2)
            80031B54	and    v1, v1, t1
            80031B58	or     a0, a0, v1
            80031B60	sw     a0, $0004(t2)
            return;
        }

        80031ADC	addu   a2, zero, zero
        80031AE4	addu   t0, t2, zero
        80031BAC	lw     a0, $0000(t2)
        80031BB4	addiu  t2, a0, $fff8 (=-$8)
        80031BB0	j      func31a68 [$80031a68]
    }

    if (V1 >= 5)
    {
        A2 = 0;

        if (S0 == 1)
        {
            T4 = T2;
        }
        else if (S0 != 2)
        {
            T5 = A0;
            T4 = T2;
            80031BA4	j      L31c8c [$80031c8c]
        }
        else if (A1 < A3)
        {
            T5 = A0;
            T4 = T2;
            A3 = A1;
        }
    }

    A0 = w[T2 + 0];
    T2 = A0 - 8;
80031BB0	j      func31a68 [$80031a68]




L31bd8:	; 80031BD8
80031BD8	beq    a2, zero, L31bec [$80031bec]
80031BDC	ori    v0, zero, $0001
80031BE0	jal    func19b50 [$80019b50]
80031BE4	ori    a0, zero, $0082

L31be8:	; 80031BE8
80031BE8	ori    v0, zero, $0001

L31bec:	; 80031BEC
80031BEC	bne    s0, v0, L31c90 [$80031c90]
80031BF0	lui    t2, $fe1f
80031BF4	sltu   v0, t4, t0
80031BF8	bne    v0, zero, L31ae8 [$80031ae8]
80031BFC	addu   t2, t0, zero
80031C00	lui    a3, $fe1f
80031C04	ori    a3, a3, $ffff
80031C08	lui    a1, $03ff
80031C0C	ori    a1, a1, $ffff
80031C10	lui    t0, $fdff
80031C14	ori    t0, t0, $ffff
80031C18	lui    t1, $001f
80031C1C	ori    t1, t1, $ffff
80031C20	lhu    a0, $01a8(gp)
80031C24	lw     v1, $0000(t4)
80031C28	ori    v0, zero, $0020
80031C2C	sh     v0, $01a8(gp)
80031C30	addiu  v0, s1, $0008
80031C34	subu   v0, v1, v0
80031C38	lw     a2, $fffc(v0)
80031C3C	sll    a0, a0, $1a
80031C40	sw     v1, $fff8(v0)
80031C44	lhu    v1, $01ac(gp)
80031C48	and    a2, a2, a3
80031C4C	andi   v1, v1, $000f
80031C50	sll    v1, v1, $15
80031C54	or     a2, a2, v1
80031C58	and    a1, a2, a1
80031C5C	or     a1, a1, a0
80031C60	and    a1, a1, t0
80031C64	lui    a0, $ffe0
80031C68	lw     v1, $0010(sp)
80031C6C	and    a0, a1, a0
80031C70	sw     a2, $fffc(v0)
80031C74	sw     a1, $fffc(v0)
80031C78	and    v1, v1, t1
80031C7C	or     a0, a0, v1
80031C80	sw     a0, $fffc(v0)
80031C84	j      L31d7c [$80031d7c]
80031C88	sw     v0, $0000(t4)

L31c8c:	; 80031C8C
80031C8C	lui    t2, $fe1f

L31c90:	; 80031C90
80031C90	ori    t2, t2, $ffff
80031C94	lui    t1, $03ff
80031C98	ori    t1, t1, $ffff
80031C9C	lui    t3, $fdff
80031CA0	ori    t3, t3, $ffff
80031CA4	lui    t0, $001f
80031CA8	ori    t0, t0, $ffff
V0 = T5;
A2 = V0 + S1;
V1 = 20;
A1 = w[A2 + 4];

80031CBC	lhu    a3, $01a8(gp)
80031CC0	lui    a0, $01e0
80031CC4	sh     v1, $01a8(gp)
80031CC8	lw     v1, $0000(t4)
80031CCC	and    a1, a1, t2
80031CD0	sw     v1, $0000(a2)
80031CD4	lw     v1, $0004(t4)
80031CD8	sll    a3, a3, $1a
80031CDC	and    v1, v1, a0
80031CE0	or     a1, a1, v1
80031CE4	sw     a1, $0004(a2)
80031CE8	lw     v1, $0004(t4)
80031CEC	and    a1, a1, t1
80031CF0	srl    v1, v1, $1a
80031CF4	sll    v1, v1, $1a
80031CF8	or     a1, a1, v1
80031CFC	and    a0, a1, t3
80031D00	sw     a1, $0004(a2)
80031D04	lw     v1, $0004(t4)
80031D08	lui    a1, $0200
80031D0C	and    v1, v1, a1
80031D10	or     a0, a0, v1
80031D14	lui    a1, $ffe0
80031D18	sw     a0, $0004(a2)
80031D1C	lw     v1, $0004(t4)
80031D20	and    a0, a0, a1
80031D24	and    v1, v1, t0
80031D28	or     a0, a0, v1
80031D2C	sw     a0, $0004(a2)
80031D30	lw     v1, $0004(t4)
80031D34	addiu  a2, a2, $0008
80031D38	sw     a2, $0000(t4)
80031D3C	and    v1, v1, t1
80031D40	or     v1, v1, a3
80031D44	sw     v1, $0004(t4)
80031D48	lw     a0, $0004(t4)
80031D4C	lhu    v1, $01ac(gp)
80031D50	and    a0, a0, t2
80031D54	andi   v1, v1, $000f
80031D58	sll    v1, v1, $15
80031D5C	or     a0, a0, v1
80031D60	and    a0, a0, t3
80031D64	lw     v1, $0010(sp)
80031D68	and    a1, a0, a1
80031D6C	sw     a0, $0004(t4)
80031D70	and    v1, v1, t0
80031D74	or     a1, a1, v1
80031D78	sw     a1, $0004(t4)

L31d7c:	; 80031D7C
return;
////////////////////////////////



////////////////////////////////
// system_copy_memory
if( A0 == 0 )
{
    return 0;
}

V1 = A0;
if( A2 > 0 )
{
    loop3f820:	; 8003F820
        [A0] = b(bu[A1]);
        A0 = A0 + 1;
        A1 = A1 + 1;
        A2 = A2 - 1;
    8003F830	bgtz   a2, loop3f820 [$8003f820]
}

return V1;
////////////////////////////////



////////////////////////////////
// system_set_pack_global_pointers
number_of_files = w[A0];
if (number_of_files != 0)
{
    A1 = 1;
    loop33268:	; 80033268
        [A0 + A1 * 4] = w(A0 + w[A0 + A1 * 4]); // set global offset
        A1 = A1 + 1;
        V0 = A1 < number_of_files;
    80033284	beq    v0, zero, loop33268 [$80033268]
}

return number_of_files;
////////////////////////////////



////////////////////////////////
// system_side_of_vector
8004A5B4	mtc2   a0,l33
8004A5B8	mtc2   a2,gbk
8004A5BC	mtc2   a1,rbk
8004A5C8	gte_func26zero,r11r12
8004A5CC	mfc2   v0,ofx
8004A5D0	jr     ra 
////////////////////////////////



////////////////////////////////
// func322bc
[GP + 1ac] = h(A0);
[80059640 + A0 * 4] = w(A1);
[GP + 1c0] = w(0);
////////////////////////////////



////////////////////////////////
// func322dc()
[GP + 1a8] = h(A0);
////////////////////////////////



////////////////////////////////
// system_cos()
return h[80051a92 + (A0 & 0fff) * 4];
////////////////////////////////



////////////////////////////////
// system_sin
return h[80051a90 + (A0 & 0fff) * 4];
////////////////////////////////



////////////////////////////////
// system_get_rotation_based_on_vector_x_y
//A0 - Y
//A1 - X
//V0 - rotation for entity

A2 = 0;
A3 = 0;

if (A1 == 0 && A0 == 0)
{
    return 0;
}

if (A1 < 0)
{
    A2 = 1;
    A1 = -A1;
}

if (A0 < 0)
{
    A3 = 1;
    A0 = -A0;
}



if (A0 >= A1)
{
    if (A0 & 7fe00000)
    {
        V0 = A1 >> 10;
        A0 = A0 / V0;
    }
    else
    {
        V0 = A0 << 10;
        A0 = V0 / A1;
    }

    V1 = h[800566d0 + A0 * 2];
}
else
{
    if (A1 & 7fe00000)
    {
        V0 = A0 >> 10;
        A0 = A1 / V0;
    }
    else
    {
        V0 = A1 << 10;
        A0 = V0 / A0;
    }

    V1 = 0400 - h[800566d0 + A0 * 2];
}

if (A2 != 0)
{
    V1 = 0800 - V1;
}

if (A3 != 0)
{
    V1 = -V1;
}

V0 = V1;
////////////////////////////////



////////////////////////////////
// battle_get_random_value_from_to
if (A0 == FF)
{
    return FF;
}
if (A1 == 0)
{
    return 0;
}

if (A0 == A1)
{
    return A0;
}

S0 = A1 - A0;
if (S0 < FF)
{
    system_get_random_2_bytes;
    V0 = V0 & FF;

    V1 = S0 + 1;
    V1 = V0 MOD V1; 1F MOD 3 = 1
    V1 = A0 + V1;
    V0 = V1;
}
else
{
    system_get_random_2_bytes;
    V0 = V0 & FF;
}

return V0;
////////////////////////////////



////////////////////////////////
// system_get_random_2_bytes
V0 = w[80059898];
V0 = V0 * 41C64E6D + 3039;
[80059898] = w(V0);
V0 = V0 >> 10;
return V0 & 7FFF;
////////////////////////////////
