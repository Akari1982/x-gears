////////////////////////////////
// 0x0B EntityNPCSpriteInit
entity_id = w[800af1f0];
sprite_data = w[800aeff0];
struct_5c_p = w[800aefe4];
struct_138 = w[800af54c];

[struct_5c_p + entity_id * 5c + 58] = h((hu[struct_5c_p + entity_id * 5c + 58] & f07f) | 0200);

A0 = 1;
read_two_bytes_with_80();

A0 = entity_id;
A1 = V0; // sprite id to load
A2 = sprite_data + w[sprite_data + V0 * 4 + 4];
A3 = 0; // local sprite
A4 = 0;
A5 = V0 | 80;
A6 = 0;
func76150();

funca0224();

[struct_138 + 0] = w((w[struct_138 + 0] | 00000100) & ffffff7f); // make solid
[struct_138 + 4] = w(w[struct_138 + 4] & fffff7ff);
[struct_138 + cc] = h(hu[struct_138 + cc] + 3);

[struct_5c_p + entity_id * 5c + 58] = h(hu[struct_5c_p + entity_id * 5c + 58] & ffdf);
////////////////////////////////



////////////////////////////////
// 0x16_EntityPCInit
entity_id = w[800af1f0];
sprite_data = w[800aeff0];
struct_5c_p = w[800aefe4];
struct_138 = w[800af54c];

A0 = 1;
read_two_bytes_with_80();
A0 = V0;
convert_magic_to_pc_id();
character_id = V0;

A0 = character_id;
get_party_slot_id();
party_slot_id = V0;

[struct_138 + e4] = h(character_id);



[struct_5c_p + V1 * 5c + 58] = h((hu[struct_5c_p + entity_id * 5c + 58] & f07f) | 0200);



// if character in party
if( party_slot_id != -1 )
{
    // if in 1st slot (leader)
    if( party_slot_id == 0 )
    {
        [800b1740] = w(entity_id);
        [800b1812] = h(entity_id);
        [struct_138 + 0] = w((w[struct_138 + 0] | 00004400) & ffffff7f); // set solid
    }

    [80059ad4 + party_slot_id * 4] = w(entity_id);

    T1 = w[800a173c];
    if( T1 != 0 )
    {
        A0 = entity_id;
        model_id = bu[800ad76c + character_id];
        A1 = model_id + T1;
        A2 = sprite_data + w[sprite_data + model_id * 4 + T1 * 4 + 4];
        A3 = 0; // local sprite
        A4 = 0;
        A5 = (model_id + T1) | 80;
        A6 = 1;
        func76150();

        [struct_138 + 0] = w((w[struct_138 + 0] | 00000400) & fffffcff);

        V1 = w[80059a38];
        if( bu[V1 + party_slot_id + 22b1] != 0 )
        {
            A0 = w[8006f020 + party_slot_id * 4];
            x = w[struct_5c_p + A0 * 5c + 4];
            y = w[struct_5c_p + entity_id * 5c + 4]
            [struct_5c_p + entity_id * 5c + 0] = w(x);
            [struct_5c_p + A0 * 5c + 4] = w(y);
            [struct_5c_p + A0 * 5c + 0] = w((w[struct_138 + 0] | 00000200) & fffffaff;
        }
    }
    else
    {
        A0 = entity_id;
        A1 = party_slot_id;
        A2 = w[80059aa4 + party_slot_id * 4];
        A3 = 1; // global sprite
        A4 = 0;
        A5 = A1;
        A6 = 1;
        func76150();

        [struct_138 + 0] = w((w[struct_138 + 0] | 00000400) & fffffcff);
    }

    [800af1f4] = h(ff40);

    [struct_5c_p + entity_id * 5c + 58] = h(hu[struct_5c_p + entity_id * 5c + 58] & ffdf);

    A0 = 2;
    get_bytes_from_800C2F3C();

    A0 = V0;
    func9efe4;

    funca0224;

    [struct_138 + 4] = w([struct_138 + 4] & fffff7ff);
}
else
{
    A0 = entity_id;
    A1 = 0;
    A2 = w[80059aa4];
    A3 = 1; // global sprite
    A4 = 0;
    A5 = 0;
    A6 = 1;
    func76150;

    [struct_138 + 0] = w(w[struct_138 + 0] | 00000001);
    [struct_138 + 4] = w(w[struct_138 + 4] | 00100000);

    [800af4c0] = w(party_slot_id);
    [800af594] = w(party_slot_id)
}

[struct_138 + 0] = w(w[struct_138 + 0] | 00020000);
[struct_138 + 4] = w(w[struct_138 + 4] | 00000400);
[struct_138 + cc] = h(hu[struct_138 + cc] + 3);
////////////////////////////////



////////////////////////////////
// 0xBC_EntityNoModelInit
// funca02cc
entity_id = w[800af1f0];
sprite_data = w[800aeff0];
struct_138 = w[800af54c];

A0 = entity_id;
A1 = 0;
A2 = sprite_data + w[sprite_data + 4];
A3 = 0; // local sprite
A4 = 0;
A5 = 80;
A6 = 1;
func76150();

funca0224();

[struct_138 + 0] = w(w[struct_138 + 0] | 00000100);
[struct_138 + 4] = w(w[struct_138 + 4] | 00000800);
[struct_138 + cc] = h(hu[struct_138 + cc] + 1);
////////////////////////////////



////////////////////////////////
// func76150()
entity_id = A0;
sprite_id = A1;
sprite_data = A2; // offset to data in 2dsprite block to load
S7 = A3; // maybe field or global sprite.
S6 = A4; // always 0
S0 = A5; // sprite id with 0x80 (sometimes)
FP = A6; // 0 or 1

struct_5c_p = w[800aefe4];
struct_138 = w[struct_5c_p + entity_id * 5c + 4c];



[GP + 1ac] = h(8);
[80059640 + 8 * 4] = w(0);
[GP + 1c0] = w(0);



[struct_138 + 126] = b(S0);
[struct_138 + 127] = b(sprite_id);
[struct_138 + 130] = w((w[struct_138 + 130] & cfffffff) | ((S7 & 3) << 1c));
[struct_138 + 134] = w((w[struct_138 + 134] & fffffff0) | (S6 & f));
[struct_138 + 134] = w((w[struct_138 + 134] & ffffffef) | ((FP & 1) << 4));



if( S7 == 0 )
{
    // from first 0x100 bytes of field file
    S5 = hu[800b144c + sprite_id * 8 + 0]; // tx
    S0 = hu[800b144c + sprite_id * 8 + 2]; // ty
    if( S6 == 0 )
    {
        if( hu[struct_5c_p + entity_id * 5c + 5a] & 0001 )
        {
            A0 = w[struct_5c_p + entity_id * 5c + 4];
            func22f24();
        }

        A0 = sprite_data;
        A1 = 100;      // clut x
        A2 = sprite_id + 1e0; // clut y
        A3 = S5;       // tx
        A4 = S0;       // ty
        A5 = 40;
        func24330(); // sprite set up
    }
    else
    {
        if( hu[struct_5c_p + entity_id * 5c + 5a] & 0001 )
        {
            A0 = w[struct_5c_p + entity_id * 5c + 4];
            func22f24();
        }

        A0 = sprite_data;
        A1 = 100 + S6 * 10;
        A2 = sprite_id + 1e0;
        A3 = S5;
        A4 = S0;
        A5 = 40;
        A6 = S6;
        80076384	jal    func240a0 [$800240a0]
    }

    S0 = V0;
    [struct_5c_p + entity_id * 5c + 4] = w(S0);
}
else
{
    if( hu[struct_5c_p + entity_id * 5c + 5a] & 0001 )
    {
        A0 = w[struct_5c_p + entity_id * 5c + 4];
        func22f24();
    }

    if( S7 == 1 )
    {
        S0 = sprite_id << 6 + 100;
        A0 = sprite_data;
        A1 = 100;
        A2 = sprite_id + e0;
        A3 = 280;
    }
    else
    {
        S0 = sprite_id << 6 + 100;
        A0 = sprite_data;
        A1 = 100;
        A2 = sprite_id + e3;
        A3 = 2a0;
    }

    A4 = S0;
    A5 = 8;
    func24330(); // sprite set up
    S0 = V0;

    [struct_5c_p + entity_id * 5c + 4] = w(S0);

    A0 = S0;
    A1 = 20;
    8007644C	jal    func231cc [$800231cc]
}

A0 = S0;
A1 = 0;
A2 = SP + 20;

S1 = entity_id * 5c;
V1 = struct_5c_p + S1;
80076480	lhu    v0, $005a(v1)
80076484	addiu  a3, sp, $0024
-80076488	ori    v0, v0, $0001
8007648C	sh     v0, $005a(v1)
80076490	addiu  v0, sp, $0028
80076494	jal    func1f434 [$8001f434]
80076498	sw     v0, $0010(sp)
8007649C	addu   a0, s0, zero
800764A0	jal    func21a48 [$80021a48]
800764A4	ori    a1, zero, $0003
800764A8	lui    v1, $8005
800764AC	lw     v1, $e9b0(v1)
800764B0	ori    v0, zero, $0c00
800764B4	sh     v0, $002c(s0)
800764B8	ori    v0, zero, $2000
800764BC	bne    v1, zero, L765a0 [$800765a0]
800764C0	sh     v0, $0082(s0)

[S0 + 0] = w(w[struct_138 + 20]);
[S0 + 4] = w(w[struct_138 + 24]);
[S0 + 8] = w(w[struct_138 + 28]);

V0 = struct_5c_p + S1;
80076540	lw     v1, $0024(v0)
80076544	lui    v0, $0001
80076548	sw     zero, $0010(s0)
8007654C	sw     zero, $000c(s0)
80076550	sw     zero, $0010(s0)
80076554	sw     zero, $0014(s0)
80076558	sw     v0, $001c(s0)
80076560	sh     v1, $0084(s0)
8007655C	bne    s7, zero, L76584 [$80076584]

[struct_138 + 1a] = h(w[SP + 24] << 1);
8007657C	j      L765a0 [$800765a0]

L76584:	; 80076584
[struct_138 + 1a] = h(0040);

L765a0:	; 800765A0
800765A0	lui    v0, $800b
800765A4	lh     v0, $1662(v0)
800765A8	nop
800765AC	beq    v0, zero, L765c4 [$800765c4]
800765B0	lui    v1, $0004
800765B4	lw     v0, $0040(s0)
800765B8	nop
800765BC	or     v0, v0, v1
800765C0	sw     v0, $0040(s0)

L765c4:	; 800765C4
A0 = S0;
A1 = 0;
800765C8	jal    func243e4 [$800243e4]

A0 = S0;
A1 = 0;
800765D4	jal    func21e40 [$80021e40]

A0 = 0;
A1 = 0;
800765E0	jal    func322bc [$800322bc]

A0 = S0;
800765EC	lw     v0, $007c(s0)
[V0 + 14] = h(entity_id);

A1 = 80076104;
800765F8	jal    func21a40 [$80021a40]

if( FP == 0 )
{
    A0 = S0;
    80076608	jal    func23090 [$80023090]

    80076610	jal    func1c7f0 [$8001c7f0]
    80076614	nop
    80076618	lw     v0, $007c(s0)
    8007661C	nop
    if( hu[V0 + c] == ff )
    {
        [struct_138 + ea] = h(00ff);
        [struct_138 + 4] = w(w[struct_138 + 4] | 01000000);
        [S0 + 0] = w(w[struct_138 + 20]);
        [S0 + 4] = w(w[struct_138 + 24]);
        [S0 + 8] = w(w[struct_138 + 28]);
    }
}

[struct_5c_p + entity_id * 5c + 20] = w(h[struct_138 + 22]); // x
[struct_5c_p + entity_id * 5c + 40] = w(h[struct_138 + 22]); // x

[struct_5c_p + entity_id * 5c + 24] = w(h[struct_138 + 26]); // y
[struct_5c_p + entity_id * 5c + 44] = w(h[struct_138 + 26]); // y

[struct_5c_p + entity_id * 5c + 28] = w(h[struct_138 + 2a]); // z
[struct_5c_p + entity_id * 5c + 48] = w(h[struct_138 + 2a]); // z

[S0 + 84] = h(w[struct_138 + 24]);

[S0 + 0] = w(w[struct_138 + 20]);
[S0 + 4] = w(w[struct_138 + 24]);
[S0 + 8] = w(w[struct_138 + 28]);

[800af148] = w(w[800af148] + 1);
////////////////////////////////



////////////////////////////////
// funca0224
current_entity_id = w[800af1f0];
struct_big = w[800af54c];
struct = w[800aefe4];
A2 = w[struct + current_entity_id * 5c + 4];

[struct + current_entity_id * 5c + 20] = w(h[struct_big + 22]);
[struct + current_entity_id * 5c + 24] = w(h[struct_big + 26]);
[struct + current_entity_id * 5c + 28] = w(h[struct_big + 2a]);
[struct + current_entity_id * 5c + 40] = w(h[struct_big + 22]);
[struct + current_entity_id * 5c + 44] = w(h[struct_big + 26]);
[struct + current_entity_id * 5c + 48] = w(h[struct_big + 2a]);

[A2 + 0] = w(w[struct_big + 20]);
[A2 + 4] = w(w[struct_big + 24]);
[A2 + 8] = w(w[struct_big + 28]);
[A2 + 10] = w(0);
[A2 + 84] = h(hu[struct_big + 26]);
[struct_big + 72] = h(hu[struct_big + 26])
////////////////////////////////



////////////////////////////////
// func9efe4
// FF   0000000000FF00
// FF   6600000000FFFF   DBFF000000FFFF
slot = A0;

field_script = w[800ad0d8];
S2 = bu[field_script + 0];
if (S2 == ff)
{
    entity_data = w[800af54c];
    [entity_data + 10] = h(bu[field_script + 1 + slot * 7 + 4]);

    A1 = 1 + slot * 7 + 0;
    func9d8c0;
    S0 = V0;

    A0 = 1 + slot * 7 + 2;
    func9d8c0;

    A0 = S0;
    A1 = V0;
    set_position_by_x_z;

    V0 = bu[field_script + 1 + slot * 7 + 5];
    if (V0 == ff)
    {
        A0 = 8;
        get_bytes_from_800C2F3C;
    }

    V0 = V1 + 4;
    V0 = V0 & 7;
    A1 = V0 << 9;
    [800aeeba] = h(A1);
    [800aeee0] = w((A1 << 10) >> 10);
    [800aeec4] = w((A1 << 10) >> 10);

    V0 = bu[field_script + 1 + slot * 7 + 6];
    if (V0 == ff)
    {
        A0 = 6;
        get_bytes_from_800C2F3C;
    }

    V0 = V0 - 2;
    V0 = V0 & 7;
    V0 = V0 << 9;

    [entity_data + 104] = h(V0 | 8000);
    [entity_data + 106] = h(V0 | 8000);
    [entity_data + 108] = h(V0 | 8000);
}

return 0;
////////////////////////////////



////////////////////////////////
// func9d8c0
V0 = w[800ad0d8];
return ((bu[V0 + A0 + 0] + (bu[V0 + A0 + 1] << 8)) << 10) >> 10;
////////////////////////////////
