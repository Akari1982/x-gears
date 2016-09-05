////////////////////////////////
// funca5118
800A5128	jal    func37334 [$80037334]

800A5130	jal    funca8938 [$800a8938]
800A5134	nop
800A5138	jal    func85b04 [$80085b04]
800A513C	nop
800A5140	jal    func7f5fc [$8007f5fc]
800A5144	nop
800A5148	lui    v1, $800b
800A514C	lw     v1, $f51c(v1)
800A5150	ori    v0, zero, $0006
800A5154	beq    v1, v0, La5180 [$800a5180]
800A5158	nop
800A515C	jal    funca8634 [$800a8634]
800A5160	nop
800A5164	lui    v1, $800b
800A5168	lw     v1, $f51c(v1)
800A516C	ori    v0, zero, $0004
800A5170	beq    v1, v0, La5180 [$800a5180]
800A5174	nop
800A5178	jal    funca3c20 [$800a3c20]
800A517C	nop

La5180:	; 800A5180
800A5180	jal    func44448 [$80044448]
800A5184	addu   a0, zero, zero
800A5188	jal    func73670 [$80073670]
800A518C	nop
800A5190	jal    func76c88 [$80076c88]
800A5194	nop
800A5198	jal    func6f740 [$8006f740]

A0 = w[80059b50];
A1 = 0;
system_memory_allocate;
S0 = V0;

A0 = S0; // to here
A1 = w[80059b70]; // from here
A2 = w[80059b50]; // this much
system_copy_memory;

A0 = w[80059b70];
[A0 - 4] = w(w[A0 - 4] & fdffffff);

A0 = w[80059b70];
800A51E4	jal    func31f0c [$80031f0c]

800A51EC	lui    v1, $800b
800A51F0	lw     v1, $f51c(v1)
800A51F4	ori    v0, zero, $0006
800A51F8	beq    v1, v0, La5208 [$800a5208]

800A5200	jal    funca858c [$800a858c]
800A5204	ori    a0, zero, $0001

La5208:	; 800A5208
A0 = w[80059b50];
A1 = 1;
system_memory_allocate;
[80059b70] = w(V0);

A0 = V0; // to here
A1 = S0; // from here
A2 = w[80059b50]; // this much
system_copy_memory; // copy clut/texture data

A0 = w[80059b70];
[A0 - 4] = w(w[A0 - 4] | 02000000);

800A5248	addu   a0, s0, zero
800A5244	jal    func31f0c [$80031f0c]

800A524C	lui    v1, $800b
800A5250	lw     v1, $f51c(v1)
800A5254	nop
800A5258	sltiu  v0, v1, $0007
800A525C	beq    v0, zero, La5880 [$800a5880]
800A5260	sll    v0, v1, $02
800A5264	lui    at, $8007
800A5268	addu   at, at, v0
800A526C	lw     v0, $f43c(at)
800A5270	nop
800A5274	jr     v0 
800A5278	nop

800A527C	lui    a0, $800b
800A5280	lw     a0, $f1e8(a0)
800A5284	jal    func7145c [$8007145c]
800A5288	addu   s0, zero, zero
800A528C	lui    v0, $800b
800A5290	lw     v0, $f1e8(v0)
800A5294	nop
800A5298	blez   v0, La5360 [$800a5360]
800A529C	ori    s1, zero, $80d4

La52a0:	; 800A52A0
800A52A0	jal    func73670 [$80073670]
800A52A4	addiu  s0, s0, $0001
800A52A8	lui    a0, $800c
800A52AC	lw     a0, $3740(a0)
800A52B0	lui    a1, $800b
800A52B4	lw     a1, $cfe0(a1)
800A52B8	jal    func71344 [$80071344]
800A52BC	addu   a0, a0, s1
800A52C0	jal    funca5dfc [$800a5dfc]
800A52C4	nop
800A52C8	lui    v0, $800b
800A52CC	lw     v0, $f1e8(v0)
800A52D0	nop
800A52D4	slt    v0, s0, v0
800A52D8	beq    v0, zero, La5360 [$800a5360]
800A52DC	nop
800A52E0	j      La52a0 [$800a52a0]
800A52E4	nop
800A52E8	addu   a0, zero, zero
800A52EC	jal    funca5b14 [$800a5b14]
800A52F0	addu   a1, zero, zero
800A52F4	lui    a0, $800b
800A52F8	lw     a0, $f1e8(a0)
800A52FC	jal    func7145c [$8007145c]
800A5300	addu   s0, zero, zero
800A5304	lui    v0, $800b
800A5308	lw     v0, $f1e8(v0)
800A530C	nop
800A5310	blez   v0, La5360 [$800a5360]
800A5314	ori    s1, zero, $80d4

loopa5318:	; 800A5318
800A5318	jal    func73670 [$80073670]
800A531C	addiu  s0, s0, $0001
800A5320	lui    a0, $800c
800A5324	lw     a0, $3740(a0)
800A5328	lui    a1, $800b
800A532C	lw     a1, $cfe0(a1)
800A5330	jal    func71344 [$80071344]
800A5334	addu   a0, a0, s1
800A5338	jal    funca58e0 [$800a58e0]
800A533C	nop
800A5340	jal    funca5dfc [$800a5dfc]
800A5344	nop
800A5348	lui    v0, $800b
800A534C	lw     v0, $f1e8(v0)
800A5350	nop
800A5354	slt    v0, s0, v0
800A5358	bne    v0, zero, loopa5318 [$800a5318]
800A535C	nop

La5360:	; 800A5360
800A5360	jal    func73670 [$80073670]
800A5364	nop
800A5368	jal    funca5dfc [$800a5dfc]
800A536C	nop
800A5370	jal    func1aed8 [$8001aed8]
800A5374	nop
800A5378	jal    func1b23c [$8001b23c]
800A537C	nop
800A5380	lui    s0, $800b
800A5384	lw     s0, $f51c(s0)
800A5388	lui    s1, $800b
800A538C	lw     s1, $f1e8(s1)
func70358;

800A5398	jal    func6fb18 [$8006fb18]
800A539C	nop
800A53A0	jal    func6fb98 [$8006fb98]
800A53A4	nop
800A53A8	lui    v1, $8005
800A53AC	lw     v1, $e9ac(v1)
800A53B0	addiu  v0, zero, $ffff (=-$1)
800A53B4	lui    at, $800b
800A53B8	sw     s0, $f51c(at)
800A53BC	lui    at, $800b
800A53C0	sw     s1, $f1e8(at)
800A53C4	bne    v1, v0, La53dc [$800a53dc]
800A53C8	nop
800A53CC	lui    a0, $8005
800A53D0	lw     a0, $e9c8(a0)
800A53D4	jal    func85134 [$80085134]
800A53D8	addu   a1, zero, zero

La53dc:	; 800A53DC
800A53DC	lui    a0, $800b
800A53E0	lw     a0, $f1e8(a0)
800A53E4	jal    func714e8 [$800714e8]
800A53E8	nop
800A53EC	j      La5878 [$800a5878]
800A53F0	nop
800A53F4	addu   a0, zero, zero
800A53F8	jal    funca5b14 [$800a5b14]
800A53FC	addu   a1, zero, zero
800A5400	lui    a0, $800b
800A5404	lw     a0, $f1e8(a0)
800A5408	jal    funca4be8 [$800a4be8]
800A540C	addu   s0, zero, zero
800A5410	lui    v0, $800b
800A5414	lw     v0, $f1e8(v0)
800A5418	nop
800A541C	blez   v0, La546c [$800a546c]
800A5420	ori    s1, zero, $80d4

loopa5424:	; 800A5424
800A5424	jal    func73670 [$80073670]
800A5428	addiu  s0, s0, $0001
800A542C	lui    a0, $800c
800A5430	lw     a0, $3740(a0)
800A5434	lui    a1, $800b
800A5438	lw     a1, $cfe0(a1)
800A543C	jal    func71344 [$80071344]
800A5440	addu   a0, a0, s1
800A5444	jal    funca58e0 [$800a58e0]
800A5448	nop
800A544C	jal    funca5dfc [$800a5dfc]
800A5450	nop
800A5454	lui    v0, $800b
800A5458	lw     v0, $f1e8(v0)
800A545C	nop
800A5460	slt    v0, s0, v0
800A5464	bne    v0, zero, loopa5424 [$800a5424]
800A5468	nop

La546c:	; 800A546C
800A546C	jal    func76c88 [$80076c88]
800A5470	nop
800A5474	jal    func1aed8 [$8001aed8]
800A5478	nop
800A547C	jal    func1b23c [$8001b23c]
800A5480	nop
800A5484	lui    s0, $800b
800A5488	lw     s0, $f51c(s0)
800A548C	lui    s1, $800b
800A5490	lw     s1, $f1e8(s1)
800A5494	jal    func70358 [$80070358]
800A5498	nop
800A549C	jal    func6fb18 [$8006fb18]
800A54A0	nop
800A54A4	jal    func6fb98 [$8006fb98]
800A54A8	nop
800A54AC	lui    v1, $8005
800A54B0	lw     v1, $e9ac(v1)
800A54B4	addiu  v0, zero, $ffff (=-$1)
800A54B8	lui    at, $800b
800A54BC	sw     s0, $f51c(at)
800A54C0	lui    at, $800b
800A54C4	sw     s1, $f1e8(at)
800A54C8	bne    v1, v0, La54e0 [$800a54e0]
800A54CC	nop
800A54D0	lui    a0, $8005
800A54D4	lw     a0, $e9c8(a0)
800A54D8	jal    func85134 [$80085134]
800A54DC	addu   a1, zero, zero

La54e0:	; 800A54E0
800A54E0	lui    a0, $800b
800A54E4	lw     a0, $f1e8(a0)
800A54E8	jal    funca4b80 [$800a4b80]
800A54EC	nop
800A54F0	j      La5878 [$800a5878]
800A54F4	nop
800A54F8	ori    a0, zero, $0001
800A54FC	jal    funca4d5c [$800a4d5c]
800A5500	ori    a1, zero, $0001
800A5504	jal    func1aed8 [$8001aed8]
800A5508	nop
800A550C	jal    func1b23c [$8001b23c]
800A5510	nop
800A5514	lui    s0, $800b
800A5518	lw     s0, $f51c(s0)
800A551C	lui    s1, $800b
800A5520	lw     s1, $f1e8(s1)
800A5524	jal    func70358 [$80070358]
800A5528	nop
800A552C	jal    func6fb18 [$8006fb18]
800A5530	nop
800A5534	lui    v1, $800b
800A5538	lw     v1, $d038(v1)
800A553C	ori    v0, zero, $0001
800A5540	bne    v1, v0, La55b8 [$800a55b8]
800A5544	nop

loopa5548:	; 800A5548
800A5548	jal    func284dc [$800284dc]
800A554C	nop
800A5550	beq    v0, zero, La5598 [$800a5598]
800A5554	nop
800A5558	jal    func73670 [$80073670]
800A555C	nop
800A5560	jal    funca58e0 [$800a58e0]
800A5564	nop
800A5568	jal    funca5dfc [$800a5dfc]
800A556C	nop
800A5570	lui    v1, $800c
800A5574	lw     v1, $1b58(v1)
800A5578	nop
800A557C	slti   v0, v1, $22c0
800A5580	beq    v0, zero, loopa5548 [$800a5548]
800A5584	addiu  v0, v1, $0020
800A5588	lui    at, $800c
800A558C	sw     v0, $1b58(at)
800A5590	j      loopa5548 [$800a5548]
800A5594	nop

La5598:	; 800A5598
800A5598	lui    a0, $800b
800A559C	lw     a0, $d0ec(a0)
800A55A0	jal    func31f0c [$80031f0c]
800A55A4	nop
800A55A8	lui    at, $800b
800A55AC	sw     zero, $d038(at)
800A55B0	jal    func78270 [$80078270]
800A55B4	nop

La55b8:	; 800A55B8
800A55B8	lui    v1, $8005
800A55BC	lw     v1, $e9ac(v1)
800A55C0	ori    v0, zero, $0001
800A55C4	lui    at, $800b
800A55C8	sw     v0, $f1d8(at)
800A55CC	addiu  v0, zero, $ffff (=-$1)
800A55D0	lui    at, $800b
800A55D4	sw     s0, $f51c(at)
800A55D8	lui    at, $800b
800A55DC	sw     s1, $f1e8(at)
800A55E0	bne    v1, v0, La55f8 [$800a55f8]
800A55E4	nop
800A55E8	lui    a0, $8005
800A55EC	lw     a0, $e9c8(a0)
800A55F0	jal    func85134 [$80085134]
800A55F4	addu   a1, zero, zero

La55f8:	; 800A55F8
800A55F8	lui    a0, $800b
800A55FC	lw     a0, $f1e8(a0)
800A5600	jal    func714e8 [$800714e8]
800A5604	lui    s1, $0080
800A5608	lui    v0, $800b
800A560C	lw     v0, $f1e8(v0)
800A5610	nop
800A5614	blez   v0, La5878 [$800a5878]
800A5618	addu   s0, zero, zero
800A561C	lui    s2, $0080

La5620:	; 800A5620
800A5620	jal    func7743c [$8007743c]
800A5624	nop
800A5628	jal    funca58e0 [$800a58e0]
800A562C	nop
800A5630	jal    func74bdc [$80074bdc]
800A5634	nop
800A5638	jal    func78170 [$80078170]
800A563C	nop
800A5640	jal    funca4ad8 [$800a4ad8]
800A5644	sra    a0, s1, $10
800A5648	lui    a0, $800b
800A564C	lw     a0, $f1e8(a0)
800A5650	nop
800A5654	div    s2, a0
800A5658	mflo   v0
800A565C	nop
800A5660	subu   s1, s1, v0
800A5664	bgez   s1, La5670 [$800a5670]
800A5668	nop
800A566C	addu   s1, zero, zero

La5670:	; 800A5670
800A5670	lui    v1, $800c
800A5674	lw     v1, $1b58(v1)
800A5678	nop
800A567C	slti   v0, v1, $22c0
800A5680	beq    v0, zero, La5690 [$800a5690]
800A5684	addiu  v0, v1, $0020
800A5688	lui    at, $800c
800A568C	sw     v0, $1b58(at)

La5690:	; 800A5690
800A5690	addiu  s0, s0, $0001
800A5694	slt    v0, s0, a0
800A5698	beq    v0, zero, La5878 [$800a5878]
800A569C	nop
800A56A0	j      La5620 [$800a5620]
800A56A4	nop
800A56A8	addu   a0, zero, zero
800A56AC	jal    funca5b14 [$800a5b14]
800A56B0	addu   a1, zero, zero
800A56B4	jal    func6fb18 [$8006fb18]
800A56B8	nop
800A56BC	jal    func73670 [$80073670]
800A56C0	nop
800A56C4	jal    funca58e0 [$800a58e0]
800A56C8	nop
800A56CC	jal    funca5dfc [$800a5dfc]
800A56D0	nop
800A56D4	jal    func1aed8 [$8001aed8]
800A56D8	nop
800A56DC	jal    func1b23c [$8001b23c]
800A56E0	nop
800A56E4	lui    s0, $800b
800A56E8	lw     s0, $f51c(s0)
800A56EC	lui    s1, $800b
800A56F0	lw     s1, $f1e8(s1)
800A56F4	ori    v0, zero, $0001
800A56F8	lui    at, $800b
800A56FC	sw     v0, $f1d8(at)
800A5700	jal    func70358 [$80070358]
800A5704	nop
800A5708	jal    func6fb98 [$8006fb98]
800A570C	nop
800A5710	lui    v1, $8005
800A5714	lw     v1, $e9ac(v1)
800A5718	addiu  v0, zero, $ffff (=-$1)
800A571C	lui    at, $800b
800A5720	sw     s0, $f51c(at)
800A5724	lui    at, $800b
800A5728	sw     s1, $f1e8(at)
800A572C	bne    v1, v0, La5748 [$800a5748]
800A5730	addu   s0, zero, zero
800A5734	lui    a0, $8005
800A5738	lw     a0, $e9c8(a0)
800A573C	jal    func85134 [$80085134]
800A5740	addu   a1, zero, zero
800A5744	addu   s0, zero, zero

La5748:	; 800A5748
800A5748	jal    func7743c [$8007743c]
800A574C	addiu  s0, s0, $0001
800A5750	jal    funca58e0 [$800a58e0]
800A5754	nop
800A5758	jal    func74bdc [$80074bdc]
800A575C	nop
800A5760	jal    func78170 [$80078170]
800A5764	nop
800A5768	slti   v0, s0, $0004
800A576C	beq    v0, zero, La5878 [$800a5878]
800A5770	nop
800A5774	j      La5748 [$800a5748]
800A5778	nop
800A577C	addu   a0, zero, zero
800A5780	jal    funca5b14 [$800a5b14]
800A5784	addu   a1, zero, zero
800A5788	jal    func6fb18 [$8006fb18]
800A578C	nop
800A5790	jal    func73670 [$80073670]
800A5794	nop
800A5798	jal    funca58e0 [$800a58e0]
800A579C	nop
800A57A0	jal    funca5dfc [$800a5dfc]
800A57A4	nop
800A57A8	jal    func1aed8 [$8001aed8]
800A57AC	nop
800A57B0	jal    func1b23c [$8001b23c]
800A57B4	nop
800A57B8	lui    s0, $800b
800A57BC	lw     s0, $f51c(s0)
800A57C0	lui    s1, $800b
800A57C4	lw     s1, $f1e8(s1)
800A57C8	ori    v0, zero, $0001
800A57CC	lui    at, $800b
800A57D0	sw     v0, $f1d8(at)
800A57D4	jal    func70358 [$80070358]
800A57D8	nop
800A57DC	jal    func6fb98 [$8006fb98]
800A57E0	nop
800A57E4	addiu  a0, sp, $0010
800A57E8	ori    a1, zero, $0140
800A57EC	ori    v0, zero, $02c0
800A57F0	sh     v0, $0010(sp)
800A57F4	ori    v0, zero, $0100
800A57F8	sh     v0, $0012(sp)
800A57FC	ori    v0, zero, $0140
800A5800	sh     v0, $0014(sp)
800A5804	ori    v0, zero, $00ff
800A5808	sh     v0, $0016(sp)
800A580C	lui    at, $800b
800A5810	sw     s0, $f51c(at)
800A5814	lui    at, $800b
800A5818	sw     s1, $f1e8(at)
800A581C	jal    func447d4 [$800447d4]
800A5820	ori    a2, zero, $00ff
800A5824	lui    v1, $8005
800A5828	lw     v1, $e9ac(v1)
800A582C	addiu  v0, zero, $ffff (=-$1)
800A5830	bne    v1, v0, La584c [$800a584c]
800A5834	addu   s0, zero, zero
800A5838	lui    a0, $8005
800A583C	lw     a0, $e9c8(a0)
800A5840	jal    func85134 [$80085134]
800A5844	addu   a1, zero, zero
800A5848	addu   s0, zero, zero

La584c:	; 800A584C
800A584C	jal    func7743c [$8007743c]
800A5850	addiu  s0, s0, $0001
800A5854	jal    funca58e0 [$800a58e0]
800A5858	nop
800A585C	jal    func74bdc [$80074bdc]
800A5860	nop
800A5864	jal    func78170 [$80078170]
800A5868	nop
800A586C	slti   v0, s0, $0004
800A5870	bne    v0, zero, La584c [$800a584c]
800A5874	nop

La5878:	; 800A5878
800A5878	lui    v1, $800b
800A587C	lw     v1, $f51c(v1)

La5880:	; 800A5880
800A5880	ori    v0, zero, $0006
800A5884	beq    v1, v0, La5898 [$800a5898]
800A5888	ori    v0, zero, $0002
800A588C	jal    funca86c8 [$800a86c8]
800A5890	nop
800A5894	ori    v0, zero, $0002

La5898:	; 800A5898
800A5898	lui    at, $800b
800A589C	sw     v0, $f51c(at)
800A58A0	ori    v0, zero, $0020
800A58A4	lui    at, $800b
800A58A8	sw     v0, $f1e8(at)
800A58AC	lui    at, $800b
800A58B0	sw     zero, $f1d8(at)
800A58B4	jal    func76bd4 [$80076bd4]
800A58B8	nop
800A58BC	jal    func31e1c [$80031e1c]
////////////////////////////////



////////////////////////////////
// func70358
A1 = 8006f184;
[SP + 38] = w(w[A1 + 0]);
[SP + 3c] = w(w[A1 + 4]);
[SP + 40] = w(w[A1 + 8]);
[SP + 44] = w(w[A1 + c]);



func6fc6c;



// copy first 0x100 byte of field file
A2 = w[80059b70];
A3 = 800b144c;
T0 = A2 + 100;
loop703cc:	; 800703CC
    [A3 + 0] = w(w[A2 + 0]);
    [A3 + 4] = w(w[A2 + 4]);
    [A3 + 8] = w(w[A2 + 8]);
    [A3 + c] = w(w[A2 + c]);
    A2 = A2 + 10;
    A3 = A3 + 10;
80070410	bne    a2, t0, loop703cc [$800703cc]



S4 = 0;
loop7045c:	; 8007045C
    S0 = 0;
    loop70464:	; 80070464
        A0 = 800afb90 + (S4 * 4 + S0) * 70;
        A1 = S0;
        A2 = S4;
        A3 = 0;
        8007047C	jal    func79e08 [$80079e08]

        S0 = S0 + 1;
        V0 = S0 < 4;
    8007048C	bne    v0, zero, loop70464 [$80070464]

    S4 = S4 + 1;
    V0 = S4 < 4;
8007049C	bne    v0, zero, loop7045c [$8007045c]



A0 = 800b0290;
A1 = 4;
A2 = 4;
A3 = 1;
800704B8	jal    func79e08 [$80079e08]

A0 = 800b0290 + 70;
A1 = 5;
A2 = 5;
A3 = 1;
800704CC	jal    func79e08 [$80079e08]

A0 = 800b0290 + e0;
A1 = 6;
A2 = 6;
A3 = 1;
800704E0	jal    func79e08 [$80079e08]

A0 = 800b0290 + 150;
A1 = 7;
A2 = 7;
A3 = 1;
800704F4	jal    func79e08 [$80079e08]

A0 = 800b0290 + 1c0;
A1 = 8;
A2 = 8;
A3 = 1;
80070508	jal    func79e08 [$80079e08]



80070510	jal    func79bd8 [$80079bd8]



// extraction (part 0 of field file)
V0 = w[80059b70];
A0 = w[V0 + 10c] + 10;
A1 = 1;
system_memory_allocate;
S2 = V0;

V0 = w[80059b70];
A0 = V0 + w[V0 + 130];
A1 = S2;
system_extract_archive;

S3 = w[S2];
if( S3 > 0 )
{
    S4 = 0;
    loop7056c:	; 8007056C
        A0 = S2 + w[S2 + 4 + S4 * 4];
        80070574	jal    func76888 [$80076888]

        S4 = S4 + 1;
        V0 = S4 < S3;
    80070580	bne    v0, zero, loop7056c [$8007056c]
}



// sprite texture extraction (part 4 of field file)
V0 = w[80059b70];
A0 = w[V0 + 11c] + 10;
A1 = 0;
system_memory_allocate;
S4 = V0;

V0 = w[80059b70];
A0 = V0 + w[V0 + 140];
A1 = S4;
system_extract_archive;

number_of_textures = w[S4];
if( number_of_textures > 0 )
{
    S0 = 0;
    func705e0:	; 800705E0
        if( h[800b1452 + S0 * 8] == 0 )
        {
            A0 = S4 + w[S4 + 4 + S0 * 4];
            A1 = hu[800b144c + S0 * 8];
            A2 = hu[800b144e + S0 * 8];
            80070610	jal    func228fc [$800228fc]
        }
        S0 = S0 + 1;
        V0 = S0 < number_of_textures;
    80070620	bne    v0, zero, func705e0 [$800705e0]
}



A0 = 0;
80070628	jal    func44448 [$80044448]

A0 = S2;
80070630	jal    func31f0c [$80031f0c]

A0 = S4;
80070638	jal    func31f0c [$80031f0c]



// 3d model extraction (part 2 of field file)
V0 = w[80059b70];
A0 = w[V0 + 114] + 10;
A1 = 0;
system_memory_allocate;
[800aefe8] = w(V0);

V1 = w[80059b70];
A0 = V1 + w[V1 + 138];
A1 = V0;
system_extract_archive;

S2 = w[800aefe8];
number_of_models = w[S2];
if( number_of_models > 0 )
{
    S4 = 0;
    loop706a8:	; 800706A8
        A0 = S2 + w[S2 + 4 + S4 * 4];
        func2c1f8; // sets global offsets for model file and return number of parts

        S4 = S4 + 1;
        V0 = S4 < number_of_models;
    800706D4	bne    v0, zero, loop706a8 [$800706a8]
}



A1 = w[80059b70];
A0 = A1 + w[A1 + 148];
A1 = 80064f6c; // where
system_extract_archive;



// script extraction (part 5 of field file)
V0 = w[80059b70];
A0 = w[V0 + 120] + 10;
A1 = 0;
system_memory_allocate;
[800ad0d0] = w(V0);

V1 = w[80059b70];
A0 = V1 + w[V1 + 144];
A1 = V0;
system_extract_archive;

V0 = w[800ad0d0];
V1 = w[V0 + 80];
[800ad0d4] = w(V1); // number of entities
[800ad0d8] = w(V0 + 84 + V1 * 40); // pointer to script data



// triggers extraction (part 8 of field file)
A0 = w[80059b70];
A0 = w[A0 + 12c] + 10;
A1 = 0;
system_memory_allocate;
[800ad0cc] = w(V0);

V1 = w[80059b70];
A0 = V1 + w[V1 + 150];
A1 = V0;
system_extract_archive;



// dialogs extraction (part 7 of field file)
V0 = w[80059b70];
A0 = w[V0 + 128] + 10;
A1 = 0;
system_memory_allocate;
[800ad0c8] = w(V0);

V1 = w[80059b70];
A0 = V1 + w[V1 + 14c];
A1 = V0;
system_extract_archive;



// walkmesh extraction (part 1 of field file)
V0 = w[80059b70];
A0 = w[V0 + 110] + 10;
A1 = 0;
system_memory_allocate;
[800aefec] = w(V0);

V1 = w[80059b70];
A0 = V1 + w[V1 + 134];
A1 = V0;
system_extract_archive;

V0 = w[800aefec];
[800af028] = h(w[V0]); // block count

S2 = w[800aefec] + 4;

S4 = 0;
loop70860:	; 80070860
    [800af018 + S4 * 4] = w(w[S2] / e); // number of triangles
    S2 = S2 + 4;
    S4 = S4 + 1;
    V0 = S4 < 4;
80070888	bne    v0, zero, loop70860 [$80070860]

[800aeff4] = w(w[800aefec] + w[S2]); // material data
S2 = S2 + 4;

blocks = h[800af028];
if( blocks > 0 )
{
    S4 = 0;
    loop708cc:	; 800708CC
        [800aeff8 + S4 * 4] = w(w[800aefec] + w[S2 + 0]); // block_start
        [800af008 + S4 * 4] = w(w[800aefec] + w[S2 + 4]; // block_vertex
        S2 = S2 + 8;
        S4 = S4 + 1;
        V0 = S4 < blocks;
    80070908	bne    v0, zero, loop708cc [$800708cc]
}

[800af1e4] = w((w[800aeff8] - w[800aeff4]) / 4); // number of materials



// sprite data extraction (part 3 of field file)
V1 = w[80059b70];
A0 = w[V1 + 118] + 10;
A1 = 0;
system_memory_allocate;
[800aeff0] = w(V0);

V1 = w[80059b70];
A0 = V1 + w[V1 + 13c];
A1 = V0;
system_extract_archive;



[800aeeb0] = h(1);
[800aeeb2] = h(1);
[800aeeb4] = h(1);
[800aeeb6] = h(1);



A0 = w[80059b70] + 154;
func6f47c;



// set up entities
V0 = w[80059b70];
number_of_entities = hu[V0 + 18c];
[800aefe0] = w(number_of_entities);

A0 = number_of_entities * 5c;
A1 = 0;
system_memory_allocate;
[800aefe4] = w(V0);

if( number_of_entities > 0 )
{
    struct_5c = w[800aefe4];

    // init entity struct with zeroes
    S4 = 0;
    loop709f0:	; 800709F0
        [struct_5c + S4] = w(0);
        S4 = S4 + 4;
        V0 = S4 < number_of_entities * 5c;
    800709FC	bne    v0, zero, loop709f0 [$800709f0]

    init_data = w[80059b70] + 190;
    entity_id = 0;
    L70a1c:	; 80070A1C
        [struct_5c + entity_id * 5c + 58] = h(hu[init_data + entity_id * 10 + 0]); // flags
        [struct_5c + entity_id * 5c + 50] = h(hu[init_data + entity_id * 10 + 2]); // x rot
        [struct_5c + entity_id * 5c + 52] = h(hu[init_data + entity_id * 10 + 4]); // y rot
        [struct_5c + entity_id * 5c + 54] = h(hu[init_data + entity_id * 10 + 6]); // z rot
        [struct_5c + entity_id * 5c + 20] = w(hu[init_data + entity_id * 10 + 8]); // x
        [struct_5c + entity_id * 5c + 40] = w(hu[init_data + entity_id * 10 + 8]); // x
        [struct_5c + entity_id * 5c + 24] = w(hu[init_data + entity_id * 10 + a]); // y
        [struct_5c + entity_id * 5c + 44] = w(hu[init_data + entity_id * 10 + a]); // y
        [struct_5c + entity_id * 5c + 28] = w(hu[init_data + entity_id * 10 + c]); // z
        [struct_5c + entity_id * 5c + 48] = w(hu[init_data + entity_id * 10 + c]); // z

        if( ( hu[struct_5c + entity_id * 5c + 58] & 0040 ) == 0 )
        {
            A0 = 24;
            A1 = 0;
            system_memory_allocate;
            S0 = V0;

            [struct_5c + entity_id * 5c + 0] = w(S0);

            models = w[800aefe8];
            model_id = hu[init_data + entity_id * 10 + e];
            [S0 + 4] = w(models + w[models + 4 + model_id * 4] + 10);

            A0 = w[S0 + 4];
            A1 = S0 + 8;
            A2 = S0 + c;
            system_allocate_memory_for_packets; // allocate place for both packets buffers

            A0 = w[S0 + 4]; // data
            A1 = w[S0 + 8]; // memory for packets
            A2 = ( hu[struct_5c + entity_id * 5c + 58] & 000c ) >> 2; // lighting flags
            system_fill_packets_drafts_for_model_part; // fill 1st buffer

            A0 = w[S0 + c]; // to
            A1 = w[S0 + 8]; // from
            V0 = w[S0 + 4];
            A2 = w[V0 + 34]; // size
            system_copy_memory; // copy from 1st buffer to second

            if( hu[struct_5c + entity_id * 5c + 58] & 2000 )
            {
                [GP + 1ac] = h(3);
                [80059640 + 3 * 4] = w(0);
                [GP + 1c0] = w(0);

                A0 = w[S0 + 4];
                A1 = 0;
                func301d8; // init +1c in model data
                [S0 + 14] = w(V0);

                [GP + 1ac] = h(8);
                [80059640 + 8 * 4] = w(0);
                [GP + 1c0] = w(0);
            }

            A0 = w[S0 + 4];
            func2c454;
        }
        else
        {
            [struct_5c + entity_id * 5c + 50] = h(0);
            [struct_5c + entity_id * 5c + 52] = h(0);
            [struct_5c + entity_id * 5c + 54] = h(0);
            [struct_5c + entity_id * 5c + 58] = h(hu[struct_5c + entity_id * 5c + 58] | 0020);
        }

        A0 = entity_id;
        func80558;

        entity_id = entity_id + 1;
        V0 = entity_id < number_of_entities;
    80070C28	bne    v0, zero, L70a1c [$80070a1c]
}



if( w[800c1b60] == 0 )
{
    80070C44	0C0A04AF	Ї...
}



80070C4C	jal    func7d4e0 [$8007d4e0]

80070C54	jal    func710f4 [$800710f4]

A0 = w[80059b70];
[A0 - 4] = w(w[A0 - 4] & fdffffff);

A0 = w[80059b70];
80070C74	jal    func31f0c [$80031f0c]

A0 = 5;
A1 = 0;
80070C80	jal    func322bc [$800322bc]

A0 = 3c00;
A1 = 0;
80070C8C	jal    func24d5c [$80024d5c]

80070C94	jal    func1c7d0 [$8001c7d0]

A0 = 8;
A1 = 0;
80070CA0	jal    func322bc [$800322bc]

S0 = 800b1710;

A0 = S0;
A1 = 800;
A2 = 0;
A3 = 0;
[SP + 10] = w(00000800);
[SP + 14] = w(0);
[SP + 18] = w(0);
[SP + 1c] = w(00000800);
[SP + 20] = w(0);
[SP + 24] = w(0);
80070CD8	jal    func76ed4 [$80076ed4]

A0 = S0 - 20;
A1 = 1f8;
A2 = fffff03f;
A3 = fffffe08;
[SP + 10] = w(0);
[SP + 14] = w(0);
[SP + 18] = w(0);
[SP + 1c] = w(0);
[SP + 20] = w(0);
[SP + 24] = w(0);
80070D04	jal    func76ed4 [$80076ed4]

S2 = 800af558;

[800a1732] = b(1e);
[800a1731] = b(1e);
[800a1730] = b(1e);

[S2] = h(140);

[800af562] = h(0);
[800af57d] = b(0);
[800af57c] = b(0);
[800af57a] = b(0);
[800af579] = b(0);
[800af578] = b(0);
[800af576] = b(0);
[800af575] = b(0);

[S2 + 1c] = b(0);
[S2 + c] = w(0);

[800af56c] = w(1000);

[800af584] = h(0);
[800af582] = h(0);
[800af580] = h(0);

[800af560] = h(0);
[800af55e] = h(0);
[800af55c] = h(0);
[800af55a] = h(0);
[800af556] = h(0);
[800af554] = h(0);

[800af586] = h(0);
[800af568] = w(0);
[800af57e] = b(20);

[800afcff4] = w(0);
S1 = S2 + c;

80070DF8	jal    funca1e64 [$800a1e64]

A1 = 800af104;

[800acff4] = w(1);

A0 = S0 - b8;
80070E14	jal    func3f5e0 [$8003f5e0]

[800af120] = w(0);
[800af11c] = w(0);
[800af118] = w(0);

S0 = S2 + 1c;

if( h[800af586] != 0 )
{
    A0 = h[800af554];
    A1 = h[800af556];
    A2 = h[S2];
    A3 = h[800af55a];
    A4 = h[800af55c];
    A5 = h[800af55e];
    A6 = h[800af560];
    A7 = h[800af562];
    A8 = S1;
    A9 = S0;
    A10 = h[800af580];
    A11 = h[800af582];
    A12 = h[800af584];

    80070EB8	jal    func26eac [$80026eac]

    [800af550] = w(V0);
}

A0 = 8;
A1 = 0;
80070ECC	jal    func322bc [$800322bc]

V1 = hu[800b1812];

80070EE0	sll    v0, v1, $01
80070EE4	addu   v0, v0, v1
80070EE8	sll    v0, v0, $03
80070EEC	subu   v0, v0, v1

V1 = w[800aefe4];

80070EF8	sll    v0, v0, $02
80070EFC	addu   v0, v0, v1
80070F00	lw     v1, $0020(v0)

A1 = 800aed94;

80070F0C	sll    v1, v1, $10
80070F10	sw     v1, $0000(a1)
80070F14	lw     v1, $0024(v0)
80070F18	nop
80070F1C	sll    v1, v1, $10

[800aed98] = w(V1);

80070F28	lw     v0, $0028(v0)

V1 = w[800aefe0];

80070F34	sll    v0, v0, $10

[800aed9c] = w(V0);

if( V1 > 0 )
{
    S4 = 0;
    S1 = A1 + 250;
    S0 = 0;

    loop70f50:	; 80070F50
        A1 = S0 + w[S1];

        A0 = A1 + 50;
        A1 = A1 + c;
        80070F60	jal    func3f5e0 [$8003f5e0]

        V0 = S0 + w[800aefe4];

        S4 = S4 + 1;

        V1 = w[V0 + c];
        A0 = w[V0 + 10];
        A1 = w[V0 + 14];
        A2 = w[V0 + 18];

        [V0 + 2c] = w(V1);
        [V0 + 30] = w(A0);
        [V0 + 34] = w(A1);
        [V0 + 38] = w(A2);

        V1 = w[V0 + 1c];
        A0 = w[V0 + 20];
        A1 = w[V0 + 24];
        A2 = w[V0 + 28];

        [V0 + 3c] = w(V1);
        [V0 + 40] = w(A0);
        [V0 + 44] = w(A1);
        [V0 + 48] = w(A2);

        S0 = S0 + 5c;
        V0 = S4 < w[S1 - 4];
    80070FC4	bne    v0, zero, loop70f50 [$80070f50]
}

80070FCC	jal    func772f0 [$800772f0]

80070FD4	jal    funca1ca4 [$800a1ca4]

[8004e9d8] = w(ffffffff);
[8004e9d4] = w(ffffffff);

80070FF0	jal    func734c8 [$800734c8]

80070FF8	jal    func768f8 [$800768f8]

if( h[800af586] == 0 )
{
    80071014	jal    func73d2c [$80073d2c]

    [800ad024] = w(V0);
}
else
{
    [800ad024] = w(1);
}

if( w[800ad0d4] > 0 )
{
    S4 = 0;
    S0 = 0;

    loop7103c:	; 8007103C
        A0 = w[800aefe4] + S0;

        if( hu[A0 + 58] & 0040 )
        {
            A2 = w[A0 + 4c];
            if( (w[A2 + 4] & 01000000) == 0 )
            {
                A0 = w[A0 + 4];
                A1 = ((hu[800aee62] + hu[A2 + 108]) << 10) >> 10;
                80071094	jal    func22218 [$80022218]
            }
            else
            {
                A0 = w[A0 + 4];
                A1 = h[A2 + 108];
                800710AC	jal    func21e40 [$80021e40]
            }
        }

        S4 = S4 + 1;
        S0 = S0 + 5c;
        V0 = S4 < w[800ad0d4];
    800710C4	bne    v0, zero, loop7103c [$8007103c]
}
////////////////////////////////



////////////////////////////////
// func80558
entity_id = A0;
struct_5c = w[800aefe4] + entity_id * 5c;

// given id greater than number of entitys
if( entity_id >= w[800ad0d4] )
{
    return;
}

[800b1654] = w(w[800b1654] + 1);

A0 = 138;
A1 = 0;
system_memory_allocate;
[struct_5c + 4c] = w(V0);

A0 = 0;
loop805dc:	; 800805DC
    [V0 + A0] = w(0);
    A0 = A0 + 4;
    V0 = A0 < 138;
800805EC	bne    v0, zero, loop805dc [$800805dc]

[struct_5c + 5a] = h(0);

struct_138 = w[struct_5c + 4c];

if( hu[struct_5c + 58] & 2000 )
{
    S1 = w[struct_5c + 0];

    A0 = 80;
    A1 = 0;
    system_memory_allocate;
    [struct_138 + 118] = w(V0);

    V1 = w[S1 + 14];
    if( V1 != 0 )
    {
        if( w[V1 + c] > 0 )
        {
            A0 = 0;
            loop80674:	; 80080674
                V0 = w[V1 + 10];
                [V0 + A0 * 20 + 0] = w(8008002c);

                V0 = w[struct_138 + 118];
                [V0 + A0 * 4] = w(0);

                A0 = A0 + 1;
                V0 = A0 < w[V1 + c];
            800806A8	bne    v0, zero, loop80674 [$80080674]
        }
    }
}

A0 = entity_id;
func80088;

A0 = 70;
A1 = 0;
system_memory_allocate;
[struct_5c + 8] = w(V0);

A0 = V0;
func7a058; // init shadow
////////////////////////////////



////////////////////////////////
// func80088
entity_id = A0;

struct_5c = w[800aefe4] + entity_id * 5c;

S0 = w[struct_5c + 4c];

[S0 + 0] = w(000000b0);
[S0 + 4] = w(00000800);
[S0 + 8] = h(0);
[S0 + a] = h(0);
[S0 + c] = h(0);
[S0 + e] = h(0);
[S0 + 10] = h(0);

[S0 + 18] = h(10);
[S0 + 1a] = h(60);
[S0 + 1c] = h(10);
[S0 + 1e] = h(hu[S0 + 18]);

[S0 + 30] = w(0);
[S0 + 34] = w(0);
[S0 + 38] = w(0);

[S0 + 40] = w(0);
[S0 + 44] = w(0);
[S0 + 48] = w(0);

[S0 + 60] = h(0);
[S0 + 62] = h(0);
[S0 + 64] = h(0);

[S0 + 6e] = h(0);

[S0 + 74] = b(ff);
[S0 + 75] = b(ff);
[S0 + 76] = h(0100);

[S0 + 80] = b(ff);

[S0 + 82] = b(0);
[S0 + 83] = b(0);
[S0 + 84] = w(0);
[S0 + 88] = h(0);
[S0 + 8a] = h(0);

// init requested script
S3 = 0;
loop8021c:	; 8008021C
    [S0 + 8c + S3 * 8 + 0] = h(ffff); // pointer to requested script
    [S0 + 8c + S3 * 8 + 2] = b(0); // wait byte
    [S0 + 8c + S3 * 8 + 3] = b(ff); // script id
    [S0 + 8c + S3 * 8 + 4] = w(( w[S0 + 8c + S3 * 8 + 4] & fffcffff & ffbfffff & fe7fffff ) | 003с0000);
    [S0 + 8c + S3 * 8 + 4] = h(ffff);
    S3 = S3 + 1;
    V0 = S3 < 8;
8008024C	bne    v0, zero, loop8021c [$8008021c]

[S0 + cc] = h(0);
[S0 + ce] = b(0);
[S0 + cf] = b(0);

[S0 + d0] = w(0);
[S0 + d4] = w(0);
[S0 + d8] = w(0);

[S0 + e2] = b(0);
[S0 + e3] = b(0);
[S0 + e4] = h(00ff);
[S0 + e6] = h(0);
[S0 + e8] = h(0);
[S0 + ec] = h(0);
[S0 + ea] = h(ff);

[S0 + f4] = h(1000);
[S0 + f6] = h(1000);
[S0 + f8] = h(1000);

[S0 + fc] = b(80);
[S0 + fd] = b(80);
[S0 + fe] = b(80);
[S0 + ff] = b(80);
[S0 + 100] = b(80);
[S0 + 101] = b(80);

system_get_random_2_bytes;
[S0 + 102] = h(V0);

[S0 + 104] = h(8000);
[S0 + 106] = h(8000);
[S0 + 108] = h(8000);

[S0 + 10d] = b(ff);

[S0 + 11e] = h(0200);
[S0 + 120] = w(0);
[S0 + 124] = h(ffff);
[S0 + 128] = h(ffff);
[S0 + 12c] = w(w[S0 + 12c] & fffffe3f & fffff1ff & ffffefff & f003ffff & fffcffff & ffffffdf & ffffffe3 & fffffffc);
[S0 + 130] = w(w[S0 + 130] & f007ffff & fffffe00 & fff801ff);
[S0 + 134] = w(w[S0 + 134] & ffffff9f & ffffff7f);



// find triangles to place entity on on all walkmeshes in field
number_of_walkmeshes = h[800af028] - 1;
if( number_of_walkmeshes > 0 )
{
    walkmesh_id = 0;
    loop80368:	; 80080368
        A0 = h[struct_5c + 20]; // x
        A1 = h[struct_5c + 28]; // z
        A2 = walkmesh_id;
        A3 = SP + 58 + walkmesh_id * 8;  // ret position
        A4 = SP + 18 + walkmesh_id * 10; // ret normal
        func7a7d8; // search for triangle model are in
        [S0 + 8 + walkmesh_id * 2] = h(V0); // store id of triangle

        if( V0 != -1 )
        {
            // if found triangle greater than total number of triangles - remove it
            if( V0 >= w[800af018 + walkmesh_id * 4] )
            {
                [800af018 + walkmesh_id * 4] = w(0);

                [SP + 18 + walkmesh_id * 10] = w(0);
                [SP + 1c + walkmesh_id * 10] = w(0);
                [SP + 20 + walkmesh_id * 10] = w(0);

                [SP + 58 + walkmesh_id * 8] = h(0);
                [SP + 5a + walkmesh_id * 8] = h(0);
                [SP + 5c + walkmesh_id * 8] = h(0);
            }
        }

        walkmesh_id = walkmesh_id + 1;
        V0 = walkmesh_id < number_of_walkmeshes;
    80080404	bne    v0, zero, loop80368 [$80080368]
}

A0 = S0;
get_current_triangle_material; // get current triangle material
[S0 + 14] = w(V0);

current_walkmesh = h[S0 + 10];
[S0 + 50] = w(w[SP + 18 + current_walkmesh * 10]);
[S0 + 54] = w(w[SP + 1c + current_walkmesh * 10]);
[S0 + 58] = w(w[SP + 20 + current_walkmesh * 10]);

if( ( hu[struct_5c + 58] & 0080 ) == 0 )
{
    [struct_5c + 24] = w(h[SP + 5a + current_walkmesh * 8]);
}

[S0 + 20] = w(w[struct_5c + 20] << 10);
[S0 + 24] = w(w[struct_5c + 24] << 10);
[S0 + 28] = w(w[struct_5c + 28] << 10);
[S0 + 72] = h(w[struct_5c + 24]);
////////////////////////////////



////////////////////////////////
// func7a058
offset_70 = S0 = A0;
S1 = S0 + 20; // start of packet

[offset_70 + 20 + 3] = b(9);
[offset_70 + 20 + 7] = b(2c);

[offset_70 + 0] = h(18);
[offset_70 + 2] = h(0);
[offset_70 + 4] = h(18);

[offset_70 + 8] = h(-18);
[offset_70 + a] = h(0);
[offset_70 + c] = h(18);

[offset_70 + 10] = h(18);
[offset_70 + 12] = h(0);
[offset_70 + 14] = h(-18);

[offset_70 + 18] = h(-18);
[offset_70 + 1a] = h(0);
[offset_70 + 1c] = h(-18);

[offset_70 + 20 + 4] = b(80);
[offset_70 + 20 + 5] = b(80);
[offset_70 + 20 + 6] = b(80);

A0 = 0;
A1 = 2;
A2 = 280;
A3 = 1e0;
func43894; // pack texpage settings
[offset_70 + 20 + 16] = h(V0);

A0 = 100;
A1 = f3;
func438d0; // pack clut
[offset_70 + 20 + e] = h(V0);

A0 = offset_70 + 20;
A1 = 1; // transparency on
system_set_draw_packet_transparency;

[offset_70 + 20 + c] = b(0);
[offset_70 + 20 + d] = b(e0);
[offset_70 + 20 + 14] = b(f);
[offset_70 + 20 + 15] = b(e0);
[offset_70 + 20 + 1c] = b(0);
[offset_70 + 20 + 1d] = b(ef);
[offset_70 + 20 + 24] = b(ef);
[offset_70 + 20 + 25] = b(f);

// copy data to 2nd buffer
A2 = 0;
loop7a12c:	; 8007A12C
    [S0 + 48 + A2 + 0] = w(w[S1 + 0]);
    [S0 + 48 + A2 + 4] = w(w[S1 + 4]);
    [S0 + 48 + A2 + 8] = w(w[S1 + 8]);
    [S0 + 48 + A2 + c] = w(w[S1 + c]);
    A2 = A2 + 10;
    S1 = S1 + 10;
8007A150	bne    s1, S0 + 40, loop7a12c [$8007a12c]

[S0 + 48 + A2 + 0] = w(w[S1 + 0]);
[S0 + 48 + A2 + 4] = w(w[S1 + 4]);
////////////////////////////////



////////////////////////////////
// func6fc6c
if( w[800c1b60] == 0 )
{
    func281274; // maybe exception
}

8006FC90	addu   a0, zero, zero
8006FC94	addu   a1, zero, zero
8006FC98	ori    a2, zero, $0140
8006FCA0	ori    a3, zero, $00e0
8006FC9C	jal    func715f4 [$800715f4]

8006FCA4	jal    func35c84 [$80035c84]

8006FCAC	addiu  a0, sp, $0020
8006FCB0	lui    a1, $800b
8006FCB4	addiu  a1, a1, $f5bc (=-$a44)
8006FCB8	ori    v0, zero, $ffff
8006FCBC	lui    s0, $800b
8006FCC0	addiu  s0, s0, $182a
8006FCC4	lui    at, $800b
8006FCC8	sh     v0, $cfd8(at)
8006FCCC	ori    v0, zero, $0005
8006FCD0	lui    at, $800b
8006FCD4	sh     zero, $f370(at)
8006FCD8	lui    at, $800b
8006FCDC	sh     zero, $f374(at)
8006FCE0	lui    at, $800c
8006FCE4	sh     zero, $1b68(at)

[800c2dcc] = h(0);
[800c2dd4] = h(0);
[800c2ddc] = h(0);
[800b181a] = h(3);
[800b181e] = h(40);
[800b1820] = h(ff);
[800c2f0c] = h(ff);
8006FD00	sb     v0, $0000(s0)


8006FD30	ori    v0, zero, $0020

[800c2f34] = w(0);
[800c2f30] = w(0);
[800b1690] = w(0);
[800b1694] = w(0);
[800b1698] = w(0);
[800b1738] = w(0);
[800b168c] = w(0);

8006FD6C	lui    at, $800b
8006FD70	sb     zero, $16a5(at)
8006FD74	lui    at, $800b
8006FD78	sb     zero, $16a4(at)
8006FD7C	lui    at, $800b
8006FD80	sw     zero, $1568(at)
8006FD84	lui    at, $800b
8006FD88	sw     zero, $1564(at)
8006FD8C	lui    at, $800b
8006FD90	sw     zero, $1560(at)
8006FD94	lui    at, $800b
8006FD98	sw     zero, $155c(at)
8006FD9C	lui    at, $800b
8006FDA0	sw     zero, $1558(at)
8006FDA4	lui    at, $800b
8006FDA8	sw     zero, $1554(at)
8006FDAC	lui    at, $800b
8006FDB0	sh     zero, $1586(at)
8006FDB4	lui    at, $800b
8006FDB8	sh     zero, $1584(at)
8006FDBC	lui    at, $800b
8006FDC0	sw     zero, $173c(at)
8006FDC4	lui    at, $800b
8006FDC8	sb     zero, $16a2(at)
8006FDCC	lui    at, $800b
8006FDD0	sh     zero, $1684(at)
8006FDD4	lui    at, $800b
8006FDD8	sh     zero, $1686(at)
8006FDDC	lui    at, $800b
8006FDE0	sh     zero, $1682(at)
8006FDE4	lui    at, $800b
8006FDE8	sh     zero, $154c(at)
8006FDEC	lui    at, $800b
8006FDF0	sb     zero, $16a1(at)
8006FDF4	lui    at, $800b
8006FDF8	sb     zero, $1673(at)
8006FDFC	lui    at, $800b
8006FE00	sb     zero, $1672(at)
8006FE04	lui    at, $800b
8006FE08	sb     zero, $1671(at)
8006FE0C	lui    at, $800b
8006FE10	sb     zero, $1670(at)
8006FE14	lui    at, $800b
8006FE18	sb     zero, $16a0(at)
8006FE1C	lui    at, $800b
8006FE20	sb     zero, $16a3(at)
8006FE24	lui    at, $800b
8006FE28	sb     zero, $16a6(at)
8006FE2C	lui    at, $800b
8006FE30	sw     zero, $d04c(at)
8006FE34	lui    at, $800b
8006FE38	sw     zero, $d024(at)
8006FE3C	lui    at, $800b
8006FE40	sw     zero, $d068(at)
8006FE44	lui    at, $800b
8006FE48	sw     zero, $cffc(at)
8006FE4C	lui    at, $800b
8006FE50	sw     zero, $d070(at)
8006FE54	lui    at, $800b
8006FE58	sw     zero, $d06c(at)
8006FE5C	lui    at, $800b
8006FE60	sw     zero, $d048(at)
8006FE64	lui    at, $800b
8006FE68	sw     zero, $d004(at)
8006FE6C	lui    at, $800b
8006FE70	sw     zero, $d040(at)
8006FE74	lui    at, $800b
8006FE78	sw     zero, $d060(at)
8006FE7C	lui    at, $800b
8006FE80	sw     zero, $d080(at)
8006FE84	lui    at, $800b
8006FE88	sw     zero, $f538(at)
8006FE8C	lui    at, $800b
8006FE90	sw     zero, $cff0(at)
8006FE94	lui    at, $800b
8006FE98	sw     zero, $d028(at)
8006FE9C	lui    at, $800b
8006FEA0	sw     zero, $f358(at)
8006FEA4	lui    at, $800b
8006FEA8	sw     zero, $f1d8(at)
8006FEAC	lui    at, $800b
8006FEB0	sb     zero, $f79c(at)
8006FEB4	lui    at, $800b
8006FEB8	sw     zero, $d0ac(at)
8006FEBC	lui    at, $800b
8006FEC0	sw     zero, $d0a8(at)
8006FEC4	lui    at, $800b
8006FEC8	sh     zero, $17b4(at)
8006FECC	lui    at, $800b
8006FED0	sh     zero, $1810(at)
8006FED4	lui    at, $800b
8006FED8	sw     zero, $0978(at)
8006FEDC	lui    at, $800b
8006FEE0	sh     zero, $1840(at)
8006FEE4	lui    at, $800b
8006FEE8	sw     zero, $d010(at)
8006FEEC	lui    at, $800b
8006FEF0	sw     zero, $d014(at)




8006FEF4	lui    at, $800b
8006FEF8	sw     v0, $f1e8(at)
8006FEFC	ori    v0, zero, $0002
8006FF00	lui    at, $800b
8006FF04	sw     v0, $f51c(at)
8006FF08	ori    v0, zero, $03ff
8006FF0C	lui    at, $800b
8006FF10	sh     v0, $1680(at)
8006FF14	ori    v0, zero, $0004
8006FF18	lui    at, $800b
8006FF1C	sw     v0, $d0f0(at)
8006FF20	ori    v0, zero, $00ff
8006FF24	lui    at, $800b
8006FF28	sw     zero, $d01c(at)
8006FF2C	lui    at, $800b
8006FF30	sh     zero, $cfda(at)
8006FF34	lui    at, $800b
8006FF38	sh     zero, $1812(at)
8006FF3C	lui    at, $800b
8006FF40	sh     zero, $1818(at)
8006FF44	lui    at, $800b
8006FF48	sh     zero, $1816(at)
8006FF4C	lui    at, $800b
8006FF50	sh     zero, $181c(at)
8006FF54	lui    at, $800b
8006FF58	sh     zero, $1822(at)
8006FF5C	lui    at, $800b
8006FF60	sb     zero, $1829(at)
8006FF64	lui    at, $800b
8006FF68	sb     zero, $cfdc(at)
8006FF6C	lui    at, $800b
8006FF70	sb     zero, $cfdd(at)
8006FF74	lui    at, $800b
8006FF78	sb     zero, $182b(at)
8006FF7C	lui    at, $800b
8006FF80	sb     zero, $1828(at)
8006FF84	lui    at, $800b
8006FF88	sw     zero, $d08c(at)
8006FF8C	lui    at, $800b
8006FF90	sw     zero, $1824(at)
8006FF94	lui    at, $800b
8006FF98	sh     zero, $d02c(at)
8006FF9C	lui    at, $800b
8006FFA0	sb     zero, $182c(at)
8006FFA4	lui    at, $800b
8006FFA8	sw     zero, $d05c(at)
8006FFAC	lui    at, $800b
8006FFB0	sw     zero, $d054(at)
8006FFB4	lui    at, $800b
8006FFB8	sw     zero, $d064(at)
8006FFBC	lui    at, $800b
8006FFC0	sw     v0, $d03c(at)
8006FFC4	sh     zero, $0020(sp)
8006FFC8	sh     zero, $0022(sp)
8006FFCC	jal    func3f5e0 [$8003f5e0]
8006FFD0	sh     zero, $0024(sp)
8006FFD4	addiu  v0, zero, $ffff (=-$1)
8006FFD8	ori    a1, zero, $0002
8006FFDC	addiu  s0, s0, $ff90 (=-$70)

loop6ffe0:	; 8006FFE0
8006FFE0	sh     v0, $0000(s0)
8006FFE4	addiu  a1, a1, $ffff (=-$1)
8006FFE8	bgez   a1, loop6ffe0 [$8006ffe0]
8006FFEC	addiu  s0, s0, $fffe (=-$2)
8006FFF0	ori    a3, zero, $001d
8006FFF4	ori    a1, zero, $000f
8006FFF8	lui    v1, $800b
8006FFFC	addiu  v1, v1, $16a8
80070000	addiu  a2, v1, $00ba
80070004	ori    a0, zero, $1000
80070008	ori    v0, zero, $0001
8007000C	lui    at, $800b
80070010	sh     v0, $d0e0(at)
80070014	ori    v0, zero, $0720
80070018	lui    at, $800b
8007001C	sh     a0, $ee0e(at)
80070020	sh     v0, $0000(v1)
80070024	ori    v0, zero, $0100
80070028	lui    at, $800b
8007002C	sh     v0, $1678(at)
80070030	lui    at, $800b
80070034	sh     v0, $1676(at)
80070038	lui    at, $800b
8007003C	sh     v0, $1674(at)
80070040	ori    v0, zero, $0200
80070044	lui    at, $800b
80070048	sh     v0, $167e(at)
8007004C	lui    at, $800b
80070050	sh     v0, $167c(at)
80070054	lui    at, $800b
80070058	sh     v0, $167a(at)
8007005C	ori    v0, zero, $0080
80070060	lui    at, $800b
80070064	sh     v0, $1688(at)
80070068	ori    v0, zero, $00ff
8007006C	lui    at, $800b
80070070	sw     v0, $d09c(at)
80070074	addiu  v0, zero, $ffff (=-$1)
80070078	lui    at, $800b
8007007C	sh     a0, $1660(at)
80070080	lui    at, $800b
80070084	sh     zero, $1658(at)
80070088	lui    at, $800b
8007008C	sh     zero, $165a(at)
80070090	lui    at, $800b
80070094	sh     zero, $165c(at)
80070098	lui    at, $800b
8007009C	sw     v0, $d044(at)

loop700a0:	; 800700A0
800700A0	sh     a3, $0000(a2)
800700A4	addiu  a1, a1, $ffff (=-$1)
800700A8	bgez   a1, loop700a0 [$800700a0]
800700AC	addiu  a2, a2, $fffe (=-$2)
800700B0	lui    v1, $8005
800700B4	lw     v1, $e9b0(v1)
800700B8	ori    v0, zero, $001d
800700BC	lui    at, $800b
800700C0	sh     v0, $1764(at)
800700C4	addiu  v0, zero, $ffff (=-$1)
800700C8	lui    at, $800b
800700CC	sw     v0, $d0c4(at)
800700D0	ori    v0, zero, $0002
800700D4	lui    at, $800b
800700D8	sw     v0, $16ac(at)
800700DC	ori    v0, zero, $ffff
800700E0	lui    at, $800b
800700E4	sh     v0, $164e(at)
800700E8	ori    v0, zero, $0080
800700EC	lui    at, $800b
800700F0	sb     v0, $1666(at)
800700F4	lui    at, $800b
800700F8	sb     v0, $1665(at)
800700FC	lui    at, $800b
80070100	sb     v0, $1664(at)
80070104	ori    v0, zero, $00ff
80070108	lui    at, $800b
8007010C	sb     v0, $166a(at)
80070110	lui    at, $800b
80070114	sb     v0, $1669(at)
80070118	lui    at, $800b
8007011C	sb     v0, $1668(at)
80070120	ori    v0, zero, $15e0
80070124	lui    at, $800b
80070128	sh     v0, $166c(at)
8007012C	ori    v0, zero, $300c
80070130	lui    at, $800b
80070134	sh     v0, $166e(at)
80070138	ori    v0, zero, $0008
8007013C	lui    at, $800b
80070140	sw     zero, $cfe0(at)
80070144	lui    at, $800b
80070148	sw     zero, $d0e4(at)
8007014C	lui    at, $800b
80070150	sh     zero, $f37c(at)
80070154	lui    at, $800b
80070158	sw     zero, $1740(at)
8007015C	lui    at, $800b
80070160	sh     zero, $164c(at)
80070164	lui    at, $800b
80070168	sh     zero, $1648(at)
8007016C	lui    at, $800b
80070170	sh     zero, $164a(at)
80070174	lui    at, $800b
80070178	sw     zero, $1654(at)
8007017C	lui    at, $800b
80070180	sw     zero, $1650(at)
80070184	lui    at, $800b
80070188	sh     zero, $1662(at)
8007018C	lui    at, $800b
80070190	sh     v0, $16aa(at)
80070194	bne    v1, zero, L701cc [$800701cc]
80070198	addu   a1, zero, zero
8007019C	ori    a2, zero, $00ff
800701A0	lui    a0, $8007
800701A4	addiu  a0, a0, $f020 (=-$fe0)
800701A8	lui    v1, $8006
800701AC	addiu  v1, v1, $9ad4 (=-$652c)

loop701b0:	; 800701B0
800701B0	sw     a2, $0000(v1)
800701B4	sw     a2, $0000(a0)
800701B8	addiu  a0, a0, $0004
800701BC	addiu  a1, a1, $0001
800701C0	slti   v0, a1, $0003
800701C4	bne    v0, zero, loop701b0 [$800701b0]
800701C8	addiu  v1, v1, $0004

L701cc:	; 800701CC
800701CC	ori    v1, zero, $ffff
800701D0	ori    a1, zero, $001f
800701D4	lui    v0, $800b
800701D8	addiu  v0, v0, $17b2

loop701dc:	; 800701DC
800701DC	sh     v1, $0000(v0)
800701E0	addiu  a1, a1, $ffff (=-$1)
800701E4	bgez   a1, loop701dc [$800701dc]
800701E8	addiu  v0, v0, $fffe (=-$2)
800701EC	addu   a1, zero, zero
800701F0	lui    v0, $800c
800701F4	addiu  v0, v0, $2f3c
800701F8	addiu  a2, v0, $0400
800701FC	addu   v1, v0, zero
80070200	lui    a0, $8006
80070204	lw     a0, $9a38(a0)
80070208	ori    v0, zero, $0002
8007020C	lui    at, $800b
80070210	sw     zero, $1770(at)
80070214	lui    at, $800b
80070218	sw     zero, $176c(at)
8007021C	lui    at, $8005
80070220	sw     v0, $f7a4(at)

loop70224:	; 80070224
80070224	lhu    v0, $1930(a0)
80070228	addiu  a0, a0, $0002
8007022C	addiu  a1, a1, $0001
80070230	sh     v0, $0000(v1)
80070234	sh     zero, $0000(a2)
80070238	addiu  a2, a2, $0002
8007023C	slti   v0, a1, $0200
80070240	bne    v0, zero, loop70224 [$80070224]
80070244	addiu  v1, v1, $0002
80070248	jal    func49ff4 [$80049ff4]
8007024C	ori    a0, zero, $0200
80070250	lui    s0, $800b
80070254	addiu  s0, s0, $ee64 (=-$119c)
80070258	jal    func6fc24 [$8006fc24]
8007025C	addu   a0, s0, zero
80070260	lui    a0, $800b
80070264	addiu  a0, a0, $ed30 (=-$12d0)
80070268	jal    func6fc24 [$8006fc24]
8007026C	addiu  s1, s0, $00d4
80070270	jal    func6fc24 [$8006fc24]
80070274	addu   a0, s1, zero
80070278	jal    func6fc24 [$8006fc24]
8007027C	addiu  a0, s0, $0114
80070280	addiu  a0, s0, $00c4
80070284	ori    v0, zero, $3000
80070288	sh     zero, $00c4(s0)
8007028C	lui    at, $800b
80070290	sh     zero, $ef2a(at)
80070294	lui    at, $800b
80070298	sh     zero, $ef2c(at)
8007029C	lui    at, $800b
800702A0	sh     zero, $ef30(at)
800702A4	lui    at, $800b
800702A8	sh     zero, $ef32(at)
800702AC	lui    at, $800b
800702B0	sh     zero, $ef34(at)
800702B4	lui    at, $800b
800702B8	sw     v0, $ef98(at)
800702BC	jal    func3f5e0 [$8003f5e0]
800702C0	addu   a1, s1, zero
800702C4	lui    v0, $800b
800702C8	addiu  v0, v0, $1970
800702CC	lui    at, $800c
800702D0	sw     v0, $3740(at)
800702D4	jal    func71bdc [$80071bdc]
800702D8	nop
800702DC	jal    func70314 [$80070314]
800702E0	nop
800702E4	jal    func85ac8 [$80085ac8]
800702E8	nop
800702EC	jal    funca874c [$800a874c]
800702F0	nop
800702F4	jal    funcab1f0 [$800ab1f0]
800702F8	nop
////////////////////////////////



////////////////////////////////
// func6f71c
A0 = A1;
A1 = A2;
system_extract_archive;
////////////////////////////////



////////////////////////////////
// func6f47c
S0 = A0; // pointer to field +154

S1 = 800aee64;

A0 = S1;
A1 = S1 - 110;
A2 = S1 - 100;
A3 = S1 - f0;
8006F4A8	jal    func72de0 [$80072de0]

S2 = S1 + d4;

A0 = S1 + c4; // rot data
A1 = S1 + d4;
func3f5e0; // calculate rotation matrix

A0 = S1;
A1 = S1 + d4;
8006F4C4	jal    func49a84 [$80049a84]

V0 = h[S0];
S0 = S0 + 2;
[S1 + 138] = w(V0);
8006F4D4	addu   a0, zero, zero
8006F4D8	addiu  a1, s1, $0138

8006F4E0	lh     v0, $0000(s0)
8006F4E4	addiu  s0, s0, $0002
8006F4E8	lui    at, $800b
8006F4EC	sw     v0, $efa0(at)
8006F4F0	lh     v0, $0000(s0)
8006F4F4	addiu  s0, s0, $0004
8006F4F8	lui    at, $800b
8006F4FC	sw     v0, $efa4(at)
8006F500	lhu    v0, $0000(s0)
8006F504	addiu  s0, s0, $0002
8006F508	sll    v0, v0, $03
8006F50C	lui    at, $800b
8006F510	sh     v0, $efa8(at)
8006F514	lhu    v0, $0000(s0)
8006F518	addiu  s0, s0, $0002
8006F51C	sll    v0, v0, $03
8006F520	lui    at, $800b
8006F524	sh     v0, $efaa(at)
8006F528	lhu    v0, $0000(s0)
8006F52C	nop
8006F530	sll    v0, v0, $03
8006F534	lui    at, $800b
8006F538	sh     v0, $efac(at)
8006F53C	jal    func30840 [$80030840]
8006F540	addiu  s0, s0, $0004
8006F544	lh     v0, $0000(s0)
8006F548	addiu  s0, s0, $0002
8006F54C	ori    a0, zero, $0001
8006F550	addiu  a1, s1, $014c
8006F554	sw     v0, $014c(s1)
8006F558	lh     v0, $0000(s0)
8006F55C	addiu  s0, s0, $0002
8006F560	lui    at, $800b
8006F564	sw     v0, $efb4(at)
8006F568	lh     v0, $0000(s0)
8006F56C	addiu  s0, s0, $0004
8006F570	lui    at, $800b
8006F574	sw     v0, $efb8(at)
8006F578	lhu    v0, $0000(s0)
8006F57C	addiu  s0, s0, $0002
8006F580	sll    v0, v0, $03
8006F584	lui    at, $800b
8006F588	sh     v0, $efbc(at)
8006F58C	lhu    v0, $0000(s0)
8006F590	addiu  s0, s0, $0002
8006F594	sll    v0, v0, $03
8006F598	lui    at, $800b
8006F59C	sh     v0, $efbe(at)
8006F5A0	lhu    v0, $0000(s0)
8006F5A4	nop
8006F5A8	sll    v0, v0, $03
8006F5AC	lui    at, $800b
8006F5B0	sh     v0, $efc0(at)
8006F5B4	jal    func30840 [$80030840]
8006F5B8	addiu  s0, s0, $0004
8006F5BC	lh     v0, $0000(s0)
8006F5C0	addiu  s0, s0, $0002
8006F5C4	ori    a0, zero, $0002
8006F5C8	addiu  a1, s1, $0160
8006F5CC	sw     v0, $0160(s1)
8006F5D0	lh     v0, $0000(s0)
8006F5D4	addiu  s0, s0, $0002
8006F5D8	lui    at, $800b
8006F5DC	sw     v0, $efc8(at)
8006F5E0	lh     v0, $0000(s0)
8006F5E4	addiu  s0, s0, $0004
8006F5E8	lui    at, $800b
8006F5EC	sw     v0, $efcc(at)
8006F5F0	lhu    v0, $0000(s0)
8006F5F4	addiu  s0, s0, $0002
8006F5F8	sll    v0, v0, $03
8006F5FC	lui    at, $800b
8006F600	sh     v0, $efd0(at)
8006F604	lhu    v0, $0000(s0)
8006F608	addiu  s0, s0, $0002
8006F60C	sll    v0, v0, $03
8006F610	lui    at, $800b
8006F614	sh     v0, $efd2(at)
8006F618	lhu    v0, $0000(s0)
8006F61C	nop
8006F620	sll    v0, v0, $03
8006F624	lui    at, $800b
8006F628	sh     v0, $efd4(at)
8006F62C	lw     v0, $0138(s1)
8006F630	lw     v1, $013c(s1)

L6f634:	; 8006F634
8006F634	lw     a2, $0140(s1)
8006F638	lw     a3, $0144(s1)
8006F63C	sw     v0, $014c(s1)
8006F640	sw     v1, $0150(s1)
8006F644	sw     a2, $0154(s1)
8006F648	sw     a3, $0158(s1)
8006F64C	lw     v0, $0148(s1)
8006F650	nop
8006F654	sw     v0, $015c(s1)
8006F658	lw     v0, $0138(s1)
8006F65C	lw     v1, $013c(s1)
8006F660	lw     a2, $0140(s1)

L6f664:	; 8006F664
8006F664	lw     a3, $0144(s1)
8006F668	sw     v0, $0160(s1)
8006F66C	sw     v1, $0164(s1)
8006F670	sw     a2, $0168(s1)
8006F674	sw     a3, $016c(s1)
8006F678	lw     v0, $0148(s1)
8006F67C	nop
8006F680	sw     v0, $0170(s1)
8006F688	addiu  s0, s0, $0004
8006F684	jal    func30840 [$80030840]

8006F68C	lhu    v0, $0000(s0)
8006F690	nop
8006F694	sll    v0, v0, $04
8006F698	lui    at, $800b
8006F69C	sh     v0, $efd8(at)
8006F6A0	lhu    v0, $0002(s0)
8006F6A4	nop
8006F6A8	sll    v0, v0, $04
8006F6AC	lui    at, $800b
8006F6B0	sh     v0, $efda(at)
8006F6B4	lhu    v0, $0004(s0)
8006F6B8	nop
8006F6BC	sll    v0, v0, $04
8006F6C0	lui    at, $800b
8006F6C4	sh     v0, $efdc(at)

A0 = S1;
system_gte_set_rotation_matrix;

A0 = S1;
system_gte_set_translation_vector;

A0 = S1 + cc;
A1 = S1 + e8;
A2 = SP + 10;
8006F6E0	jal    func4a584 [$8004a584]

A0 = S2; // original light matrix without rotation.
system_gte_calculate_and_set_lighting_matrix;

A0 = S2;
system_gte_set_rotation_matrix;

A0 = S2;
system_gte_set_translation_vector;
////////////////////////////////
