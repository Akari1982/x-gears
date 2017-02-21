////////////////////////////////
// func728c0()
800728C4	lui    a0, $800b
800728C8	addiu  a0, a0, $ee08 (=-$11f8)
800728D8	lh     v1, $0000(a0)
800728DC	ori    v0, zero, $0001
800728E0	beq    v1, v0, L72b30 [$80072b30]
800728E4	slti   v0, v1, $0002
800728E8	beq    v0, zero, L72900 [$80072900]
800728EC	nop
800728F0	beq    v1, zero, L7293c [$8007293c]
800728F4	nop
800728F8	j      L72cdc [$80072cdc]
800728FC	nop

L72900:	; 80072900
80072900	ori    v0, zero, $0002
80072904	bne    v1, v0, L72cdc [$80072cdc]
80072908	nop
8007290C	lui    v0, $800b
80072910	lw     v0, $d088(v0)
80072914	lui    at, $800b
80072918	sw     zero, $d084(at)
8007291C	addiu  v0, v0, $0001
80072920	lui    at, $800b
80072924	sw     v0, $d088(at)
80072928	slti   v0, v0, $0041
8007292C	bne    v0, zero, L729b8 [$800729b8]
80072930	nop
80072934	j      L729b8 [$800729b8]
80072938	sh     zero, $0000(a0)

L7293c:	; 8007293C
8007293C	lui    v0, $800b
80072940	lw     v0, $d084(v0)
80072944	lui    at, $800b
80072948	sw     zero, $d088(at)
8007294C	andi   v0, v0, $0003
80072950	bne    v0, zero, L729a0 [$800729a0]
80072954	nop
80072958	lui    v1, $800b
8007295C	lw     v1, $ee58(v1)
80072960	nop
80072964	slti   v0, v1, $0009
80072968	bne    v0, zero, L72974 [$80072974]
8007296C	ori    v0, zero, $0008
80072970	addiu  v0, v1, $fffe (=-$2)

L72974:	; 80072974
80072974	lui    at, $800b
80072978	sw     v0, $ee58(at)
8007297C	lui    a0, $800b
80072980	addiu  a0, a0, $ee5c (=-$11a4)
80072984	lw     v1, $0000(a0)
80072988	nop
8007298C	slti   v0, v1, $0009
80072990	bne    v0, zero, L7299c [$8007299c]
80072994	ori    v0, zero, $0008
80072998	addiu  v0, v1, $fffe (=-$2)

L7299c:	; 8007299C
8007299C	sw     v0, $0000(a0)

L729a0:	; 800729A0
800729A0	lui    v0, $800b
800729A4	lw     v0, $d084(v0)
800729A8	nop
800729AC	addiu  v0, v0, $0001
800729B0	lui    at, $800b
800729B4	sw     v0, $d084(at)

L729b8:	; 800729B8
func71d78();



pc_entity_id = hu[800b1812];
struct_5c_p = w[800aefe4];
struct_138 = w[struct_5c_p + pc_entity_id * 5c + 4c];

[SP + 18] = w(w[struct_138 + 20]);
[SP + 1c] = w(w[struct_138 + 24]);
[SP + 20] = w(w[struct_138 + 28]);

A0 = SP + 18;
A1 = h[struct_138 + 72]; // current y pos
func720c8();

80072A3C	lui    v0, $800b
80072A40	lw     v0, $eeac(v0)
80072A44	nop
80072A48	andi   v0, v0, $4000
80072A4C	bne    v0, zero, L72aa0 [$80072aa0]
80072A50	addiu  v0, sp, $0028
80072A54	lui    a0, $800b
80072A58	lh     a0, $ed86(a0)
80072A5C	lui    a1, $800b
80072A60	lh     a1, $ed8e(a1)
80072A64	lui    a2, $800b
80072A68	lh     a2, $f028(a2)
80072A6C	addiu  a3, sp, $0038
80072A70	sw     v0, $0010(sp)
80072A74	jal    func7a7d8 [$8007a7d8]
80072A78	addiu  a2, a2, $ffff (=-$1)
80072A7C	lui    v0, $800b
80072A80	lh     v0, $ed8a(v0)
80072A84	lh     v1, $003a(sp)
80072A88	nop
80072A8C	slt    v0, v1, v0
80072A90	beq    v0, zero, L72aa0 [$80072aa0]
80072A94	sll    v0, v1, $10
80072A98	lui    at, $800b
80072A9C	sw     v0, $ed88(at)

L72aa0:	; 80072AA0
80072AA0	lui    s1, $800b
80072AA4	addiu  s1, s1, $ee08 (=-$11f8)
80072AA8	lh     v1, $0000(s1)
80072AAC	ori    v0, zero, $0002
80072AB0	bne    v1, v0, L72cdc [$80072cdc]
80072AB4	nop
80072AB8	lui    v1, $800b
80072ABC	lh     v1, $ed96(v1)
80072AC0	lui    a0, $800b
80072AC4	lh     a0, $ed66(a0)
80072AC8	lui    v0, $800b
80072ACC	lh     v0, $ed9e(v0)
80072AD0	lui    a1, $800b
80072AD4	lh     a1, $ed6e(a1)
80072AD8	subu   a0, v1, a0
80072ADC	jal    length_of_vector_by_x_y [$80099020]
80072AE0	subu   a1, v0, a1
80072AE4	addu   s0, v0, zero
80072AE8	lui    a2, $800b
80072AEC	lh     a2, $ed86(a2)
80072AF0	lui    a0, $800b
80072AF4	lh     a0, $ed56(a0)
80072AF8	lui    v1, $800b
80072AFC	lh     v1, $ed8e(v1)
80072B00	lui    a1, $800b
80072B04	lh     a1, $ed5e(a1)
80072B08	subu   a0, a2, a0
80072B0C	jal    length_of_vector_by_x_y [$80099020]
80072B10	subu   a1, v1, a1
80072B14	slti   s0, s0, $0080
80072B18	beq    s0, zero, L72cdc [$80072cdc]
80072B1C	slti   v0, v0, $0080
80072B20	beq    v0, zero, L72cdc [$80072cdc]
80072B24	nop
80072B28	j      L72cdc [$80072cdc]
80072B2C	sh     zero, $0000(s1)

L72b30:	; 80072B30
80072B30	lui    a3, $800b
80072B34	lhu    a3, $ee10(a3)
80072B38	lui    at, $800b
80072B3C	sw     zero, $d084(at)
80072B40	lui    at, $800b
80072B44	sw     zero, $d088(at)
80072B48	andi   v0, a3, $0001
80072B4C	beq    v0, zero, L72c0c [$80072c0c]
80072B50	nop
80072B54	lui    v0, $800b
80072B58	lh     v0, $ee12(v0)
80072B5C	nop
80072B60	beq    v0, zero, L72bbc [$80072bbc]
80072B64	addu   a2, v0, zero
80072B68	lui    v0, $800b
80072B6C	lw     v0, $ee14(v0)
80072B70	lui    v1, $800b
80072B74	lw     v1, $ee24(v1)
80072B78	lui    a0, $800b
80072B7C	lw     a0, $ee28(a0)
80072B80	lui    a1, $800b
80072B84	lw     a1, $ee2c(a1)
80072B88	addu   v0, v0, v1
80072B8C	lui    at, $800b
80072B90	sw     v0, $ee14(at)
80072B94	lui    v0, $800b
80072B98	lw     v0, $ee18(v0)

L72b9c:	; 80072B9C
80072B9C	lui    v1, $800b
80072BA0	lw     v1, $ee1c(v1)
80072BA4	addu   v0, v0, a0
80072BA8	addu   v1, v1, a1
80072BAC	lui    at, $800b
80072BB0	sw     v0, $ee18(at)
80072BB4	lui    at, $800b
80072BB8	sw     v1, $ee1c(at)

L72bbc:	; 80072BBC
80072BBC	addiu  v0, a2, $ffff (=-$1)
80072BC0	lui    at, $800b
80072BC4	sh     v0, $ee12(at)
80072BC8	sll    v0, v0, $10
80072BCC	bne    v0, zero, L72bdc [$80072bdc]
80072BD0	andi   v0, a3, $fffe
80072BD4	lui    at, $800b
80072BD8	sh     v0, $ee10(at)

L72bdc:	; 80072BDC
80072BDC	lui    v0, $800b
80072BE0	lw     v0, $ee14(v0)
80072BE4	lui    v1, $800b
80072BE8	lw     v1, $ee18(v1)
80072BEC	lui    a0, $800b
80072BF0	lw     a0, $ee1c(a0)
80072BF4	lui    at, $800b
80072BF8	sw     v0, $ed94(at)
80072BFC	lui    at, $800b
80072C00	sw     v1, $ed98(at)
80072C04	lui    at, $800b
80072C08	sw     a0, $ed9c(at)

L72c0c:	; 80072C0C
80072C0C	lui    t0, $800b
80072C10	addiu  t0, t0, $ee10 (=-$11f0)
80072C14	lhu    a3, $0000(t0)
80072C18	nop
80072C1C	andi   v0, a3, $0002
80072C20	beq    v0, zero, L72cdc [$80072cdc]
80072C24	nop
80072C28	lui    v0, $800b
80072C2C	lh     v0, $ee34(v0)
80072C30	nop
80072C34	beq    v0, zero, L72c90 [$80072c90]
80072C38	addu   a2, v0, zero
80072C3C	lui    v0, $800b
80072C40	lw     v0, $ee38(v0)
80072C44	lui    v1, $800b
80072C48	lw     v1, $ee48(v1)
80072C4C	lui    a0, $800b
80072C50	lw     a0, $ee4c(a0)
80072C54	lui    a1, $800b
80072C58	lw     a1, $ee50(a1)
80072C5C	addu   v0, v0, v1
80072C60	lui    at, $800b

L72c64:	; 80072C64
80072C64	sw     v0, $ee38(at)
80072C68	lui    v0, $800b
80072C6C	lw     v0, $ee3c(v0)
80072C70	lui    v1, $800b
80072C74	lw     v1, $ee40(v1)
80072C78	addu   v0, v0, a0
80072C7C	addu   v1, v1, a1
80072C80	lui    at, $800b
80072C84	sw     v0, $ee3c(at)
80072C88	lui    at, $800b
80072C8C	sw     v1, $ee40(at)

L72c90:	; 80072C90
80072C90	addiu  v0, a2, $ffff (=-$1)
80072C94	lui    at, $800b
80072C98	sh     v0, $ee34(at)
80072C9C	sll    v0, v0, $10
80072CA0	bne    v0, zero, L72cac [$80072cac]
80072CA4	andi   v0, a3, $fffd
80072CA8	sh     v0, $0000(t0)

L72cac:	; 80072CAC
80072CAC	lui    v0, $800b
80072CB0	lw     v0, $ee38(v0)
80072CB4	lui    v1, $800b
80072CB8	lw     v1, $ee3c(v1)
80072CBC	lui    a0, $800b
80072CC0	lw     a0, $ee40(a0)
80072CC4	lui    at, $800b
80072CC8	sw     v0, $ed84(at)
80072CCC	lui    at, $800b
80072CD0	sw     v1, $ed88(at)
80072CD4	lui    at, $800b
80072CD8	sw     a0, $ed8c(at)

L72cdc:	; 80072CDC
80072CDC	jal    func72404 [$80072404]
80072CE0	nop
80072CE4	lui    v1, $800b
80072CE8	addiu  v1, v1, $eeba (=-$1146)
80072CEC	lhu    v0, $0000(v1)
80072CF0	nop
80072CF4	andi   v0, v0, $0fff
80072CF8	sh     v0, $0000(v1)
////////////////////////////////



////////////////////////////////
// func71d78()
80071D7C	lui    a0, $800b
80071D80	lbu    a0, $eec8(a0)
80071D84	ori    v1, zero, $00ff
80071D8C	andi   v0, a0, $00ff
80071D90	beq    v0, v1, L72028 [$80072028]

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
////////////////////////////////



////////////////////////////////
// func720c8()
S0 = A0; // vector with +20 current position
S2 = A1; // current y pos [][]

[SP + 38] = w(w[S0 + 0]); // current x
[SP + 3c] = w(0);
[SP + 40] = w(w[S0 + 8]); // current z

A0 = SP + 38; // current x z and y = 0
A1 = SP + 10; // intersect line
A2 = SP + 28; // ret position curr and fin ( x z x z )
func7c394();

if( V0 == -1 ) // we found triangle
{
    // copy intersect line in format x z x z
    [SP + 20] = h(hu[SP + 10]);
    [SP + 22] = h(hu[SP + 14]);
    [SP + 24] = h(hu[SP + 18]);
    [SP + 26] = h(hu[SP + 1c]);

    A0 = SP + 20; // intersect line
    A1 = SP + 28; // change in pos if we outside bound
    A2 = SP + 30; // ret new pos
    func71a74();

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
// func71a74()
intersect_line = A0;
change_line = A1;
ret_addr = A2;

[SP + 30] = w(h[intersect_line + 4] - h[intersect_line + 0]);
[SP + 34] = w(0);
[SP + 38] = w(h[intersect_line + 6] - h[intersect_line + 2]);
A0 = SP + 30;
A1 = SP + 10;
system_normalize_word_vector_T0_T1_T2_to_word();

[SP + 30] = w(h[change_line + 4] - h[change_line + 0]);
[SP + 34] = w(0);
[SP + 38] = w(h[change_line + 6] - h[change_line + 2]);
A0 = SP + 30;
A1 = SP + 20;
system_normalize_word_vector_T0_T1_T2_to_word();

A0 = ( ( w[SP + 20] * w[SP + 18] ) - ( w[SP + 28] * w[SP + 10] ) ) >> c;

if( A0 == 0 )
{
    A0 = 0;
}
else
{
    A0 = (((h[change_line + 2] - h[intersect_line + 2]) * w[SP + 10]) - ((h[change_line + 0] - h[intersect_line + 0]) * w[SP + 18])) / A0;
}

[ret_addr + 0] = h(hu[change_line + 0] + ((A0 * w[SP + 20]) >> c));
[ret_addr + 2] = h(hu[change_line + 2] + ((A0 * w[SP + 28]) >> c));
////////////////////////////////



////////////////////////////////
// func7c394()
intersect_line = A1;
ret_addr = A2;

cur_x = h[A0 + 2]; // x
cur_z = h[A0 + a]; // z
cur_x_z = (cur_x << 10) + cur_z;

last_walkmesh_block = h[800af028] - 1;
triangle_data = w[800aeff8 + last_walkmesh_block * 4];
vertex_data = w[800af008 + last_walkmesh_block * 4];
material_data = w[800aeff4];

if( cur_x < h[800aeeb0] )
{
    fin_x = h[800aeeb0];
}
else if( ( h[800aeeb0] + h[800aeeb4] ) < cur_x )
{
    fin_x = h[800aeeb0] + h[800aeeb4];
}
else
{
    fin_x = cur_x;
}

if( cur_z > h[800aeeb2] )
{
    fin_z = h[800aeeb2];
}
else if( ( h[800aeeb2] + h[800aeeb6] ) > cur_z )
{
    fin_z = h[800aeeb2] + h[800aeeb6];
}
else
{
    fin_z = cur_z;
}

fin_x_z = (fin_x << 10) + fin_z;



A0 = fin_x; // x
A1 = fin_z; // y
A2 = last_walkmesh_block;
A3 = SP + 18; // ret normal
A4 = SP + 20; // ret position
func7a7d8(); // get triangle in which camera resides
triangle_id = V0;



T2 = 0;
L7c4c0:	; 8007C4C0
    V0 = h[triangle_data + triangle_id * e + 0];
    tri_A = (h[vertex_data + V0 * 8 + 0] << 10) + h[vertex_data + V0 * 8 + 4];

    V1 = h[triangle_data + triangle_id * e + 2];
    tri_B = (h[vertex_data + V1 * 8 + 0] << 10) + h[vertex_data + V1 * 8 + 4];

    V0 = h[triangle_data + triangle_id * e + 4];
    tri_C = (h[vertex_data + V0 * 8 + 0] << 10) + h[vertex_data + V0 * 8 + 4];

    A1 = 0;

    SXY0 = tri_A;
    SXY1 = tri_B;
    SXY2 = cur_x_z;
    gte_NCLIP();
    if( MAC0 < 0 )
    {
        A1 = A1 | 1;
    }

    SXY0 = tri_B;
    SXY1 = tri_C;
    SXY2 = cur_x_z;
    gte_NCLIP();
    if( MAC0 < 0 )
    {
        A1 = A1 | 2;
    }

    SXY0 = tri_C;
    SXY1 = tri_A;
    SXY2 = cur_x_z;
    gte_NCLIP();
    if( MAC0 < 0 )
    {
        A1 = A1 | 4;
    }

    switch( A1 )
    {
        case 0:
        {
            T2 = ff;
        }
        break;

        case 1:
        {
            triangle_id = h[triangle_data + triangle_id * e + 6];
        }
        break;

        case 2:
        {
            triangle_id = h[triangle_data + triangle_id * e + 8];
        }
        break;

        case 3:
        {
            SXY0 = tri_B;
            SXY1 = cur_x_x;
            SXY2 = fin_x_z;
            gte_NCLIP();
            if( MAC0 < 0 )
            {
                A1 = 2;
                triangle_id = h[triangle_data + triangle_id * e + 8];
            }
            else
            {
                A1 = 1;
                triangle_id = h[triangle_data + triangle_id * e + 6];
            }
       }
        break;

        case 4:
        {
            triangle_id = h[triangle_data + triangle_id * e + a];
        }
        break;

        case 5:
        {
            SXY0 = tri_A;
            SXY1 = cur_x_x;
            SXY2 = fin_x_z;
            gte_NCLIP();
            if( MAC0 < 0 )
            {
                A1 = 1;
                triangle_id = h[triangle_data + triangle_id * e + 6];
            }
            else
            {
                A1 = 4;
                triangle_id = h[triangle_data + triangle_id * e + a];
            }
        }
        break;

        case 6:
        {
            SXY0 = tri_C;
            SXY1 = cur_x_z;
            SXY2 = fin_x_z;
            gte_NCLIP();
            if( MAC0 < 0 )
            {
                A1 = 2;
                triangle_id = h[triangle_data + triangle_id * e + 8];
            }
            else
            {
                A1 = 4;
                triangle_id = h[triangle_data + triangle_id * e + a];
            }
        }
        break;

        case 7:
        {
            triangle_id = -1;
        }
    }



    material_id = bu[triangle_data + triangle_id * e + c];
    if( ( w[material_data + material_id * 4] & 00800000 ) == 0 )
    {
        triangle_id = -1;
        break;
    }

    if( triangle_id == -1 )
    {
        break;
    }

    T2 = T2 + 1;
    V0 = T2 < f0;
8007C74C	bne    v0, zero, L7c4c0 [$8007c4c0]



if( ( triangle_id != -1 ) && ( T2 != f0 ) )
{
    return 0;
}

if( A1 == 1 )
{
    V0 = h[triangle_data + triangle_id * e + 0];
    [intersect_line + 0] = h(hu[vertex_data + V0 * 8 + 0]);
    [intersect_line + 2] = h(hu[vertex_data + V0 * 8 + 2]);
    [intersect_line + 4] = h(hu[vertex_data + V0 * 8 + 4]);
    V0 = h[triangle_data + triangle_id * e + 2];
    [intersect_line + 8] = h(hu[vertex_data + V0 * 8 + 0]);
    [intersect_line + a] = h(hu[vertex_data + V0 * 8 + 2]);
    [intersect_line + c] = h(hu[vertex_data + V0 * 8 + 4]);
}
else if( A1 == 2 )
{
    V0 = h[triangle_data + triangle_id * e + 2];
    [intersect_line + 0] = h(hu[vertex_data + V0 * 8 + 0]);
    [intersect_line + 2] = h(hu[vertex_data + V0 * 8 + 2]);
    [intersect_line + 4] = h(hu[vertex_data + V0 * 8 + 4]);
    V0 = h[triangle_data + triangle_id * e + 4];
    [intersect_line + 8] = h(hu[vertex_data + V0 * 8 + 0]);
    [intersect_line + a] = h(hu[vertex_data + V0 * 8 + 2]);
    [intersect_line + c] = h(hu[vertex_data + V0 * 8 + 4]);
}
else if( A1 == 4 )
{
    V0 = h[triangle_data + triangle_id * e + 4];
    [intersect_line + 0] = h(hu[vertex_data + V0 * 8 + 0]);
    [intersect_line + 2] = h(hu[vertex_data + V0 * 8 + 2]);
    [intersect_line + 4] = h(hu[vertex_data + V0 * 8 + 4]);
    V0 = h[triangle_data + triangle_id * e + 0];
    [intersect_line + 8] = h(hu[vertex_data + V0 * 8 + 0]);
    [intersect_line + a] = h(hu[vertex_data + V0 * 8 + 2]);
    [intersect_line + c] = h(hu[vertex_data + V0 * 8 + 4]);
}

[ret_addr + 0] = h(cur_x);
[ret_addr + 2] = h(cur_z);
[ret_addr + 4] = h(fin_x);
[ret_addr + 6] = h(fin_z);

return -1;
////////////////////////////////
