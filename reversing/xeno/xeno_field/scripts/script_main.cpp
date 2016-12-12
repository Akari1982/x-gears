////////////////////////////////
// funca183c
// call script_for_entity 0
S1 = A0;

struct_5c_p = w[800aefe4];
struct_138 = w[struct_5c_p + 4c];
[800afb8c] = w(struct_5c_p);
[800af54c] = struct_138;

A0 = 138;
A1 = 1;
system_memory_allocate();
S0 = V0;

A2 = struct_138;
A3 = S0;
T0 = struct_138 + 130;
loopa1890:	; 800A1890
    [A3 + 0] = w(w[A2 + 0]);
    [A3 + 4] = w(w[A2 + 4]);
    [A3 + 8] = w(w[A2 + 8]);
    [A3 + c] = w(w[A2 + c]);
    A2 = A2 + 10;
    A3 = A3 + 10;
800A18B4	bne    a2, t0, loopa1890 [$800a1890]



800A18BC	lw     v0, $0000(a2)
800A18C0	lw     v1, $0004(a2)
800A18C4	sw     v0, $0000(a3)
800A18C8	sw     v1, $0004(a3)
800A18CC	addu   a2, zero, zero
800A18D0	lui    t2, $fffc
800A18D4	ori    t2, t2, $ffff
800A18D8	lui    t4, $003c
800A18DC	ori    a3, zero, $ffff
800A18E0	lui    t1, $ffbf
800A18E4	ori    t1, t1, $ffff
800A18E8	ori    t3, zero, $00ff
800A18EC	lui    t0, $fe7f
800A18F0	ori    t0, t0, $ffff

loopa18f4:	; 800A18F4
    800A18F4	lui    v0, $800b
    800A18F8	lw     v0, $f54c(v0)
    800A18FC	sll    a1, a2, $03
    800A1900	addu   v0, v0, a1
    800A1904	sb     zero, $008e(v0)
    800A1908	lui    v1, $800b
    800A190C	lw     v1, $f54c(v1)
    800A1910	nop
    800A1914	addu   v1, v1, a1
    800A1918	lw     v0, $0090(v1)
    800A191C	sb     t3, $008f(v1)
    800A1920	lui    a0, $800b
    800A1924	lw     a0, $f54c(a0)
    800A1928	sh     a3, $008c(v1)
    800A192C	and    v0, v0, t2
    800A1930	or     v0, v0, t4
    800A1934	sw     v0, $0090(v1)
    800A1938	lw     v0, $0090(v1)
    800A193C	addu   a0, a0, a1
    800A1940	and    v0, v0, t1
    800A1944	sw     v0, $0090(v1)
    800A1948	sh     a3, $0090(a0)
    800A194C	lw     v0, $0090(a0)
    800A1950	addiu  a2, a2, $0001
    800A1954	and    v0, v0, t0
    800A1958	sw     v0, $0090(a0)
    800A195C	slti   v0, a2, $0008
800A1960	bne    v0, zero, loopa18f4 [$800a18f4]

[800af1f0] = w(0);
[800acff4] = w(0);
[800af4c0] = w(0);

A0 = 0;
A1 = S1;
get_script_offset();

V1 = w[800af54c];
[V1 + cc] = h(V0);

A0 = ffff;
run_script();

800A199C	addu   a3, s0, zero
800A19A0	addiu  t0, s0, $0130
800A19A4	lui    v1, $800b
800A19A8	lw     v1, $fb8c(v1)
800A19AC	ori    v0, zero, $0001
800A19B0	lui    at, $800b
800A19B4	sw     v0, $cff4(at)
800A19B8	lw     a2, $004c(v1)

loopa19bc:	; 800A19BC
    800A19BC	lw     v0, $0000(a3)
    800A19C0	lw     v1, $0004(a3)
    800A19C4	lw     a0, $0008(a3)
    800A19C8	lw     a1, $000c(a3)
    800A19CC	sw     v0, $0000(a2)
    800A19D0	sw     v1, $0004(a2)
    800A19D4	sw     a0, $0008(a2)
    800A19D8	sw     a1, $000c(a2)
    800A19E4	addiu  a2, a2, $0010
    800A19DC	addiu  a3, a3, $0010
800A19E0	bne    a3, t0, loopa19bc [$800a19bc]

V0 = w[A3 + 0];

800A19EC	lw     v1, $0004(a3)
800A19F0	sw     v0, $0000(a2)
800A19F4	sw     v1, $0004(a2)

A0 = S0;
800A19F8	jal    func31f0c [$80031f0c]
////////////////////////////////



////////////////////////////////
// call_run_script_8()
// called in move routine
// run 8 opcodes for non-party entities

if( w[800ad04c] == 1 )
{
    number_of_entity = 1;
}
else
{
    number_of_entity = w[800ad0d4]; // number of entity
}

[800ad040] = w(0);
[800c373c] = w(0); // maybe number of inited windows.

if( number_of_entity <= 0 )
{
    return;
}

entity_id = 0;
La1624:	; 800A1624
    struct_5c_p = w[800aefe4];

    if( hu[struct_5c_p + entity_id * 5c + 58] & 0f00 )
    {
        struct_138 = w[struct_5c_p + entity_id * 5c + 4c];
        // we dont move if this bit is set
        if( ( w[struct_138 + 4] & 00100000 ) == 0 )
        {
            if( w[800acff4] != 0 )
            {
                if( ( w[800ad0b8] == 0 ) || ( w[800ad0bc] == 0 ) || ( w[800ad0c4] == 0 ))
                {
                    return;
                }
            }

            [struct_138 + 0] = w(w[struct_138 + 0] & feffffff);
            [800afb8c] = w(struct_5c_p + entity_id * 5c);
            [800af1f0] = w(entity_id);
            [800af54c] = w(struct_138);

            if( bu[800b16a0] != 0 )
            {
                party_id = 0;
                loopa16fc:	; 800A16FC
                    if( w[80059ad4 + party_id * 4] != ff )
                    {
                        // if this entity is in party - skip it
                        800A170C	beq    v0, entity_id, La1808 [$800a1808]
                    }
                    party_id = party_id + 1;
                    V0 = party_id < 3;
                800A171C	bne    v0, zero, loopa16fc [$800a16fc]
            }

            top_priority = f;

            script_slot_id = 0;
            loopa1728:	; 800A1728
                priority = (w[struct_138 + 8c + script_slot_id * 8 + 4] >> 12) & f;
                if( top_priority >= priority )
                {
                    top_priority = priority;
                    [struct_138 + ce] = b(script_slot_id);
                }
                script_slot_id = script_slot_id + 1;
                V0 = script_slot_id < 8;
            800A1764	bne    v0, zero, loopa1728 [$800a1728]

            // if there is no script in slots add script 1 to first slot
            if( top_priority == f )
            {
                A0 = entity_id;
                A1 = 1;
                get_script_offset();

                [struct_138 + 8c + 0] = h(V0);
                [struct_138 + ce] = b(0);
                [struct_138 + 8c + 4] = w((w[struct_138 + 8c + 4] & ffc3ffff) | 001c0000); // run script with priority 7
            }

            [800af4c0] = w(1); // execute once and finish at stop

            V0 = bu[struct_138 + ce]; // current script slot
            [struct_138 + cc] = h(hu[struct_138 + 8c + V0 * 8 + 0]);

            if( ( w[struct_138 + 0] & 00000001 ) == 0 )
            {
                // execute 8 opcodes
                A0 = 8;
                run_script();
            }

            // update script pointer in slot
            V1 = bu[struct_138 + ce]; // current script slot
            [struct_138 + 8c + V1 * 8 + 0] = h(hu[struct_138 + cc]);
        }
    }

    entity_id = entity_id + 1;
    V0 = entity_id < number_of_entity;
800A1810	bne    v0, zero, La1624 [$800a1624]
////////////////////////////////



////////////////////////////////
// run_script()
exec_num = A0;

[800af594] = w(0);
[800af150] = w(exec_num);

if( exec_num <= 0 )
{
    return;
}

S0 = 0;
loopa1488:	; 800A1488
    // do not execute too much opcodes
    if( S0 >= 401 )
    {
        if( w[800c1b60] == 0 )
        {
            A0 = 8006f414; // EVENTLOOP ERROR ACT=%d
            A1 = w[800af1f0]; // current entity id
            func37870();
        }
        return;
    }

    date_138 = w[800af54c];
    V1 = hu[date_138 + cc];
    V0 = w[800ad0d8];
    V0 = bu[V0 + V1];
    V0 = w[800ad778 + V0 * 4];
    jalr   v0 ra

00110A80 00
04140A80 01
60110A80
D8B60980
1C100A80
840D0A80
C00C0A80
08E10980
F8E20980
30E60980
10490980
B40B0A80 0b
480E0A80 0d
D8190980
B8190980
10 D481098010820980D427098050250A801C3209804032098048FE0980ACDE0980CCDD09804CDA0980B8D90980ECD8098058D80980D8D7098098D7098030D70980
20 9CD6098024D60980A0D40980D0D509807CD3098024D40980C4D20980DCD1098058D1098054D00980ACCF0980D4CF098004970980F895098098950980CC940980
30 1C950980745709809C570980C4570980E857098034CF0980F0CE0980ACCE098020CE098094CD0980D4CB098098C90980D0C8098034C9098048CB0980BCCA0980
40 30CA098060C80980F0C7098028C7098058770980386E0980DC1D098074240980A43209801C330980548F0980047A0980C46F0980286F09804479098048780980
50 786D09807C6C0980D07609800C760980946B0980706A0980E8250980E8870980EC3E09805CEA09802048098058480980B8F70980489709808097098040A30980
60 A4F3088000F40880D8F4088064F508803CF6088098F6088070F70880D0A1098008A2098050A2098088A2098030A1098080A10980809C09803C9D09807C980980
70 B89709803C2B0980F8EC0880486208803CEC088040ED08803C3009806C300980786909803868098080680980D05F0980EC640980E4650980DC660980D4480980
80 381C09809C1C0980382C09803C1D0980185C0980885C0980F85C0980645D0980BC5D09801C540980D451098094580980F0580980E0590980F85409808C550980
90 F0550980845A0980400F0A80F4080A80A83B0980243C0980603C0980089C0980A42809806CF1088020F2088014F30880E0B009802099098074AF0980E0AF0980
50B00980 a0
449C0980
609B0980
FCF70880
649A0980
089B0980
E4690980 a6
80C70980 a8
6CB20980
C0A20980
D4F80880
90F90880
EC000980
70010980
F4010980
b0 8C02098024030980B49B0980F068098038690980B8AE098080AC0980B0A30980E0A30980085B09807C5B0980C85B0980CC020A8030400980A040098010410980
c0 80410980F041098060420980C868098004340980943509802C140A80F8AD098058AE0980084D0980F89D0980944E0980F44A098000D0098028D00980D8C30980
d0 70C4098000C5098088B60980B0B60980F0B50980FC1B0980741B0980903C0980E43C0980383D0980BC1709805815098018160980D413098068CC0980F8CC0980
e0 6C14098090110980245709804C570980A8100980180F0980DC0F09804C1009802C37098080390980D023098094060980EC080980980B0980F40C09800CF00880
C0030980 f0
1CA80880
E0EE0880
44040980
70B40980
00B70980 f5
70DB0880 f8
38D40880
843D0980
54CD0880
60B50980
50250A80
CC5F0880
50250A80

    // if ??? set exec opcodes number to maximum
    if( w[800af4c0] == 0 )
    {
        [800af150] = w(ffff);
    }

    if( ( w[800acff4] != 0 ) && ( w[800ad0d8] == 0 || w[800ad0bc] == 0 || w[800ad0c4] == 0 ) )
    {
        return;
    }

    if( ( w[800af594] == 1 ) && ( w[800af4c0] == 1 ) )
    {
        return;
    }

    S0 = S0 + 1;
    V0 = S0 < exec_num;
800A15A0	bne    v0, zero, loopa1488 [$800a1488]
////////////////////////////////
