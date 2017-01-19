////////////////////////////////
// func74958()
if( bu[800acfdd] == 1 )
{
    return;
}

S0 = 0;

A0 = w[800acfe0];
func24ed4(); // clear some set of images

[80058c08] = w(w[800c3740] + cc);

A0 = 800aef38;
func24dec(); // copy 0x20 bytes of data from gere to 8004f25c (matrix copy?)

func1d2e4(); // sprites texture and tile update by frame id.

func1c884();

func1c7f0();

A0 = w[800c3740] + cc;
A1 = w[800acfe0];
func751d4();

800749D8	lui    v0, $800b
800749DC	lw     v0, $d0d4(v0)
if( V0 > 0 )
{
    800749EC	addu   s1, zero, zero

    loop749f0:	; 800749F0
        800749F0	lui    v0, $800b
        800749F4	lw     v0, $efe4(v0)
        800749F8	nop
        800749FC	addu   a1, s1, v0
        80074A00	lw     v0, $0058(a1)
        80074A04	ori    v1, zero, $0040
        80074A08	andi   v0, v0, $0060
        80074A0C	bne    v0, v1, L74a54 [$80074a54]
        80074A10	lui    v1, $0100
        80074A14	lw     a2, $004c(a1)
        80074A18	nop
        80074A1C	lw     a0, $0004(a2)
        80074A20	ori    v0, zero, $0200
        80074A24	andi   v1, a0, $0600
        80074A28	beq    v1, v0, L74a7c [$80074a7c]
        80074A2C	andi   v0, a0, $1000
        80074A30	bne    v0, zero, L74a7c [$80074a7c]
        80074A34	nop
        80074A38	lw     v0, $0000(a2)
        80074A3C	nop
        80074A40	andi   v0, v0, $0001
        80074A44	beq    v0, zero, L74a70 [$80074a70]
        80074A48	nop
        80074A4C	j      L74a7c [$80074a7c]
        80074A50	nop

        L74a54:	; 80074A54
        80074A54	lw     v0, $004c(a1)
        80074A58	nop
        80074A5C	lw     v0, $0004(v0)
        80074A60	nop
        80074A64	and    v0, v0, v1
        80074A68	beq    v0, zero, L74a7c [$80074a7c]
        80074A6C	nop

        L74a70:	; 80074A70
        A0 = w[A1 + 4];
        func23090(); // update sprite script and animation

        L74a7c:	; 80074A7C
        80074A7C	lui    v0, $800b
        80074A80	lw     v0, $d0d4(v0)
        80074A90	addiu  s1, s1, $005c
        80074A84	addiu  s0, s0, $0001
        80074A88	slt    v0, s0, v0
    80074A8C	bne    v0, zero, loop749f0 [$800749f0]
}

A0 = w[800c3740] + cc;
A1 = w[800acfe0];
80074AA4	jal    func75b44 [$80075b44]

if( w[800c1b60] == 0 )
{
    A0 = 8006f1b8; // CHAR
    80074AC8	0C0A06C6	Ж...
}
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
800730F8	subu   a1, v0, a1
system_get_rotation_based_on_vector_x_y();

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
80073130	sra    a1, a1, $10
length_of_vector_by_x_y();

80073134	lui    a1, $800b
80073138	lw     a1, $ed68(a1)
8007313C	lui    v1, $800b
80073140	lw     v1, $ed58(v1)
80073144	addu   a0, v0, zero
80073148	subu   a1, a1, v1
80073150	sra    a1, a1, $10
system_get_rotation_based_on_vector_x_y();

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



////////////////////////////////
// func74bdc()
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

func74958(); // update sprite

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

A0 = 0;
system_draw_sync();

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
80074DEC	sll    a2, a2, $08
system_move_image();

80074DF0	j      L74e10 [$80074e10]
80074DF4	nop

L74df8:	; 80074DF8
80074DF8	addu   a2, zero, zero
80074DFC	lui    a0, $800c
80074E00	lw     a0, $3740(a0)
80074E04	addu   a3, zero, zero

L74e08:	; 80074E08
80074E0C	addiu  a0, a0, $005c
system_clear_image();

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
system_load_image();

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
// func751d4()
S5 = A0;

scruct_5c_p = w[800aefe4];



[SP + b0] = w((7 - ((h[800aee60] - 100) >> 9)) & 7);



A0 = SP + 70;
A1 = 800aee84;
func7372c(); // copy A1 to A0



[SP + a8] = w(h[800aeed0]);



[SP + 18] = h(0);
[SP + 1a] = h(0 - ((h[800aeed0] / 3) * 2));
[SP + 1c] = h(0);



number_of_entity = w[800ad0d4];
if( number_of_entity > 0 )
{
    S6 = 0;
    FP = SP + 30;
    S3 = 801e8670;
    S7 = 0;

    L75284:	; 80075284
        struct_5c = scruct_5c_p + S6 * 5c;
        T0 = hu[struct_5c + 58];

        // model or sprite loaded
        if( hu[struct_5c + 58] & 0040 )
        {
            S1 = w[struct_5c + 4c];
            S2 = w[struct_5c + 4];

            [struct_5c + 2c] = w(w[struct_5c + c]);
            [struct_5c + 30] = w(w[struct_5c + 10]);
            [struct_5c + 34] = w(w[struct_5c + 14]);
            [struct_5c + 38] = w(w[struct_5c + 18]);
            [struct_5c + 3c] = w(w[struct_5c + 1c]);
            [struct_5c + 40] = w(w[struct_5c + 20]);
            [struct_5c + 44] = w(w[struct_5c + 24]);
            [struct_5c + 48] = w(w[struct_5c + 28]);

            if( ( w[S1 + 4] & 00002000 ) == 0 )
            {
                R11R12 = w[800aef38 + 0];
                R13R21 = w[800aef38 + 4];
                R22R23 = w[800aef38 + 8];
                R31R32 = w[800aef38 + c];
                R33 = w[800aef38 + 10];
                IR1 = hu[scruct_5c_p + S6 * 5c + c];
                IR2 = hu[scruct_5c_p + S6 * 5c + 12];
                IR3 = hu[scruct_5c_p + S6 * 5c + 18];
                gte_rtir12(); // ir * rotmatrix
                [SP + 30] = h(IR1);
                [SP + 36] = h(IR2);
                [SP + 3c] = h(IR3);

                IR1 = hu[scruct_5c_p + S6 * 5c + e];
                IR2 = hu[scruct_5c_p + S6 * 5c + 14];
                IR3 = hu[scruct_5c_p + S6 * 5c + 1a];
                gte_rtir12(); // ir * rotmatrix
                [SP + 32] = h(IR1);
                [SP + 38] = h(IR2);
                [SP + 3e] = h(IR3);

                IR1 = hu[scruct_5c_p + S6 * 5c + 10];
                IR2 = hu[scruct_5c_p + S6 * 5c + 16];
                IR3 = hu[scruct_5c_p + S6 * 5c + 1c];
                gte_rtir12(); // ir * rotmatrix
                [SP + 34] = h(IR1);
                [SP + 3a] = h(IR2);
                [SP + 40] = h(IR3);

                TRX = w[800aef38 + 14];
                TRY = w[800aef38 + 18];
                TRX = w[800aef38 + 1c];
                VXY0 = (hu[scruct_5c_p + S6 * 5c + 24] << 10) | hu[scruct_5c_p + S6 * 5c + 20];
                VZ0 = w[scruct_5c_p + S6 * 5c + 28];
                gte_rtv0tr(); // v0 * rotmatrix + tr vector
                [SP + 44] = w(MAC1);
                [SP + 48] = w(MAC2);
                [SP + 4c] = w(MAC3);

                R11R12 = w[SP + 30];
                R13R21 = w[SP + 34];
                R22R23 = w[SP + 38];
                R31R32 = w[SP + 3c];
                R33 = w[SP + 40];
                TRX = w[SP + 44];
                TRY = w[SP + 48];
                TRZ = w[SP + 4c];
                VXY0 = w[SP + 18];
                VZ0 = w[SP + 1c];
                gte_RTPS(); // Perspective transform
                [SP + 98] = w(SXY2);
                [SP + 9c] = w(IR0);
                [SP + a0] = w(FLAG);
                [SP + a4] = w(SZ3 >> 2);

                V1 = (w[SP + 98] >> 10) + 9;
                V0 = ((w[SP + 98] << 10) >> 10) + 27;

                if( ( V1 >= 143 ) || ( V0 >= 18f ) )
                {
                    [S1 + 4] = w(w[S1 + 4] | 00000200);
                }
                else
                {
                    [S1 + 4] = w(w[S1 + 4] & fffffdff);
                }

                V0 = w[8004ea20];
                8007556C	bne    v0, zero, L75af8 [$80075af8]
                80075570	andi   v0, t0, $0020
                80075574	bne    v0, zero, L75af8 [$80075af8]
                80075578	nop
                8007557C	lw     v0, $00a0(sp)
                80075580	nop
                80075584	bltz   v0, L75af8 [$80075af8]

                A2 = (h[S1 + f4] * 3) / 4;
                [SP + 20] = w(A2);

                A1 = (h[S1 + f6] * 3) / 4;
                [SP + 24] = w(A1);

                A0 = (h[S1 + f8] * 3) / 4;
                [SP + 28] = w(A0);

                if( h[S1 + e4] == 7 )
                {
                    if( w[800b173c] != 0 )
                    {
                        [SP + 20] = w((A2 * 5) / 4);
                        [SP + 24] = w((A1 * 5) / 4);
                        [SP + 28] = w((A0 * 5) / 4);
                    }
                }

                V0 = w[S2 + 20];
                [V0 + c] = w(w[SP + 70]);
                [V0 + 10] = w(w[SP + 74]);
                [V0 + 14] = w(w[SP + 78]);
                [V0 + 18] = w(w[SP + 7c]);
                [V0 + 1c] = w(w[SP + 80]);
                [V0 + 20] = w(w[SP + 84]);
                [V0 + 24] = w(w[SP + 88]);
                [V0 + 28] = w(w[SP + 8c]);

                A0 = w[S2 + 20] + c;
                A1 = SP + 20;
                80075670	jal    func49c74 [$80049c74]

                V0 = w[scruct_5c_p + S6 * 5c + 4c];
                80075690	lw     v1, $0014(v0)
                80075694	lui    v0, $0020
                80075698	and    v0, v1, v0
                if( V0 != 0 )
                {
                    800756A0	srl    v0, v1, $0b
                    800756A4	addiu  v0, v0, $fffe (=-$2)
                    800756A8	lw     t1, $00b0(sp)
                    800756AC	andi   v0, v0, $0007
                    800756B0	subu   v0, t1, v0
                    800756B4	andi   v1, v0, $0007
                    if( V1 != 0 )
                    {
                        if( V1 < 4 )
                        {
                            [SP + 10] = h(0);
                            [SP + 12] = h(-80);
                            [SP + 14] = h(0);

                            A0 = SP + 10;
                            A1 = SP + 98;
                            A2 = SP + 9c;
                            A3 = SP + a0;
                            system_gte_vector_perspective_transform();
                            [SP + a4] = w(V0);
                        }
                        else if( ( V1 >= 5 ) && ( V1 < 8 ) )
                        {
                            [SP + 10] = h(0);
                            [SP + 12] = h(80);
                            [SP + 14] = h(0);

                            A0 = SP + 10;
                            A1 = SP + 98;
                            A2 = SP + 9c;
                            A3 = SP + a0;
                            system_gte_vector_perspective_transform();
                            [SP + a4] = w(V0);
                        }
                    }
                }



                if( bu[800b182b] == 0 )
                {
                    if( h[800b1662] != 0 )
                    {
                        RGB = w[80058c34];
                        gte_DPCS(); // Depth Cueing.
                        [SP + 90] = w(RGB2);

                        A0 = w[scruct_5c_p + S6 * 5c + 4];
                        A1 = bu[SP + 90];
                        A2 = bu[SP + 91];
                        A3 = bu[SP + 92];
                        80075778	jal    func219e0 [$800219e0]
                    }
                }



                80075780	lw     v0, $00a4(sp)
                80075784	lui    v1, $8005
                80075788	lw     v1, $f7a4(v1)
                8007578C	nop
                80075790	srav   v1, v1, v0
                80075794	slti   v0, v1, $0002
                80075798	bne    v0, zero, L757a8 [$800757a8]
                8007579C	sw     v1, $00a4(sp)
                800757A0	addiu  v0, v1, $fffe (=-$2)
                800757A4	sw     v0, $00a4(sp)

                L757a8:	; 800757A8
                800757A8	lhu    v0, $00e8(s1)
                800757AC	nop
                800757B0	addiu  v0, v0, $0022
                800757B4	andi   v0, v0, $ffff
                800757B8	sltiu  v0, v0, $0002
                800757BC	beq    v0, zero, L75870 [$80075870]
                800757C0	lui    v1, $0200
                800757C4	lw     v0, $0004(s1)
                800757C8	nop
                800757CC	and    v0, v0, v1
                800757D0	bne    v0, zero, L75af8 [$80075af8]
                800757D4	nop
                800757D8	lbu    a1, $00fc(s1)
                800757DC	lbu    a2, $00fd(s1)
                800757E0	lbu    a3, $00fe(s1)
                800757E4	jal    func219e0 [$800219e0]
                800757E8	addu   a0, s2, zero
                800757EC	ori    v0, zero, $00ef
                800757F0	sb     v0, $003d(s2)
                800757F4	lw     a1, $00a4(sp)
                800757F8	addu   a0, s2, zero
                800757FC	sll    a1, a1, $02
                80075800	addu   a1, s5, a1
                80075804	jal    func1e130 [$8001e130]
                80075808	addiu  a1, a1, $ffc0 (=-$40)
                8007580C	addiu  a0, sp, $0010
                80075810	addiu  a1, sp, $0098
                80075814	addiu  a2, sp, $009c
                80075818	addiu  a3, sp, $00a0
                8007581C	ori    v0, zero, $012c
                80075820	sh     zero, $0010(sp)
                80075824	sh     v0, $0012(sp)
                8007582C	sh     zero, $0014(sp)
                system_gte_vector_perspective_transform();

                80075830	addu   a0, s2, zero
                80075834	lbu    a1, $00ff(s1)
                80075838	lbu    a2, $0100(s1)
                8007583C	lui    v1, $8005
                80075840	lw     v1, $f7a4(v1)
                80075844	lbu    a3, $0101(s1)
                80075848	jal    func219e0 [$800219e0]
                8007584C	srav   s0, v1, v0
                80075850	addu   a0, s2, zero
                80075854	sll    a1, s0, $02
                80075858	addu   a1, s5, a1
                8007585C	ori    v0, zero, $00f7
                80075860	jal    func1e130 [$8001e130]
                80075864	sb     v0, $003d(a0)
                80075868	j      L75af8 [$80075af8]
                8007586C	nop

                L75870:	; 80075870
                80075870	sb     zero, $003d(s2)
                80075874	lw     v0, $0004(s1)
                80075878	nop
                8007587C	and    v0, v0, v1
                80075880	bne    v0, zero, L75af8 [$80075af8]
                80075884	nop
                80075888	lw     v1, $0134(s1)
                8007588C	nop
                80075890	andi   v0, v1, $0060
                80075894	bne    v0, zero, L758c4 [$800758c4]
                80075898	srl    v0, v1, $05
                8007589C	addu   a0, s2, zero
                800758A0	jal    func75198 [$80075198]
                800758A4	addiu  a1, s1, $00fc
                800758A8	lw     a1, $00a4(sp)
                800758AC	addu   a0, s2, zero
                800758B0	sll    a1, a1, $02
                800758B4	jal    func1e130 [$8001e130]
                800758B8	addu   a1, s5, a1
                800758BC	j      L75af8 [$80075af8]
                800758C0	nop

                L758c4:	; 800758C4
                800758C4	andi   v0, v0, $0001
                800758C8	beq    v0, zero, L75950 [$80075950]
                800758CC	addu   a0, s2, zero
                800758D0	jal    func75198 [$80075198]
                800758D4	addiu  a1, s1, $00fc
                800758D8	lui    v0, $5555
                800758DC	lw     t1, $00a8(sp)
                800758E0	ori    v0, v0, $5556
                800758E4	mult   t1, v0
                800758E8	addiu  a0, sp, $0010
                800758EC	addiu  a1, sp, $0098
                800758F0	addiu  a2, sp, $009c
                800758F4	sh     zero, $0010(sp)
                800758F8	lh     v1, $00ee(s1)
                800758FC	addiu  a3, sp, $00a0
                80075900	sh     zero, $0014(sp)
                80075904	sra    v0, t1, $1f
                80075908	mfhi   t1
                8007590C	subu   v0, t1, v0
                80075910	subu   v1, v1, v0
                80075914	sll    v1, v1, $01
                8007591C	sh     v1, $0012(sp)
                system_gte_vector_perspective_transform();

                80075920	lui    v1, $8005
                80075924	lw     v1, $f7a4(v1)
                80075928	nop
                8007592C	srav   s0, v1, v0
                80075930	slti   v0, s0, $0002
                80075934	bne    v0, zero, L75940 [$80075940]
                80075938	addu   a0, s2, zero
                8007593C	addiu  s0, s0, $fffe (=-$2)

                L75940:	; 80075940
                80075940	lh     a2, $00ee(s1)
                80075944	sll    a1, s0, $02
                80075948	jal    func1e18c [$8001e18c]
                8007594C	addu   a1, s5, a1

                L75950:	; 80075950
                80075950	lw     v0, $0134(s1)
                80075954	nop
                80075958	srl    v0, v0, $05
                8007595C	andi   v0, v0, $0002
                80075960	beq    v0, zero, L75af8 [$80075af8]
                80075964	addu   a0, s2, zero
                80075968	jal    func75198 [$80075198]
                8007596C	addiu  a1, s1, $00ff
                80075970	addu   a0, s2, zero
                80075974	lw     a1, $00a4(sp)
                80075978	lh     a2, $00ee(s1)
                8007597C	sll    a1, a1, $02
                80075980	jal    func1e1f8 [$8001e1f8]
                80075984	addu   a1, s5, a1
                80075988	j      L75af8 [$80075af8]
                8007598C	nop
            }

            80075990	lui    v0, $8005
            80075994	lw     v0, $ea24(v0)
            80075998	nop
            8007599C	bne    v0, zero, L75af8 [$80075af8]
            800759A0	lui    v1, $0001
            800759A4	lw     v0, $0000(s1)
            800759A8	nop
            800759AC	and    v0, v0, v1
            800759B0	bne    v0, zero, L759f4 [$800759f4]
            800759B4	lui    v1, $0020
            800759B8	lw     v0, $0014(s1)
            800759BC	ori    v1, v1, $0002
            800759C0	and    v0, v0, v1
            800759C4	bne    v0, zero, L759f4 [$800759f4]
            800759C8	nop
            800759CC	lw     v0, $0004(s1)
            800759D0	nop
            800759D4	andi   v0, v0, $0800
            800759D8	bne    v0, zero, L759f4 [$800759f4]
            800759DC	nop
            800759E0	lw     v1, $0000(s3)
            800759E4	nop
            800759E8	lhu    v0, $004a(v1)
            800759EC	j      L75a08 [$80075a08]
            800759F0	andi   v0, v0, $fffe

            L759f4:	; 800759F4
            800759F4	lw     v1, $0000(s3)
            800759F8	nop
            800759FC	lhu    v0, $004a(v1)
            80075A00	nop
            80075A04	ori    v0, v0, $0001

            L75a08:	; 80075A08
            80075A08	sh     v0, $004a(v1)
            80075A0C	andi   v0, t0, $0020
            80075A10	bne    v0, zero, L75a24 [$80075a24]
            80075A14	ori    v0, zero, $0001
            80075A18	lw     v1, $0000(s3)
            80075A1C	j      L75a30 [$80075a30]
            80075A20	sb     v0, $0034(v1)

            L75a24:	; 80075A24
            80075A24	lw     v0, $0000(s3)
            80075A28	nop
            80075A2C	sb     zero, $0034(v0)

            L75a30:	; 80075A30
            80075A30	lw     v0, $0004(s1)
            80075A34	lui    v1, $0002
            80075A38	and    v0, v0, v1
            if( V0 == 0 )
            {
                80075A44	lw     v0, $0000(s3)
                80075A48	lhu    v1, $0108(s1)
                80075A4C	lw     v0, $0004(v0)
                80075A50	addiu  v1, v1, $0c00
                80075A58	sh     v1, $0056(v0)
            }
            else
            {
                V0 = w[S3];
                V0 = w[V0 + 4];
                V0 = hu[V0 + 56] - c00;
                [S1 + 106] = h(V0);
                [S1 + 108] = h(V0);
            }

            V1 = h[S1 + f4];
            V0 = w[800b16e0 + S7];
            T1 = V1 * V0;
            80075A98	lw     v1, $0000(s3)
            80075AA0	sra    v0, t1, $0c
            80075AA4	sh     v0, $001c(v1)
            80075AA8	lw     v1, $0000(s3)
            80075AAC	lh     v0, $0026(s1)
            80075AB0	nop
            80075AB4	sh     v0, $0060(v1)
            80075AB8	lw     v0, $0000(s3)
            80075ABC	nop
            80075AC0	lw     v1, $0004(v0)
            80075AC4	lh     v0, $0022(s1)
            80075AC8	nop
            80075ACC	sw     v0, $005c(v1)
            80075AD0	lw     v0, $0000(s3)
            80075AD4	addiu  s7, s7, $0004
            80075AD8	lw     v1, $0004(v0)
            80075ADC	lh     v0, $002a(s1)
            80075AE0	addiu  s3, s3, $0004
            80075AE4	sw     v0, $0064(v1)
            80075AE8	lw     v0, $0004(s1)
            80075AEC	addiu  v1, zero, $fdff (=-$201)
            80075AF0	and    v0, v0, v1
            80075AF4	sw     v0, $0004(s1)
        }

        L75af8:	; 80075AF8
        S6 = S6 + 1;
        V0 = S6 < number_of_entity;
    80075B08	bne    v0, zero, L75284 [$80075284]
}
////////////////////////////////



////////////////////////////////
// func7372c()
[A0 + 0] = h(hu[A1 + 0]);
[A0 + 2] = h(hu[A1 + 2]);
[A0 + 4] = h(hu[A1 + 4]);
[A0 + 6] = h(hu[A1 + 6]);
[A0 + 8] = h(hu[A1 + 8]);
[A0 + a] = h(hu[A1 + a]);
[A0 + c] = h(hu[A1 + c]);
[A0 + e] = h(hu[A1 + e]);
[A0 + 10] = h(hu[A1 + 10]);
////////////////////////////////
