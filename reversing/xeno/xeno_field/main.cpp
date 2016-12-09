////////////////////////////////
// func77518()
80077518	addiu  sp, sp, $ffc8 (=-$38)
8007751C	lui    v1, $8001
80077520	lw     v1, $0000(v1)
80077524	addiu  v0, zero, $ffff (=-$1)
80077528	sw     ra, $0034(sp)
8007752C	sw     s6, $0030(sp)
80077530	sw     s5, $002c(sp)
80077534	sw     s4, $0028(sp)
80077538	sw     s3, $0024(sp)
8007753C	sw     s2, $0020(sp)
80077540	sw     s1, $001c(sp)
80077544	beq    v1, v0, L7755c [$8007755c]
80077548	sw     s0, $0018(sp)
8007754C	lui    at, $800c
80077550	sw     zero, $1b60(at)
80077554	j      L77568 [$80077568]
80077558	nop

L7755c:	; 8007755C
8007755C	ori    v0, zero, $0001
80077560	lui    at, $800c
80077564	sw     v0, $1b60(at)

L77568:	; 80077568
80077568	jal    func78fb0 [$80078fb0]
8007756C	nop
80077570	lui    v0, $800c
80077574	lw     v0, $1b60(v0)
80077578	nop
8007757C	bne    v0, zero, L77598 [$80077598]
80077580	ori    a0, zero, $0008
80077584	lui    a0, $8007
80077588	addiu  a0, a0, $6eac
8007758C	jal    func44350 [$80044350]
80077590	nop
80077594	ori    a0, zero, $0008

L77598:	; 80077598
80077598	lui    v0, $8006
8007759C	lw     v0, $8bfc(v0)
800775A0	lui    v1, $8006
800775A4	lw     v1, $8c48(v1)
800775A8	lui    at, $8006
800775AC	sw     v0, $1bac(at)
800775B0	lui    at, $8006
800775B4	sw     v1, $1bb4(at)
800775B8	jal    func322bc [$800322bc]
800775BC	addu   a1, zero, zero
800775C0	lui    v0, $800c
800775C4	lw     v0, $1b60(v0)
800775C8	nop
800775CC	bne    v0, zero, L77614 [$80077614]
800775D0	nop
800775D4	lui    v0, $8005
800775D8	lw     v0, $ea14(v0)
800775DC	nop
800775E0	bne    v0, zero, L77614 [$80077614]
800775E4	ori    a0, zero, $0004
800775E8	jal    func28280 [$80028280]
800775EC	addu   a1, zero, zero
800775F0	ori    a0, zero, $00ad
800775F4	lui    a1, $8028
800775F8	addu   a2, zero, zero
800775FC	jal    func293e8 [$800293e8]
80077600	ori    a3, zero, $0080
80077604	jal    func28870 [$80028870]
80077608	addu   a0, zero, zero
8007760C	jal    func78fb0 [$80078fb0]
80077610	nop

L77614:	; 80077614
80077614	lui    v0, $8005
80077618	lw     v0, $e9b0(v0)
8007761C	nop
80077620	bne    v0, zero, L77640 [$80077640]
80077624	ori    v0, zero, $00ff
80077628	lui    at, $8007
8007762C	sw     v0, $f154(at)
80077630	lui    at, $8007
80077634	sw     v0, $f150(at)
80077638	lui    at, $8007
8007763C	sw     v0, $f14c(at)

L77640:	; 80077640
80077640	jal    func84ea4 [$80084ea4]
80077644	addu   a0, zero, zero
80077648	jal    func77318 [$80077318]
8007764C	addu   s4, zero, zero
80077650	lui    v1, $800c
80077654	lw     v1, $1b60(v1)
80077658	addiu  v0, zero, $ffff (=-$1)
8007765C	lui    at, $800b
80077660	sw     v0, $d0c0(at)
80077664	lui    at, $800b
80077668	sw     v0, $d0bc(at)
8007766C	lui    at, $800b
80077670	sw     v0, $d0b8(at)
80077674	lui    at, $800b
80077678	sw     v0, $d0b4(at)
8007767C	lui    at, $800b
80077680	sw     v0, $d0b0(at)
80077684	ori    v0, zero, $0002
80077688	lui    at, $8005
8007768C	sw     zero, $e9fc(at)
80077690	lui    at, $8005
80077694	sw     zero, $e9f8(at)
80077698	lui    at, $800b
8007769C	sw     zero, $d0e8(at)
800776A0	lui    at, $800b
800776A4	sw     zero, $d038(at)
800776A8	lui    at, $800b
800776AC	sw     zero, $d00c(at)
800776B0	lui    at, $800b
800776B4	sw     zero, $d054(at)
800776B8	lui    at, $800b
800776BC	sw     v0, $d0dc(at)
800776C0	bne    v1, zero, L776d0 [$800776d0]
800776C4	nop
800776C8	0C0A0481	Ѓ...
800776CC	nop

L776d0:	; 800776D0
800776D0	jal    func76c50 [$80076c50]
800776D4	nop
800776D8	lui    v1, $8007
800776DC	lhu    v1, $efde(v1)
800776E0	lui    a0, $8007
800776E4	lhu    a0, $efe4(a0)
800776E8	lui    v0, $8007
800776EC	addiu  v0, v0, $ccc4 (=-$333c)
800776F0	lui    at, $8006
800776F4	sw     v0, $9a38(at)
800776F8	lui    v0, $8007
800776FC	lhu    v0, $efe0(v0)
80077700	lui    at, $8005
80077704	sw     v1, $e9f0(at)

L77708:	; 80077708
80077708	lui    v1, $8005
8007770C	lw     v1, $e99c(v1)
80077710	srl    v0, v0, $09
80077714	lui    at, $8007
80077718	sh     a0, $e5f6(at)
8007771C	lui    at, $8007
80077720	sh     v0, $e5fc(at)
80077724	bne    v1, zero, L7773c [$8007773c]
80077728	ori    v0, zero, $00ff
8007772C	lui    at, $8006
80077730	sb     zero, $8b6c(at)
80077734	j      L77744 [$80077744]
80077738	nop

L7773c:	; 8007773C
8007773C	lui    v0, $8007
80077740	lhu    v0, $efe6(v0)

L77744:	; 80077744
80077744	lui    at, $8005
80077748	sw     v0, $e9c8(at)

L7774c:	; 8007774C
8007774C	lui    v1, $800c
80077750	lw     v1, $1b60(v1)
80077754	ori    v0, zero, $0001
80077758	bne    v1, v0, L77778 [$80077778]
8007775C	ori    a0, zero, $0050
80077760	ori    a1, zero, $0001
80077764	lui    v1, $8006
80077768	lw     v1, $9a38(v1)
8007776C	ori    v0, zero, $0001
80077770	jal    put_bytes_to_800C2F3C [$800a2604]
80077774	sh     v0, $1980(v1)

L77778:	; 80077778
80077778	jal    func76cb0 [$80076cb0]
8007777C	nop
80077780	lui    at, $8005
80077784	sw     zero, $e9c4(at)
80077788	jal    func1aed8 [$8001aed8]
8007778C	nop
80077790	jal    func1b23c [$8001b23c]
80077794	nop
80077798	ori    a0, zero, $0004
8007779C	jal    system_memory_allocate [$800319ec]
800777A0	ori    a1, zero, $0001
800777A4	lui    v1, $800c
800777A8	lw     v1, $1b60(v1)
800777AC	lui    at, $800b
800777B0	sw     v0, $d008(at)
800777B4	bne    v1, zero, L777e8 [$800777e8]
800777B8	nop
800777BC	break   $00400
800777C0	lui    a0, $800b
800777C4	lw     a0, $1740(a0)
800777C8	jal    funca897c [$800a897c]
800777CC	nop
800777D0	ori    v0, zero, $0001
800777D4	lui    at, $800b
800777D8	sh     v0, $f7a0(at)
800777DC	ori    v0, zero, $0010
800777E0	lui    at, $800b
800777E4	sh     v0, $f7a6(at)

L777e8:	; 800777E8
800777E8	jal    func78358 [$80078358]
800777EC	addu   s5, zero, zero
800777F0	ori    v0, zero, $0001
800777F4	lui    at, $800b
800777F8	sb     v0, $cfdc(at)
800777FC	ori    s1, zero, $0001
80077800	addiu  s2, zero, $ffff (=-$1)
80077804	lui    s6, $800b
80077808	addiu  s6, s6, $1829
8007780C	ori    s3, zero, $00ff

L77810:	; 80077810
if( hu[800c2dd4] & 0800 ) // start repeated
{
    if( ( hu[800af370] & 0040 ) == 0 ) // cross currently not pressed
    {
        if( bu[800b182c] == 0 )
        {
            80077854	lui    s0, $8006
            80077858	lw     s0, $8b24(s0)
            8007785C	jal    func37d8c [$80037d8c]
            80077860	nop
            80077864	lui    a1, $800b
            80077868	lw     a1, $cfe0(a1)
            8007786C	ori    a0, zero, $0088
            80077870	addiu  a1, a1, $0001
            80077874	andi   a1, a1, $0001
            80077878	sll    a1, a1, $08
            8007787C	jal    func1f92c [$8001f92c]
            80077880	ori    a1, a1, $0064

            loop77884:	; 80077884
                80077884	jal    func44448 [$80044448]
                80077888	addu   a0, zero, zero
                8007788C	jal    func4b3f4 [$8004b3f4]
                80077890	ori    a0, zero, $0002
                80077894	jal    func73d90 [$80073d90]
                80077898	nop
                8007789C	jal    func19d24 [$80019d24]

                V0 = hu[800c2dd4] & 0800; // start repeated
            800778B4	beq    v0, zero, loop77884 [$80077884]
            800778B8	nop
            800778BC	jal    func37d34 [$80037d34]
            800778C0	nop
            800778C4	lui    at, $8006
            800778C8	sw     s0, $8b24(at)
        }
    }
}

800778CC	lui    v0, $800c
800778D0	lw     v0, $1b60(v0)
800778D4	nop
800778D8	bne    v0, s1, L778e8 [$800778e8]
800778DC	ori    a0, zero, $0050
800778E0	jal    put_bytes_to_800C2F3C [$800a2604]
800778E4	ori    a1, zero, $0001

L778e8:	; 800778E8
800778E8	jal    func19d24 [$80019d24]
800778EC	nop
800778F0	jal    func7743c [$8007743c]
800778F4	nop
800778F8	jal    func74bdc [$80074bdc]
800778FC	nop
80077900	jal    funca4dfc [$800a4dfc]
80077904	nop
80077908	lui    v0, $800b
8007790C	lw     v0, $cfe0(v0)
80077910	nop
80077914	bne    v0, s1, L77aa4 [$80077aa4]
80077918	nop
8007791C	lui    v0, $800b
80077920	lw     v0, $d0b4(v0)
80077924	nop
80077928	bne    v0, zero, L77aa4 [$80077aa4]
8007792C	nop
80077930	jal    func781dc [$800781dc]
80077934	nop
80077938	bne    v0, zero, L77aa4 [$80077aa4]
8007793C	nop
80077940	jal    func774a0 [$800774a0]
80077944	nop
80077948	bne    v0, zero, L77aa4 [$80077aa4]
8007794C	nop
80077950	lui    v0, $8005
80077954	lw     v0, $e9d8(v0)
80077958	nop
8007795C	beq    v0, s2, L77984 [$80077984]
80077960	nop
80077964	lui    a0, $8006
80077968	lw     a0, $9b70(a0)
8007796C	jal    func31edc [$80031edc]
80077970	nop
80077974	lui    a0, $8006
80077978	lw     a0, $9b70(a0)
8007797C	jal    func31f0c [$80031f0c]
80077980	nop

L77984:	; 80077984
80077984	bne    s5, zero, L779a0 [$800779a0]
80077988	nop
8007798C	lui    v0, $8005
80077990	lw     v0, $e9c8(v0)
80077994	ori    s5, zero, $0001
80077998	lui    at, $800b
8007799C	sw     v0, $f14c(at)

L779a0:	; 800779A0
800779A0	jal    func7f5fc [$8007f5fc]
800779A4	nop
800779A8	lui    v0, $800b
800779AC	lw     v0, $d0a8(v0)
800779B0	nop
800779B4	bne    v0, s1, L77a38 [$80077a38]
800779B8	nop
800779BC	lbu    v0, $0000(s6)
800779C0	lui    v1, $8005
800779C4	lw     v1, $e9c8(v1)
800779C8	lh     a0, $ff3b(s6)
800779CC	lui    a1, $8005
800779D0	lw     a1, $e9dc(a1)
800779D4	lui    at, $8006
800779D8	sb     v0, $8be8(at)
800779DC	lui    at, $800b
800779E0	sw     v1, $f14c(at)
800779E4	beq    a1, a0, L77a20 [$80077a20]
800779E8	nop
800779EC	beq    a1, s2, L779fc [$800779fc]
800779F0	nop
800779F4	lui    at, $8005
800779F8	sw     s1, $e9ec(at)

L779fc:	; 800779FC
800779FC	jal    func1b500 [$8001b500]
80077A00	nop
80077A04	lh     a0, $ff3b(s6)
80077A08	lui    at, $8005
80077A0C	sw     s2, $e9ac(at)
80077A10	lui    at, $8005
80077A14	sw     a0, $e9c8(at)
80077A18	jal    func85134 [$80085134]
80077A1C	ori    a1, zero, $0001

L77a20:	; 80077A20
80077A20	lui    at, $800b
80077A24	sw     zero, $d0a8(at)
80077A28	lui    at, $800b
80077A2C	sw     s1, $d0ac(at)
80077A30	j      L77aa4 [$80077aa4]
80077A34	nop

L77a38:	; 80077A38
80077A38	lui    v0, $800b
80077A3C	lw     v0, $cff0(v0)
80077A40	nop
80077A44	bne    v0, zero, L77a6c [$80077a6c]
80077A48	nop
80077A4C	lui    v0, $8005
80077A50	lw     v0, $e9b0(v0)
80077A54	nop
80077A58	addiu  v0, v0, $0001
80077A5C	lui    at, $8005
80077A60	sw     v0, $e9b0(at)
80077A64	jal    funca345c [$800a345c]
80077A68	nop

L77a6c:	; 80077A6C
80077A6C	lui    v0, $800b
80077A70	lw     v0, $d0ac(v0)
80077A74	nop
80077A78	bne    v0, s1, L77a94 [$80077a94]
80077A7C	addu   s0, zero, zero
80077A80	lui    a0, $8006
80077A84	lw     a0, $1bb8(a0)
80077A88	ori    a1, zero, $007f
80077A8C	jal    func3a744 [$8003a744]
80077A90	addu   a2, zero, zero

L77a94:	; 80077A94
80077A94	lui    at, $800b
80077A98	sw     zero, $d0ac(at)
80077A9C	j      L780cc [$800780cc]
80077AA0	nop

L77aa4:	; 80077AA4
80077AA4	lui    v0, $800b
80077AA8	lw     v0, $d0c4(v0)
80077AAC	nop
80077AB0	bne    v0, zero, L77b68 [$80077b68]
80077AB4	nop
80077AB8	lui    v0, $8005
80077ABC	lw     v0, $e9ac(v0)
80077AC0	nop
80077AC4	bne    v0, zero, L77b68 [$80077b68]
80077AC8	nop
80077ACC	lui    v0, $800b
80077AD0	lw     v0, $d09c(v0)
80077AD4	nop
80077AD8	bne    v0, s3, L77b68 [$80077b68]
80077ADC	nop
80077AE0	lui    v0, $800b
80077AE4	lw     v0, $d068(v0)
80077AE8	nop
80077AEC	bne    v0, zero, L77b68 [$80077b68]
80077AF0	addu   a1, zero, zero
80077AF4	lui    a0, $8005
80077AF8	lw     a0, $e9f0(a0)
80077AFC	nop
80077B00	andi   a0, a0, $0fff
80077B04	jal    func1b318 [$8001b318]
80077B08	sll    a0, a0, $01
80077B0C	bne    v0, zero, L77b68 [$80077b68]
80077B10	nop
80077B14	jal    func284dc [$800284dc]
80077B18	nop
80077B1C	bne    v0, zero, L77b68 [$80077b68]
80077B20	nop
80077B24	lui    v0, $800b
80077B28	lh     v0, $15ec(v0)
80077B2C	nop
80077B30	bne    v0, zero, L77b68 [$80077b68]
80077B34	nop
80077B38	lui    at, $800b
80077B3C	sb     zero, $cfdc(at)
80077B40	jal    funca268c [$800a268c]
80077B44	nop
80077B48	jal    func28870 [$80028870]
80077B4C	addu   a0, zero, zero
80077B50	jal    funca5118 [$800a5118]
80077B54	nop
80077B58	jal    func35c84 [$80035c84]
80077B5C	nop
80077B60	lui    at, $800b
80077B64	sb     s1, $cfdc(at)

L77b68:	; 80077B68
80077B68	lui    v0, $800b
80077B6C	lw     v0, $cfe0(v0)
80077B70	nop
80077B74	bne    v0, s1, L77d04 [$80077d04]
80077B78	nop
80077B7C	lui    v0, $800b
80077B80	lw     v0, $d0bc(v0)
80077B84	nop
80077B88	bne    v0, zero, L77be4 [$80077be4]
80077B8C	nop
80077B90	jal    func781dc [$800781dc]
80077B94	nop
80077B98	bne    v0, zero, L77be4 [$80077be4]
80077B9C	nop
80077BA0	jal    func28870 [$80028870]
80077BA4	addu   a0, zero, zero
80077BA8	lui    v0, $8005
80077BAC	lw     v0, $e9d8(v0)
80077BB0	nop
80077BB4	beq    v0, s2, L780cc [$800780cc]
80077BB8	ori    s0, zero, $0001
80077BBC	lui    a0, $8006
80077BC0	lw     a0, $9b70(a0)
80077BC4	jal    func31edc [$80031edc]
80077BC8	nop
80077BCC	lui    a0, $8006
80077BD0	lw     a0, $9b70(a0)
80077BD4	jal    func31f0c [$80031f0c]
80077BD8	nop
80077BDC	j      L780cc [$800780cc]
80077BE0	nop

L77be4:	; 80077BE4
80077BE4	lui    v0, $800b
80077BE8	lw     v0, $cfe0(v0)
80077BEC	nop
80077BF0	bne    v0, s1, L77d04 [$80077d04]
80077BF4	nop
80077BF8	lui    v0, $800b
80077BFC	lw     v0, $d0c0(v0)
80077C00	nop
80077C04	bne    v0, zero, L77c80 [$80077c80]
80077C08	nop
80077C0C	jal    func781dc [$800781dc]
80077C10	nop
80077C14	bne    v0, zero, L77c80 [$80077c80]
80077C18	nop
80077C1C	jal    func28870 [$80028870]
80077C20	addu   a0, zero, zero
80077C24	lui    v0, $8005
80077C28	lw     v0, $e9d8(v0)
80077C2C	nop
80077C30	beq    v0, s2, L77c58 [$80077c58]
80077C34	nop
80077C38	lui    a0, $8006
80077C3C	lw     a0, $9b70(a0)
80077C40	jal    func31edc [$80031edc]
80077C44	nop
80077C48	lui    a0, $8006
80077C4C	lw     a0, $9b70(a0)
80077C50	jal    func31f0c [$80031f0c]
80077C54	nop

L77c58:	; 80077C58
80077C58	lui    v0, $8005
80077C5C	lw     v0, $e9b4(v0)
80077C60	nop
80077C64	addiu  v0, v0, $0001
80077C68	lui    at, $8005
80077C6C	sw     v0, $e9b4(at)
80077C70	jal    funca345c [$800a345c]
80077C74	ori    s0, zero, $0002
80077C78	j      L780cc [$800780cc]
80077C7C	nop

L77c80:	; 80077C80
80077C80	lui    v0, $800b
80077C84	lw     v0, $cfe0(v0)
80077C88	nop
80077C8C	bne    v0, s1, L77d04 [$80077d04]
80077C90	nop
80077C94	lui    v0, $800b
80077C98	lw     v0, $d0b0(v0)
80077C9C	nop
80077CA0	bne    v0, zero, L77d04 [$80077d04]
80077CA4	nop
80077CA8	jal    func781dc [$800781dc]
80077CAC	nop
80077CB0	bne    v0, zero, L77d04 [$80077d04]
80077CB4	nop
80077CB8	jal    func28870 [$80028870]
80077CBC	addu   a0, zero, zero
80077CC0	lui    v0, $8005
80077CC4	lw     v0, $e9d8(v0)
80077CC8	nop
80077CCC	beq    v0, s2, L77cf4 [$80077cf4]
80077CD0	nop
80077CD4	lui    a0, $8006
80077CD8	lw     a0, $9b70(a0)
80077CDC	jal    func31edc [$80031edc]
80077CE0	nop
80077CE4	lui    a0, $8006
80077CE8	lw     a0, $9b70(a0)
80077CEC	jal    func31f0c [$80031f0c]
80077CF0	nop

L77cf4:	; 80077CF4
80077CF4	jal    func1b500 [$8001b500]
80077CF8	ori    s0, zero, $0003
80077CFC	j      L780cc [$800780cc]
80077D00	nop

L77d04:	; 80077D04
80077D04	lui    v0, $800c
80077D08	lw     v0, $1b60(v0)
80077D0C	nop
80077D10	bne    v0, zero, L77e20 [$80077e20]
80077D14	nop
V1 = hu[800c2ddc];
V0 = V1 & 0040; // cross on second controller repeated

80077D28	beq    v0, zero, L77d50 [$80077d50]
80077D2C	andi   v0, v1, $0010
80077D30	lui    v0, $8005
80077D34	lw     v0, $ea1c(v0)
80077D38	nop
80077D3C	addiu  v0, v0, $0001
80077D40	andi   v0, v0, $0001
80077D44	lui    at, $8005
80077D48	sw     v0, $ea1c(at)
80077D4C	andi   v0, v1, $0010

L77d50:	; 80077D50
80077D50	beq    v0, zero, L77d78 [$80077d78]
80077D54	andi   v0, v1, $0080
80077D58	lui    v0, $8005
80077D5C	lw     v0, $ea20(v0)
80077D60	nop
80077D64	addiu  v0, v0, $0001
80077D68	andi   v0, v0, $0001
80077D6C	lui    at, $8005
80077D70	sw     v0, $ea20(at)
80077D74	andi   v0, v1, $0080

L77d78:	; 80077D78
80077D78	beq    v0, zero, L77d9c [$80077d9c]
80077D7C	nop
80077D80	lui    v0, $8005
80077D84	lw     v0, $ea24(v0)
80077D88	nop
80077D8C	addiu  v0, v0, $0001
80077D90	andi   v0, v0, $0001
80077D94	lui    at, $8005
80077D98	sw     v0, $ea24(at)

L77d9c:	; 80077D9C
if( hu[800af370] & 0040 ) // cross currently pressed
{
    if( hu[800c2dd4] & 0100 ) // select repeated
    {
        if( w[800ad0c4] == S2 )
        {
            if( w[8004e9ac] == 0 )
            {
                if( w[800ad00c] == 0 )
                {
                    [8004e9f0] = w(0);
                    [800ad0c4] = w(0);

                    A0 = 2;
                    A1 = 0;
                    put_bytes_to_800C2F3C();
                }
            }
        }
    }
}

L77e20:	; 80077E20
80077E20	lui    v0, $800b
80077E24	lw     v0, $d0b0(v0)
80077E28	nop
80077E2C	bne    v0, s2, L780bc [$800780bc]
80077E30	nop
80077E34	lui    v0, $800b
80077E38	lw     v0, $d0b4(v0)
80077E3C	nop
80077E40	bne    v0, s2, L780bc [$800780bc]
80077E44	nop
80077E48	lui    v0, $800b
80077E4C	lw     v0, $d0bc(v0)
80077E50	nop
80077E54	bne    v0, s2, L780bc [$800780bc]
80077E58	nop
80077E5C	jal    func781dc [$800781dc]
80077E60	nop
80077E64	bne    v0, zero, L780bc [$800780bc]
80077E68	nop
80077E6C	lui    v0, $800b
80077E70	lw     v0, $d0c4(v0)
80077E74	nop
80077E78	bne    v0, s2, L780bc [$800780bc]
80077E7C	nop
V1 = hu[800af370];
V0 = V1 & 0003; // R2 L2 currently pressed
if( V0 == 0 )
{
    S4 = 0;
}
V0 = V1 & 1; // L2 currently pressed

80077E9C	beq    v0, zero, L77f48 [$80077f48]
80077EA0	nop
80077EA4	lui    v0, $800b
80077EA8	lw     v0, $d040(v0)
80077EAC	nop
80077EB0	bne    v0, s1, L77f48 [$80077f48]
80077EB4	andi   v0, v1, $0002
80077EB8	beq    v0, zero, L77f48 [$80077f48]
80077EBC	nop
80077EC0	bne    s4, zero, L77f48 [$80077f48]
80077EC4	nop
80077EC8	jal    func78ed0 [$80078ed0]
80077ECC	ori    s4, zero, $0001
80077ED0	lui    v0, $800b
80077ED4	lw     v0, $d03c(v0)
80077ED8	nop
80077EDC	bne    v0, s3, L77f48 [$80077f48]
80077EE0	nop
80077EE4	lui    v1, $800b
80077EE8	lw     v1, $1740(v1)
80077EEC	nop
80077EF0	sll    v0, v1, $01
80077EF4	addu   v0, v0, v1
80077EF8	sll    v0, v0, $03
80077EFC	subu   v0, v0, v1
80077F00	lui    v1, $800b
80077F04	lw     v1, $efe4(v1)
80077F08	sll    v0, v0, $02
80077F0C	addu   v0, v0, v1
80077F10	lw     v0, $004c(v0)
80077F14	nop
80077F18	lw     v0, $0000(v0)
80077F1C	nop
80077F20	andi   v0, v0, $1800
80077F24	bne    v0, zero, L77f48 [$80077f48]
80077F28	nop
80077F2C	lui    v0, $8006
80077F30	lbu    v0, $8819(v0)
80077F34	nop
80077F38	bne    v0, zero, L77f48 [$80077f48]
80077F3C	nop
80077F40	jal    funcac368 [$800ac368]
80077F44	nop

L77f48:	; 80077F48
V0 = hu[800c2dd4] & 0100; // select repeated
80077F58	beq    v0, zero, L77f90 [$80077f90]
80077F5C	nop
80077F60	lui    v0, $800b
80077F64	lw     v0, $d0c4(v0)
80077F68	nop
80077F6C	bne    v0, s2, L77f90 [$80077f90]
80077F70	nop
80077F74	lui    v0, $800b
80077F78	lw     v0, $d040(v0)
80077F7C	nop
80077F80	bne    v0, s1, L77f90 [$80077f90]
80077F84	nop
80077F88	jal    funcaaf70 [$800aaf70]
80077F8C	nop

L77f90:	; 80077F90
80077F90	lui    v0, $800b
80077F94	lw     v0, $d048(v0)
80077F98	nop
80077F9C	beq    v0, zero, L77fc8 [$80077fc8]
80077FA0	nop
80077FA4	lui    v0, $800b
80077FA8	lw     v0, $cfe0(v0)
80077FAC	nop
80077FB0	bne    v0, s1, L77fc8 [$80077fc8]
80077FB4	nop
80077FB8	jal    funca7130 [$800a7130]
80077FBC	nop
80077FC0	lui    at, $800b
80077FC4	sw     zero, $d048(at)

L77fc8:	; 80077FC8
80077FC8	lui    v0, $800b
80077FCC	lw     v0, $d03c(v0)
80077FD0	nop
80077FD4	beq    v0, s3, L78050 [$80078050]
80077FD8	nop
80077FDC	lui    v0, $800b
80077FE0	lw     v0, $cfe0(v0)
80077FE4	nop
80077FE8	bne    v0, zero, L78050 [$80078050]
80077FEC	nop
80077FF0	lui    v1, $800b
80077FF4	lw     v1, $1740(v1)
80077FF8	nop
80077FFC	sll    v0, v1, $01
80078000	addu   v0, v0, v1
80078004	sll    v0, v0, $03
80078008	subu   v0, v0, v1
8007800C	lui    v1, $800b
80078010	lw     v1, $efe4(v1)
80078014	sll    v0, v0, $02
80078018	addu   v0, v0, v1
8007801C	lw     v0, $004c(v0)
80078020	nop
80078024	lw     v0, $0000(v0)
80078028	nop
8007802C	andi   v0, v0, $1800
80078030	bne    v0, zero, L78050 [$80078050]
80078034	nop
80078038	jal    func7f5fc [$8007f5fc]
8007803C	nop
80078040	jal    func78fe8 [$80078fe8]
80078044	nop
80078048	lui    at, $800b
8007804C	sw     s3, $d03c(at)

L78050:	; 80078050
V0 = hu[800c2dd4] & 0010; // triangle repeated
80078060	beq    v0, zero, L780bc [$800780bc]
80078064	nop
80078068	lui    v0, $800b
8007806C	lbu    v0, $16a4(v0)
80078070	nop
80078074	bne    v0, zero, L780bc [$800780bc]
80078078	nop
8007807C	lui    v0, $800b
80078080	lw     v0, $d03c(v0)
80078084	nop
80078088	bne    v0, s3, L780bc [$800780bc]
8007808C	nop
80078090	lui    v0, $800b
80078094	lw     v0, $d040(v0)
80078098	nop
8007809C	bne    v0, s1, L780bc [$800780bc]
800780A0	ori    v0, zero, $0080

L780a4:	; 800780A4
800780A4	lui    v1, $800b
800780A8	lhu    v1, $1840(v1)
800780AC	lui    at, $800b
800780B0	sw     v0, $d03c(at)
800780B4	lui    at, $8006
800780B8	sb     v1, $8811(at)

L780bc:	; 800780BC
800780BC	jal    func78170 [$80078170]
800780C0	nop
800780C4	j      L77810 [$80077810]
800780C8	nop

L780cc:	; 800780CC
800780CC	jal    func78ed0 [$80078ed0]
800780D0	nop
800780D4	jal    funca86c8 [$800a86c8]
800780D8	nop
800780DC	jal    funca2778 [$800a2778]
800780E0	nop
800780E4	jal    funca8938 [$800a8938]
800780E8	nop
800780EC	jal    func85b04 [$80085b04]
800780F0	nop
800780F4	jal    func7f5fc [$8007f5fc]
800780F8	nop
800780FC	jal    func44448 [$80044448]
80078100	addu   a0, zero, zero
80078104	jal    func4b3f4 [$8004b3f4]
80078108	addu   a0, zero, zero
8007810C	jal    func6f740 [$8006f740]
80078110	nop
80078114	jal    func773bc [$800773bc]
80078118	nop
8007811C	jal    func84f9c [$80084f9c]
80078120	nop
80078124	lui    a0, $800b
80078128	lw     a0, $d008(a0)
8007812C	lui    at, $8005
80078130	sw     zero, $e9c0(at)
80078134	jal    func31f0c [$80031f0c]
80078138	nop
8007813C	jal    func78b60 [$80078b60]
80078140	addu   a0, s0, zero
80078144	lw     ra, $0034(sp)
80078148	lw     s6, $0030(sp)
8007814C	lw     s5, $002c(sp)
80078150	lw     s4, $0028(sp)
80078154	lw     s3, $0024(sp)
80078158	lw     s2, $0020(sp)
8007815C	lw     s1, $001c(sp)
80078160	lw     s0, $0018(sp)
80078164	addiu  sp, sp, $0038
80078168	jr     ra 
8007816C	nop
////////////////////////////////

