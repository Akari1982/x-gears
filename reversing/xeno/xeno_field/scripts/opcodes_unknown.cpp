//////////////////////////////////////////////////////////
// 0x23()
V1 = w[800af1f0];
V1 = w[800aefe4] + V1 * 5c;
[V1 + 58] = h(hu[V1 + 58] | 0020);

A0 = w[800af54c];
[A0 + cc] = h(hu[A0 + cc] + 1);
//////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x2A
A0 = w[800af54c];
[A0 + 0] = w(w[A0 + 0] | 00000002);

[A0 + cc] = h([A0 + cc] + 1);
////////////////////////////////////////////////////////



////////////////////////////////
// 0xF6
data_138 = w[800af54c];
V0 = hu[data_138 + cc];
V1 = w[800ad0d8];
V1 = bu[V1 + V0];

if( V1 == 0 )
{
    if( w[data_138 + 0] & 00008000 )
    {
        [data_138 + 0] = w(w[data_138 + 0] & ffff7fff);
    }

    if( w[data_138 + 4] & 00080000 )
    {
        current_entity_id = w[800af1f0];
        V1 = w[800aefe4];
        V0 = w[V1 + current_entity_id * 5c + 4];
        [V0 + c] = w(0); // animaton move x
        [V0 + 14] = w(0); // animation move z
        [V0 + 18] = w(0); // move speed

        [data_138 + 4] = w(w[data_138 + 4] & fff7ffff);
    }
}
else if( V1 == 1 )
{
    [data_138 + 0] = w(w[data_138 + 0] | 00008000);
    [data_138 + 11c] = h(hu[data_138 + 106]);
}
else if( V1 == 2 )
{
    [data_138 + 4] = w(w[data_138 + 4] | 00080000);
}

[data_138 + cc] = h(hu[data_138 + cc] + 2);
////////////////////////////////
