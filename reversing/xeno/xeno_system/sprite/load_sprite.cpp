
8002209c : SWL     01000140 (v0), 0007 (8012f464 (t0)) [8012f46b]
800220a0 : SWR     01000140 (v0), 0004 (8012f464 (t0)) [8012f468]
800220b0 : SWL     01e30100 (v0), 000b (8012f464 (t0)) [8012f46f]
800220b4 : SWR     01e30100 (v0), 0008 (8012f464 (t0)) [8012f46c]
800220d8 : SW      80111cfc (v0), 0000 (8012f464 (t0)) [8012f464]



////////////////////////////////
// func24168
80024170	lhu    s3, $0040(sp)
80024178	addu   s2, a1, zero
80024180	addu   s0, a0, zero
80024188	lhu    s4, $0044(sp)
80024190	addu   s5, a2, zero
80024198	addu   s6, a3, zero
800241A0	jal    func23680 [$80023680]

800241A8	jal    func23814 [$80023814]
800241AC	addu   a0, s0, zero
800241B0	addu   a0, s0, zero
800241B4	jal    func21e60 [$80021e60]
800241B8	ori    a1, zero, $1000
800241BC	lui    a0, $fffe
800241C0	ori    a0, a0, $1fff
800241C4	lw     v1, $003c(s0)
800241C8	addiu  v0, zero, $fffc (=-$4)
800241CC	and    v1, v1, v0
800241D0	lw     v0, $0040(s0)
800241D4	addu   s1, s2, zero
800241D8	and    v0, v0, a0
800241DC	sw     v0, $0040(s0)
800241E0	lui    v0, $8006
800241E4	lbu    v0, $884d(v0)
800241E8	ori    v1, v1, $0001
800241EC	beq    v0, zero, L24218 [$80024218]
800241F0	sw     v1, $003c(s0)
800241F4	addiu  v1, zero, $fffe (=-$2)
800241F8	lw     v0, $00a8(s0)
800241FC	lw     a0, $007c(s0)
80024200	and    v0, v0, v1
80024204	sw     v0, $00a8(s0)
80024208	sw     zero, $0008(a0)
8002420C	lw     v0, $007c(s0)
80024210	j      L2422c [$8002422c]
80024214	sh     zero, $000c(v0)

L24218:	; 80024218
80024218	lw     v0, $00a8(s0)
8002421C	lw     v1, $007c(s0)
80024220	ori    v0, v0, $0001
80024224	sw     v0, $00a8(s0)
80024228	sw     zero, $0018(v1)

L2422c:	; 8002422C
8002422C	lui    a0, $ff0f
80024230	ori    a0, a0, $ffff
80024234	lui    a1, $fff0
80024238	lw     v0, $003c(s0)
8002423C	lw     v1, $0048(gp)
80024240	ori    a1, a1, $ffff
80024244	sw     s0, $006c(s0)
80024248	and    v0, v0, a0
8002424C	andi   v1, v1, $000f
80024250	sll    a0, v1, $14
80024254	or     v0, v0, a0
80024258	and    v0, v0, a1
8002425C	sll    v1, v1, $10
80024260	or     v0, v0, v1
80024264	sw     v0, $003c(s0)
80024268	lw     a0, $0008(s1)
8002426C	jal    func1ece4 [$8001ece4]
80024270	addu   a0, s1, a0
80024274	sll    a0, v0, $01
80024278	addu   a0, a0, v0
8002427C	sll    a0, a0, $03
80024280	jal    system_memory_allocate [$800319ec]
80024284	addu   a1, zero, zero
80024288	lw     v1, $0020(s0)
8002428C	nop
80024290	sw     v0, $002c(v1)
80024294	sw     v0, $0030(v1)

V0 = w[S0 + 24];
[V0 + 4] = h(S3);
[V0 + 6] = h(S4);
[V0 + 8] = h(S5);
[V0 + a] = h(S6);

800242B4	addu   a0, s0, zero
800242C0	addu   a1, s2, zero

800242C8	jal    func22124 [$80022124]
800242CC	sw     a1, $0048(s0)
800242D0	lw     v0, $0024(s0)
800242D4	nop
800242D8	lw     v1, $0010(v0)
800242DC	addu   a0, s0, zero
800242E0	lhu    v0, $0000(v1)
800242E4	addu   a1, zero, zero
800242E8	andi   v0, v0, $003f
800242EC	addiu  v0, v0, $0001
800242F0	sll    v0, v0, $01
800242F4	addu   v0, v0, v1
800242F8	jal    func243e4 [$800243e4]
800242FC	sw     v0, $0060(s0)
80024300	addu   v0, s0, zero
////////////////////////////////
