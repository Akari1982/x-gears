EntityContainer = {}



EntityContainer[ "Director" ] = {
    on_start = function( self )
        background2d:play_animation_looped( "Light1" )
        background2d:play_animation_looped( "Light2" )
        background2d:play_animation_looped( "Fan" )

        background2d:autoscroll_to_entity( entity_manager:get_entity( "Cloud" ) )
        --03a6 (end 03a6): [UNREVERSED] BTLMD(20, 00);
        --03a9 (end 03a9): music:execute_akao( 10, pointer_to_field_AKAO_0 ); -- play field music
        --03ab (end 03ab): field:map_name(1);

        while true do
            if FFVII.Data.progress_game >= 7 then
                break
            end

            if EntityContainer[ "Cloud" ].cloud ~= nil then
                local triangle_id = EntityContainer[ "Cloud" ].cloud:get_move_triangle_id()

                if ( FFVII.Data.progress_game < 7 ) and ( triangle_id == 62 ) then
                    player_lock( true )
                    background2d:scroll_to_position( -288, 180, Background2D.SMOOTH, 1.06667 )

                    script:request( Script.ENTITY, "Cloud", "scene_part_1", 6 )

                    FFVII.Data.progress_game = 7

                    script:request_end_sync( Script.ENTITY, "Biggs", "scene_part_2", 6 )
                    script:wait( 0.2 )
                    script:request_end_sync( Script.ENTITY, "Jessie", "scene_part_3", 6 )
                    script:wait( 0.333333 )
                    script:request_end_sync( Script.ENTITY, "Biggs", "scene_part_4", 5 )
                    script:wait( 0.266667 )
                    script:request_end_sync( Script.ENTITY, "Cloud", "scene_part_6", 6 )
                    script:wait( 0.266667 )
                    script:request_end_sync( Script.ENTITY, "Barret", "scene_part_8", 6 )
                    script:wait( 0.4 )
                    --03f5 (end 043e): music:execute_akao( 20, 00000040, 00000034 ); -- play sound
                    script:wait( 0.266667 )
                    --03fd (end 043e): music:execute_akao( 20, 00000040, 00000020 ); -- play sound
                    script:request( Script.ENTITY, "DoorLeft", "open", 6 )
                    script:request( Script.ENTITY, "DoorRight", "open", 6 )
                    script:wait( 0.333333 )
                    script:request( Script.ENTITY, "Jessie", "scene_part_10", 6 )
                    script:wait( 1 )
                    script:request( Script.ENTITY, "Biggs", "scene_part_11", 6 )
                    script:wait( 0.2 )
                    script:request( Script.ENTITY, "Wedge", "scene_part_12", 6 )
                    script:wait( 0.5 )
                    script:request_end_sync( Script.ENTITY, "Barret", "scene_part_13", 6 )
                    --0420 (end 043e): [UNREVERSED] PMJMP(76, 00);
                    script:request( Script.ENTITY, "Barret", "scene_part_15", 6 )
                    script:wait( 1 )
                    --0429 (end 043e): field:movie_set( 20 );
                    EntityContainer.Movie.movie_check = true
                    --042f (end 043e): field:play_movie();
                    --0430 (end 043e): field:jump_to_map(118, 3549, 30574, 60, 180);

                    --player_lock( false )
                end
            end

            script:wait( 0 )
        end

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

        return 0
    end,

    --[[ Move Cloud to talk position for the scene. ]]
    scene_part_1 = function( self )
        self.cloud:set_move_auto_speed( 1.875 )
        self.cloud:move_to_position( 4.48438, 5.30469 )
        self.cloud:move_sync()
        self.cloud:set_rotation( 174.375 )

        return 0
    end,

    --[[ Cloud reply his name to Avalanche. ]]
    scene_part_5 = function( self )
        self.cloud:play_animation_stop( "LookAtPeople", 0, 0.233333 )
        self.cloud:animation_sync()
        message:show_dialog( "0", "md1_1_05",100, 150 )
        message:sync( "0" )
        self.cloud:play_animation_stop( "LookAtPeople", 0.266667, 0.466667 )
        self.cloud:animation_sync()

        return 0
    end,

    --[[ Cloud tells Biggs that he didn\t care about names. ]]
    scene_part_6 = function( self )
        self.cloud:play_animation( "TalkNo" )
        self.cloud:animation_sync()
        script:request( Script.ENTITY, "Biggs", "scene_part_7", 6 )
        self.cloud:play_animation_stop( "LookAtPeople", 0, 0.233333 )
        self.cloud:animation_sync()
        message:show_dialog( "0", "md1_1_07", 30, 150 )
        message:sync( "0" )
        self.cloud:play_animation_stop( "LookAtPeople", 0.233333, 0.466667 )
        self.cloud:animation_sync()

        return 0
    end,

    scene_part_9 = function( self )
        script:wait( 0.333333 )
        self.cloud:play_animation_stop( "LookAtPeople", 0.466667, 0.733333 )
        self.cloud:animation_sync()

        return 0
    end,

    scene_part_14 = function( self )
        self.cloud:play_animation_stop( "LookAtPeople", 0.733333, 0.966667 )
        self.cloud:animation_sync()

        return 0
    end,

    --[[ look at reactor and run after Barret and others. ]]
    scene_part_16 = function( self )
        self.cloud:set_animation_speed( 0.5 )
        script:wait( 0.6 )
        self.cloud:play_animation_stop( "LookUp" )
        self.cloud:animation_sync()
        self.cloud:set_move_auto_speed( 1.17187 )
        self.cloud:set_default_animation( "Idle" )
        self.cloud:play_animation( "Idle" )
        self.cloud:move_to_position( 5.02344, 11.4141 )
        self.cloud:move_sync()

        return 0
    end,
}



EntityContainer[ "Barret" ] = {
    barret = nil,

    on_start = function( self )
        set_entity_to_character( "Barret", "Barret" )
        self.barret = entity_manager:get_entity( "Barret" )

        if FFVII.Data.progress_game < 7 then
            self.barret:set_position( 8.84375, 4.82812, 5.07031 )
        end

        self.barret:set_solid( false )
        self.barret:set_visible( false )

        return 0
    end,

    scene_part_8 = function( self )
        self.barret:set_solid( true )
        self.barret:set_visible( true )
        self.barret:set_move_auto_speed( 1.17187 )
        script:request( Script.ENTITY, "Cloud", "scene_part_9", 6 )
        self.barret:move_to_position( 5.96094, 5.08594 )
        self.barret:move_sync()
        self.barret:set_rotation( 241.875 )
        message:show_dialog( "3", "md1_1_08", 25, 140 )
        message:sync( "3" )
        message:show_dialog( "3", "md1_1_09", 8, 150 )
        message:sync( "3" )

        return 0
    end,

    scene_part_13 = function( self )
        self.barret:set_move_auto_speed( 1.17187 )
        script:request( Script.ENTITY, "Cloud", "scene_part_14", 6 )
        self.barret:move_to_position( 4.39844, 7.3125 )
        self.barret:move_sync()
        script:wait( 1 )
        self.barret:turn_to_direction( 16.875, Entity.CLOSEST, Entity.SMOOTH, 0.333333 )
        self.barret:turn_sync()
        script:wait( 0.666667 )
        message:show_dialog( "0", "md1_1_10", 30, 20 )
        message:sync( "0" )
        script:wait( 0.266667 )
        --0532 (end 0532): [UNREVERSED] MENU(00, 06, 01);
        script:wait( 0.666667 )
        message:show_dialog( "0", "md1_1_11", 10, 137 )
        message:sync( "0" )

        return 0
    end,

    scene_part_15 = function( self )
        self.barret:move_to_position( 5.29297, 13.1875 )
        self.barret:move_sync()
        self.barret:set_solid( false )
        self.barret:set_visible( false )

        return 0
    end,
}



EntityContainer[ "Biggs" ] = {
    biggs = nil,

    on_start = function( self )
        self.biggs = entity_manager:get_entity( "Biggs" )
        self.biggs:set_position( 3.91406, 6.07812, 5.07031 )
        self.biggs:set_rotation( 174.375 )

        if FFVII.Data.progress_game >= 7 then
            self.biggs:set_solid( false )
            self.biggs:set_visible( false )
        else
            self.biggs:set_solid( true )
            self.biggs:set_visible( true )
        end

        return 0
    end,

    --[[ Turn to Cloud and start talk to him. ]]
    scene_part_2 = function( self )
        self.biggs:turn_to_direction( 39.375, Entity.CLOSEST, Entity.SMOOTH, 0.333333 )
        self.biggs:turn_sync()
        script:wait( 0.0333333 )
        self.biggs:play_animation_stop( "TalkGesture", 0, 0.3 )
        self.biggs:animation_sync()
        message:show_dialog( "1", "md1_1_00", 8, 8 )
        message:sync( "1" )
        self.biggs:play_animation( "TalkGesture", 0.333333, 0.633333 )
        self.biggs:animation_sync()

        return 0
    end,

    --[[ Dialog with Jessie and Cloud. We input Cloud name during this scene and call Cloud reply. ]]
    scene_part_4 = function( self )
        message:show_dialog( "1", "md1_1_03", 30, 10 )
        message:sync( "1" )
        self.biggs:play_animation_stop( "TalkGesture", 0, 0.466667 )
        self.biggs:animation_sync()
        message:show_dialog( "1", "md1_1_04", 50, 10 )
        message:sync( "1" )
        self.biggs:play_animation( "TalkGesture", 0.333333, 0.633333 )
        self.biggs:animation_sync()
        script:wait( 0.1 )
        --05be (end 05be): [UNREVERSED] MENU(00, 06, 00);
        script:wait( 0.1 )
        script:request_end_sync( Script.ENTITY, "Cloud", "scene_part_5", 6 )
        script:wait( 0.2 )
        self.biggs:play_animation_stop( "TalkGesture", 0, 0.466667 )
        self.biggs:animation_sync()
        message:show_dialog( "1", "md1_1_06", 50, 20 )
        message:sync( "1" )

        return 0
    end,

    scene_part_7 = function( self )
        self.biggs:play_animation( "TalkGesture", 0.333333, 0.633333 )
        self.biggs:animation_sync()

        return 0
    end,

    scene_part_11 = function( self )
        self.biggs:set_move_auto_speed( 1.17187 )
        self.biggs:move_to_position( 4.57422, 6.82812 )
        self.biggs:move_sync()
        self.biggs:move_to_position( 5.29297, 13.1875 )
        self.biggs:move_sync()
        self.biggs:set_solid( false )
        self.biggs:set_visible( false )

        return 0
    end,
}



EntityContainer[ "Jessie" ] = {
    jessie = nil,

    on_start = function( self )
        self.jessie = entity_manager:get_entity( "Jessie" )
        self.jessie:set_position( 4.51953, 6.32422, 5.07031 )
        self.jessie:set_rotation( 174.375 )

        self.jessie:set_default_animation( "BreakUp" )
        self.jessie:play_animation( "BreakUp" )

        if FFVII.Data.progress_game >= 7 then
            self.jessie:set_solid( false )
            self.jessie:set_visible( false )
        else
            self.jessie:set_solid( true )
            self.jessie:set_visible( true )
        end

        return 0
    end,

    --[[ Stop breaking gate for a while and talk. ]]
    scene_part_3 = function( self )
        self.jessie:play_animation_stop( "BreakUpLookBack" )
        self.jessie:animation_sync()
        message:show_dialog( "2", "md1_1_01", 155, 8 )
        message:sync( "2" )
        message:show_dialog( "2", "md1_1_02", 120, 8 )
        message:sync( "2" )
        script:wait( 0.266667 )
        self.jessie:set_default_animation( "BreakUp" )
        self.jessie:play_animation( "BreakUp" )

        return 0
    end,

    scene_part_10 = function( self )
        self.jessie:set_move_auto_speed( 1.17187 )
        self.jessie:play_animation( "BreakUpGetUp" )
        self.jessie:animation_sync()
        self.jessie:move_to_position( 5.29297, 13.1875 )
        self.jessie:move_sync()
        self.jessie:set_solid( false )
        self.jessie:set_visible( false )

        return 0
    end,
}



EntityContainer[ "Wedge" ] = {
    wedge = nil,

    on_start = function( self )
        self.wedge = entity_manager:get_entity( "Wedge" )
        self.wedge:set_position( 5.94141, 5.875, 5.07031 )
        self.wedge:set_rotation( 16.875 )
        self.wedge:set_default_animation( "LookAround" )
        self.wedge:play_animation( "LookAround" )

        if FFVII.Data.progress_game >= 7 then
            self.wedge:set_solid( false )
            self.wedge:set_visible( false )
        else
            self.wedge:set_solid( true )
            self.wedge:set_visible( true )
        end

        return 0
    end,

    scene_part_12 = function( self )
        self.wedge:set_move_auto_speed( 1.17187 )
        self.wedge:move_to_position( 4.57422, 6.82812 )
        self.wedge:move_sync()
        self.wedge:move_to_position( 5.29297, 13.1875 )
        self.wedge:move_sync()
        self.wedge:set_solid( false )
        self.wedge:set_visible( false )

        return 0
    end,
}



EntityContainer[ "DoorLeft" ] = {
    door = nil,

    on_start = function( self )
        self.door = entity_manager:get_entity( "DoorLeft" )
        self.door:set_position( 4.25, 7.20703, 5.07031 )
        self.door:set_rotation( 354.375 )

        if FFVII.Data.progress_game >= 7 then
            self.door:set_visible( false )
        else
            self.door:set_visible( true )
        end

        self.door:set_solid( false )

        return 0
    end,

    open = function( self )
        self.door:offset_to_position( -0.789062, 0, 0, Entity.LINEAR, 1.66667 )
        self.door:offset_sync()
        self.door:set_visible( false )

        return 0
    end,
}



EntityContainer[ "DoorRight" ] = {
    door = nil,

    on_start = function( self )
        self.door = entity_manager:get_entity( "DoorRight" )
        self.door:set_position( 4.93359, 7.125, 5.07031 )
        self.door:set_rotation( 174.375 )

        if FFVII.Data.progress_game >= 7 then
            self.door:set_visible( false )
        else
            self.door:set_visible( true )
        end

        self.door:set_solid( false )

        return 0
    end,

    open = function( self )
        self.door:offset_to_position( 0.71875, 0, 0, Entity.LINEAR, 1.66667 )
        self.door:offset_sync()
        self.door:set_visible( false )

        return 0
    end,
}



EntityContainer[ "Movie" ] = {
    movie_check = false,

    on_start = function( self )
        while true do
            if self.movie_check == true then
                --0717 (end 0729): temp6_09 = field:get_movie_frame();
                --071a (end 0729): if ( temp6_09 > 30 ) then continue else jumpto(0729);
                script:request( Script.ENTITY, "Cloud", "scene_part_16", 6 )
                break
            end

            script:wait( 0 )
        end

        return 0
    end,
}



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
            load_field_map_request( "ffvii_md1stin", "Spawn_md1_1" )
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
            load_field_map_request( "ffvii_md1_2", "Spawn_md1_1" )
        end

        return 0
    end,

    on_leave_line = function( self, entity )
        return 0
    end,
}
