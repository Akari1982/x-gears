////////////////////////////////
// func7ae28
8007AE30	addu   s1, a0, zero
8007AE38	addu   s3, a1, zero
8007AE40	addu   s4, a2, zero
8007AE48	addu   s2, a3, zero
8007AE50	andi   s0, s2, $0fff
8007AE54	addu   a0, s0, zero
system_cos; // cos

8007AE6C	addu   a0, s0, zero
8007AE70	lw     v1, $0000(s1)
8007AE74	sll    v0, v0, $06
8007AE78	addu   v1, v1, v0
8007AE80	sw     v1, $0018(sp)
system_sin; // sin

8007AE84	addiu  a0, sp, $0018
8007AE88	addiu  s6, s3, $0020
8007AE8C	addu   a1, s6, zero
8007AE90	addu   a2, s3, zero
8007AE94	addu   a3, s4, zero
8007AE98	sll    v0, v0, $06
8007AE9C	addiu  s5, sp, $0028
8007AEA0	lw     v1, $0008(s1)
8007AEA4	addiu  s7, zero, $ffff (=-$1)
8007AEA8	subu   v1, v1, v0
8007AEAC	sw     v1, $0020(sp)
8007AEB0	sw     s5, $0010(sp)
8007AEB4	jal    func7bca8 [$8007bca8]
8007AEB8	sw     s7, $0014(sp)
8007AEBC	bne    v0, s7, L7aed0 [$8007aed0]
8007AEC0	sll    v0, s2, $10
8007AEC4	sll    a0, s2, $10
8007AEC8	j      L7af8c [$8007af8c]
8007AECC	sra    a0, a0, $10

L7aed0:	; 8007AED0
8007AED0	sra    s2, v0, $10
8007AED4	addiu  s0, s2, $ff00 (=-$100)
8007AED8	andi   s0, s0, $0fff
8007AEE0	addu   a0, s0, zero
system_cos; // cos

8007AEE4	addu   a0, s0, zero
8007AEE8	lw     v1, $0000(s1)
8007AEEC	sll    v0, v0, $06
8007AEF0	addu   v1, v1, v0
8007AEF8	sw     v1, $0018(sp)
system_sin; // sin

8007AEFC	addiu  a0, sp, $0018
8007AF00	addu   a1, s6, zero
8007AF04	addu   a2, s3, zero
8007AF08	addu   a3, s4, zero
8007AF0C	lw     v1, $0008(s1)
8007AF10	sll    v0, v0, $06
8007AF14	subu   v1, v1, v0
8007AF18	sw     v1, $0020(sp)
8007AF1C	sw     s5, $0010(sp)
8007AF20	jal    func7bca8 [$8007bca8]
8007AF24	sw     s7, $0014(sp)
8007AF28	beq    v0, s7, L7af88 [$8007af88]
8007AF2C	addiu  s0, s2, $0100
8007AF30	andi   s0, s0, $0fff
8007AF38	addu   a0, s0, zero
system_cos; // cos

8007AF3C	addu   a0, s0, zero
8007AF40	lw     v1, $0000(s1)
8007AF44	sll    v0, v0, $06
8007AF48	addu   v1, v1, v0
8007AF50	sw     v1, $0018(sp)
system_sin; // sin

8007AF54	addiu  a0, sp, $0018
8007AF58	addu   a1, s6, zero
8007AF5C	addu   a2, s3, zero
8007AF60	addu   a3, s4, zero
8007AF64	lw     v1, $0008(s1)
8007AF68	sll    v0, v0, $06
8007AF6C	subu   v1, v1, v0
8007AF70	sw     v1, $0020(sp)
8007AF74	sw     s5, $0010(sp)
8007AF78	jal    func7bca8 [$8007bca8]
8007AF7C	sw     s7, $0014(sp)
8007AF80	bne    v0, s7, L7afbc [$8007afbc]
8007AF84	addiu  a0, sp, $0018

L7af88:	; 8007AF88
8007AF88	addu   a0, s2, zero

L7af8c:	; 8007AF8C
8007AF8C	lw     v0, $0000(s1)
8007AF90	addu   a1, s4, zero
8007AF94	sw     v0, $0018(sp)
8007AF98	lw     v0, $0004(s1)
8007AF9C	addiu  a2, sp, $0018
8007AFA0	sw     v0, $001c(sp)
8007AFA4	lw     v0, $0008(s1)
8007AFA8	addu   a3, zero, zero
8007AFB0	sw     v0, $0020(sp)
field_get_move_vector_to_move_along_with_line;

8007AFB4	j      L7afe0 [$8007afe0]
8007AFB8	addiu  a0, sp, $0018

L7afbc:	; 8007AFBC
8007AFBC	lw     v0, $0000(s1)
8007AFC0	nop
8007AFC4	sw     v0, $0018(sp)
8007AFC8	lw     v0, $0004(s1)
8007AFCC	nop
8007AFD0	sw     v0, $001c(sp)
8007AFD4	lw     v0, $0008(s1)
8007AFD8	nop
8007AFDC	sw     v0, $0020(sp)

L7afe0:	; 8007AFE0
8007AFE0	addiu  a1, s3, $0020
8007AFE4	addu   a2, s3, zero
8007AFE8	addu   a3, s4, zero
8007AFEC	addiu  v0, sp, $0028
8007AFF0	sw     v0, $0010(sp)
8007AFF4	jal    func7bca8 [$8007bca8]
8007AFF8	sw     zero, $0014(sp)
8007AFFC	addiu  v1, zero, $ffff (=-$1)
8007B000	beq    v0, v1, L7b048 [$8007b048]
8007B004	lui    v1, $0004
8007B008	lw     v0, $0000(s3)
8007B00C	nop
8007B010	and    v0, v0, v1
8007B014	bne    v0, zero, L7b050 [$8007b050]
8007B018	nop
8007B01C	lh     v0, $002a(sp)
8007B020	lw     v1, $0024(s3)
8007B024	sll    v0, v0, $10
8007B028	slt    v0, v0, v1
8007B02C	beq    v0, zero, L7b05c [$8007b05c]
8007B030	nop
8007B034	lui    v0, $800b
8007B038	lw     v0, $d070(v0)
8007B03C	nop
8007B040	bne    v0, zero, L7b05c [$8007b05c]
8007B044	nop

L7b048:	; 8007B048
8007B048	j      L7b0a4 [$8007b0a4]
8007B04C	addiu  v0, zero, $ffff (=-$1)

L7b050:	; 8007B050
8007B050	lhu    v0, $00ec(s3)
8007B054	nop
8007B058	sh     v0, $002a(sp)

L7b05c:	; 8007B05C
8007B05C	lh     v0, $002a(sp)
8007B060	lw     v1, $0024(s3)
8007B064	lw     a0, $0018(sp)
8007B068	sll    v0, v0, $10
8007B06C	subu   v0, v0, v1
8007B070	sw     v0, $001c(sp)
8007B074	sw     a0, $0000(s1)
8007B078	lw     v0, $001c(sp)
8007B07C	nop
8007B080	sw     v0, $0004(s1)
8007B084	lw     v0, $0020(sp)
8007B088	lw     a0, $0004(s1)
8007B08C	sw     v0, $0008(s1)
8007B090	lw     v1, $0024(s3)
8007B094	addu   v0, zero, zero
8007B098	addu   v1, v1, a0
8007B09C	sra    v1, v1, $10
8007B0A0	sh     v1, $0072(s3)

L7b0a4:	; 8007B0A4
////////////////////////////////



////////////////////////////////
// func7bca8
8007BCA8	addiu  sp, sp, $ff80 (=-$80)
8007BCAC	addu   t1, a0, zero
8007BCB0	addu   t0, a1, zero
8007BCB4	sw     ra, $007c(sp)
8007BCB8	sw     fp, $0078(sp)
8007BCBC	sw     s7, $0074(sp)
8007BCC0	sw     s6, $0070(sp)
8007BCC4	sw     s5, $006c(sp)
8007BCC8	sw     s4, $0068(sp)
8007BCCC	sw     s3, $0064(sp)
8007BCD0	sw     s2, $0060(sp)
8007BCD4	sw     s1, $005c(sp)
8007BCD8	sw     s0, $0058(sp)
8007BCDC	sw     a2, $0028(sp)
8007BCE0	lh     v0, $0010(a2)
8007BCE4	nop
8007BCE8	sll    v1, v0, $01
8007BCEC	addu   v1, v1, a2
8007BCF0	sll    v0, v0, $02
8007BCF4	lh     s0, $0008(v1)
8007BCF8	addiu  v1, zero, $ffff (=-$1)
8007BCFC	lui    at, $800b
8007BD00	addu   at, at, v0
8007BD04	lw     s5, $eff8(at)
8007BD08	lui    at, $800b
8007BD0C	addu   at, at, v0
8007BD10	lw     s6, $f008(at)
8007BD14	bne    s0, v1, L7bd2c [$8007bd2c]
8007BD18	addu   s7, a3, zero
8007BD1C	j      L7c31c [$8007c31c]
8007BD20	addiu  v0, zero, $ffff (=-$1)

L7bd24:	; 8007BD24
8007BD24	j      L7c044 [$8007c044]
8007BD28	addiu  s0, zero, $ffff (=-$1)

L7bd2c:	; 8007BD2C
8007BD2C	lw     a1, $0000(t0)
8007BD30	lw     v1, $0000(t1)
8007BD34	lw     a3, $0008(t0)
8007BD38	lw     a0, $0008(t1)
8007BD3C	lw     t2, $0090(sp)
8007BD40	addu   v1, a1, v1
8007BD44	sra    v1, v1, $10
8007BD48	sh     v1, $0000(t2)
8007BD4C	sll    v1, v1, $10
8007BD50	addu   a0, a3, a0
8007BD54	sra    a0, a0, $10
8007BD58	addu   fp, v1, a0
8007BD5C	sra    a1, a1, $10
8007BD60	sll    a1, a1, $10
8007BD64	lw     v0, $0008(t0)
8007BD68	lw     a2, $0008(t1)
8007BD6C	sra    a3, a3, $10
8007BD70	sw     zero, $0038(sp)
8007BD74	sh     zero, $0002(t2)
8007BD78	addu   v0, v0, a2
8007BD7C	sra    v0, v0, $10
8007BD80	sh     v0, $0004(t2)
8007BD84	lw     t2, $0028(sp)
8007BD88	addu   a1, a1, a3
8007BD8C	sw     a1, $0040(sp)
8007BD90	lh     v1, $0010(t2)
8007BD94	lw     v0, $0004(t2)
8007BD98	addiu  v1, v1, $0003
8007BD9C	srlv   v0, v1, v0
8007BDA0	andi   v0, v0, $0001
8007BDA4	bne    v0, zero, L7bdc4 [$8007bdc4]
8007BDA8	nop
8007BDAC	lui    v0, $800b
8007BDB0	lbu    v0, $16a0(v0)
8007BDB4	nop
8007BDB8	sltiu  v0, v0, $0001
8007BDBC	subu   v0, zero, v0
8007BDC0	sw     v0, $0038(sp)

L7bdc4:	; 8007BDC4
8007BDC4	sw     zero, $0048(sp)

L7bdc8:	; 8007BDC8
8007BDC8	sw     s0, $0030(sp)
8007BDCC	sll    a1, s0, $03
8007BDD0	subu   a1, a1, s0
8007BDD4	sll    a1, a1, $01
8007BDD8	addu   a1, a1, s5
8007BDDC	lh     v0, $0000(a1)
8007BDE0	addu   a2, fp, zero
8007BDE4	sll    v0, v0, $03
8007BDE8	addu   v0, v0, s6
8007BDEC	lh     v1, $0000(v0)
8007BDF0	lh     v0, $0004(v0)
8007BDF4	sll    v1, v1, $10
8007BDF8	addu   s4, v1, v0
8007BDFC	lh     v0, $0002(a1)
8007BE00	addu   a0, s4, zero
8007BE04	sll    v0, v0, $03
8007BE08	addu   v0, v0, s6
8007BE0C	lh     v1, $0000(v0)
8007BE10	lh     v0, $0004(v0)
8007BE14	sll    v1, v1, $10
8007BE18	addu   s3, v1, v0
8007BE1C	lh     v0, $0004(a1)
8007BE20	addu   a1, s3, zero
8007BE24	sll    v0, v0, $03
8007BE28	addu   v0, v0, s6
8007BE2C	lh     v1, $0000(v0)
8007BE30	lh     v0, $0004(v0)
8007BE34	sll    v1, v1, $10
8007BE38	jal    system_side_of_vector [$8004a5b4]
8007BE3C	addu   s2, v1, v0
8007BE40	srl    s1, v0, $1f
8007BE44	addu   a0, s3, zero
8007BE48	addu   a1, s2, zero
8007BE4C	jal    system_side_of_vector [$8004a5b4]
8007BE50	addu   a2, fp, zero
8007BE54	bgez   v0, L7be60 [$8007be60]
8007BE58	addu   a0, s2, zero
8007BE5C	ori    s1, s1, $0002

L7be60:	; 8007BE60
8007BE60	addu   a1, s4, zero
8007BE64	jal    system_side_of_vector [$8004a5b4]
8007BE68	addu   a2, fp, zero
8007BE6C	bgez   v0, L7be7c [$8007be7c]
8007BE70	sltiu  v0, s1, $0008
8007BE74	ori    s1, s1, $0004
8007BE78	sltiu  v0, s1, $0008

L7be7c:	; 8007BE7C
8007BE7C	beq    v0, zero, L7bf98 [$8007bf98]
8007BE80	sll    v0, s1, $02
8007BE84	lui    at, $8007
8007BE88	addu   at, at, v0
8007BE8C	lw     v0, $f23c(at)
8007BE90	nop
8007BE94	jr     v0 
8007BE98	nop

8007BE9C	ori    t2, zero, $00ff
8007BEA0	j      L7bf98 [$8007bf98]
8007BEA4	sw     t2, $0048(sp)
8007BEA8	sll    v0, s0, $03
8007BEAC	subu   v0, v0, s0
8007BEB0	sll    v0, v0, $01
8007BEB4	addu   v0, v0, s5
8007BEB8	lh     s0, $0006(v0)
8007BEBC	j      L7bf9c [$8007bf9c]
8007BEC0	sll    v0, s0, $03
8007BEC4	sll    v0, s0, $03
8007BEC8	subu   v0, v0, s0
8007BECC	sll    v0, v0, $01
8007BED0	addu   v0, v0, s5
8007BED4	lh     s0, $0008(v0)
8007BED8	j      L7bf9c [$8007bf9c]
8007BEDC	sll    v0, s0, $03
8007BEE0	addu   a0, s3, zero
8007BEE4	lw     a2, $0040(sp)
8007BEE8	jal    system_side_of_vector [$8004a5b4]
8007BEEC	addu   a1, fp, zero
8007BEF0	bltz   v0, L7bf34 [$8007bf34]
8007BEF4	sll    v0, s0, $03
8007BEF8	j      L7bf68 [$8007bf68]
8007BEFC	subu   v0, v0, s0
8007BF00	sll    v0, s0, $03
8007BF04	subu   v0, v0, s0
8007BF08	sll    v0, v0, $01
8007BF0C	addu   v0, v0, s5
8007BF10	lh     s0, $000a(v0)
8007BF14	j      L7bf9c [$8007bf9c]
8007BF18	sll    v0, s0, $03
8007BF1C	addu   a0, s4, zero
8007BF20	lw     a2, $0040(sp)
8007BF24	jal    system_side_of_vector [$8004a5b4]
8007BF28	addu   a1, fp, zero
8007BF2C	bltz   v0, L7bf7c [$8007bf7c]
8007BF30	sll    v0, s0, $03

L7bf34:	; 8007BF34
8007BF34	subu   v0, v0, s0
8007BF38	sll    v0, v0, $01
8007BF3C	addu   v0, v0, s5
8007BF40	lh     s0, $0006(v0)
8007BF44	j      L7bf98 [$8007bf98]
8007BF48	ori    s1, zero, $0001
8007BF4C	addu   a0, s2, zero
8007BF50	lw     a2, $0040(sp)
8007BF54	jal    system_side_of_vector [$8004a5b4]
8007BF58	addu   a1, fp, zero
8007BF5C	bgez   v0, L7bf7c [$8007bf7c]
8007BF60	sll    v0, s0, $03
8007BF64	subu   v0, v0, s0

L7bf68:	; 8007BF68
8007BF68	sll    v0, v0, $01
8007BF6C	addu   v0, v0, s5
8007BF70	lh     s0, $0008(v0)
8007BF74	j      L7bf98 [$8007bf98]
8007BF78	ori    s1, zero, $0002

L7bf7c:	; 8007BF7C
8007BF7C	subu   v0, v0, s0
8007BF80	sll    v0, v0, $01
8007BF84	addu   v0, v0, s5
8007BF88	lh     s0, $000a(v0)
8007BF8C	j      L7bf98 [$8007bf98]
8007BF90	ori    s1, zero, $0004
8007BF94	addiu  s0, zero, $ffff (=-$1)

L7bf98:	; 8007BF98
8007BF98	sll    v0, s0, $03

L7bf9c:	; 8007BF9C
8007BF9C	subu   v0, v0, s0
8007BFA0	sll    v0, v0, $01
8007BFA4	addu   v0, v0, s5
8007BFA8	lbu    v0, $000c(v0)
8007BFAC	lui    v1, $800b
8007BFB0	lw     v1, $eff4(v1)
8007BFB4	lw     t2, $0028(sp)
8007BFB8	sll    v0, v0, $02
8007BFBC	addu   v0, v0, v1
8007BFC0	lw     v0, $0000(v0)
8007BFC4	lw     a1, $0000(t2)
8007BFC8	lw     t2, $0038(sp)
8007BFCC	nop
8007BFD0	and    a0, v0, t2
8007BFD4	srl    v0, a1, $09
8007BFD8	andi   v0, v0, $0003
8007BFDC	srl    v1, a0, $03
8007BFE0	and    v0, v0, v1
8007BFE4	bne    v0, zero, L7bd24 [$8007bd24]
8007BFE8	srl    v0, a1, $08
8007BFEC	andi   v0, v0, $0007
8007BFF0	srl    v1, a0, $05
8007BFF4	and    v0, v0, v1
8007BFF8	bne    v0, zero, L7bd24 [$8007bd24]
8007BFFC	lui    v0, $0080
8007C000	and    v0, a0, v0
8007C004	beq    v0, zero, L7c024 [$8007c024]
8007C008	addiu  v0, zero, $ffff (=-$1)
8007C00C	lw     t2, $0028(sp)
8007C010	nop
8007C014	lh     v0, $0010(t2)
8007C018	nop
8007C01C	beq    v0, zero, L7bd24 [$8007bd24]
8007C020	addiu  v0, zero, $ffff (=-$1)

L7c024:	; 8007C024
8007C024	beq    s0, v0, L7c0c4 [$8007c0c4]
8007C028	ori    v0, zero, $0002
8007C02C	lw     t2, $0048(sp)
8007C030	nop
8007C034	addiu  t2, t2, $0001
8007C038	slti   v0, t2, $0020
8007C03C	bne    v0, zero, L7bdc8 [$8007bdc8]
8007C040	sw     t2, $0048(sp)

L7c044:	; 8007C044
8007C044	addiu  v1, zero, $ffff (=-$1)
8007C048	beq    s0, v1, L7c0c0 [$8007c0c0]
8007C04C	ori    v0, zero, $0020
8007C050	lw     t2, $0048(sp)
8007C054	nop
8007C058	beq    t2, v0, L7c0c0 [$8007c0c0]
8007C05C	nop
8007C060	lw     t2, $0094(sp)
8007C064	nop
8007C068	bne    t2, v1, L7c078 [$8007c078]
8007C06C	sll    v0, s0, $03
8007C070	j      L7c31c [$8007c31c]
8007C074	addu   v0, zero, zero

L7c078:	; 8007C078
8007C078	subu   v0, v0, s0
8007C07C	sll    v0, v0, $01
8007C080	addu   v0, v0, s5
8007C084	lh     a0, $0000(v0)
8007C088	lh     a1, $0002(v0)
8007C08C	lh     a2, $0004(v0)
8007C090	lw     a3, $0090(sp)
8007C094	addiu  v0, sp, $0018
8007C098	sw     v0, $0010(sp)
8007C09C	sll    a0, a0, $03
8007C0A0	addu   a0, s6, a0
8007C0A4	sll    a1, a1, $03
8007C0A8	addu   a1, s6, a1
8007C0AC	sll    a2, a2, $03
8007C0B0	jal    field_calculate_walkmesh_height [$8007a690]
8007C0B4	addu   a2, s6, a2
8007C0B8	j      L7c31c [$8007c31c]
8007C0BC	addu   v0, zero, zero

L7c0c0:	; 8007C0C0
8007C0C0	ori    v0, zero, $0002

L7c0c4:	; 8007C0C4
8007C0C4	beq    s1, v0, L7c1a8 [$8007c1a8]
8007C0C8	slti   v0, s1, $0003
8007C0CC	beq    v0, zero, L7c0e4 [$8007c0e4]
8007C0D0	ori    v0, zero, $0001
8007C0D4	beq    s1, v0, L7c0f8 [$8007c0f8]
8007C0D8	addiu  v0, zero, $ffff (=-$1)
8007C0DC	j      L7c31c [$8007c31c]
8007C0E0	nop

L7c0e4:	; 8007C0E4
8007C0E4	ori    v0, zero, $0004
8007C0E8	beq    s1, v0, L7c258 [$8007c258]
8007C0EC	addiu  v0, zero, $ffff (=-$1)
8007C0F0	j      L7c31c [$8007c31c]
8007C0F4	nop

L7c0f8:	; 8007C0F8
8007C0F8	lw     t2, $0030(sp)
8007C0FC	nop
8007C100	sll    v1, t2, $03
8007C104	subu   v1, v1, t2
8007C108	sll    v1, v1, $01
8007C10C	addu   v1, v1, s5
8007C110	lh     v0, $0000(v1)
8007C114	nop
8007C118	sll    v0, v0, $03
8007C11C	addu   v0, v0, s6
8007C120	lhu    v0, $0000(v0)
8007C124	nop
8007C128	sh     v0, $0000(s7)
8007C12C	lh     v0, $0000(v1)
8007C130	nop
8007C134	sll    v0, v0, $03
8007C138	addu   v0, v0, s6
8007C13C	lhu    v0, $0002(v0)
8007C140	nop
8007C144	sh     v0, $0002(s7)
8007C148	lh     v0, $0000(v1)
8007C14C	nop
8007C150	sll    v0, v0, $03
8007C154	addu   v0, v0, s6
8007C158	lhu    v0, $0004(v0)
8007C15C	nop
8007C160	sh     v0, $0004(s7)
8007C164	lh     v0, $0002(v1)
8007C168	nop
8007C16C	sll    v0, v0, $03
8007C170	addu   v0, v0, s6
8007C174	lhu    v0, $0000(v0)
8007C178	nop
8007C17C	sh     v0, $0008(s7)
8007C180	lh     v0, $0002(v1)
8007C184	nop
8007C188	sll    v0, v0, $03
8007C18C	addu   v0, v0, s6
8007C190	lhu    v0, $0002(v0)
8007C194	nop
8007C198	sh     v0, $000a(s7)
8007C19C	lh     v0, $0002(v1)
8007C1A0	j      L7c308 [$8007c308]
8007C1A4	sll    v0, v0, $03

L7c1a8:	; 8007C1A8
8007C1A8	lw     t2, $0030(sp)
8007C1AC	nop
8007C1B0	sll    v1, t2, $03
8007C1B4	subu   v1, v1, t2
8007C1B8	sll    v1, v1, $01
8007C1BC	addu   v1, v1, s5
8007C1C0	lh     v0, $0002(v1)
8007C1C4	nop
8007C1C8	sll    v0, v0, $03
8007C1CC	addu   v0, v0, s6
8007C1D0	lhu    v0, $0000(v0)
8007C1D4	nop
8007C1D8	sh     v0, $0000(s7)
8007C1DC	lh     v0, $0002(v1)
8007C1E0	nop
8007C1E4	sll    v0, v0, $03
8007C1E8	addu   v0, v0, s6
8007C1EC	lhu    v0, $0002(v0)
8007C1F0	nop
8007C1F4	sh     v0, $0002(s7)
8007C1F8	lh     v0, $0002(v1)
8007C1FC	nop
8007C200	sll    v0, v0, $03
8007C204	addu   v0, v0, s6
8007C208	lhu    v0, $0004(v0)
8007C20C	nop
8007C210	sh     v0, $0004(s7)
8007C214	lh     v0, $0004(v1)
8007C218	nop
8007C21C	sll    v0, v0, $03
8007C220	addu   v0, v0, s6
8007C224	lhu    v0, $0000(v0)
8007C228	nop
8007C22C	sh     v0, $0008(s7)
8007C230	lh     v0, $0004(v1)
8007C234	nop
8007C238	sll    v0, v0, $03
8007C23C	addu   v0, v0, s6
8007C240	lhu    v0, $0002(v0)
8007C244	nop
8007C248	sh     v0, $000a(s7)
8007C24C	lh     v0, $0004(v1)
8007C250	j      L7c308 [$8007c308]
8007C254	sll    v0, v0, $03

L7c258:	; 8007C258
8007C258	lw     t2, $0030(sp)
8007C25C	nop
8007C260	sll    v1, t2, $03
8007C264	subu   v1, v1, t2
8007C268	sll    v1, v1, $01
8007C26C	addu   v1, v1, s5
8007C270	lh     v0, $0004(v1)
8007C274	nop
8007C278	sll    v0, v0, $03
8007C27C	addu   v0, v0, s6
8007C280	lhu    v0, $0000(v0)
8007C284	nop
8007C288	sh     v0, $0000(s7)
8007C28C	lh     v0, $0004(v1)
8007C290	nop
8007C294	sll    v0, v0, $03
8007C298	addu   v0, v0, s6
8007C29C	lhu    v0, $0002(v0)
8007C2A0	nop
8007C2A4	sh     v0, $0002(s7)
8007C2A8	lh     v0, $0004(v1)
8007C2AC	nop
8007C2B0	sll    v0, v0, $03
8007C2B4	addu   v0, v0, s6
8007C2B8	lhu    v0, $0004(v0)
8007C2BC	nop
8007C2C0	sh     v0, $0004(s7)
8007C2C4	lh     v0, $0000(v1)
8007C2C8	nop
8007C2CC	sll    v0, v0, $03
8007C2D0	addu   v0, v0, s6
8007C2D4	lhu    v0, $0000(v0)
8007C2D8	nop
8007C2DC	sh     v0, $0008(s7)
8007C2E0	lh     v0, $0000(v1)
8007C2E4	nop
8007C2E8	sll    v0, v0, $03
8007C2EC	addu   v0, v0, s6
8007C2F0	lhu    v0, $0002(v0)
8007C2F4	nop
8007C2F8	sh     v0, $000a(s7)
8007C2FC	lh     v0, $0000(v1)
8007C300	nop
8007C304	sll    v0, v0, $03

L7c308:	; 8007C308
8007C308	addu   v0, v0, s6
8007C30C	lhu    v0, $0004(v0)
8007C310	nop
8007C314	sh     v0, $000c(s7)
8007C318	addiu  v0, zero, $ffff (=-$1)

L7c31c:	; 8007C31C
8007C31C	lw     ra, $007c(sp)
8007C320	lw     fp, $0078(sp)
8007C324	lw     s7, $0074(sp)
8007C328	lw     s6, $0070(sp)
8007C32C	lw     s5, $006c(sp)
8007C330	lw     s4, $0068(sp)
8007C334	lw     s3, $0064(sp)
8007C338	lw     s2, $0060(sp)
8007C33C	lw     s1, $005c(sp)
8007C340	lw     s0, $0058(sp)
8007C344	addiu  sp, sp, $0080
8007C348	jr     ra 
8007C34C	nop
////////////////////////////////



////////////////////////////////
// func7b0d4
// main move ???

// SP = SP - a8
// A0 - some address (SP + 10) // vector to which we rotated if it not 0
// A1 - entity structure
// A2 - address to store line that we can't intersect
// A3 - rotation 0x0XXX
// return -1 if we can't move, 0 otherwise.

move_vector = A0;
entity_structure = A1;
intersect_line = A2;
rotation = A3;



// check first rotation
angle1 = (rotation - 100) & 0fff;

A0 = angle1;
system_cos; // cos
[SP + 20] = w(w[move_vector + 0] + (V0 << 6));

A0 = angle1;
system_sin; // sin
[SP + 28] = w(w[move_vector + 8] - (V0 << 6));

A0 = SP + 20; // move vector
A1 = entity_structure + 20; // current pos
A2 = entity_structure;
A3 = intersect_line; // address to store line that we can't intersect
A4 = SP + 40; // address of final point
A5 = -1; // we don't need to calculate height of final point
A6 = SP + 70; // we store material here
field_check_walkmesh_triangle_and_calculate_height; // 0 - can move, -1 - can't move

if (V0 != -1)
{
    // check second rotation
    angle2 = (rotation + 100) & 0fff;

    A0 = angle2;
    system_cos; // cos
    [SP + 20] = w(w[move_vector + 0] + (V0 << 6));

    A0 = angle2;
    system_sin; // sin
    [SP + 28] = w(w[move_vector + 8] - (V0 << 6));

    A0 = SP + 20;
    A1 = entity_structure + 20;
    A2 = entity_structure;
    A3 = intersect_line;
    A4 = SP + 40;
    A5 = -1;
    A6 = SP + 70;
    field_check_walkmesh_triangle_and_calculate_height; // 0 - can move, -1 - can't move

    if (V0 != -1)
    {
        // check straight
        A0 = rotation & 0fff;
        system_cos; // cos
        [SP + 20] = w(w[move_vector + 0] + (V0 << 6));

        A0 = rotation & 0fff;
        system_sin; // sin
        [SP + 28] = w(w[move_vector + 8] - (V0 << 6));

        A0 = SP + 20;
        A1 = entity_structure + 20;
        A2 = entity_structure;
        A3 = intersect_line;
        A4 = SP + 40;
        A5 = -1;
        A6 = SP + 70;
        field_check_walkmesh_triangle_and_calculate_height; // 0 - can move, -1 - can't move

        if (V0 != -1)
        {
            [SP + 20] = w(w[move_vector + 0]);
            [SP + 24] = w(w[move_vector + 4]);
            [SP + 28] = w(w[move_vector + 8]);
            8007B274	j      L7b2a0 [$8007b2a0]
        }
    }
}

[SP + 20] = w(w[move_vector + 0]);
[SP + 24] = w(w[move_vector + 4]);
[SP + 28] = w(w[move_vector + 8]);

A0 = rotation;
A1 = intersect_line;
A2 = SP + 20;
field_get_move_vector_to_move_along_with_line;

L7b2a0:	; 8007B2A0
A0 = SP + 20;
A1 = entity_structure + 20;
A2 = entity_structure;
A3 = intersect_line;
A4 = SP + 40;
A5 = 0;
A6 = SP + 70;
field_check_walkmesh_triangle_and_calculate_height; // check triangle

if (V0 != -1)
{
    // store move vector
    [SP + 30] = w(w[SP + 20]);
    [SP + 34] = w(w[SP + 24]);
    [SP + 38] = w(w[SP + 28]);

    // store new position
    [SP + 48] = h(hu[SP + 40]);
    [SP + 4a] = h(hu[SP + 42]);
    [SP + 4c] = h(hu[SP + 44]);

    start_y = h[entity_structure + 26]; // y current
    end_y = h[SP + 42]; // y calculated

    // if we do something that can bother movement
    if ((end_y < start_y) ||
        (w[SP + 70] & 00200000) ||
        ((w[SP + 70] & 00420000) && (w[entity_structure + 14] & 00420000)) ||
        (((w[SP + 70] & 00420000) == 0) && (end_y < start_y + 40)))
    {
        V0 = w[SP + 20];
        V0 = -V0;
        V0 = V0 >> 8;
        [SP + 50] = w(V0);

        V1 = w[SP + 28];
        V1 = -V1;
        V1 = V1 >> 8;
        [SP + 58] = w(V1);

        V0 = h[SP + 42];
        A2 = w[entity_structure + 24];
        V0 = V0 << 10;
        V0 = V0 - A2;
        V0 = V0 >> 8;
        [SP + 54] = w(V0);

        A0 = SP + 50;
        A1 = SP + 60;
        system_normalize_word_vector_T0_T1_T2_to_word;

        A0 = w[SP + 20] >> 8;
        A1 = w[SP + 28] >> 8;
        length_of_vector_by_x_y;

        T2 = V0 * w[SP + 60];
        V0 = V0 * w[SP + 64];
        V1 = V0 * w[SP + 68];
        V0 = -T2;
        [SP + 20] = w(V0 >> 4);
        [SP + 24] = w(T0 >> 4);
        V0 = -V1;
        [SP + 28] = w(V0 >> 4);

        A0 = SP + 20;
        A1 = entity_structure + 20;
        A2 = entity_structure;
        A3 = intersect_line;
        [SP + 10] = w(SP + 40);
        [SP + 14] = w(0);
        [SP + 18] = w(SP + 70);
        field_check_walkmesh_triangle_and_calculate_height; // check triangle

        if (V0 == -1)
        {
            return -1;
        }

        [entity_structure + 0] = w(w[entity_structure + 0] | 04000000);
    }
    else
    {
        // restore previous position
        [SP + 20] = w(w[SP + 30]);
        [SP + 24] = w(w[SP + 34]);
        [SP + 28] = w(w[SP + 38]);

        [SP + 40] = h(hu[SP + 48]);
        [SP + 42] = h(hu[SP + 4a]);
        [SP + 44] = h(hu[SP + 4c]);
    }

    [SP + 24] = w((h[SP + 42] << 10) - w[entity_structure + 24]);
    [move_vector + 0] = w(w[SP + 20]);
    [move_vector + 4] = w(w[SP + 24]);
    [move_vector + 8] = w(w[SP + 28]);
    [entity_structure + 72] = h((w[entity_structure + 24] + w[move_vector + 4]) >> 10);

    return 0;
}

return -1;
////////////////////////////////



////////////////////////////////
// field_check_walkmesh_triangle_and_calculate_height
// A0 - move vector
// A1 - current pos
// A2 - entity structure
// A3 - address to store line that we can't intersect
// A4 - address of final point
// A5 - if -1 then we don't need to really calculate height of final point
//      if 00000080 then we can go only down. Simulate material 00400000.
// A6 - pointer to store material
// return -1 if we can't move, 0 otherwise.

move_vector             = A0;
current_pos             = A1;
entity_structure        = A2;
intersect_line          = A3;

walkmesh_id             = h[entity_structure + 10];
triangle_id             = h[entity_structure + 08 + walkmesh_id * 2];

walkmesh_vertex_data    = w[800af008 + walkmesh_id * 4];
walkmesh_triangle_data  = w[800aeff8 + walkmesh_id * 4];
walkmesh_material_data  = w[800aeff4];

if( triangle_id != -1 )
{
    move_x              = w[move_vector + 0];
    move_z              = w[move_vector + 8];
    start_x             = w[current_pos + 0];
    start_y             = w[current_pos + 4];
    start_z             = w[current_pos + 8];
    end_x               = (start_x + move_x) >> 10;
    end_z               = (start_z + move_z) >> 10;
    start_x_z           = ((start_x >> 10) << 10) + (start_z >> 10);
    ending_point_x_z    = (end_x << 10) + end_z;

    [A4 + 0] = h(end_x);
    [A4 + 2] = h(0);
    [A4 + 4] = h(end_z);

    if( ( ( w[entity_structure + 4] >> ( walkmesh_id + 3 ) ) & 1 ) == 0 && bu[800b16a0] == 0 )
    {
        material_mask = ffffffff;
    }
    else
    {
        material_mask = 00000000;
    }

    material_id = bu[walkmesh_triangle_data + triangle_id * e + c];
    material = w[walkmesh_material_data + material_id * 4];

    if( ( material & material_mask & 00400000 ) || ( A5 == 00000080 ) )
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

        V0 = h[walkmesh_triangle_data + triangle_id * e + 00];
        a_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

        V0 = h[walkmesh_triangle_data + triangle_id * e + 02];
        b_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

        V0 = h[walkmesh_triangle_data + triangle_id * e + 04];
        c_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

        A0 = a_x_z;
        A1 = b_x_z;
        A2 = ending_point_x_z;
        system_side_of_vector;
        if( V0 < 0 )
        {
            S2 = S2 | 1;
        }

        A0 = b_x_z;
        A1 = c_x_z;
        A2 = ending_point_x_z;
        system_side_of_vector;
        if( V0 < 0 )
        {
            S2 = S2 | 2;
        }

        A0 = c_x_z;
        A1 = a_x_z;
        A2 = ending_point_x_z;
        system_side_of_vector;
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
                system_side_of_vector;

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
                system_side_of_vector;

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
                system_side_of_vector;

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

        [A6] = w(material & material_mask);
        type_of_unpassability = (w[A6] >> 5)

        type_of_entity = ((w[entity_structure + 0] & 00000700) >> 8);

        if( ( type_of_entity & type_of_unpassability ) || ( ( w[A6] & 10000000 ) && ( walkmesh_id == 0 ) ) )
        {
            triangle_id = -1;
        }
        else if( ( w[A6] & 00400000 ) && material_go_only_down == 0 ) // we check both triangles start and end.
        {
            A0 = h[walkmesh_triangle_data + triangle_id * e + 0];
            A1 = h[walkmesh_triangle_data + triangle_id * e + 2];
            A2 = h[walkmesh_triangle_data + triangle_id * e + 4];

            A0 = walkmesh_vertex_data + A0 * 8;
            A1 = walkmesh_vertex_data + A1 * 8;
            A2 = walkmesh_vertex_data + A2 * 8;
            A3 = A4;
            A4 = SP + 18; // address to store normal
            field_calculate_walkmesh_height;

            new_y = h[A4 + 2];

            if (new_y < (start_y >> 10)) // Y is less on top
            {
                triangle_id = -1;
            }
        }

        if (triangle_id == -1)
        {
            break;
        }

        triangle_check_count = triangle_check_count + 1;
        V0 = triangle_check_count < 20;
    8007B970	bne    v0, zero, L7b68c [$8007b68c]



    if (triangle_id != -1 && triangle_check_count != 20)
    {
        if (A5 != -1)
        {
            A0 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 0] * 8;
            A1 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 2] * 8;
            A2 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 4] * 8;
            A3 = A4; // pos
            A4 = SP + 18; // address to store normal
            field_calculate_walkmesh_height;
        }
        return 0;
    }



    if (S2 == 1)
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
    else if (S2 == 2)
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
    else if (S2 == 4)
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
}

return -1;
////////////////////////////////



////////////////////////////////
// field_calculate_walkmesh_height
// SP = SP - 58;
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
system_normalize_word_vector_T0_T1_T2_to_word;

[SP + 30] = w(h[C_vec + 0] - h[A_vec + 0]);
[SP + 34] = w(h[C_vec + 2] - h[A_vec + 2]);
[SP + 38] = w(h[C_vec + 4] - h[A_vec + 4]);
A0 = SP + 30;
A1 = SP + 20;
system_normalize_word_vector_T0_T1_T2_to_word;

A0 = SP + 10;
A1 = SP + 20;
A2 = S4; // normal
system_outer_product2_A0_A1_to_A2;

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
// field_get_move_vector_to_move_along_with_line
// A0 - rotation;
// A1 - intersect_line;
// A2 - move_vector

intersect_line = A1;
move_vector = A2;

S1 = (c00 - A0) & fff;

A0 = h[intersect_line + c] - h[intersect_line + 4];
A1 = h[intersect_line + 8] - h[intersect_line + 0];
system_get_rotation_based_on_vector_x_y;

A0 = (0 - V0) & fff; // rotation along line that we can't intersect 

S1 = (S1 + A0) & fff;

if ((S1 - 80) >= f01)
{
    [move_vector + 0] = w(0);
    [move_vector + 4] = w(0);
    [move_vector + 8] = w(0);

    return A0;
}
else
{
    if (S1 < 800)
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
    system_normalize_word_vector_T0_T1_T2_to_word;

    A0 = w[move_vector + 0] >> c;
    A1 = w[move_vector + 8] >> c;
    length_of_vector_by_x_y;

    [move_vector + 0] = w(w[SP + 20] * V0);
    [move_vector + 4] = w(0);
    [move_vector + 8] = w(w[SP + 28] * V0);

    return S3;
}
////////////////////////////////



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
// func81aa8
if( (w[A1 + 12c] & 00001000) == 0 )
{
    return 0;
}

S0 = (((w[A1 + 20] + w[A0 + 0]) >> 10) << 10) + ((w[A1 + 28] + w[A0 + 8]) >> 10);

V1 = w[A1 + 114];
S4 = (h[V1 + 0] << 10) + h[V1 + 2];
S1 = (h[V1 + 4] << 10) + h[V1 + 6];
S2 = (h[V1 + 8] << 10) + h[V1 + a];
S3 = (h[V1 + c] << 10) + h[V1 + e];

A0 = S4;
A1 = S1;
A2 = S0;
system_side_of_vector;
if( V0 < 0 )
{
    return -1;
}

A0 = S1;
A1 = S2;
A2 = S0;
system_side_of_vector;
if( V0 < 0 )
{
    return -1;
}

A0 = S2;
A1 = S3;
A2 = S0;
system_side_of_vector;
if( V0 < 0 )
{
    return -1;
}

A0 = S3;
A1 = S4;
A2 = S0;
system_side_of_vector;
V0 = V0 >> 1f;
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
