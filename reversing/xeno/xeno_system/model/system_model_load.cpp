////////////////////////////////
// func301d8
S0 = A0;
S2 = w[S0 + 1c];
S4 = A1;

if( S2 == 0 )
{
    return 0;
}

[GP + 1a8] = h(2b);

A0 = (w[S2] << 5) | 14;
A1 = S4;
system_memory_allocate;
S1 = V0;

80030230	sw     s0, $0000(s1)
80030234	lw     v0, $0008(s0)
80030238	nop
8003023C	sw     v0, $0004(s1)
80030240	lw     v0, $000c(s0)
80030244	addiu  s3, s1, $0014
80030248	sw     s3, $0010(s1)
8003024C	sw     v0, $0008(s1)
80030250	lw     v0, $0000(s2)

8003025C	sw     v0, $000c(s1)

[GP + 1a8] = h(2c);


80030260	lhu    a0, $0002(s0)
8003026C	sll    a0, a0, $03
A1 = S4;
system_memory_allocate;

80030270	lhu    a1, $0002(s0)
80030274	sw     v0, $0008(s0)
80030278	addiu  v0, zero, $ffff (=-$1)
8003027C	addiu  a1, a1, $ffff (=-$1)
80030280	beq    a1, v0, L302e0 [$800302e0]
80030284	nop
80030288	addiu  a2, zero, $ffff (=-$1)

loop3028c:	; 8003028C
8003028C	sll    a0, a1, $03
80030290	addiu  a1, a1, $ffff (=-$1)
80030294	lw     v1, $0004(s1)
80030298	lw     v0, $0008(s0)
8003029C	addu   v1, a0, v1
800302A0	lhu    v1, $0000(v1)
800302A4	addu   v0, a0, v0
800302A8	sh     v1, $0000(v0)
800302AC	lw     v0, $0004(s1)
800302B0	lw     v1, $0008(s0)
800302B4	addu   v0, a0, v0
800302B8	lhu    v0, $0002(v0)
800302BC	addu   v1, a0, v1
800302C0	sh     v0, $0002(v1)
800302C4	lw     v0, $0004(s1)
800302C8	lw     v1, $0008(s0)
800302CC	addu   v0, a0, v0
800302D0	lhu    v0, $0004(v0)
800302D4	addu   a0, a0, v1
800302D8	bne    a1, a2, loop3028c [$8003028c]
800302DC	sh     v0, $0004(a0)

L302e0:	; 800302E0
800302E0	lhu    v0, $0000(s0)
800302E4	nop
800302E8	andi   v0, v0, $0010
800302EC	beq    v0, zero, L3037c [$8003037c]

[GP + 1a8] = h(2d);

800302FC	lhu    a0, $0002(s0)
80030300	addu   a1, s4, zero
80030304	jal    system_memory_allocate [$800319ec]
80030308	sll    a0, a0, $03
8003030C	lhu    a1, $0002(s0)
80030310	sw     v0, $000c(s0)
80030314	addiu  v0, zero, $ffff (=-$1)
80030318	addiu  a1, a1, $ffff (=-$1)
8003031C	beq    a1, v0, L3037c [$8003037c]
80030320	nop
80030324	addiu  a2, zero, $ffff (=-$1)

loop30328:	; 80030328
80030328	sll    a0, a1, $03
8003032C	addiu  a1, a1, $ffff (=-$1)
80030330	lw     v1, $0008(s1)
80030334	lw     v0, $000c(s0)
80030338	addu   v1, a0, v1
8003033C	lhu    v1, $0000(v1)
80030340	addu   v0, a0, v0
80030344	sh     v1, $0000(v0)
80030348	lw     v0, $0008(s1)
8003034C	lw     v1, $000c(s0)
80030350	addu   v0, a0, v0
80030354	lhu    v0, $0002(v0)
80030358	addu   v1, a0, v1
8003035C	sh     v0, $0002(v1)
80030360	lw     v0, $0008(s1)
80030364	lw     v1, $000c(s0)
80030368	addu   v0, a0, v0
8003036C	lhu    v0, $0004(v0)
80030370	addu   a0, a0, v1
80030374	bne    a1, a2, loop30328 [$80030328]
80030378	sh     v0, $0004(a0)

L3037c:	; 8003037C
8003037C	lw     v0, $000c(s1)
80030380	nop
80030384	blez   v0, L303c0 [$800303c0]
80030388	addu   a1, zero, zero
8003038C	lui    a0, $8003
80030390	addiu  a0, a0, $ff5c (=-$a4)
80030394	addiu  v1, s3, $000c

loop30398:	; 80030398
80030398	sw     a0, $0000(s3)
8003039C	sw     zero, $fff8(v1)
800303A0	sw     zero, $fffc(v1)
800303A4	sw     zero, $0000(v1)
800303A8	addiu  v1, v1, $0020
800303AC	lw     v0, $000c(s1)
800303B0	addiu  a1, a1, $0001
800303B4	slt    v0, a1, v0
800303B8	bne    v0, zero, loop30398 [$80030398]
800303BC	addiu  s3, s3, $0020

L303c0:	; 800303C0
800303C0	addu   v0, s1, zero

L303c4:	; 800303C4
////////////////////////////////



////////////////////////////////
// func2c1f8
// sets global offsets for model file and return number of parts
// A0 - pointer to model 3d data file
offset_to_file = A0;
T0 = w[offset_to_file + 4];
T2 = w[offset_to_file + 0];

if( ( T0 & 1 ) == 0 )
{
    [offset_to_file + 4] = w(T0 | 1);
    if( T2 > 0 )
    {
        A0 = offset_to_file + 10;

        T0 = 0;
        loop2c224:	; 8002C224
            [A0 + 8] = w(w[A0 + 8] + offset_to_file);
            [A0 + c] = w(w[A0 + c] + offset_to_file);
            [A0 + 10] = w(w[A0 + 10] + offset_to_file)
            [A0 + 14] = w(w[A0 + 14] + offset_to_file);

            V1 = w[A0 + 1c];
            if( V1 != 0 )
            {
                V0 = V1 + offset_to_file;
                [A0 + 1c] = w(V0);
                A2 = w[V0];
                V1 = V0 + 4;
                if( A2 != -1 )
                {
                    A1 = V1 + A2 * c;

                    loop2c288:	; 8002C288
                        [A1 + 4] = w(w[A1 + 4] + offset_to_file);
                        [A1 + 8] = w(w[A1 + 8] + offset_to_file);
                        A1 = A1 - c;
                        A2 = A2 - 1;
                    8002C2A4	bne    a2, -1, loop2c288 [$8002c288]
                }
            }

            A0 = A0 + 38;
            T0 = T0 + 1;
            V0 = T0 < T2;
        8002C2B4	bne    v0, zero, loop2c224 [$8002c224]
    }
}

return T2;
////////////////////////////////



////////////////////////////////
// func2c454
if( ( w[A0 + 4] & 00000002 ) == 0 )
{
    [A0 + 4] = w(w[A0 + 4] | 00000002);

    A0 = A0;
    A1 = w[A0 + 24] - A0;
    func31d94;

    return 0;
}
return 1;
////////////////////////////////



////////////////////////////////
// func31d94
part_header = A0;
T2 = w[part_header - 8];
if( A1 + 10 < T2 - part_header - 8 )
{
    [GP + 1bc] = w(1);

    [part_header + A1 + 0] = w(T2);
    [part_header + A1 + 4] = w(w[part_header + A1 + 4] & fe1fffff & 03ffffff | 84000000 & ffe00000 & fdffffff);
    [part_header - 8] = w(part_header + A1 + 8);

    return part_header - 8;
}

return 0;
////////////////////////////////



////////////////////////////////
// system_fill_packets_drafts_for_model_part
// A0 - model part data pointer
// A1 - packet data pointer
// A2 == 0 - not calculate lighting
// A2 == 1 - calculate lighing but not store it
// A2 == 2 - calculate and store lighing for the first time and then use stored data
// A2 == 3 - calculate lighing and store it

part_data          = A0;
packet_data_offset = A1; // pointer to allocated memory for packets
light_flags        = A2;

// allocate place for lightings normals
if( ( hu[part_data + 0] & 1 ) == 0 ) // if buffer not allocated
{
    if( w[part_data + 30] != 0 ) // if there is size for buffer
    {
        if( light_flags != 0 ) // if we calculate lighting
        {
            [GP + 1a8] = h(26);

            A0 = w[part_data + 30];
            A1 = 0;
            system_memory_allocate;
            [part_data + 18] = w(V0);

            [part_data + 0] = h(hu[part_data + 0] | 1);
        }
    }
}

mesh_data_offset    = w[part_data + 10];
texture_data_offset = w[part_data + 14];

[80058bd8] = w(w[part_data + 8]);
[80058bc8] = w(w[part_data + c]);
[80058b34] = w(w[part_data + 18]);

if( light_flags == 0 )
{
    S5 = 0; // not calculate light
}
else if( light_flags == 1 )
{
    S5 = 1; // calculate light but not store it
}
else if( light_flags == 2 )
{
    if( ( hu[part_data + 0] & 2 ) == 0 ) // if normals not calculated yet
    {
        if( hu[part_data + 0] & 1 ) // if buffer allocated
        {
            S5 = 3; // calculate light and store it
            [part_data + 0] = h(hu[part_data + 0] | 2);
        }
        else
        {
            S5 = 1; // calculate light but not store it
        }
    }
    else
    {
        if( hu[part_data + 0] & 1 )
        {
            S5 = 4; // use calculated stored light
        }
        else
        {
            S5 = 1; // calculate light but not store it
        }
    }
}
else if( light_flags == 3 )
{
    if( ( hu[part_data + 0] & 1 ) != 0 )
    {
        S5 = 3; // calculate light and store it
        [part_data + 0] = h(hu[part_data + 0] | 2);
    }
}



[80058c5c] = w(w[80058c5c] + hu[part_data + 4]); // + number of polygons



S2 = hu[part_data + 6]; // number of polygons block
S2 = S2 - 1;
if( S2 != -1 )
{
    loop2c84c:	; 8002C84C
        type_of_polygons = bu[mesh_data_offset + 0];
        number_of_polygons = h[mesh_data_offset + 2] - 1;
        mesh_data_offset = mesh_data_offset + 4;

        if( number_of_polygons != -1 )
        {
            // calculate lighting for packets
            loop2c894:	; 8002C894
                A0 = texture_data_offset;
                A1 = mesh_data_offset;
                A2 = S5;
                8002C8A4	jalr   w[8004f4f4 + type_of_polygons * 28 + 18] ra

                if( V0 != 0 )
                {
                    mesh_data_offset = mesh_data_offset + w[8004f4f4 + type_of_polygons * 28 + 1c]; // polygon data
                    texture_data_offset = texture_data_offset + w[8004f4f4 + type_of_polygons * 28 + 20]; // tex data
                    packet_data_offset = packet_data_offset + w[8004f4f4 + type_of_polygons * 28 + 24]; // packets
                }
                else
                {
                    number_of_polygons = number_of_polygons + 1;
                    texture_data_offset = texture_data_offset + 4;
                }

                number_of_polygons = number_of_polygons - 1;
            8002C920	bne    number_of_polygons, -1, loop2c894 [$8002c894]
        }

        S2 = S2 - 1;
    8002C92C	bne    s2, -1, loop2c84c [$8002c84c]
}

// this not needed, I just add this in case this data used somewhere else
[80058bc4] = w(mesh_data_offset);
[80058bd4] = w(texture_data_offset);
[80058ac0] = w(packet_data_offset);

system_reset_tex_page_and_clut_default_usage;
////////////////////////////////



////////////////////////////////
// system_reset_tex_page_and_clut_default_usage
[8004f7ac] = w(0);
[8004f7b0] = w(1);
////////////////////////////////



////////////////////////////////
// system_allocate_memory_for_packets
S0 = A0;
S1 = A1;
S2 = A2;

[GP + 1a8] = h(25);

A0 = w[S0 + 34] * 2;
A1 = 0;
system_memory_allocate;

[S1] = w(V0);
[S2] = w(V0 + w[S0 + 34]);

return w[S2];
////////////////////////////////



////////////////////////////////
// func384f4
if (A0 != 0)
{
    A1 = h[A0 + 14];
}

V1 = w[80058adc];
if (V1 != 0)
{
    loop3851c:	; 8003851C
        if (A1 == h[V1 + 14])
        {
            return V1;
        }

        V1 = w[V1 + 1c];
    80038534	bne    v1, zero, loop3851c [$8003851c]
}

return V1;
////////////////////////////////



////////////////////////////////
// func382d0
800382D0	addiu  sp, sp, $ffe8 (=-$18)
800382D4	sw     s0, $0010(sp)
800382D8	addu   s0, a0, zero
800382DC	lui    v0, $8006
800382E0	lhu    v0, $8c18(v0)
800382E4	nop
800382E8	andi   v0, v0, $0080
800382EC	bne    v0, zero, L3832c [$8003832c]
800382F0	sw     ra, $0014(sp)
800382F4	lui    v1, $8006
800382F8	lw     v1, $8adc(v1)
800382FC	nop
80038300	beq    v1, zero, L38330 [$80038330]
80038304	lui    a1, $7364
80038308	lhu    a1, $0014(s0)

loop3830c:	; 8003830C
8003830C	lhu    v0, $0014(v1)
80038310	nop
80038314	beq    a1, v0, L3835c [$8003835c]
80038318	nop
8003831C	lw     v1, $001c(v1)
80038320	nop
80038324	bne    v1, zero, loop3830c [$8003830c]
80038328	nop

L3832c:	; 8003832C
8003832C	lui    a1, $7364

L38330:	; 80038330
80038330	ori    a1, a1, $6573
80038334	jal    func3f4bc [$8003f4bc]
80038338	ori    a2, zero, $0101
8003833C	sll    v0, v0, $10
80038340	sra    a0, v0, $10
80038344	beq    a0, zero, L3836c [$8003836c]
80038348	nop
8003834C	jal    func3f558 [$8003f558]
80038350	nop
80038354	j      L383c0 [$800383c0]
80038358	nop

L3835c:	; 8003835C
8003835C	jal    func3f558 [$8003f558]
80038360	ori    a0, zero, $0015
80038364	j      L383c0 [$800383c0]
80038368	nop

L3836c:	; 8003836C
8003836C	lui    a0, $8006
80038370	lw     a0, $8c58(a0)
80038374	jal    func4032c [$8004032c]
80038378	nop
8003837C	lui    v0, $8006
80038380	lw     v0, $8adc(v0)
80038384	lui    a0, $8006
80038388	addiu  a0, a0, $8adc (=-$7524)
8003838C	beq    v0, zero, L383ac [$800383ac]
80038390	nop

loop38394:	; 80038394
80038394	lw     v0, $0000(a0)
80038398	nop
8003839C	lw     v1, $001c(v0)
800383A0	nop
800383A4	bne    v1, zero, loop38394 [$80038394]
800383A8	addiu  a0, v0, $001c

L383ac:	; 800383AC
800383AC	sw     s0, $0000(a0)
800383B0	lui    a0, $8006
800383B4	lw     a0, $8c58(a0)
800383B8	jal    func4031c [$8004031c]
800383BC	sw     zero, $001c(s0)

L383c0:	; 800383C0
800383C0	lw     ra, $0014(sp)
800383C4	lw     s0, $0010(sp)
800383C8	addiu  sp, sp, $0018
800383CC	jr     ra 
800383D0	nop
////////////////////////////////
