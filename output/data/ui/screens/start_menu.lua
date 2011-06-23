ui = {}



ui[ "StartScreen" ] = {
    on_start = function()
        ui:get_entity( "StartScreen.Background" ):Hide()
        ui:get_entity( "StartScreen.StartButton" ):Hide()
        ui:get_entity( "StartScreen.ContinueButton" ):Hide()
        ui:get_entity( "StartScreen.Cursor" ):Hide()
    end,

    on_show = function()
        ui:get_entity( "StartScreen.Background" ):Show()
        ui:get_entity( "StartScreen.StartButton" ):Show()
        ui:get_entity( "StartScreen.ContinueButton" ):Show()
        ui:get_entity( "StartScreen.Cursor" ):Show()
    end,

    on_key_press = function( button )
        if button == "X" then
            if ui[ "StartScreen" ][ "StartButton" ].focus == true then
                script:request_end_sync( "StartScreen", "to_start", 0 )
            else
                script:request_end_sync( "StartScreen", "to_continue", 0 )
            end

            -- when we hide parent - all it's childrens stop rendering (but not hiding),
            -- but when we call Show() again they all will be hided from script.
            ui:get_entity( "StartScreen" ):Hide()
        elseif button == "Down" then
            if ui[ "StartScreen" ][ "StartButton" ].focus == true then
                script:request( "StartScreen.Cursor", "to_continue", 0 )
            end
        elseif button == "Up" then
            if ui[ "StartScreen" ][ "StartButton" ].focus == false then
                script:request( "StartScreen.Cursor", "to_start", 0 )
            end
        end
    end,

    to_start = function()
        -- load map
    end,

    to_continue = function()
        ui:get_entity( "ContinueMenu" ):Show()
    end,



    StartButton = {
        focus = false,

        on_show = function()
            ui:get_entity( "StartScreen.StartButton" ):play_animation( "appear" )
            -- after playing this animation - entity changes to default idle animation.
        end,
    },



    ContinueButton = {
        on_show = function()
            ui:get_entity( "StartScreen.ContinueButton" ):play_animation( "appear" )
            -- after playing this animation - entity changes to default idle animation.
        end,
    },



    Cursor = {
        on_show = function()
            local cursor = ui:get_entity( "StartScreen.Cursor" )
            cursor:play_animation( "appear" )
            cursor:animation_sync()
            cursor:set_default_animation( "position1" )
            ui[ "StartScreen" ][ "StartButton" ].focus = true;
        end,

        to_start = function()
            cursor:set_default_animation( "position1" )
            ui[ "StartScreen" ][ "StartButton" ].focus = true;
        end,

        to_continue = function()
            cursor:set_default_animation( "position2" )
            ui[ "StartScreen" ][ "StartButton" ].focus = false;
        end
    },
}