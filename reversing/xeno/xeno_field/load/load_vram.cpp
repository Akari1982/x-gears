////////////////////////////////
// func74bdc
80074BDC	addiu  sp, sp, $ffd8 (=-$28)
80074BE0	ori    a0, zero, $0001
80074BE4	sw     ra, $0020(sp)
80074BE8	sw     s1, $001c(sp)
80074BEC	jal    func4b3f4 [$8004b3f4]
80074BF0	sw     s0, $0018(sp)
80074BF4	lui    at, $800b
80074BF8	sw     v0, $d074(at)
80074BFC	jal    func4b3f4 [$8004b3f4]
80074C00	addiu  a0, zero, $ffff (=-$1)
80074C04	jal    func73050 [$80073050]
80074C08	addu   s1, v0, zero
80074C0C	jal    func85f1c [$80085f1c]
80074C10	nop
80074C14	lui    v0, $800c
80074C18	lw     v0, $1b60(v0)
80074C1C	nop
80074C20	bne    v0, zero, L74c38 [$80074c38]
80074C24	ori    s0, zero, $80d4
80074C28	lui    a0, $8007
80074C2C	addiu  a0, a0, $f1c4 (=-$e3c)
80074C30	0C0A06C6	Ж...
80074C34	nop

L74c38:	; 80074C38
80074C38	lui    a0, $800c
80074C3C	lw     a0, $3740(a0)
80074C40	lui    a1, $800b
80074C44	lw     a1, $cfe0(a1)
80074C48	jal    func71344 [$80071344]
80074C4C	addu   a0, a0, s0
80074C50	lui    v0, $800c
80074C54	lw     v0, $1b60(v0)
80074C58	nop
80074C5C	bne    v0, zero, L74c74 [$80074c74]
80074C60	nop
80074C64	lui    a0, $8007
80074C68	addiu  a0, a0, $f1d0 (=-$e30)
80074C6C	0C0A06C6	Ж...
80074C70	nop

L74c74:	; 80074C74
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
80074CA0	nop
80074CA4	jal    funca8b60 [$800a8b60]
80074CA8	nop
80074CAC	lui    v0, $800c
80074CB0	lw     v0, $1b60(v0)
80074CB4	nop
80074CB8	bne    v0, zero, L74cc8 [$80074cc8]
80074CBC	nop
80074CC0	0C0A051A	....
80074CC4	nop

L74cc8:	; 80074CC8
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
80074CF8	lui    v0, $800c
80074CFC	lw     v0, $1b60(v0)
80074D00	nop
80074D04	bne    v0, zero, L74d24 [$80074d24]
80074D08	nop
80074D0C	0C0A0506	....
80074D10	nop
80074D14	lui    a0, $8007
80074D18	addiu  a0, a0, $f1dc (=-$e24)
80074D1C	0C0A06C6	Ж...
80074D20	nop

L74d24:	; 80074D24
80074D24	jal    func4b3f4 [$8004b3f4]
80074D28	ori    a0, zero, $0001
80074D2C	lui    at, $800b
80074D30	sw     v0, $d078(at)
80074D34	jal    func44448 [$80044448]
80074D38	addu   a0, zero, zero
80074D3C	jal    func7fc08 [$8007fc08]
80074D40	nop
80074D44	lui    a0, $800c
80074D48	lw     a0, $3740(a0)
80074D4C	lui    a1, $800b
80074D50	lw     a1, $cfe0(a1)
80074D54	jal    func7f660 [$8007f660]
80074D58	addu   a0, a0, s0
80074D5C	jal    func4b3f4 [$8004b3f4]
80074D60	addu   a0, zero, zero
80074D64	jal    func32adc [$80032adc]
80074D68	nop
80074D6C	lui    v0, $800b
80074D70	lw     v0, $d0f0(v0)

L74d74:	; 80074D74
80074D74	nop

L74d78:	; 80074D78
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
func24e3c;

80074E5C	lui    v0, $800c
80074E60	lw     v0, $1b60(v0)
80074E64	nop
80074E68	bne    v0, zero, L74e80 [$80074e80]
80074E6C	nop
80074E70	lui    a0, $8007
80074E74	addiu  a0, a0, $f1e8 (=-$e18)
80074E78	0C0A06C6	Ж...
80074E7C	nop

L74e80:	; 80074E80
80074E80	jal    func916ac [$800916ac]
80074E84	nop
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
80074EBC	lui    v0, $800c
80074EC0	lw     v0, $1b60(v0)
80074EC4	nop
80074EC8	bne    v0, zero, L74ee0 [$80074ee0]
80074ECC	nop
80074ED0	lui    a0, $8007
80074ED4	addiu  a0, a0, $f1f4 (=-$e0c)
80074ED8	0C0A06C6	Ж...
80074EDC	nop

L74ee0:	; 80074EE0
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
