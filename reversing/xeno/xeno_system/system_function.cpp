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
// func365c0()
S4 = A1;

A0 = bu[S4];
S3 = A2;
S5 = 0;
if( A0 == 0 )
{
    return 0;
}

S7 = 2d;
S6 = 2b;

L36608:	; 80036608
    V0 = 25;
    80036608	bne    a0, v0, L36a88 [$80036a88]
    8003660C	nop
    80036610	lui    a1, $8006
    80036614	addiu  a1, a1, $9868 (=-$6798)
    80036618	lw     v0, $0000(a1)
    8003661C	lw     v1, $0004(a1)
    80036620	lw     a0, $0008(a1)
    80036624	sw     v0, $0110(sp)
    80036628	sw     v1, $0114(sp)
    8003662C	sw     a0, $0118(sp)
    80036630	lw     v0, $000c(a1)
    80036634	nop
    80036638	sw     v0, $011c(sp)
    8003663C	ori    a1, zero, $0020
    80036640	ori    v1, zero, $0030

    L36644:	; 80036644
    S4 = S4 + 1;
    A0 = bu[S4];
    80036650	bne    a0, s7, L3666c [$8003666c]
    80036654	nop
    80036658	lw     v0, $0110(sp)
    8003665C	nop
    80036660	ori    v0, v0, $0001
    80036664	j      L36644 [$80036644]
    80036668	sw     v0, $0110(sp)

    L3666c:	; 8003666C
    8003666C	bne    a0, s6, L36688 [$80036688]
    80036670	nop
    80036674	lw     v0, $0110(sp)
    80036678	nop
    8003667C	ori    v0, v0, $0002
    80036680	j      L36644 [$80036644]
    80036684	sw     v0, $0110(sp)

    L36688:	; 80036688
    80036688	bne    a0, a1, L36698 [$80036698]
    8003668C	nop
    80036690	j      L36644 [$80036644]
    80036694	sb     a0, $0111(sp)

    L36698:	; 80036698
    80036698	bne    a0, v1, L366b4 [$800366b4]
    8003669C	ori    v0, zero, $002a
    800366A0	lw     v0, $0110(sp)
    800366A4	nop
    800366A8	ori    v0, v0, $0004
    800366AC	j      L36644 [$80036644]
    800366B0	sw     v0, $0110(sp)

    L366b4:	; 800366B4
    800366B4	bne    a0, v0, L3671c [$8003671c]
    800366B8	addiu  v0, a0, $ffd0 (=-$30)
    800366BC	addiu  s3, s3, $0004
    800366C0	lw     v0, $fffc(s3)
    800366C4	nop
    800366C8	bgez   v0, L366e4 [$800366e4]
    800366CC	sw     v0, $0114(sp)
    800366D0	lw     v1, $0110(sp)
    800366D4	subu   v0, zero, v0
    800366D8	sw     v0, $0114(sp)
    800366DC	ori    v1, v1, $0001
    800366E0	sw     v1, $0110(sp)

    L366e4:	; 800366E4
    800366E4	addiu  s4, s4, $0001
    800366E8	lbu    a0, $0000(s4)
    800366EC	j      L36728 [$80036728]
    800366F0	ori    v0, zero, $002e

    loop366f4:	; 800366F4
    800366F4	lw     v0, $0114(sp)
    800366F8	addiu  s4, s4, $0001
    800366FC	sll    v1, v0, $02
    80036700	addu   v1, v1, v0
    80036704	sll    v1, v1, $01
    80036708	addiu  v1, v1, $ffd0 (=-$30)
    8003670C	addu   v1, v1, a0
    80036710	lbu    a0, $0000(s4)
    80036714	sw     v1, $0114(sp)
    80036718	addiu  v0, a0, $ffd0 (=-$30)

    L3671c:	; 8003671C
    8003671C	sltiu  v0, v0, $000a
    80036720	bne    v0, zero, loop366f4 [$800366f4]
    80036724	ori    v0, zero, $002e

    L36728:	; 80036728
    80036728	bne    a0, v0, L367b0 [$800367b0]
    8003672C	ori    v0, zero, $002a
    80036730	addiu  s4, s4, $0001
    80036734	lbu    a0, $0000(s4)
    80036738	nop
    8003673C	bne    a0, v0, L36784 [$80036784]
    80036740	addiu  v0, a0, $ffd0 (=-$30)
    80036744	addiu  s3, s3, $0004
    80036748	addiu  s4, s4, $0001
    8003674C	lw     v0, $fffc(s3)
    80036750	lbu    a0, $0000(s4)
    80036754	j      L36790 [$80036790]
    80036758	sw     v0, $0118(sp)

    loop3675c:	; 8003675C
    8003675C	lw     v0, $0118(sp)
    80036760	addiu  s4, s4, $0001
    80036764	sll    v1, v0, $02
    80036768	addu   v1, v1, v0
    8003676C	sll    v1, v1, $01
    80036770	addiu  v1, v1, $ffd0 (=-$30)
    80036774	addu   v1, v1, a0
    80036778	lbu    a0, $0000(s4)
    8003677C	sw     v1, $0118(sp)
    80036780	addiu  v0, a0, $ffd0 (=-$30)

    L36784:	; 80036784
    80036784	sltiu  v0, v0, $000a
    80036788	bne    v0, zero, loop3675c [$8003675c]
    8003678C	nop

    L36790:	; 80036790
    80036790	lw     v0, $0118(sp)
    80036794	nop
    80036798	bltz   v0, L367b0 [$800367b0]
    8003679C	nop
    800367A0	lw     v0, $0110(sp)
    800367A4	nop
    800367A8	ori    v0, v0, $0008
    800367AC	sw     v0, $0110(sp)

    L367b0:	; 800367B0
    800367B0	lw     v1, $0110(sp)
    800367B4	nop
    800367B8	andi   v0, v1, $0001
    800367BC	beq    v0, zero, L367d0 [$800367d0]
    800367C0	addiu  s0, sp, $0110
    800367C4	addiu  v0, zero, $fffb (=-$5)
    800367C8	and    v0, v1, v0
    800367CC	sw     v0, $0110(sp)

    L367d0:	; 800367D0
    800367D0	addiu  v1, a0, $ffa8 (=-$58)
    800367D4	sltiu  v0, v1, $0021
    800367D8	beq    v0, zero, L36a7c [$80036a7c]
    800367DC	sll    v0, v1, $02
    800367E0	lui    at, $8002
    800367E4	addu   at, at, v0
    800367E8	lw     v0, $8bec(at)
    800367EC	nop
    800367F0	jr     v0 
    800367F4	nop

    800367F8	addiu  s3, s3, $0004
    800367FC	lw     a0, $fffc(s3)
    80036800	j      L36854 [$80036854]
    80036804	ori    v0, zero, $0002
    80036808	addiu  s3, s3, $0004
    8003680C	lw     a0, $fffc(s3)
    80036810	nop
    80036814	bgez   a0, L36828 [$80036828]
    80036818	nop
    8003681C	subu   a0, zero, a0
    80036820	j      L36840 [$80036840]
    80036824	sb     s7, $0111(sp)

    L36828:	; 80036828
    80036828	lw     v0, $0110(sp)
    8003682C	nop
    80036830	andi   v0, v0, $0002
    80036834	beq    v0, zero, L36858 [$80036858]
    80036838	ori    v0, zero, $000a
    8003683C	sb     s6, $0111(sp)

    L36840:	; 80036840
    80036840	j      L36858 [$80036858]
    80036844	ori    v0, zero, $000a
    80036848	addiu  s3, s3, $0004
    8003684C	lw     a0, $fffc(s3)
    80036850	ori    v0, zero, $000a

    L36854:	; 80036854
    80036854	sb     zero, $0111(sp)

    L36858:	; 80036858
    80036858	sw     v0, $011c(sp)
    8003685C	lw     v1, $0110(sp)
    80036860	nop
    80036864	andi   v0, v1, $0008
    80036868	bne    v0, zero, L368a8 [$800368a8]
    8003686C	andi   v0, v1, $0004
    80036870	beq    v0, zero, L36894 [$80036894]
    80036874	nop
    80036878	lw     v1, $0114(sp)
    8003687C	lbu    v0, $0111(sp)
    80036880	nop
    80036884	beq    v0, zero, L36894 [$80036894]
    80036888	sw     v1, $0118(sp)
    8003688C	addiu  v0, v1, $ffff (=-$1)
    80036890	sw     v0, $0118(sp)

    L36894:	; 80036894
    80036894	lw     v0, $0118(sp)
    80036898	nop
    8003689C	bgtz   v0, L368a8 [$800368a8]
    800368A0	ori    v0, zero, $0001
    800368A4	sw     v0, $0118(sp)

    L368a8:	; 800368A8
    800368A8	beq    a0, zero, L368e8 [$800368e8]
    800368AC	addu   s1, zero, zero

    loop368b0:	; 800368B0
    800368B0	lw     v0, $011c(sp)
    800368B4	nop
    800368B8	divu   a0, v0
    800368BC	mfhi   v1
    800368C0	addiu  s0, s0, $ffff (=-$1)
    800368C4	addiu  v1, v1, $0030
    800368C8	sb     v1, $0000(s0)
    800368CC	lw     v0, $011c(sp)
    800368D0	nop
    800368D4	divu   a0, v0
    800368D8	mflo   a0
    800368DC	nop
    800368E0	bne    a0, zero, loop368b0 [$800368b0]
    800368E4	addiu  s1, s1, $0001

    L368e8:	; 800368E8
    800368E8	lw     v0, $0118(sp)
    800368EC	nop
    800368F0	slt    v0, s1, v0
    800368F4	beq    v0, zero, L36920 [$80036920]
    800368F8	nop
    800368FC	ori    v1, zero, $0030
    80036900	addiu  s0, s0, $ffff (=-$1)

    loop36904:	; 80036904
    80036904	sb     v1, $0000(s0)
    80036908	lw     v0, $0118(sp)
    8003690C	addiu  s1, s1, $0001
    80036910	slt    v0, s1, v0
    80036914	bne    v0, zero, loop36904 [$80036904]
    80036918	addiu  s0, s0, $ffff (=-$1)
    8003691C	addiu  s0, s0, $0001

    L36920:	; 80036920
    80036920	lbu    v0, $0111(sp)
    80036924	nop
    80036928	beq    v0, zero, L36a98 [$80036a98]
    8003692C	nop
    80036930	addiu  s0, s0, $ffff (=-$1)
    80036934	sb     v0, $0000(s0)
    80036938	j      L36a98 [$80036a98]
    8003693C	addiu  s1, s1, $0001
    80036940	lw     v1, $0110(sp)
    80036944	ori    v0, zero, $0008
    80036948	sw     v0, $0118(sp)
    8003694C	ori    v1, v1, $0008
    80036950	sw     v1, $0110(sp)
    80036954	lui    a1, $8002
    80036958	addiu  a1, a1, $8bc4 (=-$743c)
    8003695C	j      L36970 [$80036970]
    80036960	addiu  s3, s3, $0004
    80036964	lui    a1, $8002
    80036968	addiu  a1, a1, $8bd8 (=-$7428)
    8003696C	addiu  s3, s3, $0004

    L36970:	; 80036970
    80036970	lw     v1, $0110(sp)
    80036974	lw     a0, $fffc(s3)
    80036978	andi   v0, v1, $0008
    8003697C	bne    v0, zero, L369ac [$800369ac]
    80036980	andi   v0, v1, $0004
    80036984	beq    v0, zero, L36998 [$80036998]
    80036988	nop
    8003698C	lw     v0, $0114(sp)
    80036990	nop
    80036994	sw     v0, $0118(sp)

    L36998:	; 80036998
    80036998	lw     v0, $0118(sp)
    8003699C	nop
    800369A0	bgtz   v0, L369ac [$800369ac]
    800369A4	ori    v0, zero, $0001
    800369A8	sw     v0, $0118(sp)

    L369ac:	; 800369AC
    800369AC	beq    a0, zero, L369d4 [$800369d4]
    800369B0	addu   s1, zero, zero

    loop369b4:	; 800369B4
    800369B4	addiu  s0, s0, $ffff (=-$1)
    800369B8	andi   v0, a0, $000f
    800369BC	srl    a0, a0, $04
    800369C0	addu   v0, a1, v0
    800369C4	lbu    v0, $0000(v0)
    800369C8	addiu  s1, s1, $0001
    800369CC	bne    a0, zero, loop369b4 [$800369b4]
    800369D0	sb     v0, $0000(s0)

    L369d4:	; 800369D4
    800369D4	lw     v0, $0118(sp)
    800369D8	nop
    800369DC	slt    v0, s1, v0
    800369E0	beq    v0, zero, L36a98 [$80036a98]
    800369E4	ori    v1, zero, $0030
    800369E8	addiu  s0, s0, $ffff (=-$1)

    loop369ec:	; 800369EC
    800369EC	sb     v1, $0000(s0)
    800369F0	lw     v0, $0118(sp)
    800369F4	addiu  s1, s1, $0001
    800369F8	slt    v0, s1, v0
    800369FC	bne    v0, zero, loop369ec [$800369ec]
    80036A00	addiu  s0, s0, $ffff (=-$1)
    80036A04	j      L36a98 [$80036a98]
    80036A08	addiu  s0, s0, $0001
    80036A0C	addiu  s0, s0, $ffff (=-$1)
    80036A10	addiu  s3, s3, $0004
    80036A14	lw     v0, $fffc(s3)
    80036A18	ori    s1, zero, $0001
    80036A1C	j      L36a98 [$80036a98]
    80036A20	sb     v0, $0000(s0)
    80036A24	addiu  s3, s3, $0004
    80036A28	lw     v0, $0110(sp)
    80036A2C	lw     s0, $fffc(s3)
    80036A30	andi   v0, v0, $0008
    80036A34	bne    v0, zero, L36a4c [$80036a4c]
    80036A38	addu   a0, s0, zero
    80036A3C	jal    func3fa40 [$8003fa40]
    80036A40	addu   a0, s0, zero
    80036A44	j      L36a98 [$80036a98]
    80036A48	addu   s1, v0, zero

    L36a4c:	; 80036A4C
    80036A4C	lw     a2, $0118(sp)
    80036A50	jal    func3f7c0 [$8003f7c0]
    80036A54	addu   a1, zero, zero
    80036A58	bne    v0, zero, L36a98 [$80036a98]
    80036A5C	subu   s1, v0, s0
    80036A60	lw     s1, $0118(sp)
    80036A64	j      L36a98 [$80036a98]
    80036A68	nop
    80036A6C	addiu  s3, s3, $0004
    80036A70	lw     s0, $fffc(s3)
    80036A74	j      L36b38 [$80036b38]
    80036A78	sw     s5, $0000(s0)

    L36a7c:	; 80036A7C
    80036A7C	ori    v0, zero, $0025
    80036A80	bne    a0, v0, L36b50 [$80036b50]

    L36a88:	; 80036A88
    S5 = S5 + 1;

    func36598();

    80036A90	j      L36b3c [$80036b3c]
    80036A94	addiu  s4, s4, $0001

    L36a98:	; 80036A98
    80036A98	lw     v0, $0114(sp)
    80036A9C	nop
    80036AA0	slt    v0, s1, v0
    80036AA4	beq    v0, zero, L36ae4 [$80036ae4]
    80036AA8	nop
    80036AAC	lw     v0, $0110(sp)
    80036AB0	nop
    80036AB4	andi   v0, v0, $0001
    80036AB8	bne    v0, zero, L36ae4 [$80036ae4]
    80036ABC	nop

    loop36ac0:	; 80036AC0
    A0 = 20;
    func36598();

    80036AC8	lw     v0, $0114(sp)
    80036ACC	nop
    80036AD0	addiu  v0, v0, $ffff (=-$1)
    80036AD4	sw     v0, $0114(sp)
    80036AD8	slt    v0, s1, v0
    80036ADC	bne    v0, zero, loop36ac0 [$80036ac0]
    80036AE0	addiu  s5, s5, $0001

    L36ae4:	; 80036AE4
    80036AE4	blez   s1, L36b08 [$80036b08]
    80036AE8	nop
    80036AEC	addu   s2, s1, s0

    loop36af0:	; 80036AF0
        A0 = bu[S0];
        func36598();

        80036AF8	addiu  s0, s0, $0001
        80036AFC	slt    v0, s0, s2
    80036B00	bne    v0, zero, loop36af0 [$80036af0]

    L36b08:	; 80036B08
    80036B08	lw     v0, $0114(sp)
    80036B0C	nop
    80036B10	slt    v0, s1, v0
    80036B18	addu   s5, s5, s1
    if( V0 != 0 )
    {
        loop36b1c:	; 80036B1C
            A0 = 20;
            func36598(); // call func from 8004fc34

            80036B24	lw     v0, $0114(sp)
            80036B34	addiu  s5, s5, $0001
            80036B28	addiu  s1, s1, $0001
            80036B2C	slt    v0, s1, v0
        80036B30	bne    v0, zero, loop36b1c [$80036b1c]
    }

    L36b38:	; 80036B38
    80036B38	addiu  s4, s4, $0001

    L36b3c:	; 80036B3C
    80036B3C	lbu    a0, $0000(s4)
80036B44	bne    a0, zero, L36608 [$80036608]

L36b50:	; 80036B50
return S5;
////////////////////////////////



////////////////////////////////
// func36598()
V0 = w[8004fc34]; // 80036f84
800365A8	jalr   v0 ra
////////////////////////////////



////////////////////////////////
// func36f84()
A2 = w[80058a30];
A3 = A0;
80036F90	beq    a2, zero, L3716c [$8003716c]

80036F98	lh     v1, $0032(a2)
80036F9C	lh     a1, $0016(a2)
80036FA0	lh     v0, $000e(a2)
80036FA4	lh     a0, $0012(a2)
80036FA8	addu   v1, v1, a1
80036FAC	addu   v0, v0, a0
80036FB0	slt    v0, v0, v1
80036FB4	bne    v0, zero, L3716c [$8003716c]
80036FB8	nop
80036FBC	lh     v1, $0034(a2)
80036FC0	lh     v0, $002c(a2)
80036FC4	nop
80036FC8	slt    v0, v0, v1
80036FCC	bne    v0, zero, L3716c [$8003716c]
80036FD0	slti   v0, a3, $0020
80036FD4	beq    v0, zero, L37000 [$80037000]
80036FD8	ori    v0, zero, $000a
80036FDC	bne    a3, v0, L3716c [$8003716c]
80036FE0	nop
80036FE4	lhu    v1, $0032(a2)
80036FE8	lhu    a0, $0016(a2)
80036FEC	lhu    v0, $0036(a2)
80036FF0	addu   v1, v1, a0
80036FF4	sh     v0, $0030(a2)
80036FF8	j      L3716c [$8003716c]
80036FFC	sh     v1, $0032(a2)

L37000:	; 80037000
80037000	lhu    v0, $002e(a2)
80037004	nop
80037008	andi   v0, v0, $0004
8003700C	beq    v0, zero, L37020 [$80037020]
80037010	slti   v0, a3, $0060
80037014	bne    v0, zero, L37020 [$80037020]
80037018	nop
8003701C	addiu  a3, a3, $ffe0 (=-$20)

L37020:	; 80037020
80037020	lhu    v0, $002e(a2)
80037024	nop
80037028	andi   v0, v0, $0008
8003702C	beq    v0, zero, L37044 [$80037044]
80037030	addiu  a3, a3, $ffe0 (=-$20)
80037034	addu   v0, a2, a3
80037038	lbu    a1, $0064(v0)
8003703C	j      L37048 [$80037048]
80037040	nop

L37044:	; 80037044
80037044	lh     a1, $0014(a2)

L37048:	; 80037048
80037048	lh     v0, $0030(a2)
8003704C	lh     v1, $000c(a2)
80037050	lh     a0, $0010(a2)
80037054	addu   v0, v0, a1
80037058	addu   v1, v1, a0
8003705C	slt    v0, v0, v1
80037060	bne    v0, zero, L37094 [$80037094]
80037064	nop
80037068	lhu    v0, $0000(a2)
8003706C	nop
80037070	andi   v0, v0, $0008
80037074	bne    v0, zero, L3716c [$8003716c]
80037078	nop
8003707C	lhu    v1, $0032(a2)
80037080	lhu    a0, $0016(a2)
80037084	lhu    v0, $0036(a2)
80037088	addu   v1, v1, a0
8003708C	sh     v0, $0030(a2)
80037090	sh     v1, $0032(a2)

L37094:	; 80037094
80037094	beq    a3, zero, L3715c [$8003715c]
80037098	nop
8003709C	lw     v1, $0038(a2)
800370A0	lw     v0, $0018(a2)
800370A4	nop
800370A8	sw     v0, $0004(v1)
800370AC	lh     v1, $0032(a2)
800370B0	lh     v0, $0030(a2)
800370B4	lw     a0, $0038(a2)
800370B8	sll    v1, v1, $10
800370BC	or     v0, v0, v1
800370C0	sw     v0, $0008(a0)
800370C4	lhu    v0, $002e(a2)
800370C8	nop
800370CC	andi   v0, v0, $0002
800370D0	beq    v0, zero, L37104 [$80037104]
800370D4	andi   v0, a3, $0018
800370D8	srl    v0, v0, $02
800370DC	addu   v0, v0, a2
800370E0	andi   a0, a3, $0007
800370E4	lw     v1, $0038(a2)
800370E8	lhu    v0, $003c(v0)
800370EC	sll    a0, a0, $04
800370F0	sh     v0, $000e(v1)
800370F4	andi   v0, a3, $0060
800370F8	lbu    v1, $00d2(a2)
800370FC	j      L37130 [$80037130]
80037100	sra    v0, v0, $01

L37104:	; 80037104
80037104	andi   v0, a3, $0030
80037108	srl    v0, v0, $03
8003710C	addu   v0, v0, a2
80037110	andi   a0, a3, $000f
80037114	lw     v1, $0038(a2)
80037118	lhu    v0, $003c(v0)
8003711C	sll    a0, a0, $03
80037120	sh     v0, $000e(v1)
80037124	andi   v0, a3, $00c0
80037128	lbu    v1, $00d2(a2)
8003712C	sra    v0, v0, $03

L37130:	; 80037130
80037130	addu   v1, v1, v0
80037134	sll    v1, v1, $08
80037138	lw     v0, $0038(a2)
8003713C	or     a0, a0, v1
80037140	sh     a0, $000c(v0)
80037144	lhu    v1, $0034(a2)
80037148	lw     v0, $0038(a2)
8003714C	addiu  v1, v1, $0001
80037150	addiu  v0, v0, $0010
80037154	sw     v0, $0038(a2)
80037158	sh     v1, $0034(a2)

L3715c:	; 8003715C
8003715C	lhu    v0, $0030(a2)
80037160	nop
80037164	addu   v0, v0, a1
80037168	sh     v0, $0030(a2)

L3716c:	; 8003716C
////////////////////////////////



////////////////////////////////
// func31edc
[A0 - 4] = w(w[A0 - 4] & fdffffff);
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
// func322bc()
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
