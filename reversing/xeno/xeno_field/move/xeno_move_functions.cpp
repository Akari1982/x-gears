////////////////////////////////
// get_current_triangle_material()
walkmesh_id = h[A0 + 10];
if( ( ( w[A0 + 4] >> walkmesh_id + 3 ) & 1 ) == 0 )
{
    triangle_data = w[800aeff8 + walkmesh_id * 4];
    material_data = w[800aeff4];
    triangle_id = h[A0 + 8 + walkmesh_id * 2];
    V0 = bu[triangle_data + triangle_id * e + c];
    return w[material_data + V0 * 4];
}
return 0;
////////////////////////////////



////////////////////////////////
// func7ac28()
V0 = h[800b1660]; // base walking speed
res = A0;
rot = A2 & 0fff;

S0 = ((A1 << 4) * V0) >> c;

A0 = rot;
system_cos();
[res + 0] = w(V0 * S0);

A0 = rot;
system_sin();

[res + 4] = w(0);
[res + 8] = w(0 - V0 * S0);
////////////////////////////////



////////////////////////////////
// get_distance_between_entities()
entity_id1 = A0;
entity_id2 = A1;

struct_5c = w[800aefe4];
struct_138_1 = w[struct_5c + entity_id1 * 5c + 4c];
struct_138_2 = w[struct_5c + entity_id2 * 5c + 4c];

A0 = h[struct_138_2 + 22] - h[struct_138_1 + 22];
A1 = h[struct_138_2 + 2a] - h[struct_138_1 + 2a];
length_of_vector_by_x_y();
////////////////////////////////



////////////////////////////////////////////////////////
// length_of_vector_by_x_y()
[SP + 10] = w(A0);
[SP + 14] = w(A1);
[SP + 18] = w(0);

A0 = SP + 10;
A1 = SP + 20;
system_gte_square_of_vector;

V0 = w[SP + 20];
A0 = w[SP + 24];
A0 = V0 + A0;
system_square_root;

return V0;
////////////////////////////////////////////////////////



////////////////////////////////
// func83f40()
struct_138 = A0;

if( ( w[struct_138 + 14] & 00420000 ) == 0 && 
    w[800ad070] == 0 &&
    w[struct_138 + 30] == 0 && // X
    w[struct_138 + 34] == 0 && // Y
    w[struct_138 + 38] == 0 && // Z
    w[800ad0e4] == 1 &&
    bu[struct_138 + 74] == ff &&
    (w[struct_138 + 0] & 00401800) == 0 &&
    ((w[struct_138 + 4] & 00000001) == 0 || h[struct_138 + 10] != 0) &&
    ((w[struct_138 + 4] & 00000002) == 0 || h[struct_138 + 10] != 1))
{
    if ((w[struct_138 + 4] & 00000004) == 0)
    {
        return 0;
    }

    return (h[struct_138 + 10] ^ 0002) < 1; // -1 if bit 0x0002 set, 0 otherwise
}

return -1;
////////////////////////////////



////////////////////////////////
// func81594()
struct_unk = S2 = A0;
rotation = A1;
struct_5c = S3 = A2;

struct_138 = w[struct_5c + 4c];

if( rotation & 8000 )
{
    [struct_unk + c] = w(0);
    [struct_unk + 14] = w(0);
    return;
}

if( ( hu[struct_5c + 58] & 0040 ) == 0 ) // this is model
{
    S1 = ((40000 / hu[struct_138 + 76]) >> 8) << 5;

    A0 = rotation & 0fff;
    system_cos();
    [struct_unk + c] = w(((V0 * S1) >> c) * h[struct_138 + f4]);
    [struct_unk + c] = w(w[struct_unk + c] & fffff000);

    A0 = rotation & 0fff;
    system_sin();
    [struct_unk + 14] = w(((0 - (V0 * S1)) >> c) * h[struct_138 + f8]);
    [struct_unk + 14] = w(w[struct_unk + 14] & fffff000);
    return;
}

80081610	lw     a0, $004c(s3)
80081614	nop
80081618	lw     v1, $0004(a0)
8008161C	nop
80081620	andi   v0, v1, $2000
80081624	bne    v0, zero, L816e4 [$800816e4]

8008162C	lui    v0, $0008
80081630	and    v0, v1, v0

if( V0 == 0 )
{
    A0 = S2;
    A1 = rotation;
    80081640	jal    func21e40 [$80021e40]

    [S2 + c] = w(w[S2 + c] & fffff000);
    [S2 + 14] = w(w[S2 + 14] & fffff000);
    return;
}

V1 = hu[A0 + 76];
V0 = 40000 / V1;
S0 = A1 & 0fff;
V0 = V0 >> 8;
S1 = V0 << 5;

A0 = S0;
system_cos();

80081674	mult   v0, s1
80081678	lw     v0, $004c(s3)
8008167C	mflo   a3
80081680	lh     v1, $00f4(v0)
80081684	sra    v0, a3, $0c
80081688	mult   v0, v1
8008168C	addu   a0, s0, zero
80081690	mflo   a3
80081698	sw     a3, $000c(s2)
system_sin();

8008169C	mult   v0, s1
800816A0	lw     v1, $004c(s3)
800816A4	nop
800816A8	lh     v1, $00f8(v1)
800816AC	mflo   a3
800816B0	subu   v0, zero, a3
800816B4	sra    v0, v0, $0c
800816B8	mult   v0, v1
800816BC	mflo   a3
800816C0	sw     a3, $0014(s2)
800816C4	lw     v0, $004c(s3)
800816C8	nop
800816CC	lhu    v1, $0076(v0)
800816D0	lui    v0, $0400
800816D4	div    v0, v1
800816D8	mflo   v0
800816E0	sw     v0, $0018(s2)
[S2 + c] = w(w[S2 + c] & fffff000);
[S2 + 14] = w(w[S2 + 14] & fffff000);
return;

L816e4:	; 800816E4
if( ( V1 & 00020000 ) == 0 )
{
    S1 = ((80000 / hu[struct_138 + 76]) >> 8) << 5;

    A0 = rotation & 0fff;
    system_cos();
    [S2 + c] = w(((V0 * S1) >> c) * h[struct_138 + f4]);
    [S2 + c] = w(w[S2 + c] & fffff000);

    A0 = rotation & 0fff;
    system_sin();
    [S2 + 14] = w(((0 - (V0 * S1)) >> c) * h[struct_138 + f8]);
    [S2 + 14] = w(w[S2 + 14] & fffff000);
    return;
}

L8176c:	; 8008176C
8008176C	lw     v0, $012c(a0)
80081770	nop
80081774	srl    v1, v0, $0b
80081778	lui    v0, $801f
8008177C	addiu  v0, v0, $8670 (=-$7990)
80081780	andi   v1, v1, $001c
80081784	addu   v1, v1, v0
80081788	lw     v0, $0000(v1)
8008178C	nop
80081790	lw     v0, $0128(v0)
80081794	nop
80081798	subu   v0, zero, v0
8008179C	sll    v0, v0, $10
800817A0	sw     v0, $000c(s2)
800817A4	lw     v0, $0000(v1)
800817A8	nop
800817AC	lw     v0, $0130(v0)
800817B0	nop
800817B4	subu   v0, zero, v0
800817B8	sll    v0, v0, $10
800817C0	sw     v0, $0014(s2)

[S2 + c] = w(w[S2 + c] & fffff000);
[S2 + 14] = w(w[S2 + 14] & fffff000);
////////////////////////////////
