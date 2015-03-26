EntityContainer = {}



EntityContainer[ "TestText" ] = {
    number_of_tests = 1,



    on_start = function( self )
        local var = 1;
        message:set_variable( "0", "tests", tostring( var ) )
        message:set_variable( "0", "var", "==TEST_1" )
        message:set_cursor( "0", 2, 4 )
        message:show_text( "0", "Test 1/<variable name=\"tests\" />\nStart output ... this is <colour value=\"1 0 0\">dynamic variable</colour>. TEST1<variable name=\"var\" />. And again <image sprite=\"ButtonCross\" /> same var TEST1<variable name=\"var\" />. Change after few <colour value=\"0 1 0\">seconds</colour>. Now we pause.<pause_ok />Now for next page ...<next_page />This is 2nd page. Wait 5 seconds til continue ... <pause time=\"5\" />continue. Final!", 500, 200, 200, 150 )
        timer:set_timer( 20 )
        message:set_clickable( "Timer" , false )
        message:show_text( "Timer", "<timer />", 50, 50, 100, 100 )
--[[
        message:show_dialog( 2 , "receive_potion", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "receive_phoenix_down", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "md1stin_00", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "md1_1_00", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "md1_1_01", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "md1_1_02", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "md1_1_03", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "md1_1_04", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "md1_1_05", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "md1_1_06", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "md1_1_07", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "md1_1_08", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "md1_1_09", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "md1_1_10", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "md1_1_11", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nrthmk_00", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nrthmk_01", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_00", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_01", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_02", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_03", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_04", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_05", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_06", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_07", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_08", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_09", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_10", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_11", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_12", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_13", 400, 140 )
        message:sync( 2 )
        message:show_dialog( 2 , "nmkin_1_14", 400, 140 )
]]
        script:wait( 10 )
        message:set_clickable( "1" , false )
        message:show_text( "1" , "Variable in dialog 0 changed.", 600, 340, 200, 30 )
        message:set_variable( "0", "var", "!=TEST_42" )
        script:wait( 5 )
        message:hide( "1" )

        --message:set_style( 7, Message.TRANSPARENT );
        --message:show_text_wait( 7, "Test complete!", 0, 0, 640, 480 );


        if timer:get_timer() == 0 then
            message:hide( "Timer" )
        end

        return 0
    end,
};