////////////////////////////////
// func720c8()
S0 = A0;
S2 = A1;

[SP + 38] = w(w[S0 + 0]);
[SP + 3c] = w(0);
[SP + 40] = w(w[S0 + 8]);

A0 = SP + 38;
A1 = SP + 10;
A2 = SP + 28;
80072104	jal    func7c394 [$8007c394]

if( V0 == -1 )
{
    [SP + 20] = h(hu[SP + 10]);
    [SP + 22] = h(hu[SP + 14]);
    [SP + 24] = h(hu[SP + 18]);
    [SP + 26] = h(hu[SP + 1c]);

    A0 = SP + 20;
    A1 = SP + 28;
    A2 = SP + 30;
    80072140	jal    func71a74 [$80071a74]

    [800aed94] = w(h[SP + 30] << 10);
    [800aed9c] = w(h[SP + 32] << 10);

    if( bu[800b16a1] == 0 )
    {
        if( w[800ad080] == 0 )
        {
            [800aed98] = w(S2 << 10);
            [800ad080] = w(1);
        }
    }
    else
    {
        [800aed98] = w(ffe00000 + w[S0 + 4]);
    }
}
else
{
    [800ad080] = w(0);
    [800aed94] = w(w[S0 + 0]);
    [800aed98] = w(ffe00000 + w[S0 + 4]);
    [800aed9c] = w(w[S0 + 8]);
}



[800aed84] = w(w[800aed94]);

A0 = ((h[800aeed0] * 3b) / 8) + c00;
system_cos();
[800aed88] = w(w[800aed98] + ((((0 - ((V0 * w[800aeecc]) << 5)) >> 10) * h[800aeed2]) << 4));

A0 = ((h[800aeed0] * 3b) / 8) + c00;
system_sin();
[800aed8c] = w(w[800aed9c] + (((((V0 * w[800aeecc]) << 5) >> 10) * h[800aeed2]) << 4));



A1 = 800aed94;
800722F8	jal    func72d14 [$80072d14]



if( w[800aeeac] & 00000001 )
{
    if( h[800aeef0] != 0 )
    {
        V0 = w[800aeef4] + w[800aeef8];
        [800aeef4] = w(V0);
        [800aeed2] = h(V0 >> 10);
    }

    [800aeef0] = h(h[800aeef0] - 1);
    if( h[800aeef0] == 0 )
    {
        [800aeeac] = w(w[800aeeac] & 0000fffe);
    }
}



if( w[800aeeac] & 00000008 )
{
    V0 = w[800aeed8] + w[800aeedc];
    [800aeed8] = w(V0);
    [800aeed0] = h(V0 >> 10);

    [800aeed4] = h(hu[800aeed4]) - 1;
    if( hu[800aeed4] == 0 )
    {
        [800aeeac] = w(w[800aeeac] & 0000fff7)
    }
}
////////////////////////////////



////////////////////////////////
// func71d78
80071D78	addiu  sp, sp, $ffe8 (=-$18)
80071D7C	lui    a0, $800b
80071D80	lbu    a0, $eec8(a0)
80071D84	ori    v1, zero, $00ff
80071D88	sw     ra, $0014(sp)
80071D8C	andi   v0, a0, $00ff
80071D90	beq    v0, v1, L72028 [$80072028]
80071D94	sw     s0, $0010(sp)
80071D98	lui    v0, $800b
80071D9C	lbu    v0, $eec9(v0)
80071DA0	nop
80071DA4	beq    v0, v1, L72028 [$80072028]
80071DA8	nop
80071DAC	lui    v0, $800b
80071DB0	lh     v0, $eeca(v0)
80071DB4	nop
80071DB8	bne    v0, zero, L71ee0 [$80071ee0]
80071DBC	nop
80071DC0	lui    v0, $800b
80071DC4	lhu    v0, $eeba(v0)
80071DC8	nop
80071DCC	andi   v0, v0, $0fff
80071DD0	srl    v0, v0, $09
80071DD4	lui    at, $800b
80071DD8	addu   at, at, v0
80071DDC	lbu    v0, $d0f4(at)
80071DE0	nop
80071DE4	and    v0, v0, a0
80071DE8	beq    v0, zero, L71e34 [$80071e34]
80071DEC	lui    v0, $ffc0
80071DF0	lui    v1, $800b
80071DF4	lw     v1, $eec0(v1)
80071DF8	nop
80071DFC	beq    v1, v0, L71e28 [$80071e28]
80071E00	lui    a0, $0040
80071E04	beq    v1, a0, L71e2c [$80071e2c]
80071E08	ori    v0, zero, $0008
80071E0C	lui    v0, $800b
80071E10	lw     v0, $eee0(v0)
80071E14	lui    at, $800b
80071E18	sw     a0, $eec0(at)
80071E1C	addiu  v0, v0, $0200
80071E20	lui    at, $800b
80071E24	sw     v0, $eee0(at)

L71e28:	; 80071E28
80071E28	ori    v0, zero, $0008

L71e2c:	; 80071E2C
80071E2C	lui    at, $800b
80071E30	sh     v0, $eeca(at)

L71e34:	; 80071E34
80071E34	lui    s0, $800b
80071E38	addiu  s0, s0, $eec9 (=-$1137)
80071E3C	lui    v0, $800b
80071E40	lhu    v0, $eeba(v0)
80071E44	lbu    a0, $0000(s0)
80071E48	andi   v0, v0, $0fff
80071E4C	srl    a1, v0, $09
80071E50	lui    at, $800b
80071E54	addu   at, at, a1
80071E58	lbu    v0, $d0f4(at)
80071E5C	nop
80071E60	and    v0, v0, a0
80071E64	beq    v0, zero, L71ee0 [$80071ee0]
80071E68	nop
80071E6C	jal    func719dc [$800719dc]
80071E70	nop
80071E74	lui    a1, $800b
80071E78	lhu    a1, $eeba(a1)
80071E7C	lbu    a0, $0000(s0)
80071E80	addu   s0, v0, zero
80071E84	andi   a1, a1, $0fff
80071E88	jal    func71a28 [$80071a28]
80071E8C	srl    a1, a1, $09
80071E90	slt    v0, v0, s0
80071E94	beq    v0, zero, L71eb4 [$80071eb4]
80071E98	lui    v1, $ffc0
80071E9C	lui    v0, $800b
80071EA0	lw     v0, $eee0(v0)
80071EA4	lui    at, $800b
80071EA8	sw     v1, $eec0(at)
80071EAC	j      L71ecc [$80071ecc]
80071EB0	addiu  v0, v0, $fe00 (=-$200)

L71eb4:	; 80071EB4
80071EB4	lui    v0, $800b
80071EB8	lw     v0, $eee0(v0)
80071EBC	lui    v1, $0040
80071EC0	lui    at, $800b
80071EC4	sw     v1, $eec0(at)
80071EC8	addiu  v0, v0, $0200

L71ecc:	; 80071ECC
80071ECC	lui    at, $800b
80071ED0	sw     v0, $eee0(at)
80071ED4	ori    v0, zero, $0008
80071ED8	lui    at, $800b
80071EDC	sh     v0, $eeca(at)

L71ee0:	; 80071EE0
80071EE0	lui    v0, $800b
80071EE4	lhu    v0, $f370(v0)
80071EE8	nop
80071EEC	andi   v0, v0, $0004
80071EF0	beq    v0, zero, L71f84 [$80071f84]
80071EF4	nop
80071EF8	lui    v0, $800b
80071EFC	lw     v0, $eeac(v0)
80071F00	nop
80071F04	andi   v0, v0, $8000
80071F08	bne    v0, zero, L71f84 [$80071f84]
80071F0C	nop
80071F10	lui    v0, $800b
80071F14	lh     v0, $eeca(v0)
80071F18	nop
80071F1C	bne    v0, zero, L71f84 [$80071f84]
80071F20	nop
80071F24	lui    v0, $800b
80071F28	lh     v0, $eeba(v0)
80071F2C	lui    v1, $800b
80071F30	lbu    v1, $eec9(v1)
80071F34	addiu  v0, v0, $fe00 (=-$200)
80071F38	andi   v0, v0, $0fff
80071F3C	sra    v0, v0, $09
80071F40	lui    at, $800b
80071F44	addu   at, at, v0
80071F48	lbu    v0, $d0f4(at)
80071F4C	nop
80071F50	and    v0, v0, v1
80071F54	bne    v0, zero, L71f84 [$80071f84]
80071F58	lui    v0, $ffc0
80071F5C	lui    at, $800b
80071F60	sw     v0, $eec0(at)
80071F64	lui    v0, $800b
80071F68	lw     v0, $eee0(v0)
80071F6C	ori    v1, zero, $0008
80071F70	lui    at, $800b
80071F74	sh     v1, $eeca(at)
80071F78	addiu  v0, v0, $fe00 (=-$200)
80071F7C	lui    at, $800b
80071F80	sw     v0, $eee0(at)

L71f84:	; 80071F84
80071F84	lui    v0, $800b
80071F88	lhu    v0, $f370(v0)
80071F8C	nop
80071F90	andi   v0, v0, $0008
80071F94	beq    v0, zero, L72028 [$80072028]
80071F98	nop
80071F9C	lui    v0, $800b
80071FA0	lw     v0, $eeac(v0)
80071FA4	nop
80071FA8	andi   v0, v0, $8000
80071FAC	bne    v0, zero, L72028 [$80072028]
80071FB0	nop
80071FB4	lui    v0, $800b
80071FB8	lh     v0, $eeca(v0)
80071FBC	nop
80071FC0	bne    v0, zero, L7203c [$8007203c]
80071FC4	nop
80071FC8	lui    v0, $800b
80071FCC	lh     v0, $eeba(v0)
80071FD0	lui    v1, $800b
80071FD4	lbu    v1, $eec9(v1)
80071FD8	addiu  v0, v0, $0200
80071FDC	andi   v0, v0, $0fff
80071FE0	sra    v0, v0, $09
80071FE4	lui    at, $800b
80071FE8	addu   at, at, v0
80071FEC	lbu    v0, $d0f4(at)
80071FF0	nop
80071FF4	and    v0, v0, v1
80071FF8	bne    v0, zero, L72028 [$80072028]
80071FFC	lui    v0, $0040
80072000	lui    at, $800b
80072004	sw     v0, $eec0(at)
80072008	lui    v0, $800b
8007200C	lw     v0, $eee0(v0)
80072010	ori    v1, zero, $0008
80072014	lui    at, $800b
80072018	sh     v1, $eeca(at)
8007201C	addiu  v0, v0, $0200
80072020	lui    at, $800b
80072024	sw     v0, $eee0(at)

L72028:	; 80072028
80072028	lui    v0, $800b
8007202C	lh     v0, $eeca(v0)
80072030	nop
80072034	beq    v0, zero, L72088 [$80072088]
80072038	nop

L7203c:	; 8007203C
8007203C	lui    a0, $800b
80072040	addiu  a0, a0, $eec4 (=-$113c)
80072044	lw     v0, $0000(a0)
80072048	lui    v1, $800b

func7204c:	; 8007204C
8007204C	lw     v1, $eec0(v1)
80072050	nop
80072054	addu   v0, v0, v1
80072058	sw     v0, $0000(a0)
8007205C	lui    v1, $800b
80072060	lhu    v1, $eeca(v1)
80072064	sra    v0, v0, $10
80072068	lui    at, $800b
8007206C	sh     v0, $eeba(at)
80072070	addiu  v1, v1, $ffff (=-$1)
80072074	lui    at, $800b
80072078	sh     v1, $eeca(at)
8007207C	sll    v1, v1, $10
80072080	bne    v1, zero, L72098 [$80072098]
80072084	nop

L72088:	; 80072088
80072088	lui    v0, $800b
8007208C	lw     v0, $eee0(v0)
80072090	lui    at, $800b
80072094	sh     v0, $eeba(at)

L72098:	; 80072098
80072098	lui    v0, $800c
8007209C	lw     v0, $1b60(v0)
800720A0	nop
800720A4	bne    v0, zero, L720b4 [$800720b4]
800720A8	nop
800720AC	0C0A13BE	ѕ...
800720B0	nop

L720b4:	; 800720B4
800720B4	lw     ra, $0014(sp)
800720B8	lw     s0, $0010(sp)
800720BC	addiu  sp, sp, $0018
800720C0	jr     ra 
800720C4	nop
////////////////////////////////
