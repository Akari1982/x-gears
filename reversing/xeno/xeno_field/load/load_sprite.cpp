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

800A5234	lui    a0, $8006
800A5238	lw     a0, $9b70(a0)
800A523C	jal    func31ec8 [$80031ec8]
800A5240	nop
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
80070378	lui    a1, $8007
8007037C	addiu  a1, a1, $f184 (=-$e7c)
80070380	lw     v0, $0000(a1)
80070384	lw     v1, $0004(a1)
80070388	lw     a0, $0008(a1)
8007038C	sw     v0, $0038(sp)
80070390	sw     v1, $003c(sp)
80070394	sw     a0, $0040(sp)
80070398	lw     v0, $000c(a1)
800703A0	sw     v0, $0044(sp)
800703A4	jal    func6fc6c [$8006fc6c]

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

8007044C	addu   s4, zero, zero
80070450	lui    s2, $800b
80070454	addiu  s2, s2, $fb90 (=-$470)
80070458	addu   s0, zero, zero

loop7045c:	; 8007045C
8007045C	sll    s1, s4, $02
80070460	addu   v0, s1, s0

loop70464:	; 80070464
80070464	sll    a0, v0, $03
80070468	subu   a0, a0, v0
8007046C	sll    a0, a0, $04
80070470	addu   a0, a0, s2
80070474	addu   a1, s0, zero
80070478	addu   a2, s4, zero
80070480	addu   a3, zero, zero
8007047C	jal    func79e08 [$80079e08]

80070484	addiu  s0, s0, $0001
80070488	slti   v0, s0, $0004
80070490	addu   v0, s1, s0
8007048C	bne    v0, zero, loop70464 [$80070464]

80070494	addiu  s4, s4, $0001
80070498	slti   v0, s4, $0004
800704A0	addu   s0, zero, zero
8007049C	bne    v0, zero, loop7045c [$8007045c]

800704A4	lui    s0, $800b
800704A8	addiu  s0, s0, $0290
800704AC	addu   a0, s0, zero
800704B0	ori    a1, zero, $0004
800704B4	ori    a2, zero, $0004
800704BC	ori    a3, zero, $0001
800704B8	jal    func79e08 [$80079e08]

800704C0	addiu  a0, s0, $0070
800704C4	ori    a1, zero, $0005
800704C8	ori    a2, zero, $0005
800704D0	ori    a3, zero, $0001
800704CC	jal    func79e08 [$80079e08]

800704D4	addiu  a0, s0, $00e0
800704D8	ori    a1, zero, $0006
800704DC	ori    a2, zero, $0006
800704E4	ori    a3, zero, $0001
800704E0	jal    func79e08 [$80079e08]

800704E8	addiu  a0, s0, $0150
800704EC	ori    a1, zero, $0007
800704F0	ori    a2, zero, $0007
800704F8	ori    a3, zero, $0001
800704F4	jal    func79e08 [$80079e08]

800704FC	addiu  a0, s0, $01c0
80070500	ori    a1, zero, $0008
80070504	ori    a2, zero, $0008
8007050C	ori    a3, zero, $0001
80070508	jal    func79e08 [$80079e08]

80070510	jal    func79bd8 [$80079bd8]



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



// sprite texture
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



80070640	lui    v0, $8006
80070644	lw     v0, $9b70(v0)
80070648	nop
8007064C	lw     v0, $0114(v0)
80070650	addu   a1, zero, zero
80070654	addiu  s0, v0, $0010
80070658	jal    system_memory_allocate [$800319ec]
8007065C	addu   a0, s0, zero
80070660	addu   a0, s0, zero
80070664	lui    v1, $8006
80070668	lw     v1, $9b70(v1)
8007066C	lui    s0, $800b
80070670	addiu  s0, s0, $efe8 (=-$1018)
80070674	sw     v0, $0000(s0)
80070678	lw     a1, $0138(v1)
8007067C	addu   a2, v0, zero
80070684	addu   a1, a1, v1
A0 = A1;
A1 = A2;
system_extract_archive;

80070688	lui    v0, $800b
8007068C	lw     v0, $efe8(v0)
80070690	nop
80070694	lw     v0, $0000(v0)
80070698	lw     s2, $0000(s0)
8007069C	blez   v0, L706dc [$800706dc]
800706A0	addu   s4, zero, zero
800706A4	addiu  s2, s2, $0004

loop706a8:	; 800706A8
    800706A8	lw     v0, $0000(s2)
    800706AC	lui    a0, $800b
    800706B0	lw     a0, $efe8(a0)
    800706B4	jal    func2c1f8 [$8002c1f8]
    800706B8	addu   a0, v0, a0
    800706BC	lui    v0, $800b
    800706C0	lw     v0, $efe8(v0)
    800706C4	nop
    800706C8	lw     v0, $0000(v0)
    800706CC	addiu  s4, s4, $0001
    800706D0	slt    v0, s4, v0
    800706D8	addiu  s2, s2, $0004
800706D4	bne    v0, zero, loop706a8 [$800706a8]



L706dc:	; 800706DC
A1 = w[80059b70];
A0 = A1 + w[A1 + 148];
A1 = 80064f6c;
system_extract_archive;

V0 = w[80059b70];
V0 = w[V0 + 120];
S0 = V0 + 10;

A0 = S0;
A1 = 0;
system_memory_allocate;
[800ad0d0] = w(V0); // pointer to field entity file (file 5).

V1 = w[80059b70];
A0 = V1 + w[V1 + 144];
A1 = V0;
system_extract_archive;

80070744	lui    v0, $800b

L70748:	; 80070748
80070748	lw     v0, $d0d0(v0)
8007074C	lui    a0, $8006
80070750	lw     a0, $9b70(a0)
80070754	lw     v1, $0080(v0)
80070758	addiu  v0, v0, $0084
8007075C	lui    at, $800b
80070760	sw     v1, $d0d4(at)
80070764	sll    v1, v1, $06
80070768	addu   v0, v0, v1
8007076C	lui    at, $800b
80070770	sw     v0, $d0d8(at)
80070774	lw     v0, $012c(a0)
80070778	addu   a1, zero, zero
8007077C	addiu  s0, v0, $0010
80070780	jal    system_memory_allocate [$800319ec]
80070784	addu   a0, s0, zero
80070788	lui    v1, $8006
8007078C	lw     v1, $9b70(v1)
80070790	addu   a0, s0, zero
80070794	lui    at, $800b
80070798	sw     v0, $d0cc(at)
8007079C	lw     a1, $0150(v1)
800707A0	addu   a2, v0, zero
800707A8	addu   a1, a1, v1
A0 = A1;
A1 = A2;
system_extract_archive;

800707AC	lui    v0, $8006
800707B0	lw     v0, $9b70(v0)
800707B4	nop
800707B8	lw     v0, $0128(v0)
800707BC	addu   a1, zero, zero
800707C0	addiu  s0, v0, $0010
800707C4	jal    system_memory_allocate [$800319ec]
800707C8	addu   a0, s0, zero
800707CC	lui    v1, $8006
800707D0	lw     v1, $9b70(v1)
800707D4	addu   a0, s0, zero
800707D8	lui    at, $800b
800707DC	sw     v0, $d0c8(at)
800707E0	lw     a1, $014c(v1)
800707E4	addu   a2, v0, zero
800707EC	addu   a1, a1, v1
A0 = A1;
A1 = A2;
system_extract_archive;

800707F0	lui    v0, $8006
800707F4	lw     v0, $9b70(v0)
800707F8	addu   s4, zero, zero
800707FC	lw     v0, $0110(v0)
80070800	addu   a1, zero, zero
80070804	addiu  s0, v0, $0010
80070808	jal    system_memory_allocate [$800319ec]
8007080C	addu   a0, s0, zero
80070810	addu   a0, s0, zero
80070814	lui    v1, $8006
80070818	lw     v1, $9b70(v1)
8007081C	lui    s0, $800b
80070820	addiu  s0, s0, $efec (=-$1014)
80070824	sw     v0, $0000(s0)
80070828	lw     a1, $0134(v1)
8007082C	addu   a2, v0, zero
80070834	addu   a1, a1, v1
A0 = A1;
A1 = A2;
system_extract_archive;

80070838	lui    a0, $9249

L7083c:	; 8007083C
8007083C	ori    a0, a0, $2493
80070840	addiu  v1, s0, $002c
80070844	lui    v0, $800b
80070848	lw     v0, $efec(v0)
8007084C	lw     s2, $0000(s0)
80070850	lw     v0, $0000(v0)
80070854	addiu  s2, s2, $0004
80070858	lui    at, $800b
8007085C	sh     v0, $f028(at)

loop70860:	; 80070860
80070860	lw     v0, $0000(s2)
80070864	nop
80070868	srl    v0, v0, $01
8007086C	multu  v0, a0
80070870	addiu  s2, s2, $0004
80070874	addiu  s4, s4, $0001
80070878	mfhi   t5
8007087C	srl    v0, t5, $02
80070880	sw     v0, $0000(v1)
80070884	slti   v0, s4, $0004
80070888	bne    v0, zero, loop70860 [$80070860]
8007088C	addiu  v1, v1, $0004
80070890	lui    a2, $800b
80070894	addiu  a2, a2, $eff4 (=-$100c)
80070898	lw     v0, $0000(s2)
8007089C	addiu  s2, s2, $0004
800708A0	addu   s4, zero, zero
800708A4	lui    v1, $800b
800708A8	lw     v1, $efec(v1)
800708AC	lui    a0, $800b
800708B0	lh     a0, $f028(a0)
800708B4	addu   v0, v0, v1
800708B8	blez   a0, L70910 [$80070910]
800708BC	sw     v0, $0000(a2)
800708C0	addiu  a1, a2, $0014
800708C4	addiu  a2, a2, $0004
800708C8	addu   a0, a2, zero

loop708cc:	; 800708CC
800708CC	lw     v0, $0000(s2)
800708D0	addiu  s2, s2, $0004
800708D4	lw     v1, $fff4(a2)
800708D8	addiu  s4, s4, $0001
800708DC	addu   v0, v0, v1
800708E0	sw     v0, $0000(a0)
800708E4	lw     v0, $0000(s2)
800708E8	addiu  s2, s2, $0004
800708EC	lw     v1, $fff4(a2)
800708F0	addiu  a0, a0, $0004
800708F4	addu   v0, v0, v1
800708F8	sw     v0, $0000(a1)
800708FC	lh     v0, $0030(a2)
80070900	nop
80070904	slt    v0, s4, v0
80070908	bne    v0, zero, loop708cc [$800708cc]
8007090C	addiu  a1, a1, $0004

L70910:	; 80070910

80070910	lui    v0, $800b
80070914	lw     v0, $eff8(v0)
80070918	lui    v1, $800b
8007091C	lw     v1, $eff4(v1)
80070924	subu   v0, v0, v1
[800af1e4] = w(V0 >> 2);
S4 = 0;



// sprite data
V1 = w[80059b70];
A0 = w[V1 + 118] + 10;
A1 = 0;
system_memory_allocate;
[800aeff0] = w(V0);

V1 = w[80059b70];
A0 = V1 + w[V1 + 13c];
A1 = V0;
system_extract_archive;



80070974	lui    a0, $8006
80070978	lw     a0, $9b70(a0)
8007097C	ori    v0, zero, $0001
80070980	lui    at, $800b
80070984	sh     v0, $eeb0(at)
80070988	lui    at, $800b
8007098C	sh     v0, $eeb2(at)
80070990	lui    at, $800b
80070994	sh     v0, $eeb4(at)
80070998	lui    at, $800b
8007099C	sh     v0, $eeb6(at)
800709A4	addiu  a0, a0, $0154
800709A0	jal    func6f47c [$8006f47c]

800709A8	lui    v0, $8006
800709AC	lw     v0, $9b70(v0)
800709B0	addu   a1, zero, zero
800709B4	lhu    s3, $018c(v0)
800709B8	addiu  s5, v0, $0190
800709BC	sll    s0, s3, $01
800709C0	addu   s0, s0, s3
800709C4	sll    s0, s0, $03
800709C8	subu   s0, s0, s3
800709CC	lui    at, $800b
800709D0	sw     s3, $efe0(at)
800709D4	jal    system_memory_allocate [$800319ec]
800709D8	sll    a0, s0, $02
800709DC	addu   v1, v0, zero
800709E0	lui    at, $800b
800709E4	sw     v1, $efe4(at)
800709E8	blez   s0, L70a04 [$80070a04]
800709EC	nop

loop709f0:	; 800709F0
800709F0	sw     zero, $0000(v1)
800709F4	addiu  s4, s4, $0001
800709F8	slt    v0, s4, s0
800709FC	bne    v0, zero, loop709f0 [$800709f0]
80070A00	addiu  v1, v1, $0004

L70a04:	; 80070A04
80070A04	lui    v0, $800b
80070A08	lw     v0, $efe0(v0)
80070A0C	nop
80070A10	blez   v0, L70c30 [$80070c30]
80070A14	addu   s4, zero, zero
80070A18	addu   s2, zero, zero

L70a1c:	; 80070A1C
80070A1C	lui    v0, $800b
80070A20	lw     v0, $efe4(v0)
80070A24	lhu    v1, $0000(s5)
80070A28	addiu  s5, s5, $0002
80070A2C	addu   v0, s2, v0
80070A30	sh     v1, $0058(v0)
80070A34	lui    v0, $800b
80070A38	lw     v0, $efe4(v0)
80070A3C	lhu    v1, $0000(s5)
80070A40	addu   v0, s2, v0
80070A44	sh     v1, $0050(v0)
80070A48	lui    v0, $800b
80070A4C	lw     v0, $efe4(v0)
80070A50	lhu    v1, $0002(s5)
80070A54	addu   v0, s2, v0
80070A58	sh     v1, $0052(v0)
80070A5C	lui    v0, $800b
80070A60	lw     v0, $efe4(v0)
80070A64	lhu    v1, $0004(s5)
80070A68	addiu  s5, s5, $0006
80070A6C	addu   v0, s2, v0
80070A70	sh     v1, $0054(v0)
80070A74	lui    v0, $800b
80070A78	lw     v0, $efe4(v0)
80070A7C	lhu    v1, $0000(s5)
80070A80	addu   v0, s2, v0
80070A84	sw     v1, $0020(v0)
80070A88	sw     v1, $0040(v0)
80070A8C	lui    v0, $800b
80070A90	lw     v0, $efe4(v0)
80070A94	lhu    v1, $0002(s5)
80070A98	addu   v0, s2, v0
80070A9C	sw     v1, $0024(v0)
80070AA0	sw     v1, $0044(v0)
80070AA4	lui    v0, $800b
80070AA8	lw     v0, $efe4(v0)
80070AAC	lhu    v1, $0004(s5)
80070AB0	addu   v0, s2, v0
80070AB4	sw     v1, $0028(v0)
80070AB8	sw     v1, $0048(v0)
80070ABC	lui    v0, $800b
80070AC0	lw     v0, $efe4(v0)
80070AC4	nop
80070AC8	addu   a0, s2, v0
80070ACC	lhu    v1, $0058(a0)
80070AD0	nop
80070AD4	andi   v0, v1, $0040
80070AD8	bne    v0, zero, L70bcc [$80070bcc]
80070ADC	addiu  s5, s5, $0006
80070AE0	ori    a0, zero, $0024
80070AE4	jal    system_memory_allocate [$800319ec]
80070AE8	addu   a1, zero, zero
80070AEC	addu   s0, v0, zero
80070AF0	lui    v0, $800b
80070AF4	lw     v0, $efe4(v0)
80070AF8	addiu  a1, s0, $0008
80070AFC	addu   v0, s2, v0
80070B00	sw     s0, $0000(v0)
80070B04	lhu    v0, $0000(s5)
80070B08	lui    v1, $800b
80070B0C	lw     v1, $efe8(v1)
80070B10	sll    v0, v0, $02
80070B14	addu   s1, v0, v1
80070B18	lw     v0, $0004(s1)
80070B1C	addiu  a2, s0, $000c
80070B20	addu   v0, v0, v1
80070B24	addiu  a0, v0, $0010
80070B2C	sw     a0, $0004(s0)
system_allocate_memory_for_packets; // allocate place for packets

80070B30	lui    v0, $800b
80070B34	lw     v0, $efe4(v0)
80070B38	lw     a0, $0004(s0)
80070B3C	addu   v0, s2, v0
80070B40	lhu    a2, $0058(v0)
80070B44	lw     a1, $0008(s0)
80070B48	andi   a2, a2, $000c
80070B50	srl    a2, a2, $02
system_fill_packets_drafts_for_model_part;

80070B54	lw     a0, $000c(s0)
80070B58	lw     v0, $0004(s0)
80070B5C	lw     a1, $0008(s0)
80070B60	lw     a2, $0034(v0)
80070B64	jal    system_copy_memory [$8003f810]
80070B68	nop
80070B6C	lui    v0, $800b
80070B70	lw     v0, $efe4(v0)
80070B74	nop
80070B78	addu   v0, s2, v0
80070B7C	lhu    v0, $0058(v0)
80070B80	nop
80070B84	andi   v0, v0, $2000
80070B88	beq    v0, zero, L70bb8 [$80070bb8]
80070B8C	nop
80070B90	ori    a0, zero, $0003
80070B94	jal    func322bc [$800322bc]
80070B98	addu   a1, zero, zero
80070B9C	lw     a0, $0004(s0)
80070BA0	jal    func301d8 [$800301d8]
80070BA4	addu   a1, zero, zero
80070BA8	ori    a0, zero, $0008
80070BAC	addu   a1, zero, zero
80070BB0	jal    func322bc [$800322bc]
80070BB4	sw     v0, $0014(s0)

L70bb8:	; 80070BB8
80070BB8	lw     a0, $0004(s0)
80070BBC	jal    func2c454 [$8002c454]
80070BC0	nop
80070BC4	j      L70c10 [$80070c10]
80070BC8	addu   a0, s4, zero

L70bcc:	; 80070BCC
80070BCC	ori    v0, v1, $0020
80070BD0	sh     v0, $0058(a0)
80070BD4	lui    v0, $800b
80070BD8	lw     v0, $efe4(v0)
80070BDC	nop
80070BE0	addu   v0, s2, v0
80070BE4	sh     zero, $0050(v0)
80070BE8	lui    v0, $800b
80070BEC	lw     v0, $efe4(v0)
80070BF0	nop
80070BF4	addu   v0, s2, v0
80070BF8	sh     zero, $0052(v0)
80070BFC	lui    v0, $800b
80070C00	lw     v0, $efe4(v0)
80070C04	addu   a0, s4, zero
80070C08	addu   v0, s2, v0
80070C0C	sh     zero, $0054(v0)

L70c10:	; 80070C10
80070C10	jal    func80558 [$80080558]
80070C14	addiu  s5, s5, $0002
80070C18	lui    v0, $800b
80070C1C	lw     v0, $efe0(v0)
80070C20	addiu  s4, s4, $0001
80070C24	slt    v0, s4, v0
80070C28	bne    v0, zero, L70a1c [$80070a1c]
80070C2C	addiu  s2, s2, $005c

L70c30:	; 80070C30
80070C30	lui    v0, $800c
80070C34	lw     v0, $1b60(v0)
80070C38	nop
80070C3C	bne    v0, zero, L70c4c [$80070c4c]
80070C40	nop
80070C44	0C0A04AF	Ї...
80070C48	nop

L70c4c:	; 80070C4C
80070C4C	jal    func7d4e0 [$8007d4e0]
80070C50	nop
80070C54	jal    func710f4 [$800710f4]
80070C58	nop
80070C5C	lui    a0, $8006
80070C60	lw     a0, $9b70(a0)
[A0 - 4] = w(w[A0 - 4] & fdffffff);

80070C6C	lui    a0, $8006
80070C70	lw     a0, $9b70(a0)
80070C74	jal    func31f0c [$80031f0c]
80070C78	nop
80070C7C	ori    a0, zero, $0005

L70c80:	; 80070C80
80070C80	jal    func322bc [$800322bc]
80070C84	addu   a1, zero, zero
80070C88	ori    a0, zero, $3c00
80070C8C	jal    func24d5c [$80024d5c]
80070C90	addu   a1, zero, zero
80070C94	jal    func1c7d0 [$8001c7d0]
80070C98	nop
80070C9C	ori    a0, zero, $0008
80070CA0	jal    func322bc [$800322bc]
80070CA4	addu   a1, zero, zero
80070CA8	lui    s0, $800b
80070CAC	addiu  s0, s0, $1710
80070CB0	addu   a0, s0, zero
80070CB4	ori    a1, zero, $0800
80070CB8	addu   a2, zero, zero
80070CBC	addu   a3, zero, zero
80070CC0	ori    v0, zero, $0800
80070CC4	sw     v0, $0010(sp)
80070CC8	sw     zero, $0014(sp)
80070CCC	sw     zero, $0018(sp)
80070CD0	sw     v0, $001c(sp)
80070CD4	sw     zero, $0020(sp)
80070CD8	jal    func76ed4 [$80076ed4]
80070CDC	sw     zero, $0024(sp)
80070CE0	addiu  a0, s0, $ffe0 (=-$20)
80070CE4	ori    a1, zero, $01f8
80070CE8	addiu  a2, zero, $f03f (=-$fc1)
80070CEC	addiu  a3, zero, $fe08 (=-$1f8)
80070CF0	sw     zero, $0010(sp)
80070CF4	sw     zero, $0014(sp)
80070CF8	sw     zero, $0018(sp)
80070CFC	sw     zero, $001c(sp)
80070D00	sw     zero, $0020(sp)
80070D04	jal    func76ed4 [$80076ed4]
80070D08	sw     zero, $0024(sp)
80070D0C	ori    v0, zero, $001e
80070D10	lui    s2, $800b
80070D14	addiu  s2, s2, $f558 (=-$aa8)
80070D18	lui    at, $800b
80070D1C	sb     v0, $1732(at)
80070D20	lui    at, $800b
80070D24	sb     v0, $1731(at)
80070D28	lui    at, $800b
80070D2C	sb     v0, $1730(at)
80070D30	ori    v0, zero, $0140
80070D34	sh     v0, $0000(s2)
80070D38	ori    v0, zero, $1000
80070D3C	lui    at, $800b
80070D40	sh     zero, $f562(at)
80070D44	lui    at, $800b
80070D48	sb     zero, $f57d(at)
80070D4C	lui    at, $800b
80070D50	sb     zero, $f57c(at)
80070D54	lui    at, $800b
80070D58	sb     zero, $f57a(at)
80070D5C	lui    at, $800b
80070D60	sb     zero, $f579(at)
80070D64	lui    at, $800b
80070D68	sb     zero, $f578(at)
80070D6C	lui    at, $800b
80070D70	sb     zero, $f576(at)
80070D74	lui    at, $800b
80070D78	sb     zero, $f575(at)
80070D7C	sb     zero, $001c(s2)
80070D80	sw     zero, $000c(s2)
80070D84	lui    at, $800b
80070D88	sw     v0, $f56c(at)
80070D8C	ori    v0, zero, $0020
80070D90	lui    at, $800b
80070D94	sh     zero, $f584(at)
80070D98	lui    at, $800b
80070D9C	sh     zero, $f582(at)
80070DA0	lui    at, $800b
80070DA4	sh     zero, $f580(at)
80070DA8	lui    at, $800b
80070DAC	sh     zero, $f560(at)
80070DB0	lui    at, $800b
80070DB4	sh     zero, $f55e(at)
80070DB8	lui    at, $800b
80070DBC	sh     zero, $f55c(at)
80070DC0	lui    at, $800b
80070DC4	sh     zero, $f55a(at)
80070DC8	lui    at, $800b
80070DCC	sh     zero, $f556(at)
80070DD0	lui    at, $800b
80070DD4	sh     zero, $f554(at)
80070DD8	lui    at, $800b
80070DDC	sh     zero, $f586(at)
80070DE0	lui    at, $800b
80070DE4	sw     zero, $f568(at)
80070DE8	lui    at, $800b
80070DEC	sb     v0, $f57e(at)
80070DF0	lui    at, $800b
80070DF4	sw     zero, $cff4(at)
80070DF8	jal    funca1e64 [$800a1e64]
80070DFC	addiu  s1, s2, $000c
80070E00	lui    a1, $800b
80070E04	addiu  a1, a1, $f104 (=-$efc)
80070E08	ori    v0, zero, $0001
80070E0C	lui    at, $800b
80070E10	sw     v0, $cff4(at)
80070E14	jal    func3f5e0 [$8003f5e0]
80070E18	addiu  a0, s0, $ff48 (=-$b8)
80070E1C	lui    v0, $800b
80070E20	lh     v0, $f586(v0)
80070E24	lui    at, $800b
80070E28	sw     zero, $f120(at)
80070E2C	lui    at, $800b
80070E30	sw     zero, $f11c(at)
80070E34	lui    at, $800b
80070E38	sw     zero, $f118(at)
80070E3C	beq    v0, zero, L70ec8 [$80070ec8]
80070E40	addiu  s0, s2, $001c
80070E44	lui    a0, $800b
80070E48	lh     a0, $f554(a0)
80070E4C	lui    a1, $800b
80070E50	lh     a1, $f556(a1)
80070E54	lui    v0, $800b
80070E58	lh     v0, $f55c(v0)
80070E5C	sw     s1, $0020(sp)
80070E60	sw     s0, $0024(sp)
80070E64	lh     a2, $0000(s2)
80070E68	lui    a3, $800b
80070E6C	lh     a3, $f55a(a3)
80070E70	lui    v1, $800b
80070E74	lh     v1, $f55e(v1)
80070E78	lui    t0, $800b
80070E7C	lh     t0, $f560(t0)
80070E80	lui    t1, $800b
80070E84	lh     t1, $f562(t1)
80070E88	lui    t2, $800b
80070E8C	lh     t2, $f580(t2)
80070E90	lui    t3, $800b
80070E94	lh     t3, $f582(t3)
80070E98	lui    t4, $800b
80070E9C	lh     t4, $f584(t4)
80070EA0	sw     v0, $0010(sp)
80070EA4	sw     v1, $0014(sp)
80070EA8	sw     t0, $0018(sp)
80070EAC	sw     t1, $001c(sp)
80070EB0	sw     t2, $0028(sp)
80070EB4	sw     t3, $002c(sp)
80070EB8	jal    func26eac [$80026eac]
80070EBC	sw     t4, $0030(sp)
80070EC0	lui    at, $800b
80070EC4	sw     v0, $f550(at)

L70ec8:	; 80070EC8
80070EC8	ori    a0, zero, $0008
80070ECC	jal    func322bc [$800322bc]
80070ED0	addu   a1, zero, zero
80070ED4	lui    v1, $800b
80070ED8	lhu    v1, $1812(v1)
80070EDC	nop
80070EE0	sll    v0, v1, $01
80070EE4	addu   v0, v0, v1
80070EE8	sll    v0, v0, $03
80070EEC	subu   v0, v0, v1
80070EF0	lui    v1, $800b
80070EF4	lw     v1, $efe4(v1)
80070EF8	sll    v0, v0, $02
80070EFC	addu   v0, v0, v1
80070F00	lw     v1, $0020(v0)
80070F04	lui    a1, $800b
80070F08	addiu  a1, a1, $ed94 (=-$126c)
80070F0C	sll    v1, v1, $10
80070F10	sw     v1, $0000(a1)
80070F14	lw     v1, $0024(v0)
80070F18	nop
80070F1C	sll    v1, v1, $10
80070F20	lui    at, $800b
80070F24	sw     v1, $ed98(at)
80070F28	lw     v0, $0028(v0)
80070F2C	lui    v1, $800b
80070F30	lw     v1, $efe0(v1)
80070F34	sll    v0, v0, $10
80070F38	lui    at, $800b
80070F3C	sw     v0, $ed9c(at)
80070F40	blez   v1, L70fcc [$80070fcc]
80070F44	addu   s4, zero, zero
80070F48	addiu  s1, a1, $0250
80070F4C	addu   s0, zero, zero

loop70f50:	; 80070F50
80070F50	lw     a1, $0000(s1)
80070F54	nop
80070F58	addu   a1, a1, s0
80070F5C	addiu  a0, a1, $0050
80070F60	jal    func3f5e0 [$8003f5e0]
80070F64	addiu  a1, a1, $000c
80070F68	lui    v0, $800b
80070F6C	lw     v0, $efe4(v0)
80070F70	addiu  s4, s4, $0001
80070F74	addu   v0, s0, v0
80070F78	lw     v1, $000c(v0)
80070F7C	lw     a0, $0010(v0)
80070F80	lw     a1, $0014(v0)
80070F84	lw     a2, $0018(v0)
80070F88	sw     v1, $002c(v0)
80070F8C	sw     a0, $0030(v0)
80070F90	sw     a1, $0034(v0)
80070F94	sw     a2, $0038(v0)
80070F98	lw     v1, $001c(v0)
80070F9C	lw     a0, $0020(v0)
80070FA0	lw     a1, $0024(v0)
80070FA4	lw     a2, $0028(v0)
80070FA8	sw     v1, $003c(v0)

L70fac:	; 80070FAC
80070FAC	sw     a0, $0040(v0)
80070FB0	sw     a1, $0044(v0)
80070FB4	sw     a2, $0048(v0)
80070FB8	lw     v0, $fffc(s1)
80070FBC	nop
80070FC0	slt    v0, s4, v0
80070FC4	bne    v0, zero, loop70f50 [$80070f50]
80070FC8	addiu  s0, s0, $005c

L70fcc:	; 80070FCC
80070FCC	jal    func772f0 [$800772f0]
80070FD0	nop
80070FD4	jal    funca1ca4 [$800a1ca4]
80070FD8	nop
80070FDC	addiu  v0, zero, $ffff (=-$1)
80070FE0	lui    at, $8005
80070FE4	sw     v0, $e9d8(at)
80070FE8	lui    at, $8005
80070FEC	sw     v0, $e9d4(at)
80070FF0	jal    func734c8 [$800734c8]
80070FF4	nop
80070FF8	jal    func768f8 [$800768f8]
80070FFC	nop

L71000:	; 80071000
80071000	lui    v0, $800b
80071004	lh     v0, $f586(v0)
80071008	nop
8007100C	bne    v0, zero, L7101c [$8007101c]
80071010	ori    v0, zero, $0001
80071014	jal    func73d2c [$80073d2c]
80071018	nop

L7101c:	; 8007101C
8007101C	lui    at, $800b
80071020	sw     v0, $d024(at)
80071024	lui    v0, $800b
80071028	lw     v0, $d0d4(v0)
8007102C	nop
80071030	blez   v0, L710cc [$800710cc]
80071034	addu   s4, zero, zero
80071038	addu   s0, zero, zero

loop7103c:	; 8007103C
8007103C	lui    v0, $800b
80071040	lw     v0, $efe4(v0)
80071044	nop
80071048	addu   a0, s0, v0
8007104C	lhu    v0, $0058(a0)
80071050	nop
80071054	andi   v0, v0, $0040
80071058	beq    v0, zero, L710b4 [$800710b4]
8007105C	lui    v1, $0100
80071060	lw     a2, $004c(a0)
80071064	nop
80071068	lw     v0, $0004(a2)
8007106C	nop
80071070	and    v0, v0, v1
80071074	bne    v0, zero, L710a4 [$800710a4]
80071078	nop
8007107C	lui    a1, $800b
80071080	lhu    a1, $ee62(a1)
80071084	lhu    v0, $0108(a2)
80071088	lw     a0, $0004(a0)
8007108C	addu   a1, a1, v0
80071090	sll    a1, a1, $10
80071094	jal    func22218 [$80022218]
80071098	sra    a1, a1, $10
8007109C	j      L710b4 [$800710b4]
800710A0	nop

L710a4:	; 800710A4
800710A4	lw     a0, $0004(a0)
800710A8	lh     a1, $0108(a2)
800710AC	jal    func21e40 [$80021e40]
800710B0	nop

L710b4:	; 800710B4
800710B4	lui    v0, $800b
800710B8	lw     v0, $d0d4(v0)
800710BC	addiu  s4, s4, $0001
800710C0	slt    v0, s4, v0
800710C4	bne    v0, zero, loop7103c [$8007103c]
800710C8	addiu  s0, s0, $005c

L710cc:	; 800710CC
////////////////////////////////



////////////////////////////////
// func6fc6c
8006FC6C	lui    v0, $800c
8006FC70	lw     v0, $1b60(v0)
8006FC74	addiu  sp, sp, $ffc8 (=-$38)
8006FC78	sw     ra, $0030(sp)
8006FC7C	sw     s1, $002c(sp)
8006FC80	bne    v0, zero, L6fc90 [$8006fc90]
8006FC84	sw     s0, $0028(sp)
8006FC88	0C0A049D	ќ...
8006FC8C	nop

L6fc90:	; 8006FC90
8006FC90	addu   a0, zero, zero
8006FC94	addu   a1, zero, zero
8006FC98	ori    a2, zero, $0140
8006FC9C	jal    func715f4 [$800715f4]
8006FCA0	ori    a3, zero, $00e0
8006FCA4	jal    func35c84 [$80035c84]
8006FCA8	nop
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
8006FCE8	lui    at, $800c
8006FCEC	sh     zero, $2dcc(at)
8006FCF0	lui    at, $800c
8006FCF4	sh     zero, $2dd4(at)
8006FCF8	lui    at, $800c
8006FCFC	sh     zero, $2ddc(at)
8006FD00	sb     v0, $0000(s0)
8006FD04	ori    v0, zero, $0003
8006FD08	lui    at, $800b
8006FD0C	sh     v0, $181a(at)
8006FD10	ori    v0, zero, $0040
8006FD14	lui    at, $800b
8006FD18	sh     v0, $181e(at)
8006FD1C	ori    v0, zero, $00ff
8006FD20	lui    at, $800b
8006FD24	sh     v0, $1820(at)
8006FD28	lui    at, $800c
8006FD2C	sh     v0, $2f0c(at)
8006FD30	ori    v0, zero, $0020
8006FD34	lui    at, $800c
8006FD38	sw     zero, $2f34(at)
8006FD3C	lui    at, $800c
8006FD40	sw     zero, $2f30(at)
8006FD44	lui    at, $800b
8006FD48	sw     zero, $1690(at)
8006FD4C	lui    at, $800b
8006FD50	sw     zero, $1694(at)
8006FD54	lui    at, $800b
8006FD58	sw     zero, $1698(at)
8006FD5C	lui    at, $800b
8006FD60	sw     zero, $1738(at)
8006FD64	lui    at, $800b
8006FD68	sw     zero, $168c(at)
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
800702FC	lw     ra, $0030(sp)
80070300	lw     s1, $002c(sp)
80070304	lw     s0, $0028(sp)
80070308	addiu  sp, sp, $0038
8007030C	jr     ra 
80070310	nop
////////////////////////////////



////////////////////////////////
// func6f71c
A0 = A1;
A1 = A2;
system_extract_archive;
////////////////////////////////
