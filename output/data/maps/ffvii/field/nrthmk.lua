EntityContainer = {}



EntityContainer[ "Director" ] = {
    on_start = function( self )
        if FFVII.Data.progress_game >= 27 then
            background2d:scroll_to_position( -29, 40, Background2D.NONE, 0 )
            --0322 (end 0332): music:execute_akao( 29, 40, 0, 0, 0, 1000, 7206 );
        else
            --0332 (end 0337): [UNREVERSED] BTLMD(20, 00);
            --0335 (end 0337): music:execute_akao( 10, pointer_to_field_AKAO_0 ); -- play field music
            --0337 (end 0337): field:map_name(3);
        end

        if FFVII.Data.progress_game < 27 then
            --0342 (end 0349): script:request( "l_door", "script_1", 6 )
            walkmesh:lock_walkmesh( 11, true )
        end

        return 0
    end,

    on_update = function( self )
        local triangle_id = EntityContainer[ "Cloud" ].cloud:get_move_triangle_id() -- temp6_00
        local x, y, z = EntityContainer[ "Cloud" ].cloud:get_position() -- temp6_0b temp6_0d

        return 0
    end,

    script_3 = function( self )
--[[
        0355 (end 0355): field:movie_camera_enable( false );
        0357 (end 0357): field:movie_set( 21 );
        0359 (end 0359): temp5_14 = 1;
        035d (end 035d): game:variable_set("progress_game", 33);
        0362 (end 0362): game:variable_set("act1_1_flags1", (game:variable_get( "act1_1_flags1" ) | (1 << 0)));
        0366 (end 0366): field:play_movie();
        0367 (end 0367): field:movie_camera_enable( true );
        0369 (end 0369): if ( game:variable_get( "act1_1_flags1" ) & (1 << 7) ) then continue else jumpto(0370);
        036f (end 0370): [OPCODE ff]
        0370 (end 0370): music:execute_akao( 29, 40, 0, 0, 0, f000, f201 );
        037e (end 037e): music:execute_akao( 10, pointer_to_field_AKAO_1 ); -- play field music
        0380 (end 0380): music:execute_akao( a1, 7f, 0, 0, 0, f200, 0 );
        038e (end 038e): music:execute_akao( c1, 0, 0, 0, 0, 6000, 88 );
        039c (end 039c): field:jump_to_map(136, 65515, 156, 2, 0);
        03a6 (end 03a6): return
]]
        return 0
    end,
}



EntityContainer[ "Cloud" ] = {
    cloud = nil,

    on_start = function( self )
        set_entity_to_character( "Cloud", "Cloud" )
        self.cloud = entity_manager:get_entity( "Cloud" )
        self.cloud:set_solid( true )
        self.cloud:set_visible( true )

        if FFVII.Data.progress_game == 27 then
            player_lock( true )
        end

--[[
        03b8 (end 03b8): if ( game:variable_get( "progress_game" ) == 27 ) then continue else jumpto(03e3);
        03c0 (end 03e3): if ( game:variable_get( "act1_1_flags1" ) & (1 << 7) ) then continue else jumpto(03e3);
        03c6 (end 03e3): cl:set_talkable( false );
        03c8 (end 03e3): cl:set_solid( false )
        03ca (end 03e3): cl:set_visible( false )
        03cc (end 03e3): script:wait( 0.266667 )
        03cf (end 03e3): script:request( "dir", "script_3", 6 )
        03d2 (end 03e3): script:wait( 0.666667 )
        03d5 (end 03e3): music:execute_akao( 29, 40, 0, 0, 0, 1200, 0 );
        03e3 (end 03e3): jumpto( 03e3 );
]]
        return 0
    end,

    script_3 = function( self )
--[[
        03e6 (end 03e6): cl:set_solid( false )
        03e8 (end 03e8): cl:set_position( 0, -7.82031, 3.83594 ) -- triangle_id=1
        03f3 (end 03f3): cl:set_move_speed( 4.21875 )
        03f7 (end 03f7): script:wait( 1.83333 )
        03fa (end 03fa): cl:move_to_position( 0.4375, -23.5 )
                         cl:move_sync()
        0400 (end 0400): cl:move_to_position( -4, -23.5 )
                         cl:move_sync()
        0406 (end 0406): -- set speed of entity animation to "2"
        040a (end 040a): cl:set_move_speed( 7.5 )
        040e (end 040e): cl:set_direction( 0 )
        0411 (end 0411): cl:play_animation_stop( "3" ) -- speed=1
                         cl:animation_sync()
        0414 (end 0414): return

        script_4:
        0415 (end 0415): cl:play_animation( "4" ) -- speed=1
                         cl:animation_sync()
        0418 (end 0418): cl:move_to_position( -9.67969, -24.1875 )
                         cl:move_sync()
        041e (end 041e): music:execute_akao( 29, 40, 0, 0, 0, 0, 1a1 );
        042c (end 042c): return
]]
        return 0
    end,
}



EntityContainer[ "Barret" ] = {
    barret = nil,

    on_start = function( self )
--[[
        042d (end 042d): -- assosiate entity with model (CHAR) argument doesn't matter
        042f (end 042f): set_entity_to_character( "ba", 1 );
        0431 (end 0431): if ( game:variable_get( "progress_game" ) == 27 ) then continue else jumpto(0450);
        0439 (end 0450): if ( !(game:variable_get( "act1_1_flags1" ) & (1 << 7)) ) then continue else jumpto(0450);
        043f (end 0450): ba:set_position( -0.28125, -7.42969, 3.83594 ) -- triangle_id=10
        044a (end 0450): ba:set_talkable( true );
        044c (end 0450): ba:set_solid( true )
        044e (end 0450): ba:set_visible( true )
        0450 (end 0450): return
        0451 (end 0451): if ( game:variable_get( "progress_game" ) == 27 ) then continue else jumpto(0474);
        0459 (end 0474): if ( !(game:variable_get( "act1_1_flags1" ) & (1 << 7)) ) then continue else jumpto(0474);
        045f (end 0474): ba:set_move_speed( 3.75 )
        0463 (end 0474): ba:set_solid( false )
        0465 (end 0474): script:wait( 0.133333 )
        0468 (end 0474): ba:move_to_position( 0.046875, -23.6797 )
                         ba:move_sync()
        046e (end 0474): ba:move_to_position( -9.67969, -23.7656 )
                         ba:move_sync()
        0474 (end 0474): jumpto( 0474 );
]]
        return 0
    end,
}



EntityContainer[ "Biggs" ] = {
    biggs = nil,

    on_start = function( self )
--[[
        0477 (end 0477): -- assosiate entity with model (CHAR) argument doesn't matter
        0479 (end 0479): av_b:set_direction( 247.5 )
        047c (end 047c): av_b:set_position( 1.5, -23.3594, 3.83594 ) -- triangle_id=5
        0487 (end 0487): if ( game:variable_get( "progress_game" ) >= 10 ) then continue else jumpto(0495);
        048f (end 0495): av_b:set_talkable( false );
        0491 (end 0495): av_b:set_solid( false )
        0493 (end 0495): av_b:set_visible( false )
        0495 (end 0495): if ( game:variable_get( "progress_game" ) >= 27 ) then continue else jumpto(04ae);
        049d (end 04ae): av_b:set_position( 0.296875, -8.08594, 3.83594 ) -- triangle_id=1
        04a8 (end 04ae): av_b:set_talkable( true );
        04aa (end 04ae): av_b:set_solid( true )
        04ac (end 04ae): av_b:set_visible( true )
        04ae (end 04ae): if ( game:variable_get( "act1_1_flags1" ) & (1 << 7) ) then continue else jumpto(04ba);
        04b4 (end 04ba): av_b:set_talkable( false );
        04b6 (end 04ba): av_b:set_solid( false )
        04b8 (end 04ba): av_b:set_visible( false )
        04ba (end 04ba): return
        04bb (end 04bb): av_b:set_default_animation( "2" ) -- speed=1
                         av_b:play_animation( "2" )
        04be (end 04be): av_b:set_move_speed( 4.21875 )
        04c2 (end 04c2): if ( game:variable_get( "progress_game" ) >= 27 ) then continue else jumpto(04d6);
        04ca (end 04d6): av_b:move_to_position( 0.046875, -23.6797 )
                         av_b:move_sync()
        04d0 (end 04d6): av_b:move_to_position( -9.67969, -23.7656 )
                         av_b:move_sync()
        04d6 (end 04d6): if ( game:variable_get( "progress_game" ) < 10 ) then continue else jumpto(04f0);
        04de (end 04f0): av_b:move_to_position( -0.21875, -22.4219 )
                         av_b:move_sync()
        04e4 (end 04f0): av_b:move_to_position( 0.117188, -6.33594 )
                         av_b:move_sync()
        04ea (end 04f0): av_b:set_talkable( false );
        04ec (end 04f0): av_b:set_solid( false )
        04ee (end 04f0): av_b:set_visible( false )
        04f0 (end 04f0): jumpto( 04f0 );
]]
        return 0
    end,
}



EntityContainer[ "Jessie" ] = {
    jessie = nil,

    on_start = function( self )
--[[
        av_c
        script_0:
        04f3 (end 04f3): -- assosiate entity with model (CHAR) argument doesn't matter
        04f5 (end 04f5): av_c:set_position( 2.85156, -24.1328, 3.83594 ) -- triangle_id=5
        0500 (end 0500): av_c:set_direction( 247.5 )
        0503 (end 0503): if ( game:variable_get( "progress_game" ) >= 10 ) then continue else jumpto(0511);
        050b (end 0511): av_c:set_talkable( false );
        050d (end 0511): av_c:set_solid( false )
        050f (end 0511): av_c:set_visible( false )
        0511 (end 0511): if ( game:variable_get( "progress_game" ) >= 27 ) then continue else jumpto(052a);
        0519 (end 052a): av_c:set_position( 0.234375, -8.27344, 3.83594 ) -- triangle_id=1
        0524 (end 052a): av_c:set_talkable( true );
        0526 (end 052a): av_c:set_solid( true )
        0528 (end 052a): av_c:set_visible( true )
        052a (end 052a): if ( game:variable_get( "act1_1_flags1" ) & (1 << 7) ) then continue else jumpto(0536);
        0530 (end 0536): av_c:set_talkable( false );
        0532 (end 0536): av_c:set_solid( false )
        0534 (end 0536): av_c:set_visible( false )
        0536 (end 0536): return
        0537 (end 0537): if ( game:variable_get( "progress_game" ) >= 27 ) then continue else jumpto(056c);
        053f (end 056c): av_c:set_solid( false )
        0541 (end 056c): script:wait( 1.66667 )
        0544 (end 056c): av_c:set_move_speed( 5.39062 )
        0548 (end 056c): av_c:move_to_position( 0.5, -24 )
                         av_c:move_sync()
        054e (end 056c): av_c:move_to_position( -2, -23.875 )
                         av_c:move_sync()
        0554 (end 056c): av_c:set_default_animation( "3" ) -- speed=1
                         av_c:play_animation( "3" )
        0557 (end 056c): av_c:move_to_position( "-448, -3056, false );
        055d (end 056c): av_c:set_move_speed( 1.875 )
        0561 (end 056c): av_c:move_to_position( "-512, -3056, false );
        0567 (end 056c): av_c:play_animation_stop( "3", 0.633333, 0.633333 ) -- speed=1
                         av_c:animation_sync()
        056c (end 056c): if ( game:variable_get( "progress_game" ) < 10 ) then continue else jumpto(058a);
        0574 (end 058a): av_c:set_move_speed( 3.98437 )
        0578 (end 058a): av_c:move_to_position( -0.148438, -23.0078 )
                         av_c:move_sync()
        057e (end 058a): av_c:move_to_position( 0.117188, -6.33594 )
                         av_c:move_sync()
        0584 (end 058a): av_c:set_talkable( false );
        0586 (end 058a): av_c:set_solid( false )
        0588 (end 058a): av_c:set_visible( false )
        058a (end 058a): jumpto( 058a );

        script_3:
        058d (end 058d): av_c:set_move_speed( 7.5 )
        0591 (end 0591): -- set speed of entity animation to "2"
        0595 (end 0595): av_c:play_animation_stop( "4" ) -- speed=1
                         av_c:animation_sync()
        0598 (end 0598): av_c:set_default_animation( "0" ) -- speed=1
                         av_c:play_animation( "0" )
        059b (end 059b): av_c:move_to_position( -9.67969, -24 )
                         av_c:move_sync()
        05a1 (end 05a1): return
]]
        return 0
    end,
}




EntityContainer[ "Wedge" ] = {
    wedge = nil,

    on_start = function( self )
        self.wedge = entity_manager:get_entity( "Wedge" )
        self.wedge:set_position( 4.51563, -23.2109, 3.83594 )
        self.wedge:set_interactable( true )
        self.wedge:set_solid( true )
        self.wedge:set_visible( true )


        if FFVII.Data.progress_game < 10 then
            self.wedge:set_move_auto_speed( 3.51562 )
            self.wedge:move_to_position( -6.97656, -23.7344 )
            self.wedge:move_sync()
            self.wedge:set_rotation( 247.5 )
            self.wedge:set_default_animation( "LookAround" ) -- speed=1
            self.wedge:play_animation( "LookAround" )
            FFVII.Data.progress_game = 10
        elseif FFVII.Data.progress_game >= 10 then
            self.wedge:set_position( -6.97656, -23.7344, 3.83594 )
            self.wedge:set_rotation( 247.5 )
            self.wedge:set_default_animation( "LookAround" )
            self.wedge:play_animation( "LookAround" )
        elseif FFVII.Data.progress_game >= 27 then
            script:wait( 4.66667 )
            self.wedge:set_move_auto_speed( 2.34375 )
            self.wedge:move_to_position( -10.0938, -23.6719 )
            self.wedge:move_sync()
        elseif FFVII.Data.act1_1_flags1_80 == true then
            self.wedge:set_talkable( false )
            self.wedge:set_solid( false )
            self.wedge:set_visible( false )
        end

        return 0
    end,

    on_interact = function( self )
        player_lock( true )
        message:show_dialog( "1", "nrthmk_00", 15, 10 )
        message:sync( "1" )
        message:show_dialog( "1", "nrthmk_01", 20, 10 )
        message:sync( "1" )
        player_lock( false )

        return 0
    end,
}



--[[
        unnamed_6
        script_0:
        062c (end 062c): return
        062d (end 062d): if ( game:variable_get( "progress_game" ) >= 27 ) then continue else jumpto(0651);
        0635 (end 0651): if ( game:variable_get( "act1_1_flags1" ) & (1 << 7) ) then continue else jumpto(0640);
        063b (end 0651): script:wait( 2 )
        063e (end 0651): jumpto( 0643 );
        0640 (end 0651): script:wait( 6 )
        0643 (end 0651): music:execute_akao( c2, 7f, 0, 0, 0, 1200, 0 );
        0651 (end 0651): jumpto( 0651 );

        unnamed_7
        script_0:
        0654 (end 0654): return
        0655 (end 0655): if ( game:variable_get( "progress_game" ) >= 27 ) then continue else jumpto(0669);
        065d (end 0669): if ( !(game:variable_get( "act1_1_flags1" ) & (1 << 7)) ) then continue else jumpto(0669);
        0663 (end 0669): script:request_end_sync( "cl", "script_3", 6 )
        0666 (end 0669): script:request( "dir", "script_3", 6 )
        0669 (end 0669): jumpto( 0669 );

        moviec
        script_0:
        066c (end 066c): return
        066d (end 066d): if ( game:variable_get( "progress_game" ) >= 27 ) then continue else jumpto(06ae);
        0675 (end 06ae): if ( temp5_14 == 1 ) then continue else jumpto(06ae);
        067b (end 06ae): if ( !(game:variable_get( "act1_1_flags1" ) & (1 << 7)) ) then continue else jumpto(06ae);
        0681 (end 06ae): temp6_10 = field:get_movie_frame();
        0684 (end 06ae): if ( temp5_12 == 0 ) then continue else jumpto(0699);
        068a (end 06ae): if ( temp6_10 > 13 ) then continue else jumpto(0699);
        0692 (end 06ae): temp5_12 = 1;
        0696 (end 06ae): script:request( "av_c", "script_3", 6 )
        0699 (end 06ae): if ( temp5_13 == 0 ) then continue else jumpto(06ae);
        069f (end 06ae): if ( temp6_10 > 18 ) then continue else jumpto(06ae);
        06a7 (end 06ae): temp5_13 = 1;
        06ab (end 06ae): script:request( "cl", "script_4", 6 )
        06ae (end 06ae): jumpto( 066d );

        l_door
        script_0:
        06b1 (end 06b1): field:background_clear( "1" ); -- turns off all layer of background animation with given id
        06b4 (end 06b4): field:background_off( "1", 0 ); -- turns off layer of background animation with given id
        06b8 (end 06b8): return
        06b9 (end 06b9): return

        script_1:
        06ba (end 06ba): field:background_on( "1", 0 ); -- turns on layer of background animation with given id
        06be (end 06be): return
]]



EntityContainer[ "Gateway0" ] = {
    on_start = function( self )
        return 0
    end,

    on_enter_line = function( self, entity )
        return 0
    end,

    on_move_to_line = function( self, entity )
        return 0
    end,

    on_cross_line = function( self, entity )
        if entity == "Cloud" then
            load_field_map_request( "ffvii_md1_2", "Spawn_nrthmk" )
        end

        return 0
    end,

    on_leave_line = function( self, entity )
        return 0
    end,
}



EntityContainer[ "Gateway1" ] = {
    on_start = function( self )
        return 0
    end,

    on_enter_line = function( self, entity )
        return 0
    end,

    on_move_to_line = function( self, entity )
        return 0
    end,

    on_cross_line = function( self, entity )
        if entity == "Cloud" then
            --load_field_map_request( "ffvii_nrthmk", "Spawn_md1_2" )
        end

        return 0
    end,

    on_leave_line = function( self, entity )
        return 0
    end,
}



EntityContainer[ "Gateway2" ] = {
    on_start = function( self )
        return 0
    end,

    on_enter_line = function( self, entity )
        return 0
    end,

    on_move_to_line = function( self, entity )
        return 0
    end,

    on_cross_line = function( self, entity )
        if entity == "Cloud" then
            --load_field_map_request( "ffvii_nrthmk", "Spawn_md1_2" )
        end

        return 0
    end,

    on_leave_line = function( self, entity )
        return 0
    end,
}
