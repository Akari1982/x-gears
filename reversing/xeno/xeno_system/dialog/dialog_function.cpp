////////////////////////////////
// func32d78()
offset_18 = A0;
u_tex = A1;
v_tex = A2;
x_pos = A3;
y_pos = A4;
dialog_width = A5 | 1;
dialog_rows = A6;

[offset_18 + 4] = h(x_pos);
[offset_18 + 6] = h(y_pos);
[offset_18 + 8] = h(dialog_width * 4)
[offset_18 + a] = h(dialog_width);
[offset_18 + c] = h(dialog_rows);
[offset_18 + e] = h(v_tex);
[offset_18 + 10] = h(0); // flags
[offset_18 + 12] = h(dialog_width + 3);
[offset_18 + 14] = h(e); // row height

[offset_18 + 68] = b(1); // default text speed
[offset_18 + 69] = b(1); // current text speed
[offset_18 + 6a] = b(0); // stored text speed
[offset_18 + 6b] = b(0); // state
[offset_18 + 6c] = b(0);
[offset_18 + 6d] = b(0);
[offset_18 + 6e] = b(ff);

[offset_18 + 82] = h(0);
[offset_18 + 84] = h(0); // text delay
[offset_18 + 8c] = w(0);



[GP + 1a8] = h(29);
A0 = h[offset_18 + c] * 60;
A1 = 2;
system_memory_allocate();
[offset_18 + 28] = w(V0);



[GP + 1a8] = h(28);
A0 = h[offset_18 + 12] * 1c;
A1 = 2;
system_memory_allocate();
[offset_18 + 2c] = w(V0);



// prepare packet for rectangle
[offset_18 + 4b] = b(03);
[offset_18 + 4c] = w(60000000); // rectangle with black colour
// rectangle is bigger than window
[offset_18 + 50] = w(((h[offset_18 + 6] - 5) << 10) | (h[offset_18 + 4] - 7));
[offset_18 + 54] = w((((h[offset_18 + c] * h[offset_18 + 14]) + a) << 10) | ((h[offset_18 + a] * 4) + d))

A0 = offset_18 + 48; // packet start
A1 = 1; // enable transparency
system_set_draw_packet_transparency(); 

// copy packet from 1st buffer to 2nd
[offset_18 + 58] = w(w[offset_18 + 48]);
[offset_18 + 5c] = w(w[offset_18 + 4c]);
[offset_18 + 60] = w(w[offset_18 + 50]);
[offset_18 + 64] = w(w[offset_18 + 54]);



if( h[offset_18 + c] > 0 ) // dialog rows
{
    T1 = 0;
    L32f10:	; 80032F10
        A0 = w[offset_18 + 28];

        // header
        [A0 + T1 * 60 + 3] = b(04);
        [A0 + T1 * 60 + 7] = b(65);
        [A0 + T1 * 60 + 17] = b(04);
        [A0 + T1 * 60 + 1b] = b(65);

        // sprite x and y
        [A0 + T1 * 60 + 8] = w(((h[offset_18 + 6] + (h[offset_18 + 14] * T1)) << 10) | h[offset_18 + 4]);
        [A0 + T1 * 60 + 1c] = w(((h[offset_18 + 6] + (h[offset_18 + 14] * T1)) << 10) | (h[offset_18 + 4] + 100));

        // sprite height and width
        if( h[offset_18 + 8] >= 101 )
        {
            [A0 + T1 * 60 + 10] = w(000d0100);
        }
        else
        {
            [A0 + T1 * 60 + 10] = w(000d0000 | h[offset_18 + 8]);
        }
        if( h[offset_18 + 8] >= 101 )
        {
            [A0 + T1 * 60 + 24] = w(000d0000 | (h[offset_18 + 8] - f0));
        }
        else
        {
            [A0 + T1 * 60 + 24] = w(000d0000);
        }

        // sprite uv
        [A0 + T1 * 60 + c] = h((((v_tex + (T1 / 2) * d) & ff) << 8) | ((u_tex & 3f) * 4));
        [A0 + T1 * 60 + 20] = h((((v_tex + (T1 / 2) * d) & ff) << 8) | ((u_tex & 3f) * 4));

        // copy data for second buffer
        [A0 + T1 * 60 + 28] = w([A0 + T1 * 60 + 0]);
        [A0 + T1 * 60 + 2c] = w([A0 + T1 * 60 + 4]);
        [A0 + T1 * 60 + 30] = w([A0 + T1 * 60 + 8]);
        [A0 + T1 * 60 + 34] = w([A0 + T1 * 60 + c]);
        [A0 + T1 * 60 + 38] = w([A0 + T1 * 60 + 10]);
        [A0 + T1 * 60 + 3c] = w([A0 + T1 * 60 + 14]);
        [A0 + T1 * 60 + 40] = w([A0 + T1 * 60 + 18]);
        [A0 + T1 * 60 + 44] = w([A0 + T1 * 60 + 1c]);
        [A0 + T1 * 60 + 48] = w([A0 + T1 * 60 + 20]);
        [A0 + T1 * 60 + 4c] = w([A0 + T1 * 60 + 24]);

        // default values
        [A0 + T1 * 60 + 50] = h(u_tex);
        [A0 + T1 * 60 + 52] = h(v_tex + (T1 / 2) * d);
        [A0 + T1 * 60 + 54] = h(hu[offset_18 + 12]);
        [A0 + T1 * 60 + 56] = h(000d);
        [A0 + T1 * 60 + 58] = h(0000);
        [A0 + T1 * 60 + 5a] = b(T1 & 1);
        [A0 + T1 * 60 + 5b] = b(T1);
        [A0 + T1 * 60 + 5c] = b(v_tex + (T1 / 2) * d);
        if( T1 & 1 )
        {
            [A0 + T1 * 60 + 5e] = h(hu[80058ab0]);
        }
        else
        {
            [A0 + T1 * 60 + 5e] = h(hu[80058c70]);
        }

        T1 = T1 + 1;
        V0 = T1 < h[offset_18 + c];
    800331C0	bne    v0, zero, L32f10 [$80032f10]
}



A0 = 0;
A1 = 0;
A2 = u_tex;
A3 = v_tex;
func43894(); // pack texpage

A0 = offset_18 + 30;
A1 = 0;
A2 = 0;
A3 = V0 & ffff;
A4 = 0;
func45354();

A0 = 0;
A1 = 0;
A2 = u_tex + 40;
A3 = v_tex;
func43894(); // pack texpage

A0 = offset_18 + 3c;
A1 = 0;
A2 = 0;
A3 = V0 & ffff;
A4 = 0;
func45354();
////////////////////////////////



////////////////////////////////
// func45354()
S0 = A0;
S1 = A4;

[S0 + 3] = b(02);

A0 = A1;
A1 = A2;
A2 = A3 & ffff; // tex page
func45854(); // set md me dtd dfe
[S0 + 4] = w(V0); // draw mode settings commend to GPU (e1)

A0 = S1;
func45a88();
[S0 + 8] = w(V0); // texture window setting (e2)
////////////////////////////////



////////////////////////////////
// func45854()
V1 = e1000000; // draw mode settings
if( ( bu[80055f70] - 1 ) < 2 )
{
    if( A1 != 0 )
    {
        V1 = V1 | 0800; // add md (Apply mask bit to drawn pixels)
    }
    V0 = A2 & 27ff; // remove md and me (Do not apply mask bit to drawn pixels and Draw over pixel with mask set)
    if( A0 != 0 )
    {
        V0 = V0 | 1000; // add me (No drawing to pixels with set mask bit.)
    }
}
else
{
    if( A1 != 0 )
    {
        V1 = V1 | 0200; // add dtd (Dither on)
    }
    V0 = A2 & 09ff; // remove dtd and dfe (Draw to display area prohibited and Dither off)
    if( A0 != 0 )
    {
        V0 = V0 | 0400; // add dfe (Draw to display area allowed)
    }
}
return V1 | V0;
////////////////////////////////



////////////////////////////////
// func45a88()
if( A0 == 0 )
{
    return 0;
}

twy = bu[A0 + 0] >> 3;
[SP + 0] = w(twy);
twx = bu[A0 + 2] >> 3;
[SP + 4] = w(twx);
twh = ((0 - h[A0 + 4]) & ff) >> 3;
[SP + 8] = w(twh);
tww = ((0 - h[A0 + 6]) & ff) >> 3;
[SP + c] = w(tww);

return e2000000 | (twx << f) | (twy << a) | (tww << 5) | twh; // texture window setting
////////////////////////////////



////////////////////////////////
// func3354c()
return A0 + hu[A0 + A1 * 2 + 4];
////////////////////////////////



////////////////////////////////
// func34404()
offset_18 = A0;

V0 = hu[offset_18 + 10];
[offset_18 + 10] = h(V0 & fff7);
if( V0 & 0200 )
{
    [offset_18 + 84] = h(0); // delay time
    [offset_18 + 6c] = b(0);
    [offset_18 + 10] = h(hu[offset_18 + 10] & fdff);
}
////////////////////////////////



////////////////////////////////
// func34538()
offset_18 = A0;
text_data = A1;

[offset_18 + 82] = h(hu[offset_18 + 82] + 1);

[GP + 1a8] = h(2a);
A0 = 8;
A1 = 2;
system_memory_allocate();
V1 = V0;

[V1 + 0] = w(0);
[V1 + 4] = w(text_data);

S1 = w[offset_18 + 8c];
if( S1 == 0 )
{
    [offset_18 + 8c] = w(V1);
}
else
{
    loop34594:	; 80034594
        V0 = w[S1 + 0];
        if( V0 == 0 )
        {
            break;
        }
        S1 = w[S1 + 0];
    800345A4	bne    v0, zero, loop34594 [$80034594]

    [S1 + 0] = w(V1);
}
return h[offset_18 + 82];
////////////////////////////////
