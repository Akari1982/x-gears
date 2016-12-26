Entity = {}



Entity[ "0" ] = {
    on_start = function( self )
        -- 0xBC_EntityNoModelInit(); -- 0x000f 0xbc
        -- 0x2A(); -- 0x0010 0x2a
        -- MISSING OPCODE 0xa0
    end,

    on_update = function( self )
        -- 0x02_ConditionalJumpTo( value1=GetVar( 0x02c8 ), value2=(s16)0x0002, condition="value1 & value2", jump_if_false=0x0038 ); -- 0x0019 0x02
        -- MISSING OPCODE 0xFE54
    end,

    on_talk = function( self )
        return; -- 0x0039 0x00
    end,

    on_push = function( self )
        return; -- 0x0039 0x00
    end,

    script_0x04 = function( self )
        -- 0x26_Wait( time=0x0014 ); -- 0x003a 0x26
        -- MISSING OPCODE 0xc7
    end,

    script_0x05 = function( self )
        -- 0x26_Wait( time=0x000a ); -- 0x004d 0x26
        -- MISSING OPCODE 0xb5
    end,

}



Entity[ "1" ] = {
    on_start = function( self )
        entity:init_pc( 0x0000 ); -- 0x0056 0x16
        -- 0xFE0D_SetAvatar( character_id=0x0000 ); -- 0x0059 0xfe
        return; -- 0x005d 0x00
    end,

    on_update = function( self )
        -- 0x0C_Encounter(); -- 0x005e 0x0c
        return; -- 0x005f 0x00
    end,

    on_talk = function( self )
        return; -- 0x0060 0x00
    end,

    on_push = function( self )
        return; -- 0x0060 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0x4a
    end,

    script_0x05 = function( self )
        -- MISSING OPCODE 0xd0
    end,

    script_0x06 = function( self )
        -- MISSING OPCODE 0x20
    end,

    script_0x07 = function( self )
        -- MISSING OPCODE 0xd0
    end,

    script_0x08 = function( self )
        -- MISSING OPCODE 0xd2
    end,

    script_0x09 = function( self )
        -- MISSING OPCODE 0x5d
    end,

    script_0x0a = function( self )
        -- 0x26_Wait( time=0x000a ); -- 0x00e6 0x26
        -- MISSING OPCODE 0xf6
    end,

    script_0x0b = function( self )
        -- MISSING OPCODE 0x5d
    end,

    script_0x0c = function( self )
        -- MISSING OPCODE 0x2c
    end,

    script_0x0d = function( self )
        -- MISSING OPCODE 0x2c
    end,

    script_0x0e = function( self )
        -- 0x26_Wait( time=0x0050 ); -- 0x011b 0x26
        -- MISSING OPCODE 0xb4
    end,

}



Entity[ "2" ] = {
    on_start = function( self )
        entity:init_pc( 0x0002 ); -- 0x0127 0x16
        -- 0xFE0D_SetAvatar( character_id=0x0002 ); -- 0x012a 0xfe
        return; -- 0x012e 0x00
    end,

    on_update = function( self )
        -- 0x0C_Encounter(); -- 0x012f 0x0c
        return; -- 0x0130 0x00
    end,

    on_talk = function( self )
        return; -- 0x0131 0x00
    end,

    on_push = function( self )
        return; -- 0x0131 0x00
    end,

}



Entity[ "3" ] = {
    on_start = function( self )
        entity:init_pc( 0x0001 ); -- 0x0132 0x16
        -- 0xFE0D_SetAvatar( character_id=0x0001 ); -- 0x0135 0xfe
        return; -- 0x0139 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa7
    end,

    on_talk = function( self )
        return; -- 0x013c 0x00
    end,

    on_push = function( self )
        return; -- 0x013c 0x00
    end,

}



Entity[ "4" ] = {
    on_start = function( self )
        entity:init_pc( 0x0003 ); -- 0x013d 0x16
        -- 0xFE0D_SetAvatar( character_id=0x0003 ); -- 0x0140 0xfe
        return; -- 0x0144 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa7
    end,

    on_talk = function( self )
        return; -- 0x0147 0x00
    end,

    on_push = function( self )
        return; -- 0x0147 0x00
    end,

}



Entity[ "5" ] = {
    on_start = function( self )
        entity:init_pc( 0x0005 ); -- 0x0148 0x16
        -- 0xFE0D_SetAvatar( character_id=0x0005 ); -- 0x014b 0xfe
        return; -- 0x014f 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa7
    end,

    on_talk = function( self )
        return; -- 0x0152 0x00
    end,

    on_push = function( self )
        return; -- 0x0152 0x00
    end,

}



Entity[ "6" ] = {
    on_start = function( self )
        entity:init_pc( 0x0006 ); -- 0x0153 0x16
        -- 0xFE0D_SetAvatar( character_id=0x0006 ); -- 0x0156 0xfe
        return; -- 0x015a 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa7
    end,

    on_talk = function( self )
        return; -- 0x015d 0x00
    end,

    on_push = function( self )
        return; -- 0x015d 0x00
    end,

}



Entity[ "7" ] = {
    on_start = function( self )
        entity:init_pc( 0x0007 ); -- 0x015e 0x16
        -- 0xFE0D_SetAvatar( character_id=0x0007 ); -- 0x0161 0xfe
        return; -- 0x0165 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa7
    end,

    on_talk = function( self )
        return; -- 0x0168 0x00
    end,

    on_push = function( self )
        return; -- 0x0168 0x00
    end,

}



Entity[ "8" ] = {
    on_start = function( self )
        entity:init_pc( 0x0008 ); -- 0x0169 0x16
        -- 0xFE0D_SetAvatar( character_id=0x0008 ); -- 0x016c 0xfe
        return; -- 0x0170 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa7
    end,

    on_talk = function( self )
        return; -- 0x0173 0x00
    end,

    on_push = function( self )
        return; -- 0x0173 0x00
    end,

}



Entity[ "9" ] = {
    on_start = function( self )
        -- 0x0B_EntityNPCSpriteInit( sprite_id=0x0006 ); -- 0x0174 0x0b
        -- MISSING OPCODE 0x20
    end,

    on_update = function( self )
        return; -- 0x0188 0x00
    end,

    on_talk = function( self )
        -- 0x02_ConditionalJumpTo( value1=GetVar( 0x0402 ), value2=(s16)0x0000, condition="value1 == value2", jump_if_false=0x0194 ); -- 0x0189 0x02
        -- 0x01_JumpTo( 0x0195 ); -- 0x0191 0x01
        return; -- 0x0194 0x00
        -- MISSING OPCODE 0x6f
    end,

    on_push = function( self )
        return; -- 0x0278 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0x6f
    end,

    script_0x05 = function( self )
        -- MISSING OPCODE 0x6f
    end,

    script_0x06 = function( self )
        -- MISSING OPCODE 0xf4
    end,

}



Entity[ "10" ] = {
    on_start = function( self )
        -- 0x2A(); -- 0x0296 0x2a
        -- 0x84_ProgressLessEqualJumpTo( value=0x0007, jump=0x029f ); -- 0x0297 0x84
        -- 0x01_JumpTo( 0x02a1 ); -- 0x029c 0x01
        -- MISSING OPCODE 0x29
    end,

    on_update = function( self )
        -- 0xCB_TriggerJumpTo( trigger_id=0x5c01, jump=0xfe02 ); -- 0x02a2 0xcb
        -- MISSING OPCODE 0x54
    end,

    on_talk = function( self )
        return; -- 0x02dd 0x00
    end,

    on_push = function( self )
        return; -- 0x02dd 0x00
    end,

}



Entity[ "11" ] = {
    on_start = function( self )
        -- 0x0B_EntityNPCSpriteInit( sprite_id=0x0002 ); -- 0x02de 0x0b
        -- 0x19_SetPosition( x=(vf80)0x010c, z=(vf40)0x0000, flag=(flag)0x69 ) -- 0x02e1 0x19
        -- MISSING OPCODE 0x69
    end,

    on_update = function( self )
        return; -- 0x0302 0x00
    end,

    on_talk = function( self )
        return; -- 0x0303 0x00
    end,

    on_push = function( self )
        return; -- 0x0303 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0x22
    end,

    script_0x05 = function( self )
        -- MISSING OPCODE 0x2c
    end,

    script_0x06 = function( self )
        -- MISSING OPCODE 0xd2
    end,

}



Entity[ "12" ] = {
    on_start = function( self )
        -- 0x0B_EntityNPCSpriteInit( sprite_id=0x0004 ); -- 0x03aa 0x0b
        -- MISSING OPCODE 0x20
    end,

    on_update = function( self )
        return; -- 0x03b8 0x00
    end,

    on_talk = function( self )
        -- MISSING OPCODE 0x36
    end,

    on_push = function( self )
        return; -- 0x0411 0x00
    end,

    script_0x04 = function( self )
        -- 0x26_Wait( time=0x0014 ); -- 0x0412 0x26
        -- MISSING OPCODE 0xa4
    end,

    script_0x05 = function( self )
        -- MISSING OPCODE 0xa4
    end,

    script_0x06 = function( self )
        -- 0x02_ConditionalJumpTo( value1=GetVar( 0x0008 ), value2=(s16)0x0006, condition="value1 == value2", jump_if_false=0x042f ); -- 0x041f 0x02
        -- MISSING OPCODE 0xb5
    end,

    script_0x07 = function( self )
        -- MISSING OPCODE 0xf4
    end,

}



Entity[ "13" ] = {
    on_start = function( self )
        -- 0x0B_EntityNPCSpriteInit( sprite_id=0x0000 ); -- 0x045c 0x0b
        -- MISSING OPCODE 0x20
    end,

    on_update = function( self )
        -- 0x26_Wait( time=0x000a ); -- 0x0466 0x26
        return; -- 0x0469 0x00
    end,

    on_talk = function( self )
        -- 0x02_ConditionalJumpTo( value1=GetVar( 0x0402 ), value2=(s16)0x0000, condition="value1 == value2", jump_if_false=0x0475 ); -- 0x046a 0x02
        -- 0x01_JumpTo( 0x0476 ); -- 0x0472 0x01
        return; -- 0x0475 0x00
        -- MISSING OPCODE 0x6f
    end,

    on_push = function( self )
        return; -- 0x0484 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0xf4
    end,

}



Entity[ "14" ] = {
    on_start = function( self )
        -- 0x0B_EntityNPCSpriteInit( sprite_id=0x0001 ); -- 0x048c 0x0b
        -- MISSING OPCODE 0x20
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xFE45
    end,

    on_talk = function( self )
        -- 0x02_ConditionalJumpTo( value1=GetVar( 0x0402 ), value2=(s16)0x0000, condition="value1 == value2", jump_if_false=0x04a6 ); -- 0x049b 0x02
        -- 0x01_JumpTo( 0x04a7 ); -- 0x04a3 0x01
        return; -- 0x04a6 0x00
        -- MISSING OPCODE 0xFE45
    end,

    on_push = function( self )
        return; -- 0x04bd 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0xf4
    end,

}



Entity[ "15" ] = {
    on_start = function( self )
        -- 0x0B_EntityNPCSpriteInit( sprite_id=0x0003 ); -- 0x04c5 0x0b
        return; -- 0x04c8 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa8
    end,

    on_talk = function( self )
        -- 0x02_ConditionalJumpTo( value1=GetVar( 0x0402 ), value2=(s16)0x0000, condition="value1 == value2", jump_if_false=0x0542 ); -- 0x0537 0x02
        -- 0x01_JumpTo( 0x0543 ); -- 0x053f 0x01
        return; -- 0x0542 0x00
        -- MISSING OPCODE 0x6f
    end,

    on_push = function( self )
        return; -- 0x0554 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0xf4
    end,

}



Entity[ "16" ] = {
    on_start = function( self )
        -- 0x2A(); -- 0x0559 0x2a
        return; -- 0x055a 0x00
    end,

    on_update = function( self )
        -- 0xCB_TriggerJumpTo( trigger_id=GetVar( 0x6400 ), jump=0x9805 ); -- 0x055b 0xcb
        -- MISSING OPCODE 0x0e
    end,

    on_talk = function( self )
        return; -- 0x0565 0x00
    end,

    on_push = function( self )
        return; -- 0x0565 0x00
    end,

}



Entity[ "17" ] = {
    on_start = function( self )
        -- MISSING OPCODE 0x46
    end,

    on_update = function( self )
        return; -- 0x0568 0x00
    end,

    on_talk = function( self )
        -- MISSING OPCODE 0x15
    end,

    on_push = function( self )
        return; -- 0x0574 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0xc4
    end,

    script_0x05 = function( self )
        -- MISSING OPCODE 0xc5
    end,

}



Entity[ "18" ] = {
    on_start = function( self )
        -- 0xBC_EntityNoModelInit(); -- 0x057b 0xbc
        -- 0x2A(); -- 0x057c 0x2a
        return; -- 0x057d 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xe1
    end,

    on_talk = function( self )
        return; -- 0x05b2 0x00
    end,

    on_push = function( self )
        return; -- 0x05b2 0x00
    end,

}



Entity[ "19" ] = {
    on_start = function( self )
        -- 0xBC_EntityNoModelInit(); -- 0x05b3 0xbc
        -- MISSING OPCODE 0x1d
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xFE13
    end,

    on_talk = function( self )
        return; -- 0x05c5 0x00
        -- MISSING OPCODE 0xe0
    end,

    on_push = function( self )
        return; -- 0x05c5 0x00
        -- MISSING OPCODE 0xe0
    end,

}



