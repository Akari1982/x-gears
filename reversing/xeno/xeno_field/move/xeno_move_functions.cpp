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
S2 = A0;
rotation = A1;
struct_5c = S3 = A2;

struct_138 = w[struct_5c + 4c];

if( rotation & 8000 )
{
    [S2 + c] = w(0);
    [S2 + 14] = w(0);
    return;
}

if( ( hu[struct_5c + 58] & 0040 ) == 0 ) // this is model
{
    S1 = ((40000 / hu[struct_138 + 76]) >> 8) << 5;

    A0 = rotation & 0fff;
    system_cos();
    [S2 + c] = w(((V0 * S1) >> c) * h[struct_138 + f4]);
    [S2 + c] = w(w[S2 + c] & fffff000);

    A0 = rotation & 0fff;
    system_sin();
    [S2 + 14] = w(((0 - (V0 * S1)) >> c) * h[struct_138 + f8]);
    [S2 + 14] = w(w[S2 + 14] & fffff000);
}
else if( ( w[struct_138 + 4] & 00002000 ) == 0 )
{
    if( ( w[struct_138 + 4] & 00080000 ) == 0 )
    {
        A0 = S2;
        A1 = rotation;
        80081640	jal    func21e40 [$80021e40]

        [S2 + c] = w(w[S2 + c] & fffff000);
        [S2 + 14] = w(w[S2 + 14] & fffff000);
    }
    else
    {
        S1 = ((40000 / hu[struct_138 + 76]) >> 8) << 5;

        A0 = rotation & 0fff;
        system_cos();
        [S2 + c] = w(((V0 * S1) >> c) * h[struct_138 + f4]);
        [S2 + c] = w(w[S2 + c] & fffff000);

        A0 = rotation & 0fff;
        system_sin();
        [S2 + 14] = w(((0 - (V0 * S1)) >> c) * h[struct_138 + f8]);
        [S2 + 14] = w(w[S2 + 14] & fffff000);

        [S2 + 18] = w(4000000 / hu[struct_138 + 76]);
    }
}
else if( ( w[struct_138 + 4] & 00020000 ) == 0 )
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
}
else
{
    V0 = w[801e8670 + ((w[struct_138 + 12c] >> b) & 1c)]; // 0x0000e000 flags
    [S2 + c] = w((0 - w[V0 + 128]) << 10);
    [S2 + c] = w(w[S2 + c] & fffff000);
    [S2 + 14] = w((0 - w[V0 + 130]) << 10);
    [S2 + 14] = w(w[S2 + 14] & fffff000);
}
////////////////////////////////



////////////////////////////////
// func81aa8()
move_vector = A0;
struct_138 = A1;

if( ( w[struct_138 + 12c] & 00001000 ) == 0 )
{
    return 0;
}

new_point = (((w[struct_138 + 20] + w[move_vector + 0]) >> 10) << 10) + ((w[struct_138 + 28] + w[move_vector + 8]) >> 10);

V1 = w[struct_138 + 114];
p1 = (h[V1 + 0] << 10) + h[V1 + 2];
p2 = (h[V1 + 4] << 10) + h[V1 + 6];
p3 = (h[V1 + 8] << 10) + h[V1 + a];
p4 = (h[V1 + c] << 10) + h[V1 + e];

A0 = p1;
A1 = p2;
A2 = new_point;
system_side_of_vector();
if( V0 >= 0 )
{
    A0 = p2;
    A1 = p3;
    A2 = new_point;
    system_side_of_vector();
    if( V0 >= 0 )
    {
        A0 = p3;
        A1 = p4;
        A2 = new_point;
        system_side_of_vector();
        if( V0 >= 0 )
        {
            A0 = p4;
            A1 = p1;
            A2 = new_point;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                return 0;
            }
        }
    }
}
return -1;
////////////////////////////////



////////////////////////////////
// field_check_walkmesh_triangle_and_calculate_height()
// return -1 if we can't move, 0 otherwise.

move_vector = A0;
current_pos = A1;
struct_138 = A2;
intersect_line = A3;
final_pos = A4;
flag = A5; // if -1 then we don't need to really calculate height of final point. If 00000080 then we can go only down. Simulate material 00400000.
material_ret = A6;

walkmesh_id = h[struct_138 + 10];
triangle_id = h[struct_138 + 08 + walkmesh_id * 2];

walkmesh_vertex_data = w[800af008 + walkmesh_id * 4];
walkmesh_triangle_data = w[800aeff8 + walkmesh_id * 4];
walkmesh_material_data = w[800aeff4];

if( triangle_id != -1 )
{
    start_x = w[current_pos + 0];
    start_y = w[current_pos + 4];
    start_z = w[current_pos + 8];
    end_x = (start_x + w[move_vector + 0]) >> 10;
    end_z = (start_z + w[move_vector + 8]) >> 10;
    start_x_z = ((start_x >> 10) << 10) + (start_z >> 10);
    ending_point_x_z = (end_x << 10) + end_z;

    [final_pos + 0] = h(end_x);
    [final_pos + 2] = h(0);
    [final_pos + 4] = h(end_z);

    if( ( ( w[struct_138 + 4] >> ( walkmesh_id + 3 ) ) & 1 ) == 0 && bu[800b16a0] == 0 )
    {
        material_mask = ffffffff;
    }
    else
    {
        material_mask = 00000000;
    }

    material_id = bu[walkmesh_triangle_data + triangle_id * e + c];
    material = w[walkmesh_material_data + material_id * 4];

    if( ( material & material_mask & 00400000 ) || ( flag == 00000080 ) )
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
        S2 = 0;

        V0 = h[walkmesh_triangle_data + triangle_id * e + 00];
        a_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

        V0 = h[walkmesh_triangle_data + triangle_id * e + 02];
        b_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

        V0 = h[walkmesh_triangle_data + triangle_id * e + 04];
        c_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

        A0 = a_x_z;
        A1 = b_x_z;
        A2 = ending_point_x_z;
        system_side_of_vector();
        if( V0 < 0 )
        {
            S2 = S2 | 1;
        }

        A0 = b_x_z;
        A1 = c_x_z;
        A2 = ending_point_x_z;
        system_side_of_vector();
        if( V0 < 0 )
        {
            S2 = S2 | 2;
        }

        A0 = c_x_z;
        A1 = a_x_z;
        A2 = ending_point_x_z;
        system_side_of_vector();
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
                system_side_of_vector();
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
                system_side_of_vector();
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
                system_side_of_vector();
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

        [material_ret] = w(material & material_mask);
        type_of_unpassability = (w[material_ret] >> 5)

        type_of_entity = ((w[struct_138 + 0] & 00000700) >> 8);

        if( ( type_of_entity & type_of_unpassability ) || ( ( w[material_ret] & 10000000 ) && ( walkmesh_id == 0 ) ) )
        {
            triangle_id = -1;
        }
        else if( ( w[material_ret] & 00400000 ) && material_go_only_down == 0 ) // we check both triangles start and end.
        {
            A0 = h[walkmesh_triangle_data + triangle_id * e + 0];
            A1 = h[walkmesh_triangle_data + triangle_id * e + 2];
            A2 = h[walkmesh_triangle_data + triangle_id * e + 4];

            A0 = walkmesh_vertex_data + A0 * 8;
            A1 = walkmesh_vertex_data + A1 * 8;
            A2 = walkmesh_vertex_data + A2 * 8;
            A3 = final_pos;
            A4 = SP + 18; // address to store normal
            field_calculate_walkmesh_height();

            new_y = h[final_pos + 2];

            if( new_y < ( start_y >> 10 ) ) // Y is less on top
            {
                triangle_id = -1;
            }
        }

        if( triangle_id == -1 )
        {
            break;
        }

        triangle_check_count = triangle_check_count + 1;
        V0 = triangle_check_count < 20;
    8007B970	bne    v0, zero, L7b68c [$8007b68c]



    if( triangle_id != -1 && triangle_check_count != 20 )
    {
        if( flag != -1 )
        {
            A0 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 0] * 8;
            A1 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 2] * 8;
            A2 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 4] * 8;
            A3 = final_pos;
            A4 = SP + 18; // address to store normal
            field_calculate_walkmesh_height();
        }
        return 0;
    }



    if( S2 == 1 )
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
    else if( S2 == 2 )
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
    else if( S2 == 4 )
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
// field_calculate_walkmesh_height()
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
system_normalize_word_vector_T0_T1_T2_to_word();

[SP + 30] = w(h[C_vec + 0] - h[A_vec + 0]);
[SP + 34] = w(h[C_vec + 2] - h[A_vec + 2]);
[SP + 38] = w(h[C_vec + 4] - h[A_vec + 4]);
A0 = SP + 30;
A1 = SP + 20;
system_normalize_word_vector_T0_T1_T2_to_word();

A0 = SP + 10;
A1 = SP + 20;
A2 = S4; // normal
system_outer_product2_A0_A1_to_A2();

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
// field_get_move_vector_to_move_along_with_line()
rotation = A0;
intersect_line = A1;
move_vector = A2;

S1 = (c00 - rotation) & fff;

A0 = h[intersect_line + c] - h[intersect_line + 4];
A1 = h[intersect_line + 8] - h[intersect_line + 0];
system_get_rotation_based_on_vector_x_y();

A0 = (0 - V0) & fff; // rotation along line that we can't intersect 
S1 = (S1 + A0) & fff;

if( ( S1 - 80 ) >= f01)
{
    [move_vector + 0] = w(0);
    [move_vector + 4] = w(0);
    [move_vector + 8] = w(0);
    return A0;
}
else
{
    if( S1 < 800 )
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
    system_normalize_word_vector_T0_T1_T2_to_word();

    A0 = w[move_vector + 0] >> c;
    A1 = w[move_vector + 8] >> c;
    length_of_vector_by_x_y();

    [move_vector + 0] = w(w[SP + 20] * V0);
    [move_vector + 4] = w(0);
    [move_vector + 8] = w(w[SP + 28] * V0);

    return S3;
}
////////////////////////////////
