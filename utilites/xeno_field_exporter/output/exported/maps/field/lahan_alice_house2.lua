Entity = {}



Entity[ "0" ] = {
    on_start = function( self )
        -- 0xBC_EntityNoModelInit(); -- 0x0008 0xbc
        -- 0x2A(); -- 0x0009 0x2a
        -- MISSING OPCODE 0xa0
    end,

    on_update = function( self )
        -- MISSING OPCODE 0x09
    end,

    on_talk = function( self )
        return 0 -- 0x004e 0x00
    end,

    on_push = function( self )
        -- MISSING OPCODE 0xe1
    end,

}



Entity[ "1" ] = {
    on_start = function( self )
        self.entity:init_pc( 0 ) -- 0x005e 0x16
        -- 0xFE0D_SetAvatar( character_id=0 ); -- 0x0061 0xfe
        -- 0x84_ProgressLessEqualJumpTo( value=8, jump=0x0070 ); -- 0x0065 0x84
        -- 0x19_SetPosition( x=(vf80)0xfffd, z=(vf40)0x008c, flag=(flag)0x00 ) -- 0x006a 0x19
        return 0 -- 0x0070 0x00
    end,

    on_update = function( self )
        -- 0x0C_Encounter(); -- 0x0071 0x0c
        return 0 -- 0x0072 0x00
    end,

    on_talk = function( self )
        return 0 -- 0x0073 0x00
    end,

    on_push = function( self )
        return 0 -- 0x0073 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0x4a
    end,

    script_0x05 = function( self )
        -- MISSING OPCODE 0xd2
    end,

    script_0x06 = function( self )
        -- MISSING OPCODE 0x4a
    end,

    script_0x07 = function( self )
        -- MISSING OPCODE 0x6b
    end,

    script_0x08 = function( self )
        -- MISSING OPCODE 0x69
    end,

    script_0x09 = function( self )
        -- MISSING OPCODE 0xf4
    end,

    script_0x0a = function( self )
        -- MISSING OPCODE 0xd2
    end,

    script_0x0b = function( self )
        -- MISSING OPCODE 0x6c
    end,

    script_0x0c = function( self )
        -- MISSING OPCODE 0x6f
    end,

    script_0x0d = function( self )
        -- MISSING OPCODE 0xd2
    end,

    script_0x0e = function( self )
        -- MISSING OPCODE 0xd2
    end,

    script_0x0f = function( self )
        -- MISSING OPCODE 0x2c
    end,

    script_0x10 = function( self )
        -- MISSING OPCODE 0x2c
    end,

    script_0x11 = function( self )
        -- 0x26_Wait( time=10 ); -- 0x0104 0x26
        -- MISSING OPCODE 0x4a
    end,

    script_0x12 = function( self )
        -- MISSING OPCODE 0x69
    end,

    script_0x13 = function( self )
        -- MISSING OPCODE 0xd0
    end,

    script_0x14 = function( self )
        -- MISSING OPCODE 0x6b
    end,

    script_0x15 = function( self )
        -- 0x26_Wait( time=20 ); -- 0x013d 0x26
        -- MISSING OPCODE 0xd2
    end,

    script_0x16 = function( self )
        -- MISSING OPCODE 0x4a
    end,

}



Entity[ "2" ] = {
    on_start = function( self )
        self.entity:init_pc( 2 ) -- 0x0157 0x16
        -- 0xFE0D_SetAvatar( character_id=2 ); -- 0x015a 0xfe
        return 0 -- 0x015e 0x00
    end,

    on_update = function( self )
        -- 0x0C_Encounter(); -- 0x015f 0x0c
        return 0 -- 0x0160 0x00
    end,

    on_talk = function( self )
        return 0 -- 0x0161 0x00
    end,

    on_push = function( self )
        return 0 -- 0x0161 0x00
    end,

}



Entity[ "3" ] = {
    on_start = function( self )
        self.entity:init_pc( 1 ) -- 0x0162 0x16
        -- 0xFE0D_SetAvatar( character_id=1 ); -- 0x0165 0xfe
        return 0 -- 0x0169 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa7
    end,

    on_talk = function( self )
        return 0 -- 0x016c 0x00
    end,

    on_push = function( self )
        return 0 -- 0x016c 0x00
    end,

}



Entity[ "4" ] = {
    on_start = function( self )
        self.entity:init_pc( 3 ) -- 0x016d 0x16
        -- 0xFE0D_SetAvatar( character_id=3 ); -- 0x0170 0xfe
        return 0 -- 0x0174 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa7
    end,

    on_talk = function( self )
        return 0 -- 0x0177 0x00
    end,

    on_push = function( self )
        return 0 -- 0x0177 0x00
    end,

}



Entity[ "5" ] = {
    on_start = function( self )
        self.entity:init_pc( 5 ) -- 0x0178 0x16
        -- 0xFE0D_SetAvatar( character_id=5 ); -- 0x017b 0xfe
        return 0 -- 0x017f 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa7
    end,

    on_talk = function( self )
        return 0 -- 0x0182 0x00
    end,

    on_push = function( self )
        return 0 -- 0x0182 0x00
    end,

}



Entity[ "6" ] = {
    on_start = function( self )
        self.entity:init_pc( 6 ) -- 0x0183 0x16
        -- 0xFE0D_SetAvatar( character_id=6 ); -- 0x0186 0xfe
        return 0 -- 0x018a 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa7
    end,

    on_talk = function( self )
        return 0 -- 0x018d 0x00
    end,

    on_push = function( self )
        return 0 -- 0x018d 0x00
    end,

}



Entity[ "7" ] = {
    on_start = function( self )
        self.entity:init_pc( 7 ) -- 0x018e 0x16
        -- 0xFE0D_SetAvatar( character_id=7 ); -- 0x0191 0xfe
        return 0 -- 0x0195 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa7
    end,

    on_talk = function( self )
        return 0 -- 0x0198 0x00
    end,

    on_push = function( self )
        return 0 -- 0x0198 0x00
    end,

}



Entity[ "8" ] = {
    on_start = function( self )
        self.entity:init_pc( 8 ) -- 0x0199 0x16
        -- 0xFE0D_SetAvatar( character_id=8 ); -- 0x019c 0xfe
        return 0 -- 0x01a0 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa7
    end,

    on_talk = function( self )
        return 0 -- 0x01a3 0x00
    end,

    on_push = function( self )
        return 0 -- 0x01a3 0x00
    end,

}



Entity[ "9" ] = {
    on_start = function( self )
        self.entity:init_npc( 1 ) -- 0x01a4 0x0b
        -- 0xFE0D_SetAvatar( character_id=20 ); -- 0x01a7 0xfe
        -- 0x84_ProgressLessEqualJumpTo( value=8, jump=0x01b9 ); -- 0x01ab 0x84
        -- 0x19_SetPosition( x=(vf80)0xffb4, z=(vf40)0x0003, flag=(flag)0x01 ) -- 0x01b0 0x19
        -- 0x01_JumpTo( 0x01c2 ); -- 0x01b6 0x01
        -- MISSING OPCODE 0xFE45
    end,

    on_update = function( self )
        return 0 -- 0x01c6 0x00
    end,

    on_talk = function( self )
        -- MISSING OPCODE 0x6f
    end,

    on_push = function( self )
        return 0 -- 0x01e0 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0x6f
    end,

}



Entity[ "10" ] = {
    on_start = function( self )
        -- 0xBC_EntityNoModelInit(); -- 0x0348 0xbc
        -- 0x2A(); -- 0x0349 0x2a
        return 0 -- 0x034a 0x00
    end,

    on_update = function( self )
        return 0 -- 0x034b 0x00
    end,

    on_talk = function( self )
        return 0 -- 0x034c 0x00
    end,

    on_push = function( self )
        return 0 -- 0x034c 0x00
    end,

    script_0x04 = function( self )
        -- 0x02_ConditionalJumpTo( value1=GetVar( 0x0008 ), value2=(s16)0x0003, condition="value1 > value2", jump_if_false=0x0371 ); -- 0x034d 0x02
        -- 0x02_ConditionalJumpTo( value1=GetVar( 0x0008 ), value2=(s16)0x0005, condition="value1 < value2", jump_if_false=0x036b ); -- 0x0355 0x02
        -- 0x26_Wait( time=20 ); -- 0x035d 0x26
        -- MISSING OPCODE 0xb5
    end,

    script_0x05 = function( self )
        -- MISSING OPCODE 0x99
    end,

    script_0x06 = function( self )
        -- MISSING OPCODE 0x35
    end,

    script_0x07 = function( self )
        -- MISSING OPCODE 0x35
    end,

    script_0x08 = function( self )
        -- MISSING OPCODE 0x99
    end,

}



Entity[ "11" ] = {
    on_start = function( self )
        -- 0xBC_EntityNoModelInit(); -- 0x03e3 0xbc
        -- 0x2A(); -- 0x03e4 0x2a
        return 0 -- 0x03e5 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0x5b
    end,

    on_talk = function( self )
        return 0 -- 0x03e8 0x00
    end,

    on_push = function( self )
        return 0 -- 0x03e8 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0xe1
    end,

    script_0x05 = function( self )
        -- MISSING OPCODE 0xe1
    end,

}



Entity[ "12" ] = {
    on_start = function( self )
        -- 0xBC_EntityNoModelInit(); -- 0x0429 0xbc
        -- 0x2A(); -- 0x042a 0x2a
        return 0 -- 0x042b 0x00
    end,

    on_update = function( self )
        -- 0xCB_TriggerJumpTo( trigger_id=GetVar( 0x3500 ), jump=0x9804 ); -- 0x042c 0xcb
        self.entity:init_npc( GetVar( 0x0180 ) ) -- 0x0431 0x0b
        -- MISSING OPCODE 0x80
    end,

    on_talk = function( self )
        return 0 -- 0x0436 0x00
    end,

    on_push = function( self )
        return 0 -- 0x0436 0x00
    end,

}



Entity[ "13" ] = {
    on_start = function( self )
        -- 0xBC_EntityNoModelInit(); -- 0x0437 0xbc
        -- 0x2A(); -- 0x0438 0x2a
        return 0 -- 0x0439 0x00
    end,

    on_update = function( self )
        return 0 -- 0x043a 0x00
    end,

    on_talk = function( self )
        return 0 -- 0x043b 0x00
    end,

    on_push = function( self )
        return 0 -- 0x043b 0x00
    end,

    script_0x04 = function( self )
        -- 0x26_Wait( time=20 ); -- 0x043c 0x26
        -- MISSING OPCODE 0x9d
    end,

}



Entity[ "14" ] = {
    on_start = function( self )
        return 0 -- 0x0446 0x00
        -- MISSING OPCODE 0x35
    end,

    on_update = function( self )
        return 0 -- 0x0446 0x00
        -- MISSING OPCODE 0x35
    end,

    on_talk = function( self )
        return 0 -- 0x0446 0x00
        -- MISSING OPCODE 0x35
    end,

    on_push = function( self )
        return 0 -- 0x0446 0x00
        -- MISSING OPCODE 0x35
    end,

}



